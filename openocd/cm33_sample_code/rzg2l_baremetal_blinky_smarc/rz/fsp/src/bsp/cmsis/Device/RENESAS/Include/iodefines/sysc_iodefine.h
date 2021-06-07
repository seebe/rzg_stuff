/* =========================================================================================================================== */
/* ================                              Device Specific Cluster Section                              ================ */
/* =========================================================================================================================== */

/* =========================================================================================================================== */
/* ================                            Device Specific Peripheral Section                             ================ */
/* =========================================================================================================================== */

#ifndef SYSC_IODEFINE_H
#define SYSC_IODEFINE_H

typedef struct
{
    union
    {
        __IOM uint32_t SYS_RAM0_ECC;
        struct
        {
            __IOM uint32_t VECCEN:1;
            uint32_t :31;
        } SYS_RAM0_ECC_b;
    };
    union
    {
        __IOM uint32_t SYS_RAM0_EN;
        struct
        {
            __IOM uint32_t VCEN:1;
            __IOM uint32_t VLWEN:1;
            uint32_t :30;
        } SYS_RAM0_EN_b;
    };
    __IM uint8_t        RESERVED[8];
    union
    {
        __IOM uint32_t SYS_RAM1_ECC;
        struct
        {
            __IOM uint32_t VECCEN:1;
            uint32_t :31;
        } SYS_RAM1_ECC_b;
    };
    union
    {
        __IOM uint32_t SYS_RAM1_EN;
        struct
        {
            __IOM uint32_t VCEN:1;
            __IOM uint32_t VLWEN:1;
            uint32_t :30;
        } SYS_RAM1_EN_b;
    };
    __IM uint8_t        RESERVED1[8];
    union
    {
        __IOM uint32_t SYS_WDT0_CTRL;
        struct
        {
            __IOM uint32_t WDTSTOP:1;
            uint32_t :31;
        } SYS_WDT0_CTRL_b;
    };
    __IM uint8_t        RESERVED2[12];
    union
    {
        __IOM uint32_t SYS_WDT1_CTRL;
        struct
        {
            __IOM uint32_t WDTSTOP:1;
            uint32_t :31;
        } SYS_WDT1_CTRL_b;
    };
    __IM uint8_t        RESERVED3[12];
    union
    {
        __IOM uint32_t SYS_WDT2_CTRL;
        struct
        {
            __IOM uint32_t WDTSTOP:1;
            uint32_t :31;
        } SYS_WDT2_CTRL_b;
    };
    __IM uint8_t        RESERVED4[236];
    union
    {
        __IM uint32_t SYS_GETH0_CFG;
        struct
        {
            uint32_t :24;
            __IM uint32_t FEC_GIGA_ENABLE:1;
            uint32_t :7;
        } SYS_GETH0_CFG_b;
    };
    __IM uint8_t        RESERVED5[12];
    union
    {
        __IM uint32_t SYS_GETH1_CFG;
        struct
        {
            uint32_t :24;
            __IM uint32_t FEC_GIGA_ENABLE:1;
            uint32_t :7;
        } SYS_GETH1_CFG_b;
    };
    __IM uint8_t        RESERVED6[188];
    union
    {
        __IOM uint32_t SYS_I2C0_CFG;
        struct
        {
            __IOM uint32_t af_bypass:1;
            uint32_t :31;
        } SYS_I2C0_CFG_b;
    };
    __IM uint8_t        RESERVED7[12];
    union
    {
        __IOM uint32_t SYS_I2C1_CFG;
        struct
        {
            __IOM uint32_t af_bypass:1;
            uint32_t :31;
        } SYS_I2C1_CFG_b;
    };
    __IM uint8_t        RESERVED8[12];
    union
    {
        __IOM uint32_t SYS_I2C2_CFG;
        struct
        {
            __IOM uint32_t af_bypass:1;
            uint32_t :31;
        } SYS_I2C2_CFG_b;
    };
    __IM uint8_t        RESERVED9[12];
    union
    {
        __IOM uint32_t SYS_I2C3_CFG;
        struct
        {
            __IOM uint32_t af_bypass:1;
            uint32_t :31;
        } SYS_I2C3_CFG_b;
    };
    __IM uint8_t        RESERVED10[976];
    union
    {
        __IOM uint32_t SYS_CM33_CFG0;
        struct
        {
            __IOM uint32_t CONFIGSSYSTICK:26;
            uint32_t :6;
        } SYS_CM33_CFG0_b;
    };
    union
    {
        __IOM uint32_t SYS_CM33_CFG1;
        struct
        {
            __IOM uint32_t CONFIGNSSYSTICK:26;
            uint32_t :6;
        } SYS_CM33_CFG1_b;
    };
    union
    {
        __IOM uint32_t SYS_CM33_CFG2;
        struct
        {
            uint32_t :7;
            __IOM uint32_t INITSVTOR:25;
        } SYS_CM33_CFG2_b;
    };
    union
    {
        __IOM uint32_t SYS_CM33_CFG3;
        struct
        {
            uint32_t :7;
            __IOM uint32_t INITNSVTOR:25;
        } SYS_CM33_CFG3_b;
    };
    union
    {
        __IOM uint32_t SYS_CM33_LOCK;
        struct
        {
            __IOM uint32_t LOCKSVTAIRCR:1;
            __IOM uint32_t LOCKNSVTOR:1;
            uint32_t :30;
        } SYS_CM33_LOCK_b;
    };
    __IM uint8_t        RESERVED11[64];
    union
    {
        __IOM uint32_t SYS_CA55_CFG_RVAL0;
        struct
        {
            uint32_t :2;
            __IOM uint32_t RVBARADDRL0:30;
        } SYS_CA55_CFG_RVAL0_b;
    };
    union
    {
        __IOM uint32_t SYS_CA55_CFG_RVAH0;
        struct
        {
            __IOM uint32_t RVBARADDRH0:8;
            uint32_t :24;
        } SYS_CA55_CFG_RVAH0_b;
    };
    union
    {
        __IOM uint32_t SYS_CA55_CFG_RVAL1;
        struct
        {
            uint32_t :2;
            __IOM uint32_t RVBARADDRL1:30;
        } SYS_CA55_CFG_RVAL1_b;
    };
    union
    {
        __IOM uint32_t SYS_CA55_CFG_RVAH1;
        struct
        {
            __IOM uint32_t RVBARADDRH1:8;
            uint32_t :24;
        } SYS_CA55_CFG_RVAH1_b;
    };
    __IM uint8_t        RESERVED12[408];
    union
    {
        __IM uint32_t SYS_LSI_MODE;
        struct
        {
            __IM uint32_t STAT_MD_BOOT:3;
            uint32_t :5;
            uint32_t :1;
            __IM uint32_t STAT_DEBUGEN:1;
            uint32_t :2;
            __IM uint32_t STAT_MD_CLKS:1;
            uint32_t :1;
            __IM uint32_t STAT_MD_OSCDRV:2;
            uint32_t :16;
        } SYS_LSI_MODE_b;
    };
    __IM uint8_t        RESERVED13[508];
    union
    {
        __IOM uint32_t SYS_AOF0;
        struct
        {
            __IOM uint32_t OFS00_SXSDHI_0:4;
            __IOM uint32_t OFS01_SXSDHI_0:4;
            __IOM uint32_t OFS10_SXSDHI_0:4;
            __IOM uint32_t OFS11_SXSDHI_0:4;
            __IOM uint32_t OFS00_SXSDHI_1:4;
            __IOM uint32_t OFS01_SXSDHI_1:4;
            __IOM uint32_t OFS10_SXSDHI_1:4;
            __IOM uint32_t OFS11_SXSDHI_1:4;
        } SYS_AOF0_b;
    };
    union
    {
        __IOM uint32_t SYS_AOF1;
        struct
        {
            __IOM uint32_t OFS00_SXGIGE_0:4;
            __IOM uint32_t OFS01_SXGIGE_0:4;
            __IOM uint32_t OFS10_SXGIGE_0:4;
            __IOM uint32_t OFS11_SXGIGE_0:4;
            __IOM uint32_t OFS00_SXGIGE_1:4;
            __IOM uint32_t OFS01_SXGIGE_1:4;
            __IOM uint32_t OFS10_SXGIGE_1:4;
            __IOM uint32_t OFS11_SXGIGE_1:4;
        } SYS_AOF1_b;
    };
    union
    {
        __IOM uint32_t SYS_AOF2;
        struct
        {
            __IOM uint32_t OFS00_SXUSB2_0_H:4;
            __IOM uint32_t OFS01_SXUSB2_0_H:4;
            __IOM uint32_t OFS10_SXUSB2_0_H:4;
            __IOM uint32_t OFS11_SXUSB2_0_H:4;
            __IOM uint32_t OFS00_SXUSB2_1:4;
            __IOM uint32_t OFS01_SXUSB2_1:4;
            __IOM uint32_t OFS10_SXUSB2_1:4;
            __IOM uint32_t OFS11_SXUSB2_1:4;
        } SYS_AOF2_b;
    };
    union
    {
        __IOM uint32_t SYS_AOF3;
        struct
        {
            __IOM uint32_t OFS00_SXUSB2_0_F:4;
            __IOM uint32_t OFS01_SXUSB2_0_F:4;
            __IOM uint32_t OFS10_SXUSB2_0_F:4;
            __IOM uint32_t OFS11_SXUSB2_0_F:4;
            uint32_t :16;
        } SYS_AOF3_b;
    };
    union
    {
        __IOM uint32_t SYS_AOF4;
        struct
        {
            __IOM uint32_t OFS00_SXLCDC:4;
            __IOM uint32_t OFS01_SXLCDC:4;
            __IOM uint32_t OFS10_SXLCDC:4;
            __IOM uint32_t OFS11_SXLCDC:4;
            __IOM uint32_t OFS00_SXDSIL:4;
            __IOM uint32_t OFS01_SXDSIL:4;
            __IOM uint32_t OFS10_SXDSIL:4;
            __IOM uint32_t OFS11_SXDSIL:4;
        } SYS_AOF4_b;
    };
    union
    {
        __IOM uint32_t SYS_AOF5;
        struct
        {
            __IOM uint32_t OFS00_SXH264:4;
            __IOM uint32_t OFS01_SXH264:4;
            __IOM uint32_t OFS10_SXH264:4;
            __IOM uint32_t OFS11_SXH264:4;
            uint32_t :16;
        } SYS_AOF5_b;
    };
    union
    {
        __IOM uint32_t SYS_AOF6;
        struct
        {
            __IOM uint32_t OFS00_SXDMAC_S:4;
            __IOM uint32_t OFS01_SXDMAC_S:4;
            __IOM uint32_t OFS10_SXDMAC_S:4;
            __IOM uint32_t OFS11_SXDMAC_S:4;
            __IOM uint32_t OFS00_SXDMAC_NS:4;
            __IOM uint32_t OFS01_SXDMAC_NS:4;
            __IOM uint32_t OFS10_SXDMAC_NS:4;
            __IOM uint32_t OFS11_SXDMAC_NS:4;
        } SYS_AOF6_b;
    };
    __IM uint8_t        RESERVED14[228];
    union
    {
        __IOM uint32_t SYS_LP_CTL0;
        struct
        {
            __IOM uint32_t MAIN_CPU:1;
            uint32_t :31;
        } SYS_LP_CTL0_b;
    };
    union
    {
        __IOM uint32_t SYS_LP_CTL1;
        struct
        {
            __IOM uint32_t STBY:1;
            uint32_t :7;
            __IOM uint32_t CA55SLEEP_REQ:2;
            uint32_t :2;
            __IOM uint32_t CM33SLEEP_REQ:1;
            uint32_t :3;
            __IM uint32_t STBY_CA55ST:1;
            __IM uint32_t STBY_CM33ST:1;
            uint32_t :6;
            __IOM uint32_t CA55SLEEP_ACK:2;
            uint32_t :2;
            __IOM uint32_t CM33SLEEP_ACK:1;
            uint32_t :3;
        } SYS_LP_CTL1_b;
    };
    union
    {
        __IOM uint32_t SYS_LP_CTL2;
        struct
        {
            __IOM uint32_t CA55_STBYCTL:1;
            uint32_t :31;
        } SYS_LP_CTL2_b;
    };
    union
    {
        __IOM uint32_t SYS_LP_CTL3;
        struct
        {
            __IOM uint32_t U0DP_F:1;
            __IOM uint32_t U0DM_F:1;
            __IOM uint32_t U0VBUSIN_F:1;
            __IOM uint32_t U0OVRCLR_F:1;
            uint32_t :4;
            __IOM uint32_t U1DP_F:1;
            __IOM uint32_t U1DM_F:1;
            uint32_t :1;
            __IOM uint32_t U1OVRCLR_F:1;
            uint32_t :4;
            __IOM uint32_t IRQ_F70:8;
            __IOM uint32_t NMI_F:1;
            uint32_t :7;
        } SYS_LP_CTL3_b;
    };
    union
    {
        __IOM uint32_t SYS_LP_CTL4;
        struct
        {
            __IOM uint32_t U0DP_E:1;
            __IOM uint32_t U0DM_E:1;
            __IOM uint32_t U0VBUSIN_E:1;
            __IOM uint32_t U0OVRCLR_E:1;
            uint32_t :4;
            __IOM uint32_t U1DP_E:1;
            __IOM uint32_t U1DM_E:1;
            uint32_t :1;
            __IOM uint32_t U1OVRCLR_E:1;
            uint32_t :4;
            __IOM uint32_t IRQ_E0:1;
            __IOM uint32_t IRQ_E1:1;
            __IOM uint32_t IRQ_E2:1;
            __IOM uint32_t IRQ_E3:1;
            __IOM uint32_t IRQ_E4:1;
            __IOM uint32_t IRQ_E5:1;
            __IOM uint32_t IRQ_E6:1;
            __IOM uint32_t IRQ_E7:1;
            __IOM uint32_t NMI_E:1;
            uint32_t :7;
        } SYS_LP_CTL4_b;
    };
    union
    {
        __IOM uint32_t SYS_LP_CTL5;
        struct
        {
            uint32_t :1;
            __IOM uint32_t ASCLKQDENY_F:1;
            __IOM uint32_t AMCLKQDENY_F:1;
            uint32_t :1;
            __IOM uint32_t STBY_F:1;
            uint32_t :3;
            __IOM uint32_t CA55SLEEP0_F:1;
            __IOM uint32_t CA55SLEEP1_F:1;
            __IOM uint32_t CM33SLEEP_F:1;
            uint32_t :5;
            __IM uint32_t CA55STBYDONE_F:1;
            uint32_t :3;
            __IM uint32_t CM33STBYR_F:1;
            uint32_t :11;
        } SYS_LP_CTL5_b;
    };
    union
    {
        __IOM uint32_t SYS_LP_CTL6;
        struct
        {
            uint32_t :1;
            __IOM uint32_t ASCLKQDENY_E:1;
            __IOM uint32_t AMCLKQDENY_E:1;
            uint32_t :1;
            __IOM uint32_t STBY_E:1;
            __IOM uint32_t CA55STBYDONE_E:1;
            __IOM uint32_t CM33STBYR_E:1;
            uint32_t :1;
            __IOM uint32_t CA55SLEEP0_E:1;
            __IOM uint32_t CA55SLEEP1_E:1;
            __IOM uint32_t CM33SLEEP_E:1;
            uint32_t :21;
        } SYS_LP_CTL6_b;
    };
    union
    {
        __IOM uint32_t SYS_LP_CTL7;
        struct
        {
            __IOM uint32_t IM33_MASK:1;
            uint32_t :31;
        } SYS_LP_CTL7_b;
    };
    union
    {
        __IOM uint32_t SYS_LP_CTL8;
        struct
        {
            __IOM uint32_t SUBCPU_RTRIG:1;
            uint32_t :31;
        } SYS_LP_CTL8_b;
    };
    union
    {
        __IOM uint32_t SYS_LP_CM33CTL0;
        struct
        {
            __IM uint32_t SLEEPMODE:1;
            uint32_t :3;
            __IM uint32_t SLEEPDEEP:1;
            uint32_t :4;
            __IM uint32_t SYSRESETREQ:1;
            uint32_t :14;
            __IOM uint32_t WICENABLEREQ:1;
            __IM uint32_t WICENABLEACK:1;
            uint32_t :6;
        } SYS_LP_CM33CTL0_b;
    };
    __IM uint8_t        RESERVED15[4];
    __IM uint8_t        RESERVED16[12];
    union
    {
        __IM uint32_t SYS_LP_CA55CK_CTL1;
        struct
        {
            uint32_t :1;
            __IM uint32_t ASCLKQACTIVE:1;
            __IM uint32_t AMCLKQACTIVE:1;
            uint32_t :5;
            __IM uint32_t PCLKQACTIVE:1;
            __IM uint32_t ATCLKQACTIVE:1;
            __IM uint32_t GICCLKQACTIVE:1;
            __IM uint32_t PDBGCLKQACTIVE:1;
            uint32_t :20;
        } SYS_LP_CA55CK_CTL1_b;
    };
    union
    {
        __IOM uint32_t SYS_LP_CA55CK_CTL2;
        struct
        {
            uint32_t :1;
            __IOM uint32_t ASCLKQREQn:1;
            __IOM uint32_t AMCLKQREQn:1;
            uint32_t :5;
            __IOM uint32_t PCLKQREQn:1;
            __IOM uint32_t ATCLKQREQn:1;
            __IOM uint32_t GICCLKQREQn:1;
            __IOM uint32_t PDBGCLKQREQn:1;
            uint32_t :20;
        } SYS_LP_CA55CK_CTL2_b;
    };
    union
    {
        __IM uint32_t SYS_LP_CA55CK_CTL3;
        struct
        {
            __IM uint32_t CA55_COREINSTRRUN0:1;
            __IM uint32_t ASCLKQACCEPTn:1;
            __IM uint32_t AMCLKQACCEPTn:1;
            uint32_t :5;
            __IM uint32_t PCLKQACCEPTn:1;
            __IM uint32_t ATCLKQACCEPTn:1;
            __IM uint32_t GICCLKQACCEPTn:1;
            __IM uint32_t PDBGCLKQACCEPTn:1;
            uint32_t :4;
            __IM uint32_t CA55_COREINSTRRUN1:1;
            __IM uint32_t ASCLKQDENY:1;
            __IM uint32_t AMCLKQDENY:1;
            uint32_t :5;
            __IM uint32_t PCLKQDENY:1;
            __IM uint32_t ATCLKQDENY:1;
            __IM uint32_t GICCLKQDENY:1;
            __IM uint32_t PDBGCLKQDENY:1;
            uint32_t :4;
        } SYS_LP_CA55CK_CTL3_b;
    };
    __IM uint8_t        RESERVED17[12];
    union
    {
        __IOM uint32_t SYS_LP_GPU_CTL;
        struct
        {
            __IM uint32_t QACTIVE_GPU:1;
            __IM uint32_t QACTIVE_AXI_SLV:1;
            __IM uint32_t QACTIVE_AXI_MST:1;
            __IM uint32_t QACTIVE_ACE_SLV:1;
            __IM uint32_t QACTIVE_ACE_MST:1;
            uint32_t :3;
            __IOM uint32_t QREQn_GPU:1;
            __IOM uint32_t QREQn_AXI_SLV:1;
            __IOM uint32_t QREQn_AXI_MST:1;
            __IOM uint32_t QREQn_ACE_SLV:1;
            __IOM uint32_t QREQn_ACE_MST:1;
            uint32_t :3;
            __IM uint32_t QACCEPTn_GPU:1;
            __IM uint32_t QACCEPTn_AXI_SLV:1;
            __IM uint32_t QACCEPTn_AXI_MST:1;
            __IM uint32_t QACCEPTn_ACE_SLV:1;
            __IM uint32_t QACCEPTn_ACE_MST:1;
            uint32_t :3;
            __IM uint32_t QDENY_GPU:1;
            __IM uint32_t QDENY_AXI_SLV:1;
            __IM uint32_t QDENY_AXI_MST:1;
            __IM uint32_t QDENY_ACE_SLV:1;
            __IM uint32_t QDENY_ACE_MST:1;
            uint32_t :3;
        } SYS_LP_GPU_CTL_b;
    };
    __IM uint8_t        RESERVED18[172];
    union
    {
        __IOM uint32_t SYS_GPREG_0;
        struct
        {
            __IOM uint32_t GPREG0:32;
        } SYS_GPREG_0_b;
    };
    union
    {
        __IOM uint32_t SYS_GPREG_1;
        struct
        {
            __IOM uint32_t GPREG1:32;
        } SYS_GPREG_1_b;
    };
    union
    {
        __IOM uint32_t SYS_GPREG_2;
        struct
        {
            __IOM uint32_t GPREG2:32;
        } SYS_GPREG_2_b;
    };
    union
    {
        __IOM uint32_t SYS_GPREG_3;
        struct
        {
            __IOM uint32_t GPREG3:32;
        } SYS_GPREG_3_b;
    };
} R_SYSC_Type;

/* =========================================================================================================================== */
/* ================                          Device Specific Peripheral Address Map                           ================ */
/* =========================================================================================================================== */

#define R_SYSC_BASE     0x41020200

/* =========================================================================================================================== */
/* ================                                  Peripheral declaration                                   ================ */
/* =========================================================================================================================== */

#define R_SYSC     ((R_SYSC_Type     *) R_SYSC_BASE)

#endif
