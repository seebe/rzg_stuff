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

/*******************************************************************************************************************//**
 * @defgroup BSP_IO BSP I/O access
 * @ingroup RENESAS_COMMON
 * @brief This module provides basic read/write access to port pins.
 *
 * @{
 **********************************************************************************************************************/

#ifndef BSP_IO_H
#define BSP_IO_H

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/* Private definition to set enumeration values. */
#define BSP_IO_PRV_8BIT_MASK          (0xFF)
#define BSP_IO_PRV_PIN_MASK           (1U)
#define BSP_IO_PRV_PORT_OFFSET        (8U)
#define BSP_IO_PWPR_B0WI_OFFSET       (7U)
#define BSP_IO_PWPR_PFSWE_OFFSET      (6U)
#define BSP_IO_PM_PM_OUTPUT           (3U)

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** Levels that can be set and read for individual pins */
typedef enum e_bsp_io_level
{
    BSP_IO_LEVEL_LOW = 0,              ///< Low
    BSP_IO_LEVEL_HIGH                  ///< High
} bsp_io_level_t;

/** Direction of individual pins */
typedef enum e_bsp_io_dir
{
	BSP_IO_DIRECTION_HIZ = 0,                    ///< Hi-Z
    BSP_IO_DIRECTION_INPUT,                      ///< Input
    BSP_IO_DIRECTION_OUTPUT,                     ///< Output (Input disable)
    BSP_IO_DIRECTION_OUTPUT_WITH_INPUT_ENABLE    ///< Output (Input enable)
} bsp_io_direction_t;

/** Superset list of all possible IO ports. */
typedef enum e_bsp_io_port
{
    BSP_IO_PORT_00 = 0x0000,           ///< IO port 0
    BSP_IO_PORT_01 = 0x0100,           ///< IO port 1
    BSP_IO_PORT_02 = 0x0200,           ///< IO port 2
    BSP_IO_PORT_03 = 0x0300,           ///< IO port 3
    BSP_IO_PORT_04 = 0x0400,           ///< IO port 4
    BSP_IO_PORT_05 = 0x0500,           ///< IO port 5
    BSP_IO_PORT_06 = 0x0600,           ///< IO port 6
    BSP_IO_PORT_07 = 0x0700,           ///< IO port 7
    BSP_IO_PORT_08 = 0x0800,           ///< IO port 8
    BSP_IO_PORT_09 = 0x0900,           ///< IO port 9
    BSP_IO_PORT_10 = 0x0A00,           ///< IO port 10
    BSP_IO_PORT_11 = 0x0B00,           ///< IO port 11
    BSP_IO_PORT_12 = 0x0C00,           ///< IO port 12
    BSP_IO_PORT_13 = 0x0D00,           ///< IO port 13
    BSP_IO_PORT_14 = 0x0E00,           ///< IO port 14
    BSP_IO_PORT_15 = 0x0F00,           ///< IO port 15
    BSP_IO_PORT_16 = 0x1000,           ///< IO port 16
    BSP_IO_PORT_17 = 0x1100,           ///< IO port 17
    BSP_IO_PORT_18 = 0x1200,           ///< IO port 18
    BSP_IO_PORT_19 = 0x1300,           ///< IO port 19
    BSP_IO_PORT_20 = 0x1400,           ///< IO port 20
    BSP_IO_PORT_21 = 0x1500,           ///< IO port 21
    BSP_IO_PORT_22 = 0x1600,           ///< IO port 22
    BSP_IO_PORT_23 = 0x1700,           ///< IO port 23
    BSP_IO_PORT_24 = 0x1800,           ///< IO port 24
    BSP_IO_PORT_25 = 0x1900,           ///< IO port 25
    BSP_IO_PORT_26 = 0x1A00,           ///< IO port 26
    BSP_IO_PORT_27 = 0x1B00,           ///< IO port 27
    BSP_IO_PORT_28 = 0x1C00,           ///< IO port 28
    BSP_IO_PORT_29 = 0x1D00,           ///< IO port 29
    BSP_IO_PORT_30 = 0x1E00,           ///< IO port 30
    BSP_IO_PORT_31 = 0x1F00,           ///< IO port 31
    BSP_IO_PORT_32 = 0x2000,           ///< IO port 32
    BSP_IO_PORT_33 = 0x2100,           ///< IO port 33
    BSP_IO_PORT_34 = 0x2200,           ///< IO port 34
    BSP_IO_PORT_35 = 0x2300,           ///< IO port 35
    BSP_IO_PORT_36 = 0x2400,           ///< IO port 36
    BSP_IO_PORT_37 = 0x2500,           ///< IO port 37
    BSP_IO_PORT_38 = 0x2600,           ///< IO port 38
    BSP_IO_PORT_39 = 0x2700,           ///< IO port 39
    BSP_IO_PORT_40 = 0x2800,           ///< IO port 40
    BSP_IO_PORT_41 = 0x2900,           ///< IO port 41
    BSP_IO_PORT_42 = 0x2A00,           ///< IO port 42
    BSP_IO_PORT_43 = 0x2B00,           ///< IO port 43
    BSP_IO_PORT_44 = 0x2C00,           ///< IO port 44
    BSP_IO_PORT_45 = 0x2D00,           ///< IO port 45
    BSP_IO_PORT_46 = 0x2E00,           ///< IO port 46
    BSP_IO_PORT_47 = 0x2F00,           ///< IO port 47
    BSP_IO_PORT_48 = 0x3000,           ///< IO port 48
} bsp_io_port_t;

