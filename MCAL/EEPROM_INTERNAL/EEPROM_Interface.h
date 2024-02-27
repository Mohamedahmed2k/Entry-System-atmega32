/*
 * EEPROM_Interface.h
 *
 *  Created on: ???/???/????
 *      Author: Mohamed
 */

#ifndef MCAL_EEPROM_INTERNAL_EEPROM_INTERFACE_H_
#define MCAL_EEPROM_INTERNAL_EEPROM_INTERFACE_H_

#include "EEPROM_Config.h"
#include "EEPROM_Private.h"
#include "../../Common/Bit_Math.h"
#include "../../Common/STD_Type.h"
#include "../../Common/definition.h"

void EEPROM_voidWriteByte( u8 Address , u8 data);
u8 EEPROM_voidReadByte(u8 address);
void EEPROM_voidEraseAll(void);
void EEPROM_voidWriteNBytes(u16 eeprom_Address, u8 *RamAddr, u8 NoOfBytes);
void EEPROM_voidReadNBytes(u16 EepromAddr, u8 *RamAddr, u8 NoOfBytes);

#endif /* MCAL_EEPROM_INTERNAL_EEPROM_INTERFACE_H_ */
