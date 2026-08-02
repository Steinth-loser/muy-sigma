/*
 * blink.c
 *
 *  Created on: Jul 4, 2026
 *      Author: th3ka
 */


#include "app.h"
#include "bsp.h"
#include "qpc.h"
#include "rtc.h"

Satellite sat;


/* State function prototypes */
static QState idle(Satellite * const me, void const * const par);


static QState readyToFlight(Satellite * const me, QEvt const * const e);
static QState rising(Satellite * const me, QEvt const * const e);
static QState landing(Satellite * const me, QEvt const * const e);
static QState leaving(Satellite * const me, QEvt const * const e);
static QState recovery(Satellite * const me, QEvt const * const e);
/////////////////////////////////////////
/*Substates for payload landing*/
static QState payloadLanding1(Satellite * const me, QEvt const * const e);
static QState hanging(Satellite * const me, QEvt const * const e);
static QState payloadLanding2(Satellite * const me, QEvt const * const e);
/////////////////////////////////////////
/*Super States*/
static QState telemetryActive(Satellite * const me, QEvt const * const e);
static QState telemetryDeactiveRecovery(Satellite * const me, QEvt const * const e);



void Satellite_Ctor(void) {
    Satellite*me = &sat;

    QActive_ctor(&me->super, Q_STATE_CAST(&idle));
    QTimeEvt_ctorX(&me->heightCalcTimeEvt, &me->super, HEIGHT_TIMEOUT_SIG, 0U);
    QTimeEvt_ctorX(&me->telTimeEvt, &me->super, TELEMETRY_TIMEOUT_SIG, 0U);
    QTimeEvt_ctorX(&me->tenSecTimeEvt, &me->super, TEN_SEC_TIMEOUT_SIG, 0U);
    QTimeEvt_ctorX(&me->buzzTimeEvt, &me->super, BUZZER_TIMEOUT_SIG, 0U);


}

static QState idle(Satellite * const me, void const * const par) {
    (void)par;
    // arm the timers
    QTimeEvt_armX(&me->telTimeEvt, BSP_TICKS_PER_SEC, BSP_TICKS_PER_SEC);
    QTimeEvt_armX(&me->heightCalcTimeEvt, BSP_TICKS_PER_SEC/100, BSP_TICKS_PER_SEC/100);
    uint8_t value = HAL_RTCEx_BKUPRead(&hrtc, RTC_BKP_DR0);
    switch (value) {
    case 0:
    	return Q_TRAN(&readyToFlight);

    case 1:
    	return Q_TRAN(&rising);

    case 2:
    	return Q_TRAN(&landing);

    case 3:
    	return Q_TRAN(&leaving);

    case 4:
    	return Q_TRAN(&payloadLanding1);

    case 5:
    	return Q_TRAN(&hanging);

    case 6:
    	return Q_TRAN(&payloadLanding2);

    case 7:
    	return Q_TRAN(&recovery);

    case 8:
    	return Q_TRAN(&telemetryDeactiveRecovery);

    default:
    	return Q_TRAN(&readyToFlight);
    }



}


/////////////// UÇUŞA HAZIR DURUMU


static QState readyToFlight(Satellite * const me, QEvt const * const e)
{


	switch (e->sig) {
	case Q_ENTRY_SIG:
		HAL_RTCEx_BKUPWrite(&hrtc, RTC_BKP_DR0, (uint32_t) 0);
		return Q_HANDLED();

	case HEIGHT_TIMEOUT_SIG:
		BSP_Height_Stat stat = BSP_calculate_height();
		if(stat == RISING) {


			return Q_TRAN(&rising);
		}


	default:
		return Q_SUPER(&telemetryActive);

	}

}



/////////////// YÜKSELME DURUMU



static QState rising(Satellite * const me, QEvt const * const e)
{



	switch(e->sig) {

	case Q_ENTRY_SIG:
		HAL_RTCEx_BKUPWrite(&hrtc, RTC_BKP_DR0, (uint32_t) 1);

		return Q_HANDLED();

	case HEIGHT_TIMEOUT_SIG:
		BSP_Height_Stat stat = BSP_calculate_height();
		if(stat == LANDING) {


			return Q_TRAN(&landing);
		}

	default:
		return Q_SUPER(&telemetryActive);
	}


}



///////////////// İNİŞ DURUMU


static QState landing(Satellite * const me, QEvt const * const e)
{




	switch(e->sig) {

	case Q_ENTRY_SIG:
		HAL_RTCEx_BKUPWrite(&hrtc, RTC_BKP_DR0, (uint32_t) 2);

		BSP_PID_Update_landing();

		return Q_HANDLED();


	case HEIGHT_TIMEOUT_SIG:
		BSP_Height_Stat stat = BSP_calculate_height();

		BSP_PID_Update_landing();

		if(stat == LEAVING) {

			return Q_TRAN(&leaving);
		}

	default:
		return Q_SUPER(&telemetryActive);

	}


}



///////////////// AYRILMA DURUMU


