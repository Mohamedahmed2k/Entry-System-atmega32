/*
 * LCD_KeyPad_Interface.h
 *
 *  Created on: ???/???/????
 *      Author: Mohamed
 */


#ifndef APP_LCD_KEYPAD_APP_LCD_KEYPAD_INTERFACE_H_
#define APP_LCD_KEYPAD_APP_LCD_KEYPAD_INTERFACE_H_

#include "../../Common/STD_type.h"
#include "../../HAL/Lcd/Lcd_Interface.h"
#include "../../HAL/KeyPad/KeyPad_Interface.h"

void LCD_KeyPad_App_Init(u8 *String_Password);
void LCD_KeyPad_App_Set();
void AddtionCorract();
void AddtionWrong();
#endif /* APP_LCD_KEYPAD_APP_LCD_KEYPAD_INTERFACE_H_ */
