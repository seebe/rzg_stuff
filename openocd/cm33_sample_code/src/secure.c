
#define TRUE 1
#define FALSE 0

#if !(defined(NONSECURE_BASE)&&(__ARM_FEATURE_CMSE>0))
# error "This code must be compiled with ARM CortexM security extensions"
#endif

int __attribute__ ((cmse_nonsecure_entry)) func10(void)
{
	static int __attribute__ ((cmse_nonsecure_call)) (*s_fnNonsecure) (void);

	register int i;
	register int v1, v2, v3, v4, v5, v6, v7, v8;
	register int v9, v10, v11, v12, v13, v14, v15, v16, v17;

	v17 = 0;
	for ( i = 0 ; i < 3 ; i++ )
		v17 += i;

	for ( v1 = 0 ; v1 < 3 ; v1++ )
		v17 += v1;
	for ( v2 = 0 ; v2 < 3 ; v2++ )
		v17 += v2;
	for ( v3 = 0 ; v3 < 3 ; v3++ )
		v17 += v3;
	for ( v4 = 0 ; v4 < 3 ; v4++ )
		v17 += v4;
	for ( v5 = 0 ; v5 < 3 ; v5++ )
		v17 += v5;
	for ( v6 = 0 ; v6 < 3 ; v6++ )
		v17 += v6;
	for ( v7 = 0 ; v7 < 3 ; v7++ )
		v17 += v7;
	for ( v8 = 0 ; v8 < 3 ; v8++ )
		v17 += v8;
	for ( v9 = 0 ; v9 < 3 ; v9++ )
		v17 += v9;
	for ( v10 = 0 ; v10 < 3 ; v10++ )
		v17 += v10;
	for ( v11 = 0 ; v11 < 3 ; v11++ )
		v17 += v11;
	for ( v12 = 0 ; v12 < 3 ; v12++ )
		v17 += v12;
	for ( v13 = 0 ; v13 < 3 ; v13++ )
		v17 += v13;
	for ( v14 = 0 ; v14 < 3 ; v14++ )
		v17 += v14;
	for ( v15 = 0 ; v15 < 3 ; v15++ )
		v17 += v15;
	for ( v16 = 0 ; v16 < 3 ; v16++ )
		v17 += v16;

	if (s_fnNonsecure)
		i = (*s_fnNonsecure) ();

	i = v17;

	for ( v1 = 0 ; v1 < 3 ; v1++ )
		v17 += v1;
	for ( v2 = 0 ; v2 < 3 ; v2++ )
		v17 += v2;
	for ( v3 = 0 ; v3 < 3 ; v3++ )
		v17 += v3;
	for ( v4 = 0 ; v4 < 3 ; v4++ )
		v17 += v4;
	for ( v5 = 0 ; v5 < 3 ; v5++ )
		v17 += v5;
	for ( v6 = 0 ; v6 < 3 ; v6++ )
		v17 += v6;
	for ( v7 = 0 ; v7 < 3 ; v7++ )
		v17 += v7;
	for ( v8 = 0 ; v8 < 3 ; v8++ )
		v17 += v8;
	for ( v9 = 0 ; v9 < 3 ; v9++ )
		v17 += v9;
	for ( v10 = 0 ; v10 < 3 ; v10++ )
		v17 += v10;
	for ( v11 = 0 ; v11 < 3 ; v11++ )
		v17 += v11;
	for ( v12 = 0 ; v12 < 3 ; v12++ )
		v17 += v12;
	for ( v13 = 0 ; v13 < 3 ; v13++ )
		v17 += v13;
	for ( v14 = 0 ; v14 < 3 ; v14++ )
		v17 += v14;
	for ( v15 = 0 ; v15 < 3 ; v15++ )
		v17 += v15;
	for ( v16 = 0 ; v16 < 3 ; v16++ )
		v17 += v16;

	return v17;
}

void (*monHook)(void) __attribute__ ((section (".data"))) = 0;
extern void (*watchdogTrigger)(void);

int main(void)
{
	volatile unsigned int* pNonSecureBase = (unsigned int*)NONSECURE_BASE;

	if (   ((pNonSecureBase[0] & 0x7) == 0x0)
		&& ((pNonSecureBase[1] & 0x1) == 0x1)
		&& ( pNonSecureBase[1] > NONSECURE_BASE)
	   )
	{
		// set VTOR_NS
		*((volatile unsigned int*)0xe002ed08)  = NONSECURE_BASE;
#if (__ARM_FP==4)||(__ARM_FP==5)
		// set NSACR - enable FPU in NonSecure
		*((volatile unsigned int*)0xe000ed8c) |= 0xc00;
#endif
		// set MSP_NS/PSP_NS, clear GPRs, jump to NonSecure
		__asm__ (
			"msr   msp_ns,%[msp_ns] \n"
			"msr   psp_ns,%[zero]   \n"
			"msr   apsr,%[zero]     \n"
			"mov   r0, %[pc_ns]     \n"
			"mov   r1, r0           \n"
			"mov   r2, r0           \n"
			"mov   r3, r0           \n"
			"mov   r4, r0           \n"
			"mov   r5, r0           \n"
			"mov   r6, r0           \n"
			"mov   r7, r0           \n"
			"mov   r8, r0           \n"
			"mov   r9, r0           \n"
			"mov   r10,r0           \n"
			"mov   r11,r0           \n"
			"mov   r12,r0           \n"
			"blxns r0               \n"
			"1: nop                 \n"
			"b     1b               \n"
		::[msp_ns] "r" (pNonSecureBase[0]), [zero] "r" (0), [pc_ns] "r" (pNonSecureBase[1]&~0x1));
	}

	while(TRUE) 
	{
		if (monHook)
			monHook();
		if (watchdogTrigger)
			watchdogTrigger();
	
		func10();
	}

	return 0;
}


