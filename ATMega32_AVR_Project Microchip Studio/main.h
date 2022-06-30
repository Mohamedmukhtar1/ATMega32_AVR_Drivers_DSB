/*
 * main.h
 *
 * Created: 2022-05-07 06:26:45 PM
 *  Author: Eng- Mohamed Mokhtar
 */ 

#ifndef MAIN_H_
#define MAIN_H_

/***************_APP_INCLUDES_*****************************/
#include "..\APP\Utility\APP_Utility.h"

/***************_MyApp_INCLUDES_***************************/

/***************_HAL_INCLUDES_*****************************/
#include "..\HAL\LCD\HAL_LCD_Interface.h"

/***************_MCAL_INCLUDES_****************************/
#include "..\MCAL\GPIO\MCAL_GPIO_Interface.h"
#include "..\MCAL\ADC\MCAL_ADC_Interface.h"

/***************_AVR_INCLUDES_*****************************/
#define  F_CPU 16000000UL  // 16 MHz (UL == unsigned long - [u32])
#include <util/delay.h>

/***************_main.c_FUNCTION_PROTOTYPE_****************/

#endif /* MAIN_H_ */