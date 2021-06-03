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
 * @addtogroup IOPORT
 * @{
 **********************************************************************************************************************/

#ifndef R_IOPORT_H
#define R_IOPORT_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "bsp_api.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

#include "r_ioport_api.h"
#include "r_ioport_cfg.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/
#define IOPORT_CODE_VERSION_MAJOR    (0U)
#define IOPORT_CODE_VERSION_MINOR    (1U)

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** IOPORT private control block. DO NOT MODIFY. Initialization occurs when R_IOPORT_Open() is called. */
typedef struct st_ioport_instance_ctrl
{
    uint32_t     open;
    void const * p_context;
} ioport_instance_ctrl_t;

/* This typedef is here temporarily. See SWFLEX-144 for details. */
/** Superset list of all possible IO port pins. */
typedef enum e_ioport_port_pin_t
{
    IOPORT_PORT_00_PIN_00 = 0x0000,    ///< IO port 0 pin 0
    IOPORT_PORT_00_PIN_01 = 0x0001,    ///< IO port 0 pin 1

    IOPORT_PORT_01_PIN_00 = 0x0100,    ///< IO port 1 pin 0
    IOPORT_PORT_01_PIN_01 = 0x0101,    ///< IO port 1 pin 1

    IOPORT_PORT_02_PIN_00 = 0x0200,    ///< IO port 2 pin 0
    IOPORT_PORT_02_PIN_01 = 0x0201,    ///< IO port 2 pin 1

    IOPORT_PORT_03_PIN_00 = 0x0300,    ///< IO port 3 pin 0
    IOPORT_PORT_03_PIN_01 = 0x0301,    ///< IO port 3 pin 1

    IOPORT_PORT_04_PIN_00 = 0x0400,    ///< IO port 4 pin 0
    IOPORT_PORT_04_PIN_01 = 0x0401,    ///< IO port 4 pin 1

    IOPORT_PORT_05_PIN_00 = 0x0500,    ///< IO port 5 pin 0
    IOPORT_PORT_05_PIN_01 = 0x0501,    ///< IO port 5 pin 1
    IOPORT_PORT_05_PIN_02 = 0x0502,    ///< IO port 5 pin 2

    IOPORT_PORT_06_PIN_00 = 0x0600,    ///< IO port 6 pin 0
    IOPORT_PORT_06_PIN_01 = 0x0601,    ///< IO port 6 pin 1

    IOPORT_PORT_07_PIN_00 = 0x0700,    ///< IO port 7 pin 0
    IOPORT_PORT_07_PIN_01 = 0x0701,    ///< IO port 7 pin 1
    IOPORT_PORT_07_PIN_02 = 0x0702,    ///< IO port 7 pin 2

    IOPORT_PORT_08_PIN_00 = 0x0800,    ///< IO port 8 pin 0
    IOPORT_PORT_08_PIN_01 = 0x0801,    ///< IO port 8 pin 1
    IOPORT_PORT_08_PIN_02 = 0x0802,    ///< IO port 8 pin 2

    IOPORT_PORT_09_PIN_00 = 0x0900,    ///< IO port 9 pin 0
    IOPORT_PORT_09_PIN_01 = 0x0901,    ///< IO port 9 pin 1

    IOPORT_PORT_10_PIN_00 = 0x0A00,    ///< IO port 10 pin 0
    IOPORT_PORT_10_PIN_01 = 0x0A01,    ///< IO port 10 pin 1

    IOPORT_PORT_11_PIN_00 = 0x0B00,    ///< IO port 11 pin 0
    IOPORT_PORT_11_PIN_01 = 0x0B01,    ///< IO port 11 pin 1

    IOPORT_PORT_12_PIN_00 = 0x0C00,    ///< IO port 12 pin 0
    IOPORT_PORT_12_PIN_01 = 0x0C01,    ///< IO port 12 pin 1

    IOPORT_PORT_13_PIN_00 = 0x0D00,    ///< IO port 13 pin 0
    IOPORT_PORT_13_PIN_01 = 0x0D01,    ///< IO port 13 pin 1
    IOPORT_PORT_13_PIN_02 = 0x0D02,    ///< IO port 13 pin 2

    IOPORT_PORT_14_PIN_00 = 0x0E00,    ///< IO port 14 pin 0
    IOPORT_PORT_14_PIN_01 = 0x0E01,    ///< IO port 14 pin 1

    IOPORT_PORT_15_PIN_00 = 0x0F00,    ///< IO port 15 pin 0
    IOPORT_PORT_15_PIN_01 = 0x0F01,    ///< IO port 15 pin 1

    IOPORT_PORT_16_PIN_00 = 0x1000,    ///< IO port 16 pin 0
    IOPORT_PORT_16_PIN_01 = 0x1001,    ///< IO port 16 pin 1

    IOPORT_PORT_17_PIN_00 = 0x1100,    ///< IO port 17 pin 0
    IOPORT_PORT_17_PIN_01 = 0x1101,    ///< IO port 17 pin 1
    IOPORT_PORT_17_PIN_02 = 0x1102,    ///< IO port 17 pin 2

    IOPORT_PORT_18_PIN_00 = 0x1200,    ///< IO port 18 pin 0
    IOPORT_PORT_18_PIN_01 = 0x1201,    ///< IO port 18 pin 1

    IOPORT_PORT_19_PIN_00 = 0x1300,    ///< IO port 19 pin 0
    IOPORT_PORT_19_PIN_01 = 0x1301,    ///< IO port 19 pin 1

    IOPORT_PORT_20_PIN_00 = 0x1400,    ///< IO port 20 pin 0
    IOPORT_PORT_20_PIN_01 = 0x1401,    ///< IO port 20 pin 1
    IOPORT_PORT_20_PIN_02 = 0x1402,    ///< IO port 20 pin 2

    IOPORT_PORT_21_PIN_00 = 0x1500,    ///< IO port 21 pin 0
    IOPORT_PORT_21_PIN_01 = 0x1501,    ///< IO port 21 pin 1

    IOPORT_PORT_22_PIN_00 = 0x1600,    ///< IO port 22 pin 0
    IOPORT_PORT_22_PIN_01 = 0x1601,    ///< IO port 22 pin 1

    IOPORT_PORT_23_PIN_00 = 0x1700,    ///< IO port 23 pin 0
    IOPORT_PORT_23_PIN_01 = 0x1701,    ///< IO port 23 pin 1

    IOPORT_PORT_24_PIN_00 = 0x1800,    ///< IO port 24 pin 0
    IOPORT_PORT_24_PIN_01 = 0x1801,    ///< IO port 24 pin 1

    IOPORT_PORT_25_PIN_00 = 0x1900,    ///< IO port 25 pin 0
    IOPORT_PORT_25_PIN_01 = 0x1901,    ///< IO port 25 pin 1

    IOPORT_PORT_26_PIN_00 = 0x1A00,    ///< IO port 26 pin 0
    IOPORT_PORT_26_PIN_01 = 0x1A01,    ///< IO port 26 pin 1

    IOPORT_PORT_27_PIN_00 = 0x1B00,    ///< IO port 27 pin 0
    IOPORT_PORT_27_PIN_01 = 0x1B01,    ///< IO port 27 pin 1

    IOPORT_PORT_28_PIN_00 = 0x1C00,    ///< IO port 28 pin 0
    IOPORT_PORT_28_PIN_01 = 0x1C01,    ///< IO port 28 pin 1

    IOPORT_PORT_29_PIN_00 = 0x1D00,    ///< IO port 29 pin 0
    IOPORT_PORT_29_PIN_01 = 0x1D01,    ///< IO port 29 pin 1

    IOPORT_PORT_30_PIN_00 = 0x1E00,    ///< IO port 30 pin 0
    IOPORT_PORT_30_PIN_01 = 0x1E01,    ///< IO port 30 pin 1

    IOPORT_PORT_31_PIN_00 = 0x1F00,    ///< IO port 31 pin 0
    IOPORT_PORT_31_PIN_01 = 0x1F01,    ///< IO port 31 pin 1

    IOPORT_PORT_32_PIN_00 = 0x2000,    ///< IO port 32 pin 0
    IOPORT_PORT_32_PIN_01 = 0x2001,    ///< IO port 32 pin 1

    IOPORT_PORT_33_PIN_00 = 0x2100,    ///< IO port 33 pin 0
    IOPORT_PORT_33_PIN_01 = 0x2101,    ///< IO port 33 pin 1

    IOPORT_PORT_34_PIN_00 = 0x2200,    ///< IO port 34 pin 0
    IOPORT_PORT_34_PIN_01 = 0x2201,    ///< IO port 34 pin 1

    IOPORT_PORT_35_PIN_00 = 0x2300,    ///< IO port 35 pin 0
    IOPORT_PORT_35_PIN_01 = 0x2301,    ///< IO port 35 pin 1

    IOPORT_PORT_36_PIN_00 = 0x2400,    ///< IO port 36 pin 0
    IOPORT_PORT_36_PIN_01 = 0x2401,    ///< IO port 36 pin 1

    IOPORT_PORT_37_PIN_00 = 0x2500,    ///< IO port 37 pin 0
    IOPORT_PORT_37_PIN_01 = 0x2501,    ///< IO port 37 pin 1
    IOPORT_PORT_37_PIN_02 = 0x2502,    ///< IO port 37 pin 2

    IOPORT_PORT_38_PIN_00 = 0x2600,    ///< IO port 38 pin 0
    IOPORT_PORT_38_PIN_01 = 0x2601,    ///< IO port 38 pin 1

    IOPORT_PORT_39_PIN_00 = 0x2700,    ///< IO port 39 pin 0
    IOPORT_PORT_39_PIN_01 = 0x2701,    ///< IO port 39 pin 1
    IOPORT_PORT_39_PIN_02 = 0x2702,    ///< IO port 39 pin 2

    IOPORT_PORT_40_PIN_00 = 0x2800,    ///< IO port 40 pin 0
    IOPORT_PORT_40_PIN_01 = 0x2801,    ///< IO port 40 pin 1
    IOPORT_PORT_40_PIN_02 = 0x2802,    ///< IO port 40 pin 2

    IOPORT_PORT_41_PIN_00 = 0x2900,    ///< IO port 41 pin 0
    IOPORT_PORT_41_PIN_01 = 0x2901,    ///< IO port 41 pin 1

    IOPORT_PORT_42_PIN_00 = 0x2A00,    ///< IO port 42 pin 0
    IOPORT_PORT_42_PIN_01 = 0x2A01,    ///< IO port 42 pin 1
    IOPORT_PORT_42_PIN_02 = 0x2A02,    ///< IO port 42 pin 2
    IOPORT_PORT_42_PIN_03 = 0x2A03,    ///< IO port 42 pin 3
    IOPORT_PORT_42_PIN_04 = 0x2A04,    ///< IO port 42 pin 4

    IOPORT_PORT_43_PIN_00 = 0x2B00,    ///< IO port 43 pin 0
    IOPORT_PORT_43_PIN_01 = 0x2B01,    ///< IO port 43 pin 1
    IOPORT_PORT_43_PIN_02 = 0x2B02,    ///< IO port 43 pin 2
    IOPORT_PORT_43_PIN_03 = 0x2B03,    ///< IO port 43 pin 3

    IOPORT_PORT_44_PIN_00 = 0x2C00,    ///< IO port 44 pin 0
    IOPORT_PORT_44_PIN_01 = 0x2C01,    ///< IO port 44 pin 1
    IOPORT_PORT_44_PIN_02 = 0x2C02,    ///< IO port 44 pin 2
    IOPORT_PORT_44_PIN_03 = 0x2C03,    ///< IO port 44 pin 3

    IOPORT_PORT_45_PIN_00 = 0x2D00,    ///< IO port 45 pin 0
    IOPORT_PORT_45_PIN_01 = 0x2D01,    ///< IO port 45 pin 1
    IOPORT_PORT_45_PIN_02 = 0x2D02,    ///< IO port 45 pin 2
    IOPORT_PORT_45_PIN_03 = 0x2D03,    ///< IO port 45 pin 3

    IOPORT_PORT_46_PIN_00 = 0x2E00,    ///< IO port 46 pin 0
    IOPORT_PORT_46_PIN_01 = 0x2E01,    ///< IO port 46 pin 1
    IOPORT_PORT_46_PIN_02 = 0x2E02,    ///< IO port 46 pin 2
    IOPORT_PORT_46_PIN_03 = 0x2E03,    ///< IO port 46 pin 3

    IOPORT_PORT_47_PIN_00 = 0x2F00,    ///< IO port 47 pin 0
    IOPORT_PORT_47_PIN_01 = 0x2F01,    ///< IO port 47 pin 1
    IOPORT_PORT_47_PIN_02 = 0x2F02,    ///< IO port 47 pin 2
    IOPORT_PORT_47_PIN_03 = 0x2F03,    ///< IO port 47 pin 3

    IOPORT_PORT_48_PIN_00 = 0x3000,    ///< IO port 48 pin 0
    IOPORT_PORT_48_PIN_01 = 0x3001,    ///< IO port 48 pin 1
    IOPORT_PORT_48_PIN_02 = 0x3002,    ///< IO port 48 pin 2
    IOPORT_PORT_48_PIN_03 = 0x3003,    ///< IO port 48 pin 3
    IOPORT_PORT_48_PIN_04 = 0x3004,    ///< IO port 48 pin 4
} ioport_port_pin_t;

/**********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/** @cond INC_HEADER_DEFS_SEC */
/** Filled in Interface API structure for this Instance. */
extern const ioport_api_t g_ioport_on_ioport;

/** @endcond */

/***********************************************************************************************************************
 * Public APIs
 **********************************************************************************************************************/

fsp_err_t R_IOPORT_Open(ioport_ctrl_t * const p_ctrl, const ioport_cfg_t * p_cfg);
fsp_err_t R_IOPORT_Close(ioport_ctrl_t * const p_ctrl);
fsp_err_t R_IOPORT_PinsCfg(ioport_ctrl_t * const p_ctrl, const ioport_cfg_t * p_cfg);
fsp_err_t R_IOPORT_PinCfg(ioport_ctrl_t * const p_ctrl, bsp_io_port_pin_t pin, uint32_t cfg);
fsp_err_t R_IOPORT_PinEventInputRead(ioport_ctrl_t * const p_ctrl, bsp_io_port_pin_t pin, bsp_io_level_t * p_pin_event);
fsp_err_t R_IOPORT_PinEventOutputWrite(ioport_ctrl_t * const p_ctrl, bsp_io_port_pin_t pin, bsp_io_level_t pin_value);
fsp_err_t R_IOPORT_PinRead(ioport_ctrl_t * const p_ctrl, bsp_io_port_pin_t pin, bsp_io_level_t * p_pin_value);
fsp_err_t R_IOPORT_PinWrite(ioport_ctrl_t * const p_ctrl, bsp_io_port_pin_t pin, bsp_io_level_t level);
fsp_err_t R_IOPORT_PortDirectionSet(ioport_ctrl_t * const p_ctrl,
                                    bsp_io_port_t         port,
                                    ioport_size_t         direction_values,
                                    ioport_size_t         mask);
fsp_err_t R_IOPORT_PortEventInputRead(ioport_ctrl_t * const p_ctrl, bsp_io_port_t port, ioport_size_t * event_data);
fsp_err_t R_IOPORT_PortEventOutputWrite(ioport_ctrl_t * const p_ctrl,
                                        bsp_io_port_t         port,
                                        ioport_size_t         event_data,
                                        ioport_size_t         mask_value);
fsp_err_t R_IOPORT_PortRead(ioport_ctrl_t * const p_ctrl, bsp_io_port_t port, ioport_size_t * p_port_value);
fsp_err_t R_IOPORT_PortWrite(ioport_ctrl_t * const p_ctrl, bsp_io_port_t port, ioport_size_t value, ioport_size_t mask);
fsp_err_t R_IOPORT_EthernetModeCfg(ioport_ctrl_t * const     p_ctrl,
                                   ioport_ethernet_channel_t channel,
                                   ioport_ethernet_mode_t    mode);
fsp_err_t R_IOPORT_VersionGet(fsp_version_t * p_data);

/*******************************************************************************************************************//**
 * @} (end defgroup IOPORT)
 **********************************************************************************************************************/

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif                                 // R_IOPORT_H
