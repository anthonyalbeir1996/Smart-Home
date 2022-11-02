/*
 * Button.c
 *
 *  Created on: Jun 24, 2022
 *      Author: lione
 */

#include "Button_Interface.h"
void Button_Int(void)
{
DIO_cnfg_channel(DIO_PORTB, DIO_PIN0, DIO_INPUT);
DIO_cnfg_channel(DIO_PORTD, DIO_PIN2, DIO_INPUT);
DIO_cnfg_channel(DIO_PORTD, DIO_PIN6, DIO_INPUT);

}

dio_level_t Button_Read(button_id_t id)
{
	dio_level_t loc_result=DIO_LOW;
	switch (id)
{
	case BUTTON0:
		loc_result=DIO_read(DIO_PORTB, DIO_PIN0);
		break;
	case BUTTON1:
		loc_result=DIO_read(DIO_PORTD, DIO_PIN6);
			break;
	case BUTTON2:
		loc_result=DIO_read(DIO_PORTD, DIO_PIN2);
			break;

}
	return loc_result;
}
