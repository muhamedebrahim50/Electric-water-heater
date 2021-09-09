/*
 * includes.h
 *
 * Created: 8/18/2021 10:12:15 PM
 *  Author: Mohamed Ebrahim
 */ 


#ifndef INCLUDES_H_
#define INCLUDES_H_
#define  F_CPU 8000000UL
#include "bitMath.h"
#include "dataTypes.h"
#include "registers.h"
#include "DIO.h"
#include "util/delay.h"
#include "ADC.h"
#include "EXT_INT.h"
#include "Timers.h"
#include "Seg.h"
#include "LM35.h"
#include "temperatureControl.h"
#include "spi.h"
#include "ExtEEPROM.h"
#include <stdio.h>

enum{OFF,ON,SET}; //System States

#endif /* INCLUDES_H_ */