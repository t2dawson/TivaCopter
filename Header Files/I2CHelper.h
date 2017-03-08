/*
 * I2CHelper.h
 *
 *  Created on: Mar 6, 2017
 *      Author: tdawson
 */

#ifndef I2CHELPER_H_
#define I2CHELPER_H_

#include <stdint.h>
typedef unsigned char byte;

void i2c0_init();
int16_t i2c_readFrom(uint8_t slave_addr, uint8_t reg_addr, byte* Buffer);
void i2c_writeTo(uint8_t slave_addr, uint8_t num_of_args, ...);

#endif /* I2CHELPER_H_ */
