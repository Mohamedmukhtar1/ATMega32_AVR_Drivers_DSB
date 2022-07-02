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
		SIGN_BIT(REG_ADMUX.BitAccess.REFS1_Bit, LOW_BIT);
		SIGN_BIT(REG_ADMUX.BitAccess.REFS0_Bit, LOW_BIT);
		break;
	case VOLT_AVCC_PIN:	//note: Attach the AVCC pin ~ 5V, VREF pin ~ -Cap---i|
		SIGN_BIT(REG_ADMUX.BitAccess.REFS1_Bit, LOW_BIT);
		SIGN_BIT(REG_ADMUX.BitAccess.REFS0_Bit, HGH_BIT);
		break;			//note: Attach the VREF pin ~ -Cap---i|
	case VOLT_2_56_INTERNAL:
		SIGN_BIT(REG_ADMUX.BitAccess.REFS1_Bit, HGH_BIT);
		SIGN_BIT(REG_ADMUX.BitAccess.REFS0_Bit, HGH_BIT);
		break;
	default:
		break;
	}
	/***********_ADC_RESULT_ADJUST_**********************************************/
#if		RESULT_ADJUST == RIGHT_RESULT_ADJUST
	SIGN_BIT(REG_ADMUX.BitAccess.ADLAR_Bit, LOW_BIT);
	#elif	RESULT_ADJUST == LEFT_RESULT_ADJUST		//(default)
	SIGN_BIT(REG_ADMUX.BitAccess.ADLAR_Bit, HGH_BIT);
#else
#error "invalid ADC Result Adjustment"
#endif
	/***********_ADC_PRESCALER for ADCSRA Register_******************************/
#if		ADC_PRESCALER			== PRESCALER_DIV_FACTOR_2_
	SIGN_BIT(REG_ADCSRA.BitAccess.ADPS0_Bit, HGH_BIT);
	SIGN_BIT(REG_ADCSRA.BitAccess.ADPS1_Bit, LOW_BIT);
	SIGN_BIT(REG_ADCSRA.BitAccess.ADPS2_Bit, LOW_BIT);
#elif	ADC_PRESCALER			== PRESCALER_DIV_FACTOR_4_
	SIGN_BIT(REG_ADCSRA.BitAccess.ADPS0_Bit, LOW_BIT);
	SIGN_BIT(REG_ADCSRA.BitAccess.ADPS1_Bit, HGH_BIT);
	SIGN_BIT(REG_ADCSRA.BitAccess.ADPS2_Bit, LOW_BIT);
#elif	ADC_PRESCALER			== PRESCALER_DIV_FACTOR_8_
	SIGN_BIT(REG_ADCSRA.BitAccess.ADPS0_Bit, HGH_BIT);
	SIGN_BIT(REG_ADCSRA.BitAccess.ADPS1_Bit, HGH_BIT);
	SIGN_BIT(REG_ADCSRA.BitAccess.ADPS2_Bit, LOW_BIT);
#elif	ADC_PRESCALER			== PRESCALER_DIV_FACTOR_16_
	SIGN_BIT(REG_ADCSRA.BitAccess.ADPS0_Bit, LOW_BIT);
	SIGN_BIT(REG_ADCSRA.BitAccess.ADPS1_Bit, LOW_BIT);
	SIGN_BIT(REG_ADCSRA.BitAccess.ADPS2_Bit, HGH_BIT);
#elif	ADC_PRESCALER			== PRESCALER_DIV_FACTOR_32_
	SIGN_BIT(REG_ADCSRA.BitAccess.ADPS0_Bit, HGH_BIT);
	SIGN_BIT(REG_ADCSRA.BitAccess.ADPS1_Bit, LOW_BIT);
	SIGN_BIT(REG_ADCSRA.BitAccess.ADPS2_Bit, HGH_BIT);
#elif	ADC_PRESCALER			== PRESCALER_DIV_FACTOR_64_
	SIGN_BIT(REG_ADCSRA.BitAccess.ADPS0_Bit, LOW_BIT);
	SIGN_BIT(REG_ADCSRA.BitAccess.ADPS1_Bit, HGH_BIT);
	SIGN_BIT(REG_ADCSRA.BitAccess.ADPS2_Bit, HGH_BIT);
