/*
 * Timer2.c
 *
 *  Created on: Sep 21, 2022
 *      Author: lione
 */
#include "Timer2_Interface.h"


u16 no_of_ovf2;
u16 tot_overflow2=0;
u8 rem2;
u8 check_no2=0;


void Delay2(u16 delay_number){


		f32 loc_delay_time=delay_number/1000;

		f32 ovf=0.016384;

		no_of_ovf2 =loc_delay_time/ovf;
		rem2=	fmod((loc_delay_time/ovf)*100,100);

	TCCR2 = 4; /* Timer0, normal mode, /1024 prescalar */
		TCNT2 = rem2;
		while(tot_overflow2<no_of_ovf2)
		{/* Load TCNT0, count for 10ms */
		while((TIFR&0x01)==0);  /* Wait for TOV0 to roll over */
		TCNT2 = rem2;
tot_overflow2++;
		TIFR = 0x1;
}
		TCCR2 = 0;
		tot_overflow2=0;
}



void Timer2_FPWM_Int()
{


	// to choose mode FPWM using ICR1 in timer1
	SET_BIT(TCCR2_REG,3);
	SET_BIT(TCCR2_REG,4);



//to choose non inv mode

	SET_BIT(TCCR2_REG,5);

GINT_ENABLE_INTERRUPT();
SET_BIT(TIMSK_REG,6);

SET_BIT(DDRD,7);

}


void Timer2_FPWM_Start()
{
	// choosing prescaller 256 to make 50Hz
	//SIT_BIT(TCCR2_REG,0);
	SET_BIT(TCCR2_REG,1);
	SET_BIT(TCCR2_REG,2);

}

void Timer2_Set_Duty(u8 duty_cycle)
{
	OCR2_REG=((duty_cycle*256)/100)-1;
}
void Timer2_FPWM_Stop(){
	// to stop the timer

	CLEAR_BIT(TCCR2_REG,0);
	CLEAR_BIT(TCCR2_REG,1);
	CLEAR_BIT(TCCR2_REG,2);
}
