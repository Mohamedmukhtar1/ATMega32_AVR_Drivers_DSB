/*
 * HAL_LM35_TempSensor_Config.h
 *
 *  Created on: Jun 23, 2022
 *      Author: Eng- Mohamed Mokhtar
 */

#ifndef HAL_LM35_TEMPSENSOR_HAL_LM35_TEMPSENSOR_CONFIG_H_
#define HAL_LM35_TEMPSENSOR_HAL_LM35_TEMPSENSOR_CONFIG_H_

#define LM35_VOLT_SOURCE			VOLT_AVCC_PIN
#define LM35_TRIGGERING_MODE		TRIGGERING_SOURCE_FREE_RUNNING_MODE
#define LM35_DEVICE_RESOLUTION		10U /*	mV/C	*/
#define LM35_DEVICE_VOLTAGE_mV		5000U

#endif /* HAL_LM35_TEMPSENSOR_HAL_LM35_TEMPSENSOR_CONFIG_H_ */

/*
 * AVCC pin must be connected to mapping voltage value == LM35_DEVICE_VOLTAGE_mV
 *
 * */