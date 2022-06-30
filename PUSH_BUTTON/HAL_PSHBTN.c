/*
 * HAL_PSHBTN.c
 *
 * Created: 2022-04-09 09:34:14 PM
 *  Author: Eng- Mohamed Mokhtar
 */ 

#include "HAL_PSHBTN.h"

void HAL_PUSHBUTTON_INITIATE(uint8 loc_U8_PUSHBUTTON_NAME)
{	
	switch(loc_U8_PUSHBUTTON_NAME)
	{
		case PUSH_BUTTON_1_:
			MCAL_DIO_PIN_MODE(PUSH_BUTTON_1_PIN,INPUT_STATE);
		break;
		case PUSH_BUTTON_2_:
			MCAL_DIO_PIN_MODE(PUSH_BUTTON_2_PIN,INPUT_STATE);
		break;
		case PUSH_BUTTON_3_:
			MCAL_DIO_PIN_MODE(PUSH_BUTTON_3_PIN,INPUT_STATE);
		break;
		case PUSH_BUTTON_4_:
			MCAL_DIO_PIN_MODE(PUSH_BUTTON_4_PIN,INPUT_STATE);
		break;
		default:
		break;
	}
}

uint8 HAL_PUSHBUTTON_U8_READ(uint8 loc_U8_PUSHBUTTON_NAME)
{
	uint8 loc_U8_PUSHBUTTON_PIN_Reading = 0;
	switch(loc_U8_PUSHBUTTON_NAME)
	{
		case PUSH_BUTTON_1_:
			loc_U8_PUSHBUTTON_PIN_Reading = MCAL_DIO_U8_PIN_READ(PUSH_BUTTON_1_PIN);
		break;
		case PUSH_BUTTON_2_:
			loc_U8_PUSHBUTTON_PIN_Reading = MCAL_DIO_U8_PIN_READ(PUSH_BUTTON_2_PIN);
		break;
		case PUSH_BUTTON_3_:
			loc_U8_PUSHBUTTON_PIN_Reading = MCAL_DIO_U8_PIN_READ(PUSH_BUTTON_3_PIN);
		break;
		case PUSH_BUTTON_4_:
			loc_U8_PUSHBUTTON_PIN_Reading = MCAL_DIO_U8_PIN_READ(PUSH_BUTTON_4_PIN);
		break;
		default:
		break;
	}
	return loc_U8_PUSHBUTTON_PIN_Reading;
}