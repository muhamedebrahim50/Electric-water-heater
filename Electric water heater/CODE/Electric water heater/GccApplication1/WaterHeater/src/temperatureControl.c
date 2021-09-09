/*
 * HEATER.c
 *
 * Created: 9/7/2021 11:53:58 PM
 *  Author: Mohamed Ebrahim
 */ 
#include "temperatureControl.h"
extern u8 set_temp;
extern float temp;
extern float displayTemp;
extern u8 eepromTemp;
extern u8 state;
extern u8 setFlag;
u16 i=0;
u8 j=0;
void system_init(void)
{
	INT_init(INT_0, falling_edge);	/*interrupt 1 activation*/
	INT_init(INT_1, falling_edge);	/*interrupt 2 activation*/
	INT_init(INT_2,falling_edge);	/*interrupt 2 activation*/
	SPI_Init(SPI_MASTER);
	pinDirection(PD2,INPUT);	/*set interrupt 1 as INPUT*/
	pinDirection(PD3,INPUT);	/*set interrupt 2 as INPUT*/
	pinDirection(PB2,INPUT);	/*set interrupt 3 as INPUT*/
	pinDirection(COOLER_PIN,OUTPUT);	
	pinDirection(HEATER_PIN,OUTPUT);
	pinDirection(HEATING_ELEMENT_LED,OUTPUT);
	writePin(COOLER_PIN,LOW);
	writePin(HEATER_PIN,LOW);
	eepromTemp=readEEPROM(0x00);	/*reading set temperature form external eeprom*/
	Timer0_Init(NORMAL);
	Seg_init();
	ADC_init();
}
void temperatureControl(void)
{
	static u8 flag=2;
		if(((u8)temp)<(set_temp-4))
				{
					
					flag=0;

				}
		else if(((u8)temp)>(set_temp+4))
				{
					flag=1;
				}
				
	if(((u8)temp)<(set_temp-4)&& (flag==0))			//heater on
	{
		writePin(HEATER_PIN,HIGH);
			while(i<300)
			{
				writePin(HEATING_ELEMENT_LED,HIGH);
				i++;
			}
			writePin(HEATING_ELEMENT_LED,LOW);
			i=0;
		writePin(COOLER_PIN,LOW);
		if(((u8)temp)<(set_temp-4))		
		flag=1;
	}
	
	else if(((u8)temp) > (set_temp+4)&& (flag==1))	//cooler on
	{
		writePin(HEATER_PIN,LOW);
		writePin(COOLER_PIN,HIGH);
		writePin(HEATING_ELEMENT_LED,HIGH);
		if(((u8)temp) > (set_temp+4))
		flag=0;
	}
}
void disable(void)
{
	writeAllPin(&PORTA,LOW);
	writeAllPin(&PORTC,LOW);
	writeAllPin(&PORTD,LOW);
}
void temperatureSettingEnd(void) 
{
 	writeEEPROM(0x00,set_temp);
	setFlag = 0;
	if(state==SET)
	state=ON;
}
void temperatureDecision(void)
{
	if(j<10)
	{
		temp=temp+temperatureRead();
			j++;
	}
	else
	{
		temp=temp/10;
		displayTemp=temp;
		j=0;
	}
}
