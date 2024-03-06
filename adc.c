/*
 * adc.c
 *
 *  Created on: Oct 12, 2023
 *      Author: Shorouk Shawky
 */
#include "adc.h"
#include "avr/io.h"
#include "common_macros.h"
void ADC_init(const ADC_ConfigType * Config_Ptr){

	ADMUX=(ADMUX & 0X3F)|(Config_Ptr->ref_volt<<6);
	ADCSRA |= (1<<ADEN);  /* enable ADC*/
	ADCSRA= (ADCSRA &0XF8) |(Config_Ptr->pre_scaler); /*set required pre_scaler*/


}

uint16 ADC_readChannel(uint8 channel_num){

	ADMUX=(ADMUX & 0xE0)|(channel_num & 0x0F);   /* Choose the correct channel by setting the channel number in MUX4:0 bits */
	SET_BIT(ADCSRA,ADSC);                       /* Start conversion write '1' to ADSC */
	while(BIT_IS_CLEAR(ADCSRA,ADIF));           /* Wait for conversion to complete, ADIF becomes '1' */
	SET_BIT(ADCSRA,ADIF);                       /* Clear ADIF by write '1' to it :) */
	return ADC;
}
