/*
 * ADC_cfg.h
 *
 *  Created on: Jul 3, 2022
 *      Author: Anthony
 */
#ifndef BUTTON_INTERFACE_H_
#define BUTTON_INTERFACE_H_

#include "Dio_Interface.h"
#include "Button_Types.h"



dio_level_t Button_Read(button_id_t id);

#endif /* BUTTON_INTERFACE_H_ */
