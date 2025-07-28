MEMORY
{
  /* NOTE 1 K = 1 KiBi = 1024 bytes */
  FLASH                             : ORIGIN = 0x08008000, LENGTH = 480K
  /* FLASH                             : ORIGIN = 0x08010000, LENGTH = 448K */
  RAM                         (rwx) : ORIGIN = 0x20000000, LENGTH = 131064 /* 128K - 8 */
  BACKUP_RAM                        : ORIGIN = 0x2001fffc, LENGTH = 8
}

SECTIONS
{
    .backup_ram (NOLOAD):
    {
        *(.backup_ram)
    } > BACKUP_RAM
}
