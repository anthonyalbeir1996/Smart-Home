/*
 * WDT.c
 *
 *  Created on: Oct 20, 2022
 *      Author: Anthony
 */

#include "WDT_Interface.h"

void WDT_Int()
{
	// Watchdog Enable
	SET_BIT(WDTCR_REG,3);

}

void WDT_Refresh()
{
	// WDR in assemplay means that u say to th eprossecor to reset the watchdog timer
	asm("WDR");
}

void WDT_Start()
{
		//Watchdog Timer Prescaler 2, 1, and 0 to be 2.1 sec
	SET_BIT(WDTCR_REG,0);
	SET_BIT(WDTCR_REG,1);
	SET_BIT(WDTCR_REG,2);
}

