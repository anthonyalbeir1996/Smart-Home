/*
 * EEPROM.c
 *
 *  Created on: Oct 5, 2022
 *      Author: lione
 */


#include "EEPROM_interface.h"

void E2PROM_Int()
{
	TWI_init(0b00000010);
}

void E2PROM_WriteByte(u8 DeviceAdd,u8 LocAdd,u8 data){
	u8 wDeviceAdd = (DeviceAdd & 0xFE);//clear the first bit
	if (TWI_start()== 0x08){
		if (TWI_send(wDeviceAdd) == 0x18){
			if (TWI_send(LocAdd) == 0x28){
				if (TWI_send(data) == 0x28){
					TWI_stop();
					_delay_ms(10);
					Led_ON(LED0);
				}
			}
		}
	}
}
u8 E2PROM_ReadByte(u8 DeviceAdd,u8 LocAdd){
	u8 wDeviceAdd = (DeviceAdd & 0xFE);//clear the first bit
	u8 rDeviceAdd = (DeviceAdd | (1<<0));//set the first bit
	u8 ReadValue = 0;
	if (TWI_start() == 0x08){
		if (TWI_send(wDeviceAdd) == 0x18){
			if (TWI_send(LocAdd) == 0x28){
				if (TWI_start() == 0x10){
					if (TWI_send(rDeviceAdd) == 0x40){
						TWI_read_NACK(&ReadValue);
						TWI_stop();
						Led_ON(LED2);
					}
				}
			}
		}
	}
	return ReadValue;
}

