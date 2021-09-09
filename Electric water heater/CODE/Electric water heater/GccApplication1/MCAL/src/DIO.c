/*
 * DIO.c
 *
 * Created: 8/18/2021 11:18:29 PM
 *  Author: Mohamed Ebrahim
 */ 
#include "includes.h"

/*for single bit*/
void writePin(u8 pinNo,u8 logic){
	if((pinNo>=PA0)&&(pinNo<=PA7)){
		if(logic==HIGH)
			SETBit(PORTA,(pinNo-PORTA_OFFSET));
		else if(logic==LOW)
			CLRBit(PORTA,(pinNo-PORTA_OFFSET));
		else{}
}

	else if((pinNo>=PB0)&&(pinNo<=PB7)){
		if(logic==HIGH)
			SETBit(PORTB,(pinNo-PORTB_OFFSET));
		else if(logic==LOW)
			CLRBit(PORTB,(pinNo-PORTB_OFFSET));
		else{}
	}
	
	else if((pinNo>=PC0)&&(pinNo<=PC7)){
		if(logic==HIGH)
			SETBit(PORTC,(pinNo-PORTC_OFFSET));
		else if(logic==LOW)
			CLRBit(PORTC,(pinNo-PORTC_OFFSET));
		else{}
	}
	
	else if((pinNo>=PD0)&&(pinNo<=PD7)){
		if(logic==HIGH)
			SETBit(PORTD,(pinNo-PORTD_OFFSET));
		else if(logic==LOW)
			CLRBit(PORTD,(pinNo-PORTD_OFFSET));
		else{}
	}
	else{}
}
void pinDirection(u8 pinNo, u8 direction){
	if((pinNo >= PA0) && (pinNo <= PA7)){
		if(direction == OUTPUT)
			SETBit(DDRA,(pinNo-PORTA_OFFSET));
		else if(direction == INPUT)
			CLRBit(DDRA,(pinNo-PORTA_OFFSET));
		else{}
	}
	else if((pinNo >= PB0) && (pinNo <= PB7)){
		if(direction == OUTPUT)
			SETBit(DDRB,(pinNo-PORTB_OFFSET));
		else if(direction == LOW)
			CLRBit(DDRB,(pinNo-PORTB_OFFSET));
		else{}
	}
	else if((pinNo >= PC0) && (pinNo <= PC7)){
		if(direction == OUTPUT)
			SETBit(DDRC,(pinNo-PORTC_OFFSET));
		else if(direction==INPUT)
			CLRBit(DDRC,(pinNo-PORTC_OFFSET));
		else{}
	}
	else if((pinNo >= PD0) && (pinNo <= PD7)){
		if(direction == OUTPUT)
			SETBit(DDRD,(pinNo-PORTD_OFFSET));
		else if(direction == INPUT)
			CLRBit(DDRD,(pinNo-PORTD_OFFSET));
		else{}
	}
	else{}
}

u8 readPin(u8 pinNo){
	u8 result=0;
	if((pinNo>=PA0)&&(pinNo<=PA7))
		result=GETBit(PINA,(pinNo-PORTA_OFFSET));
	else if((pinNo>=PB0)&&(pinNo<=PB7))
		result=GETBit(PINB,(pinNo-PORTB_OFFSET));
	else if((pinNo>=PC0)&&(pinNo<=PC7))
		result=GETBit(PINC,(pinNo-PORTC_OFFSET));
	else if((pinNo>=PD0)&&(pinNo<=PD7))
		result=GETBit(PIND,(pinNo-PORTD_OFFSET));
	else{}
	return result;
}
	
/*for custom number of bits*/
void writePins(volatile u8* port, u8 mask, u8 logic){
	if(logic==HIGH)
		SETBits(*port,mask);
	else if(logic==LOW)
		CLRBits(*port,mask);
	else{}
}
void pinsDirection(volatile u8* ddr, u8 mask, u8 direction){
	if(direction == OUTPUT)
		SETBits(*ddr,mask);
	else if(direction == INPUT)
		CLRBits(*ddr,mask);
	else{}
}

/*for all bits*/
void writeAllPin(volatile u8* port,u8 logic){
	if(logic==HIGH)
		SETALLBits(*port);
	else if(logic==LOW)
		CLRALLBits(*port);
	else{}
}
void allPinsDirection(volatile u8* ddr, u8 direction){
	if(direction == OUTPUT)
		SETALLBits(*ddr);
	else if(direction == INPUT)
		CLRALLBits(*ddr);
	else{}	
}
