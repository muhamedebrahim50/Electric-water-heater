/*
 * HEATER.h
 *
 * Created: 9/7/2021 11:53:02 PM
 *  Author: Mohamed Ebrahim
 */ 


#ifndef HEATER_H_
#define HEATER_H_

#include "includes.h"

#define HEATER_PIN				PB3
#define COOLER_PIN				PA4
#define HEATING_ELEMENT_LED		PA5

void system_init(void);
void temperatureControl(void);
void disable(void);
void temperatureSettingEnd(void);
void temperatureDecision(void);

#endif /* HEATER_H_ */