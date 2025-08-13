#![no_std]
#![no_main]
#![feature(impl_trait_in_assoc_type)]

mod bootloader; // sd 
mod can;

use core::ptr;
use crate::bootloader::{BootOption, configure_next_boot, watchdog_task};
use {defmt_rtt_pipe as _, panic_probe as _}; 

use can::start_can_bus_tasks;
use defmt::info; 
use embassy_executor::Spawner; 

use embassy_stm32::Peri; 
use embassy_stm32::{peripherals::PB3,peripherals::PB14, time::Hertz};
use embassy_stm32::{ 
    gpio::{Level, Output, Speed},
    time::mhz,
    bind_interrupts, 
    pac::crc::Crc, 
    peripherals, 
    rng::{self}, 
    spi::{Config as SpiConfig, Spi}
};
use embassy_stm32::{adc::{self, Adc, AdcChannel, SampleTime}, peripherals::ADC1};

use embassy_sync::{
    blocking_mutex::raw::NoopRawMutex,
    mutex::Mutex, 
    channel::Channel,
    pubsub::PubSubChannel,
};
use embassy_time::{Duration, Instant, Ticker, Timer, Delay}; 

use embedded_sdmmc::asynchronous::{Block, BlockDevice as _, BlockIdx, SdCard};
use firmware_common_new::can_bus::{
    custom_status::{ozys_custom_status::OzysCustomStatus, vl_custom_status::VLCustomStatus},
    messages::{
        node_status::{NodeHealth, NodeMode}, unix_time::UnixTimeMessage, vl_status::{FlightStage, VLStatusMessage}, CanBusMessageEnum, OZYS_MEASUREMENT_MESSAGE_TYPE, VL_STATUS_MESSAGE_TYPE
    },
    receiver::CanReceiver,
};
use firmware_common_new::can_bus::{
    messages::{node_status::NodeStatusMessage, reset::ResetMessage,ozys_measurement::OzysMeasurementMessage},
    sender::CanSender,
};
bind_interrupts!(struct Irqs {
    RNG => rng::InterruptHandler<peripherals::RNG>;
});

// receive messages:
// - unix time
// - VLStatusMessage - start recording if armed, stop recording 1 min after landed
// send messages:
// - send values for the four strain gauges every sec (OzysMeasurementMessage)
// - send node status
// detect which sg port is connected -> blink leds -> send via node status
// record strain gauges -> write sd card
#[embassy_executor::main]
async fn main(spawner: Spawner) {
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
    let mut p = embassy_stm32::init(config);
    info!("Hello OZYS V3!");

    // this is ordered by led from top to bottom, power connector on the top left
    // LED order from top to bottom: (power connector on the top left)
    // led 2: PA10
    // led 3: PB6
    // led 4: PB7
    // led 1: PC13
    // status led: PB14
    let mut _led2 = Output::new(p.PA10, Level::High, Speed::Low); // good 
    let mut _led3 = Output::new(p.PB6, Level::Low, Speed::Low); // good
    let mut _led4 = Output::new(p.PB7, Level::Low, Speed::Low); // good 
    let mut _led1 = Output::new(p.PC13, Level::Low, Speed::Low); // good 
    spawner.must_spawn(status_led_task(p.PB14)); // good 
    spawner.must_spawn(watchdog_task(p.IWDG));

    let ps = Output::new(p.PA7, Level::Low, Speed::Low); // PS pin, low: force pwm // good 
    let mut adc: Adc<'_, peripherals::ADC1> = Adc::new(p.ADC1);
    let mut vrefint_channel: adc::AnyAdcChannel<ADC1> = adc.enable_vrefint().degrade_adc();
    adc.set_sample_time(SampleTime::CYCLES640_5);
    adc.set_differential(&mut p.PA0, true); // Assuming takes hold of PA1
    let mut pa0: adc::AnyAdcChannel<ADC1> = p.PA0.degrade_adc();
    //let mut adc_async_channel = Channel::new();

    let (can_sender, can_receiver) = start_can_bus_tasks(&spawner, p.FDCAN3, p.PA8, p.PA15).await; // good 
    spawner.must_spawn(node_status_task(can_sender));
    spawner.must_spawn(can_reset_task(can_receiver));

    // END OF CONFIG

    info!("All tasks started");
    let mut i = 0usize;
    loop {
        Timer::after_secs(1).await;
        info!("Hello OZYS {}", i);
        i += 1;
        // STARTING LOOP LOGIC HERE /////////////////////////

        

        // ENDING LOOP LOGIC HERE /////////////////////////
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
                OzysCustomStatus::new(false, false, false, false, true, 0.0),
            )
            .into(),
        );
        ticker.next().await;
    }
}

#[embassy_executor::task]                                                   // CHANGE SUBSCRIBER LIMIT??
async fn can_reset_task(can_receiver: &'static CanReceiver<NoopRawMutex, 4, 1>) {
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
/* TO DO 
#[embassy_executor::task]                                                  // CHANGE SUBSCRIBER LIMIT??
async fn can_vl_status_check(can_receiver: &'static CanReceiver<NoopRawMutex, 4, 1>) {
    let mut subscriber = can_receiver.subscriber().unwrap();
    loop {
        let can_message = subscriber.next_message_pure().await.data.message;
        if let CanBusMessageEnum::VLStatus(VLStatusMessage{
            flight_stage,
            battery_mv,            
        }) = can_message {
            //GET A WATCH?? 
        }
    }
}
*/

/* TO DO 
#[embassy_executor::task]               
async fn can_get_unix_time(can_receiver: &'static CanReceiver<NoopRawMutex, 4, 1>) {
    let mut subscriber = can_receiver.subscriber().unwrap();
    loop {
        let can_message = subscriber.next_message_pure().await.data.message;
        if let CanBusMessageEnum::UnixTime(UnixTimeMessage{
            timestamp_us
        }) = can_message {
            //GET A WATCH ???? 
        }
    }
}
*/

/* TO DO 
#[embassy_executor::task]
async fn ozys_measurement_can_task (can_sender: &'static CanSender<NoopRawMutex, 4>) {
    let mut ticker = Ticker::every(Duration::from_secs(1));
    loop {
        /*
        can_sender.send(
            OzysMeasurementMessage::new(
                // GET FROM CHANNEL (PUBSUB??)
            )
            .into(),
        );
        */
        ticker.next().await;
    }
}
*/

