/*
 * Copyright (c) 2015-2021, Renesas Electronics Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "common.h"
#include "bit.h"
#include "cpg_regs.h"
#include "ostm_regs.h"
#include "cpudrv.h"

void StartTMU0(uint32_t tenmSec)
{
	volatile uint32_t dataL;

	PowerOnTmu0();

	*((volatile uint8_t*)OSTM0CTL)= 0x02U;		/* Free Running Mode */
	*((volatile uint8_t*)OSTM0TS) = 0x01U;		/* TMU0 Start */
	while(1)
	{
		dataL = *((volatile uint32_t*)OSTM0CNT);
		if (dataL >= (100000U * tenmSec))
		{
			break;
		}
	}
	*((volatile uint8_t*)OSTM0TT) = 0x01U;		/* TMU0 Stop */
}

void StartTMU0usec(uint32_t tenuSec)
{
	volatile uint32_t dataL;

	PowerOnTmu0();

	*((volatile uint8_t*)OSTM0CTL)= 0x02U;		/* Free Running Mode */
	*((volatile uint8_t*)OSTM0TS) = 0x01U;		/* TMU0 Start */
	while(1)
	{
		dataL = *((volatile uint32_t*)OSTM0CNT);
		if (dataL >= (100U * tenuSec))
		{
			break;
		}
	}
	*((volatile uint8_t*)OSTM0TT) = 0x01U;		/* TMU0 Stop */
}

void udelay(uint32_t count_us)
{
	StartTMU0usec(count_us);
}

void PowerOnTmu0(void)
{
	uint32_t dataL;

	dataL = *((volatile uint32_t*)CPG_CLKON_OSTM);
	dataL |= 0x00010001U;
	*((volatile uint32_t*)CPG_CLKON_OSTM) = dataL;
	do
	{
		dataL = *((volatile uint32_t*)CPG_CLKMON_OSTM);
	} while ((dataL & BIT0) == 0U);	/* wait until bit0=1 */

	dataL = *((volatile uint32_t*)CPG_RST_OSTM);
	dataL |= 0x00010001U;
	*((volatile uint32_t*)CPG_RST_OSTM) = dataL;
	do
	{
		dataL = *((volatile uint32_t*)CPG_RSTMON_OSTM);
	} while ((dataL & BIT0) == 1U);	/* wait until bit0=1 */
}
