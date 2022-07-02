/*
 * MCAL_GPIO.h
 *
 * Created: 2022-05-06 04:01:23 PM
 *  Author: Eng- Mohamed Mokhtar
 */

#ifndef MCAL_GPIO_H_
#define MCAL_GPIO_H_

/***************_APP_INCLUDES_*****************************/
#include "../../APP/Utility/APP_Utility.h"

/***************_MCAL_INCLUDES_****************************/
#include "MCAL_GPIO_Private.h"
#include "MCAL_GPIO_Config.h"
#include "../../MCAL/ATmeg32_Registers/MCAL_ATmega32_Register.h"

/***************_Macros_Configuration_*********************/
/****** GPIO_Port_____________________*********************/
#define	GPIOA        0U
#define	GPIOB        1U
#define	GPIOC        2U
#define	GPIOD        3U
/****** GPIO_Pin______________________*********************/
#define	GPIO_PIN_0	 0U
#define	GPIO_PIN_1	 1U
#define	GPIO_PIN_2	 2U
#define	GPIO_PIN_3	 3U
#define	GPIO_PIN_4	 4U
#define	GPIO_PIN_5	 5U
#define	GPIO_PIN_6	 6U
#define	GPIO_PIN_7	 7U
/****** Pins_States___________________*********************/
#define	GPIO_INPUT	 0U
#define	GPIO_OUTPUT	 1U
#define	GPIO_LOW	 0U
#define	GPIO_HIGH	 1U
/****** Input_Pins_Config_____________*********************/
#define	INTERNAL_PULLUP_RESISTOR	0U
#define	EXTERNAL_PULLUP_RESISTOR	1U

/*===========================================================================
 ==================_APIs Supported by "MCAL_GPIO DRIVER"_====================
 ============================================================================*/
void MGPIO_InitPinMode(u8 GPIOx, u8 GPIO_PIN_x, u8 Pin_Config_IO);
void MGPIO_DeinitPort(u8 GPIOx);

void MGPIO_WritePin(u8 GPIOx, u8 GPIO_PIN_x, u8 Pin_OP_State_HiLw);
void MGPIO_WritePort(u8 GPIOx, u8 GPIO_PortValue);
void MGPIO_TogglePin(u8 GPIOx, u8 GPIO_PIN_x);
void MGPIO_InputPinConfig(u8 GPIOx, u8 GPIO_PIN_x, u8 Pin_PullUp_Config);

u8 MGPIO_ReadPin(u8 GPIOx, u8 GPIO_PIN_x);
u8 MGPIO_ReadPort(u8 GPIOx);

#endif /* MCAL_GPIO_H_ */
