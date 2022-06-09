/*
 * Copyright (c) 2015-2021, Renesas Electronics Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef COMMON_H
#define COMMON_H

#include <stdint.h>

#ifdef AArch64
//typedef uint64_t    uintptr_t;
#define CPU_BYTE_SIZE			SIZE_64BIT
#endif

#ifdef RISCV
//typedef uint64_t    uintptr_t;
#define CPU_BYTE_SIZE			SIZE_64BIT
#endif

#ifdef AArch32
//typedef uint32_t    uintptr_t;
#define CPU_BYTE_SIZE			SIZE_32BIT
#endif


#define DIS_RTN			0		/* Disable Return		*/
#define ENB_RTN			1		/* Enable Return		*/
#define OK			0x1

#ifndef NULL
#define NULL			 0x0
#endif

#define INT_CODE		0x25		/* "%"					*/
#define BS_CODE			0x08		/* "BS"					*/
#define CR_CODE			0x0d		/* "CR"					*/
#define SP_CODE			0x20		/* "LF"					*/
#define LF_CODE			0x0a		/* "LF"					*/

#define SIZE_8BIT		1		// Old name : BYTE_SIZE
#define SIZE_16BIT		2		// Old name : WORD_SIZE
#define SIZE_32BIT		4		// Old name : LONG_SIZE
#define SIZE_64BIT		8		// New

#define COMMAND_BUFFER_SIZE	1024

#endif
