/*
 * PID.c
 *
 *  Created on: Mar 6, 2017
 *      Author: tdawson
 */
#include "PID.h"

static float pidValues[3][3];


void calculatePID(float* pidRoll, float* pidPitch, float* pidYaw, float* pidSetPoints, IMUData* gyroValues) {

	// local static variables hold the previous errors and the total I components
	static int pidITotals[3] = {0};
	static int lastRollError = 0, lastPitchError = 0, lastYawError = 0;


	// Roll Calculations
	int rollError = gyroValues->XValue - pidSetPoints[0];
	pidITotal[0] += (pidValues[0][1] * rollError);

	*pidRoll = (pidValues[0][0] * rollError) + pidITotal[0] + (pidValues[0][2] * (rollError - lastRollError));

	//Pitch Calculations
	int pitchError = gyroValues->YValue - pidSetPoints[1];
	pidITotal[1] += (pidValues[1][1] * pitchError);

	*pidPitch = (pidValues[1][0] * rollError) + pidITotal[1] + (pidValues[1][2] * (pitchError - lastPitchError));


	//Yaw Calculations
	int yawError = gyroValues->ZValue - pidSetPoints[2];
	pidITotal[2] += (pidValues[2][1] * yawError);

	*pidRoll = (pidValues[2][0] * yawError) + pidITotal[2] + (pidValues[2][2] * (yawError - lastYawError));
}


void setPIDValues(const float* pValues, const float* iValues, const float* dValues){

	for(int i = 0; i < 3; i++) {

		pidValues[i][0] = pValues[i];
		pidValues[i][1] = iValues[i];
		pidValues[i][2] = dValues[i];
	}
}

