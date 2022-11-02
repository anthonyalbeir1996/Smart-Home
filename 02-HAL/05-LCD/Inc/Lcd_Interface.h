/*
 * Lcd_Interface.h
 *
 *  Created on: Jun 24, 2022
 *      Author: lione
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_
#include "Dio_Interface.h"
#include "Lcd_Types.h"
#include "Lcd_Cfg.h"
#define LCD_Shift 4
#define LCD_MASK 0xF0

#include <util/delay.h>
void Lcd_Int(void);
void Lcd_Goto_Row_Column(u8 row, u8 column);
void Lcd_Write_Custom();
void Lcd_Display_str(u8 str[]);
void Lcd_Display_chr(u8 chr);
void Lcd_Cmd(lcd_Cmd_Type command);
#endif /* LCD_INTERFACE_H_ */
