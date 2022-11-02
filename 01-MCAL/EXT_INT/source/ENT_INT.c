/*
 * ENT_INT.c
 *
 *  Created on: Jul 3, 2022
 *      Author: Anthony
 */


#include "EXT_INT.h"

void Ext_INTERRUPT_ENABE(ext_int_t ID)
{
	switch(ID)
	{
	case ext_INT0:
		SET_BIT(EXT_INT_GIFR_REG,6);
		break;
	case ext_INT1:
		SET_BIT(EXT_INT_GIFR_REG,7);
		break;
	case ext_INT2:
			SET_BIT(EXT_INT_GIFR_REG,5);
			break;
	}
}
void EXT_INTERRUPT_DISABLE(ext_int_t ID)
{
	switch(ID)
		{
		case ext_INT0:
			CLEAR_BIT(EXT_INT_GIFR_REG,6);
			break;
		case ext_INT1:
			CLEAR_BIT(EXT_INT_GIFR_REG,7);
			break;
		case ext_INT2:
			CLEAR_BIT(EXT_INT_GIFR_REG,5);
				break;
		}
}


void EXT_INTERUPPT_SENCONTROL (ext_int_t ID,ext_int_modes_t mode)
{
	switch (ID)
	{
	case ext_INT0:
		EXT_INT_MCUCR_REG |=(mode<<0);
		break;
	case ext_INT1:
		EXT_INT_MCUCR_REG |=(mode<<2);
		break;
	case ext_INT2:
		if(mode==The_falling_edge)
		{
			CLEAR_BIT(EXT_INT_MCUCSR_REG,6);
		}
		else if (mode==The_rising_edge)
		{
			SET_BIT(EXT_INT_MCUCSR_REG,6);
		}
		else
		{
			/* do nothing */
		}


	}
}
