# OZYS Firmware (Application)

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
