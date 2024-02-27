/*
 * Lcd_config.h
 *
 *  Created on: Sep 15, 2023
 *      Author: mohamed
 */

#ifndef HAL_LCD_LCD_CONFIG_H_
#define HAL_LCD_LCD_CONFIG_H_
#include "../../MCAL/DIO/DIO_Interface.h"

#include "../../Common/STD_type.h"

#define Lcd_ControlGroup        DIO_GroupB
#define Lcd_RsPin				DIO_Pin0
#define Lcd_RwPin				DIO_Pin1
#define Lcd_EPin				DIO_Pin2


#define Lcd_DCGroup          DIO_GroupA



#endif /* HAL_LCD_LCD_CONFIG_H_ */
