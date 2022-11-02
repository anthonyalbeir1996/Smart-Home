/*
 * ADC_cfg.h
 *
 *  Created on: Jul 3, 2022
 *      Author: Anthony
 */

#ifndef BLUETOOTH_INTERFACE_H_
#define BLUETOOTH_INTERFACE_H_
#include "Uart_interface.h"
#include <util/delay.h>
#include "GINT_interface.h"
//#define DoubleSpeed



void Bluetooth_Init();
void Bluetooth_Transmit(s8 data);
s8 Bluetooth_Receive();
void Bluetooth_TransmitString(s8 * string);
void Bluetooth_ReadString(u8 name[5]);

#endif /* BLUETOOTH_INTERFACE_H_ */
