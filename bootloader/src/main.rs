#![no_std]
#![no_main]

use core::cell::RefCell;

use cortex_m::asm;
use cortex_m_rt::{entry, exception};
// use defmt::{info, warn};
use embassy_boot_stm32::*;
use embassy_stm32::{
    flash::{Flash, BANK1_REGION},
    gpio::{Level, Output, Speed},
};
use embassy_sync::blocking_mutex::Mutex;
// use {defmt_rtt as _, panic_probe as _};

#[entry]
fn main() -> ! {
    let p = embassy_stm32::init(Default::default());
    let mut bl_led1 = Output::new(p.PC13, Level::High, Speed::Low);
    let mut first_led4 = Output::new(p.PB7, Level::Low, Speed::Low);
    let mut updated_led3 = Output::new(p.PB6, Level::Low, Speed::Low);
    for i in 0..5000000 {
        asm::nop();
    }
    // info!("Hello bootloader!");

    // Uncomment this if you are debugging the bootloader with debugger/RTT attached,
    // as it prevents a hard fault when accessing flash 'too early' after boot.
    // for i in 0..1000000 {
    //     asm::nop();
    // }

    let layout = Flash::new_blocking(p.FLASH).into_blocking_regions();
    let flash_bank1 = Mutex::new(RefCell::new(layout.bank1_region));
    let flash_bank2 = Mutex::new(RefCell::new(layout.bank2_region));

    let config =
        BootLoaderConfig::from_linkerfile_blocking(&flash_bank1, &flash_bank2, &flash_bank1);
    let active_offset = config.active.offset();

    // unsafe {
    //     let mut p = cortex_m::Peripherals::steal();
    //     p.SCB.invalidate_icache();
    //     p.SCB.vtor.write(BANK1_REGION.base + active_offset);

    //     cortex_m::asm::bootload((BANK1_REGION.base + active_offset) as *const u32);
    // }

    let result = BootLoader::try_prepare::<_, _, _, 2048>(config);

    match result {
        Ok(bl) => {
            // info!(
            //     "bootloader initialized, booting to address {:X}",
            //     BANK1_REGION.base + active_offset
            // );
            unsafe { bl.load(BANK1_REGION.base + active_offset) }
        }
        Err(e) => {
            // warn!("failed to perpare bootloader: {}", e);
        }
    };

    loop {
        asm::nop();
    }
}

#[no_mangle]
#[cfg_attr(target_os = "none", link_section = ".HardFault.user")]
unsafe extern "C" fn HardFault() {
    cortex_m::peripheral::SCB::sys_reset();
}

#[exception]
unsafe fn DefaultHandler(_: i16) -> ! {
    const SCB_ICSR: *const u32 = 0xE000_ED04 as *const u32;
    let irqn = core::ptr::read_volatile(SCB_ICSR) as u8 as i16 - 16;

    panic!("DefaultHandler #{:?}", irqn);
}

#[panic_handler]
fn panic(_info: &core::panic::PanicInfo) -> ! {
    cortex_m::asm::udf();
}