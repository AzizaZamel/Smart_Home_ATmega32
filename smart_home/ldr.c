/*
 ============================================================================
 Name        : led.c
 Author      : Aziza Zamel
 Description : Source file for the LDR sensor Driver
 Date        : 4/10/2024
 ============================================================================
 */
#include "ldr.h"
#include "adc.h"


/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/


/*
 * Description :
 * Function responsible for calculate the light intensity from the ADC digital value.
 */
uint16 LDR_getLightIntensity(void){
	uint8 intensity = 0;

	uint16 adc_value = 0;

	/* Read ADC channel where the LDR sensor is connected */
	adc_value = ADC_readChannel(LDR_SENSOR_CHANNEL_ID);

	/* Calculate the intensity from the ADC value*/
	intensity = (uint8)(((uint32)adc_value*LDR_SENSOR_MAX_LIGHT_INTENSITY*ADC_REF_VOLT_VALUE)/(ADC_MAXIMUM_VALUE*LDR_SENSOR_MAX_VOLT_VALUE));

	return intensity;
}
