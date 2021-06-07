/***********************************************************************************************************************
 * Copyright [2020] Renesas Electronics Corporation and/or its affiliates.  All Rights Reserved.
 *
 * This software and documentation are supplied by Renesas Electronics America Inc. and may only be used with products
 * of Renesas Electronics Corp. and its affiliates ("Renesas").  No other uses are authorized.  Renesas products are
 * sold pursuant to Renesas terms and conditions of sale.  Purchasers are solely responsible for the selection and use
 * of Renesas products and Renesas assumes no liability.  No license, express or implied, to any intellectual property
 * right is granted by Renesas. This software is protected under all applicable laws, including copyright laws. Renesas
 * reserves the right to change or discontinue this software and/or this documentation. THE SOFTWARE AND DOCUMENTATION
 * IS DELIVERED TO YOU "AS IS," AND RENESAS MAKES NO REPRESENTATIONS OR WARRANTIES, AND TO THE FULLEST EXTENT
 * PERMISSIBLE UNDER APPLICABLE LAW, DISCLAIMS ALL WARRANTIES, WHETHER EXPLICITLY OR IMPLICITLY, INCLUDING WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NONINFRINGEMENT, WITH RESPECT TO THE SOFTWARE OR
 * DOCUMENTATION.  RENESAS SHALL HAVE NO LIABILITY ARISING OUT OF ANY SECURITY VULNERABILITY OR BREACH.  TO THE MAXIMUM
 * EXTENT PERMITTED BY LAW, IN NO EVENT WILL RENESAS BE LIABLE TO YOU IN CONNECTION WITH THE SOFTWARE OR DOCUMENTATION
 * (OR ANY PERSON OR ENTITY CLAIMING RIGHTS DERIVED FROM YOU) FOR ANY LOSS, DAMAGES, OR CLAIMS WHATSOEVER, INCLUDING,
 * WITHOUT LIMITATION, ANY DIRECT, CONSEQUENTIAL, SPECIAL, INDIRECT, PUNITIVE, OR INCIDENTAL DAMAGES; ANY LOST PROFITS,
 * OTHER ECONOMIC DAMAGE, PROPERTY DAMAGE, OR PERSONAL INJURY; AND EVEN IF RENESAS HAS BEEN ADVISED OF THE POSSIBILITY
 * OF SUCH LOSS, DAMAGES, CLAIMS OR COSTS.
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "r_gtm.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/** "GTM" in ASCII, used to determine if channel is open. */
#define GTM_OPEN                                (0x0047544DULL)

/**********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/
#if defined(__ARMCC_VERSION) || defined(__ICCARM__)
typedef void (BSP_CMSE_NONSECURE_CALL * gtm_prv_ns_callback)(timer_callback_args_t * p_args);
#elif defined(__GNUC__)
typedef BSP_CMSE_NONSECURE_CALL void (*volatile gtm_prv_ns_callback)(timer_callback_args_t * p_args);
#endif

/***********************************************************************************************************************
 * Private function prototypes
 **********************************************************************************************************************/
static void r_gtm_period_register_set(gtm_instance_ctrl_t * p_instance_ctrl, uint32_t period_counts);

static uint32_t r_gtm_clock_frequency_get(R_GTM0_Type * p_gtm_regs);

static fsp_err_t r_gtm_common_preamble(gtm_instance_ctrl_t * p_instance_ctrl);

#if GTM_CFG_PARAM_CHECKING_ENABLE
static fsp_err_t r_gtm_open_param_checking(gtm_instance_ctrl_t * p_instance_ctrl, timer_cfg_t const * const p_cfg);

#endif

/* ISRs. */
void gtm_int_isr(void);

/***********************************************************************************************************************
 * Private global variables
 **********************************************************************************************************************/

/** Version data structure. */
static const fsp_version_t s_gtm_version =
{
    .api_version_minor  = TIMER_API_VERSION_MINOR,
    .api_version_major  = TIMER_API_VERSION_MAJOR,
    .code_version_minor = GTM_CODE_VERSION_MINOR,
    .code_version_major = GTM_CODE_VERSION_MAJOR,
};

