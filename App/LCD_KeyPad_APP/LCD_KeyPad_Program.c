/*
 * LCD_KeyPad_Program.c
 *
 *  Created on: ???/???/????
 *      Author: Mohamed
 */


#include "LCD_KeyPad_Config.h"
#include "LCD_KeyPad_Interface.h"
#include <util/delay.h>
#include "../../HAL/Buzzer/Buzzer_Interface.h"
#include "../../MCAL/EEPROM_INTERNAL/EEPROM_Interface.h"

void LCD_KeyPad_App_Init(u8 *StringPass )
{
   	    Void_Key_Pad_Init();
		Lcd_voidInit();
		Lcd_voidSendWord("  ENTER PASS: ");

		EEPROM_voidWriteNBytes(0b0000000000,StringPass,Pass_Size);
}
void LCD_KeyPad_App_Set()
{
    u8 String_Password[20];
    EEPROM_voidReadNBytes(0b0000000000,String_Password,Pass_Size);
	u16 Flag = 0 ;
    u16 Correct = 0 ;
    u8 Counter = 0 ;
    u16 KO = 0 ;
    u16 Space = 0 ;
    u8 press_value = '0' ;

	Space = (16-Pass_Size)/2 ;
	do{

		KO = 0 ;
		Counter = 0 ;
		Flag = 0 ;
		while(String_Password[Counter]!='\0')
		{
			press_value = u8_Keypad_valu();
		if(press_value == String_Password[Counter] &&  press_value  != '0')
		{
			Counter++;
			Flag++;
			if(KO == 0)
						{
						Lcd_voidGoXY(1,Space);
						KO++;
						}
			Lcd_voidSendWord("#");
		}
		else if ( press_value  != '0')
		{
			Counter++;
			if(KO == 0)
						{
						Lcd_voidGoXY(1,Space);
						KO++;
						}
			Lcd_voidSendWord("#");
		}
		}



	    if( Flag < Pass_Size )
	    {
			Lcd_voidGoXY(0,0);
				Lcd_voidSendWord("    try agian    ");
				Lcd_voidGoXY(1,0);
				Lcd_voidSendWord("                   ");
				Correct++ ;
	    }
	    else if(Flag == Pass_Size)
	    {
	    	Flag++;
	    					Lcd_voidSendWord("#");
	    					_delay_ms(100);
	    					Lcd_voidGoXY(0,0);
	    					Lcd_voidSendWord("     Welcome     ");
	    					Lcd_voidGoXY(1,0);
	    					Lcd_voidSendWord("                   ");
	    					_delay_ms(3000);
	    					AddtionCorract();
	    					break;
	    }

	}while(Correct< Failed_NO );

		if (Correct >= Failed_NO)
		{
			Lcd_voidGoXY(0,0);
				Lcd_voidSendWord("     wrong ");

				Lcd_voidSpecialChar(1,Charcter,0,11);
				Lcd_voidSendWord("    ");
				Lcd_voidGoXY(1,0);
				Lcd_voidSendWord("                   ");
				AddtionWrong();
		}
}
AddtionCorract()
{
	u8 press_value = '0' ;
	Lcd_voidGoXY(0,0);
    Lcd_voidSendWord("  change Password ?    ");
    Lcd_voidGoXY(1,0);
    Lcd_voidSendWord("  1:Yes     2:No          ");
    u8 size = Pass_Size;
    u8 Value[6];
    u8 i = 0 ;

    	press_value = u8_Keypad_valu();

    if(press_value =='1'&&  press_value  != '0')
    {
    	Lcd_voidGoXY(1,0);
    				Lcd_voidSendWord("                      ");
    				Lcd_voidGoXY(0,0);
    				    				Lcd_voidSendWord("                     ");

    	while(size != 0)
    	{
    		Value[i]=u8_Keypad_valu();
    		Lcd_voidGoXY(0,5);
    		Lcd_voidSendWord("#");
    		i++ ;
    		size-- ;
    	}
      EEPROM_voidWriteNBytes(0b0000000000,Value,Pass_Size);

    }
     if(press_value ==   '2'&&  press_value  != '0')
    {
    	 Lcd_voidGoXY(0,0);
    	     Lcd_voidSendWord(" Thank you    ");
    	     Lcd_voidSpecialChar(1,Charcter,0,11);
    	     Lcd_voidGoXY(1,0);
    	     Lcd_voidSendWord("  1:Yes     2:No          ");

    }
     /* if (press_value ==   '3'&&  press_value  != '0' )
    }

	/* servo open door*/
	/* button */
	/* eeprom*/


}




AddtionWrong()
    {
	//*  wrong password */

    }
