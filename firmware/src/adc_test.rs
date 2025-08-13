#![no_std]
#![no_main]
#![feature(impl_trait_in_assoc_type)]

mod bootloader;
use core::{cell::RefCell, ptr};

use {defmt_rtt_pipe as _, panic_probe as _};

use cortex_m::{register::apsr::read, singleton};
use defmt::info;
use embassy_executor::Spawner;
use embassy_stm32::{adc::{self, Adc, AdcChannel, SampleTime}, interrupt::typelevel::TIM1_TRG_COM_TIM17, pac::Interrupt::{DMA1_CHANNEL1, TIM1_CC}, peripherals::{self, ADC1, DMA1, DMA1_CH1, PA0}, Peri};
use embassy_stm32::{
    gpio::{Level, Output, Speed},
    time::mhz,
};

use embassy_sync::{
    blocking_mutex::raw::NoopRawMutex, mutex::Mutex, pubsub::{PubSubChannel, Publisher, Subscriber, WaitResult}, signal::Signal
};
use embassy_time::{
    Duration, 
    Ticker, 
    Delay
};
use crate::bootloader::{watchdog_task};



use embassy_embedded_hal::shared_bus::asynch::spi::SpiDevice;
use embassy_stm32::{
    bind_interrupts, rng::{self}, spi::{Config as SpiConfig, Spi}
};
use embassy_stm32::{peripherals::PB3, time::Hertz};
use embedded_sdmmc::asynchronous::{Block, BlockDevice as _, BlockIdx, SdCard};
bind_interrupts!(struct Irqs { // DID I ADD THIS ACCIDENTALLY?
    RNG => rng::InterruptHandler<peripherals::RNG>;
});


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
    let mut adc= Adc::new(p.ADC1);
    let read_buffer = singleton!(:[u16;2] = [0;2]).unwrap();
    let dma = p.DMA1_CH1;
    let adc_pin = p.PA0;
    let  channel = singleton!(: PubSubChannel::<NoopRawMutex,[u16;2],4,1,1> = PubSubChannel::new()).unwrap();
    let  _pub = channel.publisher().unwrap();
    let mut _sub = channel.subscriber().unwrap();
    _spawner.must_spawn(adc_test_fn(adc, dma, adc_pin, read_buffer,_led2,_pub));

    let mut block = [Block::new()];
    match _sub.next_message().await {
        WaitResult::Message(msg)=>{
            [block[0].contents[0],block[0].contents[1]]= msg[0].to_le_bytes();
            [block[0].contents[2],block[0].contents[3]]= msg[1].to_le_bytes();
            info!("{}",&block[0].contents);
        }
        WaitResult::Lagged(missed)=>{
            info!("missed: {}",missed);
        }
    }
    // SPI TASK
    /* 
    let mut cs = Output::new(p.PB9, Level::High, Speed::High); // needed to configure as spi mode on peripheral  
    let mut spi_config = SpiConfig::default();
    spi_config.frequency = Hertz(100_000);
    let mut spi1 = Spi::new(
        p.SPI1,
        unsafe { PB3::steal() }, 
        p.PB5,
        p.PB4,
        p.DMA1_CH2, 
        p.DMA1_CH3,
        spi_config,
    );
    */
    //let spi1 = Mutex::<NoopRawMutex, _>::new(spi1); // IS THIS RIGHT MUTEX???
    //_spawner.must_spawn(single_write_sd(spi1, cs));
}

#[embassy_executor::task]
async fn adc_test_fn(
    mut _adc_peripheral: Adc<'static,ADC1>, 
    mut _dma_chanel: Peri<'static,DMA1_CH1>,
    mut _adc_pin: Peri<'static, PA0>, 
    read_buffer: &'static mut [u16;2],
    mut _led: Output<'static>,
    mut _pub: Publisher<'static, NoopRawMutex, [u16;2], 4, 1, 1>,
    ) 
    {
    let mut vrefint_channel: adc::AnyAdcChannel<ADC1> = _adc_peripheral.enable_vrefint().degrade_adc();
    _adc_peripheral.set_sample_time(SampleTime::CYCLES640_5);
    _adc_peripheral.set_differential(&mut _adc_pin, true); // Assuming takes hold of PA1
    let mut pa0: adc::AnyAdcChannel<ADC1> = _adc_pin.degrade_adc();
    let VREFINT_CAL = 0x1FFF75AA as *mut u16;
    let vref_cal = unsafe { ptr::read_volatile(VREFINT_CAL) as f32 };
    info!("VREFINT_CAL: {}", vref_cal); 
    let mut ticker = Ticker::every(Duration::from_hz(10));
    loop {
        _adc_peripheral.read( // starts code returns future and turned into statemachine cuz .await() 
            _dma_chanel.reborrow(), 
            [
                (&mut vrefint_channel, SampleTime::CYCLES640_5),
                (&mut pa0, SampleTime::CYCLES640_5),
            ]
            .into_iter(),
            read_buffer,
        )
        .await;
        _pub.publish_immediate([read_buffer[0],read_buffer[1]]);
        let vrefint = read_buffer[0];
        let measured = read_buffer[1];
        info!("Vrefint: {}, Measure: {}", vrefint,measured);
        //let vref_plus = 3.0 * vref_cal / vrefint as f32;
        //info!("Vref+: {}V", vref_plus);
        //let measured = vref_plus / (1 << 12) as f32 * measured as f32;
        //_led.toggle();
        //info!("Measured: {}V", (measured - vref_plus / 2.0) * 2.0);
        ticker.next().await;
    }
}


/* 
#[embassy_executor::task]
async fn single_write_sd(
    _spi: Mutex<NoopRawMutex, Spi<'static, embassy_stm32::mode::Async>>,
    cs: Output<'static>,
    _sub:  Subscriber<'static, NoopRawMutex, [u16; 2], 4, 1, 1>,
){
    let sd = SpiDevice::new(&_spi, cs);
    let sdcard = SdCard::new(sd, Delay);
    let size: u64 = sdcard.num_bytes().await.unwrap(); // magically abstracted spi communication? 
    let block_count = (size / 512) as u32;
    info!("Card size is {} bytes, {} blocks", size, block_count);
    let mut blocks = [Block::default()];
    let mut read_block = [Block::default()];
    let block_id = BlockIdx(0);
    sdcard.write( &blocks, block_id).await.unwrap();
    sdcard.read(&mut read_block, block_id).await.unwrap();
    info!("{}",&read_block[0].contents);
}
    */
