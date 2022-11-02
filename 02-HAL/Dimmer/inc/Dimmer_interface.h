/*
 * Dimmer_interface.h
 *
 *  Created on: Nov 1, 2022
 *      Author: Anthony
 */

#ifndef HAL_DIMMER_INC_DIMMER_INTERFACE_H_
#define HAL_DIMMER_INC_DIMMER_INTERFACE_H_
#include "Timer0_Interface.h"
#include "DIO_INTERFACE.h"

void Dimmer_Int();
void Dimmer_duty(u8 duty);
void Dimmer_OFF();

#endif /* 02_SOURCE_02_HAL_DIMMER_INC_DIMMER_INTERFACE_H_ */
