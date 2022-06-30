/*
 * HAL_LCD_CFG.h
 *
 * Created: 2022-04-10 02:44:09 PM
 *  Author: Eng- Mohamed Mokhtar
 */ 

#ifndef HAL_LCD_CFG_H_
#define HAL_LCD_CFG_H_

// LCD_MODE options -> [ _8_BIT_MODE , _4_BIT_MODE ]
#define LCD_MODE       _4_BIT_MODE

// LCD_DIMENSIONS options -> [ LCD_2_BY_16 , LCD_4_BY_16 ]
#define LCD_DIMENSIONS		LCD_4_BY_16

/*FLOAT_RESELUTION options:
[1]->0,						[0 point]
[10]->0.0,					[1 point]
[100]->0.00,				[2 point]
[1000]->0.000,				[3 point]
[10000]->0.0000				[4 point]
Max[100000000]->0.000000	[6 point]*/
#define FLOAT_RESELUTION		100

#define LCD_8BIT_DATA_PORT      GPIOB
#define LCD_4BIT_DATA_PORT      GPIOB

#define LCD_DATA_0_PIN     GPIO_PIN_0	//the manufacturer is using _4_BIT_MODE
#define LCD_DATA_1_PIN     GPIO_PIN_1	//the manufacturer is using _4_BIT_MODE
#define LCD_DATA_2_PIN     GPIO_PIN_2	//the manufacturer is using _4_BIT_MODE
#define LCD_DATA_3_PIN     GPIO_PIN_3	//the manufacturer is using _4_BIT_MODE

#define LCD_DATA_4_PIN	   GPIO_PIN_4
#define LCD_DATA_5_PIN	   GPIO_PIN_5
#define LCD_DATA_6_PIN	   GPIO_PIN_6
#define LCD_DATA_7_PIN     GPIO_PIN_7

#define LCD_RS_PIN         GPIO_PIN_6
#define LCD_RS_PORT        GPIOA
#define LCD_EN_PIN         GPIO_PIN_7
#define LCD_EN_PORT        GPIOA
//#define LCD_RW_PIN	   PB2    //the manufacturer is grounding the pin

#endif /* HAL_LCD_CFG_H_ */

/************	HARDWARE CFG	**************
VSS:	This is a ground pin of LCD
VDD:	This is the supply voltage pin of LCD [VCC/VDD]
VEE:	Adjusts the contrast of the LCD [VEE/Vo]	
--------------------------------------------------------------------
RS:		Register Select -> Toggles between Command/Data Register
		0 -> Command Mode		1-> Data Mode
--------------------------------------------------------------------
RW:		Read/Write	->	Toggles the LCD between Read/Write Operation
		0 -> Write Operation		1-> Read Operation
--------------------------------------------------------------------
EN:		Enable	->	Must be held high to perform Read/Write Operation
		Connected to MCU and always held high.
--------------------------------------------------------------------
Data[0]
  ...		Data/Command Pin
  ...		In 4-Wire Mode Only 4 pins (0-3) is connected to MCU
  ...		In 8-Wire Mode All 8 pins(0-7) are connected to MCU
Data[7]		
--------------------------------------------------------------------
A, LEDA:	LED Positive	-> Common Anode LED		-> Connected to +5V
K, LEDK:	LED Negative	-> Common Cathode LED	-> Connected to ground
*/