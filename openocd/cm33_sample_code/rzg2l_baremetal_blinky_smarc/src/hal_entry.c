#include "hal_data.h"

FSP_CPP_HEADER
void R_BSP_WarmStart(bsp_warm_start_event_t event);
FSP_CPP_FOOTER

extern bsp_leds_t g_bsp_leds;

static void timer_isr(timer_callback_args_t * const p_unused)
{
	(void)p_unused;
    /* Holds level to set for pins */
    static bsp_io_level_t pin_level = BSP_IO_LEVEL_LOW;

        /* Update all board LEDs */
        for (uint32_t i = 0; i < g_bsp_leds.led_count; i++)
        {
            /* Get pin to toggle */
            uint32_t pin = g_bsp_leds.p_leds[i];

            /* Write to this pin */
            R_BSP_PinWrite((bsp_io_port_pin_t) pin, pin_level);
        }

        /* Toggle level for next write */
        if (BSP_IO_LEVEL_LOW == pin_level)
        {
            pin_level = BSP_IO_LEVEL_HIGH;
        }
        else
        {
            pin_level = BSP_IO_LEVEL_LOW;
        }

}

/*******************************************************************************************************************//**
 * main() is generated by the RZG2L Configuration editor and is used to generate threads if an RTOS is used.  This function
 * is called by main() when no RTOS is used.
 **********************************************************************************************************************/
void hal_entry(void) {
    /* LED type structure */
    bsp_leds_t leds = g_bsp_leds;

    /* If this board has no LEDs then trap here */
    if (0 == leds.led_count)
    {
        while (1)
        {
            ;                          // There are no LEDs on this board
        }
    }


	g_timer0.p_api->open(g_timer0.p_ctrl, g_timer0.p_cfg);
	g_timer0.p_api->callbackSet(g_timer0.p_ctrl, timer_isr, NULL, NULL);
	g_timer0.p_api->start(g_timer0.p_ctrl);

	while(1);
}

/*******************************************************************************************************************//**
 * This function is called at various points during the startup process.  This implementation uses the event that is
 * called right before main() to set up the pins.
 *
 * @param[in]  event    Where at in the start up process the code is currently at
 **********************************************************************************************************************/
void R_BSP_WarmStart(bsp_warm_start_event_t event) {
	if (BSP_WARM_START_RESET == event) {
	}

	if (BSP_WARM_START_POST_C == event) {
		/* C runtime environment and system clocks are setup. */

		/* Configure pins. */
		R_IOPORT_Open(&g_ioport_ctrl, &g_bsp_pin_cfg);
	}
}
