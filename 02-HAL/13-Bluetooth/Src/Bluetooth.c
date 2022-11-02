/*
 * Bluetooth.c
 *
 *  Created on: Oct 2, 2022
 *      Author: lione
 */

#include "Bluetooth_Interface.h"

void Bluetooth_Init()
{
 UART_Int();
}

void Bluetooth_Transmit(s8 data)
{
UART_Transmit_chr(data);
}


void Bluetooth_ReadString(u8 string[15])
{
	GINT_DISABLE_INTERRUPT();
	UART1_Rx_Str(string);
}


s8 Bluetooth_Receive()
{
return UART_Receive();
}

void Bluetooth_TransmitString(s8 * string)
{
	UART_TransmitString(string);
}

