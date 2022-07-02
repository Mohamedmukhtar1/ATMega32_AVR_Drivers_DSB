/*
 * MCAL_GPIO.c
 *
 * Created: 2022-05-06 04:00:46 PM
 *  Author: Eng- Mohamed Mokhtar
 */
#include "MCAL_GPIO_Interface.h"

void MGPIO_InitPinMode(u8 GPIOx, u8 GPIO_PIN_x, u8 Pin_Config_IO) {
	switch (GPIOx) {
	case GPIOA :
		REG_DDRA.RegAccess |= (Pin_Config_IO << (GPIO_PIN_x));
		break;
	case GPIOB :
		REG_DDRB.RegAccess |= (Pin_Config_IO << (GPIO_PIN_x));
		break;
	case GPIOC :
		REG_DDRC.RegAccess |= (Pin_Config_IO << (GPIO_PIN_x));
		break;
	case GPIOD :
		REG_DDRD.RegAccess |= (Pin_Config_IO << (GPIO_PIN_x));
		break;
	default: /*ERROR*/
		break;
	}
}

void MGPIO_DeinitPort(u8 GPIOx) {
	switch (GPIOx) {
	case GPIOA :
		CLR_REG(REG_DDRA.RegAccess);
		CLR_REG(REG_PORTA.RegAccess);
		break;
	case GPIOB :
		CLR_REG(REG_DDRB.RegAccess);
		CLR_REG(REG_PORTB.RegAccess);
		break;
	case GPIOC :
		CLR_REG(REG_DDRC.RegAccess);
		CLR_REG(REG_PORTC.RegAccess);
		break;
	case GPIOD :
		CLR_REG(REG_DDRD.RegAccess);
		CLR_REG(REG_PORTD.RegAccess);
		break;
	default: /*ERROR*/
		break;
	}
}

void MGPIO_WritePin(u8 GPIOx, u8 GPIO_PIN_x, u8 Pin_OP_State_HiLw) {
	switch (Pin_OP_State_HiLw) {
	case GPIO_HIGH :
		switch (GPIOx) {
		//GIVE_BIT(GPIOA_SPTR->GPIO_MODER.RegisterAccess, 2U* PinNum, (u32)DirectionMode) ; break;
		case GPIOA :
			REG_PORTA.RegAccess |= (1U << (GPIO_PIN_x));
			break;
		case GPIOB :
			REG_PORTB.RegAccess |= (1U << (GPIO_PIN_x));
			break;
		case GPIOC :
			REG_PORTC.RegAccess |= (1U << (GPIO_PIN_x));
			break;
		case GPIOD :
			REG_PORTD.RegAccess |= (1U << (GPIO_PIN_x));
			break;
		default: /*ERROR*/
			break;
		}
		break;
	case GPIO_LOW :
		switch (GPIOx) {
		//GIVE_BIT(GPIOA_SPTR->GPIO_MODER.RegisterAccess, 2U* PinNum, (u32)DirectionMode) ; break;
		case GPIOA :
			REG_PORTA.RegAccess &= ~(1U << (GPIO_PIN_x));
			break;
		case GPIOB :
			REG_PORTB.RegAccess &= ~(1U << (GPIO_PIN_x));
			break;
		case GPIOC :
			REG_PORTC.RegAccess &= ~(1U << (GPIO_PIN_x));
			break;
		case GPIOD :
			REG_PORTD.RegAccess &= ~(1U << (GPIO_PIN_x));
			break;
		default: /*ERROR*/
			break;
		}
		break;
	default: /*ERROR*/
		break;
	}
}

void MGPIO_WritePort(u8 GPIOx, u8 GPIO_PortValue) {
	switch (GPIOx) {
	//GIVE_BIT(GPIOA_SPTR->GPIO_MODER.RegisterAccess, 2U* PinNum, (u32)DirectionMode) ; break;
	case GPIOA :
		REG_PORTA.RegAccess = (GPIO_PortValue);
		break;
	case GPIOB :
		REG_PORTB.RegAccess = (GPIO_PortValue);
		break;
	case GPIOC :
		REG_PORTC.RegAccess = (GPIO_PortValue);
		break;
	case GPIOD :
		REG_PORTD.RegAccess = (GPIO_PortValue);
		break;
	default: /*ERROR*/
		break;
	}
}

