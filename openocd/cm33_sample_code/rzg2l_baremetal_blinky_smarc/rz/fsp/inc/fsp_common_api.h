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

#ifndef FSP_COMMON_API_H
#define FSP_COMMON_API_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include <assert.h>
#include <stdint.h>

/* Includes FSP version macros. */
#include "fsp_version.h"

/*******************************************************************************************************************//**
 * @ingroup RENESAS_COMMON
 * @defgroup RENESAS_ERROR_CODES Common Error Codes
 * All FSP modules share these common error codes.
 * @{
 **********************************************************************************************************************/

/**********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/** This macro is used to suppress compiler messages about a parameter not being used in a function. The nice thing
 * about using this implementation is that it does not take any extra RAM or ROM. */

#define FSP_PARAMETER_NOT_USED(p)    (void) ((p))

/** Determine if a C++ compiler is being used.
 * If so, ensure that standard C is used to process the API information.  */
#if defined(__cplusplus)
 #define FSP_CPP_HEADER    extern "C" {
 #define FSP_CPP_FOOTER    }
#else
 #define FSP_CPP_HEADER
 #define FSP_CPP_FOOTER
#endif

/** FSP Header and Footer definitions */
#define FSP_HEADER             FSP_CPP_HEADER
#define FSP_FOOTER             FSP_CPP_FOOTER

/** Macro to be used when argument to function is ignored since function call is NSC and the parameter is statically
 *  defined on the Secure side. */
#define FSP_SECURE_ARGUMENT    (NULL)

