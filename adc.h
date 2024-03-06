/*
 * adc.h
 *
 *  Created on: Oct 12, 2023
 *      Author: Shorouk Shawky
 */

#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"

/*Definitions*/
#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   2.56

/* Types Declaration   */
typedef enum
{
	NO_PRE_SCALE=1,PRE_SCALE_2=1,PRE_SCALE_4,PRE_SCALE_8,PRE_SCALE_16,PRE_SCALE_32,PRE_SCALE_64,PRE_SCALE_128
}ADC_Pre_Scaler_Modes;

typedef enum {
	AREF=0, AVCC=1, INTERNAL=3
}ADC_ReferenceVolatge;
typedef struct
{
	ADC_Pre_Scaler_Modes pre_scaler;
	ADC_ReferenceVolatge ref_volt;
}ADC_ConfigType;

/* Functions Prototypes   */

/*
 * Description :
 * Function to initialize the ADC driver.
 */
void ADC_init(const ADC_ConfigType * Config_Ptr);

/*
 * Description :
 * Function that take analog data then convert it to digital.
 */
uint16 ADC_readChannel(uint8 channel_num);

#endif /* ADC_H_ */
