/*
 * EEPROM_int.c
 *
 *  Created on: Oct 8, 2022
 *      Author: lione
 */
#include "EEPROM_Interface_int.h"

void EEPROM_internal_Write(u16 address,u8 data)
{
while(CHECK_BIT(EECR_REG,1));
EEARL_REG=address;
EEARH_REG=(address>>8);
EEDR_REG=data;
SET_BIT(EECR_REG,2);
SET_BIT(EECR_REG,1);
}

u8 EEPROM_internal_Read(u16 address)
{
	while(CHECK_BIT(EECR_REG,1));
	EEARL_REG=address;
	EEARH_REG=(address>>8);
	SET_BIT(EECR_REG,0);

	return EEDR_REG;
}
