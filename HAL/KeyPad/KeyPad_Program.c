#include "../../Common/STD_type.h"
#include "../../Common/Definition.h"
#include "../../Common/Bit_Math.h"
#include "../../MCAL/DIO/Dio_Interface.h"
#include "util/delay.h"
#include "KeyPad_Interface.h"
#include "KeyPad_Config.h"

 u8 KeypadValueInt[Row][Colom]=
 {
                 {'1','5','9','13'},
                 {'2','6','10','14'},
                 {'3','7','11','13'},
                 {'4','8','12','16'}
 };

u8 C_Pins[]=
{
		C1_Pin,
		C2_Pin,
		C3_Pin,
		C4_Pin
};

u8 R_Pins[]=
{
		R1_Pin,
		R2_Pin,
		R3_Pin,
		R4_Pin
};

 void  Void_Key_Pad_Init()
 {
	 int i ;
	 for( i = 0 ; i < Colom ; i++ )
	 {
	 DIO_voidSetPinDir(Group_type,C_Pins[i],Output);
	 }
	 for( i = 0 ; i < Colom ; i++ )
	 {
	 DIO_voidSetPinValue(Group_type,R_Pins[i],High);
	 }
	 for( i = 0 ; i < Row ; i++ )
	 {
	 DIO_voidSetPinDir(Group_type,R_Pins[i],Input);
	 }

 }

 u8 u8_Keypad_valu(  )
 {

	 u8 C = 0 ;
	 u8 R = 0 ;
	 u8 Value = '0';
	// while(Value == '0')

		 for( C = 0 ; C < Colom ; C++ )
		 {
			 DIO_voidSetPinValue(Group_type,C_Pins[C],Low);
			 for( R = 0 ; R < Row ; R++ )
			 {
				 if( !DIO_U8ReadPinValue(Group_type,R_Pins[R]))
				 {
					 while (!DIO_U8ReadPinValue(Group_type,R_Pins[R]))
				          ;

					 Value = KeypadValueInt[R][C];
				      /* Wait until the switch is released (Single Press)                                                          */

				        /* Delay to avoid bouncing                                                                                   */
				        _delay_ms(10);
				 }
			 }
			 DIO_voidSetPinValue(Group_type,C_Pins[C],High);
		 }

	 return Value ;
 }




