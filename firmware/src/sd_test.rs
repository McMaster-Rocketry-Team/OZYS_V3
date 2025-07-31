#![no_std]
#![no_main]
#![feature(impl_trait_in_assoc_type)]

mod bootloader;

use crate::bootloader::{BootOption, configure_next_boot};

use {defmt_rtt_pipe as _, panic_probe as _};

use defmt::info;
use embassy_embedded_hal::shared_bus::asynch::spi::SpiDevice;
use embassy_executor::Spawner;
use embassy_stm32::{
    bind_interrupts, peripherals,
    rng::{self},
    spi::{Config as SpiConfig, Spi},
};
use embassy_stm32::{
    gpio::{Level, Output, Speed},
    time::mhz,
};
use embassy_stm32::{peripherals::PB3, time::Hertz};
use embassy_sync::{blocking_mutex::raw::NoopRawMutex, mutex::Mutex};
use embassy_time::Delay;
use embedded_sdmmc::asynchronous::SdCard;

bind_interrupts!(struct Irqs {
    RNG => rng::InterruptHandler<peripherals::RNG>;
});

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
    configure_next_boot(BootOption::Application);

    Output::new(p.PB14, Level::High, Speed::Low);

    info!("Hello OZYS V3!");

    let mut cs = Output::new(p.PB9, Level::High, Speed::High);

    let mut spi_config = SpiConfig::default();
    spi_config.frequency = Hertz(100_000);
    let mut spi1 = Spi::new(
        p.SPI1,
        unsafe { PB3::steal() },
        p.PB5,
        p.PB4,
        p.DMA1_CH2,
        p.DMA1_CH1,
        spi_config,
    );
    let spi1 = Mutex::<NoopRawMutex, _>::new(spi1);
    let sd = SpiDevice::new(&spi1, cs);
    let sdcard = SdCard::new(sd, Delay);

    let size = sdcard.num_bytes().await.unwrap();
    let block_count = (size / 512) as u32;
    info!("Card size is {} bytes, {} blocks", size, block_count);

    // let mut blocks = [Block::default()];
    // blocks[0].fill(0x69);
    // for block_i in 0..1 {
    //     info!(
    //         "Testing block {} ({}MiB).....",
    //         block_i,
    //         (block_i as f32) * 512.0 / 1024.0 / 1024.0
    //     );

    //     let block_id = BlockIdx(block_i);
    //     sdcard.write(&mut blocks, block_id).await.unwrap();

    //     sdcard.read(&mut blocks, block_id).await.unwrap();
    //     // let check_sum = crc.feed_bytes(&blocks[0].contents[..508]);
    //     // let check_sum2 = u32::from_le_bytes(blocks[0].contents[508..512].try_into().unwrap());
    //     // if check_sum != check_sum2 {
    //     //     info!("Failed, checksum mismatch: {} != {}", check_sum, check_sum2);
    //     //     break;
    //     // }
    // }

    info!("SD Card test passed!")
}
