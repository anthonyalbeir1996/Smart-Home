/*
 * Dimmer.c
 *
 *  Created on: Nov 1, 2022
 *      Author: Anthony
 */


#include "Dimmer_Interface.h"

void Dimmer_Int()
{
Timer0_Dimer();
}

void Dimmer_duty(u8 duty)
{
Timer0_Dimmer_Light(duty);
}

void Dimmer_OFF()
{
Timer0_FPWM_Stop();
DIO_cnfg_channel(DIO_PORTB, DIO_PIN3, DIO_INPUT);
}
