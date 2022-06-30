/*
 * MCAL_ADC_Private.h
 *
 * Created: 19-06-2022 10:30:17 PM
 *  Author: Eng- Mohamed Mokhtar
 */

#ifndef MCAL_ADC_PRIVATE_H_
#define MCAL_ADC_PRIVATE_H_

/*////////_ADC operates within a frequency range of 50kHz to 200kHz*/
#define PRESCALER_DIV_FACTOR_2_		1		// for 16 MHz/2	  = 8   MHz
#define PRESCALER_DIV_FACTOR_4_		2		// for 16 MHz/4	  = 4	MHz
#define PRESCALER_DIV_FACTOR_8_		3		// for 16 MHz/8	  = 2	MHz
#define PRESCALER_DIV_FACTOR_16_	4		// for 16 MHz/16  = 1	MHz
#define PRESCALER_DIV_FACTOR_32_	5		// for 16 MHz/32  = 500 KHz
#define PRESCALER_DIV_FACTOR_64_	6		// for 16 MHz/64  = 250 KHz
#define PRESCALER_DIV_FACTOR_128_	7		// for 16 MHz/128 = 125 KHz

#define CONVERSION_UPDATE			1

#define RIGHT_RESULT_ADJUST			1
#define LEFT_RESULT_ADJUST			2	//(default)
#define LEFT_ADJUST_SHIFT			6

#define ISR_ADC_Vector	__vector_16
void ISR_ADC_Vector(void)__attribute__((signal));

#endif /* MCAL_ADC_PRIVATE_H_ */
