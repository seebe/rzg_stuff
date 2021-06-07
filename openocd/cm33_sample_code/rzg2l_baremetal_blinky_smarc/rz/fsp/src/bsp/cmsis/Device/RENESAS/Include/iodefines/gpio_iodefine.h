/* =========================================================================================================================== */
/* ================                              Device Specific Cluster Section                              ================ */
/* =========================================================================================================================== */

/* =========================================================================================================================== */
/* ================                            Device Specific Peripheral Section                             ================ */
/* =========================================================================================================================== */

#ifndef GPIO_IODEFINE_H
#define GPIO_IODEFINE_H

#define _RA6M4_ (1)  /* The parts separated by "if _RA6M4_  endif" need to be deleted in v1.0. */
#if _RA6M4_

/* =========================================================================================================================== */
/* ================                                          R_PORT0                                          ================ */
/* =========================================================================================================================== */

/**
 * @brief I/O Ports (R_PORT0)
 */

typedef struct                         /*!< (@ 0x40040000) R_PORT0 Structure                                          */
{
    union
    {
        union
        {
            __IOM uint32_t PCNTR1;        /*!< (@ 0x00000000) Port Control Register 1                                    */

            struct
            {
                __IOM uint32_t PDR  : 16; /*!< [15..0] Pmn Direction                                                     */
                __IOM uint32_t PODR : 16; /*!< [31..16] Pmn Output Data                                                  */
            } PCNTR1_b;
        };

        struct
        {
            union
            {
                __IOM uint16_t PODR;           /*!< (@ 0x00000000) Output data register                                       */

                struct
                {
                    __IOM uint16_t PODR0  : 1; /*!< [0..0] Pmn Output Data                                                    */
                    __IOM uint16_t PODR1  : 1; /*!< [1..1] Pmn Output Data                                                    */
                    __IOM uint16_t PODR2  : 1; /*!< [2..2] Pmn Output Data                                                    */
                    __IOM uint16_t PODR3  : 1; /*!< [3..3] Pmn Output Data                                                    */
                    __IOM uint16_t PODR4  : 1; /*!< [4..4] Pmn Output Data                                                    */
                    __IOM uint16_t PODR5  : 1; /*!< [5..5] Pmn Output Data                                                    */
                    __IOM uint16_t PODR6  : 1; /*!< [6..6] Pmn Output Data                                                    */
                    __IOM uint16_t PODR7  : 1; /*!< [7..7] Pmn Output Data                                                    */
                    __IOM uint16_t PODR8  : 1; /*!< [8..8] Pmn Output Data                                                    */
                    __IOM uint16_t PODR9  : 1; /*!< [9..9] Pmn Output Data                                                    */
                    __IOM uint16_t PODR10 : 1; /*!< [10..10] Pmn Output Data                                                  */
                    __IOM uint16_t PODR11 : 1; /*!< [11..11] Pmn Output Data                                                  */
                    __IOM uint16_t PODR12 : 1; /*!< [12..12] Pmn Output Data                                                  */
                    __IOM uint16_t PODR13 : 1; /*!< [13..13] Pmn Output Data                                                  */
                    __IOM uint16_t PODR14 : 1; /*!< [14..14] Pmn Output Data                                                  */
                    __IOM uint16_t PODR15 : 1; /*!< [15..15] Pmn Output Data                                                  */
                } PODR_b;
            };

            union
            {
                __IOM uint16_t PDR;           /*!< (@ 0x00000002) Data direction register                                    */

                struct
                {
                    __IOM uint16_t PDR0  : 1; /*!< [0..0] Pmn Direction                                                      */
                    __IOM uint16_t PDR1  : 1; /*!< [1..1] Pmn Direction                                                      */
                    __IOM uint16_t PDR2  : 1; /*!< [2..2] Pmn Direction                                                      */
                    __IOM uint16_t PDR3  : 1; /*!< [3..3] Pmn Direction                                                      */
                    __IOM uint16_t PDR4  : 1; /*!< [4..4] Pmn Direction                                                      */
                    __IOM uint16_t PDR5  : 1; /*!< [5..5] Pmn Direction                                                      */
                    __IOM uint16_t PDR6  : 1; /*!< [6..6] Pmn Direction                                                      */
                    __IOM uint16_t PDR7  : 1; /*!< [7..7] Pmn Direction                                                      */
                    __IOM uint16_t PDR8  : 1; /*!< [8..8] Pmn Direction                                                      */
                    __IOM uint16_t PDR9  : 1; /*!< [9..9] Pmn Direction                                                      */
                    __IOM uint16_t PDR10 : 1; /*!< [10..10] Pmn Direction                                                    */
                    __IOM uint16_t PDR11 : 1; /*!< [11..11] Pmn Direction                                                    */
                    __IOM uint16_t PDR12 : 1; /*!< [12..12] Pmn Direction                                                    */
                    __IOM uint16_t PDR13 : 1; /*!< [13..13] Pmn Direction                                                    */
                    __IOM uint16_t PDR14 : 1; /*!< [14..14] Pmn Direction                                                    */
                    __IOM uint16_t PDR15 : 1; /*!< [15..15] Pmn Direction                                                    */
                } PDR_b;
            };
        };
    };

    union
    {
        union
        {
            __IM uint32_t PCNTR2;        /*!< (@ 0x00000004) Port Control Register 2                                    */

            struct
            {
                __IM uint32_t PIDR : 16; /*!< [15..0] Pmn Input Data                                                    */
                __IM uint32_t EIDR : 16; /*!< [31..16] Pmn Event Input Data                                             */
            } PCNTR2_b;
        };

        struct
        {
            union
            {
                __IM uint16_t EIDR;           /*!< (@ 0x00000004) Event input data register                                  */

                struct
                {
                    __IM uint16_t EIDR0  : 1; /*!< [0..0] Pmn Event Input Data                                               */
                    __IM uint16_t EIDR1  : 1; /*!< [1..1] Pmn Event Input Data                                               */
                    __IM uint16_t EIDR2  : 1; /*!< [2..2] Pmn Event Input Data                                               */
                    __IM uint16_t EIDR3  : 1; /*!< [3..3] Pmn Event Input Data                                               */
                    __IM uint16_t EIDR4  : 1; /*!< [4..4] Pmn Event Input Data                                               */
                    __IM uint16_t EIDR5  : 1; /*!< [5..5] Pmn Event Input Data                                               */
                    __IM uint16_t EIDR6  : 1; /*!< [6..6] Pmn Event Input Data                                               */
                    __IM uint16_t EIDR7  : 1; /*!< [7..7] Pmn Event Input Data                                               */
                    __IM uint16_t EIDR8  : 1; /*!< [8..8] Pmn Event Input Data                                               */
                    __IM uint16_t EIDR9  : 1; /*!< [9..9] Pmn Event Input Data                                               */
                    __IM uint16_t EIDR10 : 1; /*!< [10..10] Pmn Event Input Data                                             */
                    __IM uint16_t EIDR11 : 1; /*!< [11..11] Pmn Event Input Data                                             */
                    __IM uint16_t EIDR12 : 1; /*!< [12..12] Pmn Event Input Data                                             */
                    __IM uint16_t EIDR13 : 1; /*!< [13..13] Pmn Event Input Data                                             */
                    __IM uint16_t EIDR14 : 1; /*!< [14..14] Pmn Event Input Data                                             */
                    __IM uint16_t EIDR15 : 1; /*!< [15..15] Pmn Event Input Data                                             */
                } EIDR_b;
            };

            union
            {
                __IM uint16_t PIDR;           /*!< (@ 0x00000006) Input data register                                        */

                struct
                {
                    __IM uint16_t PIDR0  : 1; /*!< [0..0] Pmn Input Data                                                     */
                    __IM uint16_t PIDR1  : 1; /*!< [1..1] Pmn Input Data                                                     */
                    __IM uint16_t PIDR2  : 1; /*!< [2..2] Pmn Input Data                                                     */
                    __IM uint16_t PIDR3  : 1; /*!< [3..3] Pmn Input Data                                                     */
                    __IM uint16_t PIDR4  : 1; /*!< [4..4] Pmn Input Data                                                     */
                    __IM uint16_t PIDR5  : 1; /*!< [5..5] Pmn Input Data                                                     */
                    __IM uint16_t PIDR6  : 1; /*!< [6..6] Pmn Input Data                                                     */
                    __IM uint16_t PIDR7  : 1; /*!< [7..7] Pmn Input Data                                                     */
                    __IM uint16_t PIDR8  : 1; /*!< [8..8] Pmn Input Data                                                     */
                    __IM uint16_t PIDR9  : 1; /*!< [9..9] Pmn Input Data                                                     */
                    __IM uint16_t PIDR10 : 1; /*!< [10..10] Pmn Input Data                                                   */
                    __IM uint16_t PIDR11 : 1; /*!< [11..11] Pmn Input Data                                                   */
                    __IM uint16_t PIDR12 : 1; /*!< [12..12] Pmn Input Data                                                   */
                    __IM uint16_t PIDR13 : 1; /*!< [13..13] Pmn Input Data                                                   */
                    __IM uint16_t PIDR14 : 1; /*!< [14..14] Pmn Input Data                                                   */
                    __IM uint16_t PIDR15 : 1; /*!< [15..15] Pmn Input Data                                                   */
                } PIDR_b;
            };
        };
    };

    union
    {
        union
        {
            __OM uint32_t PCNTR3;        /*!< (@ 0x00000008) Port Control Register 3                                    */

            struct
            {
                __OM uint32_t POSR : 16; /*!< [15..0] Pmn Output Set                                                    */
                __OM uint32_t PORR : 16; /*!< [31..16] Pmn Output Reset                                                 */
            } PCNTR3_b;
        };

        struct
        {
            union
            {
                __OM uint16_t PORR;           /*!< (@ 0x00000008) Output set register                                        */

                struct
                {
                    __OM uint16_t PORR0  : 1; /*!< [0..0] Pmn Output Reset                                                   */
                    __OM uint16_t PORR1  : 1; /*!< [1..1] Pmn Output Reset                                                   */
                    __OM uint16_t PORR2  : 1; /*!< [2..2] Pmn Output Reset                                                   */
                    __OM uint16_t PORR3  : 1; /*!< [3..3] Pmn Output Reset                                                   */
                    __OM uint16_t PORR4  : 1; /*!< [4..4] Pmn Output Reset                                                   */
                    __OM uint16_t PORR5  : 1; /*!< [5..5] Pmn Output Reset                                                   */
                    __OM uint16_t PORR6  : 1; /*!< [6..6] Pmn Output Reset                                                   */
                    __OM uint16_t PORR7  : 1; /*!< [7..7] Pmn Output Reset                                                   */
                    __OM uint16_t PORR8  : 1; /*!< [8..8] Pmn Output Reset                                                   */
                    __OM uint16_t PORR9  : 1; /*!< [9..9] Pmn Output Reset                                                   */
                    __OM uint16_t PORR10 : 1; /*!< [10..10] Pmn Output Reset                                                 */
                    __OM uint16_t PORR11 : 1; /*!< [11..11] Pmn Output Reset                                                 */
                    __OM uint16_t PORR12 : 1; /*!< [12..12] Pmn Output Reset                                                 */
                    __OM uint16_t PORR13 : 1; /*!< [13..13] Pmn Output Reset                                                 */
                    __OM uint16_t PORR14 : 1; /*!< [14..14] Pmn Output Reset                                                 */
                    __OM uint16_t PORR15 : 1; /*!< [15..15] Pmn Output Reset                                                 */
                } PORR_b;
            };

            union
            {
                __OM uint16_t POSR;           /*!< (@ 0x0000000A) Output reset register                                      */

                struct
                {
                    __OM uint16_t POSR0  : 1; /*!< [0..0] Pmn Output Set                                                     */
                    __OM uint16_t POSR1  : 1; /*!< [1..1] Pmn Output Set                                                     */
                    __OM uint16_t POSR2  : 1; /*!< [2..2] Pmn Output Set                                                     */
                    __OM uint16_t POSR3  : 1; /*!< [3..3] Pmn Output Set                                                     */
                    __OM uint16_t POSR4  : 1; /*!< [4..4] Pmn Output Set                                                     */
                    __OM uint16_t POSR5  : 1; /*!< [5..5] Pmn Output Set                                                     */
                    __OM uint16_t POSR6  : 1; /*!< [6..6] Pmn Output Set                                                     */
                    __OM uint16_t POSR7  : 1; /*!< [7..7] Pmn Output Set                                                     */
                    __OM uint16_t POSR8  : 1; /*!< [8..8] Pmn Output Set                                                     */
                    __OM uint16_t POSR9  : 1; /*!< [9..9] Pmn Output Set                                                     */
                    __OM uint16_t POSR10 : 1; /*!< [10..10] Pmn Output Set                                                   */
                    __OM uint16_t POSR11 : 1; /*!< [11..11] Pmn Output Set                                                   */
                    __OM uint16_t POSR12 : 1; /*!< [12..12] Pmn Output Set                                                   */
                    __OM uint16_t POSR13 : 1; /*!< [13..13] Pmn Output Set                                                   */
                    __OM uint16_t POSR14 : 1; /*!< [14..14] Pmn Output Set                                                   */
                    __OM uint16_t POSR15 : 1; /*!< [15..15] Pmn Output Set                                                   */
                } POSR_b;
            };
        };
    };

    union
    {
        union
        {
            __IOM uint32_t PCNTR4;        /*!< (@ 0x0000000C) Port Control Register 4                                    */

            struct
            {
                __IOM uint32_t EOSR : 16; /*!< [15..0] Pmn Event Output Set                                              */
                __IOM uint32_t EORR : 16; /*!< [31..16] Pmn Event Output Reset                                           */
            } PCNTR4_b;
        };

        struct
        {
            union
            {
                __IOM uint16_t EORR;           /*!< (@ 0x0000000C) Event output set register                                  */

                struct
                {
                    __IOM uint16_t EORR0  : 1; /*!< [0..0] Pmn Event Output Reset                                             */
                    __IOM uint16_t EORR1  : 1; /*!< [1..1] Pmn Event Output Reset                                             */
                    __IOM uint16_t EORR2  : 1; /*!< [2..2] Pmn Event Output Reset                                             */
                    __IOM uint16_t EORR3  : 1; /*!< [3..3] Pmn Event Output Reset                                             */
                    __IOM uint16_t EORR4  : 1; /*!< [4..4] Pmn Event Output Reset                                             */
                    __IOM uint16_t EORR5  : 1; /*!< [5..5] Pmn Event Output Reset                                             */
                    __IOM uint16_t EORR6  : 1; /*!< [6..6] Pmn Event Output Reset                                             */
                    __IOM uint16_t EORR7  : 1; /*!< [7..7] Pmn Event Output Reset                                             */
                    __IOM uint16_t EORR8  : 1; /*!< [8..8] Pmn Event Output Reset                                             */
                    __IOM uint16_t EORR9  : 1; /*!< [9..9] Pmn Event Output Reset                                             */
                    __IOM uint16_t EORR10 : 1; /*!< [10..10] Pmn Event Output Reset                                           */
                    __IOM uint16_t EORR11 : 1; /*!< [11..11] Pmn Event Output Reset                                           */
                    __IOM uint16_t EORR12 : 1; /*!< [12..12] Pmn Event Output Reset                                           */
                    __IOM uint16_t EORR13 : 1; /*!< [13..13] Pmn Event Output Reset                                           */
                    __IOM uint16_t EORR14 : 1; /*!< [14..14] Pmn Event Output Reset                                           */
                    __IOM uint16_t EORR15 : 1; /*!< [15..15] Pmn Event Output Reset                                           */
                } EORR_b;
            };

            union
            {
                __IOM uint16_t EOSR;           /*!< (@ 0x0000000E) Event output reset register                                */

                struct
                {
                    __IOM uint16_t EOSR0  : 1; /*!< [0..0] Pmn Event Output Set                                               */
                    __IOM uint16_t EOSR1  : 1; /*!< [1..1] Pmn Event Output Set                                               */
                    __IOM uint16_t EOSR2  : 1; /*!< [2..2] Pmn Event Output Set                                               */
                    __IOM uint16_t EOSR3  : 1; /*!< [3..3] Pmn Event Output Set                                               */
                    __IOM uint16_t EOSR4  : 1; /*!< [4..4] Pmn Event Output Set                                               */
                    __IOM uint16_t EOSR5  : 1; /*!< [5..5] Pmn Event Output Set                                               */
                    __IOM uint16_t EOSR6  : 1; /*!< [6..6] Pmn Event Output Set                                               */
                    __IOM uint16_t EOSR7  : 1; /*!< [7..7] Pmn Event Output Set                                               */
                    __IOM uint16_t EOSR8  : 1; /*!< [8..8] Pmn Event Output Set                                               */
                    __IOM uint16_t EOSR9  : 1; /*!< [9..9] Pmn Event Output Set                                               */
                    __IOM uint16_t EOSR10 : 1; /*!< [10..10] Pmn Event Output Set                                             */
                    __IOM uint16_t EOSR11 : 1; /*!< [11..11] Pmn Event Output Set                                             */
                    __IOM uint16_t EOSR12 : 1; /*!< [12..12] Pmn Event Output Set                                             */
                    __IOM uint16_t EOSR13 : 1; /*!< [13..13] Pmn Event Output Set                                             */
                    __IOM uint16_t EOSR14 : 1; /*!< [14..14] Pmn Event Output Set                                             */
                    __IOM uint16_t EOSR15 : 1; /*!< [15..15] Pmn Event Output Set                                             */
                } EOSR_b;
            };
        };
    };
} R_PORT0_Type;                        /*!< Size = 16 (0x10)                                                          */

