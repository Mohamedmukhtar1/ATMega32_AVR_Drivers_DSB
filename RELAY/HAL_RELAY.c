/*
 * HAL_RELAY.c
 *
 * Created: 2022-04-09 11:32:00 PM
 *  Author: Eng- Mohamed Mokhtar
 */ 

#include "HAL_RELAY.h"

void HAL_RELAY_INITIATE(uint8 loc_U8_RELAY_NAME)
{
	switch(loc_U8_RELAY_NAME)
	{
		case RELAY_1:
			MCAL_DIO_PIN_MODE(RELAY_1_PIN,OUTPUT_STATE);
		break;
		case RELAY_2:
			MCAL_DIO_PIN_MODE(RELAY_2_PIN,OUTPUT_STATE);
		break;
		default:
		break;
	}
}

void HAL_RELAY_ON_STATE(uint8 loc_U8_RELAY_NAME)
{
	switch(loc_U8_RELAY_NAME)
	{
		case RELAY_1:
		MCAL_DIO_PIN_WRITE(RELAY_1_PIN,HIGH_STATE);
		break;
		case RELAY_2:
		MCAL_DIO_PIN_WRITE(RELAY_2_PIN,HIGH_STATE);
		break;
		default:
		break;
	}
}

void HAL_RELAY_OFF_STATE(uint8 loc_U8_RELAY_NAME)
{
	switch(loc_U8_RELAY_NAME)
	{
		case RELAY_1:
		MCAL_DIO_PIN_WRITE(RELAY_1_PIN,LOW_STATE);
		break;
		case RELAY_2:
		MCAL_DIO_PIN_WRITE(RELAY_2_PIN,LOW_STATE);
		break;
		default:
		break;
	}
}

void HAL_RELAY_TOGGLE_STATE(uint8 loc_U8_RELAY_NAME)
{
	switch(loc_U8_RELAY_NAME)
	{
		case RELAY_1:
		MCAL_DIO_PIN_TOGGEL(RELAY_1_PIN);
		break;
		case RELAY_2:
		MCAL_DIO_PIN_TOGGEL(RELAY_2_PIN);
		break;
		default:
		break;
	}
}