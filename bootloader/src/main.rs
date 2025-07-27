#![no_std]
#![no_main]
#![feature(slice_as_array)]
#![feature(impl_trait_in_assoc_type)]

mod fmt;

mod can;
mod ota;

use core::{mem::MaybeUninit, ptr::write_volatile};

use can::start_can_bus_tasks;
use cortex_m::singleton;
use cortex_m_rt::entry;
use embassy_executor::Executor;
use embassy_stm32::{
    Peri,
    gpio::{Level, Output, Speed},
    peripherals::PB14,
    time::mhz,
    wdg::IndependentWatchdog,
};
use embassy_sync::blocking_mutex::raw::NoopRawMutex;
use embassy_time::{Duration, Instant, Ticker, Timer};
use firmware_common_new::can_bus::{
    messages::{
        CanBusMessageEnum,
        node_status::{NodeHealth, NodeMode, NodeStatusMessage},
        reset::ResetMessage,
    },
    receiver::CanReceiver,
    sender::CanSender,
};
use ota::ota_task;
#[cfg(feature = "defmt")]
use {defmt_rtt as _, panic_probe as _};

/// # BACKUP_RAM\[0\]:
///
/// 0x69426942 to indicate the next boot should go into bootloader.
///
/// # Trial boots
///
/// Prior to loading the main application, the bootloader will set BACKUP_RAM\[0\]
/// to 0x69426942 and start a watchdog that if not refreshed in 1 second, will reset
/// the device.
///
/// After the main application is started, it should reset BACKUP_RAM\[0\] to 0 and
/// refresh or disable the watchdog.
///
/// If the main application failed to start, the watchdog will reset the device and
/// due to the magic number in BACKUP_RAM\[0\], the device will stay in bootloader.
#[unsafe(link_section = ".backup_ram")]
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

// this needs to be the same as the APP section origin in memory.x
pub const APP_ADDRESS: u32 = 0x08010000;

#[entry]
fn main() -> ! {
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

    // this is ordered by led from top to bottom, power connector on the top left
    // LED order from top to bottom: (power connector on the top left)
    // led 2: PA10
    // led 3: PB6
    // led 4: PB7
    // led 1: PC13
    // status led: PB14
    let mut _led2 = Output::new(p.PA10, Level::Low, Speed::Low);
    let mut _led3 = Output::new(p.PB6, Level::Low, Speed::Low);
    let mut _led4 = Output::new(p.PB7, Level::Low, Speed::Low);
    let mut _led1 = Output::new(p.PC13, Level::Low, Speed::Low);

    let backup_ram = unsafe {
        #[allow(static_mut_refs)]
        BACKUP_RAM.assume_init_mut()
    };

    if backup_ram[0] != 0x69426942 {
        // no magic number found, boot normally
        configure_next_boot(BootOption::Bootloader);
        let mut wdt = IndependentWatchdog::new(p.IWDG, 1_000_000);
        wdt.unleash();

        unsafe {
            let mut p = cortex_m::Peripherals::steal();
            p.SCB.invalidate_icache();
            p.SCB.vtor.write(APP_ADDRESS);
            cortex_m::asm::bootload(APP_ADDRESS as *const u32);
        }
    }

    // enter DFU only if magic number detected
    log_info!("DFU!");
    let executor = singleton!(: Executor = Executor::new()).unwrap();
    executor.run(|spawner| {
        spawner.must_spawn(status_led_task(p.PB14));
        let (can_sender, can_receiver) = start_can_bus_tasks(&spawner, p.FDCAN3, p.PA8, p.PA15);
        spawner.must_spawn(node_status_task(can_sender));
        spawner.must_spawn(can_reset_task(can_receiver));
        spawner.must_spawn(ota_task(can_sender, can_receiver, p.FLASH));
    });
}

#[embassy_executor::task]
async fn status_led_task(yellow_led: Peri<'static, PB14>) {
    let mut yellow_led = Output::new(yellow_led, Level::High, Speed::Low);

    let mut ticker = Ticker::every(Duration::from_millis(500));
    loop {
        yellow_led.set_high();
        Timer::after_millis(50).await;
        yellow_led.set_low();
        Timer::after_millis(50).await;
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
                    mode: NodeMode::Maintenance,
                    custom_status: 0,
                }
                .into(),
            );
        ticker.next().await;
    }
}

#[embassy_executor::task]
async fn can_reset_task(can_receiver: &'static CanReceiver<NoopRawMutex, 4, 2>) {
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
#[unsafe(no_mangle)]
#[cfg_attr(target_os = "none", unsafe(link_section = ".HardFault.user"))]
#[cfg(not(feature = "defmt"))]
unsafe extern "C" fn HardFault() {
    cortex_m::peripheral::SCB::sys_reset();
}

#[cortex_m_rt::exception]
#[cfg(not(feature = "defmt"))]
unsafe fn DefaultHandler(_: i16) -> ! {
    panic!();
}

#[panic_handler]
#[cfg(not(feature = "defmt"))]
fn panic(_info: &core::panic::PanicInfo) -> ! {
    cortex_m::asm::udf();
}