#elif	ADC_PRESCALER			== PRESCALER_DIV_FACTOR_128_
	SIGN_BIT(REG_ADCSRA.BitAccess.ADPS0_Bit, HGH_BIT);
	SIGN_BIT(REG_ADCSRA.BitAccess.ADPS1_Bit, HGH_BIT);
	SIGN_BIT(REG_ADCSRA.BitAccess.ADPS2_Bit, HGH_BIT);
#else
#error "invalid ADC Prescaler"
#endif
	/*==================_Defaults_================================================*/
	SIGN_BIT(REG_ADCSRA.BitAccess.ADATE_Bit, LOW_BIT); //ADC auto_trigering_mode_off
	SIGN_BIT(REG_ADCSRA.BitAccess.ADEN_Bit , HGH_BIT); //ADC Enable
	/*============================================================================*/
}

void MADC_vDisable(void)
{
	SIGN_BIT(REG_ADCSRA.BitAccess.ADEN_Bit, LOW_BIT); //ADC Disable
}

void MADC_vSetAutoTrigeringMode(u8 Auto_Trigering_Conversion_Config)
{
	switch (Auto_Trigering_Conversion_Config)
	{
		case TRIGGERING_DISABLE_MODE:
			//STOP Conversion
			SIGN_BIT(REG_ADCSRA.BitAccess.ADATE_Bit, LOW_BIT);
			break;
		case TRIGGERING_SOURCE_FREE_RUNNING_MODE:
			//START Conversion with free running
			SIGN_BIT(REG_ADCSRA.BitAccess.ADATE_Bit, LOW_BIT);
			SIGN_BIT(REG_SFIOR.BitAccess.ADTS2_Bit , LOW_BIT);
			SIGN_BIT(REG_SFIOR.BitAccess.ADTS1_Bit, LOW_BIT);
			SIGN_BIT(REG_SFIOR.BitAccess.ADTS0_Bit, LOW_BIT);
			SIGN_BIT(REG_ADCSRA.BitAccess.ADATE_Bit, HGH_BIT);
			break;
		case TRIGGERING_SOURCE_ANALOG_COMPARATOR:
			//START Conversion with analog comparison
			SIGN_BIT(REG_ADCSRA.BitAccess.ADATE_Bit, LOW_BIT);
			SIGN_BIT(REG_SFIOR.BitAccess.ADTS2_Bit , LOW_BIT);
			SIGN_BIT(REG_SFIOR.BitAccess.ADTS1_Bit , LOW_BIT);
			SIGN_BIT(REG_SFIOR.BitAccess.ADTS0_Bit , HGH_BIT);
			SIGN_BIT(REG_ADCSRA.BitAccess.ADATE_Bit, HGH_BIT);
			break;
		case TRIGGERING_SOURCE_EXT_INTERRUPT_0_REQUEST:
			//START Conversion with EXT0 request
			SIGN_BIT(REG_ADCSRA.BitAccess.ADATE_Bit, LOW_BIT);
			SIGN_BIT(REG_SFIOR.BitAccess.ADTS2_Bit , LOW_BIT);
			SIGN_BIT(REG_SFIOR.BitAccess.ADTS1_Bit , HGH_BIT);
			SIGN_BIT(REG_SFIOR.BitAccess.ADTS0_Bit , LOW_BIT);
			SIGN_BIT(REG_ADCSRA.BitAccess.ADATE_Bit, HGH_BIT);
			break;
		case TRIGGERING_SOURCE_TIMER_0_COMPARE_MATCH:
			//START Conversion with Timer0 CTC
			SIGN_BIT(REG_ADCSRA.BitAccess.ADATE_Bit, LOW_BIT);
			SIGN_BIT(REG_SFIOR.BitAccess.ADTS2_Bit , LOW_BIT);
			SIGN_BIT(REG_SFIOR.BitAccess.ADTS1_Bit , HGH_BIT);
			SIGN_BIT(REG_SFIOR.BitAccess.ADTS0_Bit , HGH_BIT);
			SIGN_BIT(REG_ADCSRA.BitAccess.ADATE_Bit, HGH_BIT);
			break;
		case TRIGGERING_SOURCE_TIMER_0_OVERFLOW:
			//START Conversion with Timer0 OVF
			SIGN_BIT(REG_ADCSRA.BitAccess.ADATE_Bit, LOW_BIT);
			SIGN_BIT(REG_SFIOR.BitAccess.ADTS2_Bit , HGH_BIT);
			SIGN_BIT(REG_SFIOR.BitAccess.ADTS1_Bit , LOW_BIT);
			SIGN_BIT(REG_SFIOR.BitAccess.ADTS0_Bit , LOW_BIT);
			SIGN_BIT(REG_ADCSRA.BitAccess.ADATE_Bit, HGH_BIT);
			break;
		case TRIGGERING_SOURCE_TIMER_1_COMPARE_MATCH_B:
			//START Conversion with Timer1 CTCB
			SIGN_BIT(REG_ADCSRA.BitAccess.ADATE_Bit, LOW_BIT);
			SIGN_BIT(REG_SFIOR.BitAccess.ADTS2_Bit , HGH_BIT);
			SIGN_BIT(REG_SFIOR.BitAccess.ADTS1_Bit , LOW_BIT);
			SIGN_BIT(REG_SFIOR.BitAccess.ADTS0_Bit , HGH_BIT);
			SIGN_BIT(REG_ADCSRA.BitAccess.ADATE_Bit, HGH_BIT);
			break;
		case TRIGGERING_SOURCE_TIMER_1_OVERFLOW:
			//START Conversion with Timer1 OVF
			SIGN_BIT(REG_ADCSRA.BitAccess.ADATE_Bit, LOW_BIT);
			SIGN_BIT(REG_SFIOR.BitAccess.ADTS2_Bit , HGH_BIT);
			SIGN_BIT(REG_SFIOR.BitAccess.ADTS1_Bit , HGH_BIT);
			SIGN_BIT(REG_SFIOR.BitAccess.ADTS0_Bit , LOW_BIT);
			SIGN_BIT(REG_ADCSRA.BitAccess.ADATE_Bit, HGH_BIT);
			break;
		case TRIGGERING_SOURCE_TIMER_1_CAPTURE_EVENT:
			//START Conversion with Timer1 ICU
			SIGN_BIT(REG_ADCSRA.BitAccess.ADATE_Bit, LOW_BIT);
			SIGN_BIT(REG_SFIOR.BitAccess.ADTS2_Bit , HGH_BIT);
			SIGN_BIT(REG_SFIOR.BitAccess.ADTS1_Bit , HGH_BIT);
			SIGN_BIT(REG_SFIOR.BitAccess.ADTS0_Bit , HGH_BIT);
			SIGN_BIT(REG_ADCSRA.BitAccess.ADATE_Bit, HGH_BIT);
			break;
		default:
			break;
	}
}

void MADC_vChannelSelect(u8 ADC_Channel_x_Name)
{
	REG_ADMUX.BitAccess.MUX_Bits = ADC_Channel_x_Name;
}

u16 MADC_u16Read_PoolingMode(void)
{
	/*_TO_START_CONVERSION_*/
	SIGN_BIT(REG_ADCSRA.BitAccess.ADSC_Bit, HGH_BIT);
	/*_ADC_INTERRUPT_FLAG_CHECK_*/
	while ((REG_ADCSRA.BitAccess.ADIF_Bit) != CONVERSION_UPDATE);
	return REG_ADCD.RegAccess.RegAccess;
}

u16 MADC_u16Read_OnInterrupt(void)
{
	/*_TO_START_CONVERSION_*/
	SIGN_BIT(REG_ADCSRA.BitAccess.ADSC_Bit, HGH_BIT);
	return REG_ADCD.RegAccess.RegAccess;
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
		SIGN_BIT(REG_ADCSRA.BitAccess.ADIE_Bit, HGH_BIT);
		break;
	case ADC_INTERRUPT_DISABLE:
		SIGN_BIT(REG_ADCSRA.BitAccess.ADIE_Bit, LOW_BIT);
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
