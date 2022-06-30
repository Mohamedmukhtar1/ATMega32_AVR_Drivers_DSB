/*
 * MCAL_ADC.c
 *
 * Created: 2022-05-06 08:54:12 PM
 *  Author: Eng- Mohamed Mokhtar
 */

#include "MCAL_ADC_Interface.h"

void (*GPtr_ADC_CallBack_Fun)(void) = NULL;

void MADC_vInitiate(u8 Volt_Referencex)
{
	switch (Volt_Referencex)
	{
	case VOLT_AREF_PIN:	//note: Internal 2.56 turned off
		CLR_BIT(REG_ADMUX, ADMUX_REFS1);
		CLR_BIT(REG_ADMUX, ADMUX_REFS1);
		break;
	case VOLT_AVCC_PIN:	//note: Attach the AVCC pin ~ 5V, VREF pin ~ -Cap---i|
		SET_BIT(REG_ADMUX, ADMUX_REFS0);
		CLR_BIT(REG_ADMUX, ADMUX_REFS1);
		break;			//note: Attach the VREF pin ~ -Cap---i|
	case VOLT_2_56_INTERNAL:
		SET_BIT(REG_ADMUX, ADMUX_REFS0);
		SET_BIT(REG_ADMUX, ADMUX_REFS1);
		break;
	default:
		break;
	}
	/***********_ADC_RESULT_ADJUST_**********************************************/
#if		RESULT_ADJUST == RIGHT_RESULT_ADJUST
	CLR_BIT(REG_ADMUX, ADMUX_ADLAR);
#elif	RESULT_ADJUST == LEFT_RESULT_ADJUST		//(default)
	SET_BIT(REG_ADMUX, ADMUX_ADLAR);
#else
#error "invalid ADC Result Adjustment"
#endif
	/***********_ADC_PRESCALER for ADCSRA Register_******************************/
#if		ADC_PRESCALER			== PRESCALER_DIV_FACTOR_2_
	SET_BIT(REG_ADCSRA, ADCSRA_ADPS0);
	CLR_BIT(REG_ADCSRA, ADCSRA_ADPS1);
	CLR_BIT(REG_ADCSRA, ADCSRA_ADPS2);
#elif	ADC_PRESCALER			== PRESCALER_DIV_FACTOR_4_
	CLR_BIT(REG_ADCSRA, ADCSRA_ADPS0);
	SET_BIT(REG_ADCSRA, ADCSRA_ADPS1);
	CLR_BIT(REG_ADCSRA, ADCSRA_ADPS2);
#elif	ADC_PRESCALER			== PRESCALER_DIV_FACTOR_8_
	SET_BIT(REG_ADCSRA, ADCSRA_ADPS0);
	SET_BIT(REG_ADCSRA, ADCSRA_ADPS1);
	CLR_BIT(REG_ADCSRA, ADCSRA_ADPS2);
#elif	ADC_PRESCALER			== PRESCALER_DIV_FACTOR_16_
	CLR_BIT(REG_ADCSRA, ADCSRA_ADPS0);
	CLR_BIT(REG_ADCSRA, ADCSRA_ADPS1);
	SET_BIT(REG_ADCSRA, ADCSRA_ADPS2);
#elif	ADC_PRESCALER			== PRESCALER_DIV_FACTOR_32_
	SET_BIT(REG_ADCSRA, ADCSRA_ADPS0);
	CLR_BIT(REG_ADCSRA, ADCSRA_ADPS1);
	SET_BIT(REG_ADCSRA, ADCSRA_ADPS2);
#elif	ADC_PRESCALER			== PRESCALER_DIV_FACTOR_64_
	CLR_BIT(REG_ADCSRA, ADCSRA_ADPS0);
	SET_BIT(REG_ADCSRA, ADCSRA_ADPS1);
	SET_BIT(REG_ADCSRA, ADCSRA_ADPS2);
#elif	ADC_PRESCALER			== PRESCALER_DIV_FACTOR_128_
	SET_BIT(REG_ADCSRA, ADCSRA_ADPS0);
	SET_BIT(REG_ADCSRA, ADCSRA_ADPS1);
	SET_BIT(REG_ADCSRA, ADCSRA_ADPS2);
#else
#error "invalid ADC Prescaler"
#endif
	/*==================_Defaults_================================================*/
	CLR_BIT(REG_ADCSRA, ADCSRA_ADATE); //ADC auto_trigering_mode_off
	SET_BIT(REG_ADCSRA, ADCSRA_ADEN);  //ADC Enable
	/*============================================================================*/
}

