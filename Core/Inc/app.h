/*
 * app.h
 *
 *  Created on: Jul 4, 2026
 *      Author: th3ka
 */

#ifndef INC_APP_H_
#define INC_APP_H_


#include "qpc.h"

/* Event signals */
enum AppSignals {
    HEIGHT_TIMEOUT_SIG = Q_USER_SIG,
    RX_COMMAND_SIG,
	TEN_SEC_TIMEOUT_SIG,
	BUZZER_TIMEOUT_SIG,
	TELEMETRY_TIMEOUT_SIG,
    MAX_SIG
};



/* Active Object struct */
typedef struct {
    QActive super;
    QTimeEvt heightCalcTimeEvt;
    QTimeEvt tenSecTimeEvt;
    QTimeEvt telTimeEvt;
    QTimeEvt buzzTimeEvt;
} Satellite;

extern Satellite sat;
#define AO_Satellite (&sat.super)

void Satellite_Ctor(void);




#endif /* INC_APP_H_ */
