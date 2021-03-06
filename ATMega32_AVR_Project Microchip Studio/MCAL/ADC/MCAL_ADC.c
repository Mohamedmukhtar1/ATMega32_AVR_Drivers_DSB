
/*
 * MCAL_ADC.c
 *
 * Created: 2022-05-06 08:54:12 PM
 *  Author: Eng- Mohamed Mokhtar
 */ 
#include "MCAL_ADC_Interface.h"

void (*global_ptr_ADC_CallBack_Function)(void) = NULL;

void MADC_Initiate(u8 Volt_Referencex)
{
	switch(Volt_Referencex)
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
	#endif
	/*==================_Defaults_================================================*/
	CLR_BIT(REG_ADCSRA, ADCSRA_ADATE); //ADC auto_trigering_mode_off
	SET_BIT(REG_ADCSRA, ADCSRA_ADEN);  //ADC Enable
	/*============================================================================*/
}

void MADC_Disable(void)
{
	CLR_BIT(REG_ADCSRA, ADCSRA_ADEN);
}

void MADC_ChannelSelect(u8 ADC_Channel_Name)
{
	switch(ADC_Channel_Name)
	{
		case ADC_CHANNEL_0:	//PA0
		REG_ADMUX = (((ADC_CHANNEL_0)&ADMUX_WRITE_RANGE) | (REG_ADMUX & ADMUX_SAFE_RANGE));
		break;
		case ADC_CHANNEL_1:	//PA1
		REG_ADMUX = (((ADC_CHANNEL_1)&ADMUX_WRITE_RANGE) | (REG_ADMUX & ADMUX_SAFE_RANGE));
		break;
		case ADC_CHANNEL_2:	//PA2
		REG_ADMUX = (((ADC_CHANNEL_2)&ADMUX_WRITE_RANGE) | (REG_ADMUX & ADMUX_SAFE_RANGE));
		break;
		case ADC_CHANNEL_3:	//PA3
		REG_ADMUX = (((ADC_CHANNEL_3)&ADMUX_WRITE_RANGE) | (REG_ADMUX & ADMUX_SAFE_RANGE));
		break;
		case ADC_CHANNEL_4:	//PA4
		REG_ADMUX = (((ADC_CHANNEL_4)&ADMUX_WRITE_RANGE) | (REG_ADMUX & ADMUX_SAFE_RANGE));
		break;
		case ADC_CHANNEL_5:	//PA5
		REG_ADMUX = (((ADC_CHANNEL_5)&ADMUX_WRITE_RANGE) | (REG_ADMUX & ADMUX_SAFE_RANGE));
		break;
		case ADC_CHANNEL_6:	//PA6
		REG_ADMUX = (((ADC_CHANNEL_6)&ADMUX_WRITE_RANGE) | (REG_ADMUX & ADMUX_SAFE_RANGE));
		break;
		case ADC_CHANNEL_7:	//PA7
		REG_ADMUX = (((ADC_CHANNEL_7)&ADMUX_WRITE_RANGE) | (REG_ADMUX & ADMUX_SAFE_RANGE));
		break;
		default:
		break;
	}
}

void MADC_AutoTrigeringMode(u8 Auto_Trigering_Conig)
{
	switch(Auto_Trigering_Conig)
	{
		case TRIGGERING_DISABLE_MODE: //STOP Conversion
			CLR_BIT(REG_ADCSRA, ADCSRA_ADATE);
		break;
		case TRIGGERING_SOURCE_FREE_RUNNING_MODE: //START Conversion with 
			SET_BIT(REG_ADCSRA, ADCSRA_ADATE);
			CLR_BIT(REG_SFIOR, SFIOR_ADTS0);
			CLR_BIT(REG_SFIOR, SFIOR_ADTS1);
			CLR_BIT(REG_SFIOR, SFIOR_ADTS2);
		break;
		case TRIGGERING_SOURCE_ANALOG_COMPARATOR: //START Conversion with
			SET_BIT(REG_ADCSRA, ADCSRA_ADATE);
			SET_BIT(REG_SFIOR, SFIOR_ADTS0);
			CLR_BIT(REG_SFIOR, SFIOR_ADTS1);
			CLR_BIT(REG_SFIOR, SFIOR_ADTS2);
		break;
		case TRIGGERING_SOURCE_EXT_INTERRUPT_0_REQUEST: //START Conversion with
			SET_BIT(REG_ADCSRA, ADCSRA_ADATE);
			CLR_BIT(REG_SFIOR, SFIOR_ADTS0);
			SET_BIT(REG_SFIOR, SFIOR_ADTS1);
			CLR_BIT(REG_SFIOR, SFIOR_ADTS2);
		break;
		case TRIGGERING_SOURCE_TIMER_0_COMPARE_MATCH: //START Conversion with
			SET_BIT(REG_ADCSRA, ADCSRA_ADATE);
			SET_BIT(REG_SFIOR, SFIOR_ADTS0);
			SET_BIT(REG_SFIOR, SFIOR_ADTS1);
			CLR_BIT(REG_SFIOR, SFIOR_ADTS2);
		break;
		case TRIGGERING_SOURCE_TIMER_0_OVERFLOW: //START Conversion with
			SET_BIT(REG_ADCSRA, ADCSRA_ADATE);
			CLR_BIT(REG_SFIOR, SFIOR_ADTS0);
			CLR_BIT(REG_SFIOR, SFIOR_ADTS1);
			SET_BIT(REG_SFIOR, SFIOR_ADTS2);
		break;
		case TRIGGERING_SOURCE_TIMER_1_COMPARE_MATCH_B: //START Conversion with
			SET_BIT(REG_ADCSRA, ADCSRA_ADATE);
			SET_BIT(REG_SFIOR, SFIOR_ADTS0);
			CLR_BIT(REG_SFIOR, SFIOR_ADTS1);
			SET_BIT(REG_SFIOR, SFIOR_ADTS2);
		break;
		case TRIGGERING_SOURCE_TIMER_1_OVERFLOW: //START Conversion with
			SET_BIT(REG_ADCSRA, ADCSRA_ADATE);
			CLR_BIT(REG_SFIOR, SFIOR_ADTS0);
			SET_BIT(REG_SFIOR, SFIOR_ADTS1);
			SET_BIT(REG_SFIOR, SFIOR_ADTS2);
		break;
		case TRIGGERING_SOURCE_TIMER_1_CAPTURE_EVENT: //START Conversion with
			SET_BIT(REG_ADCSRA, ADCSRA_ADATE);
			SET_BIT(REG_SFIOR, SFIOR_ADTS0);
			SET_BIT(REG_SFIOR, SFIOR_ADTS1);
			SET_BIT(REG_SFIOR, SFIOR_ADTS2);
		break;
		default:
		break;
	}
}

