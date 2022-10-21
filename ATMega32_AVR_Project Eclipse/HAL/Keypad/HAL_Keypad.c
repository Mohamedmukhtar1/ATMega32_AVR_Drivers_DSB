/*
 * HAL_Keypad.c
 *
 *  Created on: May 30, 2022
 *      Author: Eng- Mohamed Mokhtar
 */

#include "HAL_Keypad_Interface.h"

volatile static u8 Gu8_KeyPadARRAY[ROW_DIMENSIONS][COL_DIMENSIONS] = KEYPAD_KEYS_VALUES;

void HKEYPAD_vInitiate(void) {
	/*      _____                      _____             __ _
	 *     |  __ \                    / ____|           / _(_)
	 *     | |__) |_____      __     | |     ___  _ __ | |_ _  __ _
	 *     |  _  // _ \ \ /\ / /     | |    / _ \| '_ \|  _| |/ _` |
	 *     | | \ \ (_) \ V  V /   _  | |___| (_) | | | | | | | (_| |
	 *     |_|  \_\___/ \_/\_/   (_)  \_____\___/|_| |_|_| |_|\__, |
	 *                                                         __/ |
	 *                                                        |___/ 					*/
	MGPIO_InitPinMode(KEYPAD_ROW_PORT, KEYPAD_R0_PIN, GPIO_OUTPUT);
	MGPIO_InitPinMode(KEYPAD_ROW_PORT, KEYPAD_R1_PIN, GPIO_OUTPUT);
	MGPIO_InitPinMode(KEYPAD_ROW_PORT, KEYPAD_R2_PIN, GPIO_OUTPUT);
	MGPIO_InitPinMode(KEYPAD_ROW_PORT, KEYPAD_R3_PIN, GPIO_OUTPUT);

	MGPIO_WritePin(KEYPAD_ROW_PORT, KEYPAD_R0_PIN, GPIO_HIGH);
	MGPIO_WritePin(KEYPAD_ROW_PORT, KEYPAD_R1_PIN, GPIO_HIGH);
	MGPIO_WritePin(KEYPAD_ROW_PORT, KEYPAD_R2_PIN, GPIO_HIGH);
	MGPIO_WritePin(KEYPAD_ROW_PORT, KEYPAD_R3_PIN, GPIO_HIGH);

	/*       _____      _        _____             __ _
	 *      / ____|    | |      / ____|           / _(_)
	 *     | |     ___ | |     | |     ___  _ __ | |_ _  __ _
	 *     | |    / _ \| |     | |    / _ \| '_ \|  _| |/ _` |
	 *     | |___| (_) | |  _  | |___| (_) | | | | | | | (_| |
	 *      \_____\___/|_| (_)  \_____\___/|_| |_|_| |_|\__, |
	 *                                                   __/ |
	 *                                                  |___/ 							*/
	MGPIO_InitPinMode(KEYPAD_COL_PORT, KEYPAD_C0_PIN, GPIO_INPUT);
	MGPIO_InitPinMode(KEYPAD_COL_PORT, KEYPAD_C1_PIN, GPIO_INPUT);
	MGPIO_InitPinMode(KEYPAD_COL_PORT, KEYPAD_C2_PIN, GPIO_INPUT);
	MGPIO_InitPinMode(KEYPAD_COL_PORT, KEYPAD_C3_PIN, GPIO_INPUT);

	MGPIO_InputPinConfig(KEYPAD_COL_PORT, KEYPAD_C0_PIN, INTERNAL_PULLUP_RESISTOR);
	MGPIO_InputPinConfig(KEYPAD_COL_PORT, KEYPAD_C1_PIN, INTERNAL_PULLUP_RESISTOR);
	MGPIO_InputPinConfig(KEYPAD_COL_PORT, KEYPAD_C2_PIN, INTERNAL_PULLUP_RESISTOR);
	MGPIO_InputPinConfig(KEYPAD_COL_PORT, KEYPAD_C3_PIN, INTERNAL_PULLUP_RESISTOR);
}

u8 HKEYPAD_u8Read(void) {
	u8 Lu8_Row_Pin = KEYPAD_R0_PIN;
	u8 Lu8_Col_Pin = KEYPAD_C0_PIN;
	u8 Lu8_RC_DataReading = 0;

	for (Lu8_Row_Pin = KEYPAD_R0_PIN ; Lu8_Row_Pin <= KEYPAD_R3_PIN ; Lu8_Row_Pin++)
	{
		MGPIO_WritePin(KEYPAD_ROW_PORT, Lu8_Row_Pin, GPIO_LOW);
		for (Lu8_Col_Pin = KEYPAD_C0_PIN ; Lu8_Col_Pin <= KEYPAD_C3_PIN ; Lu8_Col_Pin++)
		{
			if (PAD_PRESSE == MGPIO_ReadPin(KEYPAD_COL_PORT, Lu8_Col_Pin))
			{
				Delay_vMilliSecond16MHzoscillator(25);
				if (PAD_PRESSE == MGPIO_ReadPin(KEYPAD_COL_PORT, Lu8_Col_Pin))
				{
					while (PAD_PRESSE == MGPIO_ReadPin(KEYPAD_COL_PORT, Lu8_Col_Pin));
					Lu8_RC_DataReading = Gu8_KeyPadARRAY[Lu8_Row_Pin-KEYPAD_R0_PIN][Lu8_Col_Pin-KEYPAD_C0_PIN];
					return Lu8_RC_DataReading;	 /*NEW Modification okokok*/
				}
				else {/*<Failed Scan after 25 mS>*/
					Lu8_RC_DataReading = PAD_THRESHOLD;
				}
			}
			else {/*<Nothing only continue Scan>*/
				Lu8_RC_DataReading = PAD_THRESHOLD;	/*NEW Modification*/
			}
		}
		MGPIO_WritePin(KEYPAD_ROW_PORT, Lu8_Row_Pin, GPIO_HIGH);
	}
	return Lu8_RC_DataReading;
}

u8 HKEYPAD_u8ReadingValidation(u8 Lu8_Reading)
{
	u8 i = 0;
	u8 j = 0;
	u8 SearchNotification = PAD_THRESHOLD;
	u8 SearchBreak =NOT_FOUND;

	if (Lu8_Reading != PAD_THRESHOLD)
	{
		for (i = 0; i < ROW_DIMENSIONS; i++)
		{
			for (j = 0; j < COL_DIMENSIONS; j++)
			{
				if (Lu8_Reading == Gu8_KeyPadARRAY[i][j])
				{
					SearchNotification = Lu8_Reading;
					SearchBreak = FOUND;
					break;
				} else{/*NOTHING*/}
			}
			if(SearchBreak == FOUND)
			{
				break;
			} else{/*NOTHING*/}
		}
	} else{/*NOTHING*/}
	return SearchNotification;
}
