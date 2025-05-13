#![no_std]
#![no_main]

use core::cell::RefCell;

use cortex_m_rt::entry;
use {defmt_rtt as _, panic_probe as _};
use embassy_boot_stm32::*;
use embassy_stm32::{flash::{Flash, BANK1_REGION}, gpio::{Level, Output, Speed}};
use embassy_sync::blocking_mutex::Mutex;

#[entry]
fn main() -> ! {
    let p = embassy_stm32::init(Default::default());
    let mut _yellow_led = Output::new(p.PB14, Level::High, Speed::Low);
    
    // Uncomment this if you are debugging the bootloader with debugger/RTT attached,
    // as it prevents a hard fault when accessing flash 'too early' after boot.
    for i in 0..10000000 {
        cortex_m::asm::nop();
    }

    let layout = Flash::new_blocking(p.FLASH).into_blocking_regions();
    let flash_bank1 = Mutex::new(RefCell::new(layout.bank1_region));
    let flash_bank2 = Mutex::new(RefCell::new(layout.bank2_region));

    let config = BootLoaderConfig::from_linkerfile_blocking(&flash_bank1, &flash_bank2, &flash_bank1);
    let active_offset = config.active.offset();
    let bl = BootLoader::prepare::<_, _, _, 2048>(config);

    unsafe { bl.load(BANK1_REGION.base + active_offset) }
}
