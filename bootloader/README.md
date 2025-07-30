# OZYS V3 Bootloader

## Memory Layout

The memory layout is defined in `memory.x`.

- Flash: total 512KiB
  - 32KiB for bootloader
  - 480KiB for application
- RAM: total 128KiB
  - (128KiB - 8 bytes) for bootloader or application
  - 8 bytes for bootloader state across reset

## Production Build

The production build does not include logging and is able to fit within 32KiB flash.

- Flash bootloader: `cargo run --release --no-default-features`
- Check bootloader size: `python size.py`

## Debug Build

To run the debug build, which enables logging and needs 64KiB flash space, you first need to update `memory.x` in both the bootloader project (this project) and the firmware project (`../firmware`).

- Flash bootloader: `cargo run` or the run button on top of the main function

## Debug Notes

Test bootloader behaviour without connecting to ST-Link, because ST-Link may initiate additional resets not included in the code.
