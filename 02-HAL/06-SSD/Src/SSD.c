/*
 * SSD.c
 *
 *  Created on: Jun 24, 2022
 *      Author: lione
 */
#include "SSD_Interface.h"

void SSD_Int()
{
	/*	Configure SSD Enable Lines as Output	*/
			DIO_cnfg_channel(DIO_PORTB, DIO_PIN1, DIO_OUTPUT);
			DIO_cnfg_channel(DIO_PORTB, DIO_PIN2, DIO_OUTPUT);
			/*Configure SSD DIP Line*/
			DIO_cnfg_channel(DIO_PORTB, DIO_PIN3, DIO_OUTPUT);

			/*	Configure SSD Data Lines as Output		*/
			DIO_cnfg_channel(DIO_PORTA, DIO_PIN4, DIO_OUTPUT);
			DIO_cnfg_channel(DIO_PORTA, DIO_PIN5, DIO_OUTPUT);
			DIO_cnfg_channel(DIO_PORTA, DIO_PIN6, DIO_OUTPUT);
			DIO_cnfg_channel(DIO_PORTA, DIO_PIN7, DIO_OUTPUT);


			/*Make SSD off*/

			DIO_write(DIO_PORTB, DIO_PIN1, DIO_LOW);
			DIO_write(DIO_PORTB, DIO_PIN2, DIO_LOW);
}
void SSD_Display(u8 number)
{
	u8 Loc_SSD_Firist_Digit=(number%10)<<4;
	u8 Loc_SSD_Second_Digit=(number/10)<<4;
if(number<=99)
{
	/*Make Digit one on*/
	DIO_write(DIO_PORTB, DIO_PIN1, DIO_HIGH);
	/*Make Digit two off*/
	DIO_write(DIO_PORTB, DIO_PIN2, DIO_LOW);
	/*Send Number of First Digit*/
	DIO_write_Group(DIO_PORTA, 0xF0,Loc_SSD_Firist_Digit );
	_delay_ms(1);

	/*Make Digit one off*/
	DIO_write(DIO_PORTB, DIO_PIN1, DIO_LOW);
		/*Make Digit two on*/
	DIO_write(DIO_PORTB, DIO_PIN2, DIO_HIGH);
		/*Send Number of Second Digit*/
	DIO_write_Group(DIO_PORTA, 0xF0,Loc_SSD_Second_Digit );
	_delay_ms(1);
}
else
{
/*Do Nothing*/
}
}
void SSD_Display_With_Delay(u8 number,u32 delay)
{
	u32 counter=0;
	for(counter=0;counter<delay;counter+=3)
	{
		SSD_Display(number);
		_delay_ms(1);

	}
}
