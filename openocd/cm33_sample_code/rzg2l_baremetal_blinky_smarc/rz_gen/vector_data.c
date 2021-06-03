/* generated vector source file - do not edit */
#include "bsp_api.h"
#include "vector_data.h"

#if VECTOR_DATA_IRQ_COUNT > 0
const bsp_interrupt_event_t g_interrupt_overwrite[VECTOR_DATA_IRQ_COUNT] =
{
    { GTM0_IRQn, gtm_int_isr }, /* GTM0 INT (GTM interrupt) */
};
#endif
