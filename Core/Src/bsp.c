/*
 * bsp.c
 *
 *  Created on: Jul 4, 2026
 *      Author: th3ka
 */


#include "gpio.h"
#include "bsp.h"
#include "qpc.h"
#include "tim.h"
#include "esc.h"
#include "servo.h"
#include <stdint.h>
#include "time_date.h"
#include <string.h>
#include "crc.h"

/* RTC Variables*/
RTC_TimeTypeDef sTime;
RTC_DateTypeDef sDate;
/* Telemetry variable*/
BSP_telemetry tel;
/* Brushless DC */
ESC_HandleTypeDef esc1;
/* Servo Motor */
Servo servo1;
// PID CONTROLLER
PIDController pid1;

// Buffer for command handling
uint8_t buffer[16];

// Descending Velocity
float des_vel;



// BSP API

void BSP_Init(void)
{
	//RTC initialization
	Set_RTC_Time_Date(&sTime, &sDate);

	// Telemetry init
	tel.packet_start = PACKET_START;
	tel.packet_number = 0;
	tel.sat_stat = 3;
	tel.error_code = 1;

	tel.press = 0.0;
	tel.height = 0.0;
	tel.des_vel = 0.0;
	tel.temp = 0.0;
	tel.volt = 0.0;
	tel.latitude = 0.0;
	tel.longtitude = 0.0;
	tel.altitude = 0.0;
	tel.pitch = 0.0;
	tel.roll = 0.0;
	tel.yaw = 0.0;

	uint8_t bonus2_vals[6] = { 0, 0x52, 0, 0x47, 0, 0x42 };
	memcpy(tel.bonus2, bonus2_vals, sizeof(bonus2_vals));

	tel.team_number = 566;
	tel.packet_end = PACKET_END;

	//Pasive object inits. (sensors will be added)
	ESC_Init(&esc1, &htim2, 0x00000000U);
	Servo_Init(&servo1, &htim4, 0x00000000U);

	PIDController_Init(&pid1);
	// Sensors here...

	// RX interrupt setting for command processing
	HAL_UARTEx_ReceiveToIdle_IT(&huart1, buffer, 64);
}

// Leaving the carrier
void BSP_Leave_Carrier(void)
{
	Servo_SetAngle(&servo1, 110.0);
}

// PID Updating functions
void BSP_PID_Update_landing(void)
{
	float pid_signal = PIDController_Update(&pid1, 6, des_vel);
	uint16_t pwm_signal = 1000U + (uint16_t) ((pid_signal * 1000.0f) + 0.5f);

	ESC_SetPulseWidth(&esc1, pwm_signal);
}

void BSP_PID_Update_hanging(void)
{
	float pid_signal = PIDController_Update(&pid1, 0, des_vel);
	uint16_t pwm_signal = 1000U + (uint16_t) ((pid_signal * 1000.0f) + 0.5f);

	ESC_SetPulseWidth(&esc1, pwm_signal);
}


// Open the parachute
void BSP_Open_Parachute(void)
{
	// will be filled
	return;
}

// Creating telemetry packet
void BSP_Create_Packet(void)
{
	// Sensors will be used here
	// ...

	HAL_RTC_GetTime(&hrtc, &sTime, RTC_FORMAT_BIN);
	HAL_RTC_GetDate(&hrtc, &sDate, RTC_FORMAT_BIN);

	tel.rtc_year = sDate.Year;
	tel.rtc_month = sDate.Month;
	tel.rtc_day = sDate.Date;
	tel.rtc_hour = sTime.Hours;
	tel.rtc_minute = sTime.Minutes;
	tel.rtc_second = sTime.Seconds;

	// 2. Paket numarasını artır
	tel.packet_number++;

	tel.crc32 = HAL_CRC_Calculate(&hcrc, (uint32_t*) &tel, 18);
}

// Writing the data to sd card
void BSP_Save_to_SD(void)
{
	// SDIO will be used here
	// ...
}

// Send the data through LoRa
void BSP_Send_Packet(void)
{
	HAL_UART_Transmit_DMA(&huart1, (uint8_t*)&tel, sizeof(tel));
}


// Buzzer Beeping
void BSP_Buzzer(void)
{
	// Handle buzzer here
}


// Process the ground station's command
BSP_Command_Stat BSP_ProcessCommand(void)
{
	if (buffer[0] == 0) {
		return LEAVE;
	}

	else if(buffer[0] == 1) {
		return OPEN_PARACHUTE;
	}

	else if(buffer[0] == 2) {
		HAL_UART_Transmit_DMA(&huart2, &buffer[1], sizeof(tel.bonus2));
		return BONUS_2;
	}
	else {
		return CMD_ERROR;
	}
}

// Calculating the height and velocity.
BSP_Height_Stat BSP_calculate_height(void)
{
	// The barometer will be used here,
	// According to sampling time, velocity will be calculated to determine velocity

	return HGHT_ERROR;
}
























//NEEDED IN EVERY PROJECT
void Q_onError(char const * const module, int_t const id) {
    (void)module;
    (void)id;
    __disable_irq();     // kesmeleri kapat
    NVIC_SystemReset();  // ya da burada kendi hata yönetimini yaz (LED yakıp sonsuz döngü vs.)
}

/* QF başlarken bir kere çağrılır  */
void QF_onStartup(void) {
	NVIC_SetPriority(SysTick_IRQn, QF_AWARE_ISR_CMSIS_PRI);
    /* Örn: SysTick önceliğini ayarla, gerekli interrupt'ları enable et */
}

/* QV kernel boşta kaldığında (işlenecek event yokken) sürekli çağrılır */
void QV_onIdle(void) {
	QF_INT_ENABLE();
    /* Örn: düşük güç moduna geç, ya da boş bırak (__WFI() de kullanılabilir) */
}
