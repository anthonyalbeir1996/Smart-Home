/*
 * EXT_INT_types.h
 *
 *  Created on: Jul 3, 2022
 *      Author: Anthony
 */

#ifndef EXT_INT_TYPES_H_
#define EXT_INT_TYPES_H_

typedef enum
{
	ext_INT0,
	ext_INT1,
	ext_INT2
}ext_int_t;



typedef enum
{
	The_low_level,
	BOTH_level,
	The_falling_edge,
	The_rising_edge

}ext_int_modes_t;


#endif /* MCAL_EXT_INT_INC_EXT_INT_TYPES_H_ */
