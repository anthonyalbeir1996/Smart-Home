/*
 * Buzzer.c
 *
 *  Created on: Jun 23, 2022
 *      Author: lione
 */

#include "Buzzer_Interface.h"
void Buzzer_Int()
{
DIO_cnfg_channel(DIO_PORTA, DIO_PIN3, DIO_OUTPUT);
DIO_write(DIO_PORTA, DIO_PIN3, DIO_LOW);
}

void Buzzer_ON(buzzer_id_t id)
{
	switch(id)
	{
	case BUZZER0:
		DIO_write(DIO_PORTA, DIO_PIN3, DIO_HIGH);
break;
}
}

void Buzzer_OFF(buzzer_id_t id)
{
	switch(id)
	{
		case BUZZER0:
			DIO_write(DIO_PORTA, DIO_PIN3, DIO_LOW);
break;
}
}



void Buzzer_Toggle(buzzer_id_t id)
{
	switch(id)
	{
			case BUZZER0:
		DIO_flip(DIO_PORTA, DIO_PIN3);
}
}
