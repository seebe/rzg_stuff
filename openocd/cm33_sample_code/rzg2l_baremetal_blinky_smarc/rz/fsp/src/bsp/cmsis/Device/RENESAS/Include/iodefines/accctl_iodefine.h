/* =========================================================================================================================== */
/* ================                              Device Specific Cluster Section                              ================ */
/* =========================================================================================================================== */

/* =========================================================================================================================== */
/* ================                            Device Specific Peripheral Section                             ================ */
/* =========================================================================================================================== */

#ifndef ACCCTL_IODEFINE_H
#define ACCCTL_IODEFINE_H

typedef struct                          /*!< R_ACCCTL_Type Structure                                                     */
{
    __IOM uint32_t SYS_SLVACCCTL0;
    __IOM uint32_t SYS_SLVACCCTL1;
    __IOM uint32_t SYS_SLVACCCTL2;
    __IOM uint32_t SYS_SLVACCCTL3;
    __IOM uint32_t SYS_SLVACCCTL4;
    __IOM uint32_t SYS_SLVACCCTL5;
    __IOM uint32_t SYS_SLVACCCTL6;
    __IOM uint32_t SYS_SLVACCCTL7;
    __IOM uint32_t SYS_SLVACCCTL8;
    __IOM uint32_t SYS_SLVACCCTL9;
    __IOM uint32_t SYS_SLVACCCTL10;
    __IOM uint32_t SYS_SLVACCCTL11;
    __IOM uint32_t SYS_SLVACCCTL12;
    __IOM uint32_t SYS_SLVACCCTL13;
    __IOM uint32_t SYS_SLVACCCTL14;
    __IOM uint32_t SYS_SLVACCCTL15;

} R_ACCCTL_Type;                        /*!<                                                                             */


/* =========================================================================================================================== */
/* ================                          Device Specific Peripheral Address Map                           ================ */
/* =========================================================================================================================== */

#define R_ACCCTL_BASE_S               0x51020100 /* Access Control(Secure)*/

/* =========================================================================================================================== */
/* ================                                  Peripheral declaration                                   ================ */
/* =========================================================================================================================== */

#define R_ACCCTL_S              ((R_ACCCTL_Type *) R_ACCCTL_BASE_S)

#endif
