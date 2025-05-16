use defmt::*;
use embassy_futures::select::{select, Either};
use embassy_stm32::{
    flash::{Flash, WRITE_SIZE},
    peripherals::FLASH,
    Peri,
};
use embassy_sync::{
    blocking_mutex::raw::{NoopRawMutex, RawMutex},
    pipe::{Reader, Writer},
    signal::Signal,
};
use embassy_time::Timer;
use embedded_io_async::{Read, Write};
use firmware_common_new::{
    can_bus::{
        messages::{ack::AckMessage, data_transfer::DataType, CanBusMessageEnum},
        receiver::CanReceiver,
        sender::CanSender,
    },
    signal_with_ack::{SignalWithAckReceiver, SignalWithAckSender},
};

use crate::{configure_next_boot, BootOption, APP_ADDRESS};

#[embassy_executor::task]
async fn ota_write_disk_task(
    flash: Peri<'static, FLASH>,
    mut pipe_rx: Reader<'static, NoopRawMutex, 64>,
    reset_signal_receiver: SignalWithAckReceiver<'static, NoopRawMutex, (), ()>,
    receive_done_signal: &'static Signal<NoopRawMutex, ()>,
) {
    let mut flash = Flash::new_blocking(flash);
    const PAGE_SIZE: u32 = 2 * 1024;
    let mut firmware_write_offset = APP_ADDRESS - 0x08000000;
    let mut pipe_rx_read_buffer = [0u8; WRITE_SIZE];

    loop {
        let reset_signal_fut = reset_signal_receiver.wait();
        let read_pipe_fut = pipe_rx.read_exact(&mut pipe_rx_read_buffer);
        match select(reset_signal_fut, read_pipe_fut).await {
            Either::First(_) => {
                // firmware transmission is going to start

                // empty the existing data in the pipe
                loop {
                    if pipe_rx.try_read(&mut pipe_rx_read_buffer).is_err() {
                        break;
                    }
                }
                // reset write offset
                firmware_write_offset = APP_ADDRESS - 0x08000000;

                reset_signal_receiver.ack(());
                receive_done_signal.reset();
            }
            Either::Second(_) => {
                // Pipe can't EOF, so we dont need to handle the result returned by read_exact
                if firmware_write_offset % PAGE_SIZE == 0 {
                    flash
                        .blocking_erase(firmware_write_offset, firmware_write_offset + PAGE_SIZE)
                        .unwrap();
                }
                flash
                    .blocking_write(firmware_write_offset, &pipe_rx_read_buffer)
                    .unwrap();
                firmware_write_offset += WRITE_SIZE as u32;
            }
        };

        if receive_done_signal.try_take().is_some() {
            // all firmware has been received in the pipe
            loop {
                if pipe_rx.try_read_exact(&mut pipe_rx_read_buffer).is_err() {
                    break;
                }
                if firmware_write_offset % PAGE_SIZE == 0 {
                    flash
                        .blocking_erase(firmware_write_offset, firmware_write_offset + PAGE_SIZE)
                        .unwrap();
                }
                flash
                    .blocking_write(firmware_write_offset, &pipe_rx_read_buffer)
                    .unwrap();
                // TODO verify firmware is signed

                configure_next_boot(BootOption::Application);
                cortex_m::peripheral::SCB::sys_reset();
            }
        }
    }
}

#[embassy_executor::task]
async fn ota_receive_task(
    self_can_node_id: u16,
    can_sender: &'static CanSender<NoopRawMutex, 4>,
    can_receiver: &'static CanReceiver<NoopRawMutex, 4, 1>,
    mut pipe_tx: Writer<'static, NoopRawMutex, 64>,
    restart_signal_sender: SignalWithAckSender<'static, NoopRawMutex, (), ()>,
    receive_done_signal: &'static Signal<NoopRawMutex, ()>,
) {
    let mut can_sub = can_receiver.subscriber().unwrap();
    loop {
        let message = can_sub.next_message_pure().await.data;

        if let CanBusMessageEnum::DataTransfer(data_transfer) = message.message
            && data_transfer.data_type == DataType::Firmware
            && data_transfer.destination_node_id == self_can_node_id
        {
            if data_transfer.start_of_transfer {
                info!("Starting to receive firmware.....");
                restart_signal_sender.send_and_wait_for_ack(()).await;
            }

            pipe_tx.write_all(data_transfer.data()).await.unwrap();

            can_sender
                .send(
                    AckMessage {
                        crc: message.crc,
                        node_id: message.id.node_id,
                    }
                    .into(),
                )
                .await;

            if data_transfer.end_of_transfer {
                info!("Received firmware successfully");
                can_sender.flush().await;
                Timer::after_millis(50).await;
                receive_done_signal.signal(());
            }
        }
    }
}

#[allow(dead_code)]
trait TryReadExact {
    fn try_read_exact(&mut self, buf: &mut [u8]) -> Result<usize, ()>;
}

impl<'p, M: RawMutex, const N: usize> TryReadExact for Reader<'p, M, N> {
    fn try_read_exact(&mut self, mut buf: &mut [u8]) -> Result<usize, ()> {
        let mut total_read = 0;
        while !buf.is_empty() {
            match self.try_read(buf) {
                Ok(0) => break,
                Ok(n) => {
                    total_read += n;
                    buf = &mut buf[n..];
                }
                Err(_) => return Err(()),
            }
        }
        Ok(total_read)
    }
}
