/*
 * servo.h
 *
 *  Created on: Jul 25, 2026
 *      Author: th3ka
 */

#ifndef INC_SERVO_H_
#define INC_SERVO_H_

#include "stm32f4xx_hal.h"
#include <stdint.h>

#define SERVO_DEFAULT_MIN_PULSE_US   500U
#define SERVO_DEFAULT_MAX_PULSE_US   2500U

#define SERVO_PWM_PERIOD_US          20000U


typedef struct {
	TIM_HandleTypeDef *htim;
	uint32_t channel;

    uint16_t min_pulse_us;
    uint16_t max_pulse_us;
    float    min_angle;
    float    max_angle;

    uint16_t current_pulse_us;
}Servo;

typedef enum
{
    SERVO_OK       = 0,
    SERVO_ERROR    = 1,
    SERVO_ERR_ARG  = 2
} Servo_StatusTypeDef;


Servo_StatusTypeDef Servo_Init(Servo *servo, TIM_HandleTypeDef *htim, uint32_t channel);


Servo_StatusTypeDef Servo_SetRange(Servo *servo, uint16_t min_pulse_us, uint16_t max_pulse_us, float min_angle, float max_angle);


Servo_StatusTypeDef Servo_SetAngle(Servo *servo, float angle_deg);


Servo_StatusTypeDef Servo_SetPulseWidth(Servo *servo, uint16_t pulse_us);


Servo_StatusTypeDef Servo_Stop(Servo *servo);


Servo_StatusTypeDef Servo_Start(Servo *servo);


#endif /* INC_SERVO_H_ */
