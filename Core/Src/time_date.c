/*
 * time_date->c
 *
 *  Created on: 1 Aug 2026
 *      Author: th3ka
 */

#include "time_date.h"

void Set_RTC_Time_Date(RTC_TimeTypeDef* sTime, RTC_DateTypeDef* sDate)
{
	sTime->Hours = 14;
	sTime->Minutes = 30;
	sTime->Seconds = 0;
	sTime->DayLightSaving = RTC_DAYLIGHTSAVING_NONE;
	sTime->StoreOperation = RTC_STOREOPERATION_RESET;

	if (HAL_RTC_SetTime(&hrtc, sTime, RTC_FORMAT_BIN) != HAL_OK) {
		Error_Handler();
	}

	// Tarihi ayarla: 1 Ağustos 2026, Cumartesi
	sDate->WeekDay = RTC_WEEKDAY_SATURDAY;
	sDate->Month = RTC_MONTH_AUGUST;
	sDate->Date = 1;
	sDate->Year = 26; // Sadece son iki hane (2026 için 26)

	if (HAL_RTC_SetDate(&hrtc, sDate, RTC_FORMAT_BIN) != HAL_OK) {
		Error_Handler();
	}
}
