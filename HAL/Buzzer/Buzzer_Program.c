/*
 * Buzzer_Program.c
 *
 *  Created on: ???/???/????
 *      Author: Mohamed
 */


#include "../../Common/STD_type.h"
#include "../../Common/Definition.h"
#include "../../Common/Bit_Math.h"
#include "../../MCAL/DIO/Dio_Interface.h"

#include "Buzzer_Interface.h"
#include "Buzzer_Config.h"

void Void_Buzzer_Pin( u8 Buzzer_status )
{
		if (Buzzer_status == Buzzer_On)
		{
		DIO_voidSetPinDir(Group_type , Pin_No , Output);
		DIO_voidSetPinValue(Group_type , Pin_No , Buzzer_On);
		}
		else if (Buzzer_status == Buzzer_Off)
		{
			DIO_voidSetPinDir(Group_type , Pin_No , Output);
		    DIO_voidSetPinValue(Group_type , Pin_No , Buzzer_Off);
		}
}