#endif  /* _RA6M4_ */

/* =========================================================================================================================== */
/* ================                                          R_PORT_Type                                      ================ */
/* =========================================================================================================================== */

typedef struct
{
	struct
	{
		union
		{
			union
			{
		        __IOM uint64_t QWORD; /*!< (@ 0x51031010) IOLH Register */

		        struct
		        {
		            __IOM uint64_t IOLH0 : 2;   /*!< [ 0.. 1] Drive ability control of pin00   */
		            uint64_t             : 6;
		            __IOM uint64_t IOLH1 : 2;   /*!< [ 8.. 9] Drive ability control of pin01   */
		            uint64_t             : 6;
		            __IOM uint64_t IOLH2 : 2;   /*!< [16..17] Drive ability control of pin02   */
		            uint64_t             : 6;
		            __IOM uint64_t IOLH3 : 2;   /*!< [24..25] Drive ability control of pin03   */
		            uint64_t             : 6;
		            __IOM uint64_t IOLH4 : 2;   /*!< [32..33] Drive ability control of pin04   */
		            uint64_t             : 6;
		            __IOM uint64_t IOLH5 : 2;   /*!< [40..41] Drive ability control of pin05   */
		            uint64_t             : 6;
		            __IOM uint64_t IOLH6 : 2;   /*!< [48..49] Drive ability control of pin06   */
		            uint64_t             : 6;
		            __IOM uint64_t IOLH7 : 2;   /*!< [56..57] Drive ability control of pin07   */
		            uint64_t             : 6;
		        } IOLH_b;
			};

			struct
			{
				__IOM uint32_t IOLH_L;
				__IOM uint32_t IOLH_H;
			} DWORD;

			struct
			{
				__IOM uint16_t IOLH_LL;
				__IOM uint16_t IOLH_LH;
				__IOM uint16_t IOLH_HL;
				__IOM uint16_t IOLH_HH;
			} WORD;

			struct
			{
				__IOM uint8_t IOLH_LLL;
				__IOM uint8_t IOLH_LLH;
				__IOM uint8_t IOLH_LHL;
				__IOM uint8_t IOLH_LHH;
				__IOM uint8_t IOLH_HLL;
				__IOM uint8_t IOLH_HLH;
				__IOM uint8_t IOLH_HHL;
				__IOM uint8_t IOLH_HHH;
			} BYTE;
		};
	} IOLH[12];

	__IM uint64_t RESERVED0[114];
	__IM uint64_t RESERVED1[2];

	struct
	{
		union
		{
			union
			{
		        __IOM uint64_t QWORD; /*!< (@ 0x51031410) SR Register */

		        struct
		        {
		            __IOM uint64_t SR0 : 1;   /*!< [ 0.. 0] Slew rate control of pin00   */
		            uint64_t           : 7;
		            __IOM uint64_t SR1 : 1;   /*!< [ 8.. 8] Slew rate control of pin01   */
		            uint64_t           : 7;
		            __IOM uint64_t SR2 : 1;   /*!< [16..16] Slew rate control of pin02   */
		            uint64_t           : 7;
		            __IOM uint64_t SR3 : 1;   /*!< [24..24] Slew rate control of pin03   */
		            uint64_t           : 7;
		            __IOM uint64_t SR4 : 1;   /*!< [32..32] Slew rate control of pin04   */
		            uint64_t           : 7;
		            __IOM uint64_t SR5 : 1;   /*!< [40..40] Slew rate control of pin05   */
		            uint64_t           : 7;
		            __IOM uint64_t SR6 : 1;   /*!< [48..48] Slew rate control of pin06   */
		            uint64_t           : 7;
		            __IOM uint64_t SR7 : 1;   /*!< [56..56] Slew rate control of pin07   */
		            uint64_t           : 7;
		        } SR_b;
			};

			struct
			{
				__IOM uint32_t SR_L;
				__IOM uint32_t SR_H;
			} DWORD;

			struct
			{
				__IOM uint16_t SR_LL;
				__IOM uint16_t SR_LH;
				__IOM uint16_t SR_HL;
				__IOM uint16_t SR_HH;
			} WORD;

			struct
			{
				__IOM uint8_t SR_LLL;
				__IOM uint8_t SR_LLH;
				__IOM uint8_t SR_LHL;
				__IOM uint8_t SR_LHH;
				__IOM uint8_t SR_HLL;
				__IOM uint8_t SR_HLH;
				__IOM uint8_t SR_HHL;
				__IOM uint8_t SR_HHH;
			} BYTE;
		};
	} SR[12];

	__IM uint64_t RESERVED2[114];
	__IM uint64_t RESERVED3[2];

	struct
	{
		union
		{
			union
			{
				__IOM uint64_t QWORD; /*!< (@ 0x51031810) IEN02 Register */

				struct
				{
		            __IOM uint64_t IEN0 : 1;   /*!< [ 0.. 0] Input enable/disable control of pin00   */
		            uint64_t            : 7;
		            __IOM uint64_t IEN1 : 1;   /*!< [ 8.. 8] Input enable/disable control of pin01   */
		            uint64_t            : 7;
		            __IOM uint64_t IEN2 : 1;   /*!< [16..16] Input enable/disable control of pin02   */
		            uint64_t            : 7;
		            __IOM uint64_t IEN3 : 1;   /*!< [24..24] Input enable/disable control of pin03   */
		            uint64_t            : 7;
		            __IOM uint64_t IEN4 : 1;   /*!< [32..32] Input enable/disable control of pin04   */
		            uint64_t            : 7;
		            __IOM uint64_t IEN5 : 1;   /*!< [40..40] Input enable/disable control of pin05   */
		            uint64_t            : 7;
		            __IOM uint64_t IEN6 : 1;   /*!< [48..48] Input enable/disable control of pin06   */
		            uint64_t            : 7;
		            __IOM uint64_t IEN7 : 1;   /*!< [56..56] Input enable/disable control of pin07   */
		            uint64_t            : 7;
				}IEN_b;
			};

			struct
			{
				__IOM uint32_t IEN_L;
				__IOM uint32_t IEN_H;
			} DWORD;

			struct
			{
				__IOM uint16_t IEN_LL;
				__IOM uint16_t IEN_LH;
				__IOM uint16_t IEN_HL;
				__IOM uint16_t IEN_HH;
			} WORD;

			struct
			{
				__IOM uint8_t IEN_LLL;
				__IOM uint8_t IEN_LLH;
				__IOM uint8_t IEN_LHL;
				__IOM uint8_t IEN_LHH;
				__IOM uint8_t IEN_HLL;
				__IOM uint8_t IEN_HLH;
				__IOM uint8_t IEN_HHL;
				__IOM uint8_t IEN_HHH;
			} BYTE;
		};
	} IEN[13];

	__IM uint64_t RESERVED4[113];
	__IM uint64_t RESERVED5[6];

	struct
	{
		union
		{
			union
			{
		        __IOM uint64_t QWORD; /*!< (@ 0x51031C30) PUPD06 Register */

		        struct
		        {
		            __IOM uint64_t PUPD0 : 2;   /*!< [ 0.. 1] set pull-up and pull-down of pin00   */
		            uint64_t             : 6;
		            __IOM uint64_t PUPD1 : 2;   /*!< [ 8.. 9] set pull-up and pull-down of pin01   */
		            uint64_t             : 6;
		            __IOM uint64_t PUPD2 : 2;   /*!< [16..17] set pull-up and pull-down of pin02   */
		            uint64_t             : 6;
		            __IOM uint64_t PUPD3 : 2;   /*!< [24..25] set pull-up and pull-down of pin03   */
		            uint64_t             : 6;
		            __IOM uint64_t PUPD4 : 2;   /*!< [32..33] set pull-up and pull-down of pin04   */
		            uint64_t             : 6;
		            __IOM uint64_t PUPD5 : 2;   /*!< [40..41] set pull-up and pull-down of pin05   */
		            uint64_t             : 6;
		            __IOM uint64_t PUPD6 : 2;   /*!< [48..49] set pull-up and pull-down of pin06   */
		            uint64_t             : 6;
		            __IOM uint64_t PUPD7 : 2;   /*!< [56..57] set pull-up and pull-down of pin07   */
		            uint64_t             : 6;
		        } PUPD_b;
			};

			struct
			{
				__IOM uint32_t PUPD_L;
				__IOM uint32_t PUPD_H;
			} DWORD;

			struct
			{
				__IOM uint16_t PUPD_LL;
				__IOM uint16_t PUPD_LH;
				__IOM uint16_t PUPD_HL;
				__IOM uint16_t PUPD_HH;
			} WORD;

			struct
			{
				__IOM uint8_t PUPD_LLL;
				__IOM uint8_t PUPD_LLH;
				__IOM uint8_t PUPD_LHL;
				__IOM uint8_t PUPD_LHH;
				__IOM uint8_t PUPD_HLL;
				__IOM uint8_t PUPD_HLH;
				__IOM uint8_t PUPD_HHL;
				__IOM uint8_t PUPD_HHH;
			} BYTE;
		};
	} PUPD[7];

	__IM uint64_t RESERVED6[115];
	__IM uint64_t RESERVED7;

	struct
	{
		union
		{
			union
			{
		        __IOM uint64_t QWORD; /*!< (@ 0x51032008) FILONOFF01 Register */

		        struct
		        {
		            __IOM uint64_t FILONOFF0 : 1;   /*!< [ 0.. 0] Digital noise filter is enabled / disabled of pin00   */
		            uint64_t                 : 7;
		            __IOM uint64_t FILONOFF1 : 1;   /*!< [ 8.. 8] Digital noise filter is enabled / disabled of pin01   */
		            uint64_t                 : 7;
		            __IOM uint64_t FILONOFF2 : 1;   /*!< [16..16] Digital noise filter is enabled / disabled of pin02   */
		            uint64_t                 : 7;
		            __IOM uint64_t FILONOFF3 : 1;   /*!< [24..24] Digital noise filter is enabled / disabled of pin03   */
		            uint64_t                 : 7;
		            __IOM uint64_t FILONOFF4 : 1;   /*!< [32..32] Digital noise filter is enabled / disabled of pin04   */
		            uint64_t                 : 7;
		            __IOM uint64_t FILONOFF5 : 1;   /*!< [40..40] Digital noise filter is enabled / disabled of pin05   */
		            uint64_t                 : 7;
		            __IOM uint64_t FILONOFF6 : 1;   /*!< [48..48] Digital noise filter is enabled / disabled of pin06   */
		            uint64_t                 : 7;
		            __IOM uint64_t FILONOFF7 : 1;   /*!< [56..56] Digital noise filter is enabled / disabled of pin07   */
		            uint64_t                 : 7;
		        } FILONOFF_b;
			};

			struct
			{
				__IOM uint32_t FILONOFF_L;
				__IOM uint32_t FILONOFF_H;
			} DWORD;

			struct
			{
				__IOM uint16_t FILONOFF_LL;
				__IOM uint16_t FILONOFF_LH;
				__IOM uint16_t FILONOFF_HL;
				__IOM uint16_t FILONOFF_HH;
			} WORD;

			struct
			{
				__IOM uint8_t FILONOFF_LLL;
				__IOM uint8_t FILONOFF_LLH;
				__IOM uint8_t FILONOFF_LHL;
				__IOM uint8_t FILONOFF_LHH;
				__IOM uint8_t FILONOFF_HLL;
				__IOM uint8_t FILONOFF_HLH;
				__IOM uint8_t FILONOFF_HHL;
				__IOM uint8_t FILONOFF_HHH;
			} BYTE;
		};
	} FILONOFF[1];

	__IM uint64_t RESERVED8[126];
	__IM uint64_t RESERVED9;

	struct
	{
		union
		{
			union
			{
		        __IOM uint64_t QWORD; /*!< (@ 0x51032408) FILNUM01 Register */

		        struct
		        {
		            __IOM uint64_t FILNUM0 : 2;   /*!< [ 0.. 1] Sets the number of FF stages of digital noise filter of pin00   */
		            uint64_t               : 6;
		            __IOM uint64_t FILNUM1 : 2;   /*!< [ 8.. 9] Sets the number of FF stages of digital noise filter of pin01   */
		            uint64_t               : 6;
		            __IOM uint64_t FILNUM2 : 2;   /*!< [16..17] Sets the number of FF stages of digital noise filter of pin02   */
		            uint64_t               : 6;
		            __IOM uint64_t FILNUM3 : 2;   /*!< [24..25] Sets the number of FF stages of digital noise filter of pin03   */
		            uint64_t               : 6;
		            __IOM uint64_t FILNUM4 : 2;   /*!< [32..33] Sets the number of FF stages of digital noise filter of pin04   */
		            uint64_t               : 6;
		            __IOM uint64_t FILNUM5 : 2;   /*!< [40..41] Sets the number of FF stages of digital noise filter of pin05   */
		            uint64_t               : 6;
		            __IOM uint64_t FILNUM6 : 2;   /*!< [48..49] Sets the number of FF stages of digital noise filter of pin06   */
		            uint64_t               : 6;
		            __IOM uint64_t FILNUM7 : 2;   /*!< [56..57] Sets the number of FF stages of digital noise filter of pin07   */
		            uint64_t               : 6;
		        } FILNUM_b;
			};

			struct
			{
				__IOM uint32_t FILNUM_L;
				__IOM uint32_t FILNUM_H;
			} DWORD;

			struct
			{
				__IOM uint16_t FILNUM_LL;
				__IOM uint16_t FILNUM_LH;
				__IOM uint16_t FILNUM_HL;
				__IOM uint16_t FILNUM_HH;
			} WORD;

			struct
			{
				__IOM uint8_t FILNUM_LLL;
				__IOM uint8_t FILNUM_LLH;
				__IOM uint8_t FILNUM_LHL;
				__IOM uint8_t FILNUM_LHH;
				__IOM uint8_t FILNUM_HLL;
				__IOM uint8_t FILNUM_HLH;
				__IOM uint8_t FILNUM_HHL;
				__IOM uint8_t FILNUM_HHH;
			} BYTE;
		};
	} FILNUM[1];

	__IM uint64_t RESERVED10[126];
	__IM uint64_t RESERVED11;

	struct
	{
		union
		{
			union
			{
		        __IOM uint64_t QWORD; /*!< (@ 0x51032808) FILCLKSEL01 Register */

		        struct
		        {
		            __IOM uint64_t FILCLKSEL0 : 2;   /*!< [ 0.. 1] Selects the divided clock to be input to digital noise filters for pin00   */
		            uint64_t                  : 6;
		            __IOM uint64_t FILCLKSEL1 : 2;   /*!< [ 8.. 9] Selects the divided clock to be input to digital noise filters for pin01   */
		            uint64_t                  : 6;
		            __IOM uint64_t FILCLKSEL2 : 2;   /*!< [16..17] Selects the divided clock to be input to digital noise filters for pin02   */
		            uint64_t                  : 6;
		            __IOM uint64_t FILCLKSEL3 : 2;   /*!< [24..25] Selects the divided clock to be input to digital noise filters for pin03   */
		            uint64_t                  : 6;
		            __IOM uint64_t FILCLKSEL4 : 2;   /*!< [32..33] Selects the divided clock to be input to digital noise filters for pin04   */
		            uint64_t                  : 6;
		            __IOM uint64_t FILCLKSEL5 : 2;   /*!< [40..41] Selects the divided clock to be input to digital noise filters for pin05   */
		            uint64_t                  : 6;
		            __IOM uint64_t FILCLKSEL6 : 2;   /*!< [48..49] Selects the divided clock to be input to digital noise filters for pin06   */
		            uint64_t                  : 6;
		            __IOM uint64_t FILCLKSEL7 : 2;   /*!< [56..57] Selects the divided clock to be input to digital noise filters for pin07   */
		            uint64_t                  : 6;
		        } FILCLKSEL_b;
			};

			struct
			{
				__IOM uint32_t FILCLKSEL_L;
				__IOM uint32_t FILCLKSEL_H;
			} DWORD;

			struct
			{
				__IOM uint16_t FILCLKSEL_LL;
				__IOM uint16_t FILCLKSEL_LH;
				__IOM uint16_t FILCLKSEL_HL;
				__IOM uint16_t FILCLKSEL_HH;
			} WORD;

			struct
			{
				__IOM uint8_t FILCLKSEL_LLL;
				__IOM uint8_t FILCLKSEL_LLH;
				__IOM uint8_t FILCLKSEL_LHL;
				__IOM uint8_t FILCLKSEL_LHH;
				__IOM uint8_t FILCLKSEL_HLL;
				__IOM uint8_t FILCLKSEL_HLH;
				__IOM uint8_t FILCLKSEL_HHL;
				__IOM uint8_t FILCLKSEL_HHH;
			} BYTE;
		};
	} FILCLKSEL[1];

	__IM uint64_t RESERVED12[126];
	__IM uint64_t RESERVED13[128];

	union
	{
		union
		{
	        __IOM uint32_t DWORD; /*!< (@ 0x51033000) SD_ch0 Register */

	        struct
	        {
	            __IOM uint32_t SD0_PVDD : 1;   /*!< [ 0.. 0] define IO Voltage for SD0 */
	            uint32_t                : 31;
	        } SD_ch0_b;
		};

		struct
		{
			__IOM uint16_t SD_ch0_L;
			__IOM uint16_t SD_ch0_H;
		} WORD;

		struct
		{
			__IOM uint8_t SD_ch0_LL;
			__IOM uint8_t SD_ch0_LH;
			__IOM uint8_t SD_ch0_HL;
			__IOM uint8_t SD_ch0_HH;
		} BYTE;
	} SD_ch0;

	union
	{
		union
		{
	        __IOM uint32_t DWORD; /*!< (@ 0x51033004) SD_ch1 Register */

	        struct
	        {
	            __IOM uint32_t SD1_PVDD : 1;   /*!< [ 0.. 0] define IO Voltage for SD1 */
	            uint32_t                : 31;
	        }SD_ch1_b;
		};

		struct
		{
			__IOM uint16_t SD_ch1_L;
			__IOM uint16_t SD_ch1_H;
		} WORD;

		struct
		{
			__IOM uint8_t SD_ch1_LL;
			__IOM uint8_t SD_ch1_LH;
			__IOM uint8_t SD_ch1_HL;
			__IOM uint8_t SD_ch1_HH;
		} BYTE;
	} SD_ch1;

	union
	{
		union
		{
	        __IOM uint32_t DWORD; /*!< (@ 0x51033008) QSPI Register */

	        struct
	        {
	            __IOM uint32_t QSPI_PVDD : 1;   /*!< [ 0.. 0] define IO Voltage for QSPI */
	            uint32_t                 : 31;
	        } QSPI_b;
		};

		struct
		{
			__IOM uint16_t QSPI_L;
			__IOM uint16_t QSPI_H;
		} WORD;

		struct
		{
			__IOM uint8_t QSPI_LL;
			__IOM uint8_t QSPI_LH;
			__IOM uint8_t QSPI_HL;
			__IOM uint8_t QSPI_HH;
		} BYTE;
	} QSPI;

	union
	{
		union
		{
	        __IOM uint32_t DWORD; /*!< (@ 0x5103300C) ETH_ch0 Register */

	        struct
	        {
	            __IOM uint32_t ETH0_18V_PVDD : 1;   /*!< [ 0.. 0] define IO Voltage for ETH_ch0 */
	            __IOM uint32_t ETH0_25V_PVDD : 1;   /*!< [ 1.. 1] define IO Voltage for ETH_ch0 */
	            uint32_t                     : 30;
	        } ETH_ch0_b;
		};

		struct
		{
			__IOM uint16_t ETH_ch0_L;
			__IOM uint16_t ETH_ch0_H;
		} WORD;

		struct
		{
			__IOM uint8_t ETH_ch0_LL;
			__IOM uint8_t ETH_ch0_LH;
			__IOM uint8_t ETH_ch0_HL;
			__IOM uint8_t ETH_ch0_HH;
		} BYTE;
	} ETH_ch0;

	union
	{
		union
		{
	        __IOM uint32_t DWORD; /*!< (@ 0x51033010) ETH_ch1 Register */

	        struct
	        {
	            __IOM uint32_t ETH1_18V_PVDD : 1;   /*!< [ 0.. 0] define IO Voltage for ETH_ch1 */
	            __IOM uint32_t ETH1_25V_PVDD : 1;   /*!< [ 1.. 1] define IO Voltage for ETH_ch1 */
	            uint32_t                     : 30;
	        } ETH_ch1_b;
		};

		struct
		{
			__IOM uint16_t ETH_ch1_L;
			__IOM uint16_t ETH_ch1_H;
		} WORD;

		struct
		{
			__IOM uint8_t ETH_ch1_LL;
			__IOM uint8_t ETH_ch1_LH;
			__IOM uint8_t ETH_ch1_HL;
			__IOM uint8_t ETH_ch1_HH;
		} BYTE;
	} ETH_ch1;

	union
	{
	    union
	    {
	        __IOM uint32_t DWORD; /*!< (@ 0x51033014) PWPR Register */

	        struct
	        {
	            uint32_t             : 6;
	            __IOM uint32_t PFCWE : 1;   /*!< [ 6.. 6] Write enable/disable of PFC Register   */
	            __IOM uint32_t B0WI  : 1;   /*!< [ 7.. 7] Write enable/disable of PFCWE bit   */
	            uint32_t             : 24;
	        } PWPR_b;
	    };

		struct
		{
			__IOM uint16_t PWPR_L;
			__IOM uint16_t PWPR_H;
		} WORD;

		struct
		{
			__IOM uint8_t PWPR_LL;
			__IOM uint8_t PWPR_LH;
			__IOM uint8_t PWPR_HL;
			__IOM uint8_t PWPR_HH;
		} BYTE;
	} PWPR;

	union
	{
	    union
	    {
	        __IOM uint32_t DWORD; /*!< (@ 0x51033018) ETH_MII_RGMII Register */

	        struct
	        {
	            __IOM uint32_t P20_0 : 1;   /*!< [ 0.. 0] Select ETH_MII_RGMII   */
	            __IOM uint32_t P29_0 : 1;   /*!< [ 1.. 1] Select ETH_MII_RGMII   */
	            uint32_t             : 30;
	        } ETH_MII_RGMII_b;
	    };

		struct
		{
			__IOM uint16_t ETH_MII_RGMII_L;
			__IOM uint16_t ETH_MII_RGMII_H;
		} WORD;

		struct
		{
			__IOM uint8_t ETH_MII_RGMII_LL;
			__IOM uint8_t ETH_MII_RGMII_LH;
			__IOM uint8_t ETH_MII_RGMII_HL;
			__IOM uint8_t ETH_MII_RGMII_HH;
		} BYTE;
	} ETH_MII_RGMII;
} R_GPIO_Type;

