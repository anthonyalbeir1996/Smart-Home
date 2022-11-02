/*
 * TWI_Interface.h
 *
 *  Created on: Aug 9, 2022
 *      Author: Anthony
 */

#ifndef _TWI_INTERFACE_H_
#define _TWI_INTERFACE_H_
#include "TWI_REG.h"
#include "TWI_types.h"

#define F 400000
#define F_cpu 16000000
#define TWPS 1
#define TWBR (((F_cpu/F)-16)/(2*4^TWPS))

void TWI_init(u8 address);
u8 TWI_status(void);
u8 TWI_start(void);
void TWI_stop(void);
u8 TWI_send(u8 data);
u8 TWI_read_Ack(u8 * data);
u8 TWI_read_NACK (u8 *data);





#endif /* MCAL_TWI_INC_TWI_INTERFACE_H_ */
