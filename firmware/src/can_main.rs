#![no_std]
#![no_main]

use {defmt_rtt as _, panic_probe as _};

use cortex_m::singleton;
use defmt::info;
use embassy_executor::Spawner;
use embassy_stm32::can::enums::FrameCreateError;
use embassy_stm32::can::{CanConfigurator, CanTx, Frame};
use embassy_stm32::peripherals::{FDCAN3, PB14};
use embassy_stm32::{bind_interrupts, can, Peri};
use embassy_stm32::{
    gpio::{Level, Output, Speed},
    time::mhz,
};
use embassy_sync::blocking_mutex::raw::NoopRawMutex;
use embassy_time::{Duration, Instant, Ticker, Timer};
use firmware_common_new::can_bus::id::can_node_id_from_serial_number;
use firmware_common_new::can_bus::messages::node_status::{NodeHealth, NodeMode};
use firmware_common_new::can_bus::messages::NodeStatusMessage;
use firmware_common_new::can_bus::node_types::OZYS_NODE_TYPE;
use firmware_common_new::can_bus::sender::CanSender;
use firmware_common_new::can_bus::CanBusTX;
use stm32_device_signature::device_id;

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
    info!("Hello OZYS V3!");

    spawner.must_spawn(power_led_task(p.PB14));

    let can_node_id = can_node_id_from_serial_number(device_id());
    info!("CAN Device ID: {}", can_node_id);

    let can_sender =
        singleton!(: CanSender<NoopRawMutex, 4> = CanSender::new(OZYS_NODE_TYPE, can_node_id))
            .unwrap();

    bind_interrupts!(struct Irqs {
        FDCAN3_IT0 => can::IT0InterruptHandler<FDCAN3>;
        FDCAN3_IT1 => can::IT1InterruptHandler<FDCAN3>;
    });

    let mut can = CanConfigurator::new(p.FDCAN3, p.PA8, p.PA15, Irqs);
    can.set_bitrate(250_000);
    let can = can.into_normal_mode();
    let (tx, _rx, _) = can.split();

    spawner.must_spawn(can_bus_tx_task(can_sender, tx));
    spawner.must_spawn(node_status_task(can_sender));
}

#[embassy_executor::task]
async fn power_led_task(yellow_led: Peri<'static, PB14>) {
    let mut yellow_led = Output::new(yellow_led, Level::High, Speed::Low);

    loop {
        yellow_led.set_high();
        Timer::after_millis(50).await;
        yellow_led.set_low();
        Timer::after_millis(950).await;
    }
}

#[embassy_executor::task]
async fn can_bus_tx_task(can_sender: &'static CanSender<NoopRawMutex, 4>, tx: CanTx<'static>) {
    struct TxWrapper(CanTx<'static>);
    impl CanBusTX for TxWrapper {
        type Error = FrameCreateError;

        async fn send(&mut self, id: u32, data: &[u8]) -> Result<(), Self::Error> {
            let frame = Frame::new_extended(id, data)?;

            self.0.write(&frame).await;
            // FIXME: not a big problem for now, but will be a problem if we implement OTA
            // it needs to flush all the can frames before rebooting
            // tx.flush_all().await;

            Ok(())
        }
    }

    let mut tx_wrapper = TxWrapper(tx);
    can_sender.run_daemon(&mut tx_wrapper).await;
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
                    mode: NodeMode::Operational,
                    custom_status: 0,
                }
                .into(),
            )
            .await;
        ticker.next().await;
    }
}