typedef struct
{
	struct
	{
		union
		{
		    __IOM uint8_t BYTE; /*!< (@ 0x51030000) P Register */

		    struct
		    {
		        __IOM uint8_t P0 : 1;   /*!< [ 0.. 0] Output level setting of pin00   */
		        __IOM uint8_t P1 : 1;   /*!< [ 1.. 1] Output level setting of pin01   */
		        __IOM uint8_t P2 : 1;   /*!< [ 2.. 2] Output level setting of pin02   */
		        __IOM uint8_t P3 : 1;   /*!< [ 3.. 3] Output level setting of pin03   */
		        __IOM uint8_t P4 : 1;   /*!< [ 4.. 4] Output level setting of pin04   */
		        __IOM uint8_t P5 : 1;   /*!< [ 5.. 5] Output level setting of pin05   */
		        __IOM uint8_t P6 : 1;   /*!< [ 6.. 6] Output level setting of pin06   */
		        __IOM uint8_t P7 : 1;   /*!< [ 7.. 7] Output level setting of pin07   */
		    } P_b;
	    };
	} P[49];

	__IM uint8_t  RESERVED1[191];
	__IM uint16_t RESERVED2[16];

	struct
	{
		union
		{
			union
			{
				__IOM uint16_t WORD; /*!< (@ 0x51030100) PM Register */

				struct {
					__IOM uint16_t PM0 :2; /*!< [ 0.. 1] Port direction setting of pin00   */
					__IOM uint16_t PM1 :2; /*!< [ 2.. 3] Port direction setting of pin01   */
					__IOM uint16_t PM2 :2; /*!< [ 4.. 5] Port direction setting of pin02   */
					__IOM uint16_t PM3 :2; /*!< [ 6.. 7] Port direction setting of pin03   */
					uint16_t :8;
				} PM_b;
			};

			struct
			{
				__IOM uint8_t PM_L;
				__IOM uint8_t PM_H;
			} BYTE;
		};
	} PM[49];

	__IM uint16_t RESERVED3[63];
	__IM uint8_t  RESERVED4[16];

	struct
	{
		union
		{
	        __IOM uint8_t BYTE; /*!< (@ 0x51030200) PMC Register */

	        struct
	        {
	            __IOM uint8_t PMC0 : 1;   /*!< [ 0.. 0] Port mode control setting of pin00   */
	            __IOM uint8_t PMC1 : 1;   /*!< [ 1.. 1] Port mode control setting of pin01   */
	            __IOM uint8_t PMC2 : 1;   /*!< [ 2.. 2] Port mode control setting of pin02   */
	            __IOM uint8_t PMC3 : 1;   /*!< [ 3.. 3] Port mode control setting of pin03   */
	            __IOM uint8_t PMC4 : 1;   /*!< [ 4.. 4] Port mode control setting of pin04   */
	            __IOM uint8_t PMC5 : 1;   /*!< [ 5.. 5] Port mode control setting of pin05   */
	            __IOM uint8_t PMC6 : 1;   /*!< [ 6.. 6] Port mode control setting of pin06   */
	            __IOM uint8_t PMC7 : 1;   /*!< [ 7.. 7] Port mode control setting of pin07   */
	        } PMC_b;
		};
	} PMC[49];

	__IM uint8_t  RESERVED5[447];
	__IM uint32_t RESERVED6[16];

	struct
	{
		union
		{
			union
			{
		        __IOM uint32_t DWORD; /*!< (@ 0x51030400) PFC Register */

			    struct
		        {
		            __IOM uint32_t PFC0 : 3;   /*!< [ 0.. 2] Pin function select of pin00   */
		            uint32_t            : 1;
		            __IOM uint32_t PFC1 : 3;   /*!< [ 4.. 6] Pin function select of pin01   */
		            uint32_t            : 1;
		            __IOM uint32_t PFC2 : 3;   /*!< [ 8..10] Pin function select of pin02   */
		            uint32_t            : 1;
		            __IOM uint32_t PFC3 : 3;   /*!< [12..14] Pin function select of pin03   */
		            uint32_t            : 1;
		            __IOM uint32_t PFC4 : 3;   /*!< [16..18] Pin function select of pin04   */
		            uint32_t            : 13;
		        } PFC_b;
			};

			struct
			{
		        __IOM uint16_t PFC_L;
		        __IOM uint16_t PFC_H;
			} WORD;

			struct
			{
		        __IOM uint8_t PFC_LL;
		        __IOM uint8_t PFC_LH;
		        __IOM uint8_t PFC_HL;
		        __IOM uint8_t PFC_HH;
			} BYTE;
		};
	} PFC[49];

	__IM uint32_t RESERVED7[191];
	__IM uint8_t  RESERVED8[16];

	struct
	{
		union
		{
	        __IM uint8_t BYTE; /*!< (@ 0x51030800) PIN Register */

	        struct
	        {
	            __IM uint8_t PIN0 : 1;   /*!< [ 0.. 0] Port level of pin00   */
	            __IM uint8_t PIN1 : 1;   /*!< [ 1.. 1] Port level of pin01   */
	            __IM uint8_t PIN2 : 1;   /*!< [ 2.. 2] Port level of pin02   */
	            __IM uint8_t PIN3 : 1;   /*!< [ 3.. 3] Port level of pin03   */
	            __IM uint8_t PIN4 : 1;   /*!< [ 4.. 4] Port level of pin04   */
	            __IM uint8_t PIN5 : 1;   /*!< [ 5.. 5] Port level of pin05   */
	            __IM uint8_t PIN6 : 1;   /*!< [ 6.. 6] Port level of pin06   */
	            __IM uint8_t PIN7 : 1;   /*!< [ 7.. 7] Port level of pin07   */
	        } PIN_b;
		};
	} PIN[49];

	__IM uint8_t  RESERVED9[447];
	__IM uint8_t  RESERVED99[1536];
	__IM uint64_t RESERVED10[16];

	struct
	{
		union
		{
			union
			{
		        __IOM uint64_t QWORD; /*!< (@ 0x51031000) IOLH Register */

		        struct
		        {
		            __IOM uint64_t IOLH0 : 2;   /*!< [ 0.. 1] Drive ability control of pin00   */
		            uint64_t             : 6;
		            __IOM uint64_t IOLH1 : 2;   /*!< [ 8.. 9] Drive ability control of pin01   */
		            uint64_t             : 6;
		            __IOM uint64_t IOLH2 : 2;   /*!< [16..17] Drive ability control of pin02   */
		            uint64_t             : 6;
		            __IOM uint64_t IOLH3 : 2;   /*!< [24..25] Drive ability control of pin03   */
		            uint64_t             : 6;
		            __IOM uint64_t IOLH4 : 2;   /*!< [32..33] Drive ability control of pin04   */
		            uint64_t             : 6;
		            __IOM uint64_t IOLH5 : 2;   /*!< [40..41] Drive ability control of pin05   */
		            uint64_t             : 6;
		            __IOM uint64_t IOLH6 : 2;   /*!< [48..49] Drive ability control of pin06   */
		            uint64_t             : 6;
		            __IOM uint64_t IOLH7 : 2;   /*!< [56..57] Drive ability control of pin07   */
		            uint64_t             : 6;
		        } IOLH_b;
			};

			struct
			{
				__IOM uint32_t IOLH_L;
				__IOM uint32_t IOLH_H;
			} DWORD;

			struct
			{
				__IOM uint16_t IOLH_LL;
				__IOM uint16_t IOLH_LH;
				__IOM uint16_t IOLH_HL;
				__IOM uint16_t IOLH_HH;
			} WORD;

			struct
			{
				__IOM uint8_t IOLH_LLL;
				__IOM uint8_t IOLH_LLH;
				__IOM uint8_t IOLH_LHL;
				__IOM uint8_t IOLH_LHH;
				__IOM uint8_t IOLH_HLL;
				__IOM uint8_t IOLH_HLH;
				__IOM uint8_t IOLH_HHL;
				__IOM uint8_t IOLH_HHH;
			} BYTE;
		};

	} IOLH[49];

	__IM uint64_t RESERVED11[63];
	__IM uint64_t RESERVED12[16];

	struct
	{
		union
		{
			union
			{
		        __IOM uint64_t QWORD; /*!< (@ 0x51031400) SR Register */

		        struct
		        {
		            __IOM uint64_t SR0 : 1;   /*!< [ 0.. 0] Slew rate control of pin00   */
		            uint64_t           : 7;
		            __IOM uint64_t SR1 : 1;   /*!< [ 8.. 8] Slew rate control of pin01   */
		            uint64_t           : 7;
		            __IOM uint64_t SR2 : 1;   /*!< [16..16] Slew rate control of pin02   */
		            uint64_t           : 7;
		            __IOM uint64_t SR3 : 1;   /*!< [24..24] Slew rate control of pin03   */
		            uint64_t           : 7;
		            __IOM uint64_t SR4 : 1;   /*!< [32..32] Slew rate control of pin04   */
		            uint64_t           : 7;
		            __IOM uint64_t SR5 : 1;   /*!< [40..40] Slew rate control of pin05   */
		            uint64_t           : 7;
		            __IOM uint64_t SR6 : 1;   /*!< [48..48] Slew rate control of pin06   */
		            uint64_t           : 7;
		            __IOM uint64_t SR7 : 1;   /*!< [56..56] Slew rate control of pin07   */
		            uint64_t           : 7;
		        } SR_b;
			};

			struct
			{
				__IOM uint32_t SR_L;
				__IOM uint32_t SR_H;
			} DWORD;

			struct
			{
				__IOM uint16_t SR_LL;
				__IOM uint16_t SR_LH;
				__IOM uint16_t SR_HL;
				__IOM uint16_t SR_HH;
			} WORD;

			struct
			{
				__IOM uint8_t SR_LLL;
				__IOM uint8_t SR_LLH;
				__IOM uint8_t SR_LHL;
				__IOM uint8_t SR_LHH;
				__IOM uint8_t SR_HLL;
				__IOM uint8_t SR_HLH;
				__IOM uint8_t SR_HHL;
				__IOM uint8_t SR_HHH;
			} BYTE;
		};
	} SR[49];

	__IM uint64_t RESERVED13[63];
	__IM uint64_t RESERVED14[128];
	__IM uint64_t RESERVED15[16];

	struct
	{
		union
		{
			union
			{
		        __IOM uint64_t QWORD; /*!< (@ 0x51031C00) PUPD Register */

		        struct
		        {
		            __IOM uint64_t PUPD0 : 2;   /*!< [ 0.. 1] set pull-up and pull-down of pin00   */
		            uint64_t             : 6;
		            __IOM uint64_t PUPD1 : 2;   /*!< [ 8.. 9] set pull-up and pull-down of pin01   */
		            uint64_t             : 6;
		            __IOM uint64_t PUPD2 : 2;   /*!< [16..17] set pull-up and pull-down of pin02   */
		            uint64_t             : 6;
		            __IOM uint64_t PUPD3 : 2;   /*!< [24..25] set pull-up and pull-down of pin03   */
		            uint64_t             : 6;
		            __IOM uint64_t PUPD4 : 2;   /*!< [32..33] set pull-up and pull-down of pin04   */
		            uint64_t             : 6;
		            __IOM uint64_t PUPD5 : 2;   /*!< [40..41] set pull-up and pull-down of pin05   */
		            uint64_t             : 6;
		            __IOM uint64_t PUPD6 : 2;   /*!< [48..49] set pull-up and pull-down of pin06   */
		            uint64_t             : 6;
		            __IOM uint64_t PUPD7 : 2;   /*!< [56..57] set pull-up and pull-down of pin07   */
		            uint64_t             : 6;
		        } PUPD_b;
			};

			struct
			{
				__IOM uint32_t PUPD_L;
				__IOM uint32_t PUPD_H;
			} DWORD;

			struct
			{
				__IOM uint16_t PUPD_LL;
				__IOM uint16_t PUPD_LH;
				__IOM uint16_t PUPD_HL;
				__IOM uint16_t PUPD_HH;
			} WORD;

			struct
			{
				__IOM uint8_t PUPD_LLL;
				__IOM uint8_t PUPD_LLH;
				__IOM uint8_t PUPD_LHL;
				__IOM uint8_t PUPD_LHH;
				__IOM uint8_t PUPD_HLL;
				__IOM uint8_t PUPD_HLH;
				__IOM uint8_t PUPD_HHL;
				__IOM uint8_t PUPD_HHH;
			} BYTE;
		};
	} PUPD[49];

	__IM uint64_t RESERVED17[63];
	__IM uint64_t RESERVED18[16];

	struct
	{
		union
		{
			union
			{
		        __IOM uint64_t QWORD; /*!< (@ 0x51032000) FILONOFF Register */

		        struct
		        {
		            __IOM uint64_t FILONOFF0 : 1;   /*!< [ 0.. 0] Digital noise filter is enabled / disabled of pin00   */
		            uint64_t                 : 7;
		            __IOM uint64_t FILONOFF1 : 1;   /*!< [ 8.. 8] Digital noise filter is enabled / disabled of pin01   */
		            uint64_t                 : 7;
		            __IOM uint64_t FILONOFF2 : 1;   /*!< [16..16] Digital noise filter is enabled / disabled of pin02   */
		            uint64_t                 : 7;
		            __IOM uint64_t FILONOFF3 : 1;   /*!< [24..24] Digital noise filter is enabled / disabled of pin03   */
		            uint64_t                 : 7;
		            __IOM uint64_t FILONOFF4 : 1;   /*!< [32..32] Digital noise filter is enabled / disabled of pin04   */
		            uint64_t                 : 7;
		            __IOM uint64_t FILONOFF5 : 1;   /*!< [40..40] Digital noise filter is enabled / disabled of pin05   */
		            uint64_t                 : 7;
		            __IOM uint64_t FILONOFF6 : 1;   /*!< [48..48] Digital noise filter is enabled / disabled of pin06   */
		            uint64_t                 : 7;
		            __IOM uint64_t FILONOFF7 : 1;   /*!< [56..56] Digital noise filter is enabled / disabled of pin07   */
		            uint64_t                 : 7;
		        } FILONOFF_b;
			};

			struct
			{
				__IOM uint32_t FILONOFF_L;
				__IOM uint32_t FILONOFF_H;
			} DWORD;

			struct
			{
				__IOM uint16_t FILONOFF_LL;
				__IOM uint16_t FILONOFF_LH;
				__IOM uint16_t FILONOFF_HL;
				__IOM uint16_t FILONOFF_HH;
			} WORD;

			struct
			{
				__IOM uint8_t FILONOFF_LLL;
				__IOM uint8_t FILONOFF_LLH;
				__IOM uint8_t FILONOFF_LHL;
				__IOM uint8_t FILONOFF_LHH;
				__IOM uint8_t FILONOFF_HLL;
				__IOM uint8_t FILONOFF_HLH;
				__IOM uint8_t FILONOFF_HHL;
				__IOM uint8_t FILONOFF_HHH;
			} BYTE;
		};
	} FILONOFF[49];

	__IM uint64_t RESERVED19[63];
	__IM uint64_t RESERVED20[16];

	struct
	{
		union
		{
			union
			{
		        __IOM uint64_t QWORD; /*!< (@ 0x51032400) FILNUM Register */

		        struct
		        {
		            __IOM uint64_t FILNUM0 : 2;   /*!< [ 0.. 1] Sets the number of FF stages of digital noise filter of pin00   */
		            uint64_t               : 6;
		            __IOM uint64_t FILNUM1 : 2;   /*!< [ 8.. 9] Sets the number of FF stages of digital noise filter of pin01   */
		            uint64_t               : 6;
		            __IOM uint64_t FILNUM2 : 2;   /*!< [16..17] Sets the number of FF stages of digital noise filter of pin02   */
		            uint64_t               : 6;
		            __IOM uint64_t FILNUM3 : 2;   /*!< [24..25] Sets the number of FF stages of digital noise filter of pin03   */
		            uint64_t               : 6;
		            __IOM uint64_t FILNUM4 : 2;   /*!< [32..33] Sets the number of FF stages of digital noise filter of pin04   */
		            uint64_t               : 6;
		            __IOM uint64_t FILNUM5 : 2;   /*!< [40..41] Sets the number of FF stages of digital noise filter of pin05   */
		            uint64_t               : 6;
		            __IOM uint64_t FILNUM6 : 2;   /*!< [48..49] Sets the number of FF stages of digital noise filter of pin06   */
		            uint64_t               : 6;
		            __IOM uint64_t FILNUM7 : 2;   /*!< [56..57] Sets the number of FF stages of digital noise filter of pin07   */
		            uint64_t               : 6;
		        } FILNUM_b;
			};

			struct
			{
				__IOM uint32_t FILNUM_L;
				__IOM uint32_t FILNUM_H;
			} DWORD;

			struct
			{
				__IOM uint16_t FILNUM_LL;
				__IOM uint16_t FILNUM_LH;
				__IOM uint16_t FILNUM_HL;
				__IOM uint16_t FILNUM_HH;
			} WORD;

			struct
			{
				__IOM uint8_t FILNUM_LLL;
				__IOM uint8_t FILNUM_LLH;
				__IOM uint8_t FILNUM_LHL;
				__IOM uint8_t FILNUM_LHH;
				__IOM uint8_t FILNUM_HLL;
				__IOM uint8_t FILNUM_HLH;
				__IOM uint8_t FILNUM_HHL;
				__IOM uint8_t FILNUM_HHH;
			} BYTE;
		};
	} FILNUM[49];

	__IM uint64_t RESERVED21[63];
	__IM uint64_t RESERVED22[16];

	struct
	{
		union
		{
			union
			{
		        __IOM uint64_t QWORD; /*!< (@ 0x51032800) FILCLKSEL Register */

		        struct
		        {
		            __IOM uint64_t FILCLKSEL0 : 2;   /*!< [ 0.. 1] Selects the divided clock to be input to digital noise filters for pin00   */
		            uint64_t                  : 6;
		            __IOM uint64_t FILCLKSEL1 : 2;   /*!< [ 8.. 9] Selects the divided clock to be input to digital noise filters for pin01   */
		            uint64_t                  : 6;
		            __IOM uint64_t FILCLKSEL2 : 2;   /*!< [16..17] Selects the divided clock to be input to digital noise filters for pin02   */
		            uint64_t                  : 6;
		            __IOM uint64_t FILCLKSEL3 : 2;   /*!< [24..25] Selects the divided clock to be input to digital noise filters for pin03   */
		            uint64_t                  : 6;
		            __IOM uint64_t FILCLKSEL4 : 2;   /*!< [32..33] Selects the divided clock to be input to digital noise filters for pin04   */
		            uint64_t                  : 6;
		            __IOM uint64_t FILCLKSEL5 : 2;   /*!< [40..41] Selects the divided clock to be input to digital noise filters for pin05   */
		            uint64_t                  : 6;
		            __IOM uint64_t FILCLKSEL6 : 2;   /*!< [48..49] Selects the divided clock to be input to digital noise filters for pin06   */
		            uint64_t                  : 6;
		            __IOM uint64_t FILCLKSEL7 : 2;   /*!< [56..57] Selects the divided clock to be input to digital noise filters for pin07   */
		            uint64_t                  : 6;
		        } FILCLKSEL_b;
			};

			struct
			{
				__IOM uint32_t FILCLKSEL_L;
				__IOM uint32_t FILCLKSEL_H;
			} DWORD;

			struct
			{
				__IOM uint16_t FILCLKSEL_LL;
				__IOM uint16_t FILCLKSEL_LH;
				__IOM uint16_t FILCLKSEL_HL;
				__IOM uint16_t FILCLKSEL_HH;
			} WORD;

			struct
			{
				__IOM uint8_t FILCLKSEL_LLL;
				__IOM uint8_t FILCLKSEL_LLH;
				__IOM uint8_t FILCLKSEL_LHL;
				__IOM uint8_t FILCLKSEL_LHH;
				__IOM uint8_t FILCLKSEL_HLL;
				__IOM uint8_t FILCLKSEL_HLH;
				__IOM uint8_t FILCLKSEL_HHL;
				__IOM uint8_t FILCLKSEL_HHH;
			} BYTE;
		};
	} FILCLKSEL[49];

	__IM uint64_t RESERVED23[63];
	__IM uint64_t RESERVED24[16];

	struct
	{
		union
		{
			union
			{
		        __IOM uint64_t QWORD; /*!< (@ 0x51032C00) ISEL Register */

		        struct
		        {
		            __IOM uint64_t ISEL0 : 1;   /*!< [ 0.. 0] Interrupt enabled / disabled of pin00   */
		            uint64_t             : 7;
		            __IOM uint64_t ISEL1 : 1;   /*!< [ 8.. 8] Interrupt enabled / disabled of pin01   */
		            uint64_t             : 7;
		            __IOM uint64_t ISEL2 : 1;   /*!< [16..16] Interrupt enabled / disabled of pin02   */
		            uint64_t             : 7;
		            __IOM uint64_t ISEL3 : 1;   /*!< [24..24] Interrupt enabled / disabled of pin03   */
		            uint64_t             : 7;
		            __IOM uint64_t ISEL4 : 1;   /*!< [32..32] Interrupt enabled / disabled of pin04   */
		            uint64_t             : 7;
		            __IOM uint64_t ISEL5 : 1;   /*!< [40..40] Interrupt enabled / disabled of pin05   */
		            uint64_t             : 7;
		            __IOM uint64_t ISEL6 : 1;   /*!< [48..48] Interrupt enabled / disabled of pin06   */
		            uint64_t             : 7;
		            __IOM uint64_t ISEL7 : 1;   /*!< [56..56] Interrupt enabled / disabled of pin07   */
		            uint64_t             : 7;
		        } ISEL_b;
			};

			struct
			{
				__IOM uint32_t ISEL_L;
				__IOM uint32_t ISEL_H;
			} DWORD;

			struct
			{
				__IOM uint16_t ISEL_LL;
				__IOM uint16_t ISEL_LH;
				__IOM uint16_t ISEL_HL;
				__IOM uint16_t ISEL_HH;
			} WORD;

			struct
			{
				__IOM uint8_t ISEL_LLL;
				__IOM uint8_t ISEL_LLH;
				__IOM uint8_t ISEL_LHL;
				__IOM uint8_t ISEL_LHH;
				__IOM uint8_t ISEL_HLL;
				__IOM uint8_t ISEL_HLH;
				__IOM uint8_t ISEL_HHL;
				__IOM uint8_t ISEL_HHH;
			} BYTE;
		};
	} ISEL[49];
} R_PORT_Type;


