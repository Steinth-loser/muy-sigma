/*
 * esc.h
 *
 *  Created on: Jul 25, 2026
 *      Author: th3ka
 */

#ifndef INC_ESC_H_
#define INC_ESC_H_

#include "stm32f4xx_hal.h"
#include <stdint.h>

#define ESC_DEFAULT_MIN_PULSE_US     1000U  /* throttle %0   */
#define ESC_DEFAULT_MAX_PULSE_US     2000U  /* throttle %100 */

#define ESC_PWM_PERIOD_US            20000U /* 20ms -> 50Hz, sabit */

#define ESC_ARMING_DURATION_MS       2500U


typedef struct
{
    TIM_HandleTypeDef* htim;
    uint32_t           channel;

    uint16_t min_pulse_us;   /* throttle %0 pulse degeri   */
    uint16_t max_pulse_us;   /* throttle %100 pulse degeri */

    uint16_t current_pulse_us;
    uint8_t  is_armed;       /* 1 = arming tamamlandi */
} ESC_HandleTypeDef;

typedef enum
{
    ESC_OK      = 0,
    ESC_ERROR   = 1,
    ESC_ERR_ARG = 2
} ESC_StatusTypeDef;


ESC_StatusTypeDef ESC_Init(ESC_HandleTypeDef *esc, TIM_HandleTypeDef *htim, uint32_t channel);


ESC_StatusTypeDef ESC_SetRange(ESC_HandleTypeDef *esc, uint16_t min_pulse_us, uint16_t max_pulse_us);


ESC_StatusTypeDef ESC_Arm(ESC_HandleTypeDef *esc);


ESC_StatusTypeDef ESC_SetThrottlePercent(ESC_HandleTypeDef *esc, float percent);


ESC_StatusTypeDef ESC_SetPulseWidth(ESC_HandleTypeDef *esc, uint16_t pulse_us);


ESC_StatusTypeDef ESC_Stop(ESC_HandleTypeDef *esc);


ESC_StatusTypeDef ESC_PWM_Disable(ESC_HandleTypeDef *esc);












#endif /* INC_ESC_H_ */
