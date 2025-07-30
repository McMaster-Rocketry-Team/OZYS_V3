# OZYS V3 Firmware (Application)

The bootloader (`../bootloader`) is required to be flashed to OZYS first before the application can be run.

## Memory Layout

The memory layout is defined in `memory.x`.

- Flash: total 512KiB
  - 32KiB for bootloader
  - 480KiB for application
- RAM: total 128KiB
  - (128KiB - 8 bytes) for bootloader or application
  - 8 bytes for bootloader state across reset

## Notes

- Flash firmware: `cargo run`
- Check firmware size: `python size.py`

`dev` profile and `release` profile are the same, so its fine to use the run button for final production firmware.

## rocket-cli

`rocket-cli` is a tool that simplifies uploading code and monitoring logs. Install it globally to the system by first cd into `<path-to-rust-monorepo>/rocket-cli` then run `cargo install --profile rocket-cli --path . --locked`

`rocket-cli` uses ST-Link or bluetooth for uploading depending on if an ST-Link is connected.

## Troubleshooting

If you think your code should run but the stm does not start or stops in the middle of execution:

1. Switch back from `rocket-cli` to `probe-rs` in `.cargo/config.toml`
2. Do not connect to ST-Link, instead use an external power
3. Power cycle stm to reset bootloader state
