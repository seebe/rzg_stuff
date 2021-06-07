/***********************************************************************************************************************
 * Copyright [2020] Renesas Electronics Corporation and/or its affiliates.  All Rights Reserved.
 *
 * This software and documentation are supplied by Renesas Electronics America Inc. and may only be used with products
 * of Renesas Electronics Corp. and its affiliates ("Renesas").  No other uses are authorized.  Renesas products are
 * sold pursuant to Renesas terms and conditions of sale.  Purchasers are solely responsible for the selection and use
 * of Renesas products and Renesas assumes no liability.  No license, express or implied, to any intellectual property
 * right is granted by Renesas. This software is protected under all applicable laws, including copyright laws. Renesas
 * reserves the right to change or discontinue this software and/or this documentation. THE SOFTWARE AND DOCUMENTATION
 * IS DELIVERED TO YOU "AS IS," AND RENESAS MAKES NO REPRESENTATIONS OR WARRANTIES, AND TO THE FULLEST EXTENT
 * PERMISSIBLE UNDER APPLICABLE LAW, DISCLAIMS ALL WARRANTIES, WHETHER EXPLICITLY OR IMPLICITLY, INCLUDING WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NONINFRINGEMENT, WITH RESPECT TO THE SOFTWARE OR
 * DOCUMENTATION.  RENESAS SHALL HAVE NO LIABILITY ARISING OUT OF ANY SECURITY VULNERABILITY OR BREACH.  TO THE MAXIMUM
 * EXTENT PERMITTED BY LAW, IN NO EVENT WILL RENESAS BE LIABLE TO YOU IN CONNECTION WITH THE SOFTWARE OR DOCUMENTATION
 * (OR ANY PERSON OR ENTITY CLAIMING RIGHTS DERIVED FROM YOU) FOR ANY LOSS, DAMAGES, OR CLAIMS WHATSOEVER, INCLUDING,
 * WITHOUT LIMITATION, ANY DIRECT, CONSEQUENTIAL, SPECIAL, INDIRECT, PUNITIVE, OR INCIDENTAL DAMAGES; ANY LOST PROFITS,
 * OTHER ECONOMIC DAMAGE, PROPERTY DAMAGE, OR PERSONAL INJURY; AND EVEN IF RENESAS HAS BEEN ADVISED OF THE POSSIBILITY
 * OF SUCH LOSS, DAMAGES, CLAIMS OR COSTS.
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/
#include "bsp_api.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/
 #define BSP_PRV_AIRCR_VECTKEY    (0x05FA0000U)
 #define RZG2L_NOT_DEFINED           (0)

 #define BSP_PRV_CLEAR_THUMB_INSTRUCTION  (0xFFFFFFFEUL)

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global variables (to be accessed by other files)
 **********************************************************************************************************************/
void R_BSP_SecurityInit(void);
void R_BSP_PinCfgSecurityInit(void);

/***********************************************************************************************************************
 * External symbols
 **********************************************************************************************************************/
extern fsp_vector_t g_vector_table[BSP_ICU_VECTOR_MAX_ENTRIES];

 #if defined(__ARMCC_VERSION) || defined(__ICCARM__)
typedef void (BSP_CMSE_NONSECURE_CALL * bsp_nonsecure_func_t)(void);
 #elif defined(__GNUC__)
typedef BSP_CMSE_NONSECURE_CALL void (*volatile bsp_nonsecure_func_t)(void);
 #endif

 #if   defined(__IAR_SYSTEMS_ICC__)
  #pragma section=".tz_flash_nsc_start"
  #pragma section=".tz_flash_ns_start"
  #pragma section=".tz_ram_nsc_start"
  #pragma section=".tz_ram_ns_start"
  #pragma section=".tz_data_flash_ns_start"
  #pragma section=".tz_sdram_ns_start"
  #pragma section=".tz_qspi_flash_ns_start"

/* &__tz_<REGION>_C is the address of the non-secure callable section. Must assign value to this variable or
 * linker will give error. */

