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
    bind_interrupts, pac::crc::Crc, peripherals, rng::{self}, spi::{Config as SpiConfig, Spi}
};
use embassy_stm32::{
    gpio::{Level, Output, Speed},
    time::mhz,
};
use embassy_stm32::{peripherals::PB3, time::Hertz};

use embassy_sync::{blocking_mutex::raw::NoopRawMutex, mutex::Mutex};
use embassy_time::Delay;
use embedded_sdmmc::asynchronous::{Block, BlockDevice as _, BlockIdx, SdCard};

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
                                                                    // is it opposite?? Level::Low? 
    let mut cs = Output::new(p.PB9, Level::High, Speed::High); // needed to configure as spi mode on peripheral  

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
    _spawner.must_spawn(sd_test_fn(spi1, cs));
    info!("SD Card test passed!")
}

#[embassy_executor::task]
async fn sd_test_fn(
    _spi: Mutex<NoopRawMutex, Spi<'static, embassy_stm32::mode::Async>>,
    cs: Output<'static>,
){
    let sd = SpiDevice::new(&_spi, cs);
    let sdcard = SdCard::new(sd, Delay);
    let size: u64 = sdcard.num_bytes().await.unwrap(); // magically abstracted spi communication? 
    let block_count = (size / 512) as u32;
    info!("Card size is {} bytes, {} blocks", size, block_count);
    let mut blocks = [Block::default()];
    let mut read_block = [Block::default()];
    for block_i in 0..10 {
        blocks[0].fill(block_i as u8);
        info!(
            "Testing block {} ({}MiB).....",
            block_i,
            (block_i as f32 + 1.0) * 512.0 / 1024.0 / 1024.0 // Mb at block[i] = i blocks *512 bytes each block / 1024bytes each Kb / 1024kb each Mb
        );
        let block_id = BlockIdx(block_i);
        sdcard.write(&mut blocks, block_id).await.unwrap();
        sdcard.read(&mut read_block, block_id).await.unwrap();
        info!("{}",read_block[0].contents.clone());
    }
}
