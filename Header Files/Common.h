/*
 * CommonConstants.h
 *
 *  Created on: Mar 7, 2017
 *      Author: tdawson
 */

#ifndef HEADER_FILES_COMMON_H_
#define HEADER_FILES_COMMON_H_

//1- address of the MPU 9250
#define IMU_SLAVE_ADDRESS 0x68

//2- register addresses for setting up MPU
#define IMU_PWR_MANAGEMENT 0x6B
#define IMU_SMPLRT_DIV 0x19
#define IMU_CONFIG 0x1A
#define IMU_GYRO_CONFIG 0x1B
#define IMU_ACCEL_CONFIG 0x1C
#define IMU_FIFO_EN 0x23
#define IMU_USR_CTL 0x6A

//3- register address to read values from MPU
#define ACCEL_XOUT_H 0x3B
#define ACCEL_XOUT_L 0x3C
#define ACCEL_YOUT_H 0x3D
#define ACCEL_YOUT_L 0x3E
#define ACCEL_ZOUT_H 0x3F
#define ACCEL_ZOUT_L 0x40
#define GYRO_XOUT_H 0x43
#define GYRO_XOUT_L 0x44
#define GYRO_YOUT_H 0x45
#define GYRO_YOUT_L 0x46
#define GYRO_ZOUT_H 0x47
#define GYRO_ZOUT_L 0x48

//4- MPU Offset register address
#define GYRO_X_OFFSET_H 0x13
#define GYRO_X_OFFSET_L 0x14
#define GYRO_Y_OFFSET_H 0x15
#define GYRO_Y_OFFSET_L 0x16
#define GYRO_Z_OFFSET_H 0x17
#define GYRO_Z_OFFSET_L 0x18
#define ACCEL_X_OFFSET_H 0x77
#define ACCEL_X_OFFSET_L 0x78
#define ACCEL_Y_OFFSET_H 0x7A
#define ACCEL_Y_OFFSET_L 0x7B
#define ACCEL_Z_OFFSET_H 0x7D
#define ACCEL_Z_OFFSET_L 0x7E


#define RESET_IMU 0x80
#define ENABLE_GYRO_DLPF 0x01
#define GYRO_FS_SELECT 0x18
#define ACCEL_FS_SELECT 0x10
#define SET_FIFO_FOR_IMU 0x78
#define ENABLE_FIFO 0x41
#define SMPLRT_DIV_VAL 0x03

// number of bytes to capture for each sensor
#define BUFFER_SIZE 6


// the size of array is based on the number of addresses written to in initialization, i.e, section 2 in this file
const uint8_t registerAddresses[7] = {IMU_PWR_MANAGEMENT,IMU_CONFIG, IMU_GYRO_CONFIG, IMU_ACCEL_CONFIG, IMU_FIFO_EN, IMU_USR_CTL, IMU_SMPLRT_DIV};
const uint8_t MPUInitValues[7] = {RESET_IMU, ENABLE_GYRO_DLPF, GYRO_FS_SELECT, ACCEL_FS_SELECT, SET_FIFO_FOR_IMU,ENABLE_FIFO, SMPLRT_DIV_VAL};


#endif /* HEADER_FILES_COMMON_H_ */
