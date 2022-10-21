/*
 * HAL_LED.c
 *
 *  Created on: May 19, 2022
 *      Author: Eng- Mohamed Mokhtar
 */

#include "HAL_LED_Interface.h"

void HLED_vInitiate(u8 Lu8_LED_x_PORT, u8 Lu8_LED_x_PIN)
{
	MGPIO_InitPinMode(Lu8_LED_x_PORT, Lu8_LED_x_PIN, GPIO_OUTPUT);
}

void HLED_vStateControl(u8 Lu8_LED_x_PORT, u8 Lu8_LED_x_PIN, u8 Lu8_LED_x_State)
{
	MGPIO_WritePin(Lu8_LED_x_PORT, Lu8_LED_x_PIN, Lu8_LED_x_State);
}

void HLED_vToggelLED(u8 Lu8_LED_x_PORT, u8 Lu8_LED_x_PIN)
{
	MGPIO_TogglePin(Lu8_LED_x_PORT, Lu8_LED_x_PIN);
}

void HLED_vBlinkLED(u8 Lu8_LED_x_PORT, u8 Lu8_LED_x_PIN)
{
	MGPIO_WritePin(Lu8_LED_x_PORT, Lu8_LED_x_PIN, GPIO_HIGH);
	Delay_vMilliSecond16MHzoscillator(5);
	MGPIO_WritePin(Lu8_LED_x_PORT, Lu8_LED_x_PIN, GPIO_LOW);
}
