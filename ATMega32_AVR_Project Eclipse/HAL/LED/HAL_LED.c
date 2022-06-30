/*
 * HAL_LED.c
 *
 *  Created on: May 19, 2022
 *      Author: Eng- Mohamed Mokhtar
 */

#include "HAL_LED_Interface.h"

void HLED_vInitiate(u8 Lu8_LED_x_) {
	switch (Lu8_LED_x_) {
	case LED_0_:
		MGPIO_InitPinMode(LED_0_PORT, LED_0_PIN, GPIO_OUTPUT);
		break;
	case LED_1_:
		MGPIO_InitPinMode(LED_1_PORT, LED_1_PIN, GPIO_OUTPUT);
		break;
	case LED_2_:
		MGPIO_InitPinMode(LED_2_PORT, LED_2_PIN, GPIO_OUTPUT);
		break;
	default:
		break;
	}
}

void HLED_vStateControl(u8 Lu8_LED_x_, u8 Lu8_LED_State) {
	switch (Lu8_LED_x_) {
	case LED_0_:
		MGPIO_WritePin(LED_0_PORT, LED_0_PIN, Lu8_LED_State);
		break;
	case LED_1_:
		MGPIO_WritePin(LED_1_PORT, LED_1_PIN, Lu8_LED_State);
		break;
	case LED_2_:
		MGPIO_WritePin(LED_2_PORT, LED_2_PIN, Lu8_LED_State);
		break;
	default:
		break;
	}
}

void HLED_vToggelLED(u8 Lu8_LED_x_) {
	switch (Lu8_LED_x_) {
	case LED_0_:
		MGPIO_TogglePin(LED_0_PORT, LED_0_PIN);
		break;
	case LED_1_:
		MGPIO_TogglePin(LED_1_PORT, LED_1_PIN);
		break;
	case LED_2_:
		MGPIO_TogglePin(LED_2_PORT, LED_2_PIN);
		break;
	default:
		break;
	}
}

void HLED_vBlinkLED(u8 Lu8_LED_x_) {
	switch (Lu8_LED_x_) {
	case LED_0_:
		MGPIO_WritePin(LED_0_PORT, LED_0_PIN, GPIO_HIGH);
		Delay_vMilliSecond16MHzoscillator(5);
		MGPIO_WritePin(LED_0_PORT, LED_0_PIN, GPIO_LOW);
		break;
	case LED_1_:
		MGPIO_WritePin(LED_1_PORT, LED_1_PIN, GPIO_HIGH);
		Delay_vMilliSecond16MHzoscillator(5);
		MGPIO_WritePin(LED_1_PORT, LED_1_PIN, GPIO_LOW);
		break;
	case LED_2_:
		MGPIO_WritePin(LED_2_PORT, LED_2_PIN, GPIO_HIGH);
		Delay_vMilliSecond16MHzoscillator(5);
		MGPIO_WritePin(LED_2_PORT, LED_2_PIN, GPIO_LOW);
		break;
	default:
		break;
	}
}
