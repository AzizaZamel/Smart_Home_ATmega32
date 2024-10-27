/*
 ============================================================================
 Name        : adc.h
 Author      : Aziza Zamel
 Description : Header file for the ADC driver without interrupt
 Date        : 2/10/2024
 ============================================================================
 */

#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"



/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define ADC_REF_VOLT_AREF         0
#define ADC_REF_VOLT_AVCC         1
#define ADC_REF_VOLT_INTERNAL     3

#define ADC_REF_VOLT              ADC_REF_VOLT_INTERNAL
#define ADC_REF_VOLT_VALUE        2.56
#define ADC_MAXIMUM_VALUE         1023

#define ADC_PRESCALER_8             3
#define ADC_PRESCALER_16 			4
#define ADC_PRESCALER_32 			5
#define ADC_PRESCALER_64 			6
#define ADC_PRESCALER_128			7

#define ADC_PRESCALER_VALUE  	    ADC_PRESCALER_128




/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/


/*
 * Description :
 * Function responsible for initialize the ADC driver.
 */
void ADC_init(void);

/*
 * Description :
 * Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 */
uint16 ADC_readChannel(uint8 ch_num);

#endif /* ADC_H_ */
