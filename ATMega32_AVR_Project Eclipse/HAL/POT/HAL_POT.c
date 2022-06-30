/*
 * HAL_POT.c
 *
 *  Created on: Jun 23, 2022
 *      Author: Eng- Mohamed Mokhtar
 */

#include "HAL_POT_Interface.h"

void HPOT_vInitiate(u8 Lu8_ADC_Channel_x_)
{
	MADC_vInitiate(POT_VOLT_SOURCE);
	MADC_vSetAutoTrigeringMode(POT_TRIGGERING_MODE);
	MADC_vChannelSelect(Lu8_ADC_Channel_x_);
}

u16 HPOT_u16Read_PoolingMode()
{
	return MADC_u16MappedRead(MADC_u16Read_PoolingMode(), POT_DEVICE_VOLTAGE_mV, POT_DEVICE_RESOLUTION);
}

u16 HPOT_u16Read_OnInterrupt()
{
	return MADC_u16MappedRead(MADC_u16Read_OnInterrupt(), POT_DEVICE_VOLTAGE_mV, POT_DEVICE_RESOLUTION);
}

f32 HPOT_f32Read_PoolingMode()
{
	return MADC_f32MappedRead(MADC_u16Read_PoolingMode(), POT_DEVICE_VOLTAGE_mV, POT_DEVICE_RESOLUTION);
}

f32 HPOT_f32Read_OnInterrupt()
{
	return MADC_f32MappedRead(MADC_u16Read_OnInterrupt(), POT_DEVICE_VOLTAGE_mV, POT_DEVICE_RESOLUTION);
}

