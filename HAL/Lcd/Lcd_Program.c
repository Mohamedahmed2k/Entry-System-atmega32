/*
 * Lcd_Program.c
 *
 *  Created on: Sep 15, 2023
 *      Author: mohamed
 */
#include "../../Common/STD_type.h"
#include "../../Common/Definition.h"
#include <util/delay.h>

#include "../../MCAL/DIO/DIO_Interface.h"

#include "Lcd_Interface.h"
#include "Lcd_Private.h"
#include "Lcd_config.h"


void Lcd_voidSendCommand(u8 command)
{
//set the RS value as Low (command =>RS =  0 )
	DIO_voidSetPinValue(Lcd_ControlGroup,Lcd_RsPin,Low);
//set the RW vlaue as Low (Write  => RW = 0 )
	DIO_voidSetPinValue(Lcd_ControlGroup,Lcd_RwPin,Low);
//set the E Value as High (High CLK)
	DIO_voidSetPinValue(Lcd_ControlGroup,Lcd_EPin,High);
//Send Command
	DIO_voidSetPortValue(Lcd_DCGroup,command);
//Set the E value as Low (Low CLK)
	DIO_voidSetPinValue(Lcd_ControlGroup,Lcd_EPin,Low);

}

void Lcd_voidSendData(u8 data)
{
//set the RS value as Low (Data =>RS =  1 )
	DIO_voidSetPinValue(Lcd_ControlGroup,Lcd_RsPin,High);
//set the RW vlaue as Low (Write  => RW = 0 )
	DIO_voidSetPinValue(Lcd_ControlGroup,Lcd_RwPin,Low);
//set the E Value as High (High CLK)
	DIO_voidSetPinValue(Lcd_ControlGroup,Lcd_EPin,High);
//Send Data
	DIO_voidSetPortValue(Lcd_DCGroup,data);
//Set the E value as Low (Low CLK)
	DIO_voidSetPinValue(Lcd_ControlGroup,Lcd_EPin,Low);

}


void Lcd_voidInit()
{
	//set Direction
	DIO_voidSetPinDir(Lcd_ControlGroup,Lcd_RsPin,Output);
	DIO_voidSetPinDir(Lcd_ControlGroup,Lcd_RwPin,Output);
	DIO_voidSetPinDir(Lcd_ControlGroup,Lcd_EPin,Output);
	DIO_voidSetPortDir(Lcd_DCGroup,0xff);
	//wait for 30ms
	_delay_ms(35);
	//sent the Function set
	Lcd_voidSendCommand(LCD_Set8Bit2Line5x8);
	//wait for 39us
	_delay_ms(1);
	//sent the display
	Lcd_voidSendCommand(LCD_CursorBlinkON);
	//wait for 39us
	_delay_ms(1);
	//sent the Clear
	Lcd_voidSendCommand(LCD_ClearDisplay);
	//wait for 1.53ms
	_delay_ms(2);
	//sent the EntryMode
	Lcd_voidSendCommand(LCD_EntryMode2);

}


void Lcd_voidSendWord(u8 *String)
{
	u8 i = 0 ;
	while(String[i]!='\0')
	{
		Lcd_voidSendData(String[i]);
		i++;
	}
}

void Lcd_voidGoXY(u8 XPos,u8 YPos)
{
	u8 DDRAM_Add;
	switch(XPos)
	{
	case FirstLinePos  : DDRAM_Add=FristLineAdd ; break;
	case SecondLinePos :DDRAM_Add=SecondLineAdd ; break;
	}
	Lcd_voidSendCommand((DDRAM_Add+YPos)|LCD_SetAddressDDRAM);

}
void Lcd_voidSpecialChar(u8 BlockNo , u8 *SpecialChar , u8 XPos,u8 YPos)
{
	u8 CGRAM_Add ;
	u8 Counter = 0 ;
	CGRAM_Add = BlockNo*LCD_CGRAMMaxSize ;
	Lcd_voidSendCommand(CGRAM_Add|LCD_SetAddCGRAM);
	for(Counter=0;Counter<8;Counter++)
	{
		Lcd_voidSendData(SpecialChar[Counter]);

	}
	Lcd_voidGoXY(XPos,YPos);
	Lcd_voidSendData(BlockNo);
}






