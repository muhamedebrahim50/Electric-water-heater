/*
 * LM35.c
 *
 * Created: 9/7/2021 9:37:59 PM
 *  Author: Mohamed	Ebrahim
 */ 
#include "LM35.h"

float temperatureRead (void)
{
	float temperature;
	temperature= read_analog(LM35_PIN)*4.88;
	temperature= temperature/10;
	return temperature ;
}