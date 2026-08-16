MEMORY
{
  /* NOTE 1 K = 1 KiBi = 1024 bytes */
  /* There is no bootloader on this board, so the firmware owns all of flash
     and links at the reset vector. */
  FLASH                             : ORIGIN = 0x08000000, LENGTH = 480K
  RAM                         (rwx) : ORIGIN = 0x20000000, LENGTH = 128K
}
