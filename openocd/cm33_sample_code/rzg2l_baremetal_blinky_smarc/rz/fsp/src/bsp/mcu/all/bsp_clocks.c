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
#include "bsp_clocks.h"

#if BSP_TZ_NONSECURE_BUILD
 #include "bsp_guard.h"
#endif

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/
/* The number of clocks is used to size the g_clock_freq array. */
#define BSP_PRV_NUM_CLOCKS                     (FSP_PRIV_CLOCK_NUM)

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global variables (to be accessed by other files)
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private global variables and functions
 **********************************************************************************************************************/

/* This array stores the clock frequency of each bus clock. This section of RAM should not be initialized by the C
 * runtime environment. This is initialized and used in bsp_clock_init, which is called before the C runtime
 * environment is initialized. */
static uint32_t g_clock_freq[BSP_PRV_NUM_CLOCKS] =
{
	BSP_CFG_CLOCK_ICLK_HZ,                     /* Initial value of Cortex-A55 Clock */
	BSP_CFG_CLOCK_I2CLK_HZ,                    /* Initial value of Cortex-M33 Clock */
	BSP_CFG_CLOCK_GCLK_HZ,                     /* Initial value of GPU Clock */
	BSP_CFG_CLOCK_S0CLK_HZ,                    /* Initial value of DDR-PHY Clock */
	BSP_CFG_CLOCK_S1CLK_HZ,                    /* Initial value of DDR-PHY, MEMC Clock */
	BSP_CFG_CLOCK_SPI0CLK_HZ,                  /* Initial value of SPI0 Clock */
	BSP_CFG_CLOCK_SPI1CLK_HZ,                  /* Initial value of SPI1 Clock */
	BSP_CFG_CLOCK_SD0CLK_HZ,                   /* Initial value of SDH0 Clock */
	BSP_CFG_CLOCK_SD1CLK_HZ,                   /* Initial value of SDH1 Clock */
	BSP_CFG_CLOCK_M0CLK_HZ,                    /* Initial value of VCP, LCDC Clock */
	BSP_CFG_CLOCK_M1CLK_HZ,                    /* Initial value of MIPI-DSI, MIPI-CSI Clock */
	BSP_CFG_CLOCK_M2CLK_HZ,                    /* Initial value of CRU, MIPI-DSI Clock */
	BSP_CFG_CLOCK_M3CLK_HZ,                    /* Initial value of MIPI-DSI, LCDC Clock */
	BSP_CFG_CLOCK_M4CLK_HZ,                    /* Initial value of MIPI-DSI Clock */
	BSP_CFG_CLOCK_HPCLK_HZ,                    /* Initial value of Ethernet Clock */
	BSP_CFG_CLOCK_TSUCLK_HZ,                   /* Initial value of TSU Clock */
	BSP_CFG_CLOCK_ZTCLK_HZ,                    /* Initial value of JAUTH Clock */
	BSP_CFG_CLOCK_P0CLK_HZ,                    /* Initial value of APB-BUS Clock */
	BSP_CFG_CLOCK_P1CLK_HZ,                    /* Initial value of AXI-BUS Clock */
	BSP_CFG_CLOCK_P2CLK_HZ,                    /* Initial value of P2CLK */
	BSP_CFG_CLOCK_ATCLK_HZ,                    /* Initial value of ATCLK */
	BSP_CFG_CLOCK_OSCCLK_HZ,                   /* Initial value of OSC Clock */
};

/*******************************************************************************************************************//**
 * Update SystemCoreClock variable based on current clock settings.
 **********************************************************************************************************************/
void SystemCoreClockUpdate (void)
{
    SystemCoreClock = g_clock_freq[FSP_PRIV_CLOCK_I2CLK];
}

/*******************************************************************************************************************//**
 * Initializes variable to store system clock frequencies.
 **********************************************************************************************************************/
