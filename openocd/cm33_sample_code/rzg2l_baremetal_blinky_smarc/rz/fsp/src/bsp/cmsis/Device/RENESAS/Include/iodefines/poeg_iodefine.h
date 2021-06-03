/* =========================================================================================================================== */
/* ================                              Device Specific Cluster Section                              ================ */
/* =========================================================================================================================== */

/* =========================================================================================================================== */
/* ================                            Device Specific Peripheral Section                             ================ */
/* =========================================================================================================================== */

#ifndef POEG_IODEFINE_H
#define POEG_IODEFINE_H

typedef struct
{
    union
    {
        __IOM uint32_t POEGGA;
        struct
        {
            __IOM uint32_t PIDF:1;
            __IOM uint32_t IOCF:1;
            uint32_t :1;
            __IOM uint32_t SSF:1;
            __IOM uint32_t PIDE:1;
            __IOM uint32_t IOCE:1;
            uint32_t :10;
            __IM uint32_t ST:1;
            uint32_t :11;
            __IOM uint32_t INV:1;
            __IOM uint32_t NFEN:1;
            __IOM uint32_t NFCS:2;
        } POEGGA_b;
    };
    __IM uint8_t        RESERVED[1020];
    union
    {
        __IOM uint32_t POEGGB;
        struct
        {
            __IOM uint32_t PIDF:1;
            __IOM uint32_t IOCF:1;
            uint32_t :1;
            __IOM uint32_t SSF:1;
            __IOM uint32_t PIDE:1;
            __IOM uint32_t IOCE:1;
            uint32_t :10;
            __IM uint32_t ST:1;
            uint32_t :11;
            __IOM uint32_t INV:1;
            __IOM uint32_t NFEN:1;
            __IOM uint32_t NFCS:2;
        } POEGGB_b;
    };
    __IM uint8_t        RESERVED1[1020];
    union
    {
        __IOM uint32_t POEGGC;
        struct
        {
            __IOM uint32_t PIDF:1;
            __IOM uint32_t IOCF:1;
            uint32_t :1;
            __IOM uint32_t SSF:1;
            __IOM uint32_t PIDE:1;
            __IOM uint32_t IOCE:1;
            uint32_t :10;
            __IM uint32_t ST:1;
            uint32_t :11;
            __IOM uint32_t INV:1;
            __IOM uint32_t NFEN:1;
            __IOM uint32_t NFCS:2;
        } POEGGC_b;
    };
    __IM uint8_t        RESERVED2[1020];
    union
    {
        __IOM uint32_t POEGGD;
        struct
        {
            __IOM uint32_t PIDF:1;
            __IOM uint32_t IOCF:1;
            uint32_t :1;
            __IOM uint32_t SSF:1;
            __IOM uint32_t PIDE:1;
            __IOM uint32_t IOCE:1;
            uint32_t :10;
            __IM uint32_t ST:1;
            uint32_t :11;
            __IOM uint32_t INV:1;
            __IOM uint32_t NFEN:1;
            __IOM uint32_t NFCS:2;
        } POEGGD_b;
    };
} R_POEG_Type;

/* =========================================================================================================================== */
/* ================                          Device Specific Peripheral Address Map                           ================ */
/* =========================================================================================================================== */

#define R_POEG_BASE     0x40048800

/* =========================================================================================================================== */
/* ================                                  Peripheral declaration                                   ================ */
/* =========================================================================================================================== */

#define R_POEG     ((R_POEG_Type     *) R_POEG_BASE)

#endif