/** Superset list of all possible IO port pins. */
typedef enum e_bsp_io_port_pin_t
{
    BSP_IO_PORT_00_PIN_00 = 0x0000,    ///< IO port 0 pin 0
    BSP_IO_PORT_00_PIN_01 = 0x0001,    ///< IO port 0 pin 1

    BSP_IO_PORT_01_PIN_00 = 0x0100,    ///< IO port 1 pin 0
    BSP_IO_PORT_01_PIN_01 = 0x0101,    ///< IO port 1 pin 1

    BSP_IO_PORT_02_PIN_00 = 0x0200,    ///< IO port 2 pin 0
    BSP_IO_PORT_02_PIN_01 = 0x0201,    ///< IO port 2 pin 1

    BSP_IO_PORT_03_PIN_00 = 0x0300,    ///< IO port 3 pin 0
    BSP_IO_PORT_03_PIN_01 = 0x0301,    ///< IO port 3 pin 1

    BSP_IO_PORT_04_PIN_00 = 0x0400,    ///< IO port 4 pin 0
    BSP_IO_PORT_04_PIN_01 = 0x0401,    ///< IO port 4 pin 1

    BSP_IO_PORT_05_PIN_00 = 0x0500,    ///< IO port 5 pin 0
    BSP_IO_PORT_05_PIN_01 = 0x0501,    ///< IO port 5 pin 1
    BSP_IO_PORT_05_PIN_02 = 0x0502,    ///< IO port 5 pin 2

    BSP_IO_PORT_06_PIN_00 = 0x0600,    ///< IO port 6 pin 0
    BSP_IO_PORT_06_PIN_01 = 0x0601,    ///< IO port 6 pin 1

    BSP_IO_PORT_07_PIN_00 = 0x0700,    ///< IO port 7 pin 0
    BSP_IO_PORT_07_PIN_01 = 0x0701,    ///< IO port 7 pin 1
    BSP_IO_PORT_07_PIN_02 = 0x0702,    ///< IO port 7 pin 2

    BSP_IO_PORT_08_PIN_00 = 0x0800,    ///< IO port 8 pin 0
    BSP_IO_PORT_08_PIN_01 = 0x0801,    ///< IO port 8 pin 1
    BSP_IO_PORT_08_PIN_02 = 0x0802,    ///< IO port 8 pin 2

    BSP_IO_PORT_09_PIN_00 = 0x0900,    ///< IO port 9 pin 0
    BSP_IO_PORT_09_PIN_01 = 0x0901,    ///< IO port 9 pin 1

    BSP_IO_PORT_10_PIN_00 = 0x0A00,    ///< IO port 10 pin 0
    BSP_IO_PORT_10_PIN_01 = 0x0A01,    ///< IO port 10 pin 1

    BSP_IO_PORT_11_PIN_00 = 0x0B00,    ///< IO port 11 pin 0
    BSP_IO_PORT_11_PIN_01 = 0x0B01,    ///< IO port 11 pin 1

    BSP_IO_PORT_12_PIN_00 = 0x0C00,    ///< IO port 12 pin 0
    BSP_IO_PORT_12_PIN_01 = 0x0C01,    ///< IO port 12 pin 1

    BSP_IO_PORT_13_PIN_00 = 0x0D00,    ///< IO port 13 pin 0
    BSP_IO_PORT_13_PIN_01 = 0x0D01,    ///< IO port 13 pin 1
    BSP_IO_PORT_13_PIN_02 = 0x0D02,    ///< IO port 13 pin 2

    BSP_IO_PORT_14_PIN_00 = 0x0E00,    ///< IO port 14 pin 0
    BSP_IO_PORT_14_PIN_01 = 0x0E01,    ///< IO port 14 pin 1

    BSP_IO_PORT_15_PIN_00 = 0x0F00,    ///< IO port 15 pin 0
    BSP_IO_PORT_15_PIN_01 = 0x0F01,    ///< IO port 15 pin 1

    BSP_IO_PORT_16_PIN_00 = 0x1000,    ///< IO port 16 pin 0
    BSP_IO_PORT_16_PIN_01 = 0x1001,    ///< IO port 16 pin 1

    BSP_IO_PORT_17_PIN_00 = 0x1100,    ///< IO port 17 pin 0
    BSP_IO_PORT_17_PIN_01 = 0x1101,    ///< IO port 17 pin 1
    BSP_IO_PORT_17_PIN_02 = 0x1102,    ///< IO port 17 pin 2

    BSP_IO_PORT_18_PIN_00 = 0x1200,    ///< IO port 18 pin 0
    BSP_IO_PORT_18_PIN_01 = 0x1201,    ///< IO port 18 pin 1

    BSP_IO_PORT_19_PIN_00 = 0x1300,    ///< IO port 19 pin 0
    BSP_IO_PORT_19_PIN_01 = 0x1301,    ///< IO port 19 pin 1

    BSP_IO_PORT_20_PIN_00 = 0x1400,    ///< IO port 20 pin 0
    BSP_IO_PORT_20_PIN_01 = 0x1401,    ///< IO port 20 pin 1
    BSP_IO_PORT_20_PIN_02 = 0x1402,    ///< IO port 20 pin 2

    BSP_IO_PORT_21_PIN_00 = 0x1500,    ///< IO port 21 pin 0
    BSP_IO_PORT_21_PIN_01 = 0x1501,    ///< IO port 21 pin 1

    BSP_IO_PORT_22_PIN_00 = 0x1600,    ///< IO port 22 pin 0
    BSP_IO_PORT_22_PIN_01 = 0x1601,    ///< IO port 22 pin 1

    BSP_IO_PORT_23_PIN_00 = 0x1700,    ///< IO port 23 pin 0
    BSP_IO_PORT_23_PIN_01 = 0x1701,    ///< IO port 23 pin 1

    BSP_IO_PORT_24_PIN_00 = 0x1800,    ///< IO port 24 pin 0
    BSP_IO_PORT_24_PIN_01 = 0x1801,    ///< IO port 24 pin 1

    BSP_IO_PORT_25_PIN_00 = 0x1900,    ///< IO port 25 pin 0
    BSP_IO_PORT_25_PIN_01 = 0x1901,    ///< IO port 25 pin 1

    BSP_IO_PORT_26_PIN_00 = 0x1A00,    ///< IO port 26 pin 0
    BSP_IO_PORT_26_PIN_01 = 0x1A01,    ///< IO port 26 pin 1

    BSP_IO_PORT_27_PIN_00 = 0x1B00,    ///< IO port 27 pin 0
    BSP_IO_PORT_27_PIN_01 = 0x1B01,    ///< IO port 27 pin 1

    BSP_IO_PORT_28_PIN_00 = 0x1C00,    ///< IO port 28 pin 0
    BSP_IO_PORT_28_PIN_01 = 0x1C01,    ///< IO port 28 pin 1

    BSP_IO_PORT_29_PIN_00 = 0x1D00,    ///< IO port 29 pin 0
    BSP_IO_PORT_29_PIN_01 = 0x1D01,    ///< IO port 29 pin 1

    BSP_IO_PORT_30_PIN_00 = 0x1E00,    ///< IO port 30 pin 0
    BSP_IO_PORT_30_PIN_01 = 0x1E01,    ///< IO port 30 pin 1

    BSP_IO_PORT_31_PIN_00 = 0x1F00,    ///< IO port 31 pin 0
    BSP_IO_PORT_31_PIN_01 = 0x1F01,    ///< IO port 31 pin 1

    BSP_IO_PORT_32_PIN_00 = 0x2000,    ///< IO port 32 pin 0
    BSP_IO_PORT_32_PIN_01 = 0x2001,    ///< IO port 32 pin 1

    BSP_IO_PORT_33_PIN_00 = 0x2100,    ///< IO port 33 pin 0
    BSP_IO_PORT_33_PIN_01 = 0x2101,    ///< IO port 33 pin 1

    BSP_IO_PORT_34_PIN_00 = 0x2200,    ///< IO port 34 pin 0
    BSP_IO_PORT_34_PIN_01 = 0x2201,    ///< IO port 34 pin 1

    BSP_IO_PORT_35_PIN_00 = 0x2300,    ///< IO port 35 pin 0
    BSP_IO_PORT_35_PIN_01 = 0x2301,    ///< IO port 35 pin 1

    BSP_IO_PORT_36_PIN_00 = 0x2400,    ///< IO port 36 pin 0
    BSP_IO_PORT_36_PIN_01 = 0x2401,    ///< IO port 36 pin 1

    BSP_IO_PORT_37_PIN_00 = 0x2500,    ///< IO port 37 pin 0
    BSP_IO_PORT_37_PIN_01 = 0x2501,    ///< IO port 37 pin 1
    BSP_IO_PORT_37_PIN_02 = 0x2502,    ///< IO port 37 pin 2

    BSP_IO_PORT_38_PIN_00 = 0x2600,    ///< IO port 38 pin 0
    BSP_IO_PORT_38_PIN_01 = 0x2601,    ///< IO port 38 pin 1

    BSP_IO_PORT_39_PIN_00 = 0x2700,    ///< IO port 39 pin 0
    BSP_IO_PORT_39_PIN_01 = 0x2701,    ///< IO port 39 pin 1
    BSP_IO_PORT_39_PIN_02 = 0x2702,    ///< IO port 39 pin 2

    BSP_IO_PORT_40_PIN_00 = 0x2800,    ///< IO port 40 pin 0
    BSP_IO_PORT_40_PIN_01 = 0x2801,    ///< IO port 40 pin 1
    BSP_IO_PORT_40_PIN_02 = 0x2802,    ///< IO port 40 pin 2

    BSP_IO_PORT_41_PIN_00 = 0x2900,    ///< IO port 41 pin 0
    BSP_IO_PORT_41_PIN_01 = 0x2901,    ///< IO port 41 pin 1

    BSP_IO_PORT_42_PIN_00 = 0x2A00,    ///< IO port 42 pin 0
    BSP_IO_PORT_42_PIN_01 = 0x2A01,    ///< IO port 42 pin 1
    BSP_IO_PORT_42_PIN_02 = 0x2A02,    ///< IO port 42 pin 2
    BSP_IO_PORT_42_PIN_03 = 0x2A03,    ///< IO port 42 pin 3
    BSP_IO_PORT_42_PIN_04 = 0x2A04,    ///< IO port 42 pin 4

    BSP_IO_PORT_43_PIN_00 = 0x2B00,    ///< IO port 43 pin 0
    BSP_IO_PORT_43_PIN_01 = 0x2B01,    ///< IO port 43 pin 1
    BSP_IO_PORT_43_PIN_02 = 0x2B02,    ///< IO port 43 pin 2
    BSP_IO_PORT_43_PIN_03 = 0x2B03,    ///< IO port 43 pin 3

    BSP_IO_PORT_44_PIN_00 = 0x2C00,    ///< IO port 44 pin 0
    BSP_IO_PORT_44_PIN_01 = 0x2C01,    ///< IO port 44 pin 1
    BSP_IO_PORT_44_PIN_02 = 0x2C02,    ///< IO port 44 pin 2
    BSP_IO_PORT_44_PIN_03 = 0x2C03,    ///< IO port 44 pin 3

    BSP_IO_PORT_45_PIN_00 = 0x2D00,    ///< IO port 45 pin 0
    BSP_IO_PORT_45_PIN_01 = 0x2D01,    ///< IO port 45 pin 1
    BSP_IO_PORT_45_PIN_02 = 0x2D02,    ///< IO port 45 pin 2
    BSP_IO_PORT_45_PIN_03 = 0x2D03,    ///< IO port 45 pin 3

    BSP_IO_PORT_46_PIN_00 = 0x2E00,    ///< IO port 46 pin 0
    BSP_IO_PORT_46_PIN_01 = 0x2E01,    ///< IO port 46 pin 1
    BSP_IO_PORT_46_PIN_02 = 0x2E02,    ///< IO port 46 pin 2
    BSP_IO_PORT_46_PIN_03 = 0x2E03,    ///< IO port 46 pin 3

    BSP_IO_PORT_47_PIN_00 = 0x2F00,    ///< IO port 47 pin 0
    BSP_IO_PORT_47_PIN_01 = 0x2F01,    ///< IO port 47 pin 1
    BSP_IO_PORT_47_PIN_02 = 0x2F02,    ///< IO port 47 pin 2
    BSP_IO_PORT_47_PIN_03 = 0x2F03,    ///< IO port 47 pin 3

    BSP_IO_PORT_48_PIN_00 = 0x3000,    ///< IO port 48 pin 0
    BSP_IO_PORT_48_PIN_01 = 0x3001,    ///< IO port 48 pin 1
    BSP_IO_PORT_48_PIN_02 = 0x3002,    ///< IO port 48 pin 2
    BSP_IO_PORT_48_PIN_03 = 0x3003,    ///< IO port 48 pin 3
    BSP_IO_PORT_48_PIN_04 = 0x3004,    ///< IO port 48 pin 4
} bsp_io_port_pin_t;

