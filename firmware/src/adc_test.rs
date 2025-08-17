#![no_std]
#![no_main]
#![feature(impl_trait_in_assoc_type)]

mod bootloader;
use core::{cell::RefCell, ptr};

use {defmt_rtt_pipe as _, panic_probe as _};

use cortex_m::{register::apsr::read, singleton};
use defmt::info;
use embassy_executor::Spawner;
use embassy_stm32::{
    Peri,
    adc::{self, Adc, AdcChannel, SampleTime},
    pac::Interrupt::{DMA1_CHANNEL1, TIM1_CC},
    peripherals::{self, ADC1, DMA1, DMA1_CH1, PA0, PA2, PB11, PB12},
    crc::{Config as CrcConfig, Crc, InputReverseConfig, PolySize},
};
use embassy_stm32::{
    gpio::{Level, Output, Speed},
    time::mhz,
};

use crate::bootloader::watchdog_task;
use embassy_sync::{
    blocking_mutex::raw::NoopRawMutex,
    mutex::Mutex,
    pubsub::{PubSubChannel, Publisher, Subscriber, WaitResult},
    signal::Signal,
};
use embassy_time::{Delay, Duration, Ticker};

use embassy_embedded_hal::shared_bus::asynch::spi::SpiDevice;
use embassy_stm32::{
    bind_interrupts,
    rng::{self},
    spi::{Config as SpiConfig, Spi},
};
use embassy_stm32::{peripherals::PB3, time::Hertz};
use embedded_sdmmc::asynchronous::{Block, BlockDevice as _, BlockIdx, SdCard};

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
            divq: Some(PllQDiv::DIV8),
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

    let mut _led2 = Output::new(p.PA10, Level::High, Speed::Low); // good 
    let ps = Output::new(p.PA7, Level::Low, Speed::Low); // PS pin, low: force pwm // good 
    //let led1 = Output::new(p.PC13, Level::High, Speed::Low); // LED1 // good
    info!("Hello OZYS V3!");
    _spawner.must_spawn(watchdog_task(p.IWDG));
    let adc = Adc::new(p.ADC1);
    let read_buffer = singleton!(:[u16;5] = [0;5]).unwrap();
    let converted_samples = singleton!(:[f32;4] = [0.0;4]).unwrap();
    let adc_samples_channel =
        singleton!(: PubSubChannel::<NoopRawMutex,[f32;4],4,1,1> = PubSubChannel::new()).unwrap();
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
    ));

    // BLOCK TEST CODE
    /*
    let mut block = [Block::new()];
    let mut block_index = 0;
    while block_index <510{
        match _sub.next_message().await {
            WaitResult::Message(samples)=>{
                for (i,sample) in samples.iter().enumerate(){
                    let offset = 2*i;
                    [block[0].contents[block_index+offset],block[0].contents[block_index+offset+1]]=sample.to_le_bytes();
                }
                info!("{}",&block[0].contents);
            }
            WaitResult::Lagged(missed)=>{
                info!("missed: {}",missed);
            }
        }
        block_index+=10;
    }
    */
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
    _spawner.must_spawn(single_write_sd(
        spi1,
        cs,
        adc_samples_channel.subscriber().unwrap(),
        crc,
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
    mut publisher: Publisher<'static, NoopRawMutex, [f32; 4], 4, 1, 1>,
    converted_samples: &'static mut [f32;4],
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
    let mut ticker = Ticker::every(Duration::from_hz(10));
    let mut cba123 = 0;
    loop {
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
        cba123+=1;
        info!("Vref+: {}V cba:{}", vref_plus, cba123);
        for i in 0..4{
            converted_samples[i] =  ((vref_plus / (1 << 12) as f32 * read_buffer[i+1] as f32)- vref_plus/2.0)*2.0;
             info!("Measured: {}V", converted_samples[i]);
        }
        //info!("Measured: {}V", converted_samples);
        publisher.publish_immediate(*converted_samples);

        // TODO apply adc calibrations

        /*
        for read in read_buffer.clone(){
            info!("Readings:{}",read.to_le_bytes());
        }
        */
        /* 
        let vrefint = read_buffer[0];
        let measured = read_buffer[1];
        let vref_plus = 3.0 * vref_cal / vrefint as f32;
        info!("Vref+: {}V", vref_plus);
        let measured = vref_plus / (1 << 12) as f32 * measured as f32;
        //_led.toggle();
        info!("Measured: {}V", (measured - vref_plus / 2.0) * 2.0);
        */
        ticker.next().await;
    }
}

// 31 samples of four f32 channels in each block
// increase CAP of channel to 1000
#[embassy_executor::task]
async fn single_write_sd(
    spi: Mutex<NoopRawMutex, Spi<'static, embassy_stm32::mode::Async>>,
    cs: Output<'static>,
    mut subscriber: Subscriber<'static, NoopRawMutex, [f32; 4], 4, 1, 1>,
    mut crc: Crc<'static>,
) {
    // BLOCK 512 BYTES
    // First 496 for samples
    // 496-507 for 
    // 508-512 for CHECK SUM 

    let sd = SpiDevice::new(&spi, cs);
    let sdcard = SdCard::new(sd, Delay);
    let size: u64 = sdcard.num_bytes().await.unwrap();
    let block_count = (size / 512) as u32;
    info!("Card size is {} bytes, {} blocks", size, block_count);
    let mut card_index = 0;
    while card_index < 3 {
        let mut block = [Block::new()];
        let mut block_index = 0;
        while block_index < 496 {
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
                    //info!("{}",&block[0].contents);
                }
                WaitResult::Lagged(missed) => {
                    info!("missed: {}", missed);
                }
            }
            block_index += 16;
        }
        // TODO CRC
        let check_sum: u32 = crc.feed_bytes(&block[0][..508]);        
        block[0][508..512].copy_from_slice(&check_sum.to_le_bytes());

        let mut read_block = [Block::default()];
        let block_id = BlockIdx(card_index);
        sdcard.write(&block, block_id).await.unwrap();
        sdcard.read(&mut read_block, block_id).await.unwrap();
        info!("{} + check: {}", &read_block[0].contents,check_sum);
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
