/*
 * ADC_cfg.h
 *
 *  Created on: Jul 3, 2022
 *      Author: Anthony
 */
#ifndef EEPROM_INTERFACE_INT_H_
#define EEPROM_INTERFACE_INT_H_

#include "std_Types.h"
#include "Bit_Math.h"
#include <avr/io.h>

#include "EEPROM_Reg_int.h"
void EEPROM_internal_Write(u16 address,u8 data);
u8 EEPROM_internal_Read(u16 address);

#endif /* 02_SOURCE_01_MCAL_10_EEPROM_INT_INC_EEPROM_INTERFACE_INT_H_ */
