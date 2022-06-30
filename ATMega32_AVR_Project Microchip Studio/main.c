/*
 * ATMega32_AVR_Project.c
 *
 * Created: 2022-05-06 03:25:40 PM
 * Author : Eng- Mohamed Mokhtar
 */ 
#include "main.h"
int main(void)
{
	HLCD_vInitiate();
	MADC_Initiate(VOLT_AVCC_PIN);
	MADC_ChannelSelect(ADC_CHANNEL_0);
	MADC_AutoTrigeringMode(TRIGGERING_SOURCE_FREE_RUNNING_MODE);
	MADC_InterruptControl(ADC_INTERRUPT_ENABLE);
	
    while (1) 
    {
		
    }
}