/***********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/
extern volatile uint32_t g_protect_pfswe_counter;

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Read the current input level of the pin.
 *
 * @param[in]  pin             The pin
 *
 * @retval     Current input level
 **********************************************************************************************************************/
__STATIC_INLINE uint32_t R_BSP_PinRead (bsp_io_port_pin_t pin)
{
    /* Read pin level. */
#if 0 /* polite description */
    //volatile const uint8_t *p_pin;
    //p_pin = &R_PORT->PIN[0].BYTE;
    //p_pin = &p_pin[pin >> BSP_IO_PRV_PORT_OFFSET];
    //return (uint32_t) (*p_pin >> (pin & BSP_IO_PRV_8BIT_MASK)) & BSP_IO_PRV_PIN_MASK;
#else /* condensed description */
	return (uint32_t) ((&R_PORT->PIN[0].BYTE)[pin >> BSP_IO_PRV_PORT_OFFSET] >> (pin & BSP_IO_PRV_8BIT_MASK)) & BSP_IO_PRV_PIN_MASK;
#endif
}

/*******************************************************************************************************************//**
 * Set a pin to output and set the output level to the level provided
 *
 * @param[in]  pin      The pin
 * @param[in]  level    The level
 **********************************************************************************************************************/
__STATIC_INLINE void R_BSP_PinWrite (bsp_io_port_pin_t pin, bsp_io_level_t level)
{
    /* Set output level and pin direction to output. */
    uint32_t lvl = (uint32_t) level;
#if 0 /* polite description */
    volatile uint16_t *p_pm;
    volatile uint8_t *p_p;
    p_pm = &R_PORT->PM[0].WORD;
    p_p = &R_PORT->P[0].BYTE;
    p_pm[pin >> BSP_IO_PRV_PORT_OFFSET] = ((p_pm[pin >> BSP_IO_PRV_PORT_OFFSET] & (uint16_t) (~(BSP_IO_PM_PM_OUTPUT << ((pin & BSP_IO_PRV_8BIT_MASK) * 2)))) | (uint16_t) (BSP_IO_PM_PM_OUTPUT << ((pin & BSP_IO_PRV_8BIT_MASK) * 2)));
    p_p[pin >> BSP_IO_PRV_PORT_OFFSET] = ((p_p[pin >> BSP_IO_PRV_PORT_OFFSET] & (uint8_t) (~(1 << (pin & BSP_IO_PRV_8BIT_MASK)))) | (uint8_t) (lvl << (pin & BSP_IO_PRV_8BIT_MASK)));
#else /* condensed description */
    (&R_PORT->PM[0].WORD)[pin >> BSP_IO_PRV_PORT_OFFSET] = (((&R_PORT->PM[0].WORD)[pin >> BSP_IO_PRV_PORT_OFFSET] & (uint16_t) (~(BSP_IO_PM_PM_OUTPUT << ((pin & BSP_IO_PRV_8BIT_MASK) * 2)))) | (uint16_t) (BSP_IO_PM_PM_OUTPUT << ((pin & BSP_IO_PRV_8BIT_MASK) * 2)));
    (&R_PORT->P[0].BYTE)[pin >> BSP_IO_PRV_PORT_OFFSET] = (((&R_PORT->P[0].BYTE)[pin >> BSP_IO_PRV_PORT_OFFSET] & (uint8_t) (~(1 << (pin & BSP_IO_PRV_8BIT_MASK)))) | (uint8_t) (lvl << (pin & BSP_IO_PRV_8BIT_MASK)));
#endif
}

