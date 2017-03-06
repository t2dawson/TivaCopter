/*
 * I2CHelper.h
 *
 *  Created on: Mar 6, 2017
 *      Author: tdawson
 */

#ifndef I2CHELPER_H_
#define I2CHELPER_H_

typedef unsigned char byte;

void i2c0_init();
int16_t i2c_readFrom(uint32_t slave_addr, uint8_t reg_addr);
void i2c_writeTo(int device, int address, byte value);


#endif /* I2CHELPER_H_ */
