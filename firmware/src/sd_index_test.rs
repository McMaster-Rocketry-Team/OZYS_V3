#![no_std]
#![no_main]
#![feature(impl_trait_in_assoc_type)]

mod bootloader;
use core::{cell::RefCell, fmt::write, ptr, time};
use embassy_futures::select::Either;
use {defmt_rtt_pipe as _, panic_probe as _};

use cortex_m::{register::apsr::read, singleton};
use defmt::info;
use embassy_executor::Spawner;
use embassy_futures::select::select;
use embassy_stm32::{
    Peri,
    adc::{self, Adc, AdcChannel, SampleTime},
    crc::{Config as CrcConfig, Crc, InputReverseConfig, PolySize},
    pac::Interrupt::{DMA1_CHANNEL1, TIM1_CC},
    peripherals::{self, ADC1, DMA1, DMA1_CH1, PA0, PA2, PB11, PB12, PB14},
};
use embassy_stm32::{
    gpio::{Level, Output, Speed},
    time::mhz,
};

use crate::bootloader::{BootOption, configure_next_boot, watchdog_task};
use embassy_sync::{
    blocking_mutex::raw::NoopRawMutex,
    mutex::Mutex,
    pubsub::{PubSubChannel, Publisher, Subscriber, WaitResult},
    signal::Signal,
    watch::Watch,
};
use embassy_time::{Delay, Duration, Instant, Ticker, Timer};

use embassy_embedded_hal::shared_bus::asynch::spi::SpiDevice;
use embassy_stm32::{
    bind_interrupts,
    rng::{self},
    spi::{Config as SpiConfig, Spi},
};
use embassy_stm32::{peripherals::PB3, time::Hertz};
use embedded_sdmmc::asynchronous::{Block, BlockDevice as _, BlockIdx, SdCard};
use firmware_common_new::can_bus::{
    custom_status::{ozys_custom_status::OzysCustomStatus, vl_custom_status::VLCustomStatus},
    messages::{
        CanBusMessageEnum, OZYS_MEASUREMENT_MESSAGE_TYPE, VL_STATUS_MESSAGE_TYPE,
        node_status::{NodeHealth, NodeMode},
        unix_time::UnixTimeMessage,
        vl_status::{FlightStage, VLStatusMessage},
    },
    receiver::CanReceiver,
};
use firmware_common_new::can_bus::{
    messages::{
        node_status::NodeStatusMessage, ozys_measurement::OzysMeasurementMessage,
        reset::ResetMessage,
    },
    sender::CanSender,
};
mod can;
use can::start_can_bus_tasks;

pub enum BlockReady {
    BlockWaiting = 0,
    BlockReady = 1,
}

