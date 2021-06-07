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

#ifndef BSP_MODULE_H
#define BSP_MODULE_H

/** Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/*******************************************************************************************************************//**
 * @addtogroup BSP_MCU
 * @{
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Cancels the module stop state.
 *
 * @param      ip       fsp_ip_t enum value for the module to be stopped
 * @param      channel  The channel. Use channel 0 for modules without channels.
 **********************************************************************************************************************/
#define R_BSP_MODULE_START(ip, channel) {BSP_MSTP_REG_ ## ip(channel) = 0x0000U                               \
                                                                     | (BSP_MSTP_BIT_ ## ip(channel) << 16U); \
                                         BSP_MSTP_REG_ ## ip(channel);}

/*******************************************************************************************************************//**
 * Enables the module stop state.
 *
 * @param      ip       fsp_ip_t enum value for the module to be stopped
 * @param      channel  The channel. Use channel 0 for modules without channels.
 **********************************************************************************************************************/
#define R_BSP_MODULE_STOP(ip, channel)  {BSP_MSTP_REG_ ## ip(channel) = 0xFFFFU                               \
                                                                     | (BSP_MSTP_BIT_ ## ip(channel) << 16U); \
                                         BSP_MSTP_REG_ ## ip(channel);}

/** @} (end addtogroup BSP_MCU) */
#define BSP_MSTP_REG_FSP_IP_MXSRAM_A(channel)              R_MSTP->ACPU
#define BSP_MSTP_BIT_FSP_IP_MXSRAM_A(channel)              (1U << R_MSTP_ACPU_SRAM_A_Pos)
#define BSP_MSTP_REG_FSP_IP_MXSRAM_M(channel)              R_MSTP->MCPU1
#define BSP_MSTP_BIT_FSP_IP_MXSRAM_M(channel)              (1U << R_MSTP_MCPU1_MXSRAM_M_Pos)
#define BSP_MSTP_REG_FSP_IP_MHSPI(channel)                 R_MSTP->MCPU1
#define BSP_MSTP_BIT_FSP_IP_MHSPI(channel)                 (1U << R_MSTP_MCPU1_MHSPI_Pos)
#define BSP_MSTP_REG_FSP_IP_MHMTU3A(channel)               R_MSTP->MCPU1
#define BSP_MSTP_BIT_FSP_IP_MHMTU3A(channel)               (1U << R_MSTP_MCPU1_MHMTU3A_Pos)
#define BSP_MSTP_REG_FSP_IP_MHSRC(channel)                 R_MSTP->MCPU1
#define BSP_MSTP_BIT_FSP_IP_MHSRC(channel)                 (1U << R_MSTP_MCPU1_MHSRC_Pos)
#define BSP_MSTP_REG_FSP_IP_MHGPT(channel)                 R_MSTP->MCPU1
#define BSP_MSTP_BIT_FSP_IP_MHGPT(channel)                 (1U << R_MSTP_MCPU1_MHGPT_Pos)
#define BSP_MSTP_REG_FSP_IP_MHPOEGA(channel)               R_MSTP->MCPU1
#define BSP_MSTP_BIT_FSP_IP_MHPOEGA(channel)               (1U << R_MSTP_MCPU1_MHPOEGA_Pos)
#define BSP_MSTP_REG_FSP_IP_MHPOEGB(channel)               R_MSTP->MCPU1
#define BSP_MSTP_BIT_FSP_IP_MHPOEGB(channel)               (1U << R_MSTP_MCPU1_MHPOEGB_Pos)
#define BSP_MSTP_REG_FSP_IP_MHPOEGC(channel)               R_MSTP->MCPU1
#define BSP_MSTP_BIT_FSP_IP_MHPOEGC(channel)               (1U << R_MSTP_MCPU1_MHPOEGC_Pos)
#define BSP_MSTP_REG_FSP_IP_MHPOEGD(channel)               R_MSTP->MCPU1
#define BSP_MSTP_BIT_FSP_IP_MHPOEGD(channel)               (1U << R_MSTP_MCPU1_MHPOEGD_Pos)
#define BSP_MSTP_REG_FSP_IP_MHPOE3(channel)                R_MSTP->MCPU1
#define BSP_MSTP_BIT_FSP_IP_MHPOE3(channel)                (1U << R_MSTP_MCPU1_MHPOE3_Pos)
#define BSP_MSTP_REG_FSP_IP_MHSSIF(channel)                R_MSTP->MCPU1
#define BSP_MSTP_BIT_FSP_IP_MHSSIF(channel)                (1U << (R_MSTP_MCPU1_MHSSIF0_Pos + channel))
#define BSP_MSTP_REG_FSP_IP_MHRSPI(channel)                *((2U>= channel) ? &R_MSTP->MCPU1 : &R_MSTP->MCPU2)
#define BSP_MSTP_BIT_FSP_IP_MHRSPI(channel)                ((2U >= channel) ? (1U << (R_MSTP_MCPU1_MHRSPI0_Pos + channel)) \
                                                                            : (1U << R_MSTP_MCPU2_MHRSPI2_Pos)
#define BSP_MSTP_REG_FSP_IP_SCIF(channel)                  R_MSTP->MCPU2
#define BSP_MSTP_BIT_FSP_IP_SCIF(channel)                  (1U << (R_MSTP_MCPU2_MHSCIF0_Pos + channel))
#define BSP_MSTP_REG_FSP_IP_MHIRDA(channel)                R_MSTP->MCPU2
#define BSP_MSTP_BIT_FSP_IP_MHIRDA(channel)                (1U << R_MSTP_MCPU2_MHIRDA_Pos)
#define BSP_MSTP_REG_FSP_IP_MHSCI(channel)                 R_MSTP->MCPU2
#define BSP_MSTP_BIT_FSP_IP_MHSCI(channel)                 (1U << (R_MSTP_MCPU2_MHSCI0_Pos + channel))
#define BSP_MSTP_REG_FSP_IP_MPCANFD(channel)               R_MSTP->MCPU2
#define BSP_MSTP_BIT_FSP_IP_MPCANFD(channel)               (1U << R_MSTP_MCPU2_MPCANFD_Pos)
#define BSP_MSTP_REG_FSP_IP_MPI2C(channel)                 R_MSTP->MCPU2
#define BSP_MSTP_BIT_FSP_IP_MPI2C(channel)                 (1U << (R_MSTP_MCPU2_MPI2C0_Pos + channel))
#define BSP_MSTP_REG_FSP_IP_MPADC(channel)                 R_MSTP->MCPU2
#define BSP_MSTP_BIT_FSP_IP_MPADC(channel)                 (1U << R_MSTP_MCPU2_MPADC_Pos)
#define BSP_MSTP_REG_FSP_IP_MPTSU(channel)                 R_MSTP->MCPU2
#define BSP_MSTP_BIT_FSP_IP_MPTSU(channel)                 (1U << R_MSTP_MCPU2_MPTSU_Pos)
#define BSP_MSTP_REG_FSP_IP_MXSDHI(channel)                R_MSTP->PERI_COM
#define BSP_MSTP_BIT_FSP_IP_MXSDHI(channel)                (1U << R_MSTP_PERI_COM_MXSDHI0_Pos + channel)
#define BSP_MSTP_REG_FSP_IP_MPGIGE(channel)                R_MSTP->PERI_COM
#define BSP_MSTP_BIT_FSP_IP_MPGIGE(channel)                (1U << R_MSTP_PERI_COM_MPGIGE0_Pos)
#define BSP_MSTP_REG_FSP_IP_MPUSBT(channel)                R_MSTP->PERI_COM
#define BSP_MSTP_BIT_FSP_IP_MPUSBT(channel)                (1U << R_MSTP_PERI_COM_MPUSBT_Pos)
#define BSP_MSTP_REG_FSP_IP_MHUSB2_0_H(channel)            R_MSTP->PERI_COM
#define BSP_MSTP_BIT_FSP_IP_MHUSB2_0_H(channel)            (1U << R_MSTP_PERI_COM_MHUSB2H_Pos)
#define BSP_MSTP_REG_FSP_IP_MHUSB2_0_F(channel)            R_MSTP->PERI_COM
#define BSP_MSTP_BIT_FSP_IP_MHUSB2_0_F(channel)            (1U << R_MSTP_PERI_COM_MHUSB2F_Pos)
#define BSP_MSTP_REG_FSP_IP_MHUSB2_1(channel)              R_MSTP->PERI_COM
#define BSP_MSTP_BIT_FSP_IP_MHUSB2_1(channel)              (1U << R_MSTP_PERI_COM_MHUSB21_Pos)
#define BSP_MSTP_REG_FSP_IP_MXCOM(channel)                 R_MSTP->PERI_COM
#define BSP_MSTP_BIT_FSP_IP_MXCOM(channel)                 (1U << R_MSTP_PERI_COM_MXCOM_Pos)
#define BSP_MSTP_REG_FSP_IP_MXMCPU(channel)                R_MSTP->PERI_CPU
#define BSP_MSTP_BIT_FSP_IP_MXMCPU(channel)                (1U << R_MSTP_PERI_CPU_MXMCPU_Pos)
#define BSP_MSTP_REG_FSP_IP_MXACPU(channel)                R_MSTP->PERI_CPU
#define BSP_MSTP_BIT_FSP_IP_MXACPU(channel)                (1U << R_MSTP_PERI_CPU_MXACPU_Pos)
#define BSP_MSTP_REG_FSP_IP_MPCST(channel)                 R_MSTP->PERI_CPU
#define BSP_MSTP_BIT_FSP_IP_MPCST(channel)                 (1U << R_MSTP_PERI_CPU_MPCST_Pos)
#define BSP_MSTP_REG_FSP_IP_MPSYC(channel)                 R_MSTP->PERI_CPU
#define BSP_MSTP_BIT_FSP_IP_MPSYC(channel)                 (1U << R_MSTP_PERI_CPU_MPSYC_Pos)
#define BSP_MSTP_REG_FSP_IP_MPCPG(channel)                 R_MSTP->PERI_CPU
#define BSP_MSTP_BIT_FSP_IP_MPCPG(channel)                 (1U << R_MSTP_PERI_CPU_MPCPG_Pos)
#define BSP_MSTP_REG_FSP_IP_MHGPIO(channel)                R_MSTP->PERI_CPU
#define BSP_MSTP_BIT_FSP_IP_MHGPIO(channel)                (1U << R_MSTP_PERI_CPU_MHGPIO_Pos)
#define BSP_MSTP_REG_FSP_IP_MPTZC(channel)                 R_MSTP->PERI_CPU
#define BSP_MSTP_BIT_FSP_IP_MPTZC(channel)                 (1U << (R_MSTP_PERI_CPU_MPTZC0_Pos + channel))
#define BSP_MSTP_REG_FSP_IP_MPSRAM_A(channel)              R_MSTP->PERI_CPU
#define BSP_MSTP_BIT_FSP_IP_MPSRAM_A(channel)              (1U << R_MSTP_PERI_CPU_MPSRAM_A_Pos)
#define BSP_MSTP_REG_FSP_IP_MPSRAM_M(channel)              R_MSTP->PERI_CPU
#define BSP_MSTP_BIT_FSP_IP_MPSRAM_M(channel)              (1U << R_MSTP_PERI_CPU_MPSRAM_M_Pos)
#define BSP_MSTP_REG_FSP_IP_MPIA55(channel)                R_MSTP->PERI_CPU
#define BSP_MSTP_BIT_FSP_IP_MPIA55(channel)                (1U << R_MSTP_PERI_CPU_MPIA55_Pos)
#define BSP_MSTP_REG_FSP_IP_MPIM33(channel)                R_MSTP->PERI_CPU
#define BSP_MSTP_BIT_FSP_IP_MPIM33(channel)                (1U << R_MSTP_PERI_CPU_MPIM33_Pos)
#define BSP_MSTP_REG_FSP_IP_MXREG0(channel)                R_MSTP->PERI_CPU
#define BSP_MSTP_BIT_FSP_IP_MXREG0(channel)                (1U << R_MSTP_PERI_CPU_MXREG0_Pos)
#define BSP_MSTP_REG_FSP_IP_MPPHY(channel)                 R_MSTP->PERI_DDR
#define BSP_MSTP_BIT_FSP_IP_MPPHY(channel)                 (1U << R_MSTP_PERI_DDR_MPPHY_Pos)
#define BSP_MSTP_REG_FSP_IP_MXMEMC_REG(channel)            R_MSTP->PERI_DDR
#define BSP_MSTP_BIT_FSP_IP_MXMEMC_REG(channel)            (1U << R_MSTP_PERI_DDR_MXMEMC_REG_Pos)
#define BSP_MSTP_REG_FSP_IP_MPVCP4L_V(channel)             R_MSTP->PERI_VIDEO
#define BSP_MSTP_BIT_FSP_IP_MPVCP4L_V(channel)             (1U << R_MSTP_PERI_VIDEO_MPVCP4L_V_Pos)
#define BSP_MSTP_REG_FSP_IP_MPVCP4L_C(channel)             R_MSTP->PERI_VIDEO
#define BSP_MSTP_BIT_FSP_IP_MPVCP4L_C(channel)             (1U << R_MSTP_PERI_VIDEO_MPVCP4L_C_Pos)
#define BSP_MSTP_REG_FSP_IP_MPFCPCS(channel)               R_MSTP->PERI_VIDEO
#define BSP_MSTP_BIT_FSP_IP_MPFCPCS(channel)               (1U << R_MSTP_PERI_VIDEO_MPFCPCS_Pos)
#define BSP_MSTP_REG_FSP_IP_MPCRU(channel)                 R_MSTP->PERI_VIDEO
#define BSP_MSTP_BIT_FSP_IP_MPCRU(channel)                 (1U << R_MSTP_PERI_VIDEO_MPCRU_Pos)
#define BSP_MSTP_REG_FSP_IP_MPISU(channel)                 R_MSTP->PERI_VIDEO
#define BSP_MSTP_BIT_FSP_IP_MPISU(channel)                 (1U << R_MSTP_PERI_VIDEO_MPISU_Pos)
#define BSP_MSTP_REG_FSP_IP_MPDSIPHY(channel)              R_MSTP->PERI_VIDEO
#define BSP_MSTP_BIT_FSP_IP_MPDSIPHY(channel)              (1U << R_MSTP_PERI_VIDEO_MPDSIPHY_Pos)
#define BSP_MSTP_REG_FSP_IP_MPDSIL(channel)                R_MSTP->PERI_VIDEO
#define BSP_MSTP_BIT_FSP_IP_MPDSIL(channel)                (1U << R_MSTP_PERI_VIDEO_MPDSIL_Pos)
#define BSP_MSTP_REG_FSP_IP_MPVSPD(channel)                R_MSTP->PERI_VIDEO
#define BSP_MSTP_BIT_FSP_IP_MPVSPD(channel)                (1U << R_MSTP_PERI_VIDEO_MPVSPD_Pos)
#define BSP_MSTP_REG_FSP_IP_MPFCPVD(channel)               R_MSTP->PERI_VIDEO
#define BSP_MSTP_BIT_FSP_IP_MPFCPVD(channel)               (1U << R_MSTP_PERI_VIDEO_MPCPVD_Pos)
#define BSP_MSTP_REG_FSP_IP_MPDU(channel)                  R_MSTP->PERI_VIDEO
#define BSP_MSTP_BIT_FSP_IP_MPDU(channel)                  (1U << R_MSTP_PERI_VIDEO_MPDU_Pos)
#define BSP_MSTP_REG_FSP_IP_MXVIDEO(channel)               R_MSTP->PERI_VIDEO
#define BSP_MSTP_BIT_FSP_IP_MXVIDEO(channel)               (1U << R_MSTP_PERI_VIDEO_MXVIDEO_Pos)
#define BSP_MSTP_REG_FSP_IP_MPWDT_PUP(channel)             R_MSTP->REG0
#define BSP_MSTP_BIT_FSP_IP_MPWDT_PUP(channel)             (1U << R_MSTP_REG0_MPWDT3_Pos)
#define BSP_MSTP_REG_FSP_IP_MPWDT_CM33(channel)            R_MSTP->REG0
#define BSP_MSTP_BIT_FSP_IP_MPWDT_CM33(channel)            (1U << R_MSTP_REG0_MPWDT2_Pos)
#define BSP_MSTP_REG_FSP_IP_MPWDT_CA55C0(channel)          R_MSTP->REG0
#define BSP_MSTP_BIT_FSP_IP_MPWDT_CA55C0(channel)          (1U << R_MSTP_REG0_MPWDT0_Pos)
#define BSP_MSTP_REG_FSP_IP_MPWDT_CA55C1(channel)          R_MSTP->REG0
#define BSP_MSTP_BIT_FSP_IP_MPWDT_CA55C1(channel)          (1U << R_MSTP_REG0_MPWDT1_Pos)
#define BSP_MSTP_REG_FSP_IP_GTM(channel)                   R_MSTP->REG0
#define BSP_MSTP_BIT_FSP_IP_GTM(channel)                   (1U << (R_MSTP_REG0_MPOSTM0_Pos + channel))
#define BSP_MSTP_REG_FSP_IP_MXDMAC_S(channel)              R_MSTP->REG1
#define BSP_MSTP_BIT_FSP_IP_MXDMAC_S(channel)              (1U << R_MSTP_REG1_MXDMAC_S_Pos)
#define BSP_MSTP_REG_FSP_IP_MPDMAC_S(channel)              R_MSTP->REG1
#define BSP_MSTP_BIT_FSP_IP_MPDMAC_S(channel)              (1U << R_MSTP_REG1_MPDMAC_S_Pos)
#define BSP_MSTP_REG_FSP_IP_MXDMAC_NS(channel)             R_MSTP->REG1
#define BSP_MSTP_BIT_FSP_IP_MXDMAC_NS(channel)             (1U << R_MSTP_REG1_MXDMAC_NS_Pos)
#define BSP_MSTP_REG_FSP_IP_MPDMAC_NS(channel)             R_MSTP->REG1
#define BSP_MSTP_BIT_FSP_IP_MPDMAC_NS(channel)             (1U << R_MSTP_REG1_MPDMAC_NS_Pos)
#define BSP_MSTP_REG_FSP_IP_MXMALI(channel)                R_MSTP->REG1
#define BSP_MSTP_BIT_FSP_IP_MXMALI(channel)                (1U << R_MSTP_REG1_MXMALI_Pos)
#define BSP_MSTP_REG_FSP_IP_MHTSIPG(channel)               R_MSTP->REG1
#define BSP_MSTP_BIT_FSP_IP_MHTSIPG(channel)               (1U << R_MSTP_REG1_MHTSIPG_Pos)
#define BSP_MSTP_REG_FSP_IP_MPTSIPG_OTP(channel)           R_MSTP->REG1
#define BSP_MSTP_BIT_FSP_IP_MPTSIPG_OTP(channel)           (1U << R_MSTP_REG1_MHTSIPG_OTP_Pos)
#define BSP_MSTP_REG_FSP_IP_MXGIC(channel)                 R_MSTP->REG1
#define BSP_MSTP_BIT_FSP_IP_MXGIC(channel)                 (1U << R_MSTP_REG1_MXGIC_Pos)
#define BSP_MSTP_REG_FSP_IP_TZCDDR(channel)                R_MSTP->TZCDDR
#define BSP_MSTP_BIT_FSP_IP_TZCDDR(channel)                (1U << (R_MSTP_TZCDDR_MSTOP0_Pos + channel))
#define BSP_MSTP_REG_FSP_IP_MHU(channel)                   R_MSTP->MHU
#define BSP_MSTP_BIT_FSP_IP_MHU(channel)                   (1U << R_MSTP_MHU_MSTOP_Pos)

/** Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif
