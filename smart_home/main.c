/*
 ============================================================================
 Name        : main.c
 Author      : Aziza Zamel
 Description : Smart Home System
 Date        : 4/10/2024
 ============================================================================
 */
#include "lcd.h"
#include "motor.h"
#include "lm35_sensor.h"
#include "adc.h"
#include "led.h"
#include "ldr.h"
#include "buzzer.h"
#include "flame_sensor.h"

int main(void) {
	/* Variables to hold the readings of the temperature sensor and LDR */
	uint8 temperature, intensity;

	/* LCD initializations */
	LCD_init();
	LCD_moveCursor(0, 3);
	LCD_displayString((uint8*) "FAN is OFF");
	LCD_moveCursor(1, 0);
	LCD_displayString((uint8*) "Temp=   LDR=   %");

	/* DC motor, ADC, LEDs, Buzzer and flame sensor initializations */
	DcMotor_Init();
	ADC_init();
	LEDS_init();
	Buzzer_init();
	FlameSensor_init();

	for (;;) {
		/* check if the flame sensor detects fire */
		if (FlameSensor_getValue() == LOGIC_HIGH) {
			/* turn on Alarm and Display "Critical alert!" on the LCD */
			Buzzer_on();
			LCD_clearScreen();
			LCD_moveCursor(0, 0);
			LCD_displayString((uint8*) "Critical alert!");
			/* wait until flame sensor no longer detects fire.  */
			while (FlameSensor_getValue() == LOGIC_HIGH){}

			/* turn off the alarm ans resume the system */
			Buzzer_off();
			LCD_clearScreen();
			LCD_moveCursor(1, 0);
			LCD_displayString((uint8*) "Temp=   LDR=   %");
		}


		temperature = LM35_getTemperature();
		LCD_moveCursor(1, 5);
		/* Display temperature on the LCD */
		if (temperature >= 100) {
			LCD_intgerToString(temperature);
		} else {
			LCD_intgerToString(temperature);
			/* In case the digital value is two or one digits print space in the next digit place */
			LCD_displayCharacter(' ');
		}
		/* if temperature is less than 25°C, turn off the DC motor(fan) */
		if (temperature < 25) {
			DcMotor_Rotate(STOP, 0);
			LCD_moveCursor(0, 3);
			LCD_displayString((uint8*) "FAN is OFF");

		}
		/* if Temperature ≥ 25°C and < 30°C, turn on the DC motor(fan) at 25% speed */
		else if (temperature < 30) {
			DcMotor_Rotate(CW, 25);
			LCD_moveCursor(0, 3);
			LCD_displayString((uint8*) "FAN is ON ");

		}
		/* if Temperature ≥ 30°C and < 35°C, turn on the DC motor(fan) at 50% speed */
		else if (temperature < 35) {
			DcMotor_Rotate(CW, 50);
			LCD_moveCursor(0, 3);
			LCD_displayString((uint8*) "FAN is ON ");

		}
		/* if Temperature ≥ 35°C and < 40°C, turn on the DC motor(fan) at 75% speed */
		else if (temperature < 40) {
			DcMotor_Rotate(CW, 75);
			LCD_moveCursor(0, 3);
			LCD_displayString((uint8*) "FAN is ON ");

		}
		/* if Temperature ≥ 40°C, turn on the DC motor(fan) at 100% speed */
		else {
			DcMotor_Rotate(CW, 100);
			LCD_moveCursor(0, 3);
			LCD_displayString((uint8*) "FAN is ON ");

		}

		intensity = LDR_getLightIntensity();
		LCD_moveCursor(1, 12);
		/* Display intensity */
		if (intensity == 100) {
			LCD_intgerToString(intensity);
		} else {
			LCD_intgerToString(intensity);
			/* In case the digital value is two or one digits print space in the next digit place */
			LCD_displayCharacter(' ');
		}

		/* if Intensity < 15%, turn ON all LEDs */
		if (intensity <= 15) {
			LED_on(RED);
			LED_on(GREEN);
			LED_on(BLUE);
		}
		/* if Intensity 16–50%, turn ON Red and Green LEDs only */
		else if (intensity <= 50) {
			LED_on(RED);
			LED_on(GREEN);
			LED_off(BLUE);
		}
		/* if Intensity 51–70%, turn ON Red LED only */
		else if (intensity <= 70) {
			LED_on(RED);
			LED_off(GREEN);
			LED_off(BLUE);
		}
		/* if Intensity > 70%, turn OFF all LEDs  */
		else {
			LED_off(RED);
			LED_off(GREEN);
			LED_off(BLUE);
		}
	}
}
