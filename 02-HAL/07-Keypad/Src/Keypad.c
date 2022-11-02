/*
 * Keypad.c
 *
 *  Created on: Jun 24, 2022
 *      Author: lione
 */

#include "Keypad_Interface.h"
u8 Keypad_Layout[4][4]={
						{'1','2','3','A'},
						{'4','5','6','B'},
						{'7','8','9','C'},
						{'S','0','P','D'}
};


static boolean Keypad_Is_Pressed(void)
{
	if (
		DIO_read(DIO_PORTC,DIO_PIN1) == DIO_LOW ||
		DIO_read(DIO_PORTC,DIO_PIN0) == DIO_LOW ||
		DIO_read(DIO_PORTC,DIO_PIN5) == DIO_LOW ||
		DIO_read(DIO_PORTA,DIO_PIN0) == DIO_LOW
	)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

static s8 Keypad_Get_Row(void)
{
	s8 loc_Row = -1;

	if (DIO_read(DIO_PORTC,DIO_PIN1) == DIO_LOW)
	{
		loc_Row = 0;
	}
	else if (DIO_read(DIO_PORTC,DIO_PIN0) == DIO_LOW)
	{
		loc_Row = 1;
	}
	else if (DIO_read(DIO_PORTC,DIO_PIN5) == DIO_LOW)
		{
			loc_Row = 2;
		}
	else if (DIO_read(DIO_PORTA,DIO_PIN0) == DIO_LOW)
		{
			loc_Row = 3;
		}
	else
	{
		/*	Do Nothing	*/
	}
return loc_Row;
}

static s8 Keypad_Get_Column(s8 current_row)
{
	s8 Loc_Column = -1;
	DIO_write(DIO_PORTB, DIO_PIN4,DIO_LOW);
	DIO_write(DIO_PORTB, DIO_PIN5,DIO_HIGH);
	DIO_write(DIO_PORTB, DIO_PIN6,DIO_HIGH);
	DIO_write(DIO_PORTB, DIO_PIN7,DIO_HIGH);

	if (Keypad_Get_Row() == current_row)
	{
		Loc_Column = 0;

	}

	DIO_write(DIO_PORTB, DIO_PIN4,DIO_HIGH);
	DIO_write(DIO_PORTB, DIO_PIN5,DIO_LOW);
	DIO_write(DIO_PORTB, DIO_PIN6,DIO_HIGH);
	DIO_write(DIO_PORTB, DIO_PIN7,DIO_HIGH);

	if (Keypad_Get_Row() == current_row)
	{
		Loc_Column = 1;

	}

	DIO_write(DIO_PORTB, DIO_PIN4,DIO_HIGH);
	DIO_write(DIO_PORTB, DIO_PIN5,DIO_HIGH);
	DIO_write(DIO_PORTB, DIO_PIN6,DIO_LOW);
	DIO_write(DIO_PORTB, DIO_PIN7,DIO_HIGH);

	if (Keypad_Get_Row() == current_row)
	{
		Loc_Column = 2;

	}

	DIO_write(DIO_PORTB, DIO_PIN4,DIO_HIGH);
	DIO_write(DIO_PORTB, DIO_PIN5,DIO_HIGH);
	DIO_write(DIO_PORTB, DIO_PIN6,DIO_HIGH);
	DIO_write(DIO_PORTB, DIO_PIN7,DIO_LOW);

	if (Keypad_Get_Row() == current_row)
	{
		Loc_Column = 3;

	}
	return Loc_Column;
}

void Keypad_Int(void)
{
	/*	Configure Rows Pins as Input	*/
	DIO_cnfg_channel(DIO_PORTC, DIO_PIN1, DIO_INPUT);
	DIO_cnfg_channel(DIO_PORTC, DIO_PIN0, DIO_INPUT);
	DIO_cnfg_channel(DIO_PORTC, DIO_PIN5, DIO_INPUT);
	DIO_cnfg_channel(DIO_PORTA, DIO_PIN0, DIO_INPUT);

	/*	Enable Pull Up Resistor For Rows Channels	*/
	DIO_pull_up(DIO_PORTC, DIO_PIN1);
	DIO_pull_up(DIO_PORTC, DIO_PIN0);
	DIO_pull_up(DIO_PORTC, DIO_PIN5);
	DIO_pull_up(DIO_PORTA, DIO_PIN0);

	/*	Configure Columns Pins as Output	*/
	DIO_cnfg_channel(DIO_PORTB, DIO_PIN4, DIO_OUTPUT);
	DIO_cnfg_channel(DIO_PORTB, DIO_PIN5, DIO_OUTPUT);
	DIO_cnfg_channel(DIO_PORTB, DIO_PIN6, DIO_OUTPUT);
	DIO_cnfg_channel(DIO_PORTB, DIO_PIN7, DIO_OUTPUT);

	/*	Initialize all Columns Outputs with zeros	*/
	DIO_write(DIO_PORTB, DIO_PIN4,DIO_LOW);
	DIO_write(DIO_PORTB, DIO_PIN5,DIO_LOW);
	DIO_write(DIO_PORTB, DIO_PIN6,DIO_LOW);
	DIO_write(DIO_PORTB, DIO_PIN7,DIO_LOW);
}



u8 Keypad_Read(void)
{
	s8 loc_Row = -1;
	s8 loc_Col = -1;
	u8 loc_button;

	Keypad_Int();
	if(Keypad_Is_Pressed() == TRUE)
	{
		loc_Row = Keypad_Get_Row();
		loc_Col = Keypad_Get_Column(loc_Row);
		loc_button = Keypad_Layout[loc_Row][loc_Col];
	}
	else
	{
		return 0xFF;
	}
	return loc_button;
}

