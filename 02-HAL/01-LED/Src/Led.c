/*
 * Led.c
 *
 *  Created on: Jun 23, 2022
 *      Author: lione
 */
#include "Led_Interface.h"
void Led_Init()
{
	DIO_cnfg_channel(DIO_PORTC, LED0_PIN, DIO_OUTPUT);
	DIO_cnfg_channel(LED1_PORT, LED1_PIN, DIO_OUTPUT);
	DIO_cnfg_channel(LED2_PORT, LED2_PIN, DIO_OUTPUT);

	DIO_write(LED0_PORT, LED0_PIN, DIO_LOW);
	DIO_write(LED1_PORT, LED1_PIN, DIO_LOW);
	DIO_write(LED2_PORT, LED2_PIN, DIO_LOW);
}
void Led_ON(led_id_t led)
{
	switch (led) {
	case LED0:
#if(LED0_CONNECTION==SOURCE)
		DIO_write(LED0_PORT, LED0_PIN, DIO_HIGH);
#else
		DIO_write(LED0_PORT, LED0_PIN, DIO_LOW);
#endif
		break;
	case LED1:
#if(LED1_CONNECTION==SOURCE)
		DIO_write(LED1_PORT, LED1_PIN, DIO_HIGH);
#else
		DIO_write(LED1_PORT, LED1_PIN, DIO_LOW);
#endif
		break;
	case LED2:
#if(LED2_CONNECTION==SOURCE)
		DIO_write(LED2_PORT, LED2_PIN, DIO_HIGH);
#else
		DIO_write(LED2_PORT, LED2_PIN, DIO_LOW);
#endif
		break;
	}
}

void Led_OFF(led_id_t led)
{
	switch (led) {
	case LED0:
#if(LED0_CONNECTION==SOURCE)
		DIO_write(LED0_PORT, LED0_PIN, DIO_LOW);
#else
		DIO_write(LED0_PORT, LED0_PIN, DIO_HIGH);
#endif
		break;

	case LED1:
#if(LED1_CONNECTION==SOURCE)
		DIO_write(LED1_PORT, LED1_PIN, DIO_LOW);
#else
		DIO_write(LED1_PORT, LED1_PIN, DIO_HIGH);
#endif
		break;

	case LED2:
#if(LED2_CONNECTION==SOURCE)
		DIO_write(LED2_PORT, LED2_PIN, DIO_LOW);
#else
		DIO_write(LED2_PORT, LED2_PIN, DIO_HIGH);
#endif
		break;
	}
}

void Led_Toggle(led_id_t led)
{
	switch (led) {
	case LED0:
		DIO_flip(DIO_PORTC,DIO_PIN2);
		break;
	case LED1:
		DIO_flip(DIO_PORTC,DIO_PIN7);
		break;
	case LED2:
		DIO_flip(DIO_PORTD,DIO_PIN3);
		break;
	}
}
