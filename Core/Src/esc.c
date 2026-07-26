/*
 * esc.c
 *
 *  Created on: Jul 25, 2026
 *      Author: th3ka
 */



#include "esc.h"

// Helper Function
static uint16_t ESC_ClampPulse(ESC_HandleTypeDef *esc, uint16_t pulse_us)
{
    if (pulse_us < esc->min_pulse_us) return esc->min_pulse_us;
    if (pulse_us > esc->max_pulse_us) return esc->max_pulse_us;
    return pulse_us;
}

// Public API

ESC_StatusTypeDef ESC_Init(ESC_HandleTypeDef *esc, TIM_HandleTypeDef *htim, uint32_t channel)
{
    if (esc == NULL || htim == NULL)
    {
        return ESC_ERR_ARG;
    }

    esc->htim    = htim;
    esc->channel = channel;

    esc->min_pulse_us = ESC_DEFAULT_MIN_PULSE_US;
    esc->max_pulse_us = ESC_DEFAULT_MAX_PULSE_US;
    esc->current_pulse_us = esc->min_pulse_us;
    esc->is_armed = 0;

    if (HAL_TIM_PWM_Start(esc->htim, esc->channel) != HAL_OK)
    {
        return ESC_ERROR;
    }

    /* Once min throttle'a cek */
    __HAL_TIM_SET_COMPARE(esc->htim, esc->channel, esc->min_pulse_us);
    esc->current_pulse_us = esc->min_pulse_us;

    /* Arming sekansi: min pulse'ta bekle */
    return ESC_Arm(esc);
}

ESC_StatusTypeDef ESC_SetRange(ESC_HandleTypeDef *esc, uint16_t min_pulse_us, uint16_t max_pulse_us)
{
    if (esc == NULL || min_pulse_us >= max_pulse_us)
    {
        return ESC_ERR_ARG;
    }

    if (max_pulse_us >= ESC_PWM_PERIOD_US)
    {
        return ESC_ERR_ARG;
    }

    esc->min_pulse_us = min_pulse_us;
    esc->max_pulse_us = max_pulse_us;

    return ESC_OK;
}

ESC_StatusTypeDef ESC_Arm(ESC_HandleTypeDef *esc)
{
    if (esc == NULL || esc->htim == NULL)
    {
        return ESC_ERR_ARG;
    }

    /* ESC'yi min throttle'da sabit tutarak arming sekansini baslat.
     * NOT: Bu fonksiyon bloklayicidir (HAL_Delay kullanir). */
    __HAL_TIM_SET_COMPARE(esc->htim, esc->channel, esc->min_pulse_us);
    esc->current_pulse_us = esc->min_pulse_us;

    HAL_Delay(ESC_ARMING_DURATION_MS);

    esc->is_armed = 1;

    return ESC_OK;
}
// istenen hızda motoru döndürür
ESC_StatusTypeDef ESC_SetThrottlePercent(ESC_HandleTypeDef *esc, float percent)
{
    if (esc == NULL || esc->htim == NULL)
    {
        return ESC_ERR_ARG;
    }

    if (percent < 0.0f)   percent = 0.0f;
    if (percent > 100.0f) percent = 100.0f;

    float pulse_span = (float)(esc->max_pulse_us - esc->min_pulse_us);
    uint16_t pulse_us = esc->min_pulse_us + (uint16_t)((percent / 100.0f) * pulse_span);

    return ESC_SetPulseWidth(esc, pulse_us);
}
// PWM sinyalini PID den alıp kullanmak için
ESC_StatusTypeDef ESC_SetPulseWidth(ESC_HandleTypeDef *esc, uint16_t pulse_us)
{
    if (esc == NULL || esc->htim == NULL)
    {
        return ESC_ERR_ARG;
    }

    uint16_t clamped = ESC_ClampPulse(esc, pulse_us);

    __HAL_TIM_SET_COMPARE(esc->htim, esc->channel, clamped);
    esc->current_pulse_us = clamped;

    return ESC_OK;
}

ESC_StatusTypeDef ESC_Stop(ESC_HandleTypeDef *esc)
{
    if (esc == NULL || esc->htim == NULL)
    {
        return ESC_ERR_ARG;
    }

    return ESC_SetPulseWidth(esc, esc->min_pulse_us);
}

ESC_StatusTypeDef ESC_PWM_Disable(ESC_HandleTypeDef *esc)
{
    if (esc == NULL || esc->htim == NULL)
    {
        return ESC_ERR_ARG;
    }

    if (HAL_TIM_PWM_Stop(esc->htim, esc->channel) != HAL_OK)
    {
        return ESC_ERROR;
    }

    esc->is_armed = 0;

    return ESC_OK;
}











