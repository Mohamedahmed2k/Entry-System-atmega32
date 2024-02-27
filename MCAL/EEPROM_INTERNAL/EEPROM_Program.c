/*
 * EEPROM_Program.cc
 *
 *  Created on: ???/???/????
 *      Author: Mohamed
 */

#include "EEPROM_Interface.h"

void EEPROM_voidWriteByte(u8 address,u8 data)
{
	//set up EEPROM address
	EE_EEARL=(u8)address;
	EE_EEARH=(u8)(address>>8);  //address is 10 bit
	//set up data register
	EE_EEDR=data;
	//enable write operation
	set_bit(EE_EECR,EE_EECR_EEMWE);
	set_bit(EE_EECR,EE_EECR_EEWE);
	//wait until write operation is complete
	while(get_bit(EE_EECR,EE_EECR_EEWE)==0);
}

u8 EEPROM_voidReadByte(u8 address)
{
	//set up EEPROM address
	EE_EEARL=(u8)address;
	EE_EEARH=(u8)(address>>8);  //address is 10 bit
	//enable read operation
	set_bit(EE_EECR,EE_EECR_EERE);
	return EE_EEDR;
}

void EEPROM_voidEraseAll(void)
{
	u16 EEPROM_Add ;
	for(EEPROM_Add = 0 ; EEPROM_Add < Max_Array ; EEPROM_Add++)
	{
		EEPROM_voidWriteByte( EEPROM_Add , 0x00 );
	}
}

void EEPROM_voidWriteNBytes(u16 eeprom_Address, u8 *RamAddr, u8 NoOfBytes)
{
	if(NULL != *RamAddr)
	{
		while(NoOfBytes !=  0)
		{
			EEPROM_voidWriteByte(eeprom_Address, *RamAddr);
			eeprom_Address++;
			RamAddr++;
			NoOfBytes--;
		}
	}
}

void EEPROM_voidReadNBytes(u16 EepromAddr, u8 *RamAddr, u8 NoOfBytes)
{
	if(NULL != *RamAddr)
	{
		while(NoOfBytes !=  0)
		{
			*RamAddr = EEPROM_voidReadByte(EepromAddr);
			EepromAddr++;
			RamAddr++;
			NoOfBytes--;
		}
	}
}
