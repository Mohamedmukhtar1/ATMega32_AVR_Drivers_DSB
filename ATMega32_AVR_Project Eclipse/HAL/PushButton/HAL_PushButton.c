/*
 * HAL_PushButton.c
 *
 *  Created on: Oct 20, 2022
 *      Author: Eng- Mohamed Mokhtar
 */

#include "HAL_PushButton_Interface.h"

void HPushButton_vInitiate(u8 Lu8_PushButton_x_PORT, u8 Lu8_PushButton_x_PIN)
{
	MGPIO_InitPinMode(Lu8_PushButton_x_PORT, Lu8_PushButton_x_PIN, GPIO_INPUT);
}

u8 HPushButton_u8Read(u8 Lu8_PushButton_x_PORT, u8 Lu8_PushButton_x_PIN)
{
	u8 PushButtonRead =0;
	if (PUSHBUTTON_PRESSE == MGPIO_ReadPin(Lu8_PushButton_x_PORT, Lu8_PushButton_x_PIN))
	{
		Delay_vMilliSecond16MHzoscillator(25);
		if (PUSHBUTTON_PRESSE == MGPIO_ReadPin(Lu8_PushButton_x_PORT, Lu8_PushButton_x_PIN))
		{
			while (PUSHBUTTON_PRESSE == MGPIO_ReadPin(Lu8_PushButton_x_PORT, Lu8_PushButton_x_PIN));
			return PushButtonRead =PUSHBUTTON_PRESSE;
		} else {/*NOTHING only done Scanning*/}
	}
	else{/*NOTHING only continue Scan*/
		PushButtonRead =PUSHBUTTON_RELEASE;
	}
	return PushButtonRead;
}

void HPushButton_vExecuteFunOnPush(void (*LPtrFun)(void), u8 Lu8_PushButton_x_PORT, u8 Lu8_PushButton_x_PIN)
{
	if(NULL != LPtrFun)
	{
		if(PUSHBUTTON_PRESSE == HPushButton_u8Read(Lu8_PushButton_x_PORT, Lu8_PushButton_x_PIN))
		{
			LPtrFun();
		}
		else{/*Nothing*/}
	}
	else{/*Error to execute*/}
}


