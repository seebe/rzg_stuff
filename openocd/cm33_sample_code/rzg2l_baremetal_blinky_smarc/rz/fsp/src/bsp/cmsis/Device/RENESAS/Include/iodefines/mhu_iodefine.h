/* =========================================================================================================================== */
/* ================                              Device Specific Cluster Section                              ================ */
/* =========================================================================================================================== */

/* =========================================================================================================================== */
/* ================                            Device Specific Peripheral Section                             ================ */
/* =========================================================================================================================== */

#ifndef MHU_IODEFINE_H
#define MHU_IODEFINE_H

typedef struct
{
    union
    {
        __IM uint32_t MSG_INT_STSn;
        struct
        {
            __IM uint32_t STAT:1;
            uint32_t :31;
        } MSG_INT_STSn_b;
    };
    union
    {
        __IOM uint32_t MSG_INT_SETn;
        struct
        {
            __IOM uint32_t SET:1;
            uint32_t :31;
        } MSG_INT_SETn_b;
    };
    union
    {
        __IOM uint32_t MSG_INT_CLRn;
        struct
        {
            __IOM uint32_t CLEAR:1;
            uint32_t :31;
        } MSG_INT_CLRn_b;
    };
    __IM uint8_t        RESERVED[4];
    union
    {
        __IM uint32_t RSP_INT_STSn;
        struct
        {
            __IM uint32_t STAT:1;
            uint32_t :31;
        } RSP_INT_STSn_b;
    };
    union
    {
        __IOM uint32_t RSP_INT_SETn;
        struct
        {
            __IOM uint32_t SET:1;
            uint32_t :31;
        } RSP_INT_SETn_b;
    };
    union
    {
        __IOM uint32_t RSP_INT_CLRn;
        struct
        {
            __IOM uint32_t CLEAR:1;
            uint32_t :31;
        } RSP_INT_CLRn_b;
    };
} R_MHU0_Type;

typedef struct
{
    union
    {
        __IM uint32_t SW_INT_STSn;
        struct
        {
            __IM uint32_t STAT:1;
            uint32_t :31;
        } SW_INT_STSn_b;
    };
    union
    {
        __IOM uint32_t SW_INT_SETn;
        struct
        {
            __IOM uint32_t SET:1;
            uint32_t :31;
        } SW_INT_SETn_b;
    };
    union
    {
        __IOM uint32_t SW_INT_CLRn;
        struct
        {
            __IOM uint32_t CLEAR:1;
            uint32_t :31;
        } SW_INT_CLRn_b;
    };
} R_MHU_SWINT0_Type;


/* =========================================================================================================================== */
/* ================                          Device Specific Peripheral Address Map                           ================ */
/* =========================================================================================================================== */

#define R_MHU0_BASE     0x40400000
#define R_MHU1_BASE     0x40400020
#define R_MHU2_BASE     0x40400040
#define R_MHU3_BASE     0x40400060
#define R_MHU4_BASE     0x40400080
#define R_MHU5_BASE     0x404000A0
#define R_MHU_SWINT0_BASE     0x40400800
#define R_MHU_SWINT1_BASE     0x40400810
#define R_MHU_SWINT2_BASE     0x40400820
#define R_MHU_SWINT3_BASE     0x40400830

/* =========================================================================================================================== */
/* ================                                  Peripheral declaration                                   ================ */
/* =========================================================================================================================== */

#define R_MHU0     ((R_MHU0_Type     *) R_MHU0_BASE)
#define R_MHU1     ((R_MHU0_Type     *) R_MHU1_BASE)
#define R_MHU2     ((R_MHU0_Type     *) R_MHU2_BASE)
#define R_MHU3     ((R_MHU0_Type     *) R_MHU3_BASE)
#define R_MHU4     ((R_MHU0_Type     *) R_MHU4_BASE)
#define R_MHU5     ((R_MHU0_Type     *) R_MHU5_BASE)
#define R_MHU_SWINT0     ((R_MHU_SWINT0_Type     *) R_MHU_SWINT0_BASE)
#define R_MHU_SWINT1     ((R_MHU_SWINT0_Type     *) R_MHU_SWINT1_BASE)
#define R_MHU_SWINT2     ((R_MHU_SWINT0_Type     *) R_MHU_SWINT2_BASE)
#define R_MHU_SWINT3     ((R_MHU_SWINT0_Type     *) R_MHU_SWINT3_BASE)

#endif