/*******************************************************************************************************************//**
 * Enable access to the PFS registers. Uses a reference counter to protect against interrupts that could occur
 * via multiple threads or an ISR re-entering this code.
 **********************************************************************************************************************/
__STATIC_INLINE void R_BSP_PinAccessEnable (void)
{
#if BSP_CFG_PFS_PROTECT
    /** Get the current state of interrupts */
    FSP_CRITICAL_SECTION_DEFINE;
    FSP_CRITICAL_SECTION_ENTER;

    /** If this is first entry then allow writing of PFS. */
    if (0 == g_protect_pfswe_counter)
    {
 #if BSP_TZ_SECURE_BUILD
        //R_PMISC->PWPRS = 0;                              ///< Clear BOWI bit - writing to PFSWE bit enabled
        //R_PMISC->PWPRS = 1U << BSP_IO_PWPR_PFSWE_OFFSET; ///< Set PFSWE bit - writing to PFS register enabled
        R_GPIO->PWPR.DWORD = 0;                              ///< Clear BOWI bit - writing to PFSWE bit enabled
        R_GPIO->PWPR.DWORD = 1U << BSP_IO_PWPR_PFSWE_OFFSET; ///< Set PFSWE bit - writing to PFS register enabled
 #else
        R_GPIO->PWPR.DWORD = 0;                              ///< Clear BOWI bit - writing to PFSWE bit enabled
        R_GPIO->PWPR.DWORD = 1U << BSP_IO_PWPR_PFSWE_OFFSET; ///< Set PFSWE bit - writing to PFS register enabled
 #endif
    }

    /** Increment the protect counter */
    g_protect_pfswe_counter++;

    /** Restore the interrupt state */
    FSP_CRITICAL_SECTION_EXIT;
#endif
}

