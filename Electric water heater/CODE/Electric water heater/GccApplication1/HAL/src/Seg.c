/*
* Seg.c
*
* Created: 9/6/2021 11:53:55 AM
*  Author: Mohamed Ebrahim
*/
#include "Seg.h"

static const u8 numbers[] = {
	NUM_0, NUM_1, NUM_2, NUM_3, NUM_4,
	NUM_5, NUM_6, NUM_7, NUM_8, NUM_9,
	NUM_DOT, E_CHAR, R_CHAR, O_CHAR
};

/* digit -> 1:2, value -> 0:9, '.' */
void Seg_init(void){
	/* Out */
	writePins(&SEG_DATA_DDR,SEG_DATA_MSK,OUTPUT);
	writePins(&SEG_DIGIT_DDR,SEG_DIGIT_MSK,OUTPUT);
	/* defaults */
	writePins(&SEG_DIGIT_PORT,SEG_DIGIT_MSK,LOW);
	writePins(&SEG_DATA_PORT,SEG_DATA_MSK,HIGH);
}
void Seg_Display(u8 digit, u8 value){ 
	SETBit(SEG_DIGIT_PORT, (digit-1));
	if(value == '.'){
		SEG_DATA_PORT = numbers[10];
	}
	else{
		SEG_DATA_PORT = numbers[value];
	}

	_delay_ms(1);
	CLRBit(SEG_DIGIT_PORT, (digit-1));
}
void Seg_DisplayInt(u32 intValue){
	int i = 0, j = 0 , arr[5] = {-1,-1,-1,-1,-1}, remainder;
	if((intValue>=0) && (intValue<100))
	{
		while (intValue != 0)
		{
			remainder = intValue % 10;
			arr[i] = remainder;
			intValue /= 10;
			i++;
		}
		i-=1;
		while (arr[j]>=0)
		{
			Seg_Display(i+1,arr[j]);
						i--;  
			j++;  
		}		
	}

}