#[embassy_executor::main]
async fn main(_spawner: Spawner) {
    let config = {
        use embassy_stm32::rcc::mux::*;
        use embassy_stm32::rcc::*;
        let mut config = embassy_stm32::Config::default();
        let rcc = &mut config.rcc;

        rcc.hsi = false;
        rcc.hse = Some(Hse {
            freq: mhz(16),
            mode: HseMode::Oscillator,
        });
        rcc.hsi48 = Some(Hsi48Config {
            sync_from_usb: true,
        });

        // Limit clock speed to 150Mhz to reduce power consumption
        rcc.pll = Some(Pll {
            source: PllSource::HSE,
            prediv: PllPreDiv::DIV4,
            mul: PllMul::MUL75,
            divp: Some(PllPDiv::DIV2),
            divq: Some(PllQDiv::DIV2),
            divr: Some(PllRDiv::DIV2),
        });

        rcc.sys = Sysclk::PLL1_R;
        rcc.ahb_pre = AHBPrescaler::DIV1;
        rcc.apb1_pre = APBPrescaler::DIV1;
        rcc.apb2_pre = APBPrescaler::DIV1;

        rcc.ls = LsConfig::default_lse();

        rcc.mux.rtcsel = RtcClockSource::LSE;
        rcc.mux.adc12sel = Adcsel::SYS;
        rcc.mux.adc345sel = Adcsel::SYS;
        rcc.mux.clk48sel = Clk48sel::HSI48;
        rcc.mux.fdcansel = Fdcansel::PLL1_Q;

        config
    };
    let p = embassy_stm32::init(config);

    // Peripherals

    let unix_time_watch = singleton!(: Watch::<NoopRawMutex,u64,1> = Watch::new()).unwrap();
    let flight_stage_watch =
        singleton!(: Watch::<NoopRawMutex,FlightStage,2> = Watch::new()).unwrap();

    let mut _led2 = Output::new(p.PA10, Level::High, Speed::Low); // good 
    let ps = Output::new(p.PA7, Level::Low, Speed::Low); // PS pin, low: force pwm // good 
    //let led1 = Output::new(p.PC13, Level::High, Speed::Low); // LED1 // good
    info!("Hello OZYS V3!");
    let adc = Adc::new(p.ADC1);
    let read_buffer = singleton!(:[u16;5] = [0;5]).unwrap();
    let converted_samples = singleton!(:[f32;4] = [0.0;4]).unwrap();
    let adc_samples_channel =
        singleton!(: PubSubChannel::<NoopRawMutex,[f32;4],4,2,1> = PubSubChannel::new()).unwrap();
    let mut cs = Output::new(p.PB9, Level::High, Speed::High); // needed to configure as spi mode on peripheral  
    let mut spi_config = SpiConfig::default();
    spi_config.frequency = Hertz(5_000_000);
    let mut spi1 = Spi::new(
        p.SPI1,
        unsafe { PB3::steal() },
        p.PB5,
        p.PB4,
        p.DMA1_CH2,
        p.DMA1_CH3,
        spi_config,
    );
    let spi1 = Mutex::<NoopRawMutex, _>::new(spi1);
    let crc_config =
        CrcConfig::new(InputReverseConfig::None, false, PolySize::Width32, 69, 69).unwrap();
    let crc = Crc::new(p.CRC, crc_config);
    let (can_sender, can_receiver) = start_can_bus_tasks(&_spawner, p.FDCAN3, p.PA8, p.PA15).await; // good 
    _spawner.must_spawn(watchdog_task(p.IWDG));
    _spawner.must_spawn(node_status_task(can_sender));
    _spawner.must_spawn(status_led_task(p.PB14)); // good 
    _spawner.must_spawn(can_vl_status_check(
        can_receiver,
        flight_stage_watch.sender(),
    ));
    _spawner.must_spawn(can_get_unix_time(can_receiver, unix_time_watch.sender()));

    // WAIT FOR CORRECT FLIGHT STATUS
    // armed: start now
    // landed: stop after 1 min
    // low power: stop now
    _spawner.must_spawn(adc_test_task(
        adc,
        p.DMA1_CH1,
        p.PA0,
        p.PA2,
        p.PB11,
        p.PB12,
        read_buffer,
        _led2,
        adc_samples_channel.publisher().unwrap(),
        converted_samples,
        flight_stage_watch.receiver().unwrap(),
    ));
    _spawner.must_spawn(single_write_sd(
        spi1,
        cs,
        adc_samples_channel.subscriber().unwrap(),
        crc,
        unix_time_watch.receiver().unwrap(),
    ));
    _spawner.must_spawn(ozys_measurement_can_task(
        can_sender,
        adc_samples_channel.subscriber().unwrap(),
    ));
}

