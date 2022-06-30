/*
 * HAL_LM35_TempSensor.c
 *
 *  Created on: Jun 23, 2022
 *      Author: Eng- Mohamed Mokhtar
 */

#include "HAL_LM35_TempSensor_Interface.h"

void HLM35_vInitiate(u8 Lu8_ADC_Channel_x_) {
	MADC_vInitiate(LM35_VOLT_SOURCE);
	MADC_vSetAutoTrigeringMode(LM35_TRIGGERING_MODE);
	MADC_vChannelSelect(Lu8_ADC_Channel_x_);
}

u16 HLM35_u16Read_PoolingMode()
{
	return MADC_u16MappedRead(MADC_u16Read_PoolingMode(), LM35_DEVICE_VOLTAGE_mV, LM35_DEVICE_RESOLUTION);
}

u16 HLM35_u16Read_OnInterrupt()
{
	return MADC_u16MappedRead(MADC_u16Read_OnInterrupt(), LM35_DEVICE_VOLTAGE_mV, LM35_DEVICE_RESOLUTION);
}

f32 HLM35_f32Read_PoolingMode()
{
	return MADC_f32MappedRead(MADC_u16Read_PoolingMode(), LM35_DEVICE_VOLTAGE_mV, LM35_DEVICE_RESOLUTION);
}

f32 HLM35_f32Read_OnInterrupt()
{
	return MADC_f32MappedRead(MADC_u16Read_OnInterrupt(), LM35_DEVICE_VOLTAGE_mV, LM35_DEVICE_RESOLUTION);
}

