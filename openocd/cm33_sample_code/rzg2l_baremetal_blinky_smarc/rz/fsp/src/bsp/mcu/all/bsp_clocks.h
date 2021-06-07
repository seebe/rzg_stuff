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

#ifndef BSP_CLOCKS_H
#define BSP_CLOCKS_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "bsp_clock_cfg.h"
#include "bsp_api.h"

/** Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/
/*******************************************************************************************************************//**
 * Start clock supply
 *
 * @param      unit     bsp_clk_unit_t enum value for the unit to which the clock is supplied.
 * @param      pos      Bit position. Only single bit can be set.
 **********************************************************************************************************************/
#define R_BSP_CLKON(unit, pos)      {BSP_CLKON_REG_ ## unit(pos)    = 0x0000U \
                                                                    | (BSP_CLKON_BIT_ ## unit(pos) << 16U) \
                                                                    | (BSP_CLKON_BIT_ ## unit(pos)); \
                                     while((BSP_CLKMON_REG_ ## unit(pos) & BSP_CLKMON_BIT_ ## unit(pos)) == 0U); \
                                     }

/*******************************************************************************************************************//**
 * Stop clock supply
 *
 * @param      unit     bsp_clk_unit_t enum value for the unit to stop clock.
 * @param      pos      Bit position. Only single bit can be set.
 **********************************************************************************************************************/
#define R_BSP_CLKOFF(unit, pos)     {BSP_CLKON_REG_ ## unit(pos)    = 0x0000U \
                                                                    | (BSP_CLKON_BIT_ ## unit(pos) << 16U); \
                                     while((BSP_CLKMON_REG_ ## unit(pos) & BSP_CLKMON_BIT_ ## unit(pos)) != 0U);\
                                     }

/*******************************************************************************************************************//**
 * Reset unit
 *
 * @param      unit     bsp_clk_unit_t enum value for the unit to be reset.
 * @param      pos      Bit position. Only single bit can be set.
 **********************************************************************************************************************/
#define R_BSP_RSTON(unit, pos)      {BSP_RST_REG_ ## unit(pos)      = 0x0000U \
                                                                    | (BSP_RST_BIT_ ## unit(pos) << 16U); \
									}

/*******************************************************************************************************************//**
 * Reset unit
 *
 * @param      unit     bsp_clk_unit_t enum value for the unit to be reset.
 * @param      pos      Bit position. Only single bit can be set.
 **********************************************************************************************************************/
#define R_BSP_RSTOFF(unit, pos)     {BSP_RST_REG_ ## unit(pos)      = 0x0000U \
                                                                    | (BSP_RST_BIT_ ## unit(pos) << 16U) \
                                                                    | (BSP_RST_BIT_ ## unit(pos)); \
                                     while((BSP_RSTMON_REG_ ## unit(pos) & BSP_RSTMON_BIT_ ## unit(pos)) != 0U); \
                                     }

#define BSP_CLKON_REG_BSP_CLK_CA55(pos)         R_CPG->CPG_CLKON_CA55
#define BSP_CLKON_BIT_BSP_CLK_CA55(pos)         (1U << R_CPG_CPG_CLKON_CA55_CLK ## pos ## _ON_Pos)
#define BSP_CLKMON_REG_BSP_CLK_CA55(pos)        R_CPG->CPG_CLKMON_CA55
#define BSP_CLKMON_BIT_BSP_CLK_CA55(pos)        (1U << R_CPG_CPG_CLKMON_CA55_CLK ## pos ## _MON_Pos)

#define BSP_RST_REG_BSP_CLK_CA55(pos)           R_CPG->CPG_RST_CA55
#define BSP_RST_BIT_BSP_CLK_CA55(pos)           (1U << R_CPG_CPG_RST_CA55_UNIT ## pos ## _RSTB_Pos)
#define BSP_RSTMON_REG_BSP_CLK_CA55(pos)        R_CPG->CPG_RSTMON_CA55
#define BSP_RSTMON_BIT_BSP_CLK_CA55(pos)        (1U << R_CPG_CPG_RSTMON_CA55_RST ## pos ## _MON_Pos)


#define BSP_CLKON_REG_BSP_CLK_CM33(pos)         R_CPG->CPG_CLKON_CM33
#define BSP_CLKON_BIT_BSP_CLK_CM33(pos)         (1U << R_CPG_CPG_CLKON_CM33_CLK ## pos ## _ON_Pos)
#define BSP_CLKMON_REG_BSP_CLK_CM33(pos)        R_CPG->CPG_CLKMON_CM33
#define BSP_CLKMON_BIT_BSP_CLK_CM33(pos)        (1U << R_CPG_CPG_CLKMON_CM33_CLK ## pos ## _MON_Pos)

#define BSP_RST_REG_BSP_CLK_CM33(pos)           R_CPG->CPG_RST_CM33
#define BSP_RST_BIT_BSP_CLK_CM33(pos)           (1U << R_CPG_CPG_RST_CM33_UNIT ## pos ## _RSTB_Pos)
#define BSP_RSTMON_REG_BSP_CLK_CM33(pos)        R_CPG->CPG_RSTMON_CM33
#define BSP_RSTMON_BIT_BSP_CLK_CM33(pos)        (1U << R_CPG_CPG_RSTMON_CM33_RST ## pos ## _MON_Pos)


#define BSP_CLKON_REG_BSP_CLK_SRAM_ACPU(pos)    R_CPG->CPG_CLKON_SRAM_ACPU
#define BSP_CLKON_BIT_BSP_CLK_SRAM_ACPU(pos)    (1U << R_CPG_CPG_CLKON_SRAM_ACPU_CLK ## pos ## _ON_Pos)
#define BSP_CLKMON_REG_BSP_CLK_SRAM_ACPU(pos)   R_CPG->CPG_CLKMON_SRAM_ACPU
#define BSP_CLKMON_BIT_BSP_CLK_SRAM_ACPU(pos)   (1U << R_CPG_CPG_CLKMON_SRAM_ACPU_CLK ## pos ## _MON_Pos)

#define BSP_RST_REG_BSP_CLK_SRAM_ACPU(pos)      R_CPG->CPG_RST_SRAM_ACPU
#define BSP_RST_BIT_BSP_CLK_SRAM_ACPU(pos)      (1U << R_CPG_CPG_RST_SRAM_ACPU_UNIT ## pos ## _RSTB_Pos)
#define BSP_RSTMON_REG_BSP_CLK_SRAM_ACPU(pos)   R_CPG->CPG_RSTMON_SRAM_ACPU
#define BSP_RSTMON_BIT_BSP_CLK_SRAM_ACPU(pos)   (1U << R_CPG_CPG_RSTMON_SRAM_ACPU_RST ## pos ## _MON_Pos)


#define BSP_CLKON_REG_BSP_CLK_SRAM_MCPU(pos)    R_CPG->CPG_CLKON_SRAM_MCPU
#define BSP_CLKON_BIT_BSP_CLK_SRAM_MCPU(pos)    (1U << R_CPG_CPG_CLKON_SRAM_MCPU_CLK ## pos ## _ON_Pos)
#define BSP_CLKMON_REG_BSP_CLK_SRAM_MCPU(pos)   R_CPG->CPG_CLKMON_SRAM_MCPU
#define BSP_CLKMON_BIT_BSP_CLK_SRAM_MCPU(pos)   (1U << R_CPG_CPG_CLKMON_SRAM_MCPU_CLK ## pos ## _MON_Pos)

#define BSP_RST_REG_BSP_CLK_SRAM_MCPU(pos)      R_CPG->CPG_RST_SRAM_MCPU
#define BSP_RST_BIT_BSP_CLK_SRAM_MCPU(pos)      (1U << R_CPG_CPG_RST_SRAM_MCPU_UNIT ## pos ## _RSTB_Pos)
#define BSP_RSTMON_REG_BSP_CLK_SRAM_MCPU(pos)   R_CPG->CPG_RSTMON_SRAM_MCPU
#define BSP_RSTMON_BIT_BSP_CLK_SRAM_MCPU(pos)   (1U << R_CPG_CPG_RSTMON_SRAM_MCPU_RST ## pos ## _MON_Pos)


#define BSP_CLKON_REG_BSP_CLK_ROM(pos)          R_CPG->CPG_CLKON_ROM
#define BSP_CLKON_BIT_BSP_CLK_ROM(pos)          (1U << R_CPG_CPG_CLKON_ROM_CLK ## pos ## _ON_Pos)
#define BSP_CLKMON_REG_BSP_CLK_ROM(pos)         R_CPG->CPG_CLKMON_ROM
#define BSP_CLKMON_BIT_BSP_CLK_ROM(pos)         (1U << R_CPG_CPG_CLKMON_ROM_CLK ## pos ## _MON_Pos)

#define BSP_RST_REG_BSP_CLK_ROM(pos)            R_CPG->CPG_RST_ROM
#define BSP_RST_BIT_BSP_CLK_ROM(pos)            (1U << R_CPG_CPG_RST_ROM_UNIT ## pos ## _RSTB_Pos)
#define BSP_RSTMON_REG_BSP_CLK_ROM(pos)         R_CPG->CPG_RSTMON_ROM
#define BSP_RSTMON_BIT_BSP_CLK_ROM(pos)         (1U << R_CPG_CPG_RSTMON_ROM_RST ## pos ## _MON_Pos)


#define BSP_CLKON_REG_BSP_CLK_GIC600(pos)       R_CPG->CPG_CLKON_GIC600
#define BSP_CLKON_BIT_BSP_CLK_GIC600(pos)       (1U << R_CPG_CPG_CLKON_GIC600_CLK ## pos ## _ON_Pos)
#define BSP_CLKMON_REG_BSP_CLK_GIC600(pos)      R_CPG->CPG_CLKMON_GIC600
#define BSP_CLKMON_BIT_BSP_CLK_GIC600(pos)      (1U << R_CPG_CPG_CLKMON_GIC600_CLK ## pos ## _MON_Pos)

#define BSP_RST_REG_BSP_CLK_GIC600(pos)         R_CPG->CPG_RST_GIC600
#define BSP_RST_BIT_BSP_CLK_GIC600(pos)         (1U << R_CPG_CPG_RST_GIC600_UNIT ## pos ## _RSTB_Pos)
#define BSP_RSTMON_REG_BSP_CLK_GIC600(pos)      R_CPG->CPG_RSTMON_GIC600
#define BSP_RSTMON_BIT_BSP_CLK_GIC600(pos)      (1U << R_CPG_CPG_RSTMON_GIC600_RST ## pos ## _MON_Pos)


#define BSP_CLKON_REG_BSP_CLK_IA55(pos)         R_CPG->CPG_CLKON_IA55
#define BSP_CLKON_BIT_BSP_CLK_IA55(pos)         (1U << R_CPG_CPG_CLKON_IA55_CLK ## pos ## _ON_Pos)
#define BSP_CLKMON_REG_BSP_CLK_IA55(pos)        R_CPG->CPG_CLKMON_IA55
#define BSP_CLKMON_BIT_BSP_CLK_IA55(pos)        (1U << R_CPG_CPG_CLKMON_IA55_CLK ## pos ## _MON_Pos)

#define BSP_RST_REG_BSP_CLK_IA55(pos)           R_CPG->CPG_RST_IA55
#define BSP_RST_BIT_BSP_CLK_IA55(pos)           (1U << R_CPG_CPG_RST_IA55_UNIT ## pos ## _RSTB_Pos)
#define BSP_RSTMON_REG_BSP_CLK_IA55(pos)        R_CPG->CPG_RSTMON_IA55
#define BSP_RSTMON_BIT_BSP_CLK_IA55(pos)        (1U << R_CPG_CPG_RSTMON_IA55_RST ## pos ## _MON_Pos)


#define BSP_CLKON_REG_BSP_CLK_IM33(pos)         R_CPG->CPG_CLKON_IM33
#define BSP_CLKON_BIT_BSP_CLK_IM33(pos)         (1U << R_CPG_CPG_CLKON_IM33_CLK ## pos ## _ON_Pos)
#define BSP_CLKMON_REG_BSP_CLK_IM33(pos)        R_CPG->CPG_CLKMON_IM33
#define BSP_CLKMON_BIT_BSP_CLK_IM33(pos)        (1U << R_CPG_CPG_CLKMON_IM33_CLK ## pos ## _MON_Pos)

#define BSP_RST_REG_BSP_CLK_IM33(pos)           R_CPG->CPG_RST_IM33
#define BSP_RST_BIT_BSP_CLK_IM33(pos)           (1U << R_CPG_CPG_RST_IM33_UNIT ## pos ## _RSTB_Pos)
#define BSP_RSTMON_REG_BSP_CLK_IM33(pos)        R_CPG->CPG_RSTMON_IM33
#define BSP_RSTMON_BIT_BSP_CLK_IM33(pos)        (1U << R_CPG_CPG_RSTMON_IM33_RST ## pos ## _MON_Pos)


#define BSP_CLKON_REG_BSP_CLK_MHU(pos)          R_CPG->CPG_CLKON_MHU
#define BSP_CLKON_BIT_BSP_CLK_MHU(pos)          (1U << R_CPG_CPG_CLKON_MHU_CLK ## pos ## _ON_Pos)
#define BSP_CLKMON_REG_BSP_CLK_MHU(pos)         R_CPG->CPG_CLKMON_MHU
#define BSP_CLKMON_BIT_BSP_CLK_MHU(pos)         (1U << R_CPG_CPG_CLKMON_MHU_CLK ## pos ## _MON_Pos)

#define BSP_RST_REG_BSP_CLK_MHU(pos)            R_CPG->CPG_RST_MHU
#define BSP_RST_BIT_BSP_CLK_MHU(pos)            (1U << R_CPG_CPG_RST_MHU_UNIT ## pos ## _RSTB_Pos)
#define BSP_RSTMON_REG_BSP_CLK_MHU(pos)         R_CPG->CPG_RSTMON_MHU
#define BSP_RSTMON_BIT_BSP_CLK_MHU(pos)         (1U << R_CPG_CPG_RSTMON_MHU_RST ## pos ## _MON_Pos)


#define BSP_CLKON_REG_BSP_CLK_CST(pos)          R_CPG->CPG_CLKON_CST
#define BSP_CLKON_BIT_BSP_CLK_CST(pos)          (1U << R_CPG_CPG_CLKON_CST_CLK ## pos ## _ON_Pos)
#define BSP_CLKMON_REG_BSP_CLK_CST(pos)         R_CPG->CPG_CLKMON_CST
#define BSP_CLKMON_BIT_BSP_CLK_CST(pos)         (1U << R_CPG_CPG_CLKMON_CST_CLK ## pos ## _MON_Pos)


#define BSP_CLKON_REG_BSP_CLK_SYC(pos)          R_CPG->CPG_CLKON_SYC
#define BSP_CLKON_BIT_BSP_CLK_SYC(pos)          (1U << R_CPG_CPG_CLKON_SYC_CLK ## pos ## _ON_Pos)
#define BSP_CLKMON_REG_BSP_CLK_SYC(pos)         R_CPG->CPG_CLKMON_SYC
#define BSP_CLKMON_BIT_BSP_CLK_SYC(pos)         (1U << R_CPG_CPG_CLKMON_SYC_CLK ## pos ## _MON_Pos)

#define BSP_RST_REG_BSP_CLK_SYC(pos)            R_CPG->CPG_RST_SYC
#define BSP_RST_BIT_BSP_CLK_SYC(pos)            (1U << R_CPG_CPG_RST_SYC_UNIT ## pos ## _RSTB_Pos)
#define BSP_RSTMON_REG_BSP_CLK_SYC(pos)         R_CPG->CPG_RSTMON_SYC
#define BSP_RSTMON_BIT_BSP_CLK_SYC(pos)         (1U << R_CPG_CPG_RSTMON_SYC_RST ## pos ## _MON_Pos)


#define BSP_CLKON_REG_BSP_CLK_DMAC_REG(pos)     R_CPG->CPG_CLKON_DMAC_REG
#define BSP_CLKON_BIT_BSP_CLK_DMAC_REG(pos)     (1U << R_CPG_CPG_CLKON_DMAC_REG_CLK ## pos ## _ON_Pos)
#define BSP_CLKMON_REG_BSP_CLK_DMAC_REG(pos)    R_CPG->CPG_CLKMON_DMAC_REG
#define BSP_CLKMON_BIT_BSP_CLK_DMAC_REG(pos)    (1U << R_CPG_CPG_CLKMON_DMAC_REG_CLK ## pos ## _MON_Pos)

#define BSP_RST_REG_BSP_CLK_DMAC_REG(pos)       R_CPG->CPG_RST_DMAC
#define BSP_RST_BIT_BSP_CLK_DMAC_REG(pos)       (1U << R_CPG_CPG_RST_DMAC_UNIT ## pos ## _RSTB_Pos)
#define BSP_RSTMON_REG_BSP_CLK_DMAC_REG(pos)    R_CPG->CPG_RSTMON_DMAC
#define BSP_RSTMON_BIT_BSP_CLK_DMAC_REG(pos)    (1U << R_CPG_CPG_RSTMON_DMAC_RST ## pos ## _MON_Pos)


#define BSP_CLKON_REG_BSP_CLK_SYSC(pos)         R_CPG->CPG_CLKON_SYSC
#define BSP_CLKON_BIT_BSP_CLK_SYSC(pos)         (1U << R_CPG_CPG_CLKON_SYSC_CLK ## pos ## _ON_Pos)
#define BSP_CLKMON_REG_BSP_CLK_SYSC(pos)        R_CPG->CPG_CLKMON_SYSC
#define BSP_CLKMON_BIT_BSP_CLK_SYSC(pos)        (1U << R_CPG_CPG_CLKMON_SYSC_CLK ## pos ## _MON_Pos)

#define BSP_RST_REG_BSP_CLK_SYSC(pos)           R_CPG->CPG_RST_SYSC
#define BSP_RST_BIT_BSP_CLK_SYSC(pos)           (1U << R_CPG_CPG_RST_SYSC_UNIT ## pos ## _RSTB_Pos)
#define BSP_RSTMON_REG_BSP_CLK_SYSC(pos)        R_CPG->CPG_RSTMON_SYSC
#define BSP_RSTMON_BIT_BSP_CLK_SYSC(pos)        (1U << R_CPG_CPG_RSTMON_SYSC_RST ## pos ## _MON_Pos)


#define BSP_CLKON_REG_BSP_CLK_GTM(pos)          R_CPG->CPG_CLKON_GTM
#define BSP_CLKON_BIT_BSP_CLK_GTM(pos)          (1U << R_CPG_CPG_CLKON_GTM_CLK ## pos ## _ON_Pos)
#define BSP_CLKMON_REG_BSP_CLK_GTM(pos)         R_CPG->CPG_CLKMON_GTM
#define BSP_CLKMON_BIT_BSP_CLK_GTM(pos)         (1U << R_CPG_CPG_CLKMON_GTM_CLK ## pos ## _MON_Pos)

#define BSP_RST_REG_BSP_CLK_GTM(pos)            R_CPG->CPG_RST_GTM
#define BSP_RST_BIT_BSP_CLK_GTM(pos)            (1U << R_CPG_CPG_RST_GTM_UNIT ## pos ## _RSTB_Pos)
#define BSP_RSTMON_REG_BSP_CLK_GTM(pos)         R_CPG->CPG_RSTMON_GTM
#define BSP_RSTMON_BIT_BSP_CLK_GTM(pos)         (1U << R_CPG_CPG_RSTMON_GTM_RST ## pos ## _MON_Pos)


#define BSP_CLKON_REG_BSP_CLK_MTU(pos)          R_CPG->CPG_CLKON_MTU
#define BSP_CLKON_BIT_BSP_CLK_MTU(pos)          (1U << R_CPG_CPG_CLKON_MTU_CLK ## pos ## _ON_Pos)
#define BSP_CLKMON_REG_BSP_CLK_MTU(pos)         R_CPG->CPG_CLKMON_MTU
#define BSP_CLKMON_BIT_BSP_CLK_MTU(pos)         (1U << R_CPG_CPG_CLKMON_MTU_CLK ## pos ## _MON_Pos)

#define BSP_RST_REG_BSP_CLK_MTU(pos)            R_CPG->CPG_RST_MTU
#define BSP_RST_BIT_BSP_CLK_MTU(pos)            (1U << R_CPG_CPG_RST_MTU_UNIT ## pos ## _RSTB_Pos)
#define BSP_RSTMON_REG_BSP_CLK_MTU(pos)         R_CPG->CPG_RSTMON_MTU
#define BSP_RSTMON_BIT_BSP_CLK_MTU(pos)         (1U << R_CPG_CPG_RSTMON_MTU_RST ## pos ## _MON_Pos)


#define BSP_CLKON_REG_BSP_CLK_POE3(pos)         R_CPG->CPG_CLKON_POE3
#define BSP_CLKON_BIT_BSP_CLK_POE3(pos)         (1U << R_CPG_CPG_CLKON_POE3_CLK ## pos ## _ON_Pos)
#define BSP_CLKMON_REG_BSP_CLK_POE3(pos)        R_CPG->CPG_CLKMON_POE3
#define BSP_CLKMON_BIT_BSP_CLK_POE3(pos)        (1U << R_CPG_CPG_CLKMON_POE3_CLK ## pos ## _MON_Pos)

#define BSP_RST_REG_BSP_CLK_POE3(pos)           R_CPG->CPG_RST_POE3
#define BSP_RST_BIT_BSP_CLK_POE3(pos)           (1U << R_CPG_CPG_RST_POE3_UNIT ## pos ## _RSTB_Pos)
#define BSP_RSTMON_REG_BSP_CLK_POE3(pos)        R_CPG->CPG_RSTMON_POE3
#define BSP_RSTMON_BIT_BSP_CLK_POE3(pos)        (1U << R_CPG_CPG_RSTMON_POE3_RST ## pos ## _MON_Pos)


#define BSP_CLKON_REG_BSP_CLK_GPT(pos)          R_CPG->CPG_CLKON_GPT
#define BSP_CLKON_BIT_BSP_CLK_GPT(pos)          (1U << R_CPG_CPG_CLKON_GPT_CLK ## pos ## _ON_Pos)
#define BSP_CLKMON_REG_BSP_CLK_GPT(pos)         R_CPG->CPG_CLKMON_GPT
#define BSP_CLKMON_BIT_BSP_CLK_GPT(pos)         (1U << R_CPG_CPG_CLKMON_GPT_CLK ## pos ## _MON_Pos)

#define BSP_RST_REG_BSP_CLK_GPT(pos)            R_CPG->CPG_RST_GPT
#define BSP_RST_BIT_BSP_CLK_GPT(pos)            (1U << R_CPG_CPG_RST_GPT_UNIT ## pos ## _RSTB_Pos)
#define BSP_RSTMON_REG_BSP_CLK_GPT(pos)         R_CPG->CPG_RSTMON_GPT
#define BSP_RSTMON_BIT_BSP_CLK_GPT(pos)         (1U << R_CPG_CPG_RSTMON_GPT_RST ## pos ## _MON_Pos)


#define BSP_CLKON_REG_BSP_CLK_POEG(pos)         R_CPG->CPG_CLKON_POEG
#define BSP_CLKON_BIT_BSP_CLK_POEG(pos)         (1U << R_CPG_CPG_CLKON_POEG_CLK ## pos ## _ON_Pos)
#define BSP_CLKMON_REG_BSP_CLK_POEG(pos)        R_CPG->CPG_CLKMON_POEG
#define BSP_CLKMON_BIT_BSP_CLK_POEG(pos)        (1U << R_CPG_CPG_CLKMON_POEG_CLK ## pos ## _MON_Pos)

#define BSP_RST_REG_BSP_CLK_POEG(pos)           R_CPG->CPG_RST_POEG
#define BSP_RST_BIT_BSP_CLK_POEG(pos)           (1U << R_CPG_CPG_RST_POEG_UNIT ## pos ## _RSTB_Pos)
#define BSP_RSTMON_REG_BSP_CLK_POEG(pos)        R_CPG->CPG_RSTMON_POEG
#define BSP_RSTMON_BIT_BSP_CLK_POEG(pos)        (1U << R_CPG_CPG_RSTMON_POEG_RST ## pos ## _MON_Pos)


#define BSP_CLKON_REG_BSP_CLK_WDT(pos)          R_CPG->CPG_CLKON_WDT
#define BSP_CLKON_BIT_BSP_CLK_WDT(pos)          (1U << R_CPG_CPG_CLKON_WDT_CLK ## pos ## _ON_Pos)
#define BSP_CLKMON_REG_BSP_CLK_WDT(pos)         R_CPG->CPG_CLKMON_WDT
#define BSP_CLKMON_BIT_BSP_CLK_WDT(pos)         (1U << R_CPG_CPG_CLKMON_WDT_CLK ## pos ## _MON_Pos)

#define BSP_RST_REG_BSP_CLK_WDT(pos)            R_CPG->CPG_RST_WDT
#define BSP_RST_BIT_BSP_CLK_WDT(pos)            (1U << R_CPG_CPG_RST_WDT_UNIT ## pos ## _RSTB_Pos)
#define BSP_RSTMON_REG_BSP_CLK_WDT(pos)         R_CPG->CPG_RSTMON_WDT
#define BSP_RSTMON_BIT_BSP_CLK_WDT(pos)         (1U << R_CPG_CPG_RSTMON_WDT_RST ## pos ## _MON_Pos)


#define BSP_CLKON_REG_BSP_CLK_DDR(pos)          R_CPG->CPG_CLKON_DDR
#define BSP_CLKON_BIT_BSP_CLK_DDR(pos)          (1U << R_CPG_CPG_CLKON_DDR_CLK ## pos ## _ON_Pos)
#define BSP_CLKMON_REG_BSP_CLK_DDR(pos)         R_CPG->CPG_CLKMON_DDR
#define BSP_CLKMON_BIT_BSP_CLK_DDR(pos)         (1U << R_CPG_CPG_CLKMON_DDR_CLK ## pos ## _MON_Pos)

#define BSP_RST_REG_BSP_CLK_DDR(pos)            R_CPG->CPG_RST_DDR
#define BSP_RST_BIT_BSP_CLK_DDR(pos)            (1U << R_CPG_CPG_RST_DDR_UNIT ## pos ## _RSTB_Pos)
#define BSP_RSTMON_REG_BSP_CLK_DDR(pos)         R_CPG->CPG_RSTMON_DDR
#define BSP_RSTMON_BIT_BSP_CLK_DDR(pos)         (1U << R_CPG_CPG_RSTMON_DDR_RST ## pos ## _MON_Pos)


#define BSP_CLKON_REG_BSP_CLK_SPI_MULTI(pos)    R_CPG->CPG_CLKON_SPI_MULTI
#define BSP_CLKON_BIT_BSP_CLK_SPI_MULTI(pos)    (1U << R_CPG_CPG_CLKON_SPI_MULTI_CLK ## pos ## _ON_Pos)
#define BSP_CLKMON_REG_BSP_CLK_SPI_MULTI(pos)   R_CPG->CPG_CLKMON_SPI_MULTI
#define BSP_CLKMON_BIT_BSP_CLK_SPI_MULTI(pos)   (1U << R_CPG_CPG_CLKMON_SPI_MULTI_CLK ## pos ## _MON_Pos)

#define BSP_RST_REG_BSP_CLK_SPI_MULTI(pos)       R_CPG->CPG_RST_SPI
#define BSP_RST_BIT_BSP_CLK_SPI_MULTI(pos)       (1U << R_CPG_CPG_RST_SPI_UNIT ## pos ## _RSTB_Pos)
#define BSP_RSTMON_REG_BSP_CLK_SPI_MULTI(pos)    R_CPG->CPG_RSTMON_SPI
#define BSP_RSTMON_BIT_BSP_CLK_SPI_MULTI(pos)    (1U << R_CPG_CPG_RSTMON_SPI_RST ## pos ## _MON_Pos)


#define BSP_CLKON_REG_BSP_CLK_SDHI(pos)         R_CPG->CPG_CLKON_SDHI
#define BSP_CLKON_BIT_BSP_CLK_SDHI(pos)         (1U << R_CPG_CPG_CLKON_SDHI_CLK ## pos ## _ON_Pos)
#define BSP_CLKMON_REG_BSP_CLK_SDHI(pos)        R_CPG->CPG_CLKMON_SDHI
#define BSP_CLKMON_BIT_BSP_CLK_SDHI(pos)        (1U << R_CPG_CPG_CLKMON_SDHI_CLK ## pos ## _MON_Pos)

#define BSP_RST_REG_BSP_CLK_SDHI(pos)           R_CPG->CPG_RST_SDHI
#define BSP_RST_BIT_BSP_CLK_SDHI(pos)           (1U << R_CPG_CPG_RST_SDHI_UNIT ## pos ## _RSTB_Pos)
#define BSP_RSTMON_REG_BSP_CLK_SDHI(pos)        R_CPG->CPG_RSTMON_SDHI
#define BSP_RSTMON_BIT_BSP_CLK_SDHI(pos)        (1U << R_CPG_CPG_RSTMON_SDHI_RST ## pos ## _MON_Pos)


#define BSP_CLKON_REG_BSP_CLK_GPU(pos)          R_CPG->CPG_CLKON_GPU
#define BSP_CLKON_BIT_BSP_CLK_GPU(pos)          (1U << R_CPG_CPG_CLKON_GPU_CLK ## pos ## _ON_Pos)
#define BSP_CLKMON_REG_BSP_CLK_GPU(pos)         R_CPG->CPG_CLKMON_GPU
#define BSP_CLKMON_BIT_BSP_CLK_GPU(pos)         (1U << R_CPG_CPG_CLKMON_GPU_CLK ## pos ## _MON_Pos)

#define BSP_RST_REG_BSP_CLK_GPU(pos)            R_CPG->CPG_RST_GPU
#define BSP_RST_BIT_BSP_CLK_GPU(pos)            (1U << R_CPG_CPG_RST_GPU_UNIT ## pos ## _RSTB_Pos)
#define BSP_RSTMON_REG_BSP_CLK_GPU(pos)         R_CPG->CPG_RSTMON_GPU
#define BSP_RSTMON_BIT_BSP_CLK_GPU(pos)         (1U << R_CPG_CPG_RSTMON_GPU_RST ## pos ## _MON_Pos)


#define BSP_CLKON_REG_BSP_CLK_ISU(pos)          R_CPG->CPG_CLKON_ISU
#define BSP_CLKON_BIT_BSP_CLK_ISU(pos)          (1U << R_CPG_CPG_CLKON_ISU_CLK ## pos ## _ON_Pos)
#define BSP_CLKMON_REG_BSP_CLK_ISU(pos)         R_CPG->CPG_CLKMON_ISU
#define BSP_CLKMON_BIT_BSP_CLK_ISU(pos)         (1U << R_CPG_CPG_CLKMON_ISU_CLK ## pos ## _MON_Pos)

#define BSP_RST_REG_BSP_CLK_ISU(pos)            R_CPG->CPG_RST_ISU
#define BSP_RST_BIT_BSP_CLK_ISU(pos)            (1U << R_CPG_CPG_RST_ISU_UNIT ## pos ## _RSTB_Pos)
#define BSP_RSTMON_REG_BSP_CLK_ISU(pos)         R_CPG->CPG_RSTMON_ISU
#define BSP_RSTMON_BIT_BSP_CLK_ISU(pos)         (1U << R_CPG_CPG_RSTMON_ISU_RST ## pos ## _MON_Pos)


#define BSP_CLKON_REG_BSP_CLK_H264(pos)         R_CPG->CPG_CLKON_H264
#define BSP_CLKON_BIT_BSP_CLK_H264(pos)         (1U << R_CPG_CPG_CLKON_H264_CLK ## pos ## _ON_Pos)
#define BSP_CLKMON_REG_BSP_CLK_H264(pos)        R_CPG->CPG_CLKMON_H264
#define BSP_CLKMON_BIT_BSP_CLK_H264(pos)        (1U << R_CPG_CPG_CLKMON_H264_CLK ## pos ## _MON_Pos)

#define BSP_RST_REG_BSP_CLK_H264(pos)           R_CPG->CPG_RST_H264
#define BSP_RST_BIT_BSP_CLK_H264(pos)           (1U << R_CPG_CPG_RST_H264_UNIT ## pos ## _RSTB_Pos)
#define BSP_RSTMON_REG_BSP_CLK_H264(pos)        R_CPG->CPG_RSTMON_H264
#define BSP_RSTMON_BIT_BSP_CLK_H264(pos)        (1U << R_CPG_CPG_RSTMON_H264_RST ## pos ## _MON_Pos)


#define BSP_CLKON_REG_BSP_CLK_CRU(pos)          R_CPG->CPG_CLKON_CRU
#define BSP_CLKON_BIT_BSP_CLK_CRU(pos)          (1U << R_CPG_CPG_CLKON_CRU_CLK ## pos ## _ON_Pos)
#define BSP_CLKMON_REG_BSP_CLK_CRU(pos)         R_CPG->CPG_CLKMON_CRU
#define BSP_CLKMON_BIT_BSP_CLK_CRU(pos)         (1U << R_CPG_CPG_CLKMON_CRU_CLK ## pos ## _MON_Pos)

#define BSP_RST_REG_BSP_CLK_CRU(pos)            R_CPG->CPG_RST_CRU
#define BSP_RST_BIT_BSP_CLK_CRU(pos)            (1U << R_CPG_CPG_RST_CRU_UNIT ## pos ## _RSTB_Pos)
#define BSP_RSTMON_REG_BSP_CLK_CRU(pos)         R_CPG->CPG_RSTMON_CRU
#define BSP_RSTMON_BIT_BSP_CLK_CRU(pos)         (1U << R_CPG_CPG_RSTMON_CRU_RST ## pos ## _MON_Pos)


#define BSP_CLKON_REG_BSP_CLK_MIPI_DSI(pos)     R_CPG->CPG_CLKON_MIPI_DSI
#define BSP_CLKON_BIT_BSP_CLK_MIPI_DSI(pos)     (1U << R_CPG_CPG_CLKON_MIPI_DSI_CLK ## pos ## _ON_Pos)
#define BSP_CLKMON_REG_BSP_CLK_MIPI_DSI(pos)    R_CPG->CPG_CLKMON_MIPI_DSI
#define BSP_CLKMON_BIT_BSP_CLK_MIPI_DSI(pos)    (1U << R_CPG_CPG_CLKMON_MIPI_DSI_CLK ## pos ## _MON_Pos)

#define BSP_RST_REG_BSP_CLK_MIPI_DSI(pos)       R_CPG->CPG_RST_MIPI_DSI
#define BSP_RST_BIT_BSP_CLK_MIPI_DSI(pos)       (1U << R_CPG_CPG_RST_MIPI_DSI_UNIT ## pos ## _RSTB_Pos)
#define BSP_RSTMON_REG_BSP_CLK_MIPI_DSI(pos)    R_CPG->CPG_RSTMON_MIPI_DSI
#define BSP_RSTMON_BIT_BSP_CLK_MIPI_DSI(pos)    (1U << R_CPG_CPG_RSTMON_MIPI_DSI_RST ## pos ## _MON_Pos)


#define BSP_CLKON_REG_BSP_CLK_LCDC(pos)         R_CPG->CPG_CLKON_LCDC
#define BSP_CLKON_BIT_BSP_CLK_LCDC(pos)         (1U << R_CPG_CPG_CLKON_LCDC_CLK ## pos ## _ON_Pos)
#define BSP_CLKMON_REG_BSP_CLK_LCDC(pos)        R_CPG->CPG_CLKMON_LCDC
#define BSP_CLKMON_BIT_BSP_CLK_LCDC(pos)        (1U << R_CPG_CPG_CLKMON_LCDC_CLK ## pos ## _MON_Pos)

#define BSP_RST_REG_BSP_CLK_LCDC(pos)           R_CPG->CPG_RST_LCDC
#define BSP_RST_BIT_BSP_CLK_LCDC(pos)           (1U << R_CPG_CPG_RST_LCDC_UNIT ## pos ## _RSTB_Pos)
#define BSP_RSTMON_REG_BSP_CLK_LCDC(pos)        R_CPG->CPG_RSTMON_LCDC
#define BSP_RSTMON_BIT_BSP_CLK_LCDC(pos)        (1U << R_CPG_CPG_RSTMON_LCDC_RST ## pos ## _MON_Pos)


#define BSP_CLKON_REG_BSP_CLK_SSIF(pos)     R_CPG->CPG_CLKON_SSI
#define BSP_CLKON_BIT_BSP_CLK_SSIF(pos)     (1U << R_CPG_CPG_CLKON_SSI_CLK ## pos ## _ON_Pos)
#define BSP_CLKMON_REG_BSP_CLK_SSIF(pos)    R_CPG->CPG_CLKMON_SSI
#define BSP_CLKMON_BIT_BSP_CLK_SSIF(pos)    (1U << R_CPG_CPG_CLKMON_SSI_CLK ## pos ## _MON_Pos)

#define BSP_RST_REG_BSP_CLK_SSIF(pos)       R_CPG->CPG_RST_SSIF
#define BSP_RST_BIT_BSP_CLK_SSIF(pos)       (1U << R_CPG_CPG_RST_SSIF_UNIT ## pos ## _RSTB_Pos)
#define BSP_RSTMON_REG_BSP_CLK_SSIF(pos)    R_CPG->CPG_RSTMON_SSIF
#define BSP_RSTMON_BIT_BSP_CLK_SSIF(pos)    (1U << R_CPG_CPG_RSTMON_SSIF_RST ## pos ## _MON_Pos)


#define BSP_CLKON_REG_BSP_CLK_SRC(pos)          R_CPG->CPG_CLKON_SRC
#define BSP_CLKON_BIT_BSP_CLK_SRC(pos)          (1U << R_CPG_CPG_CLKON_SRC_CLK ## pos ## _ON_Pos)
#define BSP_CLKMON_REG_BSP_CLK_SRC(pos)         R_CPG->CPG_CLKMON_SRC
#define BSP_CLKMON_BIT_BSP_CLK_SRC(pos)         (1U << R_CPG_CPG_CLKMON_SRC_CLK ## pos ## _MON_Pos)

#define BSP_RST_REG_BSP_CLK_SRC(pos)            R_CPG->CPG_RST_SRC
#define BSP_RST_BIT_BSP_CLK_SRC(pos)            (1U << R_CPG_CPG_RST_SRC_UNIT ## pos ## _RSTB_Pos)
#define BSP_RSTMON_REG_BSP_CLK_SRC(pos)         R_CPG->CPG_RSTMON_SRC
#define BSP_RSTMON_BIT_BSP_CLK_SRC(pos)         (1U << R_CPG_CPG_RSTMON_SRC_RST ## pos ## _MON_Pos)


#define BSP_CLKON_REG_BSP_CLK_USB(pos)          R_CPG->CPG_CLKON_USB
#define BSP_CLKON_BIT_BSP_CLK_USB(pos)          (1U << R_CPG_CPG_CLKON_USB_CLK ## pos ## _ON_Pos)
#define BSP_CLKMON_REG_BSP_CLK_USB(pos)         R_CPG->CPG_CLKMON_USB
#define BSP_CLKMON_BIT_BSP_CLK_USB(pos)         (1U << R_CPG_CPG_CLKMON_USB_CLK ## pos ## _MON_Pos)

#define BSP_RST_REG_BSP_CLK_USB(pos)            R_CPG->CPG_RST_USB
#define BSP_RST_BIT_BSP_CLK_USB(pos)            (1U << R_CPG_CPG_RST_USB_UNIT ## pos ## _RSTB_Pos)
#define BSP_RSTMON_REG_BSP_CLK_USB(pos)         R_CPG->CPG_RSTMON_USB
#define BSP_RSTMON_BIT_BSP_CLK_USB(pos)         (1U << R_CPG_CPG_RSTMON_USB_RST ## pos ## _MON_Pos)


#define BSP_CLKON_REG_BSP_CLK_ETH(pos)     R_CPG->CPG_CLKON_ETH
#define BSP_CLKON_BIT_BSP_CLK_ETH(pos)     (1U << R_CPG_CPG_CLKON_ETH_CLK ## pos ## _ON_Pos)
#define BSP_CLKMON_REG_BSP_CLK_ETH(pos)    R_CPG->CPG_CLKMON_ETH
#define BSP_CLKMON_BIT_BSP_CLK_ETH(pos)    (1U << R_CPG_CPG_CLKMON_ETH_CLK ## pos ## _MON_Pos)

#define BSP_RST_REG_BSP_CLK_ETH(pos)       R_CPG->CPG_RST_ETH
#define BSP_RST_BIT_BSP_CLK_ETH(pos)       (1U << R_CPG_CPG_RST_ETH_UNIT ## pos ## _RSTB_Pos)
#define BSP_RSTMON_REG_BSP_CLK_ETH(pos)    R_CPG->CPG_RSTMON_ETH
#define BSP_RSTMON_BIT_BSP_CLK_ETH(pos)    (1U << R_CPG_CPG_RSTMON_ETH_RST ## pos ## _MON_Pos)


#define BSP_CLKON_REG_BSP_CLK_I2C(pos)     R_CPG->CPG_CLKON_I2C
#define BSP_CLKON_BIT_BSP_CLK_I2C(pos)     (1U << R_CPG_CPG_CLKON_I2C_CLK ## pos ## _ON_Pos)
#define BSP_CLKMON_REG_BSP_CLK_I2C(pos)    R_CPG->CPG_CLKMON_I2C
#define BSP_CLKMON_BIT_BSP_CLK_I2C(pos)    (1U << R_CPG_CPG_CLKMON_I2C_CLK ## pos ## _MON_Pos)

#define BSP_RST_REG_BSP_CLK_I2C(pos)       R_CPG->CPG_RST_I2C
#define BSP_RST_BIT_BSP_CLK_I2C(pos)       (1U << R_CPG_CPG_RST_I2C_UNIT ## pos ## _RSTB_Pos)
#define BSP_RSTMON_REG_BSP_CLK_I2C(pos)    R_CPG->CPG_RSTMON_I2C
#define BSP_RSTMON_BIT_BSP_CLK_I2C(pos)    (1U << R_CPG_CPG_RSTMON_I2C_RST ## pos ## _MON_Pos)


#define BSP_CLKON_REG_BSP_CLK_SCIF(pos)     R_CPG->CPG_CLKON_SCIF
#define BSP_CLKON_BIT_BSP_CLK_SCIF(pos)     (1U << R_CPG_CPG_CLKON_SCIF_CLK ## pos ## _ON_Pos)
#define BSP_CLKMON_REG_BSP_CLK_SCIF(pos)    R_CPG->CPG_CLKMON_SCIF
#define BSP_CLKMON_BIT_BSP_CLK_SCIF(pos)    (1U << R_CPG_CPG_CLKMON_SCIF_CLK ## pos ## _MON_Pos)

#define BSP_RST_REG_BSP_CLK_SCIF(pos)       R_CPG->CPG_RST_SCIF
#define BSP_RST_BIT_BSP_CLK_SCIF(pos)       (1U << R_CPG_CPG_RST_SCIF_UNIT ## pos ## _RSTB_Pos)
#define BSP_RSTMON_REG_BSP_CLK_SCIF(pos)    R_CPG->CPG_RSTMON_SCIF
#define BSP_RSTMON_BIT_BSP_CLK_SCIF(pos)    (1U << R_CPG_CPG_RSTMON_SCIF_RST ## pos ## _MON_Pos)


#define BSP_CLKON_REG_BSP_CLK_SCI(pos)     R_CPG->CPG_CLKON_SCI
#define BSP_CLKON_BIT_BSP_CLK_SCI(pos)     (1U << R_CPG_CPG_CLKON_SCI_CLK ## pos ## _ON_Pos)
#define BSP_CLKMON_REG_BSP_CLK_SCI(pos)    R_CPG->CPG_CLKMON_SCI
#define BSP_CLKMON_BIT_BSP_CLK_SCI(pos)    (1U << R_CPG_CPG_CLKMON_SCI_CLK ## pos ## _MON_Pos)

#define BSP_RST_REG_BSP_CLK_SCI(pos)       R_CPG->CPG_RST_SCI
#define BSP_RST_BIT_BSP_CLK_SCI(pos)       (1U << R_CPG_CPG_RST_SCI_UNIT ## pos ## _RSTB_Pos)
#define BSP_RSTMON_REG_BSP_CLK_SCI(pos)    R_CPG->CPG_RSTMON_SCI
#define BSP_RSTMON_BIT_BSP_CLK_SCI(pos)    (1U << R_CPG_CPG_RSTMON_SCI_RST ## pos ## _MON_Pos)


#define BSP_CLKON_REG_BSP_CLK_IRDA(pos)     R_CPG->CPG_CLKON_IRDA
#define BSP_CLKON_BIT_BSP_CLK_IRDA(pos)     (1U << R_CPG_CPG_CLKON_IRDA_CLK ## pos ## _ON_Pos)
#define BSP_CLKMON_REG_BSP_CLK_IRDA(pos)    R_CPG->CPG_CLKMON_IRDA
#define BSP_CLKMON_BIT_BSP_CLK_IRDA(pos)    (1U << R_CPG_CPG_CLKMON_IRDA_CLK ## pos ## _MON_Pos)

#define BSP_RST_REG_BSP_CLK_IRDA(pos)       R_CPG->CPG_RST_IRDA
#define BSP_RST_BIT_BSP_CLK_IRDA(pos)       (1U << R_CPG_CPG_RST_IRDA_UNIT ## pos ## _RSTB_Pos)
#define BSP_RSTMON_REG_BSP_CLK_IRDA(pos)    R_CPG->CPG_RSTMON_IRDA
#define BSP_RSTMON_BIT_BSP_CLK_IRDA(pos)    (1U << R_CPG_CPG_RSTMON_IRDA_RST ## pos ## _MON_Pos)


#define BSP_CLKON_REG_BSP_CLK_RSPI(pos)     R_CPG->CPG_CLKON_RSPI
#define BSP_CLKON_BIT_BSP_CLK_RSPI(pos)     (1U << R_CPG_CPG_CLKON_RSPI_CLK ## pos ## _ON_Pos)
#define BSP_CLKMON_REG_BSP_CLK_RSPI(pos)    R_CPG->CPG_CLKMON_RSPI
#define BSP_CLKMON_BIT_BSP_CLK_RSPI(pos)    (1U << R_CPG_CPG_CLKMON_RSPI_CLK ## pos ## _MON_Pos)

#define BSP_RST_REG_BSP_CLK_RSPI(pos)       R_CPG->CPG_RST_RSPI
#define BSP_RST_BIT_BSP_CLK_RSPI(pos)       (1U << R_CPG_CPG_RST_RSPI_UNIT ## pos ## _RSTB_Pos)
#define BSP_RSTMON_REG_BSP_CLK_RSPI(pos)    R_CPG->CPG_RSTMON_RSPI
#define BSP_RSTMON_BIT_BSP_CLK_RSPI(pos)    (1U << R_CPG_CPG_RSTMON_RSPI_RST ## pos ## _MON_Pos)


#define BSP_CLKON_REG_BSP_CLK_CANFD(pos)     R_CPG->CPG_CLKON_CANFD
#define BSP_CLKON_BIT_BSP_CLK_CANFD(pos)     (1U << R_CPG_CPG_CLKON_CANFD_CLK ## pos ## _ON_Pos)
#define BSP_CLKMON_REG_BSP_CLK_CANFD(pos)    R_CPG->CPG_CLKMON_CANFD
#define BSP_CLKMON_BIT_BSP_CLK_CANFD(pos)    (1U << R_CPG_CPG_CLKMON_CANFD_CLK ## pos ## _MON_Pos)

#define BSP_RST_REG_BSP_CLK_CANFD(pos)       R_CPG->CPG_RST_CANFD
#define BSP_RST_BIT_BSP_CLK_CANFD(pos)       (1U << R_CPG_CPG_RST_CANFD_UNIT ## pos ## _RSTB_Pos)
#define BSP_RSTMON_REG_BSP_CLK_CANFD(pos)    R_CPG->CPG_RSTMON_CANFD
#define BSP_RSTMON_BIT_BSP_CLK_CANFD(pos)    (1U << R_CPG_CPG_RSTMON_CANFD_RST ## pos ## _MON_Pos)


#define BSP_CLKON_REG_BSP_CLK_GPIO(pos)     R_CPG->CPG_CLKON_GPIO
#define BSP_CLKON_BIT_BSP_CLK_GPIO(pos)     (1U << R_CPG_CPG_CLKON_GPIO_CLK ## pos ## _ON_Pos)
#define BSP_CLKMON_REG_BSP_CLK_GPIO(pos)    R_CPG->CPG_CLKMON_GPIO
#define BSP_CLKMON_BIT_BSP_CLK_GPIO(pos)    (1U << R_CPG_CPG_CLKMON_GPIO_CLK ## pos ## _MON_Pos)

#define BSP_RST_REG_BSP_CLK_GPIO(pos)       R_CPG->CPG_RST_GPIO
#define BSP_RST_BIT_BSP_CLK_GPIO(pos)       (1U << R_CPG_CPG_RST_GPIO_UNIT ## pos ## _RSTB_Pos)
#define BSP_RSTMON_REG_BSP_CLK_GPIO(pos)    R_CPG->CPG_RSTMON_GPIO
#define BSP_RSTMON_BIT_BSP_CLK_GPIO(pos)    (1U << R_CPG_CPG_RSTMON_GPIO_RST ## pos ## _MON_Pos)


#define BSP_CLKON_REG_BSP_CLK_TSIPG(pos)     R_CPG->CPG_CLKON_TSIPG
#define BSP_CLKON_BIT_BSP_CLK_TSIPG(pos)     (1U << R_CPG_CPG_CLKON_TSIPG_CLK ## pos ## _ON_Pos)
#define BSP_CLKMON_REG_BSP_CLK_TSIPG(pos)    R_CPG->CPG_CLKMON_TSIPG
#define BSP_CLKMON_BIT_BSP_CLK_TSIPG(pos)    (1U << R_CPG_CPG_CLKMON_TSIPG_CLK ## pos ## _MON_Pos)

#define BSP_RST_REG_BSP_CLK_TSIPG(pos)       R_CPG->CPG_RST_TSIPG
#define BSP_RST_BIT_BSP_CLK_TSIPG(pos)       (1U << R_CPG_CPG_RST_TSIPG_UNIT ## pos ## _RSTB_Pos)
#define BSP_RSTMON_REG_BSP_CLK_TSIPG(pos)    R_CPG->CPG_RSTMON_TSIPG
#define BSP_RSTMON_BIT_BSP_CLK_TSIPG(pos)    (1U << R_CPG_CPG_RSTMON_TSIPG_RST ## pos ## _MON_Pos)


#define BSP_CLKMON_REG_BSP_CLK_JAUTH(pos)    R_CPG->CPG_CLKMON_JAUTH
#define BSP_CLKMON_BIT_BSP_CLK_JAUTH(pos)    (1U << R_CPG_CPG_CLKMON_JAUTH_CLK ## pos ## _MON_Pos)

#define BSP_RST_REG_BSP_CLK_JAUTH(pos)       R_CPG->CPG_RST_JAUTH
#define BSP_RST_BIT_BSP_CLK_JAUTH(pos)       (1U << R_CPG_CPG_RST_JAUTH_UNIT ## pos ## _RSTB_Pos)
#define BSP_RSTMON_REG_BSP_CLK_JAUTH(pos)    R_CPG->CPG_RSTMON_JAUTH
#define BSP_RSTMON_BIT_BSP_CLK_JAUTH(pos)    (1U << R_CPG_CPG_RSTMON_JAUTH_RST ## pos ## _MON_Pos)


#define BSP_CLKON_REG_BSP_CLK_OTP(pos)     R_CPG->CPG_CLKON_OTP
#define BSP_CLKON_BIT_BSP_CLK_OTP(pos)     (1U << R_CPG_CPG_CLKON_OTP_CLK ## pos ## _ON_Pos)
#define BSP_CLKMON_REG_BSP_CLK_OTP(pos)    R_CPG->CPG_CLKMON_OTP
#define BSP_CLKMON_BIT_BSP_CLK_OTP(pos)    (1U << R_CPG_CPG_CLKMON_OTP_CLK ## pos ## _MON_Pos)

#define BSP_RST_REG_BSP_CLK_OTP(pos)       R_CPG->CPG_RST_OTP
#define BSP_RST_BIT_BSP_CLK_OTP(pos)       (1U << R_CPG_CPG_RST_OTP_UNIT ## pos ## _RSTB_Pos)
#define BSP_RSTMON_REG_BSP_CLK_OTP(pos)    R_CPG->CPG_RSTMON_OTP
#define BSP_RSTMON_BIT_BSP_CLK_OTP(pos)    (1U << R_CPG_CPG_RSTMON_OTP_RST ## pos ## _MON_Pos)


#define BSP_CLKON_REG_BSP_CLK_ADC(pos)     R_CPG->CPG_CLKON_ADC
#define BSP_CLKON_BIT_BSP_CLK_ADC(pos)     (1U << R_CPG_CPG_CLKON_ADC_CLK ## pos ## _ON_Pos)
#define BSP_CLKMON_REG_BSP_CLK_ADC(pos)    R_CPG->CPG_CLKMON_ADC
#define BSP_CLKMON_BIT_BSP_CLK_ADC(pos)    (1U << R_CPG_CPG_CLKMON_ADC_CLK ## pos ## _MON_Pos)

#define BSP_RST_REG_BSP_CLK_ADC(pos)       R_CPG->CPG_RST_ADC
#define BSP_RST_BIT_BSP_CLK_ADC(pos)       (1U << R_CPG_CPG_RST_ADC_UNIT ## pos ## _RSTB_Pos)
#define BSP_RSTMON_REG_BSP_CLK_ADC(pos)    R_CPG->CPG_RSTMON_ADC
#define BSP_RSTMON_BIT_BSP_CLK_ADC(pos)    (1U << R_CPG_CPG_RSTMON_ADC_RST ## pos ## _MON_Pos)


#define BSP_CLKON_REG_BSP_CLK_TSU(pos)     R_CPG->CPG_CLKON_TSU
#define BSP_CLKON_BIT_BSP_CLK_TSU(pos)     (1U << R_CPG_CPG_CLKON_TSU_CLK ## pos ## _ON_Pos)
#define BSP_CLKMON_REG_BSP_CLK_TSU(pos)    R_CPG->CPG_CLKMON_TSU
#define BSP_CLKMON_BIT_BSP_CLK_TSU(pos)    (1U << R_CPG_CPG_CLKMON_TSU_CLK ## pos ## _MON_Pos)

#define BSP_RST_REG_BSP_CLK_TSU(pos)       R_CPG->CPG_RST_TSU
#define BSP_RST_BIT_BSP_CLK_TSU(pos)       (1U << R_CPG_CPG_RST_TSU_UNIT ## pos ## _RSTB_Pos)
#define BSP_RSTMON_REG_BSP_CLK_TSU(pos)    R_CPG->CPG_RSTMON_TSU
#define BSP_RSTMON_BIT_BSP_CLK_TSU(pos)    (1U << R_CPG_CPG_RSTMON_TSU_RST ## pos ## _MON_Pos)


#define BSP_CLKON_REG_BSP_CLK_BBGU(pos)     R_CPG->CPG_CLKON_BBGU
#define BSP_CLKON_BIT_BSP_CLK_BBGU(pos)     (1U << R_CPG_CPG_CLKON_BBGU_CLK ## pos ## _ON_Pos)
#define BSP_CLKMON_REG_BSP_CLK_BBGU(pos)    R_CPG->CPG_CLKMON_BBGU
#define BSP_CLKMON_BIT_BSP_CLK_BBGU(pos)    (1U << R_CPG_CPG_CLKMON_BBGU_CLK ## pos ## _MON_Pos)

#define BSP_RST_REG_BSP_CLK_BBGU(pos)       R_CPG->CPG_RST_BBGU
#define BSP_RST_BIT_BSP_CLK_BBGU(pos)       (1U << R_CPG_CPG_RST_BBGU_UNIT ## pos ## _RSTB_Pos)
#define BSP_RSTMON_REG_BSP_CLK_BBGU(pos)    R_CPG->CPG_RSTMON_BBGU
#define BSP_RSTMON_BIT_BSP_CLK_BBGU(pos)    (1U << R_CPG_CPG_RSTMON_BBGU_RST ## pos ## _MON_Pos)


#define BSP_CLKON_REG_BSP_CLK_AXI_ACPU_BUS(pos)     R_CPG->CPG_CLKON_AXI_ACPU_BUS
#define BSP_CLKON_BIT_BSP_CLK_AXI_ACPU_BUS(pos)     (1U << R_CPG_CPG_CLKON_AXI_ACPU_BUS_CLK ## pos ## _ON_Pos)
#define BSP_CLKMON_REG_BSP_CLK_AXI_ACPU_BUS(pos)    R_CPG->CPG_CLKMON_AXI_ACPU_BUS
#define BSP_CLKMON_BIT_BSP_CLK_AXI_ACPU_BUS(pos)    (1U << R_CPG_CPG_CLKMON_AXI_ACPU_BUS_CLK ## pos ## _MON_Pos)

#define BSP_RST_REG_BSP_CLK_AXI_ACPU_BUS(pos)       R_CPG->CPG_RST_AXI_ACPU_BUS
#define BSP_RST_BIT_BSP_CLK_AXI_ACPU_BUS(pos)       (1U << R_CPG_CPG_RST_AXI_ACPU_BUS_UNIT ## pos ## _RSTB_Pos)
#define BSP_RSTMON_REG_BSP_CLK_AXI_ACPU_BUS(pos)    R_CPG->CPG_RSTMON_AXI_ACPU_BUS
#define BSP_RSTMON_BIT_BSP_CLK_AXI_ACPU_BUS(pos)    (1U << R_CPG_CPG_RSTMON_AXI_ACPU_BUS_RST ## pos ## _MON_Pos)


#define BSP_CLKON_REG_BSP_CLK_AXI_MCPU_BUS(pos)     R_CPG->CPG_CLKON_AXI_MCPU_BUS
#define BSP_CLKON_BIT_BSP_CLK_AXI_MCPU_BUS(pos)     (1U << R_CPG_CPG_CLKON_AXI_MCPU_BUS_CLK ## pos ## _ON_Pos)
#define BSP_CLKMON_REG_BSP_CLK_AXI_MCPU_BUS(pos)    R_CPG->CPG_CLKMON_AXI_MCPU_BUS
#define BSP_CLKMON_BIT_BSP_CLK_AXI_MCPU_BUS(pos)    (1U << R_CPG_CPG_CLKMON_AXI_MCPU_BUS_CLK ## pos ## _MON_Pos)

#define BSP_RST_REG_BSP_CLK_AXI_MCPU_BUS(pos)       R_CPG->CPG_RST_AXI_MCPU_BUS
#define BSP_RST_BIT_BSP_CLK_AXI_MCPU_BUS(pos)       (1U << R_CPG_CPG_RST_AXI_MCPU_BUS_UNIT ## pos ## _RSTB_Pos)
#define BSP_RSTMON_REG_BSP_CLK_AXI_MCPU_BUS(pos)    R_CPG->CPG_RSTMON_AXI_MCPU_BUS
#define BSP_RSTMON_BIT_BSP_CLK_AXI_MCPU_BUS(pos)    (1U << R_CPG_CPG_RSTMON_AXI_MCPU_BUS_RST ## pos ## _MON_Pos)


#define BSP_CLKON_REG_BSP_CLK_AXI_COM_BUS(pos)     R_CPG->CPG_CLKON_AXI_COM_BUS
#define BSP_CLKON_BIT_BSP_CLK_AXI_COM_BUS(pos)     (1U << R_CPG_CPG_CLKON_AXI_COM_BUS_CLK ## pos ## _ON_Pos)
#define BSP_CLKMON_REG_BSP_CLK_AXI_COM_BUS(pos)    R_CPG->CPG_CLKMON_AXI_COM_BUS
#define BSP_CLKMON_BIT_BSP_CLK_AXI_COM_BUS(pos)    (1U << R_CPG_CPG_CLKMON_AXI_COM_BUS_CLK ## pos ## _MON_Pos)

#define BSP_RST_REG_BSP_CLK_AXI_COM_BUS(pos)       R_CPG->CPG_RST_AXI_COM_BUS
#define BSP_RST_BIT_BSP_CLK_AXI_COM_BUS(pos)       (1U << R_CPG_CPG_RST_AXI_COM_BUS_UNIT ## pos ## _RSTB_Pos)
#define BSP_RSTMON_REG_BSP_CLK_AXI_COM_BUS(pos)    R_CPG->CPG_RSTMON_AXI_COM_BUS
#define BSP_RSTMON_BIT_BSP_CLK_AXI_COM_BUS(pos)    (1U << R_CPG_CPG_RSTMON_AXI_COM_BUS_RST ## pos ## _MON_Pos)


#define BSP_CLKON_REG_BSP_CLK_AXI_VIDEO_BUS(pos)     R_CPG->CPG_CLKON_AXI_VIDEO_BUS
#define BSP_CLKON_BIT_BSP_CLK_AXI_VIDEO_BUS(pos)     (1U << R_CPG_CPG_CLKON_AXI_VIDEO_BUS_CLK ## pos ## _ON_Pos)
#define BSP_CLKMON_REG_BSP_CLK_AXI_VIDEO_BUS(pos)    R_CPG->CPG_CLKMON_AXI_VIDEO_BUS
#define BSP_CLKMON_BIT_BSP_CLK_AXI_VIDEO_BUS(pos)    (1U << R_CPG_CPG_CLKMON_AXI_VIDEO_BUS_CLK ## pos ## _MON_Pos)

#define BSP_RST_REG_BSP_CLK_AXI_VIDEO_BUS(pos)       R_CPG->CPG_RST_AXI_VIDEO_BUS
#define BSP_RST_BIT_BSP_CLK_AXI_VIDEO_BUS(pos)       (1U << R_CPG_CPG_RST_AXI_VIDEO_BUS_UNIT ## pos ## _RSTB_Pos)
#define BSP_RSTMON_REG_BSP_CLK_AXI_VIDEO_BUS(pos)    R_CPG->CPG_RSTMON_AXI_VIDEO_BUS
#define BSP_RSTMON_BIT_BSP_CLK_AXI_VIDEO_BUS(pos)    (1U << R_CPG_CPG_RSTMON_AXI_VIDEO_BUS_RST ## pos ## _MON_Pos)


#define BSP_CLKON_REG_BSP_CLK_PERI_COM(pos)     R_CPG->CPG_CLKON_PERI_COM
#define BSP_CLKON_BIT_BSP_CLK_PERI_COM(pos)     (1U << R_CPG_CPG_CLKON_PERI_COM_CLK ## pos ## _ON_Pos)
#define BSP_CLKMON_REG_BSP_CLK_PERI_COM(pos)    R_CPG->CPG_CLKMON_PERI_COM
#define BSP_CLKMON_BIT_BSP_CLK_PERI_COM(pos)    (1U << R_CPG_CPG_CLKMON_PERI_COM_CLK ## pos ## _MON_Pos)

#define BSP_RST_REG_BSP_CLK_PERI_COM(pos)       R_CPG->CPG_RST_PERI_COM
#define BSP_RST_BIT_BSP_CLK_PERI_COM(pos)       (1U << R_CPG_CPG_RST_PERI_COM_UNIT ## pos ## _RSTB_Pos)
#define BSP_RSTMON_REG_BSP_CLK_PERI_COM(pos)    R_CPG->CPG_RSTMON_PERI_COM
#define BSP_RSTMON_BIT_BSP_CLK_PERI_COM(pos)    (1U << R_CPG_CPG_RSTMON_PERI_COM_RST ## pos ## _MON_Pos)


#define BSP_CLKON_REG_BSP_CLK_REG1_BUS(pos)     R_CPG->CPG_CLKON_REG1_BUS
#define BSP_CLKON_BIT_BSP_CLK_REG1_BUS(pos)     (1U << R_CPG_CPG_CLKON_REG1_BUS_CLK ## pos ## _ON_Pos)
#define BSP_CLKMON_REG_BSP_CLK_REG1_BUS(pos)    R_CPG->CPG_CLKMON_REG1_BUS
#define BSP_CLKMON_BIT_BSP_CLK_REG1_BUS(pos)    (1U << R_CPG_CPG_CLKMON_REG1_BUS_CLK ## pos ## _MON_Pos)

#define BSP_RST_REG_BSP_CLK_REG1_BUS(pos)       R_CPG->CPG_RST_REG1_BUS
#define BSP_RST_BIT_BSP_CLK_REG1_BUS(pos)       (1U << R_CPG_CPG_RST_REG1_BUS_UNIT ## pos ## _RSTB_Pos)
#define BSP_RSTMON_REG_BSP_CLK_REG1_BUS(pos)    R_CPG->CPG_RSTMON_REG1_BUS
#define BSP_RSTMON_BIT_BSP_CLK_REG1_BUS(pos)    (1U << R_CPG_CPG_RSTMON_REG1_BUS_RST ## pos ## _MON_Pos)


#define BSP_CLKON_REG_BSP_CLK_REG0_BUS(pos)     R_CPG->CPG_CLKON_REG0_BUS
#define BSP_CLKON_BIT_BSP_CLK_REG0_BUS(pos)     (1U << R_CPG_CPG_CLKON_REG0_BUS_CLK ## pos ## _ON_Pos)
#define BSP_CLKMON_REG_BSP_CLK_REG0_BUS(pos)    R_CPG->CPG_CLKMON_REG0_BUS
#define BSP_CLKMON_BIT_BSP_CLK_REG0_BUS(pos)    (1U << R_CPG_CPG_CLKMON_REG0_BUS_CLK ## pos ## _MON_Pos)

#define BSP_RST_REG_BSP_CLK_REG0_BUS(pos)       R_CPG->CPG_RST_REG0_BUS
#define BSP_RST_BIT_BSP_CLK_REG0_BUS(pos)       (1U << R_CPG_CPG_RST_REG0_BUS_UNIT ## pos ## _RSTB_Pos)
#define BSP_RSTMON_REG_BSP_CLK_REG0_BUS(pos)    R_CPG->CPG_RSTMON_REG0_BUS
#define BSP_RSTMON_BIT_BSP_CLK_REG0_BUS(pos)    (1U << R_CPG_CPG_RSTMON_REG0_BUS_RST ## pos ## _MON_Pos)


#define BSP_CLKON_REG_BSP_CLK_PERI_CPU(pos)     R_CPG->CPG_CLKON_PERI_CPU
#define BSP_CLKON_BIT_BSP_CLK_PERI_CPU(pos)     (1U << R_CPG_CPG_CLKON_PERI_CPU_CLK ## pos ## _ON_Pos)
#define BSP_CLKMON_REG_BSP_CLK_PERI_CPU(pos)    R_CPG->CPG_CLKMON_PERI_CPU
#define BSP_CLKMON_BIT_BSP_CLK_PERI_CPU(pos)    (1U << R_CPG_CPG_CLKMON_PERI_CPU_CLK ## pos ## _MON_Pos)

#define BSP_RST_REG_BSP_CLK_PERI_CPU(pos)       R_CPG->CPG_RST_PERI_CPU
#define BSP_RST_BIT_BSP_CLK_PERI_CPU(pos)       (1U << R_CPG_CPG_RST_PERI_CPU_UNIT ## pos ## _RSTB_Pos)
#define BSP_RSTMON_REG_BSP_CLK_PERI_CPU(pos)    R_CPG->CPG_RSTMON_PERI_CPU
#define BSP_RSTMON_BIT_BSP_CLK_PERI_CPU(pos)    (1U << R_CPG_CPG_RSTMON_PERI_CPU_RST ## pos ## _MON_Pos)


#define BSP_CLKON_REG_BSP_CLK_PERI_VIDEO(pos)     R_CPG->CPG_CLKON_PERI_VIDEO
#define BSP_CLKON_BIT_BSP_CLK_PERI_VIDEO(pos)     (1U << R_CPG_CPG_CLKON_PERI_VIDEO_CLK ## pos ## _ON_Pos)
#define BSP_CLKMON_REG_BSP_CLK_PERI_VIDEO(pos)    R_CPG->CPG_CLKMON_PERI_VIDEO
#define BSP_CLKMON_BIT_BSP_CLK_PERI_VIDEO(pos)    (1U << R_CPG_CPG_CLKMON_PERI_VIDEO_CLK ## pos ## _MON_Pos)

#define BSP_RST_REG_BSP_CLK_PERI_VIDEO(pos)       R_CPG->CPG_RST_PERI_VIDEO
#define BSP_RST_BIT_BSP_CLK_PERI_VIDEO(pos)       (1U << R_CPG_CPG_RST_PERI_VIDEO_UNIT ## pos ## _RSTB_Pos)
#define BSP_RSTMON_REG_BSP_CLK_PERI_VIDEO(pos)    R_CPG->CPG_RSTMON_PERI_VIDEO
#define BSP_RSTMON_BIT_BSP_CLK_PERI_VIDEO(pos)    (1U << R_CPG_CPG_RSTMON_PERI_VIDEO_RST ## pos ## _MON_Pos)


#define BSP_CLKON_REG_BSP_CLK_PERI_DDR(pos)     R_CPG->CPG_CLKON_PERI_DDR
#define BSP_CLKON_BIT_BSP_CLK_PERI_DDR(pos)     (1U << R_CPG_CPG_CLKON_PERI_DDR_CLK ## pos ## _ON_Pos)
#define BSP_CLKMON_REG_BSP_CLK_PERI_DDR(pos)    R_CPG->CPG_CLKMON_PERI_DDR
#define BSP_CLKMON_BIT_BSP_CLK_PERI_DDR(pos)    (1U << R_CPG_CPG_CLKMON_PERI_DDR_CLK ## pos ## _MON_Pos)

#define BSP_RST_REG_BSP_CLK_PERI_DDR(pos)       R_CPG->CPG_RST_PERI_DDR
#define BSP_RST_BIT_BSP_CLK_PERI_DDR(pos)       (1U << R_CPG_CPG_RST_PERI_DDR_UNIT ## pos ## _RSTB_Pos)
#define BSP_RSTMON_REG_BSP_CLK_PERI_DDR(pos)    R_CPG->CPG_RSTMON_PERI_DDR
#define BSP_RSTMON_BIT_BSP_CLK_PERI_DDR(pos)    (1U << R_CPG_CPG_RSTMON_PERI_DDR_RST ## pos ## _MON_Pos)


#define BSP_CLKON_REG_BSP_CLK_AXI_TZCDDR(pos)     R_CPG->CPG_CLKON_AXI_TZCDDR
#define BSP_CLKON_BIT_BSP_CLK_AXI_TZCDDR(pos)     (1U << R_CPG_CPG_CLKON_AXI_TZCDDR_CLK ## pos ## _ON_Pos)
#define BSP_CLKMON_REG_BSP_CLK_AXI_TZCDDR(pos)    R_CPG->CPG_CLKMON_AXI_TZCDDR
#define BSP_CLKMON_BIT_BSP_CLK_AXI_TZCDDR(pos)    (1U << R_CPG_CPG_CLKMON_AXI_TZCDDR_CLK ## pos ## _MON_Pos)

#define BSP_RST_REG_BSP_CLK_AXI_TZCDDR(pos)       R_CPG->CPG_RST_AXI_TZCDDR
#define BSP_RST_BIT_BSP_CLK_AXI_TZCDDR(pos)       (1U << R_CPG_CPG_RST_AXI_TZCDDR_UNIT ## pos ## _RSTB_Pos)
#define BSP_RSTMON_REG_BSP_CLK_AXI_TZCDDR(pos)    R_CPG->CPG_RSTMON_AXI_TZCDDR
#define BSP_RSTMON_BIT_BSP_CLK_AXI_TZCDDR(pos)    (1U << R_CPG_CPG_RSTMON_AXI_TZCDDR_RST ## pos ## _MON_Pos)


#define BSP_CLKON_REG_BSP_CLK_MTGPGS(pos)     R_CPG->CPG_CLKON_MTGPGS
#define BSP_CLKON_BIT_BSP_CLK_MTGPGS(pos)     (1U << R_CPG_CPG_CLKON_MTGPGS_CLK ## pos ## _ON_Pos)
#define BSP_CLKMON_REG_BSP_CLK_MTGPGS(pos)    R_CPG->CPG_CLKMON_MTGPGS
#define BSP_CLKMON_BIT_BSP_CLK_MTGPGS(pos)    (1U << R_CPG_CPG_CLKMON_MTGPGS_CLK ## pos ## _MON_Pos)

#define BSP_RST_REG_BSP_CLK_MTGPGS(pos)       R_CPG->CPG_RST_MTGPGS
#define BSP_RST_BIT_BSP_CLK_MTGPGS(pos)       (1U << R_CPG_CPG_RST_MTGPGS_UNIT ## pos ## _RSTB_Pos)
#define BSP_RSTMON_REG_BSP_CLK_MTGPGS(pos)    R_CPG->CPG_RSTMON_MTGPGS
#define BSP_RSTMON_BIT_BSP_CLK_MTGPGS(pos)    (1U << R_CPG_CPG_RSTMON_MTGPGS_RST ## pos ## _MON_Pos)


#define BSP_CLKON_REG_BSP_CLK_AXI_DEFAULT_SLV(pos)     R_CPG->CPG_CLKON_AXI_DEFAULT_SLV
#define BSP_CLKON_BIT_BSP_CLK_AXI_DEFAULT_SLV(pos)     (1U << R_CPG_CPG_CLKON_AXI_DEFAULT_SLV_CLK ## pos ## _ON_Pos)
#define BSP_CLKMON_REG_BSP_CLK_AXI_DEFAULT_SLV(pos)    R_CPG->CPG_CLKMON_AXI_DEFAULT_SLV
#define BSP_CLKMON_BIT_BSP_CLK_AXI_DEFAULT_SLV(pos)    (1U << R_CPG_CPG_CLKMON_AXI_DEFAULT_SLV_CLK ## pos ## _MON_Pos)

#define BSP_RST_REG_BSP_CLK_AXI_DEFAULT_SLV(pos)       R_CPG->CPG_RST_AXI_DEFAULT_SLV
#define BSP_RST_BIT_BSP_CLK_AXI_DEFAULT_SLV(pos)       (1U << R_CPG_CPG_RST_AXI_DEFAULT_SLV_UNIT ## pos ## _RSTB_Pos)
#define BSP_RSTMON_REG_BSP_CLK_AXI_DEFAULT_SLV(pos)    R_CPG->CPG_RSTMON_AXI_DEFAULT_SLV
#define BSP_RSTMON_BIT_BSP_CLK_AXI_DEFAULT_SLV(pos)    (1U << R_CPG_CPG_RSTMON_AXI_DEFAULT_SLV_RST ## pos ## _MON_Pos)

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** Following Units are available clock generation & control, also reset generation & control. */
typedef enum e_bsp_clk_unit
{
	BSP_CLK_CA55 = 0,
	BSP_CLK_CM33,
	BSP_CLK_SRAM_ACPU,
	BSP_CLK_SRAM_MCPU,
	BSP_CLK_ROM,
	BSP_CLK_GIC600,
	BSP_CLK_IA55,
	BSP_CLK_IM33,
	BSP_CLK_MHU,
	BSP_CLK_CST,
	BSP_CLK_SYC,
	BSP_CLK_DMAC_REG,
	BSP_CLK_SYSC,
	BSP_CLK_GTM,
	BSP_CLK_MTU,
	BSP_CLK_POE3,
	BSP_CLK_GPT,
	BSP_CLK_POEG,
	BSP_CLK_WDT,
	BSP_CLK_DDR,
	BSP_CLK_SPI_MULTI,
	BSP_CLK_SDHI,
	BSP_CLK_GPU,
	BSP_CLK_ISU,
	BSP_CLK_H264,
	BSP_CLK_CRU,
	BSP_CLK_MIPI_DSI,
	BSP_CLK_LCDC,
	BSP_CLK_SSIF,
	BSP_CLK_SRC,
	BSP_CLK_USB,
	BSP_CLK_ETH,
	BSP_CLK_I2C,
	BSP_CLK_SCIF,
	BSP_CLK_SCI,
	BSP_CLK_IRDA,
	BSP_CLK_RSPI,
	BSP_CLK_CANFD,
	BSP_CLK_GPIO,
	BSP_CLK_TSIPG,
	BSP_CLK_JAUTH,
	BSP_CLK_OTP,
	BSP_CLK_ADC,
	BSP_CLK_TSU,
	BSP_CLK_BBGU,
	BSP_CLK_AXI_ACPU_BUS,
	BSP_CLK_AXI_MCPU_BUS,
	BSP_CLK_AXI_COM_BUS,
	BSP_CLK_AXI_VIDEO_BUS,
	BSP_CLK_PERI_COM,
	BSP_CLK_REG1_BUS,
	BSP_CLK_REG0_BUS,
	BSP_CLK_PERI_CPU,
	BSP_CLK_PERI_VIDEO,
	BSP_CLK_PERI_DDR,
	BSP_CLK_AXI_TZCDDR,
	BSP_CLK_MTGPGS,
	BSP_CLK_AXI_DEFAULT_SLV,
} bsp_clk_unit_t;

/***********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 **********************************************************************************************************************/

/* Public functions defined in bsp.h */
void bsp_clock_init(void);             // Used internally by BSP

#if BSP_TZ_CFG_INIT_SECURE_ONLY
void bsp_clock_freq_var_init(void);    // Used internally by BSP

#endif

/** Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif
