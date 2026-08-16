use cortex_m::singleton;
use defmt::info;
use embassy_executor::Spawner;
use embassy_stm32::{
    Peri, bind_interrupts,
    can::{
        self, CanConfigurator, CanRx, CanTx, Frame,
        config::GlobalFilter,
        enums::{BusError, FrameCreateError},
        filter::{Action, ExtendedFilter, ExtendedFilterSlot, FilterType},
        frame::Envelope,
    },
    peripherals::{FDCAN3, PA8, PA15},
};
use embassy_sync::blocking_mutex::raw::NoopRawMutex;
use firmware_common_new::can_bus::{
    CanBusFrame, CanBusRX, CanBusTX,
    id::{CanBusExtendedId, can_node_id_from_serial_number, create_can_bus_message_type_filter_mask},
    messages::{DATA_TRANSFER_MESSAGE_TYPE, VL_STATUS_MESSAGE_TYPE},
    node_types::OZYS_NODE_TYPE,
    receiver::CanReceiver,
    sender::CanSender,
};
use stm32_device_signature::device_id;

pub async fn start_can_bus_tasks(
    spawner: &Spawner,

    fdcan3: Peri<'static, FDCAN3>,
    pa8: Peri<'static, PA8>,
    pa15: Peri<'static, PA15>,
) -> (
    &'static CanSender<NoopRawMutex>,
    &'static CanReceiver<NoopRawMutex, 4, 4>,
) {
    let can_node_id = can_node_id_from_serial_number(device_id());
    info!("CAN Device ID: {}", can_node_id);

    let can_sender =
        singleton!(: CanSender<NoopRawMutex> = CanSender::new(OZYS_NODE_TYPE, can_node_id,  Some(&defmt_rtt_pipe::PIPE)))
            .unwrap();
    let can_receiver =
        singleton!(: CanReceiver<NoopRawMutex, 4, 4> = CanReceiver::new(can_node_id)).unwrap();

    bind_interrupts!(struct Irqs {
        FDCAN3_IT0 => can::IT0InterruptHandler<FDCAN3>;
        FDCAN3_IT1 => can::IT1InterruptHandler<FDCAN3>;
    });

    let mut can = CanConfigurator::new(fdcan3, pa8, pa15, Irqs);
    can.set_bitrate(1_000_000);

    // Hardware-filter the bus down to the message types this node consumes
    // (plus Reset and UnixTime, which the mask helper always accepts). The
    // flight computer floods the bus with ~1k measurement frames/s; every one
    // of them otherwise raises an rx interrupt and gets decoded, only to be
    // dropped, while the strain gauge ADCs are sampling on a hard deadline.
    //
    // FDCAN needs both halves of this: the filter below matches the frames we
    // want, and the global filter decides what happens to everything else.
    // Its default is `IntoRxFifo0` (accept), so setting the filter alone would
    // change nothing at all. FDCAN's classic filter accepts a frame iff
    // `incoming & mask == filter & mask`, which with `filter = 0` is exactly
    // the helper's `incoming & mask == 0` contract. Standard frames are
    // rejected wholesale — this protocol only uses extended IDs.
    let filter_mask = create_can_bus_message_type_filter_mask(&[VL_STATUS_MESSAGE_TYPE]);
    can.properties().set_extended_filter(
        ExtendedFilterSlot::_0,
        ExtendedFilter {
            filter: FilterType::BitMask {
                filter: 0,
                mask: filter_mask,
            },
            action: Action::StoreInFifo0,
        },
    );
    let config = can.config().set_global_filter(GlobalFilter::reject_all());
    can.set_config(config);

    let can = can.into_normal_mode();
    let (tx, rx, _) = can.split();

    spawner.must_spawn(can_bus_tx_task(can_sender, tx));
    spawner.must_spawn(can_bus_rx_task(can_receiver, rx));

    (can_sender, can_receiver)
}

#[embassy_executor::task]
async fn can_bus_tx_task(can_sender: &'static CanSender<NoopRawMutex>, tx: CanTx<'static>) {
    struct TxWrapper(CanTx<'static>);
    impl CanBusTX for TxWrapper {
        type Error = FrameCreateError;

        async fn send(&mut self, id: u32, data: &[u8]) -> Result<(), Self::Error> {
            let frame = Frame::new_extended(id, data)?;
            self.0.write(&frame).await;
            Ok(())
        }
    }

    let mut tx_wrapper = TxWrapper(tx);
    can_sender.run_daemon(&mut tx_wrapper).await;
}

#[embassy_executor::task]
async fn can_bus_rx_task(
    can_receiver: &'static CanReceiver<NoopRawMutex, 4, 4>,
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
            loop {
                let frame = self.0.read().await.map(EnvelopeWrapper)?;
                let id = CanBusExtendedId::from_raw(frame.id());

                // Redundant with the hardware filter installed above, which
                // already rejects data transfer frames before they reach a
                // FIFO. Kept as a backstop so that widening the accept list
                // (for OTA, say) cannot silently start feeding OTA payloads
                // into the message decoder.
                if id.message_type != DATA_TRANSFER_MESSAGE_TYPE {
                    return Ok(frame);
                }
            }
        }
    }

    let mut rx_wrapper = RxWrapper(rx);
    can_receiver.run_daemon::<_, 8>(&mut rx_wrapper).await;
}
