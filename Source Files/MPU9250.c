/*
 * MPU9250.C
 *
 *  Created on: Mar 6, 2017
 *      Author: tdawson
 */
#include "MPU9250.h"

#define BUFFER_SIZE 6 // number of bytes to capture for each sensor

// Initialize the MPU registers
void MPUInit(uint8_t slave_addr, uint8_t* reg_addrs, uint8_t* initialValues) {

	uint8_t i;
	for(i = 0; i < sizeof(initialValues)-1; i++) {

			i2c_writeTo(slave_addr, 2, reg_addrs[i], initialValues[i]);
	}
}

//reading Accelerometer data from MPU
void readAccelData(IMUData* accelerometer, uint8_t slave_addr, uint8_t reg_start_addr) {

	byte Buffer[BUFFER_SIZE];
	i2c_readFrom(slave_addr, reg_start_addr, Buffer);
	accelerometer->XValue = ((int16_t)Buffer[0] << 8) + ((int16_t) Buffer[1]); // First two byte are the X values
	accelerometer->YValue = ((int16_t)Buffer[2] << 8) + ((int16_t) Buffer[3]); // Next two byte are the Y values
	accelerometer->ZValue = ((int16_t)Buffer[4] << 8) + ((int16_t) Buffer[5]); // Last two byte are the Z values

}

//reading gyro data from MPU
void readGyroData(IMUData* gyro, uint8_t slave_addr, uint8_t reg_start_addr) {

	byte Buffer[BUFFER_SIZE];
	i2c_readFrom(slave_addr, reg_start_addr, Buffer);
	gyro->XValue = ((int16_t)Buffer[0] << 8) + ((int16_t) Buffer[1]); // First two byte are the X values
	gyro->YValue = ((int16_t)Buffer[2] << 8) + ((int16_t) Buffer[3]); // Next two byte are the Y values
	gyro->ZValue = ((int16_t)Buffer[4] << 8) + ((int16_t) Buffer[5]); // Last two byte are the Z values

}

// wrapper function for writing values to MPU registers
void writeMPUDATA(uint8_t slave_addr, uint8_t reg_addr, byte value) {

	i2c_writeTo(slave_addr, 2, reg_addr, value);
}
