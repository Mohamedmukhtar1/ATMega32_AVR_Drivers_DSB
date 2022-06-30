/*
 * MCAL_GPIO.h
 *
 * Created: 2022-05-06 04:01:23 PM
 *  Author: Eng- Mohamed Mokhtar
 */ 

#ifndef MCAL_GPIO_H_
#define MCAL_GPIO_H_

/***************_APP_INCLUDES_*****************************/
#include "..\APP\Utility\APP_Utility.h"

/***************_MCAL_INCLUDES_****************************/
#include "MCAL_GPIO_Private.h"
#include "MCAL_GPIO_Config.h"
#include "MCAL_GPIO_Register.h"

/***************_Macros_Configuration_*********************/
#define	GPIO_INPUT		(u8)0	// For DDRx Register
#define	GPIO_OUTPUT		(u8)1	// For DDRx Register
#define	GPIO_LOW		(u8)0	// For PORTx Register
#define	GPIO_HIGH		(u8)1   // For PORTx Register
#define	INTERNAL_PULLUP_RESISTOR	(u8)0
#define	EXTERNAL_PULLUP_RESISTOR	(u8)1	

/*============================================================================
  ==================_APIs Supported by "MCAL_GPIO DRIVER"_====================
  ============================================================================*/

/***************_MCAL_GPIO.c_FUNCTION PROTOTYPE_***********/
void MGPIO_InitPinMode(u8 GPIOx, u8 GPIO_PIN_x, u8 Pin_Config_IO);
void MGPIO_DeinitPort(u8 GPIOx);

void MGPIO_WritePin(u8 GPIOx, u8 GPIO_PIN_x, u8 Pin_OP_State_HiLw);
void MGPIO_WritePort(u8 GPIOx, u8 GPIO_PortValue);
void MGPIO_TogglePin(u8 GPIOx, u8 GPIO_PIN_x);
void MGPIO_InputPinConfig(u8 GPIOx, u8 GPIO_PIN_x, u8 Pin_PullUp_Config);
	
u8 MGPIO_ReadPin(u8 GPIOx, u8 GPIO_PIN_x);
u8 MGPIO_ReadPort(u8 GPIOx);

#endif /* MCAL_GPIO_H_ */