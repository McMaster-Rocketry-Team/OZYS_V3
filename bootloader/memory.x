MEMORY
{
  /* NOTE 1 K = 1 KiBi = 1024 bytes */
  FLASH                             : ORIGIN = 0x08000000, LENGTH = 64K
  APP                               : ORIGIN = 0x08010000, LENGTH = 448K
  RAM                         (rwx) : ORIGIN = 0x20000000, LENGTH = 127K
  BACKUP_RAM                        : ORIGIN = 0x2001fc00, LENGTH = 1K
}

SECTIONS
{
    .backup_ram :
    {
        *(.backup_ram)
    } > BACKUP_RAM
}

__bootloader_app_start = ORIGIN(APP) - ORIGIN(FLASH);
__bootloader_app_end = ORIGIN(APP) - ORIGIN(FLASH) + LENGTH(APP);
