/*
 * MCAL_GPIO.c
 *
 * Created: 2022-05-06 04:00:46 PM
 *  Author: Eng- Mohamed Mokhtar
 */ 
#include "MCAL_GPIO_Interface.h"

void MGPIO_InitPinMode(u8 GPIOx, u8 GPIO_PIN_x, u8 Pin_Config_IO)
{
	switch(GPIOx)
	{
		case GPIOA : REG_DDRA |= (Pin_Config_IO<<(GPIO_PIN_x)); break;
		case GPIOB : REG_DDRB |= (Pin_Config_IO<<(GPIO_PIN_x)); break;
		case GPIOC : REG_DDRC |= (Pin_Config_IO<<(GPIO_PIN_x)); break;
		case GPIOD : REG_DDRD |= (Pin_Config_IO<<(GPIO_PIN_x)); break;
		default : /*ERROR*/ break;
	}
}

void MGPIO_DeinitPort(u8 GPIOx)
{
	switch (GPIOx)
	{
		case GPIOA: CLR_REG(REG_DDRA); CLR_REG(REG_PORTA); break;
		case GPIOB: CLR_REG(REG_DDRB); CLR_REG(REG_PORTB); break;
		case GPIOC: CLR_REG(REG_DDRC); CLR_REG(REG_PORTC); break;
		case GPIOD: CLR_REG(REG_DDRD); CLR_REG(REG_PORTD); break;
		default : /*ERROR*/ break ;
	}
}

void MGPIO_WritePin(u8 GPIOx, u8 GPIO_PIN_x, u8 Pin_OP_State_HiLw)
{
	switch(Pin_OP_State_HiLw)
	{
		case GPIO_HIGH:
			switch(GPIOx)
			{
				//GIVE_BIT(GPIOA_SPTR->GPIO_MODER.RegisterAccess, 2U* PinNum, (u32)DirectionMode) ; break;
				case GPIOA : REG_PORTA |= (1U <<(GPIO_PIN_x)) ; break;
				case GPIOB : REG_PORTB |= (1U <<(GPIO_PIN_x)) ; break;
				case GPIOC : REG_PORTC |= (1U <<(GPIO_PIN_x)) ; break;
				case GPIOD : REG_PORTD |= (1U <<(GPIO_PIN_x)) ; break;
				default : /*ERROR*/ break ;
			}
		break ;
		case GPIO_LOW:
			switch(GPIOx)
			{
				//GIVE_BIT(GPIOA_SPTR->GPIO_MODER.RegisterAccess, 2U* PinNum, (u32)DirectionMode) ; break;
				case GPIOA : REG_PORTA &=~ (1U <<(GPIO_PIN_x)) ; break;
				case GPIOB : REG_PORTB &=~ (1U <<(GPIO_PIN_x)) ; break;
				case GPIOC : REG_PORTC &=~ (1U <<(GPIO_PIN_x)) ; break;
				case GPIOD : REG_PORTD &=~ (1U <<(GPIO_PIN_x)) ; break;
				default : /*ERROR*/ break ;
			}
		break ;
		default : /*ERROR*/ break ;
	}
	
}

void MGPIO_WritePort(u8 GPIOx, u8 GPIO_PortValue)
{
	switch(GPIOx)
	{
		//GIVE_BIT(GPIOA_SPTR->GPIO_MODER.RegisterAccess, 2U* PinNum, (u32)DirectionMode) ; break;
		case GPIOA : REG_PORTA = (GPIO_PortValue) ; break;
		case GPIOB : REG_PORTB = (GPIO_PortValue) ; break;
		case GPIOC : REG_PORTC = (GPIO_PortValue) ; break;
		case GPIOD : REG_PORTD = (GPIO_PortValue) ; break;
		default : /*ERROR*/ break ;
	}
}

u8 MGPIO_ReadPin(u8 GPIOx, u8 GPIO_PIN_x)
{
	u8 loc_u8_GPIO_Pin_Reading =0;
	switch(GPIOx)
	{
		case GPIOA :loc_u8_GPIO_Pin_Reading = GET_BIT( REG_PINA, GPIO_PIN_x ) ; break;
		case GPIOB :loc_u8_GPIO_Pin_Reading = GET_BIT( REG_PINB, GPIO_PIN_x ) ; break;
		case GPIOC :loc_u8_GPIO_Pin_Reading = GET_BIT( REG_PINC, GPIO_PIN_x ) ; break;
		case GPIOD :loc_u8_GPIO_Pin_Reading = GET_BIT( REG_PIND, GPIO_PIN_x ) ; break;
		default : /*ERROR*/ break ;
	}
	return loc_u8_GPIO_Pin_Reading;
}

u8 MGPIO_ReadPort(u8 GPIOx)
{
	u8 loc_u8_GPIO_PORT_Reading =0;
	switch(GPIOx)
	{
		case GPIOA :loc_u8_GPIO_PORT_Reading = GET_REG( REG_PINA ); break;
		case GPIOB :loc_u8_GPIO_PORT_Reading = GET_REG( REG_PINB ); break;
		case GPIOC :loc_u8_GPIO_PORT_Reading = GET_REG( REG_PINC ); break;
		case GPIOD :loc_u8_GPIO_PORT_Reading = GET_REG( REG_PIND ); break;
		default : /*ERROR*/ break ;
	}
	return loc_u8_GPIO_PORT_Reading;
}

void MGPIO_TogglePin(u8 GPIOx, u8 GPIO_PIN_x)
{
	switch(GPIOx)
	{
		case GPIOA : TOG_BIT(REG_PORTA, GPIO_PIN_x); break;
		case GPIOB : TOG_BIT(REG_PORTB, GPIO_PIN_x); break;
		case GPIOC : TOG_BIT(REG_PORTC, GPIO_PIN_x); break;
		case GPIOD : TOG_BIT(REG_PORTD, GPIO_PIN_x); break;
		default : /*ERROR*/ break ;
	}
}

void MGPIO_InputPinConfig(u8 GPIOx, u8 GPIO_PIN_x, u8 Pin_PullUp_Config)
{
	switch(GPIOx)
	{
		case GPIOA : REG_PORTA |= (Pin_PullUp_Config<<(GPIO_PIN_x)); break;
		case GPIOB : REG_PORTB |= (Pin_PullUp_Config<<(GPIO_PIN_x)); break;
		case GPIOC : REG_PORTC |= (Pin_PullUp_Config<<(GPIO_PIN_x)); break;
		case GPIOD : REG_PORTD |= (Pin_PullUp_Config<<(GPIO_PIN_x)); break;
		default : /*ERROR*/ break ;
	}
}