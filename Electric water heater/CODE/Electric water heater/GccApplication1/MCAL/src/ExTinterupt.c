/*
 * ExTinterupt.c
 *
 * Created: 8/21/2021 4:23:22 PM
 *  Author: Mohamed Ebrahim
 */ 
#include "EXT_INT.h"

void INT_init(u8 int_num , u8 sense_control)
{
	switch(int_num)
	{
		case INT_2:
		MCUCSR|=((sense_control & 0x01)<<6);
		SETBit(GICR,INT_2);
		break;
		
		case INT_0:
		CLRBits(MCUCR,INT0_ISC_MSK);
		SETBits(MCUCR,sense_control<<INT0_ISC_POS);
		SETBit(GICR,INT_0);
		break;
		case INT_1:
		CLRBits(MCUCR,INT1_ISC_MSK);
		SETBits(MCUCR,sense_control<<INT1_ISC_POS);
		SETBit(GICR,INT_1);
	}
	GLOBAL_INT_EN();
}

void GLOBAL_INT_EN(void)
{
	writePins( &SREG,0x80,HIGH );
}

void GLOBAL_INT_DE(void)
{
	writePins( &SREG,0x80,LOW );
}
