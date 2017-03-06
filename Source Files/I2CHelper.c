/*
 * I2CHelper.c
 *
 *  Created on: Mar 6, 2017
 *      Author: tdawson
 */

#include "I2CHelper.h"
#include <stdint.h>

// initialize I2C0 module
void i2c0_init(void) {
	
����//enable I2C module 0
����SysCtlPeripheralEnable(SYSCTL_PERIPH_I2C0);
�
����//reset module
����SysCtlPeripheralReset(SYSCTL_PERIPH_I2C0);
�����
����//enable GPIO peripheral that contains I2C 0
����SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
�
����// Configure the pin muxing for I2C0 functions on port B2 and B3.
����GPIOPinConfigure(GPIO_PB2_I2C0SCL);
����GPIOPinConfigure(GPIO_PB3_I2C0SDA);
�����
����// Select the I2C function for these pins.
����GPIOPinTypeI2CSCL(GPIO_PORTB_BASE, GPIO_PIN_2);
����GPIOPinTypeI2C(GPIO_PORTB_BASE, GPIO_PIN_3);
�
����// Enable and initialize the I2C0 master module.� Use the system clock for
����// the I2C0 module.� The last parameter sets the I2C data transfer rate.
����// If false the data rate is set to 100kbps and if true the data rate will
����// be set to 400kbps.
����I2CMasterInitExpClk(I2C0_BASE, SysCtlClockGet(), false);
�����
����//clear I2C FIFOs
����HWREG(I2C0_BASE + I2C_O_FIFOCTL) = 80008000;
}

// Reads Register value from specified address and register
int16_t i2c_readFrom(uint8_t slave_addr, uint8_t reg_addr) {
	
����//specify that we are writing (a register address) to the
����//slave device
����I2CMasterSlaveAddrSet(I2C0_BASE, slave_addr, false);
�
����//specify register to be read
����I2CMasterDataPut(I2C0_BASE, reg_addr);
�
����//send control byte and register address byte to slave device
����I2CMasterControl(I2C0_BASE, I2C_MASTER_CMD_BURST_SEND_START);
�����
����//wait for MCU to finish transaction
����while(I2CMasterBusy(I2C0_BASE));
�����
����//specify that we are going to read from slave device
����I2CMasterSlaveAddrSet(I2C0_BASE, slave_addr, true);
�����
����//send control byte and read from the register we
����//specified
����I2CMasterControl(I2C0_BASE, I2C_MASTER_CMD_SINGLE_RECEIVE);
�����
����//wait for MCU to finish transaction
����while(I2CMasterBusy(I2C0_BASE));
�����
����//return data pulled from the specified register
����return I2CMasterDataGet(I2C0_BASE);
}
	
//sends an I2C command to the specified slave
void i2c_writeTo(uint8_t slave_addr, uint8_t num_of_args, ...)
{
����// Tell the master module what address it will place on the bus when
����// communicating with the slave.
����I2CMasterSlaveAddrSet(I2C0_BASE, slave_addr, false);
�����
����//stores list of variable number of arguments
����va_list vargs;
�����
����//specifies the va_list to "open" and the last fixed argument
����//so vargs knows where to start looking
����va_start(vargs, num_of_args);
�����
����//put data to be sent into FIFO
����I2CMasterDataPut(I2C0_BASE, va_arg(vargs, uint32_t));
�����
����//if there is only one argument, we only need to use the
����//single send I2C function
����if(num_of_args == 1)
����{
��������//Initiate send of data from the MCU
��������I2CMasterControl(I2C0_BASE, I2C_MASTER_CMD_SINGLE_SEND);
���������
��������// Wait until MCU is done transferring.
��������while(I2CMasterBusy(I2C0_BASE));
���������
��������//"close" variable argument list
��������va_end(vargs);
����}
�����
����//otherwise, we start transmission of multiple bytes on the
����//I2C bus
����else
����{
��������//Initiate send of data from the MCU
��������I2CMasterControl(I2C0_BASE, I2C_MASTER_CMD_BURST_SEND_START);
���������
��������// Wait until MCU is done transferring.
��������while(I2CMasterBusy(I2C0_BASE));
���������
��������//send num_of_args-2 pieces of data, using the
��������//BURST_SEND_CONT command of the I2C module
��������for(uint8_t i = 1; i < (num_of_args - 1); i++)
��������{
������������//put next piece of data into I2C FIFO
������������I2CMasterDataPut(I2C0_BASE, va_arg(vargs, uint32_t));
������������//send next data that was just placed into FIFO
������������I2CMasterControl(I2C0_BASE, I2C_MASTER_CMD_BURST_SEND_CONT);
�����
������������// Wait until MCU is done transferring.
������������while(I2CMasterBusy(I2C0_BASE));
��������}
�����
��������//put last piece of data into I2C FIFO
��������I2CMasterDataPut(I2C0_BASE, va_arg(vargs, uint32_t));
��������//send next data that was just placed into FIFO
��������I2CMasterControl(I2C0_BASE, I2C_MASTER_CMD_BURST_SEND_FINISH);
��������// Wait until MCU is done transferring.
��������while(I2CMasterBusy(I2C0_BASE));
���������
��������//"close" variable args list
��������va_end(vargs);
����}
}
