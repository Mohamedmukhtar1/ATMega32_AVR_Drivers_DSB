/*
 * MCAL_ATmega32_Register_Config.h
 *
 *  Created on: Jun 30, 2022
 *      Author: Eng- Mohamed Mokhtar
 */

#ifndef MCAL_ATMEG32_REGISTERS_MCAL_ATMEGA32_REGISTER_CONFIG_H_
#define MCAL_ATMEG32_REGISTERS_MCAL_ATMEGA32_REGISTER_CONFIG_H_

#define PORTA_BaseAddress	0x3B
#define PORTB_BaseAddress	0x38
#define PORTC_BaseAddress	0x35
#define PORTD_BaseAddress	0x32

#define DDRA_BaseAddress	0x3A
#define DDRB_BaseAddress	0x37
#define DDRC_BaseAddress	0x34
#define DDRD_BaseAddress	0x31

#define PINA_BaseAddress	0x39
#define PINB_BaseAddress	0x36
#define PINC_BaseAddress	0x33
#define PIND_BaseAddress	0x30

#define ADMUX_BaseAddress	0x27	// [ADC Multiplexer Selection Register]
#define ADCSRA_BaseAddress	0x26	// [ADC Control and Status Register]
#define ADCH_BaseAddress	0x25	// [ADC DATA High Register]
#define ADCL_BaseAddress	0x24	// [ADC DATA Low Register]
#define ADCD_BaseAddress	0x24	// [ADC DATA Register]

#define MCUCR_BaseAddress	0x55	// [MCU Control Register]
#define MCUCSR_BaseAddress	0x54	// [MCU Control and Status Register]
#define GICR_BaseAddress	0x5B	// [General Interrupt Control Register]
#define GIFR_BaseAddress	0x5A	// [General Interrupt Flag Register]

#define SFIOR_BaseAddress	0x50	// [Special Function I/O Register]

#endif /* MCAL_ATMEG32_REGISTERS_MCAL_ATMEGA32_REGISTER_CONFIG_H_ */
