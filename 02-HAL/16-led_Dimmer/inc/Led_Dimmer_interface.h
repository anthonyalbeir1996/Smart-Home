/*
 * Led_Dimmer_interface.h
 *
 *  Created on: Oct 30, 2022
 *      Author: Anthony
 */

#ifndef LED_DIMMER_INTERFACE_H_
#define LED_DIMMER_INTERFACE_H_

#include "Timer1_Interface.h"
#include "DIO_INTERFACE.h"
#include <util/delay.h>



void Led_Dimmer_init();
void delay_on(int t);
void init_timer(void);






#endif /* 02_HAL_16_LED_DIMMER_INC_LED_DIMMER_INTERFACE_H_ */
