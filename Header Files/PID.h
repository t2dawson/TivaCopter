/*
 * PID.h
 *
 *  Created on: Mar 6, 2017
 *      Author: tdawson
 */

#ifndef PID_H_
#define PID_H_

void calculatePID(float* pidRoll, float* pidPitch, float* pidYaw, IMUData* gyroValues);
void setPIDValues(float* pValues, float* iValues, float* dValues);

#endif /* PID_H_ */
