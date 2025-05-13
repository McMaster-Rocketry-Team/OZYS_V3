#![no_std]
#![no_main]

use core::ptr;

use {defmt_rtt as _, panic_probe as _};

use cortex_m::singleton;
use defmt::info;
use embassy_executor::Spawner;
use embassy_stm32::adc::{Adc, AdcChannel, SampleTime};
use embassy_stm32::{
    gpio::{Level, Output, Speed},
    time::mhz,
};
use embassy_time::Timer;

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

    let ps = Output::new(p.PA7, Level::Low, Speed::Low); // PS pin, low: force pwm
    let led1 = Output::new(p.PC13, Level::High, Speed::Low); // LED1

    info!("Hello OZYS V3!");

    let mut adc = Adc::new(p.ADC1);
    let mut vrefint_channel = adc.enable_vrefint().degrade_adc();
    adc.set_sample_time(SampleTime::CYCLES640_5);
    adc.set_differential(&mut p.PA0, true);
    let mut pa0 = p.PA0.degrade_adc();

    let read_buffer = singleton!(:[u16;2] = [0;2]).unwrap();

    let VREFINT_CAL = 0x1FFF75AA as *mut u16;
    let vref_cal = unsafe { ptr::read_volatile(VREFINT_CAL) as f32 };
    info!("VREFINT_CAL: {}", vref_cal);

    loop {
        adc.read(
            p.DMA1_CH1.reborrow(),
            [
                (&mut vrefint_channel, SampleTime::CYCLES640_5),
                (&mut pa0, SampleTime::CYCLES640_5),
            ]
            .into_iter(),
            read_buffer,
        )
        .await;

        let vrefint = read_buffer[0];
        let measured = read_buffer[1];

        let vref_plus = 3.0 * vref_cal / vrefint as f32;
        info!("Vref+: {}V", vref_plus);

        let measured = vref_plus / (1 << 12) as f32 * measured as f32;
        info!("Measured: {}V", (measured - vref_plus / 2.0) * 2.0);

        Timer::after_millis(500).await;
    }
}
