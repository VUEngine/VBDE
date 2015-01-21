OUTPUT_FORMAT("elf32-v810", "elf32-v810", "elf32-v810")
OUTPUT("a.elf") /* force elf format output */
OUTPUT_ARCH(v810)
TARGET(elf32-v810)
ENTRY(_start)
SEARCH_DIR(.);

MEMORY 
{
	ram	(!r): ORIGIN = 0x05000000, LENGTH = 64k
	rom	(rx): ORIGIN = 0x07000000, LENGTH = 16M
}

__text_vma = 0x07000000;
__data_vma = 0x05000000;

__gp = __data_vma + 0x8000;

SECTIONS
{
  .text __text_vma :
  {
    *(.text*)
  } >rom = 0xFF

  .rodata :
  {
    *(.rodata*)
  } >rom = 0xFF

  /* Stop empty section from causing a compiler error */
  /DISCARD/ :
  {
    *(.comment*)
  }

  /* Ram memory */

  __data_lma = .;
  .data __data_vma : AT(__data_lma) 
  {
    *(.data*)
  } >ram = 0xFF

  .sdata : 
  {
    *(.sdata)

  } >ram = 0xFF

  __data_end = .;

  .sbss : 
  {
    *(.sbss)
    *(.scommon)
  } >ram

  .bss : 
  {
    *(.bss*)
  } >ram = 0xFF
  /* These must appear regardless of  .  */


  /* Compute vector table address */
  /* This promotes . to a power of two */

  v = __data_lma + (__data_end - __data_vma);
  v += 0x21F;   /* add size of vector table and rom header */
  v &= 0x00FFFFFF;
  v |= v>>1;
  v |= v>>2;
  v |= v>>4;
  v |= v>>8;
  v |= v>>16;
  __vbvectors_end = __text_vma + v;
  __vbvectors_lma = __vbvectors_end - 0x21F;

  /* Place interrupt and reset vector at end of rom */

  .vbvectors __vbvectors_lma :
  { 
    KEEP (*(.vbvectors))
  } >rom = 0xFF 
}
