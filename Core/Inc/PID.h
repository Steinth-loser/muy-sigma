/*
 * PID.h
 *
 *  Created on: Mar 8, 2026
 *      Author: th3ka
 */

#ifndef INC_PID_H_
#define INC_PID_H_

#define CLAMP(x, min, max) ((x) < (min) ? (min): ((x) > (max) ? (max) : (x)))

typedef struct {
	//Controller Gains
	float Kp;
	float Ki;
	float Kd;

	//Time constant
	float tau;

	//Output limits
	float limMax;
	float limMin;

	//Integrator Limits
	float limMaxInt;
	float limMinInt;

	//Sample time (in seconds)
	float T;

	//Controller's memory
	float integrator;
	float prevError; // fon integration
	float differentiator;
	float prevMeasurement; // for differentiation

	//Controller's output signal y[s]

	float out;

}PIDController;

void PIDController_Init(PIDController* self);

float PIDController_Update(PIDController* self, float setpoint, float measurement);

void set_motor_pwm(float pid_signal);

#endif /* INC_PID_H_ */
