/*
 * HAL_Keypad_Interface.h
 *
 *  Created on: May 30, 2022
 *      Author: Eng- Mohamed Mokhtar
 */

#ifndef SRC_HAL_KEYPAD_HAL_KEYPAD_INTERFACE_H_
#define SRC_HAL_KEYPAD_HAL_KEYPAD_INTERFACE_H_

/***************_APP_INCLUDES_*****************************/
#include "..\..\APP\Utility\APP_Utility.h"

/***************_HAL_INCLUDES_*****************************/
#include "HAL_Keypad_Private.h"
#include "HAL_Keypad_Config.h"

/***************_MCAL_INCLUDES_****************************/
#include "../../MCAL/GPIO/MCAL_GPIO_Interface.h"

/*============================================================================
 ==================_APIs Supported by "HAL_Keypad DRIVER"_===================
 ============================================================================*/
void HKEYPAD_vInitiate(void);
u8 HKEYPAD_u8Read(void);
u8 HKEYPAD_u8ReadingValidation(u8 Lu8_Reading);

#endif /* SRC_HAL_KEYPAD_HAL_KEYPAD_INTERFACE_H_ */
