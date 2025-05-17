use cortex_m::singleton;
use embassy_executor::Spawner;
use embassy_stm32::{
    bind_interrupts,
    can::{
        self,
        enums::{BusError, FrameCreateError},
        frame::Envelope,
        CanConfigurator, CanRx, CanTx, Frame,
    },
    peripherals::{FDCAN3, PA15, PA8},
    Peri,
};
use embassy_sync::blocking_mutex::raw::NoopRawMutex;
use firmware_common_new::can_bus::{
    id::can_node_id_from_serial_number, node_types::OZYS_NODE_TYPE, receiver::CanReceiver,
    sender::CanSender, CanBusFrame, CanBusRX, CanBusTX,
};
use stm32_device_signature::device_id;

pub fn start_can_bus_tasks(
    spawner: &Spawner,

    fdcan3: Peri<'static, FDCAN3>,
    pa8: Peri<'static, PA8>,
    pa15: Peri<'static, PA15>,
) -> (
    &'static CanSender<NoopRawMutex, 4>,
    &'static CanReceiver<NoopRawMutex, 4, 2>,
) {
    let can_node_id = can_node_id_from_serial_number(device_id());
    log_info!("CAN Device ID: {}", can_node_id);

    let can_sender =
        singleton!(: CanSender<NoopRawMutex, 4> = CanSender::new(OZYS_NODE_TYPE, can_node_id))
            .unwrap();
    let can_receiver =
        singleton!(: CanReceiver<NoopRawMutex, 4, 2> = CanReceiver::new(can_node_id)).unwrap();

    bind_interrupts!(struct Irqs {
        FDCAN3_IT0 => can::IT0InterruptHandler<FDCAN3>;
        FDCAN3_IT1 => can::IT1InterruptHandler<FDCAN3>;
    });

    let mut can = CanConfigurator::new(fdcan3, pa8, pa15, Irqs);
    can.set_bitrate(1_000_000);
    let can = can.into_normal_mode();
    let (tx, rx, _) = can.split();

    spawner.must_spawn(can_bus_tx_task(can_sender, tx));
    spawner.must_spawn(can_bus_rx_task(can_receiver, rx));

    (can_sender, can_receiver)
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
async fn can_bus_rx_task(
    can_receiver: &'static CanReceiver<NoopRawMutex, 4, 2>,
    rx: CanRx<'static>,
) {
    struct RxWrapper(CanRx<'static>);
    struct EnvelopeWrapper(Envelope);

    impl CanBusFrame for EnvelopeWrapper {
        fn timestamp_us(&self) -> u64 {
            self.0.ts.as_micros()
        }

        fn id(&self) -> u32 {
            match self.0.frame.id() {
                embedded_can::Id::Standard(standard_id) => standard_id.as_raw() as u32,
                embedded_can::Id::Extended(extended_id) => extended_id.as_raw() as u32,
            }
        }

        fn data(&self) -> &[u8] {
            self.0.frame.data()
        }
    }

    impl CanBusRX for RxWrapper {
        type Error = BusError;
        type Frame = EnvelopeWrapper;

        async fn receive(&mut self) -> Result<Self::Frame, Self::Error> {
            let frame = self.0.read().await.map(EnvelopeWrapper)?;
            Ok(frame)
        }
    }

    let mut rx_wrapper = RxWrapper(rx);
    can_receiver.run_daemon::<_, 8>(&mut rx_wrapper, None).await;
}
