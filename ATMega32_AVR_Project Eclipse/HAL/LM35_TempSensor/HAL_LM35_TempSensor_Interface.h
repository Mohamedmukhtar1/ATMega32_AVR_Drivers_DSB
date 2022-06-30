/*
 * HAL_LM35_TempSensor_Interface.h
 *
 *  Created on: Jun 23, 2022
 *      Author: Eng- Mohamed Mokhtar
 */

#ifndef HAL_LM35_TEMPSENSOR_HAL_LM35_TEMPSENSOR_INTERFACE_H_
#define HAL_LM35_TEMPSENSOR_HAL_LM35_TEMPSENSOR_INTERFACE_H_

/***************_APP_INCLUDES_*****************************/
#include "..\..\APP\Utility\APP_Utility.h"

/***************_HAL_INCLUDES_*****************************/
#include "HAL_LM35_TempSensor_Private.h"
#include "HAL_LM35_TempSensor_Config.h"

/***************_MCAL_INCLUDES_****************************/
#include "../../MCAL/ADC/MCAL_ADC_Interface.h"

/*============================================================================
 ==================_APIs Supported by "HAL_LM35_TempSensor DRIVER"_==========
 ============================================================================*/
void HLM35_vInitiate(u8 Lu8_ADC_Channel_x_);

u16 HLM35_u16Read_PoolingMode();
u16 HLM35_u16Read_OnInterrupt();

f32 HLM35_f32Read_PoolingMode();
f32 HLM35_f32Read_OnInterrupt();

#endif /* HAL_LM35_TEMPSENSOR_HAL_LM35_TEMPSENSOR_INTERFACE_H_ */
