/*
 * bsp.h
 *
 *  Created on: Jul 4, 2026
 *      Author: th3ka
 */

#ifndef INC_BSP_H_
#define INC_BSP_H_

#include "gpio.h"
#include <stdint.h>
#include "qpc.h"
#include "pid.h"


#define BSP_TICKS_PER_SEC   1000U


#define PACKET_START 0x3C3C3C3C // <<<<
#define PACKET_END   0x3E3E3E3E // >>>>


// Telemetri Paketi,
// NOT: Lora için adres high, low ve channel bilgisi eklenebilir
// veya sadece channel.
typedef struct{
	uint32_t packet_start;

	uint16_t packet_number;

	uint8_t  sat_stat;

	uint8_t error_code;

	uint32_t sending_time;


	float press;
	float height;
	float des_vel;
	float temp;
	float volt;
	float latitude, longtitude, altitude;
	float pitch, roll, yaw;

	uint8_t bonus2[6];

	uint32_t team_number;

	uint32_t packet_end;

}BSP_telemetry __attribute__((packed));

// Yükeseklik sorgusu için
typedef enum {
	RISING,
	LANDING,
	LEAVING,
	HANGING,
	RECOVERY
}BSP_Height_Stat;

// Komut İşlemek için
typedef enum {
	LEAVE,
	OPEN_PARACHUTE,
	BONUS_2
}BSP_Command_Stat;

// STATIC OBJECTS




/* BSP API */

void BSP_Init(void);

void BSP_Leave_Carrier(void);

void BSP_PID_Update(void);

void BSP_Open_Parachute(void);

void BSP_Create_Packet(void);

void BSP_Save_to_SD(void);

void BSP_Send_Packet(void);

BSP_Command_Stat BSP_ProcessCommand(void);

BSP_Height_Stat BSP_calculate_height(void);






//NEEDED IN EVERY PROJECT
void Q_onError(char const * const module, int_t const id);
void QF_onStartup(void);
void QV_onIdle(void);
#endif /* INC_BSP_H_ */
