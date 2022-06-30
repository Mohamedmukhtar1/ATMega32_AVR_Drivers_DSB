/*
 * HAL_LED_Interface.h
 *
 *  Created on: May 19, 2022
 *      Author: Eng- Mohamed Mokhtar
 */

#ifndef INC_HAL_LED_HAL_LED_INTERFACE_H_
#define INC_HAL_LED_HAL_LED_INTERFACE_H_

/***************_APP_INCLUDES_*****************************/
#include "..\..\APP\Utility\APP_Utility.h"

/***************_HAL_INCLUDES_*****************************/
#include "HAL_LED_Private.h"
#include "HAL_LED_Config.h"

/***************_MCAL_INCLUDES_****************************/
#include "..\..\MCAL\GPIO\MCAL_GPIO_Interface.h"

#define LED_0_	(0U)
#define LED_1_	(1U)
#define LED_2_	(2U)

#define LED_ON		GPIO_HIGH
#define LED_OFF		GPIO_LOW

/*============================================================================
 ==================_APIs Supported by "HAL_LED DRIVER"_======================
 ============================================================================*/
void HLED_vInitiate(u8 Lu8_LED_x_);
void HLED_vStateControl(u8 Lu8_LED_x_, u8 Lu8_LED_State);
void HLED_vToggelLED(u8 Lu8_LED_x_);
void HLED_vBlinkLED(u8 Lu8_LED_x_);

#endif /* INC_HAL_LED_HAL_LED_INTERFACE_H_ */
