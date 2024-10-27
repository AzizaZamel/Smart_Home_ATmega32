/*
 ============================================================================
 Name        : flame_sensor.h
 Author      : Aziza Zamel
 Description : Header file for the flame sensor Driver
 Date        : 5/10/2024
 ============================================================================
 */

#ifndef FLAME_SENSOR_H_
#define FLAME_SENSOR_H_

#include "std_types.h"


/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

/* Flame sensor HW Port and Pin Id */
#define FLAME_SENSOR_PORT_ID		PORTD_ID
#define FLAME_SENSOR_PIN_ID			PIN2_ID



/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for Initialize the flame sensor pin direction.
 */
void FlameSensor_init(void);

/*
 * Description :
 * Function responsible for  Read the value from the flame sensor and returns it.
 */
uint8 FlameSensor_getValue(void);

#endif /* FLAME_SENSOR_H_ */