/* &__tz_<REGION>_N is the start address of the non-secure region. */
BSP_DONT_REMOVE void const * const __tz_CODE_N       BSP_ALIGN_VARIABLE(32768) @".tz_flash_ns_start";
BSP_DONT_REMOVE uint32_t const * const gp_start_of_nonsecure_flash = (uint32_t *) &__tz_CODE_N;
 #elif defined(__ARMCC_VERSION)
extern const uint32_t Image$$__tz_CODE_N$$Base;

  #define __tz_CODE_N             Image$$__tz_CODE_N$$Base

/* Assign region addresses to pointers so that AC6 includes symbols that can be used to determine the
 * start addresses of Secure, Non-secure and Non-secure Callable regions. */
BSP_DONT_REMOVE uint32_t const * const gp_start_of_nonsecure_flash          = &__tz_CODE_N;
 #elif defined(__GNUC__)
extern const uint32_t __tz_CODE_N;
BSP_DONT_REMOVE uint32_t const * const gp_start_of_nonsecure_flash = &__tz_CODE_N;
 #endif


#define BSP_PRV_STACK_LIMIT                          ((uint32_t) &__StackLimit)
extern uint32_t __StackLimit;

/*******************************************************************************************************************//**
 * @addtogroup BSP_MCU
 * @{
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Enter the non-secure code environment.
 *
 * This function configures the non-secure MSP and vector table then jumps to the non-secure project's Reset_Handler.
 *
 * @note This function (and therefore the non-secure code) should not return.
 **********************************************************************************************************************/
void R_BSP_NonSecureEnter (void)
{
    /* The NS vector table is at the start of the NS section in flash */
    uint32_t const * p_ns_vector_table = gp_start_of_nonsecure_flash;

    /* Set up the NS Reset_Handler to be called */
    uint32_t const * p_ns_reset_address = (uint32_t const *) ((uint32_t) p_ns_vector_table + sizeof(uint32_t));
    uint32_t const   ns_reset_address 	= (uint32_t const  ) ((uint32_t)(*p_ns_reset_address) & BSP_PRV_CLEAR_THUMB_INSTRUCTION);

    /* Set the NS vector table address */
    SCB_NS->VTOR = (uint32_t) p_ns_vector_table;

    /* Use CM33 stack monitor. */
    __TZ_set_MSPLIM_NS(BSP_PRV_STACK_LIMIT);

    /* Set the NS stack pointer to the first entry in the NS vector table */
    __TZ_set_MSP_NS(p_ns_vector_table[0]);

    /* Jump to the NS Reset_Handler */
	__ASM volatile ("blxns %0"::"r" (ns_reset_address));
}

/** @} (end addtogroup BSP_MCU) */

