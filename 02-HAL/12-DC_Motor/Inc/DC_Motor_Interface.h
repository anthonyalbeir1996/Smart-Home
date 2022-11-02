/*
 * ADC_cfg.h
 *
 *  Created on: Jul 3, 2022
 *      Author: Anthony
 */
#ifndef DC_MOTOR_INTERFACE_H_
#define DC_MOTOR_INTERFACE_H_
#include "std_Types.h"
#include "Bit_Math.h"
#include "Dio_Interface.h"
#include "Timer2_Interface.h"
typedef enum{
	CLOCKWISE,
	ANTICLOCKWISE
	
}direction;

void DC_Motor_Int();
void DC_Motor_Start(void);
void DC_Motor_Set_Direction(direction direction_motor);
void DC_Motor_Stop(void);
void DC_Motor_Speed(u8 Speed);
#endif /* DC_MOTOR_INTERFACE_H_ */
