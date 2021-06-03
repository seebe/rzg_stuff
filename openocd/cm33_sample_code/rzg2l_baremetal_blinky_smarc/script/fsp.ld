/*
                  Linker File for Renesas FSP
*/

INCLUDE memory_regions_secure_area.ld

/* Define memory regions. */
MEMORY
{
  SRAM_S   (rwx)    : ORIGIN = SRAM_S_START,    LENGTH = SRAM_S_LENGTH
  SRAM_S_L (rwx)    : ORIGIN = SRAM_S_START_L,  LENGTH = SRAM_S_LENGTH
  SRAM_N   (rwx)    : ORIGIN = SRAM_N_START,    LENGTH = SRAM_N_LENGTH
  SRAM_N_L (rwx)    : ORIGIN = SRAM_N_START_L,  LENGTH = SRAM_N_LENGTH
  CODE_S   (rx)     : ORIGIN = CODE_S_START,    LENGTH = CODE_S_LENGTH
  CODE_S_L (rx)     : ORIGIN = CODE_S_START_L,  LENGTH = CODE_S_LENGTH
  CODE_N   (rx)     : ORIGIN = CODE_N_START,    LENGTH = CODE_N_LENGTH
  CODE_N_L (rx)     : ORIGIN = CODE_N_START_L,  LENGTH = CODE_N_LENGTH
}

/* Library configurations */
GROUP(libgcc.a libc.a libm.a libnosys.a)

/* Linker script to place sections and symbol values. Should be used together
 * with other linker script that defines memory regions CODE and SRAM.
 * It references following symbols, which must be defined in code:
 *   Reset_Handler_S : Entry of secure reset handler
 *
 * It defines following symbols, which code can use without definition:
 *   __exidx_start
 *   __exidx_end
 *   __copy_table_start__
 *   __copy_table_end__
 *   __zero_table_start__
 *   __zero_table_end__
 *   __etext
 *   __data_start__
 *   __preinit_array_start
 *   __preinit_array_end
 *   __init_array_start
 *   __init_array_end
 *   __fini_array_start
 *   __fini_array_end
 *   __data_end__
 *   __bss_start__
 *   __bss_end__
 *   __HeapLimit
 *   __StackLimit
 *   __StackTop
 *   __stack
 *   __Vectors_End
 *   __Vectors_Size
 */
