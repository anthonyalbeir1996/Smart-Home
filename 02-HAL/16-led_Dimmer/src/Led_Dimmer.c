/*
 * Led_Dimmer.c
 *
 *  Created on: Oct 30, 2022
 *      Author: Anthony
 */
#include "Led_Dimmer_interface.h"

void Led_Dimmer_init()
{
   DIO_DDRB_REG=(DIO_DDRB_REG|(1<<DIO_PORTB,5))&&(DIO_DDRB_REG &~(1<<DIO_PORTB,7));
   _delay_ms(1);
   DIO_cnfg_channel(DIO_PORTB, DIO_PIN5, DIO_OUTPUT);
   _delay_ms(1);
   DIO_cnfg_channel(DIO_PORTB, DIO_PIN7, DIO_OUTPUT);

}
void delay_on(int t)
{
  int i;
  for(i=0;i<t;i++)
  {
	  _delay_ms(1);
  }
}
void init_timer(void)
{
   //set mode to ctc mode//
	CLEAR_BIT(TCCR1A_REG,0);
	CLEAR_BIT(TCCR1A_REG,1);
	SET_BIT(TCCR1A_REG,3);
	CLEAR_BIT(TCCR1B_REG,4);

	OCR1A_REG=0xF9;
	//set pre-scaler to 1024//
	SET_BIT(TCCR1B_REG,0);
	CLEAR_BIT(TCCR1B_REG,1);
	SET_BIT(TCCR1B_REG,2);



}
