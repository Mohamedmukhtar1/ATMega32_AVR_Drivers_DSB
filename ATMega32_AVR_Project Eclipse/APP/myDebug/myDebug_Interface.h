/*
 * myDebug_Interface.h
 *
 *  Created on: Jun 24, 2022
 *      Author: Eng- Mohamed Mokhtar
 */

#ifndef APP_MYDEBUG_MYDEBUG_INTERFACE_H_
#define APP_MYDEBUG_MYDEBUG_INTERFACE_H_

/***************_APP_INCLUDES_*****************************/
#include "../../APP\Utility/APP_Utility.h"
#include "../../APP/Utility/Math/Math_Interface.h"

/***************_myDebug_INCLUDES_*************************/
#include "../../APP/myDebug/myDebug_Config.h"

/***************_RTOS_INCLUDES_****************************/
#include "../../RTOS/FreeRTOS.h"
#include "../../RTOS/task.h"
#include "../../RTOS/semphr.h"

/***************_HAL_INCLUDES_*****************************/
////Output Devices
#include "../../HAL/LCD/HAL_LCD_Interface.h"
#include "../../HAL/LED/HAL_LED_Interface.h"

////Input Devices
#include "../../HAL/Keypad/HAL_Keypad_Interface.h"
#include "../../HAL/LM35_TempSensor/HAL_LM35_TempSensor_Interface.h"
#include "../../HAL/POT/HAL_POT_Interface.h"
#include "../../HAL/PushButton/HAL_PushButton_Interface.h"

/***************_MCAL_INCLUDES_****************************/
#include "../../MCAL/GPIO/MCAL_GPIO_Interface.h"
#include "../../MCAL/ADC/MCAL_ADC_Interface.h"
#include "../../MCAL/GIE/MCAL_GIE_Interface.h"
#include "../../MCAL/EXTI/MCAL_EXTI_Interface.h"

/*============================================================================
 ==================_APIs Supported by "myDebug DRIVER"_===================
 ============================================================================*/
void DADC_ActiveAll_GPIO_Test(void);
void DADC_Simple_ADC_Test(u8 ADC_CHANNEL_x);
void DKeyPad_Simple_Kepad_Test(void);
void DKeyPad_Simple_Kepad_withoutValidation(void);
void DLM35_Simple_LM35_Test(u8 ADC_CHANNEL_x);
void DPOT_Simple_POT_Test(u8 ADC_CHANNEL_x);
void DPushButton_Simple_PushButton_Read(u8 Lu8_PushButton_x_PORT, u8 Lu8_PushButton_x_PIN);
void DPushButton_ExecuteFunOnPush(u8 Lu8_PushButton_x_PORT, u8 Lu8_PushButton_x_PIN);
void PushTest(void);

#endif /* APP_MYDEBUG_MYDEBUG_INTERFACE_H_ */
