/*
 * Timer1_Interface.h
 *
 *  Created on: Oct 20, 2022
 *      Author: Anthony
 */

#ifndef TIMER1_INTERFACE_H_
#define TIMER1_INTERFACE_H_

#include "Bit_Math.h"
#include "Timer_Reg.h"
#include "GINT_interface.h"
#include "Timer_reg.h"

void Timer1_Int(void);
void Timer1_SetTime(u32 time_delay);
void Timer1_Start(void);
void Timer1_Stop(void);



void Timer1_FPWM_Stop();
void Timer1_FPWM_Start();
void Timer1_FPWM_SetTime(u8 duty_cycle);
void Timer1_FPWM_Int();


#endif /* 01_MCAL_TIMER_TIMER1_TIMER1_INTERFACE_H_ */