static QState leaving(Satellite * const me, QEvt const * const e)
{




	switch(e->sig) {

	case Q_ENTRY_SIG:
		HAL_RTCEx_BKUPWrite(&hrtc, RTC_BKP_DR0, (uint32_t) 3);

		BSP_Leave_Carrier();

		return Q_TRAN(&payloadLanding1);

	default:
		return Q_SUPER(&telemetryActive);
	}


}



/////////////// GÖREV YÜKÜ İNİŞ 1 DURUMU


static QState payloadLanding1(Satellite * const me, QEvt const * const e)
{




	switch(e->sig) {

	case Q_ENTRY_SIG:
		HAL_RTCEx_BKUPWrite(&hrtc, RTC_BKP_DR0, (uint32_t) 4);

		return Q_HANDLED();

	case HEIGHT_TIMEOUT_SIG:

		BSP_Height_Stat stat = BSP_calculate_height();

		BSP_PID_Update_landing();

		if(stat == HANGING) {

			return Q_TRAN(&hanging);

		}

	default:

		return Q_SUPER(&telemetryActive);

	}


}



////////////////// ASILI KALMA DURUMU (BONUS 1)



static QState hanging(Satellite * const me, QEvt const * const e)
{
	switch(e->sig) {
	case Q_ENTRY_SIG:
		HAL_RTCEx_BKUPWrite(&hrtc, RTC_BKP_DR0, (uint32_t) 5);

		QTimeEvt_armX(&me->tenSecTimeEvt, 10000U, 0U);

		return Q_HANDLED();

	case HEIGHT_TIMEOUT_SIG:
		BSP_Height_Stat stat = BSP_calculate_height();

		if(stat == LANDING) {
			return Q_TRAN(&payloadLanding2);
		}

		BSP_PID_Update_hanging();

		return Q_HANDLED();

	case TEN_SEC_TIMEOUT_SIG:

		return Q_TRAN(&payloadLanding2);

	default:
		return Q_SUPER(&telemetryActive);
	}

}



////////////////// GÖREV YÜKÜ İNİŞ DURUMU 2



static QState payloadLanding2(Satellite * const me, QEvt const * const e)
{
	switch(e->sig) {
	case Q_ENTRY_SIG:

		HAL_RTCEx_BKUPWrite(&hrtc, RTC_BKP_DR0, (uint32_t) 6);

		return Q_HANDLED();

	case HEIGHT_TIMEOUT_SIG:

		BSP_Height_Stat stat = BSP_calculate_height();

		BSP_PID_Update_landing();

		if(stat == RECOVERY) {
			return Q_TRAN(&recovery);
		}

	default:

		return Q_SUPER(&telemetryActive);

	}
}



////////////////// TELEMETRİ AKTİF/ KURTARMA DURUMU


static QState recovery(Satellite * const me, QEvt const * const e)
{
	switch(e->sig) {
	case Q_ENTRY_SIG:

		HAL_RTCEx_BKUPWrite(&hrtc, RTC_BKP_DR0, (uint32_t) 7);

		QTimeEvt_armX(&me->tenSecTimeEvt, 10000U, 0U);

		QTimeEvt_armX(&me->buzzTimeEvt, 500U, 500U);

		return Q_HANDLED();

	case BUZZER_TIMEOUT_SIG:

		BSP_Buzzer();

		return Q_HANDLED();

	case TEN_SEC_TIMEOUT_SIG:

		return Q_TRAN(&telemetryDeactiveRecovery);

	default:

		return Q_SUPER(&telemetryActive);

	}
}



//////////////////// TELEMETRİ PASİF / KURTARMA DURUMU



static QState telemetryDeactiveRecovery(Satellite * const me, QEvt const * const e)
{
	switch(e->sig) {
	case Q_ENTRY_SIG:

		HAL_RTCEx_BKUPWrite(&hrtc, RTC_BKP_DR0, (uint32_t) 8);

		return Q_HANDLED();

	case BUZZER_TIMEOUT_SIG:

		BSP_Buzzer();

		return Q_HANDLED();


	}
	return Q_SUPER(&QHsm_top);
}




////////////////// TELEMETRİ AKTİF SÜPER DURUMU




static QState telemetryActive(Satellite * const me, QEvt const * const e)
{
	switch(e->sig) {
	case Q_ENTRY_SIG:

		return Q_HANDLED();

	case RX_COMMAND_SIG:

		BSP_Command_Stat stat = BSP_ProcessCommand();

		if(stat == LEAVE) {
			BSP_Leave_Carrier();

			return Q_TRAN(&leaving);
		}

		else if(stat == OPEN_PARACHUTE) {

			BSP_Open_Parachute();

			return Q_HANDLED();
		}

	case TELEMETRY_TIMEOUT_SIG:

		BSP_Create_Packet();

		BSP_Save_to_SD();

		BSP_Send_Packet();

		return Q_HANDLED();

	}
	return Q_SUPER(&QHsm_top);
}


































