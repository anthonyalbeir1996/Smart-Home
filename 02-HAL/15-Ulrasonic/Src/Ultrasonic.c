/*
 * Ultrasonic.c
 *
 *  Created on: Sep 30, 2022
 *      Author: lione
 */

#include "Ultrasonic_Interface.h"
#include "DIO_INTERFACE.h"

volatile u16 TOV_Counter;

double Ultrasonic_Read(void)
{
	double distance = 0;
		unsigned long Count = 0;

GINT_ENABLE_INTERRUPT();
// choose normal mode in timer1
CLEAR_BIT(TCCR1A_REG,0);
CLEAR_BIT(TCCR1A_REG,1);
CLEAR_BIT(TCCR1B_REG,3);
CLEAR_BIT(TCCR1B_REG,4);

// enable ISES1 to make it see the rising edge
SET_BIT(TCCR1B_REG,6);
// to enable prescaller 8
SET_BIT(TCCR1B_REG,1);
//to enable over flow timer to take counter
SET_BIT(TIMSK_REG,2);
// make pulse on pin A0 to enable ultrasonic
DIO_cnfg_channel(DIO_PORTA, 0, DIO_OUTPUT);
DIO_cnfg_channel(DIO_PORTA, 0, DIO_HIGH);
_delay_us(10);
DIO_write(DIO_PORTA, 0, DIO_LOW);
// wait until rising edge come
while(CHECK_BIT(TIFR_REG,5)==0);
TCNT1_REG = 0;
TOV_Counter = 0;
// clear flag of over flow
//SIT_BIT(TIFR_REG,2);
// clear ICF1 flag
SET_BIT(TIFR_REG,5);
// change from rising edge to falling edge
CLEAR_BIT(TCCR1B_REG,6);

// wait until falling edge come
while(CHECK_BIT(TIFR_REG,5)==0);
// clear ICF1 flag
//SIT_BIT(TIFR_REG,5);


Count=ICR1_REG+(65535*TOV_Counter);

//distance=DISTANCE_EXEPT_COUNTER*Count;
distance=(double)0.008575*Count;
return distance;
}




ISR(TIMER1_OVF_vect){
	TOV_Counter++;
}


