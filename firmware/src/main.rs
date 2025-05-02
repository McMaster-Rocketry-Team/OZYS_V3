#![no_std]
#![no_main]

use {defmt_rtt as _, panic_probe as _};

use defmt::info;
use embassy_executor::Spawner;
use embassy_stm32::{
    gpio::{Level, Output, Speed},
    time::mhz,
};
use embassy_time::{Duration, Timer};

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

    let mut status_led = Output::new(p.PB14, Level::Low, Speed::Low);
    let mut led1 = Output::new(p.PC13, Level::Low, Speed::Low);
    let mut led2 = Output::new(p.PA10, Level::Low, Speed::Low);
    let mut led3 = Output::new(p.PB6, Level::Low, Speed::Low);
    let mut led4 = Output::new(p.PB7, Level::Low, Speed::Low);

    info!("Hello OZYS V3!");

    loop {
        status_led.set_high();
        Timer::after(Duration::from_millis(500)).await;
        status_led.set_low();
        led1.set_high();
        Timer::after(Duration::from_millis(500)).await;
        led1.set_low();
        led4.set_high();
        Timer::after(Duration::from_millis(500)).await;
        led4.set_low();
        led3.set_high();
        Timer::after(Duration::from_millis(500)).await;
        led3.set_low();
        led2.set_high();
        Timer::after(Duration::from_millis(500)).await;
        led2.set_low();
    }
}
