.text
.globl  _start
.globl  _exit.crt0
.globl  watchdogTrigger


#ifdef __thumb__
# define subs sub
#endif

.macro WEAK_FUNCTION name
.weak \name
.thumb_func
\name :
.endm


_start:
    /* disable interrupts, enable faults */
    cpsid  i
    cpsie  f
    mov    r0, #0
    msr    BASEPRI, r0
    /* set stack and frame pointer */
    ldr    r1, .SP
    mov    r0, #7
    bic    r1, r0 
    mov    r0, #0
    mov    sp, r1
    mov    fp, r0
    mov    lr, r0
#if defined(__ARM_ARCH_7M__)||defined(__ARM_ARCH_7EM__)||defined(__ARM_ARCH_8M_BASE__)||defined(__ARM_ARCH_8M_MAIN__)
    /* set NVIC Base */
    ldr    r4, .VTOR
    ldr    r0, .NVIC_BASE
    str    r0, [r4]
#if (__ARM_FP==4)||(__ARM_FP==5)
    /* enable FPU */
    ldr    r4, .CPACR
    ldr    r1, .CPACR_FPU_EN
    ldr    r0,[r4]
    orr    r0, r1
    str    r0,[r4]
#endif
#endif

    /* early initialize Watchdog */
    ldr    r3, .WDG_INIT_EARLY
    cmp    r3, #0
    beq    wdg_init_early_done
    bl     crt0_veneer
wdg_init_early_done:

#if defined(ENABLE_ICACHE)&&(defined(__ARM_ARCH_7M__)||defined(__ARM_ARCH_7EM__)||defined(__ARM_ARCH_8M_MAIN__))
    bl     enableIC
#endif

#if defined(RAM_ECC_LONG)||defined(RAM_ECC_SHORT)
    ldr    r2, .ECC_RAMSTART
    ldr    r1, .ECC_RAMSIZE
    ldr    r4, .DATA_S
    ldr    r5, .DATA_LADDR
    cmp    r4, r5
    b      ecc_check
ecc_clear:
#if defined(RAM_ECC_LONG)
    subs   r1, r1, #0x4
    str    r0, [r2, r1]
#elif defined(RAM_ECC_SHORT)
    subs   r1, r1, #0x2
    strh   r0, [r2, r1]
#endif
ecc_check:
    bne    ecc_clear
#endif

#if defined(ENABLE_DCACHE)&&(defined(__ARM_ARCH_7M__)||defined(__ARM_ARCH_7EM__)||defined(__ARM_ARCH_8M_MAIN__))
    bl     enableDC
#endif

    /* copy data from FLASH to SRAM */
    ldr    r4, .DATA_S
    ldr    r5, .DATA_LADDR
    ldr    r6, .DATA_SIZE
    cmp    r4, r5
    beq    data_done
data_copy:
    ldrb   r0, [r5]
    strb   r0, [r4]
    add    r4, r4, #1
    add    r5, r5, #1
    subs   r6, r6, #1
    bne    data_copy
data_done:

    /* clear .bss-section */
    ldr    r4, .BSS_S
    ldr    r5, .BSS_E
    mov    r0, #0
    b      bss_check
bss_clear:
    strb   r0, [r4]
    add    r4, r4, #1
bss_check:
    cmp    r5, r4
    bne    bss_clear
bss_done:

    /* initialize Watchdog */
    ldr    r3, .WDG_INIT
    cmp    r3, #0
    beq    wdg_init_done
    bl     crt0_veneer
wdg_init_done:
    /* register the WatchdogHook */
    ldr    r3, .WDG_TRIGGER
    ldr    r4, .WDG_HOOK
    str    r3, [r4]

    /* initialization of e.g. static objects */
    ldr    r4, .INIT_S
    ldr    r5, .INIT_LADDR
    ldr    r6, .INIT_SIZE
    cmp    r6, #0
    beq    init_done
    add    r7, r6, #4
    cmp    r4, r5
    beq    init_check
init_copy:
    subs   r6, r6, #1
    ldrb   r0, [r5, r6]
    strb   r0, [r4, r6]
    bne    init_copy
    b      init_check
init:
    ldm    r4!, {r3}
    bl     crt0_veneer
init_check:
    subs   r7, r7, #4
    bne    init
init_done:

gomain:
    ldr    r3, .MAIN
    bl     crt0_veneer
    nop
_exit.crt0:
    /* we should never get here */
    b      _exit.crt0

    /* intended fallthrough for all weak default handlers */
WEAK_FUNCTION NMI_Handler
WEAK_FUNCTION HardFault_Handler
WEAK_FUNCTION MemManage_Handler
WEAK_FUNCTION BusFault_Handler
WEAK_FUNCTION UsageFault_Handler
WEAK_FUNCTION SVC_Handler
WEAK_FUNCTION PendSV_Handler
WEAK_FUNCTION SysTick_Handler
WEAK_FUNCTION _exit
.thumb_func
_hang:
    /* default fault handler */
    b      _hang

crt0_veneer:
    /* make a THUMB/ARM generic veneer call to r3 */
    /* lr is set by preceding bl instruction      */
    mov    r0, #0
    mov    r1, #0
    bx     r3

.org 0x100
_start_secondary:
    /* set stack and frame pointer */
    /* _start_secondary-_start = 0x100 -> SP is placed 0x100 bytes after SP of Core0 */
    ldr   r1, .SP
    mov   r0, #0
    mov   sp, r1
    mov   fp, r0
    bl    background
    b     _exit.crt0