void MADC_vDisable(void)
{
	CLR_BIT(REG_ADCSRA, ADCSRA_ADEN);
}

void MADC_vSetAutoTrigeringMode(u8 Auto_Trigering_Conversion_Config)
{
	switch (Auto_Trigering_Conversion_Config)
	{
		case TRIGGERING_DISABLE_MODE:
			//STOP Conversion
			CLR_BIT(REG_ADCSRA, ADCSRA_ADATE);
			break;
		case TRIGGERING_SOURCE_FREE_RUNNING_MODE:
			//START Conversion with free running
			SET_BIT(REG_ADCSRA, ADCSRA_ADATE);
			CLR_BIT(REG_SFIOR, SFIOR_ADTS0);
			CLR_BIT(REG_SFIOR, SFIOR_ADTS1);
			CLR_BIT(REG_SFIOR, SFIOR_ADTS2);
			break;
		case TRIGGERING_SOURCE_ANALOG_COMPARATOR:
			//START Conversion with analog comparison
			SET_BIT(REG_ADCSRA, ADCSRA_ADATE);
			SET_BIT(REG_SFIOR, SFIOR_ADTS0);
			CLR_BIT(REG_SFIOR, SFIOR_ADTS1);
			CLR_BIT(REG_SFIOR, SFIOR_ADTS2);
			break;
		case TRIGGERING_SOURCE_EXT_INTERRUPT_0_REQUEST:
			//START Conversion with EXT0 request
			SET_BIT(REG_ADCSRA, ADCSRA_ADATE);
			CLR_BIT(REG_SFIOR, SFIOR_ADTS0);
			SET_BIT(REG_SFIOR, SFIOR_ADTS1);
			CLR_BIT(REG_SFIOR, SFIOR_ADTS2);
			break;
		case TRIGGERING_SOURCE_TIMER_0_COMPARE_MATCH:
			//START Conversion with Timer0 CTC
			SET_BIT(REG_ADCSRA, ADCSRA_ADATE);
			SET_BIT(REG_SFIOR, SFIOR_ADTS0);
			SET_BIT(REG_SFIOR, SFIOR_ADTS1);
			CLR_BIT(REG_SFIOR, SFIOR_ADTS2);
			break;
		case TRIGGERING_SOURCE_TIMER_0_OVERFLOW:
			//START Conversion with Timer0 OVF
			SET_BIT(REG_ADCSRA, ADCSRA_ADATE);
			CLR_BIT(REG_SFIOR, SFIOR_ADTS0);
			CLR_BIT(REG_SFIOR, SFIOR_ADTS1);
			SET_BIT(REG_SFIOR, SFIOR_ADTS2);
			break;
		case TRIGGERING_SOURCE_TIMER_1_COMPARE_MATCH_B:
			//START Conversion with Timer1 CTCB
			SET_BIT(REG_ADCSRA, ADCSRA_ADATE);
			SET_BIT(REG_SFIOR, SFIOR_ADTS0);
			CLR_BIT(REG_SFIOR, SFIOR_ADTS1);
			SET_BIT(REG_SFIOR, SFIOR_ADTS2);
			break;
		case TRIGGERING_SOURCE_TIMER_1_OVERFLOW:
			//START Conversion with Timer1 OVF
			SET_BIT(REG_ADCSRA, ADCSRA_ADATE);
			CLR_BIT(REG_SFIOR, SFIOR_ADTS0);
			SET_BIT(REG_SFIOR, SFIOR_ADTS1);
			SET_BIT(REG_SFIOR, SFIOR_ADTS2);
			break;
		case TRIGGERING_SOURCE_TIMER_1_CAPTURE_EVENT:
			//START Conversion with Timer1 ICU
			SET_BIT(REG_ADCSRA, ADCSRA_ADATE);
			SET_BIT(REG_SFIOR, SFIOR_ADTS0);
			SET_BIT(REG_SFIOR, SFIOR_ADTS1);
			SET_BIT(REG_SFIOR, SFIOR_ADTS2);
			break;
		default:
			break;
	}
}