/***********************************************************************************************************************
 * Global Variables
 **********************************************************************************************************************/

/** GTM Implementation of General Timer Driver  */
const timer_api_t g_timer_on_gtm =
{
    .open         = R_GTM_Open,
    .stop         = R_GTM_Stop,
    .start        = R_GTM_Start,
    .reset        = R_GTM_Reset,
    .enable       = R_GTM_Enable,
    .disable      = R_GTM_Disable,
    .periodSet    = R_GTM_PeriodSet,
    .dutyCycleSet = R_GTM_DutyCycleSet,
    .infoGet      = R_GTM_InfoGet,
    .statusGet    = R_GTM_StatusGet,
    .callbackSet  = R_GTM_CallbackSet,
    .close        = R_GTM_Close,
    .versionGet   = R_GTM_VersionGet
};

/*******************************************************************************************************************//**
 * @addtogroup GTM
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Initializes the GTM module instance. Implements @ref timer_api_t::open.
 *
 * The GTM hardware does not support one-shot functionality natively.  The one-shot feature is therefore implemented in
 * the GTM HAL layer. For a timer configured as a one-shot timer, the timer is stopped upon the first timer expiration.
 *
 * The GTM implementation of the general timer can accept an optional gtm_extended_cfg_t extension parameter.  For
 * GTM, the extension specifies the clock to be used as timer source and the output pin configurations.  If the
 * extension parameter is not specified (NULL), the default clock PCLKB is used and the output pins are disabled.
 *
 * Example:
 * @snippet r_gtm_example.c R_GTM_Open
 *
 * @retval FSP_SUCCESS                 Initialization was successful and timer has started.
 * @retval FSP_ERR_ASSERTION           A required input pointer is NULL or the period is not in the valid range of
 *                                     1 to 0xFFFF.
 * @retval FSP_ERR_ALREADY_OPEN        R_GTM_Open has already been called for this p_ctrl.
 * @retval FSP_ERR_IRQ_BSP_DISABLED    A required interrupt has not been enabled in the vector table.
 * @retval FSP_ERR_IP_CHANNEL_NOT_PRESENT  Requested channel number is not available on GTM.
 **********************************************************************************************************************/
