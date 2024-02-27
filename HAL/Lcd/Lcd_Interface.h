/*
 * Lcd_Interface.h
 *
 *  Created on: Sep 15, 2023
 *      Author: mohamed
 */

#ifndef HAL_LCD_LCD_INTERFACE_H_
#define HAL_LCD_LCD_INTERFACE_H_
#include "../../Common/STD_type.h"
#include "Lcd_Private.h"
#include "Lcd_config.h"


void Lcd_voidSendCommand(u8 command);
void Lcd_voidSendData(u8 data);
void Lcd_voidInit();
void Lcd_voidSendWord(u8 *String);

void Lcd_voidGoXY(u8 XPos,u8 YPos);
void Lcd_voidSpecialChar(u8 BlockNo , u8 *SpecialChar,u8 XPos,u8 YPos);

#endif /* HAL_LCD_LCD_INTERFACE_H_ */
