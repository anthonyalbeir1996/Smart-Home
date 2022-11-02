/*
 * ADC_cfg.h
 *
 *  Created on: Jul 3, 2022
 *      Author: Anthony
 */

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_
#include "Uart_Reg.h"
#include "std_Types.h"
#include "Bit_Math.h"
#include <stddef.h>
#include <avr/interrupt.h>
#include "Led_Interface.h"
#include "GINT_interface.h"
#include "Servo_Motor_Inteface.h"
#include <avr/io.h>

void UART_Int(void);
void UART_Transmit_chr(u8 data);
void UART_TransmitString(u8* str);
void EXT_INT_UASRT_Callout(void(*ptr)(u8));
u8 UART_Receive(void);



u8 *UART1_Rx_Str();

#define BAUD 9600

#endif /* UART_INTERFACE_H_ */
