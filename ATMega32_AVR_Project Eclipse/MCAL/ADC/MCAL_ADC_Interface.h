/*
 * MCAL_ADC.h
 *
 * Created: 2022-05-06 08:54:20 PM
 *  Author: Eng- Mohamed Mokhtar
 */

#ifndef MCAL_ADC_H_
#define MCAL_ADC_H_

/***************_APP_INCLUDES_*****************************/
#include "../../APP/Utility/APP_Utility.h"

/***************_MCAL_INCLUDES_****************************/
#include "MCAL_ADC_Private.h"
#include "MCAL_ADC_Config.h"
#include "MCAL_ADC_Register.h"

/***************_Macros_Configuration_*********************/
/****** Voltage Source___________________******************/
#define VOLT_AVCC_PIN				1U
#define VOLT_AREF_PIN				2U
#define VOLT_2_56_INTERNAL			3U
/****** Interrupt Control___________________***************/
#define ADC_INTERRUPT_ENABLE		1U
#define ADC_INTERRUPT_DISABLE		2U
/****** Channel Select___________________******************/
#define ADC_CHANNEL_0		0U	/// PA0 (default)
#define ADC_CHANNEL_1		1U	/// PA1
#define ADC_CHANNEL_2		2U   /// PA2
#define ADC_CHANNEL_3		3U   /// PA3
#define ADC_CHANNEL_4		4U   /// PA4
#define ADC_CHANNEL_5		5U   /// PA5
#define ADC_CHANNEL_6		6U   /// PA6
#define ADC_CHANNEL_7		7U   /// PA7
/****** Conversion Triggering Source ___________________***/
#define TRIGGERING_DISABLE_MODE								0U
#define TRIGGERING_SOURCE_FREE_RUNNING_MODE					1U
#define TRIGGERING_SOURCE_ANALOG_COMPARATOR					2U
#define TRIGGERING_SOURCE_EXT_INTERRUPT_0_REQUEST			3U
#define TRIGGERING_SOURCE_TIMER_0_COMPARE_MATCH				4U
#define TRIGGERING_SOURCE_TIMER_0_OVERFLOW					5U
#define TRIGGERING_SOURCE_TIMER_1_COMPARE_MATCH_B			6U
#define TRIGGERING_SOURCE_TIMER_1_OVERFLOW					7U
#define TRIGGERING_SOURCE_TIMER_1_CAPTURE_EVENT				8U

/*============================================================================
  ==================_APIs Supported by "MCAL_ADC DRIVER"_=====================
  ============================================================================*/

void MADC_vInitiate(u8 Volt_Referencex);
void MADC_vDisable(void);
void MADC_vSetAutoTrigeringMode(u8 Auto_Trigering_Conversion_Config);
void MADC_vChannelSelect(u8 ADC_Channel_Name);

u16 MADC_u16Read_PoolingMode(void);
u16 MADC_u16Read_OnInterrupt(void);

f32 MADC_f32MappedRead(u16 Lu8_ADC_Conversion_Read, u16 Lu16_DeviceVolt, u8 Lu8_DeviceResolution) ;
u16 MADC_u16MappedRead(u16 Lu8_ADC_Conversion_Read, u16 Lu16_DeviceVolt, u8 Lu8_DeviceResolution);

void MADC_vInterruptControl(u8 Interrupt_Config);
void MADC_vSetCallBack_Execution(void (*LPtr_toFUNCTION)(void));

#endif /* MCAL_ADC_H_ */
