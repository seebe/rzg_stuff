/* ${REA_DISCLAIMER_PLACEHOLDER} */

#ifndef BSP_FEATURE_H
#define BSP_FEATURE_H

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global variables (to be accessed by other files)
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private global variables and functions
 **********************************************************************************************************************/
//2021.04.07 tujimoto. BSP_FEATURE_BSP_UNIQUE_ID_POINTER address needs to be fixed by v1.0.
#define BSP_FEATURE_BSP_UNIQUE_ID_OFFSET                  (0U)
#define BSP_FEATURE_BSP_UNIQUE_ID_POINTER                 (0x01008190U)

#define BSP_FEATURE_GPTEH_CHANNEL_MASK                    (0)

#define BSP_FEATURE_GPTE_CHANNEL_MASK                     (0)

#define BSP_FEATURE_GPT_32BIT_CHANNEL_MASK                (0x0FU)
#define BSP_FEATURE_GPT_VALID_CHANNEL_MASK                (0x1FFU)

#if 0   //2021.04.07 tujimoto. ICU is not provided in v1.0.
#define BSP_FEATURE_ICU_HAS_WUPEN1                        (1U)
#define BSP_FEATURE_ICU_IRQ_CHANNELS_MASK                 (0xFFFFU)
#define BSP_FEATURE_ICU_WUPEN_MASK                        (0x7FB0DFFFFULL) // Note there is another WUPEN1 register
#endif

#define BSP_FEATURE_IIC_FAST_MODE_PLUS                    (1U << 0U)
#define BSP_FEATURE_IIC_VALID_CHANNEL_MASK                (0x03)

#if 0   //2021.04.07 tujimoto. RZG2L do not have event link.
#define BSP_FEATURE_IOPORT_ELC_PORTS                      (4)
#endif
#define BSP_FEATURE_IOPORT_HAS_ETHERNET                   (1U)

//2021.04.07 tujimoto. POEG definitions needs to be checked by v1.0.
#define BSP_FEATURE_OSPI_DEVICE_0_START_ADDRESS           (0x68000000U)
#define BSP_FEATURE_OSPI_DEVICE_1_START_ADDRESS           (0x70000000U)

#define BSP_FEATURE_POEG_CHANNEL_MASK                     (0xFU)

#define BSP_FEATURE_SCI_ADDRESS_MATCH_CHANNELS            (0x3F9U)
#define BSP_FEATURE_SCI_CHANNELS                          (0x3FFU)
#define BSP_FEATURE_SCI_CLOCK                             (FSP_PRIV_CLOCK_P0CLK)
#define BSP_FEATURE_SCI_UART_FIFO_CHANNELS                (0x3F9U)
#define BSP_FEATURE_SCI_UART_FIFO_DEPTH                   (16U)

#define BSP_FEATURE_SCIF_CHANNELS                         (0x1FU)
#define BSP_FEATURE_SCIF_CHANNELS_HAS_RTSCTS              (0x07U)
#define BSP_FEATURE_SCIF_CLOCK                            (FSP_PRIV_CLOCK_P0CLK)

#define BSP_FEATURE_GTM_VALID_CHANNEL_MASK                (0x7)

//2021.04.07 tujimoto. SPI definitions needs to be checked by v1.0.
#define BSP_FEATURE_SPI_CLK                               (FSP_PRIV_CLOCK_P0CLK)
#define BSP_FEATURE_SPI_HAS_BYTE_SWAP                     (1U)
#define BSP_FEATURE_SPI_HAS_SPCR3                         (1U)
#define BSP_FEATURE_SPI_HAS_SSL_LEVEL_KEEP                (1U)
#define BSP_FEATURE_SPI_MAX_CHANNEL                       (2U)

#define BSP_FEATURE_TZ_HAS_TRUSTZONE                      (1U)

#endif
