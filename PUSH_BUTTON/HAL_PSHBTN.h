/*
 * HAL_PSHBTN.h
 *
 * Created: 2022-04-09 09:34:30 PM
 *  Author: Eng- Mohamed Mokhtar
 */ 

#ifndef HAL_PSHBTN_H_
#define HAL_PSHBTN_H_

#include "APP_STD_Types.h"
#include "HAL_PSHBTN_CFG.h"
#include "MCAL_DIO.h"

#define    PRESSED         0
#define    RELEASED        1

/**		PushButton_NAME_LIST	 PushButton_Number		**/
#define PUSH_BUTTON_1_					1
#define PUSH_BUTTON_2_					2
#define PUSH_BUTTON_3_					3
#define PUSH_BUTTON_4_					4

/***************HAL_PSHBTN.C FUNCTION PROTOTYPE****************/
void HAL_PUSHBUTTON_INITIATE(uint8 HAL_uint8_PUSHBUTTON_NAME);
uint8 HAL_PUSHBUTTON_U8_READ(uint8 loc_U8_PUSHBUTTON_NAME);
//uint8 HAL_PUSHBUTTON_READ(uint8 HAL_uint8_PUSHBUTTON_NAME);

#endif /* HAL_PSHBTN_H_ */