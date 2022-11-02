/*
 * ADC_cfg.h
 *
 *  Created on: Jul 3, 2022
 *      Author: Anthony
 */
#ifndef TIMER0_INTERFACE_H_
#define TIMER0_INTERFACE_H_
#include <math.h>
#include <avr/interrupt.h>
#include "std_Types.h"
#include "Bit_Math.h"
#include <stddef.h>
#include "Timer_Reg.h"
#include "GINT_interface.h"
void Timer0_Delay(f32 delay_time_ms,void(*ptr)(void));
void Timer0_INT_Callout(void(*ptr)(void));
void Delay(u16 delay_number);


void Timer0_FPWM_Start();
void Timer0_FPWM_Int();
void Timer0_FPWM_Stop();
void Timer0_Set_Duty(u8 duty_cycle);

// for Dimmer

void Timer0_Dimmer_Light(u8 duty);
void Timer0_Dimer(void);
#endif /* TIMER0_INTERFACE_H_ */
