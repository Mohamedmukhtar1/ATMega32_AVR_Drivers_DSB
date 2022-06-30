/*
 * MCAL_ADC.h
 *
 * Created: 2022-05-06 08:54:20 PM
 *  Author: Eng- Mohamed Mokhtar
 */ 

#ifndef MCAL_ADC_H_
#define MCAL_ADC_H_

/***************_APP_INCLUDES_*****************************/
#include "..\APP\Utility\APP_Utility.h"

/***************_MCAL_INCLUDES_****************************/
#include "MCAL_ADC_Private.h"
#include "MCAL_ADC_Config.h"
#include "MCAL_ADC_Register.h"

/***************_AVR_INCLUDES_*****************************/
#include <avr/interrupt.h>

/***************_Macros_Configuration_*********************/
#define VOLT_AVCC_PIN				1
#define VOLT_AREF_PIN				2
#define VOLT_2_56_INTERNAL			3
	
#define ADC_INTERRUPT_ENABLE		1
#define ADC_INTERRUPT_DISABLE		2
#define	ISR_ADC_vect			_VECTOR(16)

#define ADC_CHANNEL_0		(u8)0	//(default)
#define ADC_CHANNEL_1		(u8)1
#define ADC_CHANNEL_2		(u8)2
#define ADC_CHANNEL_3		(u8)3
#define ADC_CHANNEL_4		(u8)4
#define ADC_CHANNEL_5		(u8)5
#define ADC_CHANNEL_6		(u8)6
#define ADC_CHANNEL_7		(u8)7

#define  TRIGGERING_DISABLE_MODE								0
#define  TRIGGERING_SOURCE_FREE_RUNNING_MODE					1
#define  TRIGGERING_SOURCE_ANALOG_COMPARATOR					2
#define  TRIGGERING_SOURCE_EXT_INTERRUPT_0_REQUEST				3
#define  TRIGGERING_SOURCE_TIMER_0_COMPARE_MATCH				4
#define  TRIGGERING_SOURCE_TIMER_0_OVERFLOW						5
#define  TRIGGERING_SOURCE_TIMER_1_COMPARE_MATCH_B				6
#define  TRIGGERING_SOURCE_TIMER_1_OVERFLOW						7
#define  TRIGGERING_SOURCE_TIMER_1_CAPTURE_EVENT				8

/***************_MCAL_ADC.c_FUNCTION_PROTOTYPE_************/
void MADC_Initiate(u8 Volt_Referencex);
void MADC_Disable(void);

void MADC_ChannelSelect(u8 ADC_Channel_Name);
void MADC_AutoTrigeringMode(u8 Auto_Trigering_Conig);
void MADC_u16ADC_StartConversion_PoolingMode(void);

u16 MADC_Read(void);
f32 MADC_MappedRead(u8 loc_u8_Sensor_Resolution);

void MADC_InterruptControl(u8 Interrupt_Config);
void MADC_SetCallBack_exe(void(*loc_PTR_toFUNCTION)(void));
//ISR (ISR_ADC_VECTOR);

#endif /* MCAL_ADC_H_ */