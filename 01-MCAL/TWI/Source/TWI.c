/*
 * TWI.c
 *
 *  Created on: Aug 9, 2022
 *      Author: Anthony
 */

#include "TWI_Interface.h"

void TWI_init(u8 address)
{
	TWI->TWI_TWAR=address;
	TWI->TWI_TWBR=TWBR;
	TWI->TWI_TWCR.Bits;
}



u8 TWI_status(void)
{
 return (TWI->TWI_TWSR & 0xF8);
}



u8 TWI_start(void)
{
   TWI->TWI_TWCR.Bits.TWSTA=1;
   TWI->TWI_TWCR.Bits.TWINT=1;
   while(TWI->TWI_TWCR.Bits.TWINT==0);
   return TWI_status();
}



void TWI_stop(void)
{
   TWI->TWI_TWCR.Bits.TWSTO=1;
   TWI->TWI_TWCR.Bits.TWINT=1;
   }




u8 TWI_send(u8 data)
{
   TWI->TWI_TWDR=data;
   TWI->TWI_TWCR.Bits.TWINT=1;
   while(TWI->TWI_TWCR.Bits.TWINT==0);
   return TWI_status();
}


u8 TWI_read_Ack(u8 * data)
{
	TWI->TWI_TWCR.Bits.TWEA=1;
	TWI->TWI_TWCR.Bits.TWINT=1;
	while(TWI->TWI_TWCR.Bits.TWINT==0);
	* data=TWI->TWI_TWDR;
	return TWI_status();

}



u8 TWI_read_NACK (u8 *data)
{
	TWI->TWI_TWCR.Bits.TWINT=1;
	while(TWI->TWI_TWCR.Bits.TWINT==0);
	*data=TWI->TWI_TWDR;
	return TWI_status();
}
