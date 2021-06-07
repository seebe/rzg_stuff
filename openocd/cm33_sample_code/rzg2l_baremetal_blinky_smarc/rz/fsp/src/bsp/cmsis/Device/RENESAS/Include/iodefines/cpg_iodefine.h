/* =========================================================================================================================== */
/* ================                              Device Specific Cluster Section                              ================ */
/* =========================================================================================================================== */

/* =========================================================================================================================== */
/* ================                            Device Specific Peripheral Section                             ================ */
/* =========================================================================================================================== */

#ifndef CPG_IODEFINE_H
#define CPG_IODEFINE_H

typedef struct
{
    union
    {
        __IOM uint32_t CPG_PLL1_STBY;
        struct
        {
            __IOM uint32_t RESETB:1;
            uint32_t :1;
            __IOM uint32_t SSC_EN:1;
            uint32_t :1;
            __IOM uint32_t SSC_MODE:2;
            uint32_t :10;
            __IOM uint32_t RESETB_WEN:1;
            uint32_t :1;
            __IOM uint32_t SSC_EN_WEN:1;
            uint32_t :1;
            __IOM uint32_t SSC_MODE_WEN:1;
            uint32_t :11;
        } CPG_PLL1_STBY_b;
    };
    union
    {
        __IOM uint32_t CPG_PLL1_CLK1;
        struct
        {
            __IOM uint32_t DIV_P:6;
            __IOM uint32_t DIV_M:10;
            __IOM uint32_t DIV_K:16;
        } CPG_PLL1_CLK1_b;
    };
    union
    {
        __IOM uint32_t CPG_PLL1_CLK2;
        struct
        {
            __IOM uint32_t DIV_S:3;
            uint32_t :5;
            __IOM uint32_t MRR:6;
            uint32_t :2;
            __IOM uint32_t MFR:8;
            uint32_t :8;
        } CPG_PLL1_CLK2_b;
    };
    union
    {
        __IM uint32_t CPG_PLL1_MON;
        struct
        {
            __IM uint32_t PLL1_RESETB:1;
            uint32_t :3;
            __IM uint32_t PLL1_LOCK:1;
            uint32_t :27;
        } CPG_PLL1_MON_b;
    };
    union
    {
        __IOM uint32_t CPG_PLL4_STBY;
        struct
        {
            __IOM uint32_t RESETB:1;
            uint32_t :1;
            __IOM uint32_t SSC_EN:1;
            uint32_t :1;
            __IOM uint32_t SSC_MODE:2;
            uint32_t :10;
            __IOM uint32_t RESETB_WEN:1;
            uint32_t :1;
            __IOM uint32_t SSC_EN_WEN:1;
            uint32_t :1;
            __IOM uint32_t SSC_MODE_WEN:1;
            uint32_t :11;
        } CPG_PLL4_STBY_b;
    };
    union
    {
        __IOM uint32_t CPG_PLL4_CLK1;
        struct
        {
            __IOM uint32_t DIV_P:6;
            __IOM uint32_t DIV_M:10;
            __IOM uint32_t DIV_K:16;
        } CPG_PLL4_CLK1_b;
    };
    union
    {
        __IOM uint32_t CPG_PLL4_CLK2;
        struct
        {
            __IOM uint32_t DIV_S:3;
            uint32_t :5;
            __IOM uint32_t MRR:6;
            uint32_t :2;
            __IOM uint32_t MFR:8;
            uint32_t :8;
        } CPG_PLL4_CLK2_b;
    };
    union
    {
        __IM uint32_t CPG_PLL4_MON;
        struct
        {
            __IM uint32_t PLL4_RESETB:1;
            uint32_t :3;
            __IM uint32_t PLL4_LOCK:1;
            uint32_t :27;
        } CPG_PLL4_MON_b;
    };
    union
    {
        __IOM uint32_t CPG_PLL6_STBY;
        struct
        {
            __IOM uint32_t RESETB:1;
            uint32_t :1;
            __IOM uint32_t SSC_EN:1;
            uint32_t :1;
            __IOM uint32_t SSC_MODE:2;
            uint32_t :10;
            __IOM uint32_t RESETB_WEN:1;
            uint32_t :1;
            __IOM uint32_t SSC_EN_WEN:1;
            uint32_t :1;
            __IOM uint32_t SSC_MODE_WEN:1;
            uint32_t :11;
        } CPG_PLL6_STBY_b;
    };
    union
    {
        __IOM uint32_t CPG_PLL6_CLK1;
        struct
        {
            __IOM uint32_t DIV_P:6;
            __IOM uint32_t DIV_M:10;
            __IOM uint32_t DIV_K:16;
        } CPG_PLL6_CLK1_b;
    };
    union
    {
        __IOM uint32_t CPG_PLL6_CLK2;
        struct
        {
            __IOM uint32_t DIV_S:3;
            uint32_t :5;
            __IOM uint32_t MRR:6;
            uint32_t :2;
            __IOM uint32_t MFR:8;
            uint32_t :8;
        } CPG_PLL6_CLK2_b;
    };
    union
    {
        __IM uint32_t CPG_PLL6_MON;
        struct
        {
            __IM uint32_t PLL6_RESETB:1;
            uint32_t :3;
            __IM uint32_t PLL6_LOCK:1;
            uint32_t :27;
        } CPG_PLL6_MON_b;
    };
    __IM uint8_t        RESERVED[16];
    union
    {
        __IOM uint32_t CPG_PLL1_SETTING;
        struct
        {
            __IOM uint32_t SEL_PLL1:1;
            uint32_t :15;
            __IOM uint32_t SEL_PLL1_WEN:1;
            uint32_t :15;
        } CPG_PLL1_SETTING_b;
    };
    union
    {
        __IM uint32_t CPG_OTPPLL0_MON;
        struct
        {
            __IM uint32_t OTP0_MON:1;
            __IM uint32_t OTP1_MON:1;
            __IM uint32_t OTP2_MON:1;
            __IM uint32_t OTP3_MON:1;
            __IM uint32_t OTP4_MON:1;
            __IM uint32_t OTP5_MON:1;
            __IM uint32_t OTP6_MON:1;
            __IM uint32_t OTP7_MON:1;
            __IM uint32_t OTP8_MON:1;
            __IM uint32_t OTP9_MON:1;
            __IM uint32_t OTP10_MON:1;
            __IM uint32_t OTP11_MON:1;
            __IM uint32_t OTP12_MON:1;
            __IM uint32_t OTP13_MON:1;
            __IM uint32_t OTP14_MON:1;
            __IM uint32_t OTP15_MON:1;
            __IM uint32_t OTP16_MON:1;
            __IM uint32_t OTP17_MON:1;
            __IM uint32_t OTP18_MON:1;
            __IM uint32_t OTP19_MON:1;
            __IM uint32_t OTP20_MON:1;
            __IM uint32_t OTP21_MON:1;
            __IM uint32_t OTP22_MON:1;
            __IM uint32_t OTP23_MON:1;
            __IM uint32_t OTP24_MON:1;
            __IM uint32_t OTP25_MON:1;
            __IM uint32_t OTP26_MON:1;
            __IM uint32_t OTP27_MON:1;
            __IM uint32_t OTP28_MON:1;
            __IM uint32_t OTP29_MON:1;
            __IM uint32_t OTP30_MON:1;
            __IM uint32_t OTP31_MON:1;
        } CPG_OTPPLL0_MON_b;
    };
    union
    {
        __IM uint32_t CPG_OTPPLL1_MON;
        struct
        {
            __IM uint32_t OTP0_MON:1;
            __IM uint32_t OTP1_MON:1;
            __IM uint32_t OTP2_MON:1;
            __IM uint32_t OTP3_MON:1;
            __IM uint32_t OTP4_MON:1;
            __IM uint32_t OTP5_MON:1;
            __IM uint32_t OTP6_MON:1;
            __IM uint32_t OTP7_MON:1;
            __IM uint32_t OTP8_MON:1;
            __IM uint32_t OTP9_MON:1;
            __IM uint32_t OTP10_MON:1;
            __IM uint32_t OTP11_MON:1;
            __IM uint32_t OTP12_MON:1;
            __IM uint32_t OTP13_MON:1;
            __IM uint32_t OTP14_MON:1;
            __IM uint32_t OTP15_MON:1;
            __IM uint32_t OTP16_MON:1;
            __IM uint32_t OTP17_MON:1;
            __IM uint32_t OTP18_MON:1;
            __IM uint32_t OTP19_MON:1;
            __IM uint32_t OTP20_MON:1;
            __IM uint32_t OTP21_MON:1;
            __IM uint32_t OTP22_MON:1;
            __IM uint32_t OTP23_MON:1;
            __IM uint32_t OTP24_MON:1;
            __IM uint32_t OTP25_MON:1;
            __IM uint32_t OTP26_MON:1;
            __IM uint32_t OTP27_MON:1;
            __IM uint32_t OTP28_MON:1;
            __IM uint32_t OTP29_MON:1;
            __IM uint32_t OTP30_MON:1;
            __IM uint32_t OTP31_MON:1;
        } CPG_OTPPLL1_MON_b;
    };
    union
    {
        __IM uint32_t CPG_OTPPLL2_MON;
        struct
        {
            __IM uint32_t OTP0_MON:1;
            __IM uint32_t OTP1_MON:1;
            __IM uint32_t OTP2_MON:1;
            __IM uint32_t OTP3_MON:1;
            __IM uint32_t OTP4_MON:1;
            __IM uint32_t OTP5_MON:1;
            __IM uint32_t OTP6_MON:1;
            __IM uint32_t OTP7_MON:1;
            __IM uint32_t OTP8_MON:1;
            __IM uint32_t OTP9_MON:1;
            __IM uint32_t OTP10_MON:1;
            __IM uint32_t OTP11_MON:1;
            __IM uint32_t OTP12_MON:1;
            __IM uint32_t OTP13_MON:1;
            __IM uint32_t OTP14_MON:1;
            __IM uint32_t OTP15_MON:1;
            __IM uint32_t OTP16_MON:1;
            __IM uint32_t OTP17_MON:1;
            __IM uint32_t OTP18_MON:1;
            __IM uint32_t OTP19_MON:1;
            __IM uint32_t OTP20_MON:1;
            __IM uint32_t OTP21_MON:1;
            __IM uint32_t OTP22_MON:1;
            __IM uint32_t OTP23_MON:1;
            __IM uint32_t OTP24_MON:1;
            __IM uint32_t OTP25_MON:1;
            __IM uint32_t OTP26_MON:1;
            __IM uint32_t OTP27_MON:1;
            __IM uint32_t OTP28_MON:1;
            __IM uint32_t OTP29_MON:1;
            __IM uint32_t OTP30_MON:1;
            __IM uint32_t OTP31_MON:1;
        } CPG_OTPPLL2_MON_b;
    };
    __IM uint8_t        RESERVED1[204];
    union
    {
        __IM uint32_t CPG_PLL2_MON;
        struct
        {
            __IM uint32_t PLL2_RESETB:1;
            uint32_t :3;
            __IM uint32_t PLL2_LOCK:1;
            uint32_t :27;
        } CPG_PLL2_MON_b;
    };
    __IM uint8_t        RESERVED2[28];
    union
    {
        __IM uint32_t CPG_PLL3_MON;
        struct
        {
            __IM uint32_t PLL3_RESETB:1;
            uint32_t :3;
            __IM uint32_t PLL3_LOCK:1;
            uint32_t :27;
        } CPG_PLL3_MON_b;
    };
    union
    {
        __IOM uint32_t CPG_PLL5_STBY;
        struct
        {
            __IOM uint32_t RESETB:1;
            uint32_t :1;
            __IOM uint32_t SSC_EN:1;
            uint32_t :1;
            __IOM uint32_t DOWNSPREAD:1;
            uint32_t :11;
            __IOM uint32_t RESETB_WEN:1;
            uint32_t :1;
            __IOM uint32_t SSC_EN_WEN:1;
            uint32_t :1;
            __IOM uint32_t DOWNSPREAD_WEN:1;
            uint32_t :11;
        } CPG_PLL5_STBY_b;
    };
    union
    {
        __IOM uint32_t CPG_PLL5_CLK1;
        struct
        {
            __IOM uint32_t POSTDIV1:3;
            uint32_t :1;
            __IOM uint32_t POSTDIV2:3;
            uint32_t :1;
            __IOM uint32_t REFDIV:6;
            uint32_t :2;
            __IOM uint32_t POSTDIV1_WEN:1;
            uint32_t :3;
            __IOM uint32_t POSTDIV2_WEN:1;
            uint32_t :3;
            __IOM uint32_t REFDIV_WEN:1;
            uint32_t :7;
        } CPG_PLL5_CLK1_b;
    };
    union
    {
        __IOM uint32_t CPG_PLL5_CLK2;
        struct
        {
            __IOM uint32_t DACPD:1;
            uint32_t :1;
            __IOM uint32_t DSMPD:1;
            uint32_t :1;
            __IOM uint32_t FOUT4PHASEPD:1;
            uint32_t :1;
            __IOM uint32_t FOUTPOSTDIVPD:1;
            uint32_t :1;
            __IOM uint32_t FOUTVCOPD:1;
            uint32_t :7;
            __IOM uint32_t DACPD_WEN:1;
            uint32_t :1;
            __IOM uint32_t DSMPD_WEN:1;
            uint32_t :1;
            __IOM uint32_t FOUT4PHASEPD_WEN:1;
            uint32_t :1;
            __IOM uint32_t FOUTPOSTDIVPD_WEN:1;
            uint32_t :1;
            __IOM uint32_t FOUTVCOPD_WEN:1;
            uint32_t :7;
        } CPG_PLL5_CLK2_b;
    };
    union
    {
        __IOM uint32_t CPG_PLL5_CLK3;
        struct
        {
            __IOM uint32_t DIVVAL:6;
            uint32_t :2;
            __IOM uint32_t FRACIN:24;
        } CPG_PLL5_CLK3_b;
    };
    union
    {
        __IOM uint32_t CPG_PLL5_CLK4;
        struct
        {
            uint32_t :16;
            __IOM uint32_t INTIN:12;
            uint32_t :4;
        } CPG_PLL5_CLK4_b;
    };
    union
    {
        __IOM uint32_t CPG_PLL5_CLK5;
        struct
        {
            __IOM uint32_t SPREAD:5;
            uint32_t :27;
        } CPG_PLL5_CLK5_b;
    };
    __IM uint8_t        RESERVED3[4];
    union
    {
        __IM uint32_t CPG_PLL5_MON;
        struct
        {
            __IM uint32_t PLL5_RESETB:1;
            uint32_t :3;
            __IM uint32_t PLL5_LOCK:1;
            uint32_t :27;
        } CPG_PLL5_MON_b;
    };
    __IM uint8_t        RESERVED4[160];
    union
    {
        __IOM uint32_t CPG_PL1_DDIV;
        struct
        {
            __IOM uint32_t DIVPL1_SET:2;
            uint32_t :14;
            __IOM uint32_t DIV_PLL1SET_WEN:1;
            uint32_t :15;
        } CPG_PL1_DDIV_b;
    };
    union
    {
        __IOM uint32_t CPG_PL2_DDIV;
        struct
        {
            __IOM uint32_t DIVPL2A_SET:3;
            uint32_t :1;
            __IOM uint32_t DIVPL2B_SET:3;
            uint32_t :1;
            __IOM uint32_t DIVPL2C_SET:3;
            uint32_t :1;
            __IOM uint32_t DIVDSILPCLK_SET:2;
            uint32_t :2;
            __IOM uint32_t DIV_PLL2_A_WEN:1;
            uint32_t :3;
            __IOM uint32_t DIV_PLL2_B_WEN:1;
            uint32_t :3;
            __IOM uint32_t DIV_PLL2_C_WEN:1;
            uint32_t :3;
            __IOM uint32_t DIV_DSI_LPCLK_WEN:1;
            uint32_t :3;
        } CPG_PL2_DDIV_b;
    };
    union
    {
        __IOM uint32_t CPG_PL3A_DDIV;
        struct
        {
            __IOM uint32_t DIVPL3A_SET:3;
            uint32_t :1;
            __IOM uint32_t DIVPL3B_SET:3;
            uint32_t :1;
            __IOM uint32_t DIVPL3C_SET:3;
            uint32_t :5;
            __IOM uint32_t DIV_PLL3_A_WEN:1;
            uint32_t :3;
            __IOM uint32_t DIV_PLL3_B_WEN:1;
            uint32_t :3;
            __IOM uint32_t DIV_PLL3_C_WEN:1;
            uint32_t :7;
        } CPG_PL3A_DDIV_b;
    };
    union
    {
        __IOM uint32_t CPG_PL3B_DDIV;
        struct
        {
            __IOM uint32_t DIVPL3CLK200FIX_SET:3;
            uint32_t :13;
            __IOM uint32_t DIV_PLL3_CLK200FIX_WEN:1;
            uint32_t :15;
        } CPG_PL3B_DDIV_b;
    };
    union
    {
        __IOM uint32_t CPG_PL6_DDIV;
        struct
        {
            __IOM uint32_t DIVGPU_SET:2;
            uint32_t :14;
            __IOM uint32_t DIV_GPU_WEN:1;
            uint32_t :15;
        } CPG_PL6_DDIV_b;
    };
    __IM uint8_t        RESERVED5[4];
    union
    {
        __IOM uint32_t CPG_PL2SDHI_DSEL;
        struct
        {
            __IOM uint32_t SEL_SDHI0_SET:2;
            uint32_t :2;
            __IOM uint32_t SEL_SDHI1_SET:2;
            uint32_t :10;
            __IOM uint32_t SEL_SDHI0_WEN:1;
            uint32_t :3;
            __IOM uint32_t SEL_SDHI1_WEN:1;
            uint32_t :11;
        } CPG_PL2SDHI_DSEL_b;
    };
    union
    {
        __IOM uint32_t CPG_PL4_DSEL;
        struct
        {
            __IOM uint32_t SEL_PLL4_SET:1;
            uint32_t :15;
            __IOM uint32_t SEL_PLL4_WEN:1;
            uint32_t :15;
        } CPG_PL4_DSEL_b;
    };
    __IM uint8_t        RESERVED6[96];
    union
    {
        __IM uint32_t CPG_CLKSTATUS;
        struct
        {
            __IM uint32_t DIVPL1_STS:1;
            uint32_t :3;
            __IM uint32_t DIVPL2A_STS:1;
            __IM uint32_t DIVPL2B_STS:1;
            __IM uint32_t DIVPL2C_STS:1;
            __IM uint32_t DIVDSILPCLK_STS:1;
            __IM uint32_t DIVPL3A_STS:1;
            __IM uint32_t DIVPL3B_STS:1;
            __IM uint32_t DIVPL3C_STS:1;
            __IM uint32_t DIVPL3CLK200FIX_STS:1;
            uint32_t :8;
            __IM uint32_t DIVGPU_STS:1;
            uint32_t :3;
            __IM uint32_t DIVPL3D_STS:1;
            __IM uint32_t DIVPL3E_STS:1;
            uint32_t :2;
            __IM uint32_t SELSDHI0_STS:1;
            __IM uint32_t SELSDHI1_STS:1;
            uint32_t :1;
            __IM uint32_t SELPLL4_STS:1;
        } CPG_CLKSTATUS_b;
    };
    __IM uint8_t        RESERVED7[388];
    union
    {
        __IOM uint32_t CPG_PL3_SSEL;
        struct
        {
            __IOM uint32_t SEL_PLL3_1_SET:1;
            uint32_t :3;
            __IOM uint32_t SEL_PLL3_2_SET:1;
            uint32_t :3;
            __IOM uint32_t SEL_PLL3_3_SET:1;
            uint32_t :7;
            __IM uint32_t SEL_PLL3_1_WEN:1;
            uint32_t :3;
            __IM uint32_t SEL_PLL3_2_WEN:1;
            uint32_t :3;
            __IM uint32_t SEL_PLL3_3_WEN:1;
            uint32_t :7;
        } CPG_PL3_SSEL_b;
    };
    __IM uint8_t        RESERVED8[8];
    union
    {
        __IOM uint32_t CPG_PL6_SSEL;
        struct
        {
            __IOM uint32_t SEL_PLL6_1_SET:1;
            uint32_t :3;
            __IOM uint32_t SEL_GPU1_1_SET:1;
            uint32_t :3;
            __IOM uint32_t SEL_GPU1_2_SET:1;
            uint32_t :3;
            __IOM uint32_t SEL_GPU2_SET:1;
            uint32_t :3;
            __IOM uint32_t SEL_PL6_1_WEN:1;
            uint32_t :3;
            __IOM uint32_t SEL_GPU1_1_WEN:1;
            uint32_t :3;
            __IOM uint32_t SEL_GPU1_2_WEN:1;
            uint32_t :3;
            __IOM uint32_t SEL_GPU2_WEN:1;
            uint32_t :3;
        } CPG_PL6_SSEL_b;
    };
    union
    {
        __IOM uint32_t CPG_PL6_ETH_SSEL;
        struct
        {
            __IOM uint32_t SEL_PLL6_2_SET:1;
            uint32_t :3;
            __IOM uint32_t SEL_ETH_SET:1;
            uint32_t :11;
            __IOM uint32_t SEL_PLL6_2_WEN:1;
            uint32_t :3;
            __IOM uint32_t SEL_ETH_WEN:1;
            uint32_t :11;
        } CPG_PL6_ETH_SSEL_b;
    };
    __IM uint8_t        RESERVED9[4];
    union
    {
        __IOM uint32_t CPG_PL5_SDIV;
        struct
        {
            __IOM uint32_t DIVDSIA_SET:2;
            uint32_t :6;
            __IOM uint32_t DIVDSIB_SET:4;
            uint32_t :4;
            __IOM uint32_t DIV_DSI_A_WEN:1;
            uint32_t :7;
            __IOM uint32_t DIV_DSI_B_WEN:1;
            uint32_t :7;
        } CPG_PL5_SDIV_b;
    };
    __IM uint8_t        RESERVED10[220];
    union
    {
        __IOM uint32_t CPG_CLKON_CA55;
        struct
        {
            __IOM uint32_t CLK0_ON:1;
            __IOM uint32_t CLK1_ON:1;
            __IOM uint32_t CLK2_ON:1;
            __IOM uint32_t CLK3_ON:1;
            __IOM uint32_t CLK4_ON:1;
            __IOM uint32_t CLK5_ON:1;
            uint32_t :10;
            __IOM uint32_t CLK0_ONWEN:1;
            __IOM uint32_t CLK1_ONWEN:1;
            __IOM uint32_t CLK2_ONWEN:1;
            __IOM uint32_t CLK3_ONWEN:1;
            __IOM uint32_t CLK4_ONWEN:1;
            __IOM uint32_t CLK5_ONWEN:1;
            uint32_t :10;
        } CPG_CLKON_CA55_b;
    };
    union
    {
        __IOM uint32_t CPG_CLKON_CM33;
        struct
        {
            __IOM uint32_t CLK0_ON:1;
            __IOM uint32_t CLK1_ON:1;
            uint32_t :14;
            __IOM uint32_t CLK0_ONWEN:1;
            __IOM uint32_t CLK1_ONWEN:1;
            uint32_t :14;
        } CPG_CLKON_CM33_b;
    };
    union
    {
        __IOM uint32_t CPG_CLKON_SRAM_ACPU;
        struct
        {
            __IOM uint32_t CLK0_ON:1;
            uint32_t :15;
            __IOM uint32_t CLK0_ONWEN:1;
            uint32_t :15;
        } CPG_CLKON_SRAM_ACPU_b;
    };
    union
    {
        __IOM uint32_t CPG_CLKON_SRAM_MCPU;
        struct
        {
            __IOM uint32_t CLK0_ON:1;
            uint32_t :15;
            __IOM uint32_t CLK0_ONWEN:1;
            uint32_t :15;
        } CPG_CLKON_SRAM_MCPU_b;
    };
    union
    {
        __IOM uint32_t CPG_CLKON_ROM;
        struct
        {
            __IOM uint32_t CLK0_ON:1;
            uint32_t :15;
            __IOM uint32_t CLK0_ONWEN:1;
            uint32_t :15;
        } CPG_CLKON_ROM_b;
    };
    union
    {
        __IOM uint32_t CPG_CLKON_GIC600;
        struct
        {
            __IOM uint32_t CLK0_ON:1;
            uint32_t :15;
            __IOM uint32_t CLK0_ONWEN:1;
            uint32_t :15;
        } CPG_CLKON_GIC600_b;
    };
    union
    {
        __IOM uint32_t CPG_CLKON_IA55;
        struct
        {
            __IOM uint32_t CLK0_ON:1;
            __IOM uint32_t CLK1_ON:1;
            uint32_t :14;
            __IOM uint32_t CLK0_ONWEN:1;
            __IOM uint32_t CLK1_ONWEN:1;
            uint32_t :14;
        } CPG_CLKON_IA55_b;
    };
    union
    {
        __IOM uint32_t CPG_CLKON_IM33;
        struct
        {
            __IOM uint32_t CLK0_ON:1;
            __IOM uint32_t CLK1_ON:1;
            uint32_t :14;
            __IOM uint32_t CLK0_ONWEN:1;
            __IOM uint32_t CLK1_ONWEN:1;
            uint32_t :14;
        } CPG_CLKON_IM33_b;
    };
    union
    {
        __IOM uint32_t CPG_CLKON_MHU;
        struct
        {
            __IOM uint32_t CLK0_ON:1;
            uint32_t :15;
            __IOM uint32_t CLK0_ONWEN:1;
            uint32_t :15;
        } CPG_CLKON_MHU_b;
    };
    union
    {
        __IOM uint32_t CPG_CLKON_CST;
        struct
        {
            __IOM uint32_t CLK0_ON:1;
            __IOM uint32_t CLK1_ON:1;
            __IOM uint32_t CLK2_ON:1;
            __IOM uint32_t CLK3_ON:1;
            __IOM uint32_t CLK4_ON:1;
            __IOM uint32_t CLK5_ON:1;
            __IOM uint32_t CLK6_ON:1;
            __IOM uint32_t CLK7_ON:1;
            __IOM uint32_t CLK8_ON:1;
            __IOM uint32_t CLK9_ON:1;
            __IOM uint32_t CLK10_ON:1;
            uint32_t :5;
            __IOM uint32_t CLK0_ONWEN:1;
            __IOM uint32_t CLK1_ONWEN:1;
            __IOM uint32_t CLK2_ONWEN:1;
            __IOM uint32_t CLK3_ONWEN:1;
            __IOM uint32_t CLK4_ONWEN:1;
            __IOM uint32_t CLK5_ONWEN:1;
            __IOM uint32_t CLK6_ONWEN:1;
            __IOM uint32_t CLK7_ONWEN:1;
            __IOM uint32_t CLK8_ONWEN:1;
            __IOM uint32_t CLK9_ONWEN:1;
            __IOM uint32_t CLK10_ONWEN:1;
            uint32_t :5;
        } CPG_CLKON_CST_b;
    };
    union
    {
        __IOM uint32_t CPG_CLKON_SYC;
        struct
        {
            __IOM uint32_t CLK0_ON:1;
            uint32_t :15;
            __IOM uint32_t CLK0_ONWEN:1;
            uint32_t :15;
        } CPG_CLKON_SYC_b;
    };
    union
    {
        __IOM uint32_t CPG_CLKON_DMAC_REG;
        struct
        {
            __IOM uint32_t CLK0_ON:1;
            __IOM uint32_t CLK1_ON:1;
            uint32_t :14;
            __IOM uint32_t CLK0_ONWEN:1;
            __IOM uint32_t CLK1_ONWEN:1;
            uint32_t :14;
        } CPG_CLKON_DMAC_REG_b;
    };
    union
    {
        __IOM uint32_t CPG_CLKON_SYSC;
        struct
        {
            __IOM uint32_t CLK0_ON:1;
            uint32_t :15;
            __IOM uint32_t CLK0_ONWEN:1;
            uint32_t :15;
        } CPG_CLKON_SYSC_b;
    };
    union
    {
        __IOM uint32_t CPG_CLKON_GTM;
        struct
        {
            __IOM uint32_t CLK0_ON:1;
            __IOM uint32_t CLK1_ON:1;
            __IOM uint32_t CLK2_ON:1;
            uint32_t :13;
            __IOM uint32_t CLK0_ONWEN:1;
            __IOM uint32_t CLK1_ONWEN:1;
            __IOM uint32_t CLK2_ONWEN:1;
            uint32_t :13;
        } CPG_CLKON_GTM_b;
    };
    union
    {
        __IOM uint32_t CPG_CLKON_MTU;
        struct
        {
            __IOM uint32_t CLK0_ON:1;
            uint32_t :15;
            __IOM uint32_t CLK0_ONWEN:1;
            uint32_t :15;
        } CPG_CLKON_MTU_b;
    };
    union
    {
        __IOM uint32_t CPG_CLKON_POE3;
        struct
        {
            __IOM uint32_t CLK0_ON:1;
            uint32_t :15;
            __IOM uint32_t CLK0_ONWEN:1;
            uint32_t :15;
        } CPG_CLKON_POE3_b;
    };
    union
    {
        __IOM uint32_t CPG_CLKON_GPT;
        struct
        {
            __IOM uint32_t CLK0_ON:1;
            uint32_t :15;
            __IOM uint32_t CLK0_ONWEN:1;
            uint32_t :15;
        } CPG_CLKON_GPT_b;
    };
    union
    {
        __IOM uint32_t CPG_CLKON_POEG;
        struct
        {
            __IOM uint32_t CLK0_ON:1;
            __IOM uint32_t CLK1_ON:1;
            __IOM uint32_t CLK2_ON:1;
            __IOM uint32_t CLK3_ON:1;
            uint32_t :12;
            __IOM uint32_t CLK0_ONWEN:1;
            __IOM uint32_t CLK1_ONWEN:1;
            __IOM uint32_t CLK2_ONWEN:1;
            __IOM uint32_t CLK3_ONWEN:1;
            uint32_t :12;
        } CPG_CLKON_POEG_b;
    };
    union
    {
        __IOM uint32_t CPG_CLKON_WDT;
        struct
        {
            __IOM uint32_t CLK0_ON:1;
            __IOM uint32_t CLK1_ON:1;
            __IOM uint32_t CLK2_ON:1;
            __IOM uint32_t CLK3_ON:1;
            __IOM uint32_t CLK4_ON:1;
            __IOM uint32_t CLK5_ON:1;
            uint32_t :10;
            __IOM uint32_t CLK0_ONWEN:1;
            __IOM uint32_t CLK1_ONWEN:1;
            __IOM uint32_t CLK2_ONWEN:1;
            __IOM uint32_t CLK3_ONWEN:1;
            __IOM uint32_t CLK4_ONWEN:1;
            __IOM uint32_t CLK5_ONWEN:1;
            uint32_t :10;
        } CPG_CLKON_WDT_b;
    };
    union
    {
        __IOM uint32_t CPG_CLKON_DDR;
        struct
        {
            __IOM uint32_t CLK0_ON:1;
            __IOM uint32_t CLK1_ON:1;
            uint32_t :14;
            __IOM uint32_t CLK0_ONWEN:1;
            __IOM uint32_t CLK1_ONWEN:1;
            uint32_t :14;
        } CPG_CLKON_DDR_b;
    };
    union
    {
        __IOM uint32_t CPG_CLKON_SPI_MULTI;
        struct
        {
            __IOM uint32_t CLK0_ON:1;
            __IOM uint32_t CLK1_ON:1;
            uint32_t :14;
            __IOM uint32_t CLK0_ONWEN:1;
            __IOM uint32_t CLK1_ONWEN:1;
            uint32_t :14;
        } CPG_CLKON_SPI_MULTI_b;
    };
    union
    {
        __IOM uint32_t CPG_CLKON_SDHI;
        struct
        {
            __IOM uint32_t CLK0_ON:1;
            __IOM uint32_t CLK1_ON:1;
            __IOM uint32_t CLK2_ON:1;
            __IOM uint32_t CLK3_ON:1;
            __IOM uint32_t CLK4_ON:1;
            __IOM uint32_t CLK5_ON:1;
            __IOM uint32_t CLK6_ON:1;
            __IOM uint32_t CLK7_ON:1;
            uint32_t :8;
            __IOM uint32_t CLK0_ONWEN:1;
            __IOM uint32_t CLK1_ONWEN:1;
            __IOM uint32_t CLK2_ONWEN:1;
            __IOM uint32_t CLK3_ONWEN:1;
            __IOM uint32_t CLK4_ONWEN:1;
            __IOM uint32_t CLK5_ONWEN:1;
            __IOM uint32_t CLK6_ONWEN:1;
            __IOM uint32_t CLK7_ONWEN:1;
            uint32_t :8;
        } CPG_CLKON_SDHI_b;
    };
    union
    {
        __IOM uint32_t CPG_CLKON_GPU;
        struct
        {
            __IOM uint32_t CLK0_ON:1;
            __IOM uint32_t CLK1_ON:1;
            __IOM uint32_t CLK2_ON:1;
            uint32_t :13;
            __IOM uint32_t CLK0_ONWEN:1;
            __IOM uint32_t CLK1_ONWEN:1;
            __IOM uint32_t CLK2_ONWEN:1;
            uint32_t :13;
        } CPG_CLKON_GPU_b;
    };
    union
    {
        __IOM uint32_t CPG_CLKON_ISU;
        struct
        {
            __IOM uint32_t CLK0_ON:1;
            __IOM uint32_t CLK1_ON:1;
            uint32_t :14;
            __IOM uint32_t CLK0_ONWEN:1;
            __IOM uint32_t CLK1_ONWEN:1;
            uint32_t :14;
        } CPG_CLKON_ISU_b;
    };
    union
    {
        __IOM uint32_t CPG_CLKON_H264;
        struct
        {
            __IOM uint32_t CLK0_ON:1;
            uint32_t :15;
            __IOM uint32_t CLK0_ONWEN:1;
            uint32_t :15;
        } CPG_CLKON_H264_b;
    };
    union
    {
        __IOM uint32_t CPG_CLKON_CRU;
        struct
        {
            __IOM uint32_t CLK0_ON:1;
            __IOM uint32_t CLK1_ON:1;
            __IOM uint32_t CLK2_ON:1;
            __IOM uint32_t CLK3_ON:1;
            __IOM uint32_t CLK4_ON:1;
            uint32_t :11;
            __IOM uint32_t CLK0_ONWEN:1;
            __IOM uint32_t CLK1_ONWEN:1;
            __IOM uint32_t CLK2_ONWEN:1;
            __IOM uint32_t CLK3_ONWEN:1;
            __IOM uint32_t CLK4_ONWEN:1;
            uint32_t :11;
        } CPG_CLKON_CRU_b;
    };
    union
    {
        __IOM uint32_t CPG_CLKON_MIPI_DSI;
        struct
        {
            __IOM uint32_t CLK0_ON:1;
            __IOM uint32_t CLK1_ON:1;
            __IOM uint32_t CLK2_ON:1;
            __IOM uint32_t CLK3_ON:1;
            __IOM uint32_t CLK4_ON:1;
            __IOM uint32_t CLK5_ON:1;
            uint32_t :10;
            __IOM uint32_t CLK0_ONWEN:1;
            __IOM uint32_t CLK1_ONWEN:1;
            __IOM uint32_t CLK2_ONWEN:1;
            __IOM uint32_t CLK3_ONWEN:1;
            __IOM uint32_t CLK4_ONWEN:1;
            __IOM uint32_t CLK5_ONWEN:1;
            uint32_t :10;
        } CPG_CLKON_MIPI_DSI_b;
    };
    union
    {
        __IOM uint32_t CPG_CLKON_LCDC;
        struct
        {
            __IOM uint32_t CLK0_ON:1;
            __IOM uint32_t CLK1_ON:1;
            uint32_t :14;
            __IOM uint32_t CLK0_ONWEN:1;
            __IOM uint32_t CLK1_ONWEN:1;
            uint32_t :14;
        } CPG_CLKON_LCDC_b;
    };
    union
    {
        __IOM uint32_t CPG_CLKON_SSI;
        struct
        {
            __IOM uint32_t CLK0_ON:1;
            __IOM uint32_t CLK1_ON:1;
            __IOM uint32_t CLK2_ON:1;
            __IOM uint32_t CLK3_ON:1;
            __IOM uint32_t CLK4_ON:1;
            __IOM uint32_t CLK5_ON:1;
            __IOM uint32_t CLK6_ON:1;
            __IOM uint32_t CLK7_ON:1;
            uint32_t :8;
            __IOM uint32_t CLK0_ONWEN:1;
            __IOM uint32_t CLK1_ONWEN:1;
            __IOM uint32_t CLK2_ONWEN:1;
            __IOM uint32_t CLK3_ONWEN:1;
            __IOM uint32_t CLK4_ONWEN:1;
            __IOM uint32_t CLK5_ONWEN:1;
            __IOM uint32_t CLK6_ONWEN:1;
            __IOM uint32_t CLK7_ONWEN:1;
            uint32_t :8;
        } CPG_CLKON_SSI_b;
    };
    union
    {
        __IOM uint32_t CPG_CLKON_SRC;
        struct
        {
            __IOM uint32_t CLK0_ON:1;
            uint32_t :15;
            __IOM uint32_t CLK0_ONWEN:1;
            uint32_t :15;
        } CPG_CLKON_SRC_b;
    };
    union
    {
        __IOM uint32_t CPG_CLKON_USB;
        struct
        {
            __IOM uint32_t CLK0_ON:1;
            __IOM uint32_t CLK1_ON:1;
            __IOM uint32_t CLK2_ON:1;
            __IOM uint32_t CLK3_ON:1;
            uint32_t :12;
            __IOM uint32_t CLK0_ONWEN:1;
            __IOM uint32_t CLK1_ONWEN:1;
            __IOM uint32_t CLK2_ONWEN:1;
            __IOM uint32_t CLK3_ONWEN:1;
            uint32_t :12;
        } CPG_CLKON_USB_b;
    };
    union
    {
        __IOM uint32_t CPG_CLKON_ETH;
        struct
        {
            __IOM uint32_t CLK0_ON:1;
            __IOM uint32_t CLK1_ON:1;
            uint32_t :14;
            __IOM uint32_t CLK0_ONWEN:1;
            __IOM uint32_t CLK1_ONWEN:1;
            uint32_t :14;
        } CPG_CLKON_ETH_b;
    };
    union
    {
        __IOM uint32_t CPG_CLKON_I2C;
        struct
        {
            __IOM uint32_t CLK0_ON:1;
            __IOM uint32_t CLK1_ON:1;
            __IOM uint32_t CLK2_ON:1;
            __IOM uint32_t CLK3_ON:1;
            uint32_t :12;
            __IOM uint32_t CLK0_ONWEN:1;
            __IOM uint32_t CLK1_ONWEN:1;
            __IOM uint32_t CLK2_ONWEN:1;
            __IOM uint32_t CLK3_ONWEN:1;
            uint32_t :12;
        } CPG_CLKON_I2C_b;
    };
    union
    {
        __IOM uint32_t CPG_CLKON_SCIF;
        struct
        {
            __IOM uint32_t CLK0_ON:1;
            __IOM uint32_t CLK1_ON:1;
            __IOM uint32_t CLK2_ON:1;
            __IOM uint32_t CLK3_ON:1;
            __IOM uint32_t CLK4_ON:1;
            uint32_t :11;
            __IOM uint32_t CLK0_ONWEN:1;
            __IOM uint32_t CLK1_ONWEN:1;
            __IOM uint32_t CLK2_ONWEN:1;
            __IOM uint32_t CLK3_ONWEN:1;
            __IOM uint32_t CLK4_ONWEN:1;
            uint32_t :11;
        } CPG_CLKON_SCIF_b;
    };
    union
    {
        __IOM uint32_t CPG_CLKON_SCI;
        struct
        {
            __IOM uint32_t CLK0_ON:1;
            __IOM uint32_t CLK1_ON:1;
            uint32_t :14;
            __IOM uint32_t CLK0_ONWEN:1;
            __IOM uint32_t CLK1_ONWEN:1;
            uint32_t :14;
        } CPG_CLKON_SCI_b;
    };
    union
    {
        __IOM uint32_t CPG_CLKON_IRDA;
        struct
        {
            __IOM uint32_t CLK0_ON:1;
            uint32_t :15;
            __IOM uint32_t CLK0_ONWEN:1;
            uint32_t :15;
        } CPG_CLKON_IRDA_b;
    };
    union
    {
        __IOM uint32_t CPG_CLKON_RSPI;
        struct
        {
            __IOM uint32_t CLK0_ON:1;
            __IOM uint32_t CLK1_ON:1;
            __IOM uint32_t CLK2_ON:1;
            uint32_t :13;
            __IOM uint32_t CLK0_ONWEN:1;
            __IOM uint32_t CLK1_ONWEN:1;
            __IOM uint32_t CLK2_ONWEN:1;
            uint32_t :13;
        } CPG_CLKON_RSPI_b;
    };
    union
    {
        __IOM uint32_t CPG_CLKON_CANFD;
        struct
        {
            __IOM uint32_t CLK0_ON:1;
            uint32_t :15;
            __IOM uint32_t CLK0_ONWEN:1;
            uint32_t :15;
        } CPG_CLKON_CANFD_b;
    };
    union
    {
        __IOM uint32_t CPG_CLKON_GPIO;
        struct
        {
            __IOM uint32_t CLK0_ON:1;
            uint32_t :15;
            __IOM uint32_t CLK0_ONWEN:1;
            uint32_t :15;
        } CPG_CLKON_GPIO_b;
    };
    union
    {
        __IOM uint32_t CPG_CLKON_TSIPG;
        struct
        {
            __IOM uint32_t CLK0_ON:1;
            __IOM uint32_t CLK1_ON:1;
            uint32_t :14;
            __IOM uint32_t CLK0_ONWEN:1;
            __IOM uint32_t CLK1_ONWEN:1;
            uint32_t :14;
        } CPG_CLKON_TSIPG_b;
    };
    __IM uint8_t        RESERVED11[4];
    union
    {
        __IOM uint32_t CPG_CLKON_OTP;
        struct
        {
            __IOM uint32_t CLK0_ON:1;
            __IOM uint32_t CLK1_ON:1;
            uint32_t :14;
            __IOM uint32_t CLK0_ONWEN:1;
            __IOM uint32_t CLK1_ONWEN:1;
            uint32_t :14;
        } CPG_CLKON_OTP_b;
    };
    union
    {
        __IOM uint32_t CPG_CLKON_ADC;
        struct
        {
            __IOM uint32_t CLK0_ON:1;
            __IOM uint32_t CLK1_ON:1;
            uint32_t :14;
            __IOM uint32_t CLK0_ONWEN:1;
            __IOM uint32_t CLK1_ONWEN:1;
            uint32_t :14;
        } CPG_CLKON_ADC_b;
    };
    union
    {
        __IOM uint32_t CPG_CLKON_TSU;
        struct
        {
            __IOM uint32_t CLK0_ON:1;
            uint32_t :15;
            __IOM uint32_t CLK0_ONWEN:1;
            uint32_t :15;
        } CPG_CLKON_TSU_b;
    };
    union
    {
        __IOM uint32_t CPG_CLKON_BBGU;
        struct
        {
            __IOM uint32_t CLK0_ON:1;
            uint32_t :15;
            __IOM uint32_t CLK0_ONWEN:1;
            uint32_t :15;
        } CPG_CLKON_BBGU_b;
    };
    union
    {
        __IOM uint32_t CPG_CLKON_AXI_ACPU_BUS;
        struct
        {
            __IOM uint32_t CLK0_ON:1;
            __IOM uint32_t CLK1_ON:1;
            __IOM uint32_t CLK2_ON:1;
            __IOM uint32_t CLK3_ON:1;
            uint32_t :12;
            __IOM uint32_t CLK0_ONWEN:1;
            __IOM uint32_t CLK1_ONWEN:1;
            __IOM uint32_t CLK2_ONWEN:1;
            __IOM uint32_t CLK3_ONWEN:1;
            uint32_t :12;
        } CPG_CLKON_AXI_ACPU_BUS_b;
    };
    union
    {
        __IOM uint32_t CPG_CLKON_AXI_MCPU_BUS;
        struct
        {
            __IOM uint32_t CLK0_ON:1;
            __IOM uint32_t CLK1_ON:1;
            __IOM uint32_t CLK2_ON:1;
            __IOM uint32_t CLK3_ON:1;
            __IOM uint32_t CLK4_ON:1;
            __IOM uint32_t CLK5_ON:1;
            __IOM uint32_t CLK6_ON:1;
            __IOM uint32_t CLK7_ON:1;
            __IOM uint32_t CLK8_ON:1;
            __IOM uint32_t CLK9_ON:1;
            __IOM uint32_t CLK10_ON:1;
            uint32_t :5;
            __IOM uint32_t CLK0_ONWEN:1;
            __IOM uint32_t CLK1_ONWEN:1;
            __IOM uint32_t CLK2_ONWEN:1;
            __IOM uint32_t CLK3_ONWEN:1;
            __IOM uint32_t CLK4_ONWEN:1;
            __IOM uint32_t CLK5_ONWEN:1;
            __IOM uint32_t CLK6_ONWEN:1;
            __IOM uint32_t CLK7_ONWEN:1;
            __IOM uint32_t CLK8_ONWEN:1;
            __IOM uint32_t CLK9_ONWEN:1;
            __IOM uint32_t CLK10_ONWEN:1;
            uint32_t :5;
        } CPG_CLKON_AXI_MCPU_BUS_b;
    };
    union
    {
        __IOM uint32_t CPG_CLKON_AXI_COM_BUS;
        struct
        {
            __IOM uint32_t CLK0_ON:1;
            __IOM uint32_t CLK1_ON:1;
            uint32_t :14;
            __IOM uint32_t CLK0_ONWEN:1;
            __IOM uint32_t CLK1_ONWEN:1;
            uint32_t :14;
        } CPG_CLKON_AXI_COM_BUS_b;
    };
    union
    {
        __IOM uint32_t CPG_CLKON_AXI_VIDEO_BUS;
        struct
        {
            __IOM uint32_t CLK0_ON:1;
            __IOM uint32_t CLK1_ON:1;
            uint32_t :14;
            __IOM uint32_t CLK0_ONWEN:1;
            __IOM uint32_t CLK1_ONWEN:1;
            uint32_t :14;
        } CPG_CLKON_AXI_VIDEO_BUS_b;
    };
    union
    {
        __IOM uint32_t CPG_CLKON_PERI_COM;
        struct
        {
            __IOM uint32_t CLK0_ON:1;
            __IOM uint32_t CLK1_ON:1;
            uint32_t :14;
            __IOM uint32_t CLK0_ONWEN:1;
            __IOM uint32_t CLK1_ONWEN:1;
            uint32_t :14;
        } CPG_CLKON_PERI_COM_b;
    };
    union
    {
        __IOM uint32_t CPG_CLKON_REG1_BUS;
        struct
        {
            __IOM uint32_t CLK0_ON:1;
            __IOM uint32_t CLK1_ON:1;
            uint32_t :14;
            __IOM uint32_t CLK0_ONWEN:1;
            __IOM uint32_t CLK1_ONWEN:1;
            uint32_t :14;
        } CPG_CLKON_REG1_BUS_b;
    };
    union
    {
        __IOM uint32_t CPG_CLKON_REG0_BUS;
        struct
        {
            __IOM uint32_t CLK0_ON:1;
            __IOM uint32_t CLK1_ON:1;
            __IOM uint32_t CLK2_ON:1;
            __IOM uint32_t CLK3_ON:1;
            uint32_t :12;
            __IOM uint32_t CLK0_ONWEN:1;
            __IOM uint32_t CLK1_ONWEN:1;
            __IOM uint32_t CLK2_ONWEN:1;
            __IOM uint32_t CLK3_ONWEN:1;
            uint32_t :12;
        } CPG_CLKON_REG0_BUS_b;
    };
    union
    {
        __IOM uint32_t CPG_CLKON_PERI_CPU;
        struct
        {
            __IOM uint32_t CLK0_ON:1;
            __IOM uint32_t CLK1_ON:1;
            __IOM uint32_t CLK2_ON:1;
            __IOM uint32_t CLK3_ON:1;
            uint32_t :12;
            __IOM uint32_t CLK0_ONWEN:1;
            __IOM uint32_t CLK1_ONWEN:1;
            __IOM uint32_t CLK2_ONWEN:1;
            __IOM uint32_t CLK3_ONWEN:1;
            uint32_t :12;
        } CPG_CLKON_PERI_CPU_b;
    };
    union
    {
        __IOM uint32_t CPG_CLKON_PERI_VIDEO;
        struct
        {
            __IOM uint32_t CLK0_ON:1;
            __IOM uint32_t CLK1_ON:1;
            __IOM uint32_t CLK2_ON:1;
            uint32_t :13;
            __IOM uint32_t CLK0_ONWEN:1;
            __IOM uint32_t CLK1_ONWEN:1;
            __IOM uint32_t CLK2_ONWEN:1;
            uint32_t :13;
        } CPG_CLKON_PERI_VIDEO_b;
    };
    union
    {
        __IOM uint32_t CPG_CLKON_PERI_DDR;
        struct
        {
            __IOM uint32_t CLK0_ON:1;
            uint32_t :15;
            __IOM uint32_t CLK0_ONWEN:1;
            uint32_t :15;
        } CPG_CLKON_PERI_DDR_b;
    };
    union
    {
        __IOM uint32_t CPG_CLKON_AXI_TZCDDR;
        struct
        {
            __IOM uint32_t CLK0_ON:1;
            __IOM uint32_t CLK1_ON:1;
            __IOM uint32_t CLK2_ON:1;
            __IOM uint32_t CLK3_ON:1;
            __IOM uint32_t CLK4_ON:1;
            uint32_t :11;
            __IOM uint32_t CLK0_ONWEN:1;
            __IOM uint32_t CLK1_ONWEN:1;
            __IOM uint32_t CLK2_ONWEN:1;
            __IOM uint32_t CLK3_ONWEN:1;
            __IOM uint32_t CLK4_ONWEN:1;
            uint32_t :11;
        } CPG_CLKON_AXI_TZCDDR_b;
    };
    union
    {
        __IOM uint32_t CPG_CLKON_MTGPGS;
        struct
        {
            __IOM uint32_t CLK0_ON:1;
            __IOM uint32_t CLK1_ON:1;
            uint32_t :14;
            __IOM uint32_t CLK0_ONWEN:1;
            __IOM uint32_t CLK1_ONWEN:1;
            uint32_t :14;
        } CPG_CLKON_MTGPGS_b;
    };
    union
    {
        __IOM uint32_t CPG_CLKON_AXI_DEFAULT_SLV;
        struct
        {
            __IOM uint32_t CLK0_ON:1;
            uint32_t :15;
            __IOM uint32_t CLK0_ONWEN:1;
            uint32_t :15;
        } CPG_CLKON_AXI_DEFAULT_SLV_b;
    };
    __IM uint8_t        RESERVED12[152];
    union
    {
        __IM uint32_t CPG_CLKMON_CA55;
        struct
        {
            __IM uint32_t CLK0_MON:1;
            __IM uint32_t CLK1_MON:1;
            __IM uint32_t CLK2_MON:1;
            __IM uint32_t CLK3_MON:1;
            __IM uint32_t CLK4_MON:1;
            __IM uint32_t CLK5_MON:1;
            uint32_t :26;
        } CPG_CLKMON_CA55_b;
    };
    union
    {
        __IM uint32_t CPG_CLKMON_CM33;
        struct
        {
            __IM uint32_t CLK0_MON:1;
            __IM uint32_t CLK1_MON:1;
            uint32_t :30;
        } CPG_CLKMON_CM33_b;
    };
    union
    {
        __IM uint32_t CPG_CLKMON_SRAM_ACPU;
        struct
        {
            __IM uint32_t CLK0_MON:1;
            uint32_t :31;
        } CPG_CLKMON_SRAM_ACPU_b;
    };
    union
    {
        __IM uint32_t CPG_CLKMON_SRAM_MCPU;
        struct
        {
            __IM uint32_t CLK0_MON:1;
            uint32_t :31;
        } CPG_CLKMON_SRAM_MCPU_b;
    };
    union
    {
        __IM uint32_t CPG_CLKMON_ROM;
        struct
        {
            __IM uint32_t CLK0_MON:1;
            uint32_t :31;
        } CPG_CLKMON_ROM_b;
    };
    union
    {
        __IM uint32_t CPG_CLKMON_GIC600;
        struct
        {
            __IM uint32_t CLK0_MON:1;
            uint32_t :31;
        } CPG_CLKMON_GIC600_b;
    };
    union
    {
        __IM uint32_t CPG_CLKMON_IA55;
        struct
        {
            __IM uint32_t CLK0_MON:1;
            __IM uint32_t CLK1_MON:1;
            uint32_t :30;
        } CPG_CLKMON_IA55_b;
    };
    union
    {
        __IM uint32_t CPG_CLKMON_IM33;
        struct
        {
            __IM uint32_t CLK0_MON:1;
            __IM uint32_t CLK1_MON:1;
            uint32_t :30;
        } CPG_CLKMON_IM33_b;
    };
    union
    {
        __IM uint32_t CPG_CLKMON_MHU;
        struct
        {
            __IM uint32_t CLK0_MON:1;
            uint32_t :31;
        } CPG_CLKMON_MHU_b;
    };
    union
    {
        __IM uint32_t CPG_CLKMON_CST;
        struct
        {
            __IM uint32_t CLK0_MON:1;
            __IM uint32_t CLK1_MON:1;
            __IM uint32_t CLK2_MON:1;
            __IM uint32_t CLK3_MON:1;
            __IM uint32_t CLK4_MON:1;
            __IM uint32_t CLK5_MON:1;
            __IM uint32_t CLK6_MON:1;
            __IM uint32_t CLK7_MON:1;
            __IM uint32_t CLK8_MON:1;
            __IM uint32_t CLK9_MON:1;
            __IM uint32_t CLK10_MON:1;
            uint32_t :21;
        } CPG_CLKMON_CST_b;
    };
    union
    {
        __IM uint32_t CPG_CLKMON_SYC;
        struct
        {
            __IM uint32_t CLK0_MON:1;
            uint32_t :31;
        } CPG_CLKMON_SYC_b;
    };
    union
    {
        __IM uint32_t CPG_CLKMON_DMAC_REG;
        struct
        {
            __IM uint32_t CLK0_MON:1;
            __IM uint32_t CLK1_MON:1;
            uint32_t :30;
        } CPG_CLKMON_DMAC_REG_b;
    };
    union
    {
        __IM uint32_t CPG_CLKMON_SYSC;
        struct
        {
            __IM uint32_t CLK0_MON:1;
            uint32_t :31;
        } CPG_CLKMON_SYSC_b;
    };
    union
    {
        __IM uint32_t CPG_CLKMON_GTM;
        struct
        {
            __IM uint32_t CLK0_MON:1;
            __IM uint32_t CLK1_MON:1;
            __IM uint32_t CLK2_MON:1;
            uint32_t :29;
        } CPG_CLKMON_GTM_b;
    };
    union
    {
        __IM uint32_t CPG_CLKMON_MTU;
        struct
        {
            __IM uint32_t CLK0_MON:1;
            uint32_t :31;
        } CPG_CLKMON_MTU_b;
    };
    union
    {
        __IM uint32_t CPG_CLKMON_POE3;
        struct
        {
            __IM uint32_t CLK0_MON:1;
            uint32_t :31;
        } CPG_CLKMON_POE3_b;
    };
    union
    {
        __IM uint32_t CPG_CLKMON_GPT;
        struct
        {
            __IM uint32_t CLK0_MON:1;
            uint32_t :31;
        } CPG_CLKMON_GPT_b;
    };
    union
    {
        __IM uint32_t CPG_CLKMON_POEG;
        struct
        {
            __IM uint32_t CLK0_MON:1;
            __IM uint32_t CLK1_MON:1;
            __IM uint32_t CLK2_MON:1;
            __IM uint32_t CLK3_MON:1;
            uint32_t :28;
        } CPG_CLKMON_POEG_b;
    };
    union
    {
        __IM uint32_t CPG_CLKMON_WDT;
        struct
        {
            __IM uint32_t CLK0_MON:1;
            __IM uint32_t CLK1_MON:1;
            __IM uint32_t CLK2_MON:1;
            __IM uint32_t CLK3_MON:1;
            __IM uint32_t CLK4_MON:1;
            __IM uint32_t CLK5_MON:1;
            __IM uint32_t CLK6_MON:1;
            __IM uint32_t CLK7_MON:1;
            uint32_t :24;
        } CPG_CLKMON_WDT_b;
    };
    union
    {
        __IM uint32_t CPG_CLKMON_DDR;
        struct
        {
            __IM uint32_t CLK0_MON:1;
            __IM uint32_t CLK1_MON:1;
            uint32_t :30;
        } CPG_CLKMON_DDR_b;
    };
    union
    {
        __IM uint32_t CPG_CLKMON_SPI_MULTI;
        struct
        {
            __IM uint32_t CLK0_MON:1;
            __IM uint32_t CLK1_MON:1;
            uint32_t :30;
        } CPG_CLKMON_SPI_MULTI_b;
    };
    union
    {
        __IM uint32_t CPG_CLKMON_SDHI;
        struct
        {
            __IM uint32_t CLK0_MON:1;
            __IM uint32_t CLK1_MON:1;
            __IM uint32_t CLK2_MON:1;
            __IM uint32_t CLK3_MON:1;
            __IM uint32_t CLK4_MON:1;
            __IM uint32_t CLK5_MON:1;
            __IM uint32_t CLK6_MON:1;
            __IM uint32_t CLK7_MON:1;
            uint32_t :24;
        } CPG_CLKMON_SDHI_b;
    };
    union
    {
        __IM uint32_t CPG_CLKMON_GPU;
        struct
        {
            __IM uint32_t CLK0_MON:1;
            __IM uint32_t CLK1_MON:1;
            __IM uint32_t CLK2_MON:1;
            uint32_t :29;
        } CPG_CLKMON_GPU_b;
    };
    union
    {
        __IM uint32_t CPG_CLKMON_ISU;
        struct
        {
            __IM uint32_t CLK0_MON:1;
            __IM uint32_t CLK1_MON:1;
            uint32_t :30;
        } CPG_CLKMON_ISU_b;
    };
    union
    {
        __IM uint32_t CPG_CLKMON_H264;
        struct
        {
            __IM uint32_t CLK0_MON:1;
            uint32_t :31;
        } CPG_CLKMON_H264_b;
    };
    union
    {
        __IM uint32_t CPG_CLKMON_CRU;
        struct
        {
            __IM uint32_t CLK0_MON:1;
            __IM uint32_t CLK1_MON:1;
            __IM uint32_t CLK2_MON:1;
            __IM uint32_t CLK3_MON:1;
            __IM uint32_t CLK4_MON:1;
            uint32_t :27;
        } CPG_CLKMON_CRU_b;
    };
    union
    {
        __IM uint32_t CPG_CLKMON_MIPI_DSI;
        struct
        {
            __IM uint32_t CLK0_MON:1;
            __IM uint32_t CLK1_MON:1;
            __IM uint32_t CLK2_MON:1;
            __IM uint32_t CLK3_MON:1;
            __IM uint32_t CLK4_MON:1;
            __IM uint32_t CLK5_MON:1;
            uint32_t :26;
        } CPG_CLKMON_MIPI_DSI_b;
    };
    union
    {
        __IM uint32_t CPG_CLKMON_LCDC;
        struct
        {
            __IM uint32_t CLK0_MON:1;
            __IM uint32_t CLK1_MON:1;
            uint32_t :30;
        } CPG_CLKMON_LCDC_b;
    };
    union
    {
        __IM uint32_t CPG_CLKMON_SSI;
        struct
        {
            __IM uint32_t CLK0_MON:1;
            __IM uint32_t CLK1_MON:1;
            __IM uint32_t CLK2_MON:1;
            __IM uint32_t CLK3_MON:1;
            __IM uint32_t CLK4_MON:1;
            __IM uint32_t CLK5_MON:1;
            __IM uint32_t CLK6_MON:1;
            __IM uint32_t CLK7_MON:1;
            uint32_t :24;
        } CPG_CLKMON_SSI_b;
    };
    union
    {
        __IM uint32_t CPG_CLKMON_SRC;
        struct
        {
            __IM uint32_t CLK0_MON:1;
            uint32_t :31;
        } CPG_CLKMON_SRC_b;
    };
    union
    {
        __IM uint32_t CPG_CLKMON_USB;
        struct
        {
            __IM uint32_t CLK0_MON:1;
            __IM uint32_t CLK1_MON:1;
            __IM uint32_t CLK2_MON:1;
            __IM uint32_t CLK3_MON:1;
            uint32_t :28;
        } CPG_CLKMON_USB_b;
    };
    union
    {
        __IM uint32_t CPG_CLKMON_ETH;
        struct
        {
            __IM uint32_t CLK0_MON:1;
            __IM uint32_t CLK1_MON:1;
            uint32_t :30;
        } CPG_CLKMON_ETH_b;
    };
    union
    {
        __IM uint32_t CPG_CLKMON_I2C;
        struct
        {
            __IM uint32_t CLK0_MON:1;
            __IM uint32_t CLK1_MON:1;
            __IM uint32_t CLK2_MON:1;
            __IM uint32_t CLK3_MON:1;
            uint32_t :28;
        } CPG_CLKMON_I2C_b;
    };
    union
    {
        __IM uint32_t CPG_CLKMON_SCIF;
        struct
        {
            __IM uint32_t CLK0_MON:1;
            __IM uint32_t CLK1_MON:1;
            __IM uint32_t CLK2_MON:1;
            __IM uint32_t CLK3_MON:1;
            __IM uint32_t CLK4_MON:1;
            uint32_t :27;
        } CPG_CLKMON_SCIF_b;
    };
    union
    {
        __IM uint32_t CPG_CLKMON_SCI;
        struct
        {
            __IM uint32_t CLK0_MON:1;
            __IM uint32_t CLK1_MON:1;
            uint32_t :30;
        } CPG_CLKMON_SCI_b;
    };
    union
    {
        __IM uint32_t CPG_CLKMON_IRDA;
        struct
        {
            __IM uint32_t CLK0_MON:1;
            uint32_t :31;
        } CPG_CLKMON_IRDA_b;
    };
    union
    {
        __IM uint32_t CPG_CLKMON_RSPI;
        struct
        {
            __IM uint32_t CLK0_MON:1;
            __IM uint32_t CLK1_MON:1;
            __IM uint32_t CLK2_MON:1;
            uint32_t :29;
        } CPG_CLKMON_RSPI_b;
    };
    union
    {
        __IM uint32_t CPG_CLKMON_CANFD;
        struct
        {
            __IM uint32_t CLK0_MON:1;
            uint32_t :31;
        } CPG_CLKMON_CANFD_b;
    };
    union
    {
        __IM uint32_t CPG_CLKMON_GPIO;
        struct
        {
            __IM uint32_t CLK0_MON:1;
            uint32_t :31;
        } CPG_CLKMON_GPIO_b;
    };
    union
    {
        __IM uint32_t CPG_CLKMON_TSIPG;
        struct
        {
            __IM uint32_t CLK0_MON:1;
            __IM uint32_t CLK1_MON:1;
            uint32_t :30;
        } CPG_CLKMON_TSIPG_b;
    };
    union
    {
        __IM uint32_t CPG_CLKMON_JAUTH;
        struct
        {
            __IM uint32_t CLK0_MON:1;
            uint32_t :31;
        } CPG_CLKMON_JAUTH_b;
    };
    union
    {
        __IM uint32_t CPG_CLKMON_OTP;
        struct
        {
            __IM uint32_t CLK0_MON:1;
            __IM uint32_t CLK1_MON:1;
            uint32_t :30;
        } CPG_CLKMON_OTP_b;
    };
    union
    {
        __IM uint32_t CPG_CLKMON_ADC;
        struct
        {
            __IM uint32_t CLK0_MON:1;
            __IM uint32_t CLK1_MON:1;
            uint32_t :30;
        } CPG_CLKMON_ADC_b;
    };
    union
    {
        __IM uint32_t CPG_CLKMON_TSU;
        struct
        {
            __IM uint32_t CLK0_MON:1;
            uint32_t :31;
        } CPG_CLKMON_TSU_b;
    };
    union
    {
        __IM uint32_t CPG_CLKMON_BBGU;
        struct
        {
            __IM uint32_t CLK0_MON:1;
            uint32_t :31;
        } CPG_CLKMON_BBGU_b;
    };
    union
    {
        __IM uint32_t CPG_CLKMON_AXI_ACPU_BUS;
        struct
        {
            __IM uint32_t CLK0_MON:1;
            __IM uint32_t CLK1_MON:1;
            __IM uint32_t CLK2_MON:1;
            __IM uint32_t CLK3_MON:1;
            uint32_t :28;
        } CPG_CLKMON_AXI_ACPU_BUS_b;
    };
    union
    {
        __IM uint32_t CPG_CLKMON_AXI_MCPU_BUS;
        struct
        {
            __IM uint32_t CLK0_MON:1;
            __IM uint32_t CLK1_MON:1;
            __IM uint32_t CLK2_MON:1;
            __IM uint32_t CLK3_MON:1;
            __IM uint32_t CLK4_MON:1;
            __IM uint32_t CLK5_MON:1;
            __IM uint32_t CLK6_MON:1;
            __IM uint32_t CLK7_MON:1;
            __IM uint32_t CLK8_MON:1;
            __IM uint32_t CLK9_MON:1;
            __IM uint32_t CLK10_MON:1;
            uint32_t :21;
        } CPG_CLKMON_AXI_MCPU_BUS_b;
    };
    union
    {
        __IM uint32_t CPG_CLKMON_AXI_COM_BUS;
        struct
        {
            __IM uint32_t CLK0_MON:1;
            __IM uint32_t CLK1_MON:1;
            uint32_t :30;
        } CPG_CLKMON_AXI_COM_BUS_b;
    };
    union
    {
        __IM uint32_t CPG_CLKMON_AXI_VIDEO_BUS;
        struct
        {
            __IM uint32_t CLK0_MON:1;
            __IM uint32_t CLK1_MON:1;
            uint32_t :30;
        } CPG_CLKMON_AXI_VIDEO_BUS_b;
    };
    union
    {
        __IM uint32_t CPG_CLKMON_PERI_COM;
        struct
        {
            __IM uint32_t CLK0_MON:1;
            __IM uint32_t CLK1_MON:1;
            uint32_t :30;
        } CPG_CLKMON_PERI_COM_b;
    };
    union
    {
        __IM uint32_t CPG_CLKMON_REG1_BUS;
        struct
        {
            __IM uint32_t CLK0_MON:1;
            __IM uint32_t CLK1_MON:1;
            uint32_t :30;
        } CPG_CLKMON_REG1_BUS_b;
    };
    union
    {
        __IM uint32_t CPG_CLKMON_REG0_BUS;
        struct
        {
            __IM uint32_t CLK0_MON:1;
            __IM uint32_t CLK1_MON:1;
            __IM uint32_t CLK2_MON:1;
            __IM uint32_t CLK3_MON:1;
            uint32_t :28;
        } CPG_CLKMON_REG0_BUS_b;
    };
    union
    {
        __IM uint32_t CPG_CLKMON_PERI_CPU;
        struct
        {
            __IM uint32_t CLK0_MON:1;
            __IM uint32_t CLK1_MON:1;
            __IM uint32_t CLK2_MON:1;
            __IM uint32_t CLK3_MON:1;
            uint32_t :28;
        } CPG_CLKMON_PERI_CPU_b;
    };
    union
    {
        __IM uint32_t CPG_CLKMON_PERI_VIDEO;
        struct
        {
            __IM uint32_t CLK0_MON:1;
            __IM uint32_t CLK1_MON:1;
            __IM uint32_t CLK2_MON:1;
            uint32_t :29;
        } CPG_CLKMON_PERI_VIDEO_b;
    };
    union
    {
        __IM uint32_t CPG_CLKMON_PERI_DDR;
        struct
        {
            __IM uint32_t CLK0_MON:1;
            uint32_t :31;
        } CPG_CLKMON_PERI_DDR_b;
    };
    union
    {
        __IM uint32_t CPG_CLKMON_AXI_TZCDDR;
        struct
        {
            __IM uint32_t CLK0_MON:1;
            __IM uint32_t CLK1_MON:1;
            __IM uint32_t CLK2_MON:1;
            __IM uint32_t CLK3_MON:1;
            __IM uint32_t CLK4_MON:1;
            uint32_t :27;
        } CPG_CLKMON_AXI_TZCDDR_b;
    };
    union
    {
        __IM uint32_t CPG_CLKMON_MTGPGS;
        struct
        {
            __IM uint32_t CLK0_MON:1;
            __IM uint32_t CLK1_MON:1;
            uint32_t :30;
        } CPG_CLKMON_MTGPGS_b;
    };
    union
    {
        __IM uint32_t CPG_CLKMON_AXI_DEFAULT_SLV;
        struct
        {
            __IM uint32_t CLK0_MON:1;
            uint32_t :31;
        } CPG_CLKMON_AXI_DEFAULT_SLV_b;
    };
    __IM uint8_t        RESERVED13[152];
    union
    {
        __IOM uint32_t CPG_RST_CA55;
        struct
        {
            __IOM uint32_t UNIT0_RSTB:1;
            __IOM uint32_t UNIT1_RSTB:1;
            __IOM uint32_t UNIT2_RSTB:1;
            __IOM uint32_t UNIT3_RSTB:1;
            __IOM uint32_t UNIT4_RSTB:1;
            __IOM uint32_t UNIT5_RSTB:1;
            __IOM uint32_t UNIT6_RSTB:1;
            __IOM uint32_t UNIT7_RSTB:1;
            __IOM uint32_t UNIT8_RSTB:1;
            __IOM uint32_t UNIT9_RSTB:1;
            __IOM uint32_t UNIT10_RSTB:1;
            __IOM uint32_t UNIT11_RSTB:1;
            __IOM uint32_t UNIT12_RSTB:1;
            uint32_t :3;
            __IOM uint32_t UNIT0_RSTWEN:1;
            __IOM uint32_t UNIT1_RSTWEN:1;
            __IOM uint32_t UNIT2_RSTWEN:1;
            __IOM uint32_t UNIT3_RSTWEN:1;
            __IOM uint32_t UNIT4_RSTWEN:1;
            __IOM uint32_t UNIT5_RSTWEN:1;
            __IOM uint32_t UNIT6_RSTWEN:1;
            __IOM uint32_t UNIT7_RSTWEN:1;
            __IOM uint32_t UNIT8_RSTWEN:1;
            __IOM uint32_t UNIT9_RSTWEN:1;
            __IOM uint32_t UNIT10_RSTWEN:1;
            __IOM uint32_t UNIT11_RSTWEN:1;
            __IOM uint32_t UNIT12_RSTWEN:1;
            uint32_t :3;
        } CPG_RST_CA55_b;
    };
    union
    {
        __IOM uint32_t CPG_RST_CM33;
        struct
        {
            __IOM uint32_t UNIT0_RSTB:1;
            __IOM uint32_t UNIT1_RSTB:1;
            __IOM uint32_t UNIT2_RSTB:1;
            uint32_t :13;
            __IOM uint32_t UNIT0_RSTWEN:1;
            __IOM uint32_t UNIT1_RSTWEN:1;
            __IOM uint32_t UNIT2_RSTWEN:1;
            uint32_t :13;
        } CPG_RST_CM33_b;
    };
    union
    {
        __IOM uint32_t CPG_RST_SRAM_ACPU;
        struct
        {
            __IOM uint32_t UNIT0_RSTB:1;
            uint32_t :15;
            __IOM uint32_t UNIT0_RSTWEN:1;
            uint32_t :15;
        } CPG_RST_SRAM_ACPU_b;
    };
    union
    {
        __IOM uint32_t CPG_RST_SRAM_MCPU;
        struct
        {
            __IOM uint32_t UNIT0_RSTB:1;
            uint32_t :15;
            __IOM uint32_t UNIT0_RSTWEN:1;
            uint32_t :15;
        } CPG_RST_SRAM_MCPU_b;
    };
    union
    {
        __IOM uint32_t CPG_RST_ROM;
        struct
        {
            __IOM uint32_t UNIT0_RSTB:1;
            uint32_t :15;
            __IOM uint32_t UNIT0_RSTWEN:1;
            uint32_t :15;
        } CPG_RST_ROM_b;
    };
    union
    {
        __IOM uint32_t CPG_RST_GIC600;
        struct
        {
            __IOM uint32_t UNIT0_RSTB:1;
            __IOM uint32_t UNIT1_RSTB:1;
            uint32_t :14;
            __IOM uint32_t UNIT0_RSTWEN:1;
            __IOM uint32_t UNIT1_RSTWEN:1;
            uint32_t :14;
        } CPG_RST_GIC600_b;
    };
    union
    {
        __IOM uint32_t CPG_RST_IA55;
        struct
        {
            __IOM uint32_t UNIT0_RSTB:1;
            uint32_t :15;
            __IOM uint32_t UNIT0_RSTWEN:1;
            uint32_t :15;
        } CPG_RST_IA55_b;
    };
    union
    {
        __IOM uint32_t CPG_RST_IM33;
        struct
        {
            __IOM uint32_t UNIT0_RSTB:1;
            uint32_t :15;
            __IOM uint32_t UNIT0_RSTWEN:1;
            uint32_t :15;
        } CPG_RST_IM33_b;
    };
    union
    {
        __IOM uint32_t CPG_RST_MHU;
        struct
        {
            __IOM uint32_t UNIT0_RSTB:1;
            uint32_t :15;
            __IOM uint32_t UNIT0_RSTWEN:1;
            uint32_t :15;
        } CPG_RST_MHU_b;
    };
    __IM uint8_t        RESERVED14[4];
    union
    {
        __IOM uint32_t CPG_RST_SYC;
        struct
        {
            __IOM uint32_t UNIT0_RSTB:1;
            uint32_t :15;
            __IOM uint32_t UNIT0_RSTWEN:1;
            uint32_t :15;
        } CPG_RST_SYC_b;
    };
    union
    {
        __IOM uint32_t CPG_RST_DMAC;
        struct
        {
            __IOM uint32_t UNIT0_RSTB:1;
            __IOM uint32_t UNIT1_RSTB:1;
            uint32_t :14;
            __IOM uint32_t UNIT0_RSTWEN:1;
            __IOM uint32_t UNIT1_RSTWEN:1;
            uint32_t :14;
        } CPG_RST_DMAC_b;
    };
    union
    {
        __IOM uint32_t CPG_RST_SYSC;
        struct
        {
            __IOM uint32_t UNIT0_RSTB:1;
            __IOM uint32_t UNIT1_RSTB:1;
            __IOM uint32_t UNIT2_RSTB:1;
            uint32_t :13;
            __IOM uint32_t UNIT0_RSTWEN:1;
            __IOM uint32_t UNIT1_RSTWEN:1;
            __IOM uint32_t UNIT2_RSTWEN:1;
            uint32_t :13;
        } CPG_RST_SYSC_b;
    };
    union
    {
        __IOM uint32_t CPG_RST_GTM;
        struct
        {
            __IOM uint32_t UNIT0_RSTB:1;
            __IOM uint32_t UNIT1_RSTB:1;
            __IOM uint32_t UNIT2_RSTB:1;
            uint32_t :13;
            __IOM uint32_t UNIT0_RSTWEN:1;
            __IOM uint32_t UNIT1_RSTWEN:1;
            __IOM uint32_t UNIT2_RSTWEN:1;
            uint32_t :13;
        } CPG_RST_GTM_b;
    };
    union
    {
        __IOM uint32_t CPG_RST_MTU;
        struct
        {
            __IOM uint32_t UNIT0_RSTB:1;
            uint32_t :15;
            __IOM uint32_t UNIT0_RSTWEN:1;
            uint32_t :15;
        } CPG_RST_MTU_b;
    };
    union
    {
        __IOM uint32_t CPG_RST_POE3;
        struct
        {
            __IOM uint32_t UNIT0_RSTB:1;
            uint32_t :15;
            __IOM uint32_t UNIT0_RSTWEN:1;
            uint32_t :15;
        } CPG_RST_POE3_b;
    };
    union
    {
        __IOM uint32_t CPG_RST_GPT;
        struct
        {
            __IOM uint32_t UNIT0_RSTB:1;
            uint32_t :15;
            __IOM uint32_t UNIT0_RSTWEN:1;
            uint32_t :15;
        } CPG_RST_GPT_b;
    };
    union
    {
        __IOM uint32_t CPG_RST_POEG;
        struct
        {
            __IOM uint32_t UNIT0_RSTB:1;
            __IOM uint32_t UNIT1_RSTB:1;
            __IOM uint32_t UNIT2_RSTB:1;
            __IOM uint32_t UNIT3_RSTB:1;
            uint32_t :12;
            __IOM uint32_t UNIT0_RSTWEN:1;
            __IOM uint32_t UNIT1_RSTWEN:1;
            __IOM uint32_t UNIT2_RSTWEN:1;
            __IOM uint32_t UNIT3_RSTWEN:1;
            uint32_t :12;
        } CPG_RST_POEG_b;
    };
    union
    {
        __IOM uint32_t CPG_RST_WDT;
        struct
        {
            __IOM uint32_t UNIT0_RSTB:1;
            __IOM uint32_t UNIT1_RSTB:1;
            __IOM uint32_t UNIT2_RSTB:1;
            __IOM uint32_t UNIT3_RSTB:1;
            uint32_t :12;
            __IOM uint32_t UNIT0_RSTWEN:1;
            __IOM uint32_t UNIT1_RSTWEN:1;
            __IOM uint32_t UNIT2_RSTWEN:1;
            __IOM uint32_t UNIT3_RSTWEN:1;
            uint32_t :12;
        } CPG_RST_WDT_b;
    };
    union
    {
        __IOM uint32_t CPG_RST_DDR;
        struct
        {
            __IOM uint32_t UNIT0_RSTB:1;
            __IOM uint32_t UNIT1_RSTB:1;
            __IOM uint32_t UNIT2_RSTB:1;
            __IOM uint32_t UNIT3_RSTB:1;
            __IOM uint32_t UNIT4_RSTB:1;
            __IOM uint32_t UNIT5_RSTB:1;
            __IOM uint32_t UNIT6_RSTB:1;
            uint32_t :9;
            __IOM uint32_t UNIT0_RSTWEN:1;
            __IOM uint32_t UNIT1_RSTWEN:1;
            __IOM uint32_t UNIT2_RSTWEN:1;
            __IOM uint32_t UNIT3_RSTWEN:1;
            __IOM uint32_t UNIT4_RSTWEN:1;
            __IOM uint32_t UNIT5_RSTWEN:1;
            __IOM uint32_t UNIT6_RSTWEN:1;
            uint32_t :9;
        } CPG_RST_DDR_b;
    };
    union
    {
        __IOM uint32_t CPG_RST_SPI;
        struct
        {
            __IOM uint32_t UNIT0_RSTB:1;
            uint32_t :15;
            __IOM uint32_t UNIT0_RSTWEN:1;
            uint32_t :15;
        } CPG_RST_SPI_b;
    };
    union
    {
        __IOM uint32_t CPG_RST_SDHI;
        struct
        {
            __IOM uint32_t UNIT0_RSTB:1;
            __IOM uint32_t UNIT1_RSTB:1;
            uint32_t :14;
            __IOM uint32_t UNIT0_RSTWEN:1;
            __IOM uint32_t UNIT1_RSTWEN:1;
            uint32_t :14;
        } CPG_RST_SDHI_b;
    };
    union
    {
        __IOM uint32_t CPG_RST_GPU;
        struct
        {
            __IOM uint32_t UNIT0_RSTB:1;
            __IOM uint32_t UNIT1_RSTB:1;
            __IOM uint32_t UNIT2_RSTB:1;
            uint32_t :13;
            __IOM uint32_t UNIT0_RSTWEN:1;
            __IOM uint32_t UNIT1_RSTWEN:1;
            __IOM uint32_t UNIT2_RSTWEN:1;
            uint32_t :13;
        } CPG_RST_GPU_b;
    };
    union
    {
        __IOM uint32_t CPG_RST_ISU;
        struct
        {
            __IOM uint32_t UNIT0_RSTB:1;
            __IOM uint32_t UNIT1_RSTB:1;
            uint32_t :14;
            __IOM uint32_t UNIT0_RSTWEN:1;
            __IOM uint32_t UNIT1_RSTWEN:1;
            uint32_t :14;
        } CPG_RST_ISU_b;
    };
    union
    {
        __IOM uint32_t CPG_RST_H264;
        struct
        {
            __IOM uint32_t UNIT0_RSTB:1;
            __IOM uint32_t UNIT1_RSTB:1;
            uint32_t :14;
            __IOM uint32_t UNIT0_RSTWEN:1;
            __IOM uint32_t UNIT1_RSTWEN:1;
            uint32_t :14;
        } CPG_RST_H264_b;
    };
    union
    {
        __IOM uint32_t CPG_RST_CRU;
        struct
        {
            __IOM uint32_t UNIT0_RSTB:1;
            __IOM uint32_t UNIT1_RSTB:1;
            __IOM uint32_t UNIT2_RSTB:1;
            uint32_t :13;
            __IOM uint32_t UNIT0_RSTWEN:1;
            __IOM uint32_t UNIT1_RSTWEN:1;
            __IOM uint32_t UNIT2_RSTWEN:1;
            uint32_t :13;
        } CPG_RST_CRU_b;
    };
    union
    {
        __IOM uint32_t CPG_RST_MIPI_DSI;
        struct
        {
            __IOM uint32_t UNIT0_RSTB:1;
            __IOM uint32_t UNIT1_RSTB:1;
            __IOM uint32_t UNIT2_RSTB:1;
            uint32_t :13;
            __IOM uint32_t UNIT0_RSTWEN:1;
            __IOM uint32_t UNIT1_RSTWEN:1;
            __IOM uint32_t UNIT2_RSTWEN:1;
            uint32_t :13;
        } CPG_RST_MIPI_DSI_b;
    };
    union
    {
        __IOM uint32_t CPG_RST_LCDC;
        struct
        {
            __IOM uint32_t UNIT0_RSTB:1;
            uint32_t :15;
            __IOM uint32_t UNIT0_RSTWEN:1;
            uint32_t :15;
        } CPG_RST_LCDC_b;
    };
    union
    {
        __IOM uint32_t CPG_RST_SSIF;
        struct
        {
            __IOM uint32_t UNIT0_RSTB:1;
            __IOM uint32_t UNIT1_RSTB:1;
            __IOM uint32_t UNIT2_RSTB:1;
            __IOM uint32_t UNIT3_RSTB:1;
            uint32_t :12;
            __IOM uint32_t UNIT0_RSTWEN:1;
            __IOM uint32_t UNIT1_RSTWEN:1;
            __IOM uint32_t UNIT2_RSTWEN:1;
            __IOM uint32_t UNIT3_RSTWEN:1;
            uint32_t :12;
        } CPG_RST_SSIF_b;
    };
    union
    {
        __IOM uint32_t CPG_RST_SRC;
        struct
        {
            __IOM uint32_t UNIT0_RSTB:1;
            uint32_t :15;
            __IOM uint32_t UNIT0_RSTWEN:1;
            uint32_t :15;
        } CPG_RST_SRC_b;
    };
    union
    {
        __IOM uint32_t CPG_RST_USB;
        struct
        {
            __IOM uint32_t UNIT0_RSTB:1;
            __IOM uint32_t UNIT1_RSTB:1;
            __IOM uint32_t UNIT2_RSTB:1;
            __IOM uint32_t UNIT3_RSTB:1;
            uint32_t :12;
            __IOM uint32_t UNIT0_RSTWEN:1;
            __IOM uint32_t UNIT1_RSTWEN:1;
            __IOM uint32_t UNIT2_RSTWEN:1;
            __IOM uint32_t UNIT3_RSTWEN:1;
            uint32_t :12;
        } CPG_RST_USB_b;
    };
    union
    {
        __IOM uint32_t CPG_RST_ETH;
        struct
        {
            __IOM uint32_t UNIT0_RSTB:1;
            __IOM uint32_t UNIT1_RSTB:1;
            uint32_t :14;
            __IOM uint32_t UNIT0_RSTWEN:1;
            __IOM uint32_t UNIT1_RSTWEN:1;
            uint32_t :14;
        } CPG_RST_ETH_b;
    };
    union
    {
        __IOM uint32_t CPG_RST_I2C;
        struct
        {
            __IOM uint32_t UNIT0_RSTB:1;
            __IOM uint32_t UNIT1_RSTB:1;
            __IOM uint32_t UNIT2_RSTB:1;
            __IOM uint32_t UNIT3_RSTB:1;
            uint32_t :12;
            __IOM uint32_t UNIT0_RSTWEN:1;
            __IOM uint32_t UNIT1_RSTWEN:1;
            __IOM uint32_t UNIT2_RSTWEN:1;
            __IOM uint32_t UNIT3_RSTWEN:1;
            uint32_t :12;
        } CPG_RST_I2C_b;
    };
    union
    {
        __IOM uint32_t CPG_RST_SCIF;
        struct
        {
            __IOM uint32_t UNIT0_RSTB:1;
            __IOM uint32_t UNIT1_RSTB:1;
            __IOM uint32_t UNIT2_RSTB:1;
            __IOM uint32_t UNIT3_RSTB:1;
            __IOM uint32_t UNIT4_RSTB:1;
            uint32_t :11;
            __IOM uint32_t UNIT0_RSTWEN:1;
            __IOM uint32_t UNIT1_RSTWEN:1;
            __IOM uint32_t UNIT2_RSTWEN:1;
            __IOM uint32_t UNIT3_RSTWEN:1;
            __IOM uint32_t UNIT4_RSTWEN:1;
            uint32_t :11;
        } CPG_RST_SCIF_b;
    };
    union
    {
        __IOM uint32_t CPG_RST_SCI;
        struct
        {
            __IOM uint32_t UNIT0_RSTB:1;
            __IOM uint32_t UNIT1_RSTB:1;
            uint32_t :14;
            __IOM uint32_t UNIT0_RSTWEN:1;
            __IOM uint32_t UNIT1_RSTWEN:1;
            uint32_t :14;
        } CPG_RST_SCI_b;
    };
    union
    {
        __IOM uint32_t CPG_RST_IRDA;
        struct
        {
            __IOM uint32_t UNIT0_RSTB:1;
            uint32_t :15;
            __IOM uint32_t UNIT0_RSTWEN:1;
            uint32_t :15;
        } CPG_RST_IRDA_b;
    };
    union
    {
        __IOM uint32_t CPG_RST_RSPI;
        struct
        {
            __IOM uint32_t UNIT0_RSTB:1;
            __IOM uint32_t UNIT1_RSTB:1;
            __IOM uint32_t UNIT2_RSTB:1;
            uint32_t :13;
            __IOM uint32_t UNIT0_RSTWEN:1;
            __IOM uint32_t UNIT1_RSTWEN:1;
            __IOM uint32_t UNIT2_RSTWEN:1;
            uint32_t :13;
        } CPG_RST_RSPI_b;
    };
    union
    {
        __IOM uint32_t CPG_RST_CANFD;
        struct
        {
            __IOM uint32_t UNIT0_RSTB:1;
            __IOM uint32_t UNIT1_RSTB:1;
            uint32_t :14;
            __IOM uint32_t UNIT0_RSTWEN:1;
            __IOM uint32_t UNIT1_RSTWEN:1;
            uint32_t :14;
        } CPG_RST_CANFD_b;
    };
    union
    {
        __IOM uint32_t CPG_RST_GPIO;
        struct
        {
            __IOM uint32_t UNIT0_RSTB:1;
            __IOM uint32_t UNIT1_RSTB:1;
            __IOM uint32_t UNIT2_RSTB:1;
            uint32_t :13;
            __IOM uint32_t UNIT0_RSTWEN:1;
            __IOM uint32_t UNIT1_RSTWEN:1;
            __IOM uint32_t UNIT2_RSTWEN:1;
            uint32_t :13;
        } CPG_RST_GPIO_b;
    };
    union
    {
        __IOM uint32_t CPG_RST_TSIPG;
        struct
        {
            __IOM uint32_t UNIT0_RSTB:1;
            uint32_t :15;
            __IOM uint32_t UNIT0_RSTWEN:1;
            uint32_t :15;
        } CPG_RST_TSIPG_b;
    };
    union
    {
        __IOM uint32_t CPG_RST_JAUTH;
        struct
        {
            __IOM uint32_t UNIT0_RSTB:1;
            uint32_t :15;
            __IOM uint32_t UNIT0_RSTWEN:1;
            uint32_t :15;
        } CPG_RST_JAUTH_b;
    };
    union
    {
        __IOM uint32_t CPG_RST_OTP;
        struct
        {
            __IOM uint32_t UNIT0_RSTB:1;
            uint32_t :15;
            __IOM uint32_t UNIT0_RSTWEN:1;
            uint32_t :15;
        } CPG_RST_OTP_b;
    };
    union
    {
        __IOM uint32_t CPG_RST_ADC;
        struct
        {
            __IOM uint32_t UNIT0_RSTB:1;
            __IOM uint32_t UNIT1_RSTB:1;
            uint32_t :14;
            __IOM uint32_t UNIT0_RSTWEN:1;
            __IOM uint32_t UNIT1_RSTWEN:1;
            uint32_t :14;
        } CPG_RST_ADC_b;
    };
    union
    {
        __IOM uint32_t CPG_RST_TSU;
        struct
        {
            __IOM uint32_t UNIT0_RSTB:1;
            uint32_t :15;
            __IOM uint32_t UNIT0_RSTWEN:1;
            uint32_t :15;
        } CPG_RST_TSU_b;
    };
    union
    {
        __IOM uint32_t CPG_RST_BBGU;
        struct
        {
            __IOM uint32_t UNIT0_RSTB:1;
            uint32_t :15;
            __IOM uint32_t UNIT0_RSTWEN:1;
            uint32_t :15;
        } CPG_RST_BBGU_b;
    };
    union
    {
        __IOM uint32_t CPG_RST_AXI_ACPU_BUS;
        struct
        {
            __IOM uint32_t UNIT0_RSTB:1;
            uint32_t :15;
            __IOM uint32_t UNIT0_RSTWEN:1;
            uint32_t :15;
        } CPG_RST_AXI_ACPU_BUS_b;
    };
    union
    {
        __IOM uint32_t CPG_RST_AXI_MCPU_BUS;
        struct
        {
            __IOM uint32_t UNIT0_RSTB:1;
            uint32_t :15;
            __IOM uint32_t UNIT0_RSTWEN:1;
            uint32_t :15;
        } CPG_RST_AXI_MCPU_BUS_b;
    };
    union
    {
        __IOM uint32_t CPG_RST_AXI_COM_BUS;
        struct
        {
            __IOM uint32_t UNIT0_RSTB:1;
            uint32_t :15;
            __IOM uint32_t UNIT0_RSTWEN:1;
            uint32_t :15;
        } CPG_RST_AXI_COM_BUS_b;
    };
    union
    {
        __IOM uint32_t CPG_RST_AXI_VIDEO_BUS;
        struct
        {
            __IOM uint32_t UNIT0_RSTB:1;
            uint32_t :15;
            __IOM uint32_t UNIT0_RSTWEN:1;
            uint32_t :15;
        } CPG_RST_AXI_VIDEO_BUS_b;
    };
    union
    {
        __IOM uint32_t CPG_RST_PERI_COM;
        struct
        {
            __IOM uint32_t UNIT0_RSTB:1;
            uint32_t :15;
            __IOM uint32_t UNIT0_RSTWEN:1;
            uint32_t :15;
        } CPG_RST_PERI_COM_b;
    };
    union
    {
        __IOM uint32_t CPG_RST_REG1_BUS;
        struct
        {
            __IOM uint32_t UNIT0_RSTB:1;
            uint32_t :15;
            __IOM uint32_t UNIT0_RSTWEN:1;
            uint32_t :15;
        } CPG_RST_REG1_BUS_b;
    };
    union
    {
        __IOM uint32_t CPG_RST_REG0_BUS;
        struct
        {
            __IOM uint32_t UNIT0_RSTB:1;
            uint32_t :15;
            __IOM uint32_t UNIT0_RSTWEN:1;
            uint32_t :15;
        } CPG_RST_REG0_BUS_b;
    };
    union
    {
        __IOM uint32_t CPG_RST_PERI_CPU;
        struct
        {
            __IOM uint32_t UNIT0_RSTB:1;
            uint32_t :15;
            __IOM uint32_t UNIT0_RSTWEN:1;
            uint32_t :15;
        } CPG_RST_PERI_CPU_b;
    };
    union
    {
        __IOM uint32_t CPG_RST_PERI_VIDEO;
        struct
        {
            __IOM uint32_t UNIT0_RSTB:1;
            uint32_t :15;
            __IOM uint32_t UNIT0_RSTWEN:1;
            uint32_t :15;
        } CPG_RST_PERI_VIDEO_b;
    };
    union
    {
        __IOM uint32_t CPG_RST_PERI_DDR;
        struct
        {
            __IOM uint32_t UNIT0_RSTB:1;
            uint32_t :15;
            __IOM uint32_t UNIT0_RSTWEN:1;
            uint32_t :15;
        } CPG_RST_PERI_DDR_b;
    };
    union
    {
        __IOM uint32_t CPG_RST_AXI_TZCDDR;
        struct
        {
            __IOM uint32_t UNIT0_RSTB:1;
            __IOM uint32_t UNIT1_RSTB:1;
            __IOM uint32_t UNIT2_RSTB:1;
            __IOM uint32_t UNIT3_RSTB:1;
            __IOM uint32_t UNIT4_RSTB:1;
            uint32_t :11;
            __IOM uint32_t UNIT0_RSTWEN:1;
            __IOM uint32_t UNIT1_RSTWEN:1;
            __IOM uint32_t UNIT2_RSTWEN:1;
            __IOM uint32_t UNIT3_RSTWEN:1;
            __IOM uint32_t UNIT4_RSTWEN:1;
            uint32_t :11;
        } CPG_RST_AXI_TZCDDR_b;
    };
    union
    {
        __IOM uint32_t CPG_RST_MTGPGS;
        struct
        {
            __IOM uint32_t UNIT0_RSTB:1;
            __IOM uint32_t UNIT1_RSTB:1;
            uint32_t :14;
            __IOM uint32_t UNIT0_RSTWEN:1;
            __IOM uint32_t UNIT1_RSTWEN:1;
            uint32_t :14;
        } CPG_RST_MTGPGS_b;
    };
    union
    {
        __IOM uint32_t CPG_RST_AXI_DEFAULT_SLV;
        struct
        {
            __IOM uint32_t UNIT0_RSTB:1;
            uint32_t :15;
            __IOM uint32_t UNIT0_RSTWEN:1;
            uint32_t :15;
        } CPG_RST_AXI_DEFAULT_SLV_b;
    };
    __IM uint8_t        RESERVED15[152];
    union
    {
        __IOM uint32_t CPG_RSTMON_CA55;
        struct
        {
            __IOM uint32_t RST0_MON:1;
            __IOM uint32_t RST1_MON:1;
            __IOM uint32_t RST2_MON:1;
            __IOM uint32_t RST3_MON:1;
            __IOM uint32_t RST4_MON:1;
            __IOM uint32_t RST5_MON:1;
            __IOM uint32_t RST6_MON:1;
            __IOM uint32_t RST7_MON:1;
            __IOM uint32_t RST8_MON:1;
            __IOM uint32_t RST9_MON:1;
            __IOM uint32_t RST10_MON:1;
            __IOM uint32_t RST11_MON:1;
            __IOM uint32_t RST12_MON:1;
            uint32_t :19;
        } CPG_RSTMON_CA55_b;
    };
    union
    {
        __IOM uint32_t CPG_RSTMON_CM33;
        struct
        {
            __IOM uint32_t RST0_MON:1;
            __IOM uint32_t RST1_MON:1;
            __IOM uint32_t RST2_MON:1;
            uint32_t :29;
        } CPG_RSTMON_CM33_b;
    };
    union
    {
        __IOM uint32_t CPG_RSTMON_SRAM_ACPU;
        struct
        {
            __IOM uint32_t RST0_MON:1;
            uint32_t :31;
        } CPG_RSTMON_SRAM_ACPU_b;
    };
    union
    {
        __IOM uint32_t CPG_RSTMON_SRAM_MCPU;
        struct
        {
            __IOM uint32_t RST0_MON:1;
            uint32_t :31;
        } CPG_RSTMON_SRAM_MCPU_b;
    };
    union
    {
        __IOM uint32_t CPG_RSTMON_ROM;
        struct
        {
            __IOM uint32_t RST0_MON:1;
            uint32_t :31;
        } CPG_RSTMON_ROM_b;
    };
    union
    {
        __IOM uint32_t CPG_RSTMON_GIC600;
        struct
        {
            __IOM uint32_t RST0_MON:1;
            __IOM uint32_t RST1_MON:1;
            uint32_t :30;
        } CPG_RSTMON_GIC600_b;
    };
    union
    {
        __IOM uint32_t CPG_RSTMON_IA55;
        struct
        {
            __IOM uint32_t RST0_MON:1;
            uint32_t :31;
        } CPG_RSTMON_IA55_b;
    };
    union
    {
        __IOM uint32_t CPG_RSTMON_IM33;
        struct
        {
            __IOM uint32_t RST0_MON:1;
            uint32_t :31;
        } CPG_RSTMON_IM33_b;
    };
    union
    {
        __IOM uint32_t CPG_RSTMON_MHU;
        struct
        {
            __IOM uint32_t RST0_MON:1;
            uint32_t :31;
        } CPG_RSTMON_MHU_b;
    };
    __IM uint8_t        RESERVED16[4];
    union
    {
        __IOM uint32_t CPG_RSTMON_SYC;
        struct
        {
            __IOM uint32_t RST0_MON:1;
            uint32_t :31;
        } CPG_RSTMON_SYC_b;
    };
    union
    {
        __IOM uint32_t CPG_RSTMON_DMAC;
        struct
        {
            __IOM uint32_t RST0_MON:1;
            __IOM uint32_t RST1_MON:1;
            uint32_t :30;
        } CPG_RSTMON_DMAC_b;
    };
    union
    {
        __IOM uint32_t CPG_RSTMON_SYSC;
        struct
        {
            __IOM uint32_t RST0_MON:1;
            __IOM uint32_t RST1_MON:1;
            __IOM uint32_t RST2_MON:1;
            uint32_t :29;
        } CPG_RSTMON_SYSC_b;
    };
    union
    {
        __IOM uint32_t CPG_RSTMON_GTM;
        struct
        {
            __IOM uint32_t RST0_MON:1;
            __IOM uint32_t RST1_MON:1;
            __IOM uint32_t RST2_MON:1;
            uint32_t :29;
        } CPG_RSTMON_GTM_b;
    };
    union
    {
        __IOM uint32_t CPG_RSTMON_MTU;
        struct
        {
            __IOM uint32_t RST0_MON:1;
            uint32_t :31;
        } CPG_RSTMON_MTU_b;
    };
    union
    {
        __IOM uint32_t CPG_RSTMON_POE3;
        struct
        {
            __IOM uint32_t RST0_MON:1;
            uint32_t :31;
        } CPG_RSTMON_POE3_b;
    };
    union
    {
        __IOM uint32_t CPG_RSTMON_GPT;
        struct
        {
            __IOM uint32_t RST0_MON:1;
            uint32_t :31;
        } CPG_RSTMON_GPT_b;
    };
    union
    {
        __IOM uint32_t CPG_RSTMON_POEG;
        struct
        {
            __IOM uint32_t RST0_MON:1;
            __IOM uint32_t RST1_MON:1;
            __IOM uint32_t RST2_MON:1;
            __IOM uint32_t RST3_MON:1;
            uint32_t :28;
        } CPG_RSTMON_POEG_b;
    };
    union
    {
        __IOM uint32_t CPG_RSTMON_WDT;
        struct
        {
            __IOM uint32_t RST0_MON:1;
            __IOM uint32_t RST1_MON:1;
            __IOM uint32_t RST2_MON:1;
            __IOM uint32_t RST3_MON:1;
            uint32_t :28;
        } CPG_RSTMON_WDT_b;
    };
    union
    {
        __IOM uint32_t CPG_RSTMON_DDR;
        struct
        {
            __IOM uint32_t RST0_MON:1;
            __IOM uint32_t RST1_MON:1;
            __IOM uint32_t RST2_MON:1;
            __IOM uint32_t RST3_MON:1;
            __IOM uint32_t RST4_MON:1;
            __IOM uint32_t RST5_MON:1;
            __IOM uint32_t RST6_MON:1;
            uint32_t :25;
        } CPG_RSTMON_DDR_b;
    };
    union
    {
        __IOM uint32_t CPG_RSTMON_SPI;
        struct
        {
            __IOM uint32_t RST0_MON:1;
            uint32_t :31;
        } CPG_RSTMON_SPI_b;
    };
    union
    {
        __IOM uint32_t CPG_RSTMON_SDHI;
        struct
        {
            __IOM uint32_t RST0_MON:1;
            __IOM uint32_t RST1_MON:1;
            uint32_t :30;
        } CPG_RSTMON_SDHI_b;
    };
    union
    {
        __IOM uint32_t CPG_RSTMON_GPU;
        struct
        {
            __IOM uint32_t RST0_MON:1;
            __IOM uint32_t RST1_MON:1;
            __IOM uint32_t RST2_MON:1;
            uint32_t :29;
        } CPG_RSTMON_GPU_b;
    };
    union
    {
        __IOM uint32_t CPG_RSTMON_ISU;
        struct
        {
            __IOM uint32_t RST0_MON:1;
            __IOM uint32_t RST1_MON:1;
            uint32_t :30;
        } CPG_RSTMON_ISU_b;
    };
    union
    {
        __IOM uint32_t CPG_RSTMON_H264;
        struct
        {
            __IOM uint32_t RST0_MON:1;
            __IOM uint32_t RST1_MON:1;
            uint32_t :30;
        } CPG_RSTMON_H264_b;
    };
    union
    {
        __IOM uint32_t CPG_RSTMON_CRU;
        struct
        {
            __IOM uint32_t RST0_MON:1;
            __IOM uint32_t RST1_MON:1;
            __IOM uint32_t RST2_MON:1;
            uint32_t :29;
        } CPG_RSTMON_CRU_b;
    };
    union
    {
        __IOM uint32_t CPG_RSTMON_MIPI_DSI;
        struct
        {
            __IOM uint32_t RST0_MON:1;
            __IOM uint32_t RST1_MON:1;
            __IOM uint32_t RST2_MON:1;
            uint32_t :29;
        } CPG_RSTMON_MIPI_DSI_b;
    };
    union
    {
        __IOM uint32_t CPG_RSTMON_LCDC;
        struct
        {
            __IOM uint32_t RST0_MON:1;
            uint32_t :31;
        } CPG_RSTMON_LCDC_b;
    };
    union
    {
        __IOM uint32_t CPG_RSTMON_SSIF;
        struct
        {
            __IOM uint32_t RST0_MON:1;
            __IOM uint32_t RST1_MON:1;
            __IOM uint32_t RST2_MON:1;
            __IOM uint32_t RST3_MON:1;
            uint32_t :28;
        } CPG_RSTMON_SSIF_b;
    };
    union
    {
        __IOM uint32_t CPG_RSTMON_SRC;
        struct
        {
            __IOM uint32_t RST0_MON:1;
            uint32_t :31;
        } CPG_RSTMON_SRC_b;
    };
    union
    {
        __IOM uint32_t CPG_RSTMON_USB;
        struct
        {
            __IOM uint32_t RST0_MON:1;
            __IOM uint32_t RST1_MON:1;
            __IOM uint32_t RST2_MON:1;
            __IOM uint32_t RST3_MON:1;
            uint32_t :28;
        } CPG_RSTMON_USB_b;
    };
    union
    {
        __IOM uint32_t CPG_RSTMON_ETH;
        struct
        {
            __IOM uint32_t RST0_MON:1;
            __IOM uint32_t RST1_MON:1;
            uint32_t :30;
        } CPG_RSTMON_ETH_b;
    };
    union
    {
        __IOM uint32_t CPG_RSTMON_I2C;
        struct
        {
            __IOM uint32_t RST0_MON:1;
            __IOM uint32_t RST1_MON:1;
            __IOM uint32_t RST2_MON:1;
            __IOM uint32_t RST3_MON:1;
            uint32_t :28;
        } CPG_RSTMON_I2C_b;
    };
    union
    {
        __IOM uint32_t CPG_RSTMON_SCIF;
        struct
        {
            __IOM uint32_t RST0_MON:1;
            __IOM uint32_t RST1_MON:1;
            __IOM uint32_t RST2_MON:1;
            __IOM uint32_t RST3_MON:1;
            __IOM uint32_t RST4_MON:1;
            uint32_t :27;
        } CPG_RSTMON_SCIF_b;
    };
    union
    {
        __IOM uint32_t CPG_RSTMON_SCI;
        struct
        {
            __IOM uint32_t RST0_MON:1;
            __IOM uint32_t RST1_MON:1;
            uint32_t :30;
        } CPG_RSTMON_SCI_b;
    };
    union
    {
        __IOM uint32_t CPG_RSTMON_IRDA;
        struct
        {
            __IOM uint32_t RST0_MON:1;
            uint32_t :31;
        } CPG_RSTMON_IRDA_b;
    };
    union
    {
        __IOM uint32_t CPG_RSTMON_RSPI;
        struct
        {
            __IOM uint32_t RST0_MON:1;
            __IOM uint32_t RST1_MON:1;
            __IOM uint32_t RST2_MON:1;
            uint32_t :29;
        } CPG_RSTMON_RSPI_b;
    };
    union
    {
        __IOM uint32_t CPG_RSTMON_CANFD;
        struct
        {
            __IOM uint32_t RST0_MON:1;
            __IOM uint32_t RST1_MON:1;
            uint32_t :30;
        } CPG_RSTMON_CANFD_b;
    };
    union
    {
        __IOM uint32_t CPG_RSTMON_GPIO;
        struct
        {
            __IOM uint32_t RST0_MON:1;
            __IOM uint32_t RST1_MON:1;
            __IOM uint32_t RST2_MON:1;
            uint32_t :29;
        } CPG_RSTMON_GPIO_b;
    };
    union
    {
        __IOM uint32_t CPG_RSTMON_TSIPG;
        struct
        {
            __IOM uint32_t RST0_MON:1;
            uint32_t :31;
        } CPG_RSTMON_TSIPG_b;
    };
    union
    {
        __IOM uint32_t CPG_RSTMON_JAUTH;
        struct
        {
            __IOM uint32_t RST0_MON:1;
            uint32_t :31;
        } CPG_RSTMON_JAUTH_b;
    };
    union
    {
        __IOM uint32_t CPG_RSTMON_OTP;
        struct
        {
            __IOM uint32_t RST0_MON:1;
            uint32_t :31;
        } CPG_RSTMON_OTP_b;
    };
    union
    {
        __IOM uint32_t CPG_RSTMON_ADC;
        struct
        {
            __IOM uint32_t RST0_MON:1;
            __IOM uint32_t RST1_MON:1;
            uint32_t :30;
        } CPG_RSTMON_ADC_b;
    };
    union
    {
        __IOM uint32_t CPG_RSTMON_TSU;
        struct
        {
            __IOM uint32_t RST0_MON:1;
            uint32_t :31;
        } CPG_RSTMON_TSU_b;
    };
    union
    {
        __IOM uint32_t CPG_RSTMON_BBGU;
        struct
        {
            __IOM uint32_t RST0_MON:1;
            uint32_t :31;
        } CPG_RSTMON_BBGU_b;
    };
    union
    {
        __IOM uint32_t CPG_RSTMON_AXI_ACPU_BUS;
        struct
        {
            __IOM uint32_t RST0_MON:1;
            uint32_t :31;
        } CPG_RSTMON_AXI_ACPU_BUS_b;
    };
    union
    {
        __IOM uint32_t CPG_RSTMON_AXI_MCPU_BUS;
        struct
        {
            __IOM uint32_t RST0_MON:1;
            uint32_t :31;
        } CPG_RSTMON_AXI_MCPU_BUS_b;
    };
    union
    {
        __IOM uint32_t CPG_RSTMON_AXI_COM_BUS;
        struct
        {
            __IOM uint32_t RST0_MON:1;
            uint32_t :31;
        } CPG_RSTMON_AXI_COM_BUS_b;
    };
    union
    {
        __IOM uint32_t CPG_RSTMON_AXI_VIDEO_BUS;
        struct
        {
            __IOM uint32_t RST0_MON:1;
            uint32_t :31;
        } CPG_RSTMON_AXI_VIDEO_BUS_b;
    };
    union
    {
        __IOM uint32_t CPG_RSTMON_PERI_COM;
        struct
        {
            __IOM uint32_t RST0_MON:1;
            uint32_t :31;
        } CPG_RSTMON_PERI_COM_b;
    };
    union
    {
        __IOM uint32_t CPG_RSTMON_REG1_BUS;
        struct
        {
            __IOM uint32_t RST0_MON:1;
            uint32_t :31;
        } CPG_RSTMON_REG1_BUS_b;
    };
    union
    {
        __IOM uint32_t CPG_RSTMON_REG0_BUS;
        struct
        {
            __IOM uint32_t RST0_MON:1;
            uint32_t :31;
        } CPG_RSTMON_REG0_BUS_b;
    };
    union
    {
        __IOM uint32_t CPG_RSTMON_PERI_CPU;
        struct
        {
            __IOM uint32_t RST0_MON:1;
            uint32_t :31;
        } CPG_RSTMON_PERI_CPU_b;
    };
    union
    {
        __IOM uint32_t CPG_RSTMON_PERI_VIDEO;
        struct
        {
            __IOM uint32_t RST0_MON:1;
            uint32_t :31;
        } CPG_RSTMON_PERI_VIDEO_b;
    };
    union
    {
        __IOM uint32_t CPG_RSTMON_PERI_DDR;
        struct
        {
            __IOM uint32_t RST0_MON:1;
            uint32_t :31;
        } CPG_RSTMON_PERI_DDR_b;
    };
    union
    {
        __IOM uint32_t CPG_RSTMON_AXI_TZCDDR;
        struct
        {
            __IOM uint32_t RST0_MON:1;
            __IOM uint32_t RST1_MON:1;
            __IOM uint32_t RST2_MON:1;
            __IOM uint32_t RST3_MON:1;
            __IOM uint32_t RST4_MON:1;
            uint32_t :27;
        } CPG_RSTMON_AXI_TZCDDR_b;
    };
    union
    {
        __IOM uint32_t CPG_RSTMON_MTGPGS;
        struct
        {
            __IOM uint32_t RST0_MON:1;
            __IOM uint32_t RST1_MON:1;
            uint32_t :30;
        } CPG_RSTMON_MTGPGS_b;
    };
    union
    {
        __IOM uint32_t CPG_RSTMON_AXI_DEFAULT_SLV;
        struct
        {
            __IOM uint32_t RST0_MON:1;
            uint32_t :31;
        } CPG_RSTMON_AXI_DEFAULT_SLV_b;
    };
    __IM uint8_t        RESERVED17[152];
    union
    {
        __IOM uint32_t CPG_EN_GTM;
        struct
        {
            __IOM uint32_t EN0_ON:1;
            __IOM uint32_t EN1_ON:1;
            __IOM uint32_t EN2_ON:1;
            uint32_t :13;
            __IOM uint32_t EN0WEN:1;
            __IOM uint32_t EN1WEN:1;
            __IOM uint32_t EN2WEN:1;
            uint32_t :13;
        } CPG_EN_GTM_b;
    };
    __IM uint8_t        RESERVED18[12];
    union
    {
        __IOM uint32_t CPG_WDTOVF_RST;
        struct
        {
            __IOM uint32_t WDTOVF0:1;
            __IOM uint32_t WDTOVF1:1;
            __IOM uint32_t WDTOVF2:1;
            uint32_t :13;
            __IOM uint32_t WDTOVF0_WEN:1;
            __IOM uint32_t WDTOVF1_WEN:1;
            __IOM uint32_t WDTOVF2_WEN:1;
            uint32_t :13;
        } CPG_WDTOVF_RST_b;
    };
    union
    {
        __IOM uint32_t CPG_WDTRST_SEL;
        struct
        {
            __IOM uint32_t WDTRSTSEL0:1;
            __IOM uint32_t WDTRSTSEL1:1;
            __IOM uint32_t WDTRSTSEL2:1;
            uint32_t :1;
            __IOM uint32_t WDTRSTSEL4:1;
            __IOM uint32_t WDTRSTSEL5:1;
            __IOM uint32_t WDTRSTSEL6:1;
            uint32_t :1;
            __IOM uint32_t WDTRSTSEL8:1;
            __IOM uint32_t WDTRSTSEL9:1;
            __IOM uint32_t WDTRSTSEL10:1;
            uint32_t :5;
            __IOM uint32_t WDTRSTSEL0_WEN:1;
            __IOM uint32_t WDTRSTSEL1_WEN:1;
            __IOM uint32_t WDTRSTSEL2_WEN:1;
            uint32_t :1;
            __IOM uint32_t WDTRSTSEL4_WEN:1;
            __IOM uint32_t WDTRSTSEL5_WEN:1;
            __IOM uint32_t WDTRSTSEL6_WEN:1;
            uint32_t :1;
            __IOM uint32_t WDTRSTSEL8_WEN:1;
            __IOM uint32_t WDTRSTSEL9_WEN:1;
            __IOM uint32_t WDTRSTSEL10_WEN:1;
            uint32_t :5;
        } CPG_WDTRST_SEL_b;
    };
    __IM uint8_t        RESERVED19[24];
    union
    {
        __IM uint32_t CPG_CLUSTER_PCHMON;
        struct
        {
            __IM uint32_t PACCEPT_MON:1;
            __IM uint32_t PDENY_MON:1;
            uint32_t :30;
        } CPG_CLUSTER_PCHMON_b;
    };
    union
    {
        __IOM uint32_t CPG_CLUSTER_PCHCTL;
        struct
        {
            __IOM uint32_t PREQ_SET:1;
            uint32_t :15;
            __IOM uint32_t PSTATE0_SET:7;
            uint32_t :9;
        } CPG_CLUSTER_PCHCTL_b;
    };
    union
    {
        __IM uint32_t CPG_CORE0_PCHMON;
        struct
        {
            __IM uint32_t PACCEPT0_MON:1;
            __IM uint32_t PDENY0_MON:1;
            uint32_t :30;
        } CPG_CORE0_PCHMON_b;
    };
    union
    {
        __IOM uint32_t CPG_CORE0_PCHCTL;
        struct
        {
            __IOM uint32_t PREQ0_SET:1;
            uint32_t :15;
            __IOM uint32_t PSTATE0_SET:6;
            uint32_t :10;
        } CPG_CORE0_PCHCTL_b;
    };
    union
    {
        __IM uint32_t CPG_CORE1_PCHMON;
        struct
        {
            __IM uint32_t PACCEPT1_MON:1;
            __IM uint32_t PDENY1_MON:1;
            uint32_t :30;
        } CPG_CORE1_PCHMON_b;
    };
    union
    {
        __IOM uint32_t CPG_CORE1_PCHCTL;
        struct
        {
            __IOM uint32_t PREQ1_SET:1;
            uint32_t :15;
            __IOM uint32_t PSTATE1_SET:6;
            uint32_t :10;
        } CPG_CORE1_PCHCTL_b;
    };
    __IM uint8_t        RESERVED20[24];
    union
    {
        __IOM uint32_t CPG_BUS_ACPU_MSTOP;
        struct
        {
            __IOM uint32_t MSTOP0_ON:1;
            uint32_t :15;
            __IOM uint32_t MSTOP0_ON_WEN:1;
            uint32_t :15;
        } CPG_BUS_ACPU_MSTOP_b;
    };
    union
    {
        __IOM uint32_t CPG_BUS_MCPU1_MSTOP;
        struct
        {
            __IOM uint32_t MSTOP0_ON:1;
            __IOM uint32_t MSTOP1_ON:1;
            __IOM uint32_t MSTOP2_ON:1;
            __IOM uint32_t MSTOP3_ON:1;
            __IOM uint32_t MSTOP4_ON:1;
            __IOM uint32_t MSTOP5_ON:1;
            __IOM uint32_t MSTOP6_ON:1;
            __IOM uint32_t MSTOP7_ON:1;
            __IOM uint32_t MSTOP8_ON:1;
            __IOM uint32_t MSTOP9_ON:1;
            __IOM uint32_t MSTOP10_ON:1;
            __IOM uint32_t MSTOP11_ON:1;
            __IOM uint32_t MSTOP12_ON:1;
            __IOM uint32_t MSTOP13_ON:1;
            __IOM uint32_t MSTOP14_ON:1;
            __IOM uint32_t MSTOP15_ON:1;
            __IOM uint32_t MSTOP0_ON_WEN:1;
            __IOM uint32_t MSTOP1_ON_WEN:1;
            __IOM uint32_t MSTOP2_ON_WEN:1;
            __IOM uint32_t MSTOP3_ON_WEN:1;
            __IOM uint32_t MSTOP4_ON_WEN:1;
            __IOM uint32_t MSTOP5_ON_WEN:1;
            __IOM uint32_t MSTOP6_ON_WEN:1;
            __IOM uint32_t MSTOP7_ON_WEN:1;
            __IOM uint32_t MSTOP8_ON_WEN:1;
            __IOM uint32_t MSTOP9_ON_WEN:1;
            __IOM uint32_t MSTOP10_ON_WEN:1;
            __IOM uint32_t MSTOP11_ON_WEN:1;
            __IOM uint32_t MSTOP12_ON_WEN:1;
            __IOM uint32_t MSTOP13_ON_WEN:1;
            __IOM uint32_t MSTOP14_ON_WEN:1;
            __IOM uint32_t MSTOP15_ON_WEN:1;
        } CPG_BUS_MCPU1_MSTOP_b;
    };
    union
    {
        __IOM uint32_t CPG_BUS_MCPU2_MSTOP;
        struct
        {
            __IOM uint32_t MSTOP0_ON:1;
            __IOM uint32_t MSTOP1_ON:1;
            __IOM uint32_t MSTOP2_ON:1;
            __IOM uint32_t MSTOP3_ON:1;
            __IOM uint32_t MSTOP4_ON:1;
            __IOM uint32_t MSTOP5_ON:1;
            __IOM uint32_t MSTOP6_ON:1;
            __IOM uint32_t MSTOP7_ON:1;
            __IOM uint32_t MSTOP8_ON:1;
            __IOM uint32_t MSTOP9_ON:1;
            __IOM uint32_t MSTOP10_ON:1;
            __IOM uint32_t MSTOP11_ON:1;
            __IOM uint32_t MSTOP12_ON:1;
            __IOM uint32_t MSTOP13_ON:1;
            __IOM uint32_t MSTOP14_ON:1;
            __IOM uint32_t MSTOP15_ON:1;
            __IOM uint32_t MSTOP0_ON_WEN:1;
            __IOM uint32_t MSTOP1_ON_WEN:1;
            __IOM uint32_t MSTOP2_ON_WEN:1;
            __IOM uint32_t MSTOP3_ON_WEN:1;
            __IOM uint32_t MSTOP4_ON_WEN:1;
            __IOM uint32_t MSTOP5_ON_WEN:1;
            __IOM uint32_t MSTOP6_ON_WEN:1;
            __IOM uint32_t MSTOP7_ON_WEN:1;
            __IOM uint32_t MSTOP8_ON_WEN:1;
            __IOM uint32_t MSTOP9_ON_WEN:1;
            __IOM uint32_t MSTOP10_ON_WEN:1;
            __IOM uint32_t MSTOP11_ON_WEN:1;
            __IOM uint32_t MSTOP12_ON_WEN:1;
            __IOM uint32_t MSTOP13_ON_WEN:1;
            __IOM uint32_t MSTOP14_ON_WEN:1;
            __IOM uint32_t MSTOP15_ON_WEN:1;
        } CPG_BUS_MCPU2_MSTOP_b;
    };
    union
    {
        __IOM uint32_t CPG_BUS_PERI_COM_MSTOP;
        struct
        {
            __IOM uint32_t MSTOP0_ON:1;
            __IOM uint32_t MSTOP1_ON:1;
            __IOM uint32_t MSTOP2_ON:1;
            __IOM uint32_t MSTOP3_ON:1;
            __IOM uint32_t MSTOP4_ON:1;
            __IOM uint32_t MSTOP5_ON:1;
            __IOM uint32_t MSTOP6_ON:1;
            __IOM uint32_t MSTOP7_ON:1;
            __IOM uint32_t MSTOP8_ON:1;
            uint32_t :7;
            __IOM uint32_t MSTOP0_ON_WEN:1;
            __IOM uint32_t MSTOP1_ON_WEN:1;
            __IOM uint32_t MSTOP2_ON_WEN:1;
            __IOM uint32_t MSTOP3_ON_WEN:1;
            __IOM uint32_t MSTOP4_ON_WEN:1;
            __IOM uint32_t MSTOP5_ON_WEN:1;
            __IOM uint32_t MSTOP6_ON_WEN:1;
            __IOM uint32_t MSTOP7_ON_WEN:1;
            __IOM uint32_t MSTOP8_ON_WEN:1;
            uint32_t :7;
        } CPG_BUS_PERI_COM_MSTOP_b;
    };
    union
    {
        __IOM uint32_t CPG_BUS_PERI_CPU_MSTOP;
        struct
        {
            __IOM uint32_t MSTOP0_ON:1;
            __IOM uint32_t MSTOP1_ON:1;
            __IOM uint32_t MSTOP2_ON:1;
            __IOM uint32_t MSTOP3_ON:1;
            __IOM uint32_t MSTOP4_ON:1;
            uint32_t :1;
            __IOM uint32_t MSTOP6_ON:1;
            __IOM uint32_t MSTOP7_ON:1;
            __IOM uint32_t MSTOP8_ON:1;
            __IOM uint32_t MSTOP9_ON:1;
            __IOM uint32_t MSTOP10_ON:1;
            __IOM uint32_t MSTOP11_ON:1;
            __IOM uint32_t MSTOP12_ON:1;
            __IOM uint32_t MSTOP13_ON:1;
            __IOM uint32_t MSTOP14_ON:1;
            __IOM uint32_t MSTOP15_ON:1;
            __IOM uint32_t MSTOP0_ON_WEN:1;
            __IOM uint32_t MSTOP1_ON_WEN:1;
            __IOM uint32_t MSTOP2_ON_WEN:1;
            __IOM uint32_t MSTOP3_ON_WEN:1;
            __IOM uint32_t MSTOP4_ON_WEN:1;
            __IOM uint32_t MSTOP5_ON_WEN:1;
            __IOM uint32_t MSTOP6_ON_WEN:1;
            __IOM uint32_t MSTOP7_ON_WEN:1;
            __IOM uint32_t MSTOP8_ON_WEN:1;
            __IOM uint32_t MSTOP9_ON_WEN:1;
            __IOM uint32_t MSTOP10_ON_WEN:1;
            __IOM uint32_t MSTOP11_ON_WEN:1;
            __IOM uint32_t MSTOP12_ON_WEN:1;
            __IOM uint32_t MSTOP13_ON_WEN:1;
            __IOM uint32_t MSTOP14_ON_WEN:1;
            __IOM uint32_t MSTOP15_ON_WEN:1;
        } CPG_BUS_PERI_CPU_MSTOP_b;
    };
    union
    {
        __IOM uint32_t CPG_BUS_PERI_DDR_MSTOP;
        struct
        {
            __IOM uint32_t MSTOP0_ON:1;
            __IOM uint32_t MSTOP1_ON:1;
            uint32_t :14;
            __IOM uint32_t MSTOP0_ON_WEN:1;
            __IOM uint32_t MSTOP1_ON_WEN:1;
            uint32_t :14;
        } CPG_BUS_PERI_DDR_MSTOP_b;
    };
    union
    {
        __IOM uint32_t CPG_BUS_PERI_VIDEO_MSTOP;
        struct
        {
            __IOM uint32_t MSTOP0_ON:1;
            __IOM uint32_t MSTOP1_ON:1;
            __IOM uint32_t MSTOP2_ON:1;
            __IOM uint32_t MSTOP3_ON:1;
            __IOM uint32_t MSTOP4_ON:1;
            __IOM uint32_t MSTOP5_ON:1;
            __IOM uint32_t MSTOP6_ON:1;
            __IOM uint32_t MSTOP7_ON:1;
            __IOM uint32_t MSTOP8_ON:1;
            __IOM uint32_t MSTOP9_ON:1;
            __IOM uint32_t MSTOP10_ON:1;
            uint32_t :5;
            __IOM uint32_t MSTOP0_ON_WEN:1;
            __IOM uint32_t MSTOP1_ON_WEN:1;
            __IOM uint32_t MSTOP2_ON_WEN:1;
            __IOM uint32_t MSTOP3_ON_WEN:1;
            __IOM uint32_t MSTOP4_ON_WEN:1;
            __IOM uint32_t MSTOP5_ON_WEN:1;
            __IOM uint32_t MSTOP6_ON_WEN:1;
            __IOM uint32_t MSTOP7_ON_WEN:1;
            __IOM uint32_t MSTOP8_ON_WEN:1;
            __IOM uint32_t MSTOP9_ON_WEN:1;
            __IOM uint32_t MSTOP10_ON_WEN:1;
            uint32_t :5;
        } CPG_BUS_PERI_VIDEO_MSTOP_b;
    };
    union
    {
        __IOM uint32_t CPG_BUS_REG0_MSTOP;
        struct
        {
            __IOM uint32_t MSTOP0_ON:1;
            __IOM uint32_t MSTOP1_ON:1;
            __IOM uint32_t MSTOP2_ON:1;
            __IOM uint32_t MSTOP3_ON:1;
            __IOM uint32_t MSTOP4_ON:1;
            __IOM uint32_t MSTOP5_ON:1;
            __IOM uint32_t MSTOP6_ON:1;
            uint32_t :9;
            __IOM uint32_t MSTOP0_ON_WEN:1;
            __IOM uint32_t MSTOP1_ON_WEN:1;
            __IOM uint32_t MSTOP2_ON_WEN:1;
            __IOM uint32_t MSTOP3_ON_WEN:1;
            __IOM uint32_t MSTOP4_ON_WEN:1;
            __IOM uint32_t MSTOP5_ON_WEN:1;
            __IOM uint32_t MSTOP6_ON_WEN:1;
            uint32_t :9;
        } CPG_BUS_REG0_MSTOP_b;
    };
    union
    {
        __IOM uint32_t CPG_BUS_REG1_MSTOP;
        struct
        {
            __IOM uint32_t MSTOP0_ON:1;
            __IOM uint32_t MSTOP1_ON:1;
            __IOM uint32_t MSTOP2_ON:1;
            __IOM uint32_t MSTOP3_ON:1;
            __IOM uint32_t MSTOP4_ON:1;
            __IOM uint32_t MSTOP5_ON:1;
            __IOM uint32_t MSTOP6_ON:1;
            __IOM uint32_t MSTOP7_ON:1;
            uint32_t :8;
            __IOM uint32_t MSTOP0_ON_WEN:1;
            __IOM uint32_t MSTOP1_ON_WEN:1;
            __IOM uint32_t MSTOP2_ON_WEN:1;
            __IOM uint32_t MSTOP3_ON_WEN:1;
            __IOM uint32_t MSTOP4_ON_WEN:1;
            __IOM uint32_t MSTOP5_ON_WEN:1;
            __IOM uint32_t MSTOP6_ON_WEN:1;
            __IOM uint32_t MSTOP7_ON_WEN:1;
            uint32_t :8;
        } CPG_BUS_REG1_MSTOP_b;
    };
    union
    {
        __IOM uint32_t CPG_BUS_TZCDDR_MSTOP;
        struct
        {
            __IOM uint32_t MSTOP0_ON:1;
            __IOM uint32_t MSTOP1_ON:1;
            __IOM uint32_t MSTOP2_ON:1;
            __IOM uint32_t MSTOP3_ON:1;
            uint32_t :12;
            __IOM uint32_t MSTOP0_ON_WEN:1;
            __IOM uint32_t MSTOP1_ON_WEN:1;
            __IOM uint32_t MSTOP2_ON_WEN:1;
            __IOM uint32_t MSTOP3_ON_WEN:1;
            uint32_t :12;
        } CPG_BUS_TZCDDR_MSTOP_b;
    };
    union
    {
        __IOM uint32_t CPG_MHU_MSTOP;
        struct
        {
            __IOM uint32_t MSTOP0_ON:1;
            uint32_t :15;
            __IOM uint32_t MSTOP0_ON_WEN:1;
            uint32_t :15;
        } CPG_MHU_MSTOP_b;
    };
    __IM uint8_t        RESERVED21[92];
    union
    {
        __IOM uint32_t CPG_OTHERFUNC1_REG;
        struct
        {
            __IOM uint32_t RES0_SET:1;
            uint32_t :15;
            __IOM uint32_t RES0_ON_WEN:1;
            __IOM uint32_t RES1_ON_WEN:1;
            __IOM uint32_t RES2_ON_WEN:1;
            __IOM uint32_t RES3_ON_WEN:1;
            __IOM uint32_t RES4_ON_WEN:1;
            __IOM uint32_t RES5_ON_WEN:1;
            __IOM uint32_t RES6_ON_WEN:1;
            __IOM uint32_t RES7_ON_WEN:1;
            __IOM uint32_t RES8_ON_WEN:1;
            __IOM uint32_t RES9_ON_WEN:1;
            __IOM uint32_t RES10_ON_WEN:1;
            __IOM uint32_t RES11_ON_WEN:1;
            __IOM uint32_t RES12_ON_WEN:1;
            __IOM uint32_t RES13_ON_WEN:1;
            __IOM uint32_t RES14_ON_WEN:1;
            __IOM uint32_t RES15_ON_WEN:1;
        } CPG_OTHERFUNC1_REG_b;
    };
    union
    {
        __IOM uint32_t CPG_OTHERFUNC2_REG;
        struct
        {
            __IOM uint32_t RES0_SET:1;
            uint32_t :15;
            __IOM uint32_t RES0_ON_WEN:1;
            __IOM uint32_t RES1_ON_WEN:1;
            __IOM uint32_t RES2_ON_WEN:1;
            __IOM uint32_t RES3_ON_WEN:1;
            __IOM uint32_t RES4_ON_WEN:1;
            __IOM uint32_t RES5_ON_WEN:1;
            __IOM uint32_t RES6_ON_WEN:1;
            __IOM uint32_t RES7_ON_WEN:1;
            __IOM uint32_t RES8_ON_WEN:1;
            __IOM uint32_t RES9_ON_WEN:1;
            __IOM uint32_t RES10_ON_WEN:1;
            __IOM uint32_t RES11_ON_WEN:1;
            __IOM uint32_t RES12_ON_WEN:1;
            __IOM uint32_t RES13_ON_WEN:1;
            __IOM uint32_t RES14_ON_WEN:1;
            __IOM uint32_t RES15_ON_WEN:1;
        } CPG_OTHERFUNC2_REG_b;
    };
} R_CPG_Type;

/* =========================================================================================================================== */
/* ================                          Device Specific Peripheral Address Map                           ================ */
/* =========================================================================================================================== */

#define R_CPG_BASE     0x41010000

/* =========================================================================================================================== */
/* ================                                  Peripheral declaration                                   ================ */
/* =========================================================================================================================== */

#define R_CPG     ((R_CPG_Type     *) R_CPG_BASE)

#endif
