/*
 ============================================================================
 Name        : adc.c
 Author      : Aziza Zamel
 Description : Source file for the ADC driver without interrupt
 Date        : 2/10/2024
 ============================================================================
 */


#include "adc.h"
#include "common_macros.h"
#include "ATmega32_Registers.h"


/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/


/*
 * Description :
 * Function responsible for initialize the ADC driver.
 */
void ADC_init(void){
	ADMUX_REG.bits.REFS_bits = ADC_REF_VOLT;			/* select the voltage reference for the ADC */
	ADMUX_REG.bits.ADLAR_bit = LOGIC_LOW;					/* Right adjusted */
	ADCSRA_REG.bits.ADEN_bit = LOGIC_HIGH;					/* Enable the ADC */
	ADCSRA_REG.bits.ADIE_bit = LOGIC_LOW;					/* Disable ADC Interrupt */
	ADCSRA_REG.bits.ADATE_bit = LOGIC_LOW;					/* Disable Auto Trigger */
	ADCSRA_REG.bits.ADPS_bits = ADC_PRESCALER_VALUE;         /* Select ADC Prescaler */

}


/*
 * Description :
 * Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 */
uint16 ADC_readChannel(uint8 ch_num){
	ADMUX_REG.bits.MUX_bits = ch_num;						/* Selects which combination of analog inputs are connected to the ADC */
	ADCSRA_REG.bits.ADSC_bit = LOGIC_HIGH;					/* ADC start conversion */
	while(ADCSRA_REG.bits.ADIF_bit == LOGIC_LOW);			/* Wait until ADC conversion completes */
	ADCSRA_REG.bits.ADIF_bit = LOGIC_HIGH;					/* Clear ADC Interrupt Flag */
	return ADC_REG.TwoBytes;							/* Return the result from the conversion */
}