/*******************************************************************************************************************//**
 * Disable access to the PFS registers. Uses a reference counter to protect against interrupts that could occur via
 * multiple threads or an ISR re-entering this code.
 **********************************************************************************************************************/
__STATIC_INLINE void R_BSP_PinAccessDisable (void)
{
#if BSP_CFG_PFS_PROTECT

    /** Get the current state of interrupts */
    FSP_CRITICAL_SECTION_DEFINE;
    FSP_CRITICAL_SECTION_ENTER;

    /** Is it safe to disable PFS register? */
    if (0 != g_protect_pfswe_counter)
    {
        /* Decrement the protect counter */
        g_protect_pfswe_counter--;
    }

    /** Is it safe to disable writing of PFS? */
    if (0 == g_protect_pfswe_counter)
    {
 #if BSP_TZ_SECURE_BUILD
        //R_PMISC->PWPRS = 0;                             ///< Clear PFSWE bit - writing to PFSWE bit enabled
        //R_PMISC->PWPRS = 1U << BSP_IO_PWPR_B0WI_OFFSET; ///< Set BOWI bit - writing to PFS register enabled
        R_GPIO->PWPR.DWORD = 0;                             ///< Clear PFSWE bit - writing to PFS register disabled
        R_GPIO->PWPR.DWORD = 1U << BSP_IO_PWPR_B0WI_OFFSET; ///< Set BOWI bit - writing to PFSWE bit disabled
 #else
        R_GPIO->PWPR.DWORD = 0;                             ///< Clear PFSWE bit - writing to PFS register disabled
        R_GPIO->PWPR.DWORD = 1U << BSP_IO_PWPR_B0WI_OFFSET; ///< Set BOWI bit - writing to PFSWE bit disabled
 #endif
    }

    /** Restore the interrupt state */
    FSP_CRITICAL_SECTION_EXIT;
#endif
}

/** @} (end addtogroup BSP_IO) */

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif
