/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file main.c
 * @brief Main entry point to the Final Assessment
 *
 *
 * @author Vimil Rathod
 * @date Dec 24 2020
 *
 */

/******************************************************************************
******************************************************************************/
#include<stdint.h>
#include "data.h"
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base) {
	int32_t temp;
	char flag = 0;
	uint8_t i = 0,length;
	if(data == 0) {
		*(ptr + ++i) = '\0';
		return i+1;	
	}
	
	*(ptr + i++) = '\0';
	
	if(data < 0 && base == 10){
		flag = 1;	
		data = -data;
	}
	while( data != 0) {
		*(ptr + i) =	data%base;
		i = i+1;
		data = data/base;
	}

	if( flag == 1 ) // No other number other than decimal has sign to it.
		*(ptr + i++) = '-';
	
	length = i;
	i = 0;

        for ( i = 0; i < (length)/2; i++){
                temp = *(ptr + i );
                *(ptr + i ) = *( ptr + length - i - 1);
                *( ptr + length - i - 1) = temp;

        }
        return length;

}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base) {

	int32_t data = 0;
	uint8_t i = digits-2;
	uint8_t temp = (uint8_t)base;
	base = 1;
	/* Checking for a Null pointer */	
	if(!ptr)
		return -1;
	/* String to Integer conversion except last character ( MSB ) */
	while( i > 0 ) {
		data += *(ptr + i ) * ( base ) ;
		i = i - 1;
		base*= temp;
	}
	
	/* Last Character check for -ve sign */ 
	if(temp == 10 && *(ptr + i) == '-')    
		data = -data;
	else
		data += *(ptr + i) * ( base ); 
	
	return data;

}