fsp_err_t R_GTM_Open (timer_ctrl_t * const p_ctrl, timer_cfg_t const * const p_cfg)
{
    gtm_instance_ctrl_t * p_instance_ctrl = (gtm_instance_ctrl_t *) p_ctrl;

#if GTM_CFG_PARAM_CHECKING_ENABLE
    fsp_err_t err = r_gtm_open_param_checking(p_instance_ctrl, p_cfg);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
#endif

    intptr_t base_address = (intptr_t) R_GTM0_BASE + (p_cfg->channel * ((intptr_t) R_GTM1_BASE - (intptr_t) R_GTM0_BASE));
    p_instance_ctrl->p_reg = (R_GTM0_Type *) base_address;
    p_instance_ctrl->p_cfg = p_cfg;

    /* Power on the GTM channel. */
    R_BSP_MODULE_START(FSP_IP_GTM, p_cfg->channel);
    switch(p_cfg->channel)
    {
    case 0:
		R_BSP_CLKON(BSP_CLK_GTM, 0);
		R_BSP_RSTOFF(BSP_CLK_GTM, 0);
		break;
    case 1:
		R_BSP_CLKON(BSP_CLK_GTM, 1);
		R_BSP_RSTOFF(BSP_CLK_GTM, 1);
		break;
    case 2:
		R_BSP_CLKON(BSP_CLK_GTM, 2);
		R_BSP_RSTOFF(BSP_CLK_GTM, 2);
		break;
    }

    /* Forcibly stop timer. */
    p_instance_ctrl->p_reg->OSTMnTT = 1;

    /* Set period register and update duty cycle if output mode is used for one-shot or periodic mode. */
    r_gtm_period_register_set(p_instance_ctrl, p_cfg->period_counts);

    if (p_cfg->cycle_end_irq >= 0)
    {
        R_BSP_IrqCfgEnable(p_cfg->cycle_end_irq, p_cfg->cycle_end_ipl, p_instance_ctrl);
    }

    /* Set callback and context pointers */

#if BSP_TZ_SECURE_BUILD

    /* If this is a secure build, the callback provided in p_cfg must be secure. */
    p_instance_ctrl->callback_is_secure = true;
#endif
    p_instance_ctrl->p_callback        = p_cfg->p_callback;
    p_instance_ctrl->p_context         = p_cfg->p_context;
    p_instance_ctrl->p_callback_memory = NULL;

    p_instance_ctrl->open = GTM_OPEN;

    /* All done.  */
    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Starts timer. Implements @ref timer_api_t::start.
 *
 * Example:
 * @snippet r_gtm_example.c R_GTM_Start
 *
 * @retval FSP_SUCCESS                 Timer started.
 * @retval FSP_ERR_ASSERTION           p_ctrl is null.
 * @retval FSP_ERR_NOT_OPEN            The instance control structure is not opened.
 **********************************************************************************************************************/
fsp_err_t R_GTM_Start (timer_ctrl_t * const p_ctrl)
{
    gtm_instance_ctrl_t * p_instance_ctrl = (gtm_instance_ctrl_t *) p_ctrl;

    fsp_err_t err = r_gtm_common_preamble(p_instance_ctrl);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);

    /* Start timer */
    p_instance_ctrl->p_reg->OSTMnTS = 1;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Stops the timer.  Implements @ref timer_api_t::stop.
 *
 * Example:
 * @snippet r_gtm_example.c R_GTM_Stop
 *
 * @retval FSP_SUCCESS                 Timer stopped.
 * @retval FSP_ERR_ASSERTION           p_ctrl was NULL.
 * @retval FSP_ERR_NOT_OPEN            The instance control structure is not opened.
 **********************************************************************************************************************/
fsp_err_t R_GTM_Stop (timer_ctrl_t * const p_ctrl)
{
    gtm_instance_ctrl_t * p_instance_ctrl = (gtm_instance_ctrl_t *) p_ctrl;

    fsp_err_t err = r_gtm_common_preamble(p_instance_ctrl);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);

    /* Stop timer */
    p_instance_ctrl->p_reg->OSTMnTT = 1;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Resets the counter value to the period minus one. Implements @ref timer_api_t::reset.
 *
 * @retval FSP_SUCCESS                 Counter reset.
 * @retval FSP_ERR_ASSERTION           p_ctrl is NULL
 * @retval FSP_ERR_NOT_OPEN            The instance control structure is not opened.
 **********************************************************************************************************************/
fsp_err_t R_GTM_Reset (timer_ctrl_t * const p_ctrl)
{
	(void)p_ctrl;
	return FSP_ERR_UNSUPPORTED;
}

/*******************************************************************************************************************//**
 * Enables external event triggers that start, stop, clear, or capture the counter. Implements @ref timer_api_t::enable.
 *
 * Example:
 * @snippet r_gtm_example.c R_GTM_Enable
 *
 * @retval FSP_SUCCESS                 External events successfully enabled.
 * @retval FSP_ERR_ASSERTION           p_ctrl was NULL.
 * @retval FSP_ERR_NOT_OPEN            The instance is not opened.
 **********************************************************************************************************************/
fsp_err_t R_GTM_Enable (timer_ctrl_t * const p_ctrl)
{
	(void)p_ctrl;
	return FSP_ERR_UNSUPPORTED;
}

/*******************************************************************************************************************//**
 * Disables external event triggers that start, stop, clear, or capture the counter. Implements @ref timer_api_t::disable.
 *
 * Example:
 * @snippet r_gtm_example.c R_GTM_Disable
 *
 * @retval FSP_SUCCESS                 External events successfully disabled.
 * @retval FSP_ERR_ASSERTION           p_ctrl was NULL.
 * @retval FSP_ERR_NOT_OPEN            The instance is not opened.
 **********************************************************************************************************************/
fsp_err_t R_GTM_Disable (timer_ctrl_t * const p_ctrl)
{
	(void)p_ctrl;
	return FSP_ERR_UNSUPPORTED;
}

/*******************************************************************************************************************//**
 * Updates period. The new period is updated immediately and the counter is reset to the maximum value. Implements
 * @ref timer_api_t::periodSet.
 *
 * @warning If periodic output is used, the duty cycle buffer registers are updated after the period buffer register.
 * If this function is called while the timer is running and an GTM underflow occurs during processing, the duty cycle
 * will not be the desired 50% duty cycle until the counter underflow after processing completes.
 *
 * @warning Stop the timer before calling this function if one-shot output is used.
 *
 * Example:
 * @snippet r_gtm_example.c R_GTM_PeriodSet
 *
 * @retval FSP_SUCCESS                 Period value updated.
 * @retval FSP_ERR_ASSERTION           A required pointer was NULL, or the period was not in the valid range of
 *                                     1 to 0xFFFF.
 * @retval FSP_ERR_NOT_OPEN            The instance control structure is not opened.
 **********************************************************************************************************************/
fsp_err_t R_GTM_PeriodSet (timer_ctrl_t * const p_ctrl, uint32_t const period_counts)
{
    gtm_instance_ctrl_t * p_instance_ctrl = (gtm_instance_ctrl_t *) p_ctrl;
#if GTM_CFG_PARAM_CHECKING_ENABLE

    /* Validate period parameter. */
    FSP_ASSERT(0U != period_counts);
    FSP_ASSERT(period_counts <= GTM_MAX_PERIOD);
#endif

    fsp_err_t err = r_gtm_common_preamble(p_instance_ctrl);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);

    /* Set period. */
    r_gtm_period_register_set(p_instance_ctrl, period_counts);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Updates duty cycle. If the timer is counting, the new duty cycle is reflected after the next counter underflow.
 * Implements @ref timer_api_t::dutyCycleSet.
 *
 * Example:
 * @snippet r_gtm_example.c R_GTM_DutyCycleSet
 *
 * @retval FSP_ERR_UNSUPPORTED
 **********************************************************************************************************************/
fsp_err_t R_GTM_DutyCycleSet (timer_ctrl_t * const p_ctrl, uint32_t const duty_cycle_counts, uint32_t const pin)
{
	(void)p_ctrl;
	(void)duty_cycle_counts;
	(void)pin;
	return FSP_ERR_UNSUPPORTED;
}

/*******************************************************************************************************************//**
 * Gets timer information and store it in provided pointer p_info. Implements @ref timer_api_t::infoGet.
 *
 * Example:
 * @snippet r_gtm_example.c R_GTM_InfoGet
 *
 * @retval FSP_SUCCESS                 Period, count direction, and frequency stored in p_info.
 * @retval FSP_ERR_ASSERTION           A required pointer is NULL.
 * @retval FSP_ERR_NOT_OPEN            The instance control structure is not opened.
 **********************************************************************************************************************/
fsp_err_t R_GTM_InfoGet (timer_ctrl_t * const p_ctrl, timer_info_t * const p_info)
{
    gtm_instance_ctrl_t * p_instance_ctrl = (gtm_instance_ctrl_t *) p_ctrl;
#if GTM_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_info);
#endif

    fsp_err_t err = r_gtm_common_preamble(p_instance_ctrl);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);

    /* Get and store period */
    p_info->period_counts = p_instance_ctrl->period;

    /* Get and store clock frequency */
	p_info->clock_frequency = r_gtm_clock_frequency_get(p_instance_ctrl->p_reg);

    /* GTM counting direction */
    p_info->count_direction =
    		(p_instance_ctrl->p_reg->OSTMnCTL & R_GTM0_OSTMnCTL_OSTMnMD1_Msk) ?
    				TIMER_DIRECTION_UP : TIMER_DIRECTION_UP;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Retrieves the current state and counter value stores them in p_status. Implements @ref timer_api_t::statusGet.
 *
 * Example:
 * @snippet r_gtm_example.c R_GTM_StatusGet
 *
 * @retval FSP_SUCCESS                 Current status and counter value provided in p_status.
 * @retval FSP_ERR_ASSERTION           A required pointer is NULL.
 * @retval FSP_ERR_NOT_OPEN            The instance control structure is not opened.
 **********************************************************************************************************************/
fsp_err_t R_GTM_StatusGet (timer_ctrl_t * const p_ctrl, timer_status_t * const p_status)
{
    gtm_instance_ctrl_t * p_instance_ctrl = (gtm_instance_ctrl_t *) p_ctrl;

#if GTM_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_status);
#endif

    fsp_err_t err = r_gtm_common_preamble(p_instance_ctrl);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);

    /* Read the state. */
    p_status->state = p_instance_ctrl->p_reg->OSTMnTE_b.OSTMnTE ?
    		TIMER_STATE_COUNTING : TIMER_STATE_STOPPED;

    /* Read counter value */
    p_status->counter = p_instance_ctrl->p_reg->OSTMnCNT;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Updates the user callback with the option to provide memory for the callback argument structure.
 * Implements @ref timer_api_t::callbackSet.
 *
 * @retval  FSP_SUCCESS                  Callback updated successfully.
 * @retval  FSP_ERR_ASSERTION            A required pointer is NULL.
 * @retval  FSP_ERR_NOT_OPEN             The control block has not been opened.
 * @retval  FSP_ERR_NO_CALLBACK_MEMORY   p_callback is non-secure and p_callback_memory is either secure or NULL.
 **********************************************************************************************************************/
fsp_err_t R_GTM_CallbackSet (timer_ctrl_t * const          p_api_ctrl,
                             void (                      * p_callback)(timer_callback_args_t *),
                             void const * const            p_context,
                             timer_callback_args_t * const p_callback_memory)
{
    gtm_instance_ctrl_t * p_ctrl = (gtm_instance_ctrl_t *) p_api_ctrl;

#if GTM_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_ctrl);
    FSP_ASSERT(p_callback);
    FSP_ERROR_RETURN(GTM_OPEN == p_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

#if BSP_TZ_SECURE_BUILD

    /* Get security state of p_callback */
    p_ctrl->callback_is_secure =
        (NULL == cmse_check_address_range((void *) p_callback, sizeof(void *), CMSE_AU_NONSECURE));

 #if GTM_CFG_PARAM_CHECKING_ENABLE

    /* In secure projects, p_callback_memory must be provided in non-secure space if p_callback is non-secure */
    timer_callback_args_t * const p_callback_memory_checked = cmse_check_pointed_object(p_callback_memory,
                                                                                        CMSE_AU_NONSECURE);
    FSP_ERROR_RETURN(p_ctrl->callback_is_secure || (NULL != p_callback_memory_checked), FSP_ERR_NO_CALLBACK_MEMORY);
 #endif
#endif

    /* Store callback and context */

#if BSP_TZ_SECURE_BUILD

    /* cmse_check_address_range returns NULL if p_callback is located in secure memory */
    p_ctrl->callback_is_secure =
        (NULL == cmse_check_address_range((void *) p_callback, sizeof(void *), CMSE_AU_NONSECURE));
#endif
    p_ctrl->p_callback        = p_callback;
    p_ctrl->p_context         = p_context;
    p_ctrl->p_callback_memory = p_callback_memory;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Stops counter, disables interrupts, disables output pins, and clears internal driver data.  Implements
 * @ref timer_api_t::close.
 *
 *
 *
 * @retval FSP_SUCCESS                 Timer closed.
 * @retval FSP_ERR_ASSERTION           p_ctrl is NULL.
 * @retval FSP_ERR_NOT_OPEN            The instance control structure is not opened.
 **********************************************************************************************************************/
fsp_err_t R_GTM_Close (timer_ctrl_t * const p_ctrl)
{
    gtm_instance_ctrl_t * p_instance_ctrl = (gtm_instance_ctrl_t *) p_ctrl;

    fsp_err_t err = r_gtm_common_preamble(p_instance_ctrl);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);

    /* Cleanup the device: Stop counter, disable interrupts, and power down if no other channels are in use. */

    /* Stop timer */
    p_instance_ctrl->p_reg->OSTMnTT = 1;

    if (FSP_INVALID_VECTOR != p_instance_ctrl->p_cfg->cycle_end_irq)
    {
        NVIC_DisableIRQ(p_instance_ctrl->p_cfg->cycle_end_irq);
        R_FSP_IsrContextSet(p_instance_ctrl->p_cfg->cycle_end_irq, p_instance_ctrl);
    }

    p_instance_ctrl->open = 0U;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Sets driver version based on compile time macros.  Implements @ref timer_api_t::versionGet.
 *
 * @retval     FSP_SUCCESS          Version in p_version.
 * @retval     FSP_ERR_ASSERTION    The parameter p_version is NULL.
 **********************************************************************************************************************/
fsp_err_t R_GTM_VersionGet (fsp_version_t * const p_version)
{
#if GTM_CFG_PARAM_CHECKING_ENABLE

    /* Verify parameters are valid */
    FSP_ASSERT(NULL != p_version);
#endif

    p_version->version_id = s_gtm_version.version_id;

    return FSP_SUCCESS;
}

/** @} (end addtogroup GTM) */

/***********************************************************************************************************************
 * Private Functions
 **********************************************************************************************************************/

#if GTM_CFG_PARAM_CHECKING_ENABLE

/*******************************************************************************************************************//**
 * Parameter checking for R_GTM_Open.
 *
 * @param[in] p_instance_ctrl          Pointer to instance control structure.
 * @param[in]  p_cfg              Configuration structure for this instance
 *
 * @retval FSP_SUCCESS                 Initialization was successful and timer has started.
 * @retval FSP_ERR_ASSERTION           A required input pointer is NULL or the period is not in the valid range of
 *                                     1 to 0xFFFF.
 * @retval FSP_ERR_ALREADY_OPEN        R_GTM_Open has already been called for this p_ctrl.
 * @retval FSP_ERR_IRQ_BSP_DISABLED    A required interrupt has not been enabled in the vector table.
 * @retval FSP_ERR_IP_CHANNEL_NOT_PRESENT  Requested channel number is not available on GTM.
 **********************************************************************************************************************/
static fsp_err_t r_gtm_open_param_checking (gtm_instance_ctrl_t * p_instance_ctrl, timer_cfg_t const * const p_cfg)
{
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ASSERT(NULL != p_cfg);
    FSP_ASSERT(NULL != p_cfg->p_extend);
    FSP_ERROR_RETURN(GTM_OPEN != p_instance_ctrl->open, FSP_ERR_ALREADY_OPEN);

    /* Enable IRQ if user supplied a callback function,
     *  or if the timer is a one-shot timer (so the driver is able to
     *  turn off the timer after one period. */
    if ((NULL != p_cfg->p_callback) || (TIMER_MODE_ONE_SHOT == p_cfg->mode))
    {
        /* Return error if IRQ is required and not in the vector table. */
        FSP_ERROR_RETURN(p_cfg->cycle_end_irq >= 0, FSP_ERR_IRQ_BSP_DISABLED);
    }

    FSP_ASSERT(0U != p_cfg->period_counts);

    /* Validate period parameter. */
    FSP_ASSERT((uint64_t)p_cfg->period_counts <= GTM_MAX_PERIOD);

    /* Validate channel number. */
    FSP_ERROR_RETURN(((1U << p_cfg->channel) & BSP_FEATURE_GTM_VALID_CHANNEL_MASK), FSP_ERR_IP_CHANNEL_NOT_PRESENT);

    return FSP_SUCCESS;
}

#endif

/*******************************************************************************************************************//**
 * Common code at the beginning of all GTM functions except open.
 *
 * @param[in] p_instance_ctrl          Pointer to instance control structure.
 *
 * @retval FSP_SUCCESS                 No invalid conditions detected, timer state matches expected state.
 * @retval FSP_ERR_ASSERTION           p_ctrl is null.
 * @retval FSP_ERR_NOT_OPEN            The instance control structure is not opened.
 **********************************************************************************************************************/
static fsp_err_t r_gtm_common_preamble (gtm_instance_ctrl_t * p_instance_ctrl)
{
#if GTM_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(GTM_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#else
    (void)p_instance_ctrl;
#endif


    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Sets period register and updates compare match registers in one-shot and periodic mode.
 *
 * @param[in]  p_instance_ctrl    Control block for this instance
 * @param[in]  period_counts      GTM period in counts
 **********************************************************************************************************************/
static void r_gtm_period_register_set (gtm_instance_ctrl_t * p_instance_ctrl, uint32_t period_counts)
{
    /* Store the period value so it can be retrieved later. */
    p_instance_ctrl->period = period_counts;

    /* Set counter to period. */
    p_instance_ctrl->p_reg->OSTMnCMP = period_counts;
}

/*******************************************************************************************************************//**
 * Obtains the clock frequency of GTM for all clock sources except GTM0 underflow, with divisor applied.
 *
 * @param[in]  p_gtm_regs         Registers of GTM channel used
 *
 * @return Source clock frequency of GTM in Hz, divider applied.
 **********************************************************************************************************************/
static uint32_t r_gtm_clock_frequency_get (R_GTM0_Type * p_gtm_regs)
{
	(void)p_gtm_regs;
    uint32_t           clock_freq_hz    = 0U;

	/* Call CGC function to obtain current PCLKB clock frequency. */
	clock_freq_hz = R_FSP_SystemClockHzGet(FSP_PRIV_CLOCK_P0CLK);

    return clock_freq_hz;
}

/*********************************************************************************************************************
 * GTM counter underflow interrupt.
 **********************************************************************************************************************/
void gtm_int_isr (void)
{
    /* Save context if RTOS is used */
    FSP_CONTEXT_SAVE

    IRQn_Type irq = R_FSP_CurrentIrqGet();

    /* Clear pending IRQ to make sure it doesn't fire again after exiting */
    R_BSP_IrqStatusClear(irq);

    /* Recover ISR context saved in open. */
    gtm_instance_ctrl_t * p_instance_ctrl = (gtm_instance_ctrl_t *) R_FSP_IsrContextGet(irq);

    /* If the channel is configured to be one-shot mode, stop the timer. */
    if (TIMER_MODE_ONE_SHOT == p_instance_ctrl->p_cfg->mode)
    {
        /* Stop timer */
        p_instance_ctrl->p_reg->OSTMnTT = 1;
    }

    /* Invoke the callback function if it is set. */
    if (NULL != p_instance_ctrl->p_callback)
    {
        /* Setup parameters for the user-supplied callback function. */
        timer_callback_args_t callback_args;

        /* Store callback arguments in memory provided by user if available.  This allows callback arguments to be
         * stored in non-secure memory so they can be accessed by a non-secure callback function. */
        timer_callback_args_t * p_args = p_instance_ctrl->p_callback_memory;
        if (NULL == p_args)
        {
            /* Store on stack */
            p_args = &callback_args;
        }
        else
        {
            /* Save current arguments on the stack in case this is a nested interrupt. */
            callback_args = *p_args;
        }

        p_args->p_context = p_instance_ctrl->p_context;

#if BSP_TZ_SECURE_BUILD

        /* p_callback can point to a secure function or a non-secure function. */
        if (p_instance_ctrl->callback_is_secure)
        {
            /* If p_callback is secure, then the project does not need to change security state. */
            p_instance_ctrl->p_callback(p_args);
        }
        else
        {
            /* If p_callback is Non-secure, then the project must change to Non-secure state in order to call the callback. */
            gtm_prv_ns_callback p_callback = (gtm_prv_ns_callback) (p_instance_ctrl->p_callback);
            p_callback(p_args);
        }

#else

        /* If the project is not Trustzone Secure, then it will never need to change security state in order to call the callback. */
        p_instance_ctrl->p_callback(p_args);
#endif

        if (NULL != p_instance_ctrl->p_callback_memory)
        {
            /* Restore callback memory in case this is a nested interrupt. */
            *p_instance_ctrl->p_callback_memory = callback_args;
        }
    }

    /* Restore context if RTOS is used */
    FSP_CONTEXT_RESTORE
}
