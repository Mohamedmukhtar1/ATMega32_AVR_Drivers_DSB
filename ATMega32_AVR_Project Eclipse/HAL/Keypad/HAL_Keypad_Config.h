/*
 * HAL_Keypad_Config.h
 *
 *  Created on: May 30, 2022
 *      Author: Eng- Mohamed Mokhtar
 */

#ifndef SRC_HAL_KEYPAD_HAL_KEYPAD_CONFIG_H_
#define SRC_HAL_KEYPAD_HAL_KEYPAD_CONFIG_H_

#define ROW_DIMENSIONS		4
#define COL_DIMENSIONS		4

#define KEYPAD_KEYS_VALUES		{{'7','8','9','/'},\
						         {'4','5','6','x'},\
						         {'1','2','3','-'},\
						         {'C','0','=','+'}}

/***************************************************/
#define KEYPAD_ROW_PORT 	GPIOB
/*--------------------------------------*/
#define KEYPAD_R0_PIN	  	GPIO_PIN_4
#define KEYPAD_R1_PIN	  	GPIO_PIN_5
#define KEYPAD_R2_PIN	  	GPIO_PIN_6
#define KEYPAD_R3_PIN	  	GPIO_PIN_7
/***************************************************/
#define KEYPAD_COL_PORT 	GPIOD
/*--------------------------------------*/
#define KEYPAD_C0_PIN	  	GPIO_PIN_2
#define KEYPAD_C1_PIN	  	GPIO_PIN_3
#define KEYPAD_C2_PIN	  	GPIO_PIN_4
#define KEYPAD_C3_PIN	  	GPIO_PIN_5
/***************************************************/

#endif /* SRC_HAL_KEYPAD_HAL_KEYPAD_CONFIG_H_ */