void MADC_u16ADC_StartConversion_PoolingMode(void)
{
	/*Wait On ADC Conversion Completed Flag is set to one */
	while(GET_BIT(REG_ADCSRA, ADCSRA_ADIF) == 0);
}

u16 MADC_Read(void)
{
	SET_BIT(REG_ADCSRA, ADCSRA_ADSC);	/*_TO_START_CONVERSION_*/
	while(GET_BIT(REG_ADCSRA, ADCSRA_ADIF) != CONVERSION_UPDATE);	/*_ADC_INTERRUPT_FLAG_CHECK_*/
	#if		RESULT_ADJUST == RIGHT_RESULT_ADJUST
	return	REG_ADC_VALUE;
	#elif	RESULT_ADJUST == LEFT_RESULT_ADJUST
	return	REG_ADC_VALUE>>LEFT_ADJUST_SHIFT;
	#endif
}

f32 MADC_MappedRead(u8 loc_u8_Sensor_Resolution)
{
	SET_BIT(REG_ADCSRA, ADCSRA_ADSC);	/*_TO_START_CONVERSION_*/
	while(GET_BIT(REG_ADCSRA, ADCSRA_ADIF) != CONVERSION_UPDATE);	/*_ADC_INTERRUPT_FLAG_CHECK_*/
	/*_ADC_READ_VALUE_
	  				mVolt				Reading				 Sensor
					0					0					   --
					5000				1023			       --
					#SRD(mV)			ADCUR				(SUDEG =1)
					  --				ADCR				 SenVAL
		ADCUR = (SRD(mV)*1023)/5000
		
		SenVAL = (ADCR* SUDEG)/ADCUR	,, SUDEG = 1
			   = ADCR / ADCUR
			   = ADCR /((SRD(mV)*1023)/5000)
			   = (5000*ADCR)/(SRD(mV)*1023)) 
		
		->>> SRD:	Sensor_Resolution/Degree
						->	ADCUR:	ADC Unit Reading
						->	ADCR:	ADC Conversion Reading
						->	SUDEG:	Sensor Unit Degree	= 1
										->>> SenVAL: Sensor Value						*/
	
	f32 SENSOR_MAPPED_Read =0;   // float ,,,    casting is the float
	#if		RESULT_ADJUST == RIGHT_RESULT_ADJUST
	SENSOR_MAPPED_Read = ((f32)(REG_ADC_VALUE)*5000)/(loc_u8_Sensor_Resolution*1023);
	return	SENSOR_MAPPED_Read;
	#elif	RESULT_ADJUST == LEFT_RESULT_ADJUST
	SENSOR_MAPPED_Read = ((f32)(REG_ADC_VALUE>>LEFT_ADJUST_SHIFT)*5000)/(loc_u8_Sensor_Resolution*1023);
	return	SENSOR_MAPPED_Read;
	#endif
}
void MADC_InterruptControl(u8 Interrupt_Config)
{
	switch(Interrupt_Config)
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
void MADC_SetCallBack_exe(void(*loc_PTR_toFUNCTION)(void))
{
	global_ptr_ADC_CallBack_Function = loc_PTR_toFUNCTION;
}
ISR (ISR_ADC_vect)
{
	global_ptr_ADC_CallBack_Function();
}