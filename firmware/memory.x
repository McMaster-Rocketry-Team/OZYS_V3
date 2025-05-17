MEMORY
{
  /* NOTE 1 K = 1 KiBi = 1024 bytes */
  BOOTLOADER                        : ORIGIN = 0x08000000, LENGTH = 64K
  FLASH                             : ORIGIN = 0x08010000, LENGTH = 448K
  RAM                         (rwx) : ORIGIN = 0x20000000, LENGTH = 127K
  BACKUP_RAM                  (rwx) : ORIGIN = 0x2001fc00, LENGTH = 1K
}

SECTIONS
{
    .backup_ram (NOLOAD):
    {
        *(.backup_ram)
    } > BACKUP_RAM
}
