/*
 * KeyPad_Config.h
 *
 *  Created on: ???/???/????
 *      Author: Mohamed
 */

#ifndef HAL_KEYPAD_KEYPAD_CONFIG_H_
#define HAL_KEYPAD_KEYPAD_CONFIG_H_
#include "../../MCAL/DIO/Dio_Interface.h"


#define Group_type  DIO_GroupD

#define C1_Pin  DIO_Pin0
#define C2_Pin  DIO_Pin1
#define C3_Pin  DIO_Pin2
#define C4_Pin  DIO_Pin3

#define R1_Pin  DIO_Pin4
#define R2_Pin  DIO_Pin5
#define R3_Pin  DIO_Pin6
#define R4_Pin  DIO_Pin7

#define Row      4
#define Colom    4
#define Pressed  0
#define Unpressed -1



#endif /* HAL_KEYPAD_KEYPAD_CONFIG_H_ */
