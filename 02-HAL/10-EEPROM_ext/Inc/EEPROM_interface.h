/*
 * ADC_cfg.h
 *
 *  Created on: Jul 3, 2022
 *      Author: Anthony
 */

#ifndef EEPROM_INTERFACE_H_
#define EEPROM_INTERFACE_H_
#include "TWI_Interface.h"
#include <util/delay.h>
#include "Led_Interface.h"




void E2PROM_Int();
void E2PROM_WriteByte(u8 DeviceAdd,u8 LocAdd,u8 data);
u8 E2PROM_ReadByte(u8 DeviceAdd,u8 LocAdd);


#endif /* EEPROM_INTERFACE_H_ */
