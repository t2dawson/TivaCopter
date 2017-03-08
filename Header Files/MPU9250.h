/*
 * MPU9250.h
 *
 *  Created on: Mar 6, 2017
 *      Author: tdawson
 */

#ifndef MPU9250_H_
#define MPU9250_H_

#include "I2CHelper.h"

typedef struct _IMUData {

	int16_t XValue;
	int16_t YValue;
	int16_t ZValue;

}IMUData;

void accelerometerInit(uint8_t slave_addr, uint8_t* reg_addrs, uint8_t* initialValues);
void gyroInit(uint8_t slave_addr, uint8_t* reg_addrs, uint8_t* initialValues);
void readAccelData(IMUData* accelerometer, uint8_t slave_addr, uint8_t reg_start_addr);
void readGyroData(IMUData* gyro, uint8_t slave_addr, uint8_t reg_start_addr);





#endif /* MPU9250_H_ */
