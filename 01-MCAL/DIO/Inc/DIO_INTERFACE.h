/*
 * DIO_INTERFACE.h
 *
 *  Created on: Jun 21, 2022
 *      Author: Anthony
 */

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#include "Bit_Math.h"
#include "Std_Types.h"
#include "DIO_REG.h"
#include "DIO_TYPES.h"


void DIO_cnfg_channel (dio_port_t port, dio_pin_t pin, dio_direction_t direction);
void DIO_write (dio_port_t port, dio_pin_t pin, dio_level_t level);
void DIO_write_Group(dio_port_t port,u8 mask,u8 data);
void DIO_pull_up(dio_port_t port,dio_pin_t pin);

dio_level_t DIO_read(dio_port_t port,dio_pin_t pin );
void DIO_flip(dio_port_t port,dio_pin_t pin );



#endif /* DIO_INTERFACE_H_ */
