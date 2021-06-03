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

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global variables (to be accessed by other files)
 **********************************************************************************************************************/
extern void Default_Handler(void);

BSP_DONT_REMOVE fsp_vector_t g_vector_table[BSP_ICU_VECTOR_MAX_ENTRIES] BSP_PLACE_IN_SECTION(BSP_SECTION_APPLICATION_VECTORS) =
{
    Default_Handler, /* Interrupt ID:0, NMI */
    Default_Handler, /* Interrupt ID:1, IRQ0 */
    Default_Handler, /* Interrupt ID:2, IRQ1 */
    Default_Handler, /* Interrupt ID:3, IRQ2 */
    Default_Handler, /* Interrupt ID:4, IRQ3 */
    Default_Handler, /* Interrupt ID:5, IRQ4 */
    Default_Handler, /* Interrupt ID:6, IRQ5 */
    Default_Handler, /* Interrupt ID:7, IRQ6 */
    Default_Handler, /* Interrupt ID:8, IRQ7 */
    Default_Handler, /* Interrupt ID:9, nCOMMIRQ[1] */
    Default_Handler, /* Interrupt ID:10, nCOMMIRQ[0] */
    Default_Handler, /* Interrupt ID:11, nPMUIRQ[1] */
    Default_Handler, /* Interrupt ID:12, nPMUIRQ[0] */
    Default_Handler, /* Interrupt ID:13, nCLUSTERPMUIRQ */
    Default_Handler, /* Interrupt ID:14, nERRIRQ[2] */
    Default_Handler, /* Interrupt ID:15, nERRIRQ[1] */
    Default_Handler, /* Interrupt ID:16, nERRIRQ[0] */
    Default_Handler, /* Interrupt ID:17, nFAULTIRQ[2] */
    Default_Handler, /* Interrupt ID:18, nFAULTIRQ[1] */
    Default_Handler, /* Interrupt ID:19, nFAULTIRQ[0] */
    Default_Handler, /* Interrupt ID:20, CTIIRQ[1] */
    Default_Handler, /* Interrupt ID:21, CTIIRQ[0] */
    Default_Handler, /* Interrupt ID:22, fault_int */
    Default_Handler, /* Interrupt ID:23, err_int */
    Default_Handler, /* Interrupt ID:24, pmu_int */
    Default_Handler, /* Interrupt ID:25, BUS_ERR_INTR_W_SXCA55 */
    Default_Handler, /* Interrupt ID:26, TZCINT_SRAM_A */
    Default_Handler, /* Interrupt ID:27, TZCINT_SRAM_M */
    Default_Handler, /* Interrupt ID:28, TZCINT_SPI */
    Default_Handler, /* Interrupt ID:29, TZCINT_DDR */
    Default_Handler, /* Interrupt ID:30, ERRINT_BRG_CM33_S */
    Default_Handler, /* Interrupt ID:31, ERRINT_BRG_CM33_C */
    Default_Handler, /* Interrupt ID:32, SECINT */
    Default_Handler, /* Interrupt ID:33, DEDINT */
    Default_Handler, /* Interrupt ID:34, ACPU EC7TIE1[0] */
    Default_Handler, /* Interrupt ID:35, ACPU EC7TIE2[0] */
    Default_Handler, /* Interrupt ID:36, ACPU EC7TIOVF[0] */
    Default_Handler, /* Interrupt ID:37, MCPU EC7TIE1[0] */
    Default_Handler, /* Interrupt ID:38, MCPU EC7TIE2[0] */
    Default_Handler, /* Interrupt ID:39, MCPU EC7TIOVF[0] */
    Default_Handler, /* Interrupt ID:40, DDR3L/4 Interrupt signal from the controller */
    Default_Handler, /* Interrupt ID:41, SPI Multi interrupt request signal */
    Default_Handler, /* Interrupt ID:42, SYS_LPM_INT */
    Default_Handler, /* Interrupt ID:43, SYS_CA55STBYDONE_INT */
    Default_Handler, /* Interrupt ID:44, SYS_CM33STBYR_INT */
    Default_Handler, /* Interrupt ID:45, SYS_CA55_DENY */
    Default_Handler, /* Interrupt ID:46, General Timer ch 0 Interrupt signal  */
    Default_Handler, /* Interrupt ID:47, General Timer ch 1 Interrupt signal  */
    Default_Handler, /* Interrupt ID:48, General Timer ch 2 Interrupt signal  */
    Default_Handler, /* Interrupt ID:49, CA55 core 0 WDTINT  */
    Default_Handler, /* Interrupt ID:50, CA55 core 0 PERROUT */
    Default_Handler, /* Interrupt ID:51, CA55 core 1 WDTINT  */
    Default_Handler, /* Interrupt ID:52, CA55 core 1 PERROUT */
    Default_Handler, /* Interrupt ID:53, CM33 WDTINT  */
    Default_Handler, /* Interrupt ID:54, CM33 PERROUT */
    Default_Handler, /* Interrupt ID:55, Power up WDTINT */
    Default_Handler, /* Interrupt ID:56, msg_ch0_s */
    Default_Handler, /* Interrupt ID:57, msg_ch1_s */
    Default_Handler, /* Interrupt ID:58, msg_ch2_s */
    Default_Handler, /* Interrupt ID:59, msg_ch3_s */
    Default_Handler, /* Interrupt ID:60, msg_ch4_s */
    Default_Handler, /* Interrupt ID:61, msg_ch5_s */
    Default_Handler, /* Interrupt ID:62, rsp_ch0_s */
    Default_Handler, /* Interrupt ID:63, rsp_ch1_s */
    Default_Handler, /* Interrupt ID:64, rsp_ch2_s */
    Default_Handler, /* Interrupt ID:65, rsp_ch3_s */
    Default_Handler, /* Interrupt ID:66, rsp_ch4_s */
    Default_Handler, /* Interrupt ID:67, rsp_ch5_s */
    Default_Handler, /* Interrupt ID:68, msg_ch0_ns */
    Default_Handler, /* Interrupt ID:69, msg_ch1_ns */
    Default_Handler, /* Interrupt ID:70, msg_ch2_ns */
    Default_Handler, /* Interrupt ID:71, msg_ch3_ns */
    Default_Handler, /* Interrupt ID:72, msg_ch4_ns */
    Default_Handler, /* Interrupt ID:73, msg_ch5_ns */
    Default_Handler, /* Interrupt ID:74, rsp_ch0_ns */
    Default_Handler, /* Interrupt ID:75, rsp_ch1_ns */
    Default_Handler, /* Interrupt ID:76, rsp_ch2_ns */
    Default_Handler, /* Interrupt ID:77, rsp_ch3_ns */
    Default_Handler, /* Interrupt ID:78, rsp_ch4_ns */
    Default_Handler, /* Interrupt ID:79, rsp_ch5_ns */
    Default_Handler, /* Interrupt ID:80, sw_mhu_int_0 */
    Default_Handler, /* Interrupt ID:81, sw_mhu_int_1 */
    Default_Handler, /* Interrupt ID:82, sw_mhu_int_2 */
    Default_Handler, /* Interrupt ID:83, sw_mhu_int_3 */
    Default_Handler, /* Interrupt ID:84, pif_int_n */
    Default_Handler, /* Interrupt ID:85, int_fil_n */
    Default_Handler, /* Interrupt ID:86, int_arp_ns_n */
    Default_Handler, /* Interrupt ID:87, pif_int_n */
    Default_Handler, /* Interrupt ID:88, int_fil_n */
    Default_Handler, /* Interrupt ID:89, int_arp_ns_n */
    Default_Handler, /* Interrupt ID:90, U2H0_INT */
    Default_Handler, /* Interrupt ID:91, U2H0_OHCI_INT */
    Default_Handler, /* Interrupt ID:92, U2H0_EHCI_INT */
    Default_Handler, /* Interrupt ID:93, U2H0_WAKEON_INT */
    Default_Handler, /* Interrupt ID:94, U2H0_OBINT */
    Default_Handler, /* Interrupt ID:95, U2H1_INT */
    Default_Handler, /* Interrupt ID:96, U2H1_OHCI_INT */
    Default_Handler, /* Interrupt ID:97, U2H1_EHCI_INT */
    Default_Handler, /* Interrupt ID:98, U2H1_WAKEON_INT */
    Default_Handler, /* Interrupt ID:99, U2H1_OBINT */
    Default_Handler, /* Interrupt ID:100, U2P_IXL_INT */
    Default_Handler, /* Interrupt ID:101, U2P_INT_DMA[0] */
    Default_Handler, /* Interrupt ID:102, U2P_INT_DMA[1] */
    Default_Handler, /* Interrupt ID:103, U2P_INT_DMAERR */
    Default_Handler, /* Interrupt ID:104, SDHI_eMMC0 OXMNIRQ */
    Default_Handler, /* Interrupt ID:105, SDHI_eMMC0 OXASIOIRQ */
    Default_Handler, /* Interrupt ID:106, SDHI_eMMC0 OXMNIRQ */
    Default_Handler, /* Interrupt ID:107, SDHI_eMMC0 OXASIOIRQ */
    Default_Handler, /* Interrupt ID:108, DMAC_intreq_dmaint0(Secure) */
    Default_Handler, /* Interrupt ID:109, DMAC_intreq_dmaint1(Secure) */
    Default_Handler, /* Interrupt ID:110, DMAC_intreq_dmaint2(Secure) */
    Default_Handler, /* Interrupt ID:111, DMAC_intreq_dmaint3(Secure) */
    Default_Handler, /* Interrupt ID:112, DMAC_intreq_dmaint4(Secure) */
    Default_Handler, /* Interrupt ID:113, DMAC_intreq_dmaint5(Secure) */
    Default_Handler, /* Interrupt ID:114, DMAC_intreq_dmaint6(Secure) */
    Default_Handler, /* Interrupt ID:115, DMAC_intreq_dmaint7(Secure) */
    Default_Handler, /* Interrupt ID:116, DMAC_intreq_dmaint8(Secure) */
    Default_Handler, /* Interrupt ID:117, DMAC_intreq_dmaint9(Secure) */
    Default_Handler, /* Interrupt ID:118, DMAC_intreq_dmaint10(Secure) */
    Default_Handler, /* Interrupt ID:119, DMAC_intreq_dmaint11(Secure) */
    Default_Handler, /* Interrupt ID:120, DMAC_intreq_dmaint12(Secure) */
    Default_Handler, /* Interrupt ID:121, DMAC_intreq_dmaint13(Secure) */
    Default_Handler, /* Interrupt ID:122, DMAC_intreq_dmaint14(Secure) */
    Default_Handler, /* Interrupt ID:123, DMAC_intreq_dmaint15(Secure) */
    Default_Handler, /* Interrupt ID:124, DMAERR(Secure) */
    Default_Handler, /* Interrupt ID:125, DMAC_intreq_dmaint0(Non-Secure) */
    Default_Handler, /* Interrupt ID:126, DMAC_intreq_dmaint1(Non-Secure) */
    Default_Handler, /* Interrupt ID:127, DMAC_intreq_dmaint2(Non-Secure) */
    Default_Handler, /* Interrupt ID:128, DMAC_intreq_dmaint3(Non-Secure) */
    Default_Handler, /* Interrupt ID:129, DMAC_intreq_dmaint4(Non-Secure) */
    Default_Handler, /* Interrupt ID:130, DMAC_intreq_dmaint5(Non-Secure) */
    Default_Handler, /* Interrupt ID:131, DMAC_intreq_dmaint6(Non-Secure) */
    Default_Handler, /* Interrupt ID:132, DMAC_intreq_dmaint7(Non-Secure) */
    Default_Handler, /* Interrupt ID:133, DMAC_intreq_dmaint8(Non-Secure) */
    Default_Handler, /* Interrupt ID:134, DMAC_intreq_dmaint9(Non-Secure) */
    Default_Handler, /* Interrupt ID:135, DMAC_intreq_dmaint10(Non-Secure) */
    Default_Handler, /* Interrupt ID:136, DMAC_intreq_dmaint11(Non-Secure) */
    Default_Handler, /* Interrupt ID:137, DMAC_intreq_dmaint12(Non-Secure) */
    Default_Handler, /* Interrupt ID:138, DMAC_intreq_dmaint13(Non-Secure) */
    Default_Handler, /* Interrupt ID:139, DMAC_intreq_dmaint14(Non-Secure) */
    Default_Handler, /* Interrupt ID:140, DMAC_intreq_dmaint15(Non-Secure) */
    Default_Handler, /* Interrupt ID:141, DMAERR(Non-Secure) */
    Default_Handler, /* Interrupt ID:142, dsi_int_seq0 */
    Default_Handler, /* Interrupt ID:143, dsi_int_seq1 */
    Default_Handler, /* Interrupt ID:144, dsi_int_vin1 */
    Default_Handler, /* Interrupt ID:145, dsi_int_rcv */
    Default_Handler, /* Interrupt ID:146, dsi_int_ferr */
    Default_Handler, /* Interrupt ID:147, dsi_int_ppi */
    Default_Handler, /* Interrupt ID:148, dsi_int_debug */
    Default_Handler, /* Interrupt ID:149, vs1o_intreq_n */
    Default_Handler, /* Interrupt ID:150, vs1o_smg0_int_unmatched_n */
    Default_Handler, /* Interrupt ID:151, vs1o_smg0_int_frozen_n */
    Default_Handler, /* Interrupt ID:152, duo_intr_n */
    Default_Handler, /* Interrupt ID:153, IRQGPU */
    Default_Handler, /* Interrupt ID:154, IRQJOB */
    Default_Handler, /* Interrupt ID:155, IRQMMU */
    Default_Handler, /* Interrupt ID:156, IRQEVENT */
    Default_Handler, /* Interrupt ID:157, ISU_INT_FRE */
    Default_Handler, /* Interrupt ID:158, ISU_INT_DESE */
    Default_Handler, /* Interrupt ID:159, ISU_INT_STOPE */
    Default_Handler, /* Interrupt ID:160, ISU_INT_ERR */
    Default_Handler, /* Interrupt ID:161, vpo_vintreq_n */
    Default_Handler, /* Interrupt ID:162, vpo_cintreq_n */
    Default_Handler, /* Interrupt ID:163, vpo_vedcerr */
    Default_Handler, /* Interrupt ID:164, vpo_cedcerr */
    Default_Handler, /* Interrupt ID:165, fco_edcerr */
    Default_Handler, /* Interrupt ID:166, csi2_link_int  */
    Default_Handler, /* Interrupt ID:167, image_conv_int */
    Default_Handler, /* Interrupt ID:168, image_conv_err_int */
    Default_Handler, /* Interrupt ID:169, axi_mst_err_int */
    Default_Handler, /* Interrupt ID:170, tgi0a_pls_n */
    Default_Handler, /* Interrupt ID:171, tgi0b_pls_n */
    Default_Handler, /* Interrupt ID:172, tgi0c_pls_n */
    Default_Handler, /* Interrupt ID:173, tgi0d_pls_n */
    Default_Handler, /* Interrupt ID:174, tci0v_pls_n */
    Default_Handler, /* Interrupt ID:175, tgi0e_pls_n */
    Default_Handler, /* Interrupt ID:176, tgi0f_pls_n */
    Default_Handler, /* Interrupt ID:177, tgi1a_pls_n */
    Default_Handler, /* Interrupt ID:178, tgi1b_pls_n */
    Default_Handler, /* Interrupt ID:179, tci1v_pls_n */
    Default_Handler, /* Interrupt ID:180, tci1u_pls_n */
    Default_Handler, /* Interrupt ID:181, tgi2a_pls_n */
    Default_Handler, /* Interrupt ID:182, tgi2b_pls_n */
    Default_Handler, /* Interrupt ID:183, tci2v_pls_n */
    Default_Handler, /* Interrupt ID:184, tci2u_pls_n */
    Default_Handler, /* Interrupt ID:185, tgi3ai_pls_n */
    Default_Handler, /* Interrupt ID:186, tgi3bi_pls_n */
    Default_Handler, /* Interrupt ID:187, tgi3ci_pls_n */
    Default_Handler, /* Interrupt ID:188, tgi3di_pls_n */
    Default_Handler, /* Interrupt ID:189, tci3vi_pls_n */
    Default_Handler, /* Interrupt ID:190, tgi4ai_pls_n */
    Default_Handler, /* Interrupt ID:191, tgi4bi_pls_n */
    Default_Handler, /* Interrupt ID:192, tgi4ci_pls_n */
    Default_Handler, /* Interrupt ID:193, tgi4di_pls_n */
    Default_Handler, /* Interrupt ID:194, tci4vi_pls_n */
    Default_Handler, /* Interrupt ID:195, tgi5ui_pls_n */
    Default_Handler, /* Interrupt ID:196, tgi5vi_pls_n */
    Default_Handler, /* Interrupt ID:197, tgi5wi_pls_n */
    Default_Handler, /* Interrupt ID:198, tgi6ai_pls_n */
    Default_Handler, /* Interrupt ID:199, tgi6bi_pls_n */
    Default_Handler, /* Interrupt ID:200, tgi6ci_pls_n */
    Default_Handler, /* Interrupt ID:201, tgi6di_pls_n */
    Default_Handler, /* Interrupt ID:202, tci6vi_pls_n */
    Default_Handler, /* Interrupt ID:203, tgi7ai_pls_n */
    Default_Handler, /* Interrupt ID:204, tgi7bi_pls_n */
    Default_Handler, /* Interrupt ID:205, tgi7ci_pls_n */
    Default_Handler, /* Interrupt ID:206, tgi7di_pls_n */
    Default_Handler, /* Interrupt ID:207, tci7vi_pls_n */
    Default_Handler, /* Interrupt ID:208, tgi8a_pls_n */
    Default_Handler, /* Interrupt ID:209, tgi8b_pls_n */
    Default_Handler, /* Interrupt ID:210, tgi8c_pls_n */
    Default_Handler, /* Interrupt ID:211, tgi8d_pls_n */
    Default_Handler, /* Interrupt ID:212, tci8v_pls_n */
    Default_Handler, /* Interrupt ID:213, tci8u_pls_n */
    Default_Handler, /* Interrupt ID:214, poe_oei1_n */
    Default_Handler, /* Interrupt ID:215, poe_oei2_n */
    Default_Handler, /* Interrupt ID:216, poe_oei3_n */
    Default_Handler, /* Interrupt ID:217, poe_oei4_n */
    Default_Handler, /* Interrupt ID:218, gpt_gtcia_n[0] */
    Default_Handler, /* Interrupt ID:219, gpt_gtcib_n[0] */
    Default_Handler, /* Interrupt ID:220, gpt_gtcic_n[0] */
    Default_Handler, /* Interrupt ID:221, gpt_gtcid_n[0] */
    Default_Handler, /* Interrupt ID:222, gpt_gtcie_n[0] */
    Default_Handler, /* Interrupt ID:223, gpt_gtcif_n[0] */
    Default_Handler, /* Interrupt ID:224, gpt_gtciada_n[0] */
    Default_Handler, /* Interrupt ID:225, gpt_gtciadb_n[0] */
    Default_Handler, /* Interrupt ID:226, gpt_gtciv_n[0] */
    Default_Handler, /* Interrupt ID:227, gpt_gtciu_n[0] */
    Default_Handler, /* Interrupt ID:228, gpt_gtcih_n[0] */
    Default_Handler, /* Interrupt ID:229, gpt_gtcil_n[0] */
    Default_Handler, /* Interrupt ID:230, gpt_gtdei_n[0] */
    Default_Handler, /* Interrupt ID:231, gpt_gtcia_n[1] */
    Default_Handler, /* Interrupt ID:232, gpt_gtcib_n[1] */
    Default_Handler, /* Interrupt ID:233, gpt_gtcic_n[1] */
    Default_Handler, /* Interrupt ID:234, gpt_gtcid_n[1] */
    Default_Handler, /* Interrupt ID:235, gpt_gtcie_n[1] */
    Default_Handler, /* Interrupt ID:236, gpt_gtcif_n[1] */
    Default_Handler, /* Interrupt ID:237, gpt_gtciada_n[1] */
    Default_Handler, /* Interrupt ID:238, gpt_gtciadb_n[1] */
    Default_Handler, /* Interrupt ID:239, gpt_gtciv_n[1] */
    Default_Handler, /* Interrupt ID:240, gpt_gtciu_n[1] */
    Default_Handler, /* Interrupt ID:241, gpt_gtcih_n[1] */
    Default_Handler, /* Interrupt ID:242, gpt_gtcil_n[1] */
    Default_Handler, /* Interrupt ID:243, gpt_gtdei_n[1] */
    Default_Handler, /* Interrupt ID:244, gpt_gtcia_n[2] */
    Default_Handler, /* Interrupt ID:245, gpt_gtcib_n[2] */
    Default_Handler, /* Interrupt ID:246, gpt_gtcic_n[2] */
    Default_Handler, /* Interrupt ID:247, gpt_gtcid_n[2] */
    Default_Handler, /* Interrupt ID:248, gpt_gtcie_n[2] */
    Default_Handler, /* Interrupt ID:249, gpt_gtcif_n[2] */
    Default_Handler, /* Interrupt ID:250, gpt_gtciada_n[2] */
    Default_Handler, /* Interrupt ID:251, gpt_gtciadb_n[2] */
    Default_Handler, /* Interrupt ID:252, gpt_gtciv_n[2] */
    Default_Handler, /* Interrupt ID:253, gpt_gtciu_n[2] */
    Default_Handler, /* Interrupt ID:254, gpt_gtcih_n[2] */
    Default_Handler, /* Interrupt ID:255, gpt_gtcil_n[2] */
    Default_Handler, /* Interrupt ID:256, gpt_gtdei_n[2] */
    Default_Handler, /* Interrupt ID:257, gpt_gtcia_n[3] */
    Default_Handler, /* Interrupt ID:258, gpt_gtcib_n[3] */
    Default_Handler, /* Interrupt ID:259, gpt_gtcic_n[3] */
    Default_Handler, /* Interrupt ID:260, gpt_gtcid_n[3] */
    Default_Handler, /* Interrupt ID:261, gpt_gtcie_n[3] */
    Default_Handler, /* Interrupt ID:262, gpt_gtcif_n[3] */
    Default_Handler, /* Interrupt ID:263, gpt_gtciada_n[3] */
    Default_Handler, /* Interrupt ID:264, gpt_gtciadb_n[3] */
    Default_Handler, /* Interrupt ID:265, gpt_gtciv_n[3] */
    Default_Handler, /* Interrupt ID:266, gpt_gtciu_n[3] */
    Default_Handler, /* Interrupt ID:267, gpt_gtcih_n[3] */
    Default_Handler, /* Interrupt ID:268, gpt_gtcil_n[3] */
    Default_Handler, /* Interrupt ID:269, gpt_gtdei_n[3] */
    Default_Handler, /* Interrupt ID:270, gpt_gtcia_n[4] */
    Default_Handler, /* Interrupt ID:271, gpt_gtcib_n[4] */
    Default_Handler, /* Interrupt ID:272, gpt_gtcic_n[4] */
    Default_Handler, /* Interrupt ID:273, gpt_gtcid_n[4] */
    Default_Handler, /* Interrupt ID:274, gpt_gtcie_n[4] */
    Default_Handler, /* Interrupt ID:275, gpt_gtcif_n[4] */
    Default_Handler, /* Interrupt ID:276, gpt_gtciada_n[4] */
    Default_Handler, /* Interrupt ID:277, gpt_gtciadb_n[4] */
    Default_Handler, /* Interrupt ID:278, gpt_gtciv_n[4] */
    Default_Handler, /* Interrupt ID:279, gpt_gtciu_n[4] */
    Default_Handler, /* Interrupt ID:280, gpt_gtcih_n[4] */
    Default_Handler, /* Interrupt ID:281, gpt_gtcil_n[4] */
    Default_Handler, /* Interrupt ID:282, gpt_gtdei_n[4] */
    Default_Handler, /* Interrupt ID:283, gpt_gtcia_n[5] */
    Default_Handler, /* Interrupt ID:284, gpt_gtcib_n[5] */
    Default_Handler, /* Interrupt ID:285, gpt_gtcic_n[5] */
    Default_Handler, /* Interrupt ID:286, gpt_gtcid_n[5] */
    Default_Handler, /* Interrupt ID:287, gpt_gtcie_n[5] */
    Default_Handler, /* Interrupt ID:288, gpt_gtcif_n[5] */
    Default_Handler, /* Interrupt ID:289, gpt_gtciada_n[5] */
    Default_Handler, /* Interrupt ID:290, gpt_gtciadb_n[5] */
    Default_Handler, /* Interrupt ID:291, gpt_gtciv_n[5] */
    Default_Handler, /* Interrupt ID:292, gpt_gtciu_n[5] */
    Default_Handler, /* Interrupt ID:293, gpt_gtcih_n[5] */
    Default_Handler, /* Interrupt ID:294, gpt_gtcil_n[5] */
    Default_Handler, /* Interrupt ID:295, gpt_gtdei_n[5] */
    Default_Handler, /* Interrupt ID:296, gpt_gtcia_n[6] */
    Default_Handler, /* Interrupt ID:297, gpt_gtcib_n[6] */
    Default_Handler, /* Interrupt ID:298, gpt_gtcic_n[6] */
    Default_Handler, /* Interrupt ID:299, gpt_gtcid_n[6] */
    Default_Handler, /* Interrupt ID:300, gpt_gtcie_n[6] */
    Default_Handler, /* Interrupt ID:301, gpt_gtcif_n[6] */
    Default_Handler, /* Interrupt ID:302, gpt_gtciada_n[6] */
    Default_Handler, /* Interrupt ID:303, gpt_gtciadb_n[6] */
    Default_Handler, /* Interrupt ID:304, gpt_gtciv_n[6] */
    Default_Handler, /* Interrupt ID:305, gpt_gtciu_n[6] */
    Default_Handler, /* Interrupt ID:306, gpt_gtcih_n[6] */
    Default_Handler, /* Interrupt ID:307, gpt_gtcil_n[6] */
    Default_Handler, /* Interrupt ID:308, gpt_gtdei_n[6] */
    Default_Handler, /* Interrupt ID:309, gpt_gtcia_n[7] */
    Default_Handler, /* Interrupt ID:310, gpt_gtcib_n[7] */
    Default_Handler, /* Interrupt ID:311, gpt_gtcic_n[7] */
    Default_Handler, /* Interrupt ID:312, gpt_gtcid_n[7] */
    Default_Handler, /* Interrupt ID:313, gpt_gtcie_n[7] */
    Default_Handler, /* Interrupt ID:314, gpt_gtcif_n[7] */
    Default_Handler, /* Interrupt ID:315, gpt_gtciada_n[7] */
    Default_Handler, /* Interrupt ID:316, gpt_gtciadb_n[7] */
    Default_Handler, /* Interrupt ID:317, gpt_gtciv_n[7] */
    Default_Handler, /* Interrupt ID:318, gpt_gtciu_n[7] */
    Default_Handler, /* Interrupt ID:319, gpt_gtcih_n[7] */
    Default_Handler, /* Interrupt ID:320, gpt_gtcil_n[7] */
    Default_Handler, /* Interrupt ID:321, gpt_gtdei_n[7] */
    Default_Handler, /* Interrupt ID:322, mhc_elcoutdis */
    Default_Handler, /* Interrupt ID:323, mhc_elcoutdis */
    Default_Handler, /* Interrupt ID:324, mhc_elcoutdis */
    Default_Handler, /* Interrupt ID:325, mhc_elcoutdis */
    Default_Handler, /* Interrupt ID:326, INT_ssif_int_req */
    Default_Handler, /* Interrupt ID:327, INT_ssif_dma_rx */
    Default_Handler, /* Interrupt ID:328, INT_ssif_dma_tx */
    Default_Handler, /* Interrupt ID:329, INT_ssif_dma_rt */
    Default_Handler, /* Interrupt ID:330, INT_ssif_int_req */
    Default_Handler, /* Interrupt ID:331, INT_ssif_dma_rx */
    Default_Handler, /* Interrupt ID:332, INT_ssif_dma_tx */
    Default_Handler, /* Interrupt ID:333, INT_ssif_dma_rt */
    Default_Handler, /* Interrupt ID:334, INT_ssif_int_req */
    Default_Handler, /* Interrupt ID:335, INT_ssif_dma_rx */
    Default_Handler, /* Interrupt ID:336, INT_ssif_dma_tx */
    Default_Handler, /* Interrupt ID:337, INT_ssif_dma_rt */
    Default_Handler, /* Interrupt ID:338, INT_ssif_int_req */
    Default_Handler, /* Interrupt ID:339, INT_ssif_dma_rx */
    Default_Handler, /* Interrupt ID:340, INT_ssif_dma_tx */
    Default_Handler, /* Interrupt ID:341, INT_ssif_dma_rt */
    Default_Handler, /* Interrupt ID:342, intdma_src_idei_pls_n */
    Default_Handler, /* Interrupt ID:343, intdma_src_odfi_pls_n */
    Default_Handler, /* Interrupt ID:344, intreq_src_cef_n */
    Default_Handler, /* Interrupt ID:345, intreq_src_udf_n */
    Default_Handler, /* Interrupt ID:346, intreq_src_ovf_n */
    Default_Handler, /* Interrupt ID:347, INTAD */
    Default_Handler, /* Interrupt ID:348, ri_p */
    Default_Handler, /* Interrupt ID:349, ti_p */
    Default_Handler, /* Interrupt ID:350, tei_p */
    Default_Handler, /* Interrupt ID:351, naki_p */
    Default_Handler, /* Interrupt ID:352, spi_p */
    Default_Handler, /* Interrupt ID:353, sti_p */
    Default_Handler, /* Interrupt ID:354, ali_p */
    Default_Handler, /* Interrupt ID:355, tmoi_p */
    Default_Handler, /* Interrupt ID:356, ri_p */
    Default_Handler, /* Interrupt ID:357, ti_p */
    Default_Handler, /* Interrupt ID:358, tei_p */
    Default_Handler, /* Interrupt ID:359, naki_p */
    Default_Handler, /* Interrupt ID:360, spi_p */
    Default_Handler, /* Interrupt ID:361, sti_p */
    Default_Handler, /* Interrupt ID:362, ali_p */
    Default_Handler, /* Interrupt ID:363, tmoi_p */
    Default_Handler, /* Interrupt ID:364, ri_p */
    Default_Handler, /* Interrupt ID:365, ti_p */
    Default_Handler, /* Interrupt ID:366, tei_p */
    Default_Handler, /* Interrupt ID:367, naki_p */
    Default_Handler, /* Interrupt ID:368, spi_p */
    Default_Handler, /* Interrupt ID:369, sti_p */
    Default_Handler, /* Interrupt ID:370, ali_p */
    Default_Handler, /* Interrupt ID:371, tmoi_p */
    Default_Handler, /* Interrupt ID:372, ri_p */
    Default_Handler, /* Interrupt ID:373, ti_p */
    Default_Handler, /* Interrupt ID:374, tei_p */
    Default_Handler, /* Interrupt ID:375, naki_p */
    Default_Handler, /* Interrupt ID:376, spi_p */
    Default_Handler, /* Interrupt ID:377, sti_p */
    Default_Handler, /* Interrupt ID:378, ali_p */
    Default_Handler, /* Interrupt ID:379, tmoi_p */
    Default_Handler, /* Interrupt ID:380, ub1_rerr_n */
    Default_Handler, /* Interrupt ID:381, ub1_brk_n */
    Default_Handler, /* Interrupt ID:382, ub1_rxi_n */
    Default_Handler, /* Interrupt ID:383, ub1_txi_n */
    Default_Handler, /* Interrupt ID:384, ub1_tei_dri_n */
    Default_Handler, /* Interrupt ID:385, ub1_rerr_n */
    Default_Handler, /* Interrupt ID:386, ub1_brk_n */
    Default_Handler, /* Interrupt ID:387, ub1_rxi_n */
    Default_Handler, /* Interrupt ID:388, ub1_txi_n */
    Default_Handler, /* Interrupt ID:389, ub1_tei_dri_n */
    Default_Handler, /* Interrupt ID:390, ub1_rerr_n */
    Default_Handler, /* Interrupt ID:391, ub1_brk_n */
    Default_Handler, /* Interrupt ID:392, ub1_rxi_n */
    Default_Handler, /* Interrupt ID:393, ub1_txi_n */
    Default_Handler, /* Interrupt ID:394, ub1_tei_dri_n */
    Default_Handler, /* Interrupt ID:395, ub1_rerr_n */
    Default_Handler, /* Interrupt ID:396, ub1_brk_n */
    Default_Handler, /* Interrupt ID:397, ub1_rxi_n */
    Default_Handler, /* Interrupt ID:398, ub1_txi_n */
    Default_Handler, /* Interrupt ID:399, ub1_tei_dri_n */
    Default_Handler, /* Interrupt ID:400, ub1_rerr_n */
    Default_Handler, /* Interrupt ID:401, ub1_brk_n */
    Default_Handler, /* Interrupt ID:402, ub1_rxi_n */
    Default_Handler, /* Interrupt ID:403, ub1_txi_n */
    Default_Handler, /* Interrupt ID:404, ub1_tei_dri_n */
    Default_Handler, /* Interrupt ID:405, sc_eri_n */
    Default_Handler, /* Interrupt ID:406, sc_rxi_n */
    Default_Handler, /* Interrupt ID:407, sc_txi_n */
    Default_Handler, /* Interrupt ID:408, sc_tei_n */
    Default_Handler, /* Interrupt ID:409, sc_eri_n */
    Default_Handler, /* Interrupt ID:410, sc_rxi_n */
    Default_Handler, /* Interrupt ID:411, sc_txi_n */
    Default_Handler, /* Interrupt ID:412, sc_tei_n */
    Default_Handler, /* Interrupt ID:413, sp_rxint_n */
    Default_Handler, /* Interrupt ID:414, sp_txint_n */
    Default_Handler, /* Interrupt ID:415, sp_errint_n */
    Default_Handler, /* Interrupt ID:416, sp_rxint_n */
    Default_Handler, /* Interrupt ID:417, sp_txint_n */
    Default_Handler, /* Interrupt ID:418, sp_errint_n */
    Default_Handler, /* Interrupt ID:419, sp_rxint_n */
    Default_Handler, /* Interrupt ID:420, sp_txint_n */
    Default_Handler, /* Interrupt ID:421, sp_errint_n */
    Default_Handler, /* Interrupt ID:422, can_cherr_int[0]  */
    Default_Handler, /* Interrupt ID:423, can_cherr_int[1] */
    Default_Handler, /* Interrupt ID:424, can_comfrx_int[0]  */
    Default_Handler, /* Interrupt ID:425, can_comfrx_int[1] */
    Default_Handler, /* Interrupt ID:426, can_glerr_int  */
    Default_Handler, /* Interrupt ID:427, can_rxf_int  */
    Default_Handler, /* Interrupt ID:428, can_tx_int[0]  */
    Default_Handler, /* Interrupt ID:429, can_tx_int[1] */
    Default_Handler, /* Interrupt ID:430, WRRDYB_1_G */
    Default_Handler, /* Interrupt ID:431, WRRDYB_0_G */
    Default_Handler, /* Interrupt ID:432, WRRDYB_4_G */
    Default_Handler, /* Interrupt ID:433, RDRDYB_1_G */
    Default_Handler, /* Interrupt ID:434, RDRDYB_0_G */
    Default_Handler, /* Interrupt ID:435, ROM_OK_G */
    Default_Handler, /* Interrupt ID:436, LONG_PLGB_G */
    Default_Handler, /* Interrupt ID:437, PROC_BUSYB_G */
    Default_Handler, /* Interrupt ID:438, INTEGRATE_RDRDYB_G */
    Default_Handler, /* Interrupt ID:439, INTEGRATE_WRRDYB_G */
    Default_Handler, /* Interrupt ID:440, Reserved */
    Default_Handler, /* Interrupt ID:441, Reserved */
    Default_Handler, /* Interrupt ID:442, Reserved */
    Default_Handler, /* Interrupt ID:443, Reserved */
    Default_Handler, /* Interrupt ID:444, TINT0 */
    Default_Handler, /* Interrupt ID:445, TINT1 */
    Default_Handler, /* Interrupt ID:446, TINT2 */
    Default_Handler, /* Interrupt ID:447, TINT3 */
    Default_Handler, /* Interrupt ID:448, TINT4 */
    Default_Handler, /* Interrupt ID:449, TINT5 */
    Default_Handler, /* Interrupt ID:450, TINT6 */
    Default_Handler, /* Interrupt ID:451, TINT7 */
    Default_Handler, /* Interrupt ID:452, TINT8 */
    Default_Handler, /* Interrupt ID:453, TINT9 */
    Default_Handler, /* Interrupt ID:454, TINT10 */
    Default_Handler, /* Interrupt ID:455, TINT11 */
    Default_Handler, /* Interrupt ID:456, TINT12 */
    Default_Handler, /* Interrupt ID:457, TINT13 */
    Default_Handler, /* Interrupt ID:458, TINT14 */
    Default_Handler, /* Interrupt ID:459, TINT15 */
    Default_Handler, /* Interrupt ID:460, TINT16 */
    Default_Handler, /* Interrupt ID:461, TINT17 */
    Default_Handler, /* Interrupt ID:462, TINT18 */
    Default_Handler, /* Interrupt ID:463, TINT19 */
    Default_Handler, /* Interrupt ID:464, TINT20 */
    Default_Handler, /* Interrupt ID:465, TINT21 */
    Default_Handler, /* Interrupt ID:466, TINT22 */
    Default_Handler, /* Interrupt ID:467, TINT23 */
    Default_Handler, /* Interrupt ID:468, TINT24 */
    Default_Handler, /* Interrupt ID:469, TINT25 */
    Default_Handler, /* Interrupt ID:470, TINT26 */
    Default_Handler, /* Interrupt ID:471, TINT27 */
    Default_Handler, /* Interrupt ID:472, TINT28 */
    Default_Handler, /* Interrupt ID:473, TINT29 */
    Default_Handler, /* Interrupt ID:474, TINT30 */
    Default_Handler, /* Interrupt ID:475, TINT31 */
    Default_Handler, /* Interrupt ID:476, Reserved */
    Default_Handler, /* Interrupt ID:477, Reserved */
    Default_Handler, /* Interrupt ID:478, Reserved */
    Default_Handler, /* Interrupt ID:479, Reserved */
};

/***********************************************************************************************************************
 * Private global variables and functions
 **********************************************************************************************************************/
 
/** @} (end addtogroup BSP_MCU_PRV) */
