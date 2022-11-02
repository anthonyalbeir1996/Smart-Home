/*
 * GINT.c
 *
 *  Created on: Jul 3, 2022
 *      Author: Anthony
 */


#include "GINT_interface.h"

void GINT_ENABLE_INTERRUPT(void)
{
	SET_BIT(GINT_SREG_reg,7);
}
void GINT_DISABLE_INTERRUPT(void)
{
	CLEAR_BIT(GINT_SREG_reg,7);
}

