/*
* GccApplication1.c
*
* Created: 9/6/2021 11:25:57 PM
* Author : Mohamed Ebrahim
*/

#include "includes.h"
#include "Timers.h"
#include <avr/interrupt.h>
u8 state = OFF;	//initial state
u8 set_temp=60; //initial set temperature
u16 counter=0;
u8 setFlag = 0;
u8 eepromTemp;
float temp=0.0;
int main(void)
{
	system_init();
	Timer0_RunFun(temperatureSettingEnd,5000,FALSE); //Exit setting mode after 5 sec with no button pressed

	while (1)
	{
		if(state==OFF)
		{
			disable();
		}
		else if(state==ON)
		{
			temp=temperatureRead();
			Seg_DisplayInt((u32)temp);
			temperatureControl();
		}
		else if(state==SET)
		{
			Seg_init();
			while(counter<300)
			{
				Seg_DisplayInt((u32)set_temp);
				counter++;
			}
			counter=0;
			_delay_ms(200);
	
		}
	}
}

ISR(INT0_vect)	// Up button
{
	state=SET;
	ResetTimer();
	if((state==SET) && (set_temp<75) && (setFlag == 1) )
	{	
		set_temp+=5;
	}
	setFlag = 1;
}
ISR(INT1_vect)	// Down button
{
	state=SET;
	ResetTimer();
	if((state==SET) && (set_temp>35) && (setFlag == 1))
	{
		set_temp-=5;
	}
	setFlag = 1;
}
ISR(INT2_vect) // ON/OFF Button
{
	if(state==OFF)
	{
		state=ON;
		setFlag=0;
	}
	else if((state==ON)||(state==SET))
	{
		state=OFF;
	}
}