u8 MGPIO_ReadPin(u8 GPIOx, u8 GPIO_PIN_x) {
	u8 loc_u8_GPIO_Pin_Reading = 0;
	switch (GPIOx) {
	case GPIOA :
		loc_u8_GPIO_Pin_Reading = GET_BIT(REG_PINA.RegAccess, GPIO_PIN_x);
		break;
	case GPIOB :
		loc_u8_GPIO_Pin_Reading = GET_BIT(REG_PINB.RegAccess, GPIO_PIN_x);
		break;
	case GPIOC :
		loc_u8_GPIO_Pin_Reading = GET_BIT(REG_PINC.RegAccess, GPIO_PIN_x);
		break;
	case GPIOD :
		loc_u8_GPIO_Pin_Reading = GET_BIT(REG_PIND.RegAccess, GPIO_PIN_x);
		break;
	default: /*ERROR*/
		break;
	}
	return loc_u8_GPIO_Pin_Reading;
}

u8 MGPIO_ReadPort(u8 GPIOx) {
	u8 loc_u8_GPIO_PORT_Reading = 0;
	switch (GPIOx) {
	case GPIOA :
		loc_u8_GPIO_PORT_Reading = GET_REG(REG_PINA.RegAccess);
		break;
	case GPIOB :
		loc_u8_GPIO_PORT_Reading = GET_REG(REG_PINB.RegAccess);
		break;
	case GPIOC :
		loc_u8_GPIO_PORT_Reading = GET_REG(REG_PINC.RegAccess);
		break;
	case GPIOD :
		loc_u8_GPIO_PORT_Reading = GET_REG(REG_PIND.RegAccess);
		break;
	default: /*ERROR*/
		break;
	}
	return loc_u8_GPIO_PORT_Reading;
}

void MGPIO_TogglePin(u8 GPIOx, u8 GPIO_PIN_x) {
	switch (GPIOx) {
	case GPIOA :
		TOG_BIT(REG_PORTA.RegAccess, GPIO_PIN_x);
		break;
	case GPIOB :
		TOG_BIT(REG_PORTB.RegAccess, GPIO_PIN_x);
		break;
	case GPIOC :
		TOG_BIT(REG_PORTC.RegAccess, GPIO_PIN_x);
		break;
	case GPIOD :
		TOG_BIT(REG_PORTD.RegAccess, GPIO_PIN_x);
		break;
	default: /*ERROR*/
		break;
	}
}

void MGPIO_InputPinConfig(u8 GPIOx, u8 GPIO_PIN_x, u8 Pin_PullUp_Config) {
	switch (Pin_PullUp_Config) {
	case INTERNAL_PULLUP_RESISTOR :
		switch (GPIOx) {
		//GIVE_BIT(GPIOA_SPTR->GPIO_MODER.RegisterAccess, 2U* PinNum, (u32)DirectionMode) ; break;
		case GPIOA :
			REG_PORTA.RegAccess |= (1U << (GPIO_PIN_x));
			break;
		case GPIOB :
			REG_PORTB.RegAccess |= (1U << (GPIO_PIN_x));
			break;
		case GPIOC :
			REG_PORTC.RegAccess |= (1U << (GPIO_PIN_x));
			break;
		case GPIOD :
			REG_PORTD.RegAccess |= (1U << (GPIO_PIN_x));
			break;
		default: /*ERROR*/
			break;
		}
		break;
	case EXTERNAL_PULLUP_RESISTOR :
		switch (GPIOx) {
		//GIVE_BIT(GPIOA_SPTR->GPIO_MODER.RegisterAccess, 2U* PinNum, (u32)DirectionMode) ; break;
		case GPIOA :
			REG_PORTA.RegAccess &= ~(1U << (GPIO_PIN_x));
			break;
		case GPIOB :
			REG_PORTB.RegAccess &= ~(1U << (GPIO_PIN_x));
			break;
		case GPIOC :
			REG_PORTC.RegAccess &= ~(1U << (GPIO_PIN_x));
			break;
		case GPIOD :
			REG_PORTD.RegAccess &= ~(1U << (GPIO_PIN_x));
			break;
		default: /*ERROR*/
			break;
		}
		break;
	default: /*ERROR*/
		break;
	}
}