#[embassy_executor::task]
async fn adc_test_task(
    mut adc_peripheral: Adc<'static, ADC1>,
    mut dma_chanel: Peri<'static, DMA1_CH1>,
    mut adc_pin_1: Peri<'static, PA0>,
    mut adc_pin_2: Peri<'static, PA2>,
    mut adc_pin_3: Peri<'static, PB11>,
    mut adc_pin_4: Peri<'static, PB12>,
    read_buffer: &'static mut [u16; 5],
    mut led: Output<'static>,
    mut publisher: Publisher<'static, NoopRawMutex, [f32; 4], 4, 2, 1>,
    converted_samples: &'static mut [f32; 4],
    mut state_watch_rx: embassy_sync::watch::Receiver<'static, NoopRawMutex, FlightStage, 2>,
) {
    let mut vrefint_channel = adc_peripheral.enable_vrefint().degrade_adc();
    adc_peripheral.set_sample_time(SampleTime::CYCLES247_5);
    adc_peripheral.set_differential(&mut adc_pin_1, true);
    adc_peripheral.set_differential(&mut adc_pin_2, true);
    adc_peripheral.set_differential(&mut adc_pin_3, true);
    adc_peripheral.set_differential(&mut adc_pin_4, true);
    let mut pa0 = adc_pin_1.degrade_adc();
    let mut pa2 = adc_pin_2.degrade_adc();
    let mut pb11 = adc_pin_3.degrade_adc();
    let mut pb12 = adc_pin_4.degrade_adc();
    let VREFINT_CAL = 0x1FFF75AA as *mut u16;
    let vref_cal = unsafe { ptr::read_volatile(VREFINT_CAL) as f32 };
    info!("VREFINT_CAL: {}", vref_cal);
    let mut ticker = Ticker::every(Duration::from_hz(50));
    let mut cba123 = 0;

    let mut last_state = state_watch_rx.get().await;
    loop {
        let start_fut = async {
            loop {
                if last_state.clone() == FlightStage::Armed {
                    adc_peripheral
                        .read(
                            // starts code returns future and turned into statemachine cuz .await()
                            dma_chanel.reborrow(),
                            [
                                (&mut vrefint_channel, SampleTime::CYCLES247_5),
                                (&mut pa0, SampleTime::CYCLES247_5),
                                (&mut pa2, SampleTime::CYCLES247_5),
                                (&mut pb11, SampleTime::CYCLES247_5),
                                (&mut pb12, SampleTime::CYCLES247_5),
                            ]
                            .into_iter(),
                            read_buffer,
                        )
                        .await;
                    let vrefint = read_buffer[0];
                    let vref_plus = 3.0 * vref_cal / vrefint as f32;
                    cba123 += 1;
                    //info!("Vref+: {}V cba:{}", vref_plus, cba123);
                    for i in 0..4 {
                        converted_samples[i] = ((vref_plus / (1 << 12) as f32
                            * read_buffer[i + 1] as f32)
                            - vref_plus / 2.0)
                            * 2.0;
                    }
                    info!("Measured: {}V", converted_samples);
                    publisher.publish_immediate(*converted_samples);
                    ticker.next().await;
                }else {
                    Timer::after_millis(100).await;
                }
            }
        };
        let stop_fut = async { state_watch_rx.changed().await };
        match select(start_fut, stop_fut).await {
            Either::First(_) => unreachable!(),
            Either::Second(new_state) => {
                last_state = new_state;
            }
        }; // Doesnt a change result in function ending??? 
    }
}