/*******************************************************************************************************************//**
 * Initialize security features for TrustZone.
 *
 * This function initializes ARM security register and Renesas SAR registers for secure projects.
 *
 * @note IDAU settings must be configured to match project settings with a separate configuration tool.
**********************************************************************************************************************/
void R_BSP_SecurityInit (void)
{
    /* Setting SAU_CTRL.ALLNS to 1 allows the security attribution of all addresses to be set by the IDAU in the
     * system. */
    SAU->CTRL = SAU_CTRL_ALLNS_Msk;

    /* Controls whether the SLEEPDEEP bit is only accessible from the Secure state, and
     * Controls whether the processor uses sleep or deep sleep as its low-power mode. */
    SCB->SCR   = (SCB->SCR & ~(SCB_SCR_SLEEPDEEPS_Msk | SCB_SCR_SLEEPDEEP_Msk)) |
                 ((SCB_SCR_SLEEPDEEPS_VAL << SCB_SCR_SLEEPDEEPS_Pos) & SCB_SCR_SLEEPDEEPS_Msk) |
                 ((SCB_SCR_SLEEPDEEP_VAL  << SCB_SCR_SLEEPDEEP_Pos)  & SCB_SCR_SLEEPDEEP_Msk);

 #if defined(SCB_CSR_AIRCR_INIT) && (SCB_CSR_AIRCR_INIT == 1U)

    /* Configure whether non-secure projects have access to system reset, whether bus fault, hard fault, and NMI target
     * secure or non-secure, and whether non-secure interrupt priorities are reduced to the lowest 8 priority levels. */
    SCB->AIRCR = (SCB->AIRCR & ~(SCB_AIRCR_VECTKEY_Msk | SCB_AIRCR_SYSRESETREQS_Msk |
                                 SCB_AIRCR_BFHFNMINS_Msk | SCB_AIRCR_PRIS_Msk)) |
                 BSP_PRV_AIRCR_VECTKEY |
                 ((SCB_AIRCR_SYSRESETREQS_VAL << SCB_AIRCR_SYSRESETREQS_Pos) & SCB_AIRCR_SYSRESETREQS_Msk) |
                 ((SCB_AIRCR_PRIS_VAL << SCB_AIRCR_PRIS_Pos) & SCB_AIRCR_PRIS_Msk) |
                 ((SCB_AIRCR_BFHFNMINS_VAL << SCB_AIRCR_BFHFNMINS_Pos) & SCB_AIRCR_BFHFNMINS_Msk);
 #endif

    SCB->SHCSR = (SCB->SHCSR & ~(SCB_SHCSR_SECUREFAULTENA_Msk)) |
                 ((SCB_SHCSR_SECUREFAULTENA_VAL << SCB_SHCSR_SECUREFAULTENA_Pos) & SCB_SHCSR_SECUREFAULTENA_Msk);
 
 #if defined(__FPU_USED) && (__FPU_USED == 1U) && \
    defined(TZ_FPU_NS_USAGE) && (TZ_FPU_NS_USAGE == 1U)

    /* Configure whether the FPU can be accessed in the non-secure project. */
    SCB->NSACR = (SCB->NSACR & ~(SCB_NSACR_CP10_Msk | SCB_NSACR_CP11_Msk)) |
                 ((SCB_NSACR_CP10_11_VAL << SCB_NSACR_CP10_Pos) & (SCB_NSACR_CP10_Msk | SCB_NSACR_CP11_Msk));

    /* Configure whether FPU registers are always treated as non-secure (and therefore not preserved on the stack when
     * switching from secure to non-secure), and whether the FPU registers should be cleared on exception return. */
    FPU->FPCCR = (FPU->FPCCR & ~(FPU_FPCCR_TS_Msk | FPU_FPCCR_CLRONRETS_Msk | FPU_FPCCR_CLRONRET_Msk)) |
                 ((FPU_FPCCR_TS_VAL << FPU_FPCCR_TS_Pos) & FPU_FPCCR_TS_Msk) |
                 ((FPU_FPCCR_CLRONRETS_VAL << FPU_FPCCR_CLRONRETS_Pos) & FPU_FPCCR_CLRONRETS_Msk) |
                 ((FPU_FPCCR_CLRONRET_VAL << FPU_FPCCR_CLRONRET_Pos) & FPU_FPCCR_CLRONRET_Msk);
 #endif

    /* Slave Access Control: set level0 to enable RD & WR in Non Secure */
    R_BSP_ACCESS_CONTROL_SET(ACCCNT_TZC0,  0)
    R_BSP_ACCESS_CONTROL_SET(ACCCNT_TZC1,  0)
    R_BSP_ACCESS_CONTROL_SET(ACCCNT_TZC2,  0)
    R_BSP_ACCESS_CONTROL_SET(ACCCNT_TZC3,  0)
    R_BSP_ACCESS_CONTROL_SET(ACCCNT_DMAC0, 0)
    R_BSP_ACCESS_CONTROL_SET(ACCCNT_OSTM0, 0)

    /* Initialize security attribution registers for Pins. */
    R_BSP_PinCfgSecurityInit();

}

/* This function is overridden by tooling. */
BSP_WEAK_REFERENCE void R_BSP_PinCfgSecurityInit (void)
{
}
