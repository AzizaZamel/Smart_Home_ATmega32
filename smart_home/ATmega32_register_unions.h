/*
 ============================================================================
 Name        : ATmega32_register_unions.h
 Author      : Aziza Zamel
 Description : Header file with union declarations for all ATmega32 registers,
 providing access to full register values and individual bits for peripheral control.
 Date        : 25/9/2024
 ============================================================================
 */

#ifndef ATMEGA32_REGISTER_UNIONS_H_
#define ATMEGA32_REGISTER_UNIONS_H_

#include "std_types.h"



typedef union {
	uint8 byte;
	struct {
		uint8 C_bit :1;
		uint8 Z_bit :1;
		uint8 N_bit :1;
		uint8 V_bit :1;
		uint8 S_bit :1;
		uint8 H_bit :1;
		uint8 T_bit :1;
		uint8 I_bit :1;
	} bits;
} SREG_Type;


/************************* GPIO type structure declarations ************************/

typedef union {
	uint8 byte;
	struct {
		uint8 Bit0 :1;
		uint8 Bit1 :1;
		uint8 Bit2 :1;
		uint8 Bit3 :1;
		uint8 Bit4 :1;
		uint8 Bit5 :1;
		uint8 Bit6 :1;
		uint8 Bit7 :1;
	} bits;
} GPIO_Reg_Type;

/***********************************************************************************************/


/************************* ADC Registers type structure declarations ************************/

typedef union {
	uint8 byte;
	struct {
		uint8 MUX_bits :5;
		uint8 ADLAR_bit :1;
		uint8 REFS_bits :2;
	} bits;
} ADC_ADMUX_Type;

typedef union {
	uint8 byte;
	struct {
		uint8 ADPS_bits :3;
		uint8 ADIE_bit :1;
		uint8 ADIF_bit :1;
		uint8 ADATE_bit :1;
		uint8 ADSC_bit :1;
		uint8 ADEN_bit :1;
	} bits;
} ADC_ADCSRA_Type;

typedef union {
	uint16 TwoBytes;
	struct {
		uint16 Bit0 :1;
		uint16 Bit1 :1;
		uint16 Bit2 :1;
		uint16 Bit3 :1;
		uint16 Bit :1;
		uint16 Bit5 :1;
		uint16 Bit6 :1;
		uint16 Bit7 :1;
		uint16 Bit8 :1;
		uint16 Bit9 :1;
		uint16 Bit10 :1;
		uint16 Bit11 :1;
		uint16 Bit12 :1;
		uint16 Bit13 :1;
		uint16 Bit14 :1;
		uint16 Bit15 :1;
	} Bits;
} ADC_Data_Type;


/***********************************************************************************************/


/************************* Timer0 Registers type structure declarations ************************/

typedef union {
	uint8 byte;
	struct {
		uint8 CS0_bits :3;
		uint8 WGM01_bit :1;
		uint8 COM0_bits :2;
		uint8 WGM00_bit :1;
		uint8 FOC0_bit :1;
	} bits;
} Timer0_TCCR0_Type;


typedef union {
	uint8 byte;
	struct {
		uint8 Bit0 :1;
		uint8 Bit1 :1;
		uint8 Bit2 :1;
		uint8 Bit3 :1;
		uint8 Bit4 :1;
		uint8 Bit5 :1;
		uint8 Bit6 :1;
		uint8 Bit7 :1;
	} bits;
} Timer0_TCNT0_Type;


typedef union {
	uint8 byte;
	struct {
		uint8 Bit0 :1;
		uint8 Bit1 :1;
		uint8 Bit2 :1;
		uint8 Bit3 :1;
		uint8 Bit4 :1;
		uint8 Bit5 :1;
		uint8 Bit6 :1;
		uint8 Bit7 :1;
	} bits;
} Timer0_OCR0_Type;


typedef union {
	uint8 Byte;
	struct{
		uint8 TOIE0_bit:1;
		uint8 OCIE0_bit:1;
		uint8 TOIE1_bit:1;
		uint8 OCIE1B_bit:1;
		uint8 OCIE1A_bit:1;
		uint8 TICIE1_bit:1;
		uint8 TOIE2_bit:1;
		uint8 OCIE2_bit:1;
	}Bits;
}Timers_TIMSK_Type;


typedef union {
	uint8 Byte;
	struct{
		uint8 TOV0_bit:1;
		uint8 OCF0_bit:1;
		uint8 TOV1_bit:1;
		uint8 OCF1B_bit:1;
		uint8 OCF1A_bit:1;
		uint8 ICF1_bit:1;
		uint8 TOV2_bit:1;
		uint8 OCF2_bit:1;
	}Bits;
}Timers_TIFR_Type;



















#endif /* ATMEGA32_REGISTER_UNIONS_H_ */
