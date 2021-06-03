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

#ifndef FSP_FEATURES_H
#define FSP_FEATURES_H

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/

/* C99 includes. */
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <assert.h>

/* Different compiler support. */
#include "fsp_common_api.h"
#include "../../fsp/src/bsp/mcu/all/bsp_compiler_support.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * @addtogroup BSP_MCU
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** Bus slave unit. */
typedef enum e_fsp_ip
{
    FSP_IP_MXSRAM_A     = 0,   ///< 
    FSP_IP_MXSRAM_M     = 1,   ///< 
    FSP_IP_MHSPI        = 2,   ///< 
    FSP_IP_MHMTU3A      = 3,   ///< 
    FSP_IP_MHSRC        = 4,   ///< 
    FSP_IP_MHGPT        = 5,   ///< 
    FSP_IP_MHPOEGA      = 6,   ///< 
    FSP_IP_MHPOEGB      = 7,   ///< 
    FSP_IP_MHPOEGC      = 8,   ///< 
    FSP_IP_MHPOEGD      = 9,   ///< 
    FSP_IP_MHPOE3       = 10,  ///< 
    FSP_IP_MHSSIF       = 11,  ///< 
    FSP_IP_MHRSPI       = 12,  ///< 
    FSP_IP_MHSCIF       = 13,  ///< 
    FSP_IP_MHIRDA       = 14,  ///< 
    FSP_IP_MHSCI        = 15,  ///< 
    FSP_IP_MPCANFD      = 16,  ///< 
    FSP_IP_MPI2C        = 17,  ///< 
    FSP_IP_MPADC        = 18,  ///< 
    FSP_IP_MPTSU        = 19,  ///< 
    FSP_IP_MXSDHI       = 20,  ///< 
    FSP_IP_MPGIGE       = 21,  ///< 
    FSP_IP_MPUSBT       = 22,  ///< 
    FSP_IP_MHUSB2_0_H   = 23,  ///< 
    FSP_IP_MHUSB2_0_F   = 24,  ///< 
    FSP_IP_MHUSB2_1     = 25,  ///< 
    FSP_IP_MXCOM        = 26,  ///< 
    FSP_IP_MXMCPU       = 27,  ///< 
    FSP_IP_MXACPU       = 28,  ///< 
    FSP_IP_MPCST        = 29,  ///< 
    FSP_IP_MPSYC        = 30,  ///< 
    FSP_IP_MPCPG        = 31,  ///< 
    FSP_IP_MHGPIO       = 32,  ///< 
    FSP_IP_MPTZC        = 33,  ///< 
    FSP_IP_MPSRAM_A     = 34,  ///< 
    FSP_IP_MPSRAM_M     = 35,  ///< 
    FSP_IP_MPIA55       = 36,  ///< 
    FSP_IP_MPIM33       = 37,  ///< 
    FSP_IP_MXREG0       = 38,  ///< 
    FSP_IP_MPPHY        = 39,  ///< 
    FSP_IP_MXMEMC_REG   = 40,  ///< 
    FSP_IP_MPVCP4L_V    = 41,  ///< 
    FSP_IP_MPVCP4L_C    = 42,  ///< 
    FSP_IP_MPFCPCS      = 43,  ///< 
    FSP_IP_MPCRU        = 44,  ///< 
    FSP_IP_MPISU        = 45,  ///< 
    FSP_IP_MPDSIPHY     = 46,  ///< 
    FSP_IP_MPDSIL       = 47,  ///< 
    FSP_IP_MPVSPD       = 48,  ///< 
    FSP_IP_MPFCPVD      = 49,  ///< 
    FSP_IP_MPDU         = 50,  ///< 
    FSP_IP_MXVIDEO      = 51,  ///< 
    FSP_IP_MPWDT_PUP    = 52,  ///< 
    FSP_IP_MPWDT_CM33   = 53,  ///< 
    FSP_IP_MPWDT_CA55C0 = 54,  ///< 
    FSP_IP_MPWDT_CA55C1 = 55,  ///< 
    FSP_IP_MPOSTM       = 56,  ///< 
    FSP_IP_MXDMAC_S     = 57,  ///< 
    FSP_IP_MPDMAC_S     = 58,  ///< 
    FSP_IP_MXDMAC_NS    = 59,  ///< 
    FSP_IP_MPDMAC_NS    = 60,  ///< 
    FSP_IP_MXMALI       = 61,  ///< 
    FSP_IP_MHTSIPG      = 62,  ///< 
    FSP_IP_MPTSIPG_OTP  = 63,  ///< 
    FSP_IP_MXGIC        = 64,  ///< 
    FSP_IP_TZCDDR       = 65,  ///< 
    FSP_IP_MHU          = 66,  ///<
} fsp_ip_t;

typedef void (* fsp_vector_t)(void);

/** @} (end addtogroup BSP_MCU) */

#endif
