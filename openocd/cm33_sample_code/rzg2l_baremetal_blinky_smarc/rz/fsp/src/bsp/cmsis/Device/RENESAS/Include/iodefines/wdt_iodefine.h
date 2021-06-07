/* =========================================================================================================================== */
/* ================                              Device Specific Cluster Section                              ================ */
/* =========================================================================================================================== */

/* =========================================================================================================================== */
/* ================                            Device Specific Peripheral Section                             ================ */
/* =========================================================================================================================== */

#ifndef WDT_IODEFINE_H
#define WDT_IODEFINE_H

typedef struct
{
    union
    {
        __IOM uint32_t WDTCNT_2;
        struct
        {
            __IOM uint32_t WDTEN:1;
            uint32_t :31;
        } WDTCNT_2_b;
    };
    union
    {
        __IOM uint32_t WDTSET_2;
        struct
        {
            uint32_t :20;
            __IOM uint32_t WDTTIME:12;
        } WDTSET_2_b;
    };
    union
    {
        __IOM uint32_t WDTTIM_2;
        struct
        {
            __IOM uint32_t CRTTIME:32;
        } WDTTIM_2_b;
    };
    union
    {
        __IOM uint32_t WDTINT_2;
        struct
        {
            __IOM uint32_t INTDISP:1;
            uint32_t :31;
        } WDTINT_2_b;
    };
    union
    {
        __IOM uint32_t PECR_2;
        struct
        {
            __IOM uint32_t PECR:32;
        } PECR_2_b;
    };
    union
    {
        __IOM uint32_t PEEN_2;
        struct
        {
            __IOM uint32_t PEEN:1;
            uint32_t :31;
        } PEEN_2_b;
    };
    union
    {
        __IOM uint32_t PESR_2;
        struct
        {
            __IOM uint32_t PESR:32;
        } PESR_2_b;
    };
    union
    {
        __IOM uint32_t PEER_2;
        struct
        {
            __IOM uint32_t PEER:32;
        } PEER_2_b;
    };
    union
    {
        __IOM uint32_t PEPO_2;
        struct
        {
            __IOM uint32_t PEPO:32;
        } PEPO_2_b;
    };
    __IM uint8_t        RESERVED[988];
    union
    {
        __IOM uint32_t WDTCNT_0;
        struct
        {
            __IOM uint32_t WDTEN:1;
            uint32_t :31;
        } WDTCNT_0_b;
    };
    union
    {
        __IOM uint32_t WDTSET_0;
        struct
        {
            uint32_t :20;
            __IOM uint32_t WDTTIME:12;
        } WDTSET_0_b;
    };
    union
    {
        __IOM uint32_t WDTTIM_0;
        struct
        {
            __IOM uint32_t CRTTIME:32;
        } WDTTIM_0_b;
    };
    union
    {
        __IOM uint32_t WDTINT_0;
        struct
        {
            __IOM uint32_t INTDISP:1;
            uint32_t :31;
        } WDTINT_0_b;
    };
    union
    {
        __IOM uint32_t PECR_0;
        struct
        {
            __IOM uint32_t PECR:32;
        } PECR_0_b;
    };
    union
    {
        __IOM uint32_t PEEN_0;
        struct
        {
            __IOM uint32_t PEEN:1;
            uint32_t :31;
        } PEEN_0_b;
    };
    union
    {
        __IOM uint32_t PESR_0;
        struct
        {
            __IOM uint32_t PESR:32;
        } PESR_0_b;
    };
    union
    {
        __IOM uint32_t PEER_0;
        struct
        {
            __IOM uint32_t PEER:32;
        } PEER_0_b;
    };
    union
    {
        __IOM uint32_t PEPO_0;
        struct
        {
            __IOM uint32_t PEPO:32;
        } PEPO_0_b;
    };
    __IM uint8_t        RESERVED1[988];
    union
    {
        __IOM uint32_t WDTCNT_1;
        struct
        {
            __IOM uint32_t WDTEN:1;
            uint32_t :31;
        } WDTCNT_1_b;
    };
    union
    {
        __IOM uint32_t WDTSET_1;
        struct
        {
            uint32_t :20;
            __IOM uint32_t WDTTIME:12;
        } WDTSET_1_b;
    };
    union
    {
        __IOM uint32_t WDTTIM_1;
        struct
        {
            __IOM uint32_t CRTTIME:32;
        } WDTTIM_1_b;
    };
    union
    {
        __IOM uint32_t WDTINT_1;
        struct
        {
            __IOM uint32_t INTDISP:1;
            uint32_t :31;
        } WDTINT_1_b;
    };
    union
    {
        __IOM uint32_t PECR_1;
        struct
        {
            __IOM uint32_t PECR:32;
        } PECR_1_b;
    };
    union
    {
        __IOM uint32_t PEEN_1;
        struct
        {
            __IOM uint32_t PEEN:1;
            uint32_t :31;
        } PEEN_1_b;
    };
    union
    {
        __IOM uint32_t PESR_1;
        struct
        {
            __IOM uint32_t PESR:32;
        } PESR_1_b;
    };
    union
    {
        __IOM uint32_t PEER_1;
        struct
        {
            __IOM uint32_t PEER:32;
        } PEER_1_b;
    };
    union
    {
        __IOM uint32_t PEPO_1;
        struct
        {
            __IOM uint32_t PEPO:32;
        } PEPO_1_b;
    };
} R_WDT_Type;

/* =========================================================================================================================== */
/* ================                          Device Specific Peripheral Address Map                           ================ */
/* =========================================================================================================================== */

#define R_WDT_BASE     0x42800400

/* =========================================================================================================================== */
/* ================                                  Peripheral declaration                                   ================ */
/* =========================================================================================================================== */

#define R_WDT     ((R_WDT_Type     *) R_WDT_BASE)

#endif
