/*
 * Servo_Motor.c
 *
 * Created: 9/29/2022 1:55:07 AM
 *  Author: Unlimited
 */ 
#include "Servo_Motor_Inteface.h"

void Servo_Motor_Int()
{
	// to make pin5 in DDRD as output
	DIO_cnfg_channel(DIO_PORTD,5,DIO_OUTPUT);
    // SIT_BIT(DIO_DDRD_REG,5);
	Timer1_FPWM_Int();
	Timer1_FPWM_Start();
}


void Servo_Motor_Rotat(u8 duty_cycle)
{
	Timer1_FPWM_SetTime(duty_cycle);
}
