/* generated HAL source file - do not edit */
#include "hal_data.h"
gtm_instance_ctrl_t g_timer0_ctrl;
const gtm_extended_cfg_t g_timer0_extend =
{ .generate_interrupt_when_starts = 0, .count_direction = TIMER_DIRECTION_DOWN, };
const timer_cfg_t g_timer0_cfg =
{ .mode = TIMER_MODE_PERIODIC,
  .period_counts = 12499999 /* Actual period: 0.125 seconds. */,
  .channel = 0,
  .p_callback = NULL,
  .p_context = NULL,
  .cycle_end_ipl = 128,
  .p_extend = &g_timer0_extend,
#if defined(VECTOR_NUMBER_GTM0_COUNTER_OVERFLOW)
    .cycle_end_irq       = VECTOR_NUMBER_GTM0_COUNTER_OVERFLOW,
#else
  .cycle_end_irq = GTM0_IRQn,
#endif
        };
/* Instance structure to use this module. */
const timer_instance_t g_timer0 =
{ .p_ctrl = &g_timer0_ctrl, .p_cfg = &g_timer0_cfg, .p_api = &g_timer_on_gtm };
void g_hal_init(void)
{
    g_common_init ();
}