.align  2
.SP:
    .word __stack_end
.BSS_S:
    .word __bss_start
.BSS_E:
    .word __bss_end
.INIT_S:
    .word __init_vaddr
.INIT_LADDR:
    .word __init_laddr
.INIT_SIZE:
    .word __init_size
.DATA_S:
    .word __data_vaddr
.DATA_LADDR:
    .word __data_laddr
.DATA_SIZE:
    .word __data_size
#ifndef WATCHDOG
.WDG_INIT:
    .word 0x0
.WDG_INIT_EARLY:
    .word 0x0
.WDG_TRIGGER:
    .word 0x0
#else
.WDG_INIT:
    .word WatchdogInit
.WDG_INIT_EARLY:
    .word WatchdogInitEarly
.WDG_TRIGGER:
    .word WatchdogTrigger
#endif
.WDG_HOOK:
    .word watchdogTrigger
.MAIN:
    .word main
.NVIC_BASE:
    .word __nvic_base
.VTOR:
    .word 0xe000ed08
.CPACR:
    .word 0xe000ed88
.CPACR_FPU_EN:
    .word 0x00f00000
.ECC_RAMSTART:
    .word __SRAM_start
#ifdef RAMSIZE
.ECC_RAMSIZE:
    .word RAMSIZE
#else
.ECC_RAMSIZE:
    .word __SRAM_size
#endif

.section .exception_vector
    .word __stack_end          /* 0x00 initial SP */
    .word _start+1             /* 0x04 Reset */
    .word NMI_Handler          /* 0x08 NMI */
    .word HardFault_Handler    /* 0x0c Hard fault */
    .word MemManage_Handler    /* 0x10 MPU */
    .word BusFault_Handler     /* 0x14 Bus fault */
    .word UsageFault_Handler   /* 0x18 Usage fault */
    .word 0                    /* 0x1C Reserved */
    .word 0                    /* 0x20 Reserved */
    .word 0                    /* 0x24 Reserved */
    .word 0                    /* 0x28 Reserved */
    .word SVC_Handler          /* 0x2c SVCall */
    .word 0                    /* 0x30 Reserved */
    .word 0                    /* 0x34 Reserved */
    .word PendSV_Handler       /* 0x38 PendSV */
    .word SysTick_Handler      /* 0x3c Systick */
    /* 0x40 onwards NVIC table Interrupts */

.section .text
.weak background
background:
    nop
1:
    wfe
    b 1b

#if defined(__ARM_ARCH_7M__)||defined(__ARM_ARCH_7EM__)||defined(__ARM_ARCH_8M_MAIN__)
.section .text
.thumb_func
enableIC:
    /* check for ICache */
    ldr    r1, .CLIDR
    ldr    r0, [r1]
    mov    r1, #0x1
    tst    r0, r1
    beq    enable_ic_done
    /* invalidate ICache */
    mov    r0, #0x0
    ldr    r1, .ICIALLU
    str    r0, [r1]
    dsb
    isb
    /* enalbe ICache */
    ldr    r2, .CCR
    ldr    r1, .CCR_IC
    ldr    r0, [r2]
    orr    r0, r1
    str    r0, [r2]
    dsb
    isb
enable_ic_done:
    bx     r14

.thumb_func
enableDC:
    /* check for DCache */
    ldr    r1, .CLIDR
    ldr    r0, [r1]
    mov    r1, #0x2
    tst    r0, r1
    beq    enable_dc_done
    /* detect DCache set & way*/
    mov    r0, #0x0
    ldr    r1, .CSSELR
    str    r0, [r1]
    dsb
    ldr    r1, .CCSIDR
    ldr    r2, .CCSIDR_WAY_MASK
    ldr    r3, .CCSIDR_SET_MASK
    ldr    r5, [r1]
    mov    r6, r5
    lsr    r5, r5, #0x3
    mov    r4, r5
    lsr    r5, r5, #0xa
    and    r4, r2       /* #Ways */
    and    r5, r3       /* #Sets */
    mov    r0, #0x7
    and    r6, r0
    add    r6, #0x2     /* #log2(Words) */
    clz    r7, r4       /* WayShift */
    /* invalidate DCache */
    ldr    r1, .DCISW
1:
    mov    r6, r5
    lsl    r6, #0x5     /* DCISW.currentSet */
    mov    r3, r4       /* currentWay */
2:
    mov    r0, r6
    mov    r2, r3
    lsl    r2, r7
    orr    r0, r2  
    str    r0, [r1]     /* DCISW */
    sub    r3, #0x1
    bge    2b
    sub    r5, #0x1
    bge    1b
    /* enable DCache */
    dsb
    isb
    ldr    r2, .CCR
    ldr    r1, .CCR_DC
    ldr    r0, [r2]
    orr    r0, r1
    str    r0, [r2]
    dsb
    isb
enable_dc_done:
    bx     r14

.align 2
.CLIDR:
    .word 0xe000ed78
.CCSIDR:
    .word 0xe000ed80
.CCSIDR_WAY_MASK:
    .word 0x3ff
.CCSIDR_SET_MASK:
    .word 0x7fff
.CSSELR:
    .word 0xe000ed84
.CCR:
    .word 0xe000ed14
.CCR_IC:
    .word 0x00020000
.CCR_DC:
    .word 0x00010000
.ICIALLU:
    .word 0xe000ef50
.DCISW:
    .word 0xe000ef60
#endif

.section .data
watchdogTrigger:
    .word 0x0

