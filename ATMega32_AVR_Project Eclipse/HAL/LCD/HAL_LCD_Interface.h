/*
 * HAL_LCD_Interface.H
 *
 * Created: 2022-04-10 02:43:49 PM
 *  Author: Eng- Mohamed Mokhtar
 */

#ifndef HAL_LCD_INTERFACE_H_
#define HAL_LCD_INTERFACE_H_

/***************_APP_INCLUDES_*****************************/
#include "..\..\APP\Utility\APP_Utility.h"

/***************_HAL_INCLUDES_*****************************/
#include "HAL_LCD_Private.h"
#include "HAL_LCD_Config.h"
#include "HAL_LCD_COMMANDS.h"

/***************_MCAL_INCLUDES_****************************/
#include "..\..\MCAL\GPIO\MCAL_GPIO_Interface.h"

/*============================================================================
 ==================_APIs Supported by "HAL_LCD DRIVER"_======================
 ============================================================================*/
void HLCD_vInitiate(void);
void HLCD_vWriteCommand(u8 Lu8_LCD_Command);
void HLCD_vClearScreen(void);
void HLCD_vGoTo(u8 Lu8_Row, u8 Lu8_Col);
void HLCD_vBuildCustomChar(u8 MemoryLocation, u8 CChar_Name);
/***********************************************************************/
void HLCD_vWriteCharacter(u8 Lu8_LCD_Character);
void HLCD_vWriteString(u8 *Lu8_PTR_String);
void HLCD_vWriteOrignalNumber(f32 loc_F32_NUMBER);
void HLCD_vWriteNumber(s32 loc_S32_NUMBER);
/***********************************************************************/
void HLCD_vWriteNumberFixedPosition(s32 loc_S32_NUMBER, u8 LinePostion,
		u8 Postion, u8 Width);

#endif /* HAL_LCD_INTERFACE_H_ */