#if BSP_TZ_CFG_INIT_SECURE_ONLY
void bsp_clock_freq_var_init (void)
#else
static void bsp_clock_freq_var_init (void)
#endif
{
    g_clock_freq[FSP_PRIV_CLOCK_ICLK]       = BSP_CFG_CLOCK_ICLK_HZ;
    g_clock_freq[FSP_PRIV_CLOCK_I2CLK]      = BSP_CFG_CLOCK_I2CLK_HZ;
    g_clock_freq[FSP_PRIV_CLOCK_GCLK]       = BSP_CFG_CLOCK_GCLK_HZ;
    g_clock_freq[FSP_PRIV_CLOCK_S0CLK]      = BSP_CFG_CLOCK_S0CLK_HZ;
    g_clock_freq[FSP_PRIV_CLOCK_S1CLK]      = BSP_CFG_CLOCK_S1CLK_HZ;
    g_clock_freq[FSP_PRIV_CLOCK_SPI0CLK]    = BSP_CFG_CLOCK_SPI0CLK_HZ;
    g_clock_freq[FSP_PRIV_CLOCK_SPI1CLK]    = BSP_CFG_CLOCK_SPI1CLK_HZ;
    g_clock_freq[FSP_PRIV_CLOCK_SD0CLK]     = BSP_CFG_CLOCK_SD0CLK_HZ;
    g_clock_freq[FSP_PRIV_CLOCK_SD1CLK]     = BSP_CFG_CLOCK_SD1CLK_HZ;
    g_clock_freq[FSP_PRIV_CLOCK_M0CLK]      = BSP_CFG_CLOCK_M0CLK_HZ;
    g_clock_freq[FSP_PRIV_CLOCK_M1CLK]      = BSP_CFG_CLOCK_M1CLK_HZ;
    g_clock_freq[FSP_PRIV_CLOCK_M2CLK]      = BSP_CFG_CLOCK_M2CLK_HZ;
    g_clock_freq[FSP_PRIV_CLOCK_M3CLK]      = BSP_CFG_CLOCK_M3CLK_HZ;
    g_clock_freq[FSP_PRIV_CLOCK_M4CLK]      = BSP_CFG_CLOCK_M4CLK_HZ;
    g_clock_freq[FSP_PRIV_CLOCK_HPCLK]      = BSP_CFG_CLOCK_HPCLK_HZ;
    g_clock_freq[FSP_PRIV_CLOCK_TSUCLK]     = BSP_CFG_CLOCK_TSUCLK_HZ;
    g_clock_freq[FSP_PRIV_CLOCK_ZTCLK]      = BSP_CFG_CLOCK_ZTCLK_HZ;
    g_clock_freq[FSP_PRIV_CLOCK_P0CLK]      = BSP_CFG_CLOCK_P0CLK_HZ;
    g_clock_freq[FSP_PRIV_CLOCK_P1CLK]      = BSP_CFG_CLOCK_P1CLK_HZ;
    g_clock_freq[FSP_PRIV_CLOCK_P2CLK]      = BSP_CFG_CLOCK_P2CLK_HZ;
    g_clock_freq[FSP_PRIV_CLOCK_ATCLK]      = BSP_CFG_CLOCK_ATCLK_HZ;
    g_clock_freq[FSP_PRIV_CLOCK_OSCCLK]     = BSP_CFG_CLOCK_OSCCLK_HZ;

    /* The SystemCoreClock needs to be updated before calling R_BSP_SoftwareDelay. */
    SystemCoreClockUpdate();
}

/*******************************************************************************************************************//**
 * Initializes system clocks.  Makes no assumptions about current register settings.
 **********************************************************************************************************************/
void bsp_clock_init (void)
{
    bsp_clock_freq_var_init();
}

uint32_t R_FSP_SystemClockHzGet(fsp_priv_clock_t clock)
{
 	return(g_clock_freq[clock]);
}
 
/** @} (end addtogroup BSP_MCU_PRV) */
