use embassy_stm32::{peripherals::IWDG, wdg::IndependentWatchdog, Peri};
use embassy_time::{Duration, Ticker};

/// Resets the device if the firmware stops making progress.
///
/// The timeout is deliberately several times the pet interval, so ordinary
/// scheduling jitter cannot trip it — only a task that has genuinely stopped
/// running will.
///
/// There is no CAN bootloader on this board: the firmware is linked at the
/// start of flash and a watchdog reset simply restarts it. A failing image
/// will therefore reset in a loop rather than fall back to anything, which is
/// the intended behaviour when the alternative is a strain gauge node that is
/// silently wedged mid-flight.
#[embassy_executor::task]
pub async fn watchdog_task(wdt: Peri<'static, IWDG>) {
    let mut wdt = IndependentWatchdog::new(wdt, 500_000);
    wdt.unleash();

    let mut ticker = Ticker::every(Duration::from_millis(250));
    loop {
        wdt.pet();
        ticker.next().await;
    }
}
