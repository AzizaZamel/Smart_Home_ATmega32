/*
 ============================================================================
 Name        : flame_sensor.c
 Author      : Aziza Zamel
 Description : Source file for the flame sensor Driver
 Date        : 5/10/2024
 ============================================================================
 */
#include "flame_sensor.h"
#include "gpio.h"



/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/


/*
 * Description :
 * Function responsible for Initialize the flame sensor pin direction.
 */
void FlameSensor_init(void){
	GPIO_setupPinDirection(FLAME_SENSOR_PORT_ID,FLAME_SENSOR_PIN_ID,PIN_INPUT);
}

/*
 * Description :
 * Function responsible for  Read the value from the flame sensor and returns it.
 */
uint8 FlameSensor_getValue(void){
	return GPIO_readPin(FLAME_SENSOR_PORT_ID,FLAME_SENSOR_PIN_ID);
}




