/* Default linker script, for normal executables */
OUTPUT_FORMAT("elf32-v810", "elf32-v810",
	      "elf32-v810")
OUTPUT_ARCH(v810)
ENTRY(_start)
SEARCH_DIR(.);
EXTERN(__gp __tp __tpend __zpdat __zpbss __zpend);
SECTIONS
{
  /* Read-only sections, merged into text segment.  */
  . = 0x8000;
  .interp	: { *(.interp) }
  .hash		: { *(.hash) }
  .dynsym	: { *(.dynsym) }
  .dynstr	: { *(.dynstr) }
  .rel.text	: { *(.rel.text) }
  .rela.text	: { *(.rela.text) }
  .rel.data	: { *(.rel.data) }
  .rela.data	: { *(.rela.data) }
  .rel.rodata	: { *(.rel.rodata) }
  .rela.rodata	: { *(.rela.rodata) }
  .rel.gcc_except_table : { *(.rel.gcc_except_table) }
  .rela.gcc_except_table : { *(.rela.gcc_except_table) }
  .rel.got	: { *(.rel.got) }
  .rela.got	: { *(.rela.got) }
  .rel.ctors	: { *(.rel.ctors) }
  .rela.ctors	: { *(.rela.ctors) }
  .rel.dtors	: { *(.rel.dtors) }
  .rela.dtors	: { *(.rela.dtors) }
  .rel.init	: { *(.rel.init) }
  .rela.init	: { *(.rela.init) }
  .rel.fini	: { *(.rel.fini) }
  .rela.fini	: { *(.rela.fini) }
  .rel.bss	: { *(.rel.bss) }
  .rela.bss	: { *(.rela.bss) }
  .rel.plt	: { *(.rel.plt) }
  .rela.plt	: { *(.rela.plt) }
  .init		: { KEEP (*(.init)) } =0
  .plt		: { *(.plt) }
  .text		:
  {
    *(.text)
    *(.text.*)
    /* .gnu.warning sections are handled specially by elf32.em.  */
    *(.gnu.warning)
    *(.gnu.linkonce.t*)
  } =0
  _etext = .;
  PROVIDE (etext = .);
  .fini		: { KEEP (*(.fini)) } =0
  .rodata	: { *(.rodata) *(.rodata.*) *(.gnu.linkonce.r*) }
  .rodata1	: { *(.rodata1) }
  .data		:
  {
    *(.data)
    *(.data.*)
    *(.gnu.linkonce.d*)
    CONSTRUCTORS
  }
  .data1	: { *(.data1) }
  .ctors	:
  {
    ___ctors = .;
    KEEP (*(EXCLUDE_FILE (*crtend.o) .ctors))
    KEEP (*(SORT(.ctors.*)))
    KEEP (*crtend(.ctors))
    ___ctors_end = .;
  }
  .dtors	:
  {
    ___dtors = .;
    KEEP (*(EXCLUDE_FILE (*crtend.o) .dtors))
    KEEP (*(SORT(.dtors.*)))
    KEEP (*crtend.o(.dtors))
    ___dtors_end = .;
  }
  .jcr		:
  {
    KEEP (*(.jcr))
  }
  .gcc_except_table : { *(.gcc_except_table) }
  .got		: { *(.got.plt) *(.got) }
  .dynamic	: { *(.dynamic) }
  .tdata ALIGN (8) :
  {
	PROVIDE (__tp = .);
	*(.tbyte)
	*(.tcommon_byte)
	*(.tdata)
	*(.tbss)
	*(.tcommon)
	. = ALIGN(8);
	PROVIDE (__tpend = .);
  }
  /* We want the small data sections together, so single-instruction offsets
     can access them all, and initialized data all before uninitialized, so
     we can shorten the on-disk segment size.  */
  .sdata ALIGN (8) :
  {
	PROVIDE (__gp = . + 0x8000);
	. = 0x58;
	*(.sdata)
  }
  /* This is the read only part of the small data area.
     Having it as a seperate section prevents its
     attributes from being inherited by the sdata
     section.  Specifically it prevents the sdata
     section from being marked READONLY.  */
  .rosdata ALIGN (4) :
  {
	*(.rosdata)
  }
  /* We place the .sbss data section AFTER the .rosdata section, so that
     it can directly preceed the .bss section.  This allows runtime startup
     code to initialise all the zero-data sections by simply taking the
     value of '_edata' and zeroing until it reaches '_end'.  */
  . = ALIGN(16);
  .sbss  :
  {
	__sbss_start = .;
	*(.sbss)
	*(.scommon)
  }
  _edata  = DEFINED (__sbss_start) ? __sbss_start : . ;
  PROVIDE (edata = _edata);
  .bss       :
  {
	__bss_start = DEFINED (__sbss_start) ? __sbss_start : . ;
	__real_bss_start = . ;
	*(.dynbss)
	*(.bss)
	*(COMMON)
  }
  . = ALIGN(16);
  _end = . ;
  PROVIDE (end = .);
  PROVIDE (_heap_start = .);
  /* Put all initialized R0-relative data at the end of the output file on
     top of the .sbss/.bss sections so that it can be copied into place at
     startup and then wiped to zero for use as the .sbss/.bss  */
  . = 0x0;
	. = ALIGN(8);
	PROVIDE (__zpdat = .);
  .zdata : AT ( _edata )
  {
	*(.rozdata)
	*(.zdata)
  }
	. = ALIGN(8);
	PROVIDE (__zpbss = .);
  .zbss : AT ( ADDR (.zdata) + SIZEOF (.zdata) )
  {
	*(.zbss)
	*(.zcommon)
  }
	. = ALIGN(8);
	PROVIDE (__zpend = .);
  /* Stabs debugging sections.  */
  .stab 0		: { *(.stab) }
  .stabstr 0		: { *(.stabstr) }
  .stab.excl 0		: { *(.stab.excl) }
  .stab.exclstr 0	: { *(.stab.exclstr) }
  .stab.index 0		: { *(.stab.index) }
  .stab.indexstr 0	: { *(.stab.indexstr) }
  .comment 0		: { *(.comment) }
  /* DWARF debug sections.
     Symbols in the DWARF debugging sections are relative to the beginning
     of the section so we begin them at 0.  */
  /* DWARF 1 */
  .debug          0	: { *(.debug) }
  .line           0	: { *(.line) }
  /* GNU DWARF 1 extensions */
  .debug_srcinfo  0	: { *(.debug_srcinfo) }
  .debug_sfnames  0	: { *(.debug_sfnames) }
  /* DWARF 1.1 and DWARF 2 */
  .debug_aranges  0	: { *(.debug_aranges) }
  .debug_pubnames 0	: { *(.debug_pubnames) }
  /* DWARF 2 */
  .debug_info     0	: { *(.debug_info) *(.gnu.linkonce.wi.*) }
  .debug_abbrev   0	: { *(.debug_abbrev) }
  .debug_line     0	: { *(.debug_line) }
  .debug_frame    0	: { *(.debug_frame) }
  .debug_str      0	: { *(.debug_str) }
  .debug_loc      0	: { *(.debug_loc) }
  .debug_macinfo  0	: { *(.debug_macinfo) }
  /* SGI/MIPS DWARF 2 extensions.  */
  .debug_weaknames 0	: { *(.debug_weaknames) }
  .debug_funcnames 0	: { *(.debug_funcnames) }
  .debug_typenames 0	: { *(.debug_typenames) }
  .debug_varnames  0	: { *(.debug_varnames) }
  /* DWARF 3 */
  .debug_pubtypes 0 : { *(.debug_pubtypes) }
  .debug_ranges   0 : { *(.debug_ranges) }
  /* DWARF Extension.  */
  .debug_macro    0 : { *(.debug_macro) }
  /* User stack.  */
  .stack 0x200000	:
  {
	__stack = .;
	*(.stack)
  }
}
