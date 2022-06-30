/*
 * HAL_POT_Interface.h
 *
 *  Created on: Jun 23, 2022
 *      Author: Eng- Mohamed Mokhtar
 */

#ifndef HAL_POT_HAL_POT_INTERFACE_H_
#define HAL_POT_HAL_POT_INTERFACE_H_

/***************_APP_INCLUDES_*****************************/
#include "..\..\APP\Utility\APP_Utility.h"

/***************_HAL_INCLUDES_*****************************/
#include "HAL_POT_Private.h"
#include "HAL_POT_Config.h"

/***************_MCAL_INCLUDES_****************************/
#include "../../MCAL/ADC/MCAL_ADC_Interface.h"

/*============================================================================
 ==================_APIs Supported by "HAL_POT DRIVER"_======================
 ============================================================================*/
void HPOT_vInitiate(u8 Lu8_ADC_Channel_x_);

u16 HPOT_u16Read_PoolingMode();
u16 HPOT_u16Read_OnInterrupt();

f32 HPOT_f32Read_PoolingMode();
f32 HPOT_f32Read_OnInterrupt();

#endif /* HAL_POT_HAL_POT_INTERFACE_H_ */
