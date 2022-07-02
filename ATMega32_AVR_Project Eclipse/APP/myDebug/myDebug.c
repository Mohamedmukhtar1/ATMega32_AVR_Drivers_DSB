/*
 * myDebug.c
 *
 *  Created on: Jun 24, 2022
 *      Author: Eng- Mohamed Mokhtar
 */

#include "myDebug_Interface.h"

void DADC_ActiveAll_GPIO_Test(void)
{
	u8 i=0;
	u8 j=0;
	for(i=0; i<=3; i++)
	{
		for(j=0; j<=7; j++)
		{
			MGPIO_InitPinMode(i, j, GPIO_OUTPUT);
			MGPIO_WritePin(i, j, GPIO_HIGH);
		}
	}

}

void DADC_Simple_ADC_Test(u8 ADC_CHANNEL_x)
{
	HLCD_vInitiate();
	MADC_vInitiate(VOLT_AVCC_PIN);
	MADC_vSetAutoTrigeringMode(TRIGGERING_SOURCE_FREE_RUNNING_MODE);
	MADC_vChannelSelect(ADC_CHANNEL_x);
	MADC_vInterruptControl(ADC_INTERRUPT_ENABLE);

	HLCD_vGoTo(0,0);
	HLCD_vWriteString((u8*)"Hello ADC Test");

	while (1)
	{
		HLCD_vGoTo(1,0);
		HLCD_vWriteNumber(MADC_u16Read_PoolingMode());
		HLCD_vWriteString((u8*)"   ");
		HLCD_vGoTo(2,0);
		HLCD_vWriteOrignalNumber(MADC_f32MappedRead(MADC_u16Read_PoolingMode(), 5000, 10));
		HLCD_vWriteString((u8*)"   ");
		HLCD_vGoTo(3,0);
		HLCD_vWriteOrignalNumber(MADC_u16MappedRead(MADC_u16Read_PoolingMode(), 5000, 10));
		HLCD_vWriteString((u8*)"   ");
	}
}

void DKeyPad_Simple_Kepad_Test(void)
{
	HLCD_vInitiate();
	HKEYPAD_vInitiate();

	HLCD_vGoTo(0,0);
	HLCD_vWriteString((u8*)"Hello PAD Test");
	HLCD_vGoTo(1,0);

	u8 Gu8_Key = PAD_THRESHOLD;

	while (1)
	{
		Gu8_Key = HKEYPAD_u8Read();
		if (PAD_THRESHOLD != HKEYPAD_u8ReadingValidation(Gu8_Key))
		{
			if (Gu8_Key == 'C')
			{
				HLCD_vClearScreen();
			}else{	}

			//HLCD_vWriteCharacter('*');
			HLCD_vWriteCharacter(Gu8_Key);
			Gu8_Key = PAD_THRESHOLD;

		}else{	}
	}
}

void DLM35_Simple_LM35_Test(u8 ADC_CHANNEL_x)
{
	HLCD_vInitiate();
	HLM35_vInitiate(ADC_CHANNEL_x);

	HLCD_vGoTo(0,0);
	HLCD_vWriteString((u8*)"Hello LM35 Test");
	HLCD_vGoTo(1,0);

	f32 Lf32_Holder =0.0;

	while (1)
	{
		HLCD_vGoTo(1,0);

		HLCD_vWriteOrignalNumber(HLM35_u16Read_PoolingMode());
		HLCD_vWriteString((u8*)"   , ");
		Lf32_Holder = HLM35_f32Read_PoolingMode();
		if (Lf32_Holder < 5)
		{
			Lf32_Holder = AMath_f32RoundNumber(Lf32_Holder);
		}else{	}
		HLCD_vWriteOrignalNumber(Lf32_Holder);
		HLCD_vWriteString((u8*)"   ");
	}
}

void DPOT_Simple_POT_Test(u8 ADC_CHANNEL_x)
{
	HLCD_vInitiate();
	HLM35_vInitiate(ADC_CHANNEL_x);

	HLCD_vGoTo(0,0);
	HLCD_vWriteString((u8*)"Hello POT Test");
	HLCD_vGoTo(1,0);

	while (1)
	{
		HLCD_vGoTo(1,0);
		HLCD_vWriteOrignalNumber(HPOT_u16Read_PoolingMode());
		HLCD_vWriteString((u8*)"   , ");
		HLCD_vWriteOrignalNumber(HPOT_f32Read_PoolingMode());
		HLCD_vWriteString((u8*)"   ");
	}
}

