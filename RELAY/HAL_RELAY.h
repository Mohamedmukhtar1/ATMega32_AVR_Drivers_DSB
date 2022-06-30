/*
 * HAL_RELAY.h
 *
 * Created: 2022-04-09 11:32:08 PM
 *  Author: Eng- Mohamed Mokhtar
 */ 

#ifndef HAL_RELAY_H_
#define HAL_RELAY_H_

#include "APP_STD_Types.h"
#include "HAL_RELAY_CFG.h"
#include "MCAL_DIO.h"

/**		RELAY_NAME_LIST		RELAY_Number		**/
#define RELAY_1					1
#define RELAY_2					2

/***************HAL_RELAY.C FUNCTION PROTOTYPE****************/
void HAL_RELAY_INITIATE(uint8 loc_U8_RELAY_NAME);
void HAL_RELAY_ON_STATE(uint8 loc_U8_RELAY_NAME);
void HAL_RELAY_OFF_STATE(uint8 loc_U8_RELAY_NAME);
void HAL_RELAY_TOGGLE_STATE(uint8 loc_U8_RELAY_NAME); 

#endif /* HAL_RELAY_H_ */