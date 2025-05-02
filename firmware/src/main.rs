#![no_std]
#![no_main]

use {defmt_rtt as _, panic_probe as _};

use defmt::info;
use embassy_executor::Spawner;
use embassy_stm32::gpio::{Level, Output, Speed};
use embassy_time::{Duration, Timer};

#[embassy_executor::main]
async fn main(_spawner: Spawner) {
    let p = embassy_stm32::init(Default::default());
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