// 31 samples of four f32 channels in each block
// increase CAP of channel to 1000
#[embassy_executor::task]
async fn single_write_sd(
    spi: Mutex<NoopRawMutex, Spi<'static, embassy_stm32::mode::Async>>,
    cs: Output<'static>,
    mut subscriber: Subscriber<'static, NoopRawMutex, [f32; 4], 4, 2, 1>,
    mut crc: Crc<'static>,
    mut watch_rx: embassy_sync::watch::Receiver<'static, NoopRawMutex, u64, 1>,
) {
    // BLOCK 512 BYTES
    // First 496 for samples
    // 508-512 for CHECK SUM

    let sd = SpiDevice::new(&spi, cs);
    let sdcard = SdCard::new(sd, Delay);
    let size: u64 = sdcard.num_bytes().await.unwrap();
    let block_count = (size / 512) as u32;
    info!("Card size is {} bytes, {} blocks", size, block_count);
    let mut card_index = 0;
    let mut read_block = [Block::default()];
    let block_index_primary = 0;
    let block_index_secondary = 1;
    let mut block_index_primary_inside = 0;
    let mut block_index_secondary_inside = 1;
    let mut crc_primary_flag = false; // check for corruption, false = corrupted
    let mut crc_secondary_flag = false;
    let mut write_to_primary = true;

    //TEST PRIMARY CRC
    sdcard
        .read(&mut read_block, BlockIdx(block_index_primary))
        .await
        .unwrap();
    info!("Read Prim: {}", read_block[0].contents);
    crc.reset();
    let check_sum = crc.feed_bytes(&read_block[0][0..508]);
    let check_sum2 = u32::from_le_bytes(read_block[0][508..512].try_into().unwrap());
    if check_sum != check_sum2 {
        info!(
            "Primary Failed, checksum mismatch: {} != {}",
            check_sum.to_le_bytes(),
            check_sum2.to_le_bytes()
        );
    } else {
        info!("Primary Succeeded");
        block_index_primary_inside = u32::from_le_bytes(read_block[0][0..4].try_into().unwrap());
        crc_primary_flag = true;
    }

    //TEST SECONDARY CRC
    sdcard
        .read(&mut read_block, BlockIdx(block_index_secondary))
        .await
        .unwrap();
    info!("Read Sec: {}", read_block[0].contents);
    crc.reset();
    let check_sum = crc.feed_bytes(&read_block[0][0..508]);
    let check_sum2 = u32::from_le_bytes(read_block[0][508..512].try_into().unwrap());
    if check_sum != check_sum2 {
        info!(
            "Secondary Failed, checksum mismatch: {} != {}",
            check_sum.to_be_bytes(),
            check_sum2.to_le_bytes()
        );
    } else {
        info!("Secondary Succeeded");
        block_index_secondary_inside = u32::from_le_bytes(read_block[0][0..4].try_into().unwrap());
        crc_secondary_flag = true;
    }
    if crc_secondary_flag && crc_primary_flag {
        if block_index_primary_inside > block_index_secondary_inside {
            card_index = block_index_primary_inside;
            write_to_primary = false;
        } else {
            card_index = block_index_secondary_inside;
        }
    } else if crc_primary_flag {
        card_index = block_index_primary_inside;
        write_to_primary = false;
    } else if crc_secondary_flag {
        card_index = block_index_secondary_inside;
    } else {
        crc.reset();
        card_index = 2;
        let mut empty = [Block::new()];
        empty[0].contents.fill(0);
        empty[0][0..4].copy_from_slice(&card_index.to_le_bytes());
        let check_sum: u32 = crc.feed_bytes(&empty[0][0..508]);
        empty[0][508..512].copy_from_slice(&check_sum.to_le_bytes());
        sdcard.write(&empty, BlockIdx(0)).await.unwrap();
        sdcard.write(&empty, BlockIdx(1)).await.unwrap();
        info!("Restarting index of all Blocks/ Check:{}", check_sum);
    }
    while card_index < 110 {
        if card_index % 100 == 0 {
            crc.reset();
            let mut empty = [Block::new()];
            empty[0].contents.fill(0);
            empty[0][0..4].copy_from_slice(&card_index.to_le_bytes());
            let check_sum: u32 = crc.feed_bytes(&empty[0][0..508]);
            empty[0][508..512].copy_from_slice(&check_sum.to_le_bytes());
            if write_to_primary {
                sdcard
                    .write(&empty, BlockIdx(block_index_primary))
                    .await
                    .unwrap();
                write_to_primary = false;
            } else {
                sdcard
                    .write(&empty, BlockIdx(block_index_secondary))
                    .await
                    .unwrap();
                write_to_primary = true;
            }
            sdcard
                .read(&mut read_block, BlockIdx(block_index_primary))
                .await
                .unwrap();
            info!("Primary Block: {}", read_block[0].contents);
            sdcard
                .read(&mut read_block, BlockIdx(block_index_secondary))
                .await
                .unwrap();
            info!("Secondary Block: {}", read_block[0].contents);
        }
        info!("card index = {}", card_index);
        let mut block = [Block::new()];
        block[0][0..8].copy_from_slice(&watch_rx.get().await.to_le_bytes());
        let mut block_index = 8;
        while block_index < 504 {
            match subscriber.next_message().await {
                WaitResult::Message(samples) => {
                    for (i, sample) in samples.iter().enumerate() {
                        let offset = 4 * i;
                        let bytes = sample.to_le_bytes();
                        block[0].contents[block_index + offset] = bytes[0];
                        block[0].contents[block_index + offset + 1] = bytes[1];
                        block[0].contents[block_index + offset + 2] = bytes[2];
                        block[0].contents[block_index + offset + 3] = bytes[3];
                    }
                }
                WaitResult::Lagged(missed) => {
                    //info!("missed: {}", missed);
                }
            }
            block_index += 16;
        }
        crc.reset();
        let check_sum: u32 = crc.feed_bytes(&block[0][..508]);
        block[0][508..512].copy_from_slice(&check_sum.to_le_bytes());
        let block_id = BlockIdx(card_index);
        sdcard.write(&block, block_id).await.unwrap();
        sdcard.read(&mut read_block, block_id).await.unwrap();
        info!(
            "{} + check: {}",
            &read_block[0].contents,
            check_sum.to_le_bytes()
        );
        card_index += 1;
        crc.reset();
        let check_sum = crc.feed_bytes(&block[0][..508]);
        let check_sum2 = u32::from_le_bytes(read_block[0][508..512].try_into().unwrap());
        if check_sum != check_sum2 {
            info!("Failed, checksum mismatch: {} != {}", check_sum, check_sum2);
            break;
        } else {
            info!("Start dancing");
        }
    }
}

