/*
 * Led_Program.c
 *
 *  Created on: ???/???/????
 *      Author: Mohamed
 */

#include "../../Common/STD_type.h"
#include "../../Common/Definition.h"
#include "../../Common/Bit_Math.h"
#include "../../MCAL/DIO/Dio_Interface.h"

#include "Led_Interface.h"
#include "Led_Config.h"

void Void_Led_Pin( u8 Led_status )
{
		if (Led_status == Led_On)
		{
		DIO_voidSetPinDir(Group_type , Pin_No , Output);
		DIO_voidSetPinValue(Group_type , Pin_No , Led_On);
		}
		else if (Led_status == Led_Off)
		{
			DIO_voidSetPinDir(Group_type , Pin_No , Output);
		    DIO_voidSetPinValue(Group_type , Pin_No , Led_Off);
		}
}


