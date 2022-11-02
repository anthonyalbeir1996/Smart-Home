/*
 * ADC_cfg.h
 *
 *  Created on: Jul 3, 2022
 *      Author: Anthony
 */
#ifndef TIMER2_INTERFACE_H_
#define TIMER2_INTERFACE_H_

#include <math.h>
#include <avr/interrupt.h>
#include "std_Types.h"
#include "Bit_Math.h"
#include <stddef.h>
#include "Timer_Reg.h"
#include "GINT_interface.h"
void Delay2(u16 delay_number);


void Timer2_FPWM_Int();
void Timer2_FPWM_Start();
void Timer2_Set_Duty(u8 duty_cycle);
void Timer2_FPWM_Stop();
#endif /* TIMER2_INTERFACE_H_ */