/**********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** Common error codes */
typedef enum e_fsp_err
{
    FSP_SUCCESS = 0,

    FSP_ERR_ASSERTION             = 1,                      ///< A critical assertion has failed
    FSP_ERR_INVALID_POINTER       = 2,                      ///< Pointer points to invalid memory location
    FSP_ERR_INVALID_ARGUMENT      = 3,                      ///< Invalid input parameter
    FSP_ERR_INVALID_CHANNEL       = 4,                      ///< Selected channel does not exist
    FSP_ERR_INVALID_MODE          = 5,                      ///< Unsupported or incorrect mode
    FSP_ERR_UNSUPPORTED           = 6,                      ///< Selected mode not supported by this API
    FSP_ERR_NOT_OPEN              = 7,                      ///< Requested channel is not configured or API not open
    FSP_ERR_IN_USE                = 8,                      ///< Channel/peripheral is running/busy
    FSP_ERR_OUT_OF_MEMORY         = 9,                      ///< Allocate more memory in the driver's cfg.h
    FSP_ERR_HW_LOCKED             = 10,                     ///< Hardware is locked
    FSP_ERR_IRQ_BSP_DISABLED      = 11,                     ///< IRQ not enabled in BSP
    FSP_ERR_OVERFLOW              = 12,                     ///< Hardware overflow
    FSP_ERR_UNDERFLOW             = 13,                     ///< Hardware underflow
    FSP_ERR_ALREADY_OPEN          = 14,                     ///< Requested channel is already open in a different configuration
    FSP_ERR_APPROXIMATION         = 15,                     ///< Could not set value to exact result
    FSP_ERR_CLAMPED               = 16,                     ///< Value had to be limited for some reason
    FSP_ERR_INVALID_RATE          = 17,                     ///< Selected rate could not be met
    FSP_ERR_ABORTED               = 18,                     ///< An operation was aborted
    FSP_ERR_NOT_ENABLED           = 19,                     ///< Requested operation is not enabled
    FSP_ERR_TIMEOUT               = 20,                     ///< Timeout error
    FSP_ERR_INVALID_BLOCKS        = 21,                     ///< Invalid number of blocks supplied
    FSP_ERR_INVALID_ADDRESS       = 22,                     ///< Invalid address supplied
    FSP_ERR_INVALID_SIZE          = 23,                     ///< Invalid size/length supplied for operation
    FSP_ERR_WRITE_FAILED          = 24,                     ///< Write operation failed
    FSP_ERR_ERASE_FAILED          = 25,                     ///< Erase operation failed
    FSP_ERR_INVALID_CALL          = 26,                     ///< Invalid function call is made
    FSP_ERR_INVALID_HW_CONDITION  = 27,                     ///< Detected hardware is in invalid condition
    FSP_ERR_INVALID_FACTORY_FLASH = 28,                     ///< Factory flash is not available on this MCU
    FSP_ERR_INVALID_STATE         = 30,                     ///< API or command not valid in the current state
    FSP_ERR_NOT_ERASED            = 31,                     ///< Erase verification failed
    FSP_ERR_SECTOR_RELEASE_FAILED = 32,                     ///< Sector release failed
    FSP_ERR_NOT_INITIALIZED       = 33,                     ///< Required initialization not complete
    FSP_ERR_NOT_FOUND             = 34,                     ///< The requested item could not be found
    FSP_ERR_NO_CALLBACK_MEMORY    = 35,                     ///< Non-secure callback memory not provided for non-secure callback

    /* Start of RTOS only error codes */
    FSP_ERR_INTERNAL     = 100,                             ///< Internal error
    FSP_ERR_WAIT_ABORTED = 101,                             ///< Wait aborted

    /* Start of UART specific */
    FSP_ERR_FRAMING            = 200,                       ///< Framing error occurs
    FSP_ERR_BREAK_DETECT       = 201,                       ///< Break signal detects
    FSP_ERR_PARITY             = 202,                       ///< Parity error occurs
    FSP_ERR_RXBUF_OVERFLOW     = 203,                       ///< Receive queue overflow
    FSP_ERR_QUEUE_UNAVAILABLE  = 204,                       ///< Can't open s/w queue
    FSP_ERR_INSUFFICIENT_SPACE = 205,                       ///< Not enough space in transmission circular buffer
    FSP_ERR_INSUFFICIENT_DATA  = 206,                       ///< Not enough data in receive circular buffer

    /* Start of SPI specific */
    FSP_ERR_TRANSFER_ABORTED = 300,                         ///< The data transfer was aborted.
    FSP_ERR_MODE_FAULT       = 301,                         ///< Mode fault error.
    FSP_ERR_READ_OVERFLOW    = 302,                         ///< Read overflow.
    FSP_ERR_SPI_PARITY       = 303,                         ///< Parity error.
    FSP_ERR_OVERRUN          = 304,                         ///< Overrun error.
    /* Start of IP specific */
    FSP_ERR_IP_HARDWARE_NOT_PRESENT = 1400,                 ///< Requested IP does not exist on this device
    FSP_ERR_IP_UNIT_NOT_PRESENT     = 1401,                 ///< Requested unit does not exist on this device
    FSP_ERR_IP_CHANNEL_NOT_PRESENT  = 1402,                 ///< Requested channel does not exist on this device

    /* Start of Message framework specific */
    FSP_ERR_NO_MORE_BUFFER           = 2000,         ///< No more buffer found in the memory block pool
    FSP_ERR_ILLEGAL_BUFFER_ADDRESS   = 2001,         ///< Buffer address is out of block memory pool
    FSP_ERR_INVALID_WORKBUFFER_SIZE  = 2002,         ///< Work buffer size is invalid
    FSP_ERR_INVALID_MSG_BUFFER_SIZE  = 2003,         ///< Message buffer size is invalid
    FSP_ERR_TOO_MANY_BUFFERS         = 2004,         ///< Number of buffer is too many
    FSP_ERR_NO_SUBSCRIBER_FOUND      = 2005,         ///< No message subscriber found
    FSP_ERR_MESSAGE_QUEUE_EMPTY      = 2006,         ///< No message found in the message queue
    FSP_ERR_MESSAGE_QUEUE_FULL       = 2007,         ///< No room for new message in the message queue
    FSP_ERR_ILLEGAL_SUBSCRIBER_LISTS = 2008,         ///< Message subscriber lists is illegal
    FSP_ERR_BUFFER_RELEASED          = 2009,         ///< Buffer has been released

    /* Start of BYTEQ library specific */
    FSP_ERR_QUEUE_FULL  = 10000,                     ///< Queue is full, cannot queue another data
    FSP_ERR_QUEUE_EMPTY = 10001,                     ///< Queue is empty, no data to dequeue

    /** @note SF_CRYPTO APIs may return an error code starting from 0x10000 which is of Crypto module.
     *        Refer to sf_cryoto_err.h for Crypto error codes.
     */
} fsp_err_t;

/** Common version structure */
typedef union st_fsp_version
{
    /** Version id */
    uint32_t version_id;

    /** Code version parameters */
    struct
    {
        uint8_t code_version_minor;    ///< Code minor version
        uint8_t code_version_major;    ///< Code major version
        uint8_t api_version_minor;     ///< API minor version
        uint8_t api_version_major;     ///< API major version
    };
} fsp_version_t;

/** @} */

/***********************************************************************************************************************
 * Function prototypes
 **********************************************************************************************************************/

#endif
