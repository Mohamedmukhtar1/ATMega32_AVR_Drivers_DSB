/*
 * HAL_PushButton_Interface.h
 *
 *  Created on: Oct 20, 2022
 *      Author: Eng- Mohamed Mokhtar
 */

#ifndef HAL_PUSHBUTTON_HAL_PUSHBUTTON_INTERFACE_H_
#define HAL_PUSHBUTTON_HAL_PUSHBUTTON_INTERFACE_H_

/***************_APP_INCLUDES_*****************************/
#include "..\..\APP\Utility\APP_Utility.h"

/***************_HAL_INCLUDES_*****************************/
#include "HAL_PushButton_Private.h"
#include "HAL_PushButton_Config.h"

/***************_MCAL_INCLUDES_****************************/
#include "../../MCAL/GPIO/MCAL_GPIO_Interface.h"
#include "../../MCAL/EXTI/MCAL_EXTI_Interface.h"

/*============================================================================
 ==================_APIs Supported by "HAL_PushButton DRIVER"_======================
 ============================================================================*/
void HPushButton_vInitiate(u8 Lu8_PushButton_x_PORT, u8 Lu8_PushButton_x_PIN);
u8 HPushButton_u8Read(u8 Lu8_PushButton_x_PORT, u8 Lu8_PushButton_x_PIN);
void HPushButton_vExecuteFunOnPush(void (*LPtrFun)(void), u8 Lu8_PushButton_x_PORT, u8 Lu8_PushButton_x_PIN);

#endif /* HAL_PUSHBUTTON_HAL_PUSHBUTTON_INTERFACE_H_ */
