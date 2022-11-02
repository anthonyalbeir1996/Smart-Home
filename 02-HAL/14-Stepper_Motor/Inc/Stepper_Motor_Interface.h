/*
 * ADC_cfg.h
 *
 *  Created on: Jul 3, 2022
 *      Author: Anthony
 */
#ifndef STEPPER_MOTOR_INTERFACE_H_
#define STEPPER_MOTOR_INTERFACE_H_

#include "Dio_Interface.h"
#include <util/delay.h>
typedef enum
{
	CLOCK_WISE_STEPPER,
	ANTI_CLOCK_WISE_STEPPER

}clk_wise;

typedef enum
{
LOW_NIPPLE,
HIGH_NIPPLE,
RAND_NIPPLE
}nipple_port;
void Stepper_Int(dio_port_t port,nipple_port nipple);
void Stepper_Cfg(u8 speed,clk_wise clk,nipple_port nipple);


#endif /* STEPPER_MOTOR_INTERFACE_H_ */
