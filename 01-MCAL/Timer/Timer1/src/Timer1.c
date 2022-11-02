/*
 * Timer1.c
 *
 *  Created on: Oct 20, 2022
 *      Author: Anthony
 */


#include "Timer1_Interface.h"



void Timer1_Int(void)
{
	// choose ctc mode 4 in timer1
	CLEAR_BIT(TCCR1A_REG,0);
	CLEAR_BIT(TCCR1A_REG,1);
	SET_BIT(TCCR1B_REG,3);
	CLEAR_BIT(TCCR1B_REG,4);
	// to open global interrupt
	GINT_ENABLE_INTERRUPT();
	// enable OCRA interrupt
	SET_BIT(TIMSK_REG,4);
}

void Timer1_SetTime(u32 time_delay)
{

		u32 ticktime=1024/16; //result in micro
		u32 totaltiks =(time_delay *1000)/ticktime;
		OCR1A_REG=totaltiks-1;


}

void Timer1_Start(void)
{
	// choose prescaler  1024 for timer1
	SET_BIT(TCCR1B_REG,0);
	CLEAR_BIT(TCCR1B_REG,1);
	SET_BIT(TCCR1B_REG,2);

}

void Timer1_Stop(void)
{
	// to stop timer1
	CLEAR_BIT(TCCR1B_REG,0);
	CLEAR_BIT(TCCR1B_REG,1);
	CLEAR_BIT(TCCR1B_REG,2);
}




void Timer1_FPWM_Int()
{


	// to choose mode FPWM using ICR1 in timer1
CLEAR_BIT(TCCR1A_REG,0);
SET_BIT(TCCR1A_REG,1);
SET_BIT(TCCR1B_REG,3);
SET_BIT(TCCR1B_REG,4);


//to choose non inv mode

SET_BIT(TCCR1A_REG,7);

// put the value in ICR1 to make 50Hz
ICR1_REG=1250;

}



void Timer1_FPWM_SetTime(u8 duty_cycle)
{
OCR1A_REG=((duty_cycle*1250)/100)-1;
}



void Timer1_FPWM_Start()
{
	// choosing prescaller 256 to make 50Hz
	CLEAR_BIT(TCCR1B_REG,0);
	CLEAR_BIT(TCCR1B_REG,1);
    SET_BIT(TCCR1B_REG,2);
}



void Timer1_FPWM_Stop()
{
	CLEAR_BIT(TCCR1B_REG,0);
	CLEAR_BIT(TCCR1B_REG,1);
	CLEAR_BIT(TCCR1B_REG,2);
}




