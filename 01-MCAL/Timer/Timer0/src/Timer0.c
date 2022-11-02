/*
 * Timer0.c
 *
 *  Created on: Sep 12, 2022
 *      Author: lione
 */

#include "Timer0_Interface.h"
#include "Led_Interface.h"
#include<avr/io.h>
u16 no_of_ovf;
u16 tot_overflow=0;
u8 rem;
u8 check_no=0;

static void (*Timer0_INT0)(void)=NULL;

void Timer0_Delay(f32 delay_time_ms,void(*ptr)(void))
{
GINT_ENABLE_INTERRUPT();
	Timer0_INT0=ptr;
	f32 loc_delay_time=delay_time_ms/1000;

	f32 ovf=0.016384;
if(loc_delay_time>ovf)

{
	check_no=1;

	no_of_ovf =loc_delay_time/ovf;


			rem=	fmod((loc_delay_time/ovf)*100,100);


			GINT_ENABLE_INTERRUPT();
			SET_BIT(TIMSK_REG,0); //to enable inturrept


			TCCR0_REG=5;
			//TCNT0=256-rem;
}
else if (loc_delay_time<ovf)

{
	   check_no=2;

		no_of_ovf =loc_delay_time/ovf;


		rem=	fmod((loc_delay_time/ovf)*100,100);


		GINT_ENABLE_INTERRUPT();
		SET_BIT(TIMSK_REG,0); //to enable inturrept


		TCCR0_REG=5;
		TCNT0=rem;
}
else {

	//do nothing
}

}

void Delay(u16 delay_number){


		f32 loc_delay_time=delay_number/1000;

		f32 ovf=0.016384;

		no_of_ovf =loc_delay_time/ovf;
		rem=	fmod((loc_delay_time/ovf)*100,100);

	TCCR0_REG = 5; /* Timer0, normal mode, /1024 prescalar */
		TCNT0_REG = rem;
		while(tot_overflow<no_of_ovf)
		{/* Load TCNT0, count for 10ms */
		while((TIFR_REG&0x01)==0);  /* Wait for TOV0 to roll over */
		TCNT0 = rem;
tot_overflow++;
		TIFR_REG = 0x1;
}
		TCCR0_REG = 0;
		tot_overflow=0;
}


/*
void Timer0_INT_Callout(void(*ptr)(void))
{
	Timer0_INT0=ptr;
}
*/



void Timer0_FPWM_Int(){
	// choose the mode of fpwm in timer0

	SET_BIT(TCCR0_REG,6);
	SET_BIT(TCCR0_REG,3);
	  // to choose mode of non inverting in fpwm
	 CLEAR_BIT(TCCR0_REG,4);
	 SET_BIT(TCCR0_REG,5);

	GINT_ENABLE_INTERRUPT();

	SET_BIT(TIMSK_REG,0);
	// make pin 3 in portB as output to make pwm out from this pin
	SET_BIT(DDRB,3);
}


void Timer0_FPWM_Start(){
	// to start the timer prescaler 256
	TCCR0_REG|= 4;
}



void Timer0_Set_Duty(u8 duty_cycle){
	OCR0_REG=((duty_cycle*256)/100)-1;
}

void Timer0_FPWM_Stop(){
	// to stop the timer

	CLEAR_BIT(TCCR0_REG,0);
	CLEAR_BIT(TCCR0_REG,1);
	CLEAR_BIT(TCCR0_REG,2);
}


ISR(TIMER0_OVF_vect)
{
if(Timer0_INT0!=NULL)
{

if(check_no==1)
{

	if(tot_overflow==no_of_ovf){


		Timer0_INT0();
			  tot_overflow=0;


			//  TCNT0=256-rem;

			 // Timer0_INT0=NULL;
	}
	tot_overflow++;
}

else if(check_no==2)

{
	if(tot_overflow==(u8)no_of_ovf){


			Timer0_INT0();
				  tot_overflow=0;


				  TCNT0=256-rem;

				  Timer0_INT0=NULL;
		}
}
}
else
{
//do nothing
}
}

void Timer0_Dimer(void)
{
	// phase correct mode
	SET_BIT(TCCR0_REG,6);
	//SIT_BIT(TCCR0_REG,3);

	// no prescaller
	SET_BIT(TCCR0_REG,5);
	SET_BIT(TCCR0_REG,0);

	// make pin 3 in port B be output
	DIO_cnfg_channel(DIO_PORTB, PORT3, DIO_OUTPUT);
}

void Timer0_Dimmer_Light(u8 duty)
{
OCR0_REG=duty;
}
