/*
 * PID.c
 *
 *  Created on: Mar 8, 2026
 *      Author: th3ka
 */


#include "PID.h"


/*

	p[n] = Kp * e[n]

	i[n] = KiT/2(e[n] + e[n-1]) + i[n-1]

	d[n] = 2Kd/(2*Tau + T)(e[n] - e[n-1]) + (2*Tau - T) / (2Tau + T) (d[u-1]

	output signal:
	u[n] = p[n] + i[n] + d[n]

 */

void PIDController_Init(PIDController* self)
{
	//we are clearing controller variables...
	self->integrator = 0.0f;
	self->prevError  = 0.0f;

	self->differentiator  = 0.0f;
	self->prevMeasurement = 0.0f;

	self->out = 0.0f;

}




float PIDController_Update(PIDController* self, float setpoint, float measurement)
{
	/*Error Signal*/
	float error = setpoint - measurement;

	/*Proportional*/
	float proportional = self->Kp * error;

	/*Integral*/
	self->integrator = self->integrator + 0.5f * self->Ki * self->T * (error + self->prevError);

	/* Anti-wind-up via integrator clamping */
	if(self->integrator > self->limMaxInt) {

		self->integrator = self->limMaxInt;

	}
	else if(self->integrator < self->limMinInt){

		self->integrator = self->limMinInt;

	}

	/*Band limited Differentiator*/
    self->differentiator = -(2.0f * self->Kd * (measurement - self->prevMeasurement)	/* Note: derivative on measurement, therefore minus sign in front of equation! */
                        + (2.0f * self->tau - self->T) * self->differentiator)
                        / (2.0f * self->tau + self->T);

    /*Compute output and apply limits*/
    self->out = proportional + self->integrator + self->differentiator;

    if(self->out > self->limMax) {

    	self->out = self->limMax;

    }
    else if(self->out < self->limMin) {

    	self->out = self->limMin;

    }

    return self->out;

}




















