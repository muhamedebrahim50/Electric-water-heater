/*
 * Seg.h
 *
 * Created: 9/6/2021 12:53:42 AM
 *  Author: Mohamed	Ebrahim
 */ 


#ifndef SEG_H_
#define SEG_H_

#include "includes.h"

/* CFG */
#define SEG_DATA_PORT		PORTC
#define SEG_DATA_DDR		DDRC
#define SEG_DATA_MSK		0x7F


#define SEG_DIGIT_PORT		PORTD
#define SEG_DIGIT_DDR		DDRD
#define SEG_DIGIT_MSK		0x03

/* Common Anode  */
#define NUM_0		0xC0	
#define NUM_1		0xF9
#define NUM_2		0xA4
#define NUM_3		0xB0
#define NUM_4		0x99
#define NUM_5		0x92
#define NUM_6		0x82
#define NUM_7		0xF8
#define NUM_8		0x80	
#define NUM_9		0x90
#define NUM_DOT		0x7F
#define E_CHAR		0x86  
#define R_CHAR		0xAF	
#define O_CHAR		0xA3
#define NULL_CHAR	0xFE


/* digit -> 1:4, value -> 0:9, '.' */
void Seg_init(void);
void Seg_Display(u8 digit, u8 value);
void Seg_DisplayInt(u32 intValue);


#endif /* SEG_H_ */