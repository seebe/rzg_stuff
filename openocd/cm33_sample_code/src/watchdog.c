void WatchdogInitEarly() __attribute__ ((naked));
void WatchdogTrigger();

void WatchdogInitEarly()
{
	// please use only inline assembly here
	// intenionally left empty
	__asm__ volatile ("bx r14");
}

void WatchdogInit()
{
	// intenionally left empty
}

void WatchdogTrigger()
{
	// intenionally left empty
}
