/*
 * servo.c
 *
 *  Created on: Jul 25, 2026
 *      Author: th3ka
 */



#include "servo.h"

// Helper Functions
static uint16_t Servo_ClampPulse(Servo *servo, uint16_t pulse_us)
{
    if (pulse_us < servo->min_pulse_us) return servo->min_pulse_us;
    if (pulse_us > servo->max_pulse_us) return servo->max_pulse_us;
    return pulse_us;
}

static float Servo_ClampAngle(Servo *servo, float angle)
{
    if (angle < servo->min_angle) return servo->min_angle;
    if (angle > servo->max_angle) return servo->max_angle;
    return angle;
}

// Class Methods
Servo_StatusTypeDef Servo_Init(Servo *servo, TIM_HandleTypeDef *htim, uint32_t channel)
{
    if (servo == NULL || htim == NULL)
    {
        return SERVO_ERR_ARG;
    }

    servo->htim    = htim;
    servo->channel = channel;

    servo->min_pulse_us = SERVO_DEFAULT_MIN_PULSE_US;
    servo->max_pulse_us = SERVO_DEFAULT_MAX_PULSE_US;
    servo->min_angle    = 0.0f;
    servo->max_angle    = 180.0f;

    /* Guvenli varsayilan: orta pozisyon (90 derece) */
    servo->current_pulse_us = (uint16_t)((servo->min_pulse_us + servo->max_pulse_us) / 2U);

    if (HAL_TIM_PWM_Start(servo->htim, servo->channel) != HAL_OK)
    {
        return SERVO_ERROR;
    }

    __HAL_TIM_SET_COMPARE(servo->htim, servo->channel, servo->current_pulse_us);

    return SERVO_OK;
}



Servo_StatusTypeDef Servo_SetRange(Servo *servo, uint16_t min_pulse_us, uint16_t max_pulse_us, float min_angle, float max_angle)
{
    if (servo == NULL || min_pulse_us >= max_pulse_us || min_angle >= max_angle)
    {
        return SERVO_ERR_ARG;
    }

    if (max_pulse_us >= SERVO_PWM_PERIOD_US)
    {
        return SERVO_ERR_ARG; /* pulse periyodu asamaz */
    }

    servo->min_pulse_us = min_pulse_us;
    servo->max_pulse_us = max_pulse_us;
    servo->min_angle    = min_angle;
    servo->max_angle    = max_angle;

    return SERVO_OK;
}



Servo_StatusTypeDef Servo_SetAngle(Servo *servo, float angle_deg)
{
    if (servo == NULL || servo->htim == NULL)
    {
        return SERVO_ERR_ARG;
    }

    float clamped_angle = Servo_ClampAngle(servo, angle_deg);

    /* Dogrusal interpolasyon: angle -> pulse_us */
    float angle_span = servo->max_angle - servo->min_angle;
    float pulse_span  = (float)(servo->max_pulse_us - servo->min_pulse_us);

    float ratio = (clamped_angle - servo->min_angle) / angle_span;
    uint16_t pulse_us = servo->min_pulse_us + (uint16_t)(ratio * pulse_span);

    return Servo_SetPulseWidth(servo, pulse_us);
}

Servo_StatusTypeDef Servo_SetPulseWidth(Servo *servo, uint16_t pulse_us)
{
    if (servo == NULL || servo->htim == NULL)
    {
        return SERVO_ERR_ARG;
    }

    uint16_t clamped = Servo_ClampPulse(servo, pulse_us);

    __HAL_TIM_SET_COMPARE(servo->htim, servo->channel, clamped);
    servo->current_pulse_us = clamped;

    return SERVO_OK;
}


Servo_StatusTypeDef Servo_Stop(Servo *servo)
{
    if (servo == NULL || servo->htim == NULL)
    {
        return SERVO_ERR_ARG;
    }

    if (HAL_TIM_PWM_Stop(servo->htim, servo->channel) != HAL_OK)
    {
        return SERVO_ERROR;
    }

    return SERVO_OK;
}



Servo_StatusTypeDef Servo_Start(Servo *servo)
{
    if (servo == NULL || servo->htim == NULL)
    {
        return SERVO_ERR_ARG;
    }

    if (HAL_TIM_PWM_Start(servo->htim, servo->channel) != HAL_OK)
    {
        return SERVO_ERROR;
    }

    return SERVO_OK;
}