#[embassy_executor::task]
async fn status_led_task(yellow_led: Peri<'static, PB14>) {
    let mut yellow_led = Output::new(yellow_led, Level::High, Speed::Low);
    let mut ticker = Ticker::every(Duration::from_millis(1000));
    loop {
        yellow_led.set_high();
        Timer::after_millis(50).await;
        yellow_led.set_low();
        ticker.next().await;
    }
}

#[embassy_executor::task]
async fn node_status_task(can_sender: &'static CanSender<NoopRawMutex, 4>) {
    let mut ticker = Ticker::every(Duration::from_millis(500));
    loop {
        can_sender.send(
            NodeStatusMessage::new(
                Instant::now().as_secs() as u32,
                NodeHealth::Healthy,
                NodeMode::Operational,
                OzysCustomStatus::new(true, true, true, true, true, 0.0),
            )
            .into(),
        );
        ticker.next().await;
    }
}

#[embassy_executor::task] // CHANGE SUBSCRIBER LIMIT??
async fn can_reset_task(can_receiver: &'static CanReceiver<NoopRawMutex, 4, 4>) {
    let mut subscriber = can_receiver.subscriber().unwrap();
    loop {
        let can_message = subscriber.next_message_pure().await.data.message;
        if let CanBusMessageEnum::Reset(ResetMessage {
            node_id,
            reset_all,
            into_bootloader,
        }) = can_message
            && (node_id == can_receiver.self_node_id() || reset_all)
        {
            configure_next_boot(if into_bootloader {
                BootOption::Bootloader
            } else {
                BootOption::Application
            });
            cortex_m::peripheral::SCB::sys_reset();
        }
    }
}

////////////////// Djordje's Implemented Tasks ///////////////////////

#[embassy_executor::task] // CHANGE SUBSCRIBER LIMIT??
async fn can_vl_status_check(
    can_receiver: &'static CanReceiver<NoopRawMutex, 4, 4>,
    watch_tx: embassy_sync::watch::Sender<'static, NoopRawMutex, FlightStage, 2>,
) {
    let mut subscriber = can_receiver.subscriber().unwrap();
    loop {
        let can_message = subscriber.next_message_pure().await.data.message;
        if let CanBusMessageEnum::VLStatus(VLStatusMessage {
            flight_stage,
            battery_mv,
        }) = can_message
        {
            watch_tx.send(flight_stage);
        }
    }
}

#[embassy_executor::task]
async fn can_get_unix_time(
    can_receiver: &'static CanReceiver<NoopRawMutex, 4, 4>,
    watch_tx: embassy_sync::watch::Sender<'static, NoopRawMutex, u64, 1>,
) {
    let mut subscriber = can_receiver.subscriber().unwrap();
    loop {
        let can_message = subscriber.next_message_pure().await.data.message;
        if let CanBusMessageEnum::UnixTime(UnixTimeMessage { timestamp_us }) = can_message {
            watch_tx.send(timestamp_us);
        }
    }
}

#[embassy_executor::task]
async fn ozys_measurement_can_task(
    can_sender: &'static CanSender<NoopRawMutex, 4>,
    mut subscriber: Subscriber<'static, NoopRawMutex, [f32; 4], 4, 2, 1>,
) {
    let mut ticker = Ticker::every(Duration::from_hz(10));
    loop {
        let samples: WaitResult<[f32; 4]> = subscriber.next_message().await;
        info!("Should be sending SG: {}", samples);
        match subscriber.next_message().await {
            WaitResult::Message(samples) => {
                can_sender.send(
                    OzysMeasurementMessage::new(
                        Some(samples[0]),
                        Some(samples[1]),
                        Some(samples[2]),
                        Some(samples[3]),
                    )
                    .into(),
                );
            }
            WaitResult::Lagged(missed) => {
                //info!("missed: {}", missed);
            }
        }
        ticker.next().await;
    }
}
