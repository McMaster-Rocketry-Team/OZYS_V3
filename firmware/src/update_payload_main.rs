#![no_std]
#![no_main]
#![feature(let_chains)]

use {defmt_rtt as _, panic_probe as _};

use defmt::info;
use embassy_boot::{AlignedBuffer, FirmwareState, FirmwareUpdaterConfig};
use embassy_embedded_hal::adapter::BlockingAsync;
use embassy_executor::Spawner;
use embassy_stm32::flash::{Flash, WRITE_SIZE};
use embassy_stm32::gpio::AnyPin;
use embassy_stm32::peripherals::PC13;
use embassy_stm32::Peri;
use embassy_stm32::{
    gpio::{Level, Output, Speed},
    time::mhz,
};
use embassy_sync::mutex::Mutex;
use embassy_time::{Duration, Ticker, Timer};

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
    let mut bl_led1 = Output::new(p.PC13, Level::Low, Speed::Low);
    let mut first_led4 = Output::new(p.PB7, Level::Low, Speed::Low);
    spawner.must_spawn(status_led_task(p.PB6.into()));
    info!("Hello OZYS V3 updated!");

    let flash = Flash::new_blocking(p.FLASH);
    let flash = Mutex::new(BlockingAsync::new(flash));
    let config = FirmwareUpdaterConfig::from_linkerfile(&flash, &flash);
    let mut magic = AlignedBuffer([0; WRITE_SIZE]);
    let mut firmware_state = FirmwareState::from_config(config, &mut magic.0);
    firmware_state.mark_booted().await.unwrap();
}

#[embassy_executor::task]
async fn status_led_task(led: Peri<'static, AnyPin>) {
    let mut led = Output::new(led, Level::High, Speed::Low);

    let mut ticker = Ticker::every(Duration::from_millis(100));
    loop {
        led.set_high();
        Timer::after_millis(50).await;
        led.set_low();
        ticker.next().await;
    }
}
