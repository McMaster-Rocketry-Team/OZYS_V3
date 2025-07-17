#![no_std]
#![no_main]
#![feature(impl_trait_in_assoc_type)]

use core::{mem::MaybeUninit, ptr::{self, write_volatile}};

use {defmt_rtt as _, panic_probe as _};

use cortex_m::singleton;
use defmt::info;
use embassy_executor::Spawner;
use embassy_stm32::{adc::{Adc, AdcChannel, SampleTime}, peripherals::IWDG, wdg::IndependentWatchdog, Peri};
use embassy_stm32::{
    gpio::{Level, Output, Speed},
    time::mhz,
};
use embassy_time::{Duration, Ticker, Timer};

#[link_section = ".backup_ram"]
static mut BACKUP_RAM: MaybeUninit<[u32; 256]> = MaybeUninit::uninit();

pub enum BootOption {
    Bootloader,
    Application,
}

pub fn configure_next_boot(boot_option: BootOption) {
    let backup_ram = unsafe {
        #[allow(static_mut_refs)]
        BACKUP_RAM.assume_init_mut()
    };
    let magic = match boot_option {
        BootOption::Bootloader => 0x69426942,
        BootOption::Application => 0,
    };
    unsafe {
        write_volatile(backup_ram.as_mut_ptr(), magic);
    }
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
    let mut p = embassy_stm32::init(config);

    let mut ps = Output::new(p.PA7, Level::High, Speed::Low); // PS pin, low: force pwm

    info!("Hello OZYS V3!");

    configure_next_boot(BootOption::Application);
    _spawner.must_spawn(watchdog_task(p.IWDG));

    loop {
        // ps.toggle();

        Timer::after_millis(2000).await;
    }
}

#[embassy_executor::task]
async fn watchdog_task(wdt: Peri<'static, IWDG>) {
    configure_next_boot(BootOption::Application);
    let mut wdt = IndependentWatchdog::new(wdt, 500_000);
    wdt.unleash();

    let mut ticker = Ticker::every(Duration::from_millis(250));
    loop {
        wdt.pet();
        ticker.next().await;
    }
}