/**
 * @file data.c
 * @brief Data manipulation with strings
 *
 * This implementation file provides implementation functions to 
 * handle integer to ascii and vice versa.
 *
 * @author Ahmed Gamal
 * @date June 8 2020
 *
 */
#include "../include\common\data.h"
#include <stdio.h>
#include <stdlib.h>
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base)
{
	int n = abs(data);
	int i = 0;
	while(n)
	{
		int r = n%base;
		if(r >= 10)
		{
			*(ptr+i) = 65 + (r - 10);
			i++;
		}
		else
		{
			*(ptr+i) = 48 + r;
			i++;
		}
		n/=base;
	}
	if(i == 0)
	{
		*(ptr+i) = '0';
		i++;
	}
	if(data < 0)
	{
		*(ptr+i) = '-';
		i++;
	}
	*(ptr+i) = '\0';	
	return i;
}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base)
{
	int32_t retVal = 0;
	int sign = 1;
	uint8_t i = 0;
	uint8_t tempVal = 0;
	for(uint8_t j = 0; j < digits/2; j++)
	{		
		tempVal = *(ptr+j);
		*(ptr+j) = *(ptr+digits-j-1);
		*(ptr+digits-j-1) = tempVal;
	}
	if(*ptr == '-')
	{
		sign = -1;
		i++;
	}
	for(; i < digits; i++)
	{		
		retVal = retVal * base + (*(ptr+i) - '0');
	}
	return retVal*sign;
}