/* =========================================================================================================================== */
/* ================                          Device Specific Peripheral Address Map                           ================ */
/* =========================================================================================================================== */

#define R_PORT_BASE             0x41030010
#define R_GPIO_BASE             0x41031010

#if _RA6M4_
 #define R_PORT0_BASE           0x40080000
 #define R_PORT1_BASE           0x40080020
 #define R_PORT2_BASE           0x40080040
 #define R_PORT3_BASE           0x40080060
 #define R_PORT4_BASE           0x40080080
 #define R_PORT5_BASE           0x400800A0
 #define R_PORT6_BASE           0x400800C0
 #define R_PORT7_BASE           0x400800E0
 #define R_PORT8_BASE           0x40080100
 #define R_PORT9_BASE           0x40080120
 #define R_PORT10_BASE          0x40080140
 #define R_PORT11_BASE          0x40080160
#endif  /* _RA6M4_ */

/* =========================================================================================================================== */
/* ================                                  Peripheral declaration                                   ================ */
/* =========================================================================================================================== */

#define R_PORT              ((R_PORT_Type *) R_PORT_BASE)
#define R_GPIO              ((R_GPIO_Type *) R_GPIO_BASE)

#if _RA6M4_
 #define R_PORT0            ((R_PORT0_Type *) R_PORT0_BASE)
 #define R_PORT1            ((R_PORT0_Type *) R_PORT1_BASE)
 #define R_PORT2            ((R_PORT0_Type *) R_PORT2_BASE)
 #define R_PORT3            ((R_PORT0_Type *) R_PORT3_BASE)
 #define R_PORT4            ((R_PORT0_Type *) R_PORT4_BASE)
 #define R_PORT5            ((R_PORT0_Type *) R_PORT5_BASE)
 #define R_PORT6            ((R_PORT0_Type *) R_PORT6_BASE)
 #define R_PORT7            ((R_PORT0_Type *) R_PORT7_BASE)
 #define R_PORT8            ((R_PORT0_Type *) R_PORT8_BASE)
 #define R_PORT9            ((R_PORT0_Type *) R_PORT9_BASE)
 #define R_PORT10           ((R_PORT0_Type *) R_PORT10_BASE)
 #define R_PORT11           ((R_PORT0_Type *) R_PORT11_BASE)
#endif  /* _RA6M4_ */

#endif
