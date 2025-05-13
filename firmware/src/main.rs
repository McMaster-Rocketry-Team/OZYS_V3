#![no_std]
#![no_main]
#![feature(let_chains)]

mod can;
mod ota;

use {defmt_rtt as _, panic_probe as _};

use can::start_can_bus_tasks;
use defmt::info;
use embassy_executor::Spawner;
use embassy_stm32::peripherals::PB14;
use embassy_stm32::Peri;
use embassy_stm32::{
    gpio::{Level, Output, Speed},
    time::mhz,
};
use embassy_sync::blocking_mutex::raw::NoopRawMutex;
use embassy_time::{Duration, Instant, Ticker, Timer};
use firmware_common_new::can_bus::messages::node_status::{NodeHealth, NodeMode};
use firmware_common_new::can_bus::messages::NodeStatusMessage;
use firmware_common_new::can_bus::sender::CanSender;
use ota::start_ota_tasks;

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
    let p = embassy_stm32::init(config);
    info!("Hello OZYS V3!");

    spawner.must_spawn(status_led_task(p.PB14));
    let (self_can_node_id, can_sender, can_receiver) =
        start_can_bus_tasks(&spawner, p.FDCAN3, p.PA8, p.PA15).await;
    start_ota_tasks(
        &spawner,
        self_can_node_id,
        can_sender,
        can_receiver,
        p.FLASH,
    )
    .await;
    spawner.must_spawn(node_status_task(can_sender));

    info!("All tasks started");

    // let mut led1 = Output::new(p.PC13, Level::Low, Speed::Low);
    // let mut led2 = Output::new(p.PA10, Level::Low, Speed::Low);
    // let mut led3 = Output::new(p.PB6, Level::Low, Speed::Low);
    // let mut led4 = Output::new(p.PB7, Level::Low, Speed::Low);

    // let now = NaiveDate::from_ymd_opt(2025, 5, 2)
    //     .unwrap()
    //     .and_hms_opt(10, 30, 15)
    //     .unwrap();

    // let mut rtc = Rtc::new(p.RTC, RtcConfig::default());

    // rtc.set_datetime(now.into()).unwrap();
    // let now: NaiveDateTime = rtc.now().unwrap().into();
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
        can_sender
            .send(
                NodeStatusMessage {
                    uptime_s: Instant::now().as_secs() as u32,
                    health: NodeHealth::Healthy,
                    mode: NodeMode::Operational,
                    custom_status: 0,
                }
                .into(),
            )
            .await;
        ticker.next().await;
    }
}