ENTRY(Reset_Handler_S)
SECTIONS
{
	__tz_CODE_S = ABSOLUTE(CODE_S_START);
	. = __tz_CODE_S;
	.secure :
	{
		__CODE_S_Start = .;
		/* Even though the vector table is not 16 entries (64B) long, we still allocate that much space. */
		KEEP(*(.fixed_secure_vectors*))
		/* start at address 0x00000040 */
		. = __CODE_S_Start + 0x00000040;

		*\bsp_security.o (.text)
		*\bsp_security.o (.text.*)
		*\bsp_security.o (.rodata)
		*\bsp_security.o (.rodata.*)
		*\bsp_irqs.o (.text)
		*\bsp_irqs.o (.text.*)
		*\bsp_irqs.o (.rodata)
		*\bsp_irqs.o (.rodata.*)
		*\startups.o (.text)
		*\startups.o (.text.*)
		*\startups.o (.rodata)
		*\startups.o (.rodata.*)
		*\systems.o (.text)
		*\systems.o (.text.*)
		*\systems.o (.rodata)
		*\systems.o (.rodata.*)

		__CODE_S_End = .;
	} >CODE_S AT > CODE_S_L
	
	__tz_SRAM_S = ABSOLUTE(SRAM_S_START);
	. = __tz_SRAM_S;

	/* secure stacks are stored in this section. */
	.s_stack_dummy (NOLOAD) :
	{
		__S_StackLimit = .;
		/* secure main stack */
		KEEP(*(.s_stack))
		__S_StackTop = .;
	} >SRAM_S AT > SRAM_S_L

	/* start at address CODE_N_START */
	__tz_CODE_N = ABSOLUTE(CODE_N_START);
	. = __tz_CODE_N;

	.text :
	{
		__CODE_N_Start = .;
		/* Even though the vector table is not 512 entries (2KB) long, we still allocate that much space. */
		KEEP(*(.fixed_vectors*))
		KEEP(*(.application_vectors*))
		__Vectors_End = .;
		/* start at address 0x00000800 */
		. = __CODE_N_Start + 0x800;
		*(.text*)
		KEEP(*(.version))
		KEEP(*(.init))
		KEEP(*(.fini))
		/* .ctors */
		*crtbegin.o(.ctors)
		*crtbegin?.o(.ctors)
		*(EXCLUDE_FILE(* crtend?.o * crtend.o) .ctors)
		*(SORT(.ctors.*))
		*(.ctors)
		/* .dtors */
		*crtbegin.o(.dtors)
		*crtbegin?.o(.dtors)
		*(EXCLUDE_FILE(* crtend?.o * crtend.o) .dtors)
		*(SORT(.dtors.*))
		*(.dtors)
		*(.rodata*)
		KEEP(*(.eh_frame*))
		__CODE_N_End = .;
	} >CODE_N AT > CODE_N_L

	__Vectors_Size = __Vectors_End - __Vectors;
	.ARM.extab :
	{
		*(.ARM.extab* .gnu.linkonce.armextab.*)
	} > CODE_N
	__exidx_start = .;
	.ARM.exidx :
	{
		*(.ARM.exidx* .gnu.linkonce.armexidx.*)
	} > CODE_N AT > CODE_N_L
	__exidx_end = .;
	/* To copy multiple CODE_N to SRAM_N sections,
	 * uncomment .copy.table section and,
	 * define __STARTUP_COPY_MULTIPLE in startup_ARMCMx.S */
	/*
	 * .copy.table :
	 * {
	 *     . = ALIGN(4);
	 *     __copy_table_start__ = .;
	 *     LONG (__etext)
	 *     LONG (__data_start__)
	 *     LONG (__data_end__ - __data_start__)
	 *     LONG (__etext2)
	 *     LONG (__data2_start__)
	 *     LONG (__data2_end__ - __data2_start__)
	 *     __copy_table_end__ = .;
	 * } > CODE_N AT > CODE_N_L
	 */
	/* To clear multiple BSS sections,
	 * uncomment .zero.table section and,
	 * define __STARTUP_CLEAR_BSS_MULTIPLE in startup_ARMCMx.S */
	/*
	 * .zero.table :
	 * {
	 *     . = ALIGN(4);
	 *     __zero_table_start__ = .;
	 *     LONG (__bss_start__)
	 *     LONG (__bss_end__ - __bss_start__)
	 *     LONG (__bss2_start__)
	 *     LONG (__bss2_end__ - __bss2_start__)
	 *     __zero_table_end__ = .;
	 * } > CODE_N AT > CODE_N_L
	 */
	__etext = .;
	__tz_SRAM_N = ABSOLUTE(SRAM_N_START);
	. = __tz_SRAM_N;
	/* Initialized data section. */
	.data :
	{
		__data_start__ = .;
		. = ALIGN(4);
		__Code_In_RAM_Start = .;
		KEEP(*(.code_in_ram*))
		__Code_In_RAM_End = .;
		*(vtable)
		/* Don't use *(.data*) because it will place data meant for .data_flash in this section. */
		*(.data.*)
		*(.data)
		. = ALIGN(4);
		/* preinit data */
		PROVIDE_HIDDEN(__preinit_array_start = .);
		KEEP(*(.preinit_array))
		PROVIDE_HIDDEN(__preinit_array_end = .);
		. = ALIGN(4);
		/* init data */
		PROVIDE_HIDDEN(__init_array_start = .);
		KEEP(*(SORT(.init_array.*)))
		KEEP(*(.init_array))
		PROVIDE_HIDDEN(__init_array_end = .);
		. = ALIGN(4);
		/* finit data */
		PROVIDE_HIDDEN(__fini_array_start = .);
		KEEP(*(SORT(.fini_array.*)))
		KEEP(*(.fini_array))
		PROVIDE_HIDDEN(__fini_array_end = .);
		KEEP(*(.jcr*))
		. = ALIGN(4);
		/* All data end */
		__data_end__ = .;
	} > SRAM_N AT > SRAM_N_L
	.noinit (NOLOAD) :
	{
		. = ALIGN(4);
		__noinit_start = .;
		KEEP(*(.noinit*))
		. = ALIGN(8);
		/* Place the FreeRTOS heap here so that the __HeapLimit calculation does not include the freertos heap. */
		KEEP(*(.heap.*))
		__noinit_end = .;
	} > SRAM_N AT > SRAM_N_L
	.bss :
	{
		. = ALIGN(4);
		__bss_start__ = .;
		*(.bss*)
		*(COMMON)
		. = ALIGN(4);
		__bss_end__ = .;
	} > SRAM_N AT > SRAM_N_L
	.heap (NOLOAD) :
	{
		. = ALIGN(8);
		__HeapBase = .;
		/* Place the STD heap here. */
		KEEP(*(.heap))
		__HeapLimit = .;
	} > SRAM_N AT > SRAM_N_L
	/* Stacks are stored in this section. */
	.stack_dummy (NOLOAD) :
	{
		. = ALIGN(8);
		__StackLimit = .;
		/* Main stack */
		KEEP(*(.stack))
		__StackTop = .;
		/* Thread stacks */
		KEEP(*(.stack*))
		__StackTopAll = .;
	} > SRAM_N AT > SRAM_N_L 
	PROVIDE(__stack = __StackTopAll);
	/* This symbol represents the end of user allocated SRAM. The SRAM after this symbol can be used
	 at run time for things such as ThreadX memory pool allocations. */
	__SRAM_segment_used_end__ = ALIGN(__StackTopAll , 4);

	PROVIDE(__tz_SRAM_C = __SRAM_segment_used_end__);
	/* __tz_SRAM_C = ALIGN(__SRAM_segment_used_end__, 0); */

}