void MADC_vChannelSelect(u8 ADC_Channel_x_Name)
{
	REG_ADMUX = (((ADC_Channel_x_Name) & ADMUX_WRITE_RANGE) | (REG_ADMUX & ADMUX_SAFE_RANGE));
}

u16 MADC_u16Read_PoolingMode(void)
{
	/*_TO_START_CONVERSION_*/
	SET_BIT(REG_ADCSRA, ADCSRA_ADSC);
	/*_ADC_INTERRUPT_FLAG_CHECK_*/
	while (GET_BIT(REG_ADCSRA, ADCSRA_ADIF) != CONVERSION_UPDATE);
	return REG_ADC_VALUE;
}

u16 MADC_u16Read_OnInterrupt(void)
{
	/*_TO_START_CONVERSION_*/
	SET_BIT(REG_ADCSRA, ADCSRA_ADSC);
	return REG_ADC_VALUE;
}

f32 MADC_f32MappedRead(u16 Lu8_ADC_Conversion_Read, u16 Lu16_DeviceVolt, u8 Lu8_DeviceResolution)
{
	/*			_ADC_READ_VALUE_
	 mVolt				Reading				 Sensor
	 0					0					   --
	 5000 (mV)			1023			       --
	 InputVolt(mV)		ADC_Conversion		DeviceResolution (mV/Unite)
	 --					--					SensorReading

	 InputVolt(mV) = (ADC_Conversion*5000)/1023

	 SensorReading = (InputVolt(mV))/(DeviceResolution)
	 = ((ADC_Conversion*5000)/1023)/(DeviceResolution)
	 = ((ADC_Conversion*5000)/1023) * (1/(DeviceResolution))
	 = ((ADC_Conversion*5000)/(1023*DeviceResolution))
	 = ADC_Conversion*((5000)/(1023*DeviceResolution))							*/

	f32 SENSOR_MAPPED_Read = 0.0;
	SENSOR_MAPPED_Read = (Lu8_ADC_Conversion_Read)*((f32)(Lu16_DeviceVolt)/(Lu8_DeviceResolution * 1023));
	return SENSOR_MAPPED_Read;
}

u16 MADC_u16MappedRead(u16 Lu8_ADC_Conversion_Read, u16 Lu16_DeviceVolt, u8 Lu8_DeviceResolution)
{
	u16 SENSOR_MAPPED_Read = 0;
	SENSOR_MAPPED_Read = (Lu8_ADC_Conversion_Read)*((f32)(Lu16_DeviceVolt)/(Lu8_DeviceResolution * 1023));
	return SENSOR_MAPPED_Read;
}

void MADC_vInterruptControl(u8 Interrupt_Config)
{
	switch (Interrupt_Config)
	{
	case ADC_INTERRUPT_ENABLE:
		SET_BIT(REG_ADCSRA, ADCSRA_ADIE);
		break;
	case ADC_INTERRUPT_DISABLE:
		CLR_BIT(REG_ADCSRA, ADCSRA_ADIE);
		break;
	default:
		break;
	}
}
void MADC_vSetCallBack_Execution(void (*LPtr_toFUNCTION)(void))
{
	GPtr_ADC_CallBack_Fun = LPtr_toFUNCTION;
}
void ISR_ADC_Vector(void)
{
	GPtr_ADC_CallBack_Fun();
}
