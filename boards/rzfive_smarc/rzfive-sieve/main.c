/*
 * Copyright (c) 2015-2021, Renesas Electronics Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "common.h"
#include "bit.h"
#include "cpudrv.h"
#include "tzc_400.h"
#include "mmio.h"
#include "cpg.h"
#include "ddr.h"
#include "sysc.h"

extern void main(void);

#define	RZFIVE_DEVID	(0x847C447)

void _main(void)
{
	uint32_t readDevId;

	init_tzc_400_spimulti();

	/* setup Clock and Reset */
	cpg_setup();

	udelay(100);

	ddr_setup();

	main();
}
