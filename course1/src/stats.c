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
 * @file stats.c 
 * @brief implementation file of stats module 
 *
 * Reponsible for statsical analysis on an Array input.
 *
 * @author Ahmed Gamal
 * @date 28-05-2020
 *
 */


#include <stdio.h>
#include "../include\common\stats.h"
/* Size of the Data Set */
#define SIZE (40)

/* Add other Implementation File Code Here */
void print_statistics(unsigned char minimum, unsigned char maximum, unsigned char mean, unsigned char median)
{
	PRINTF("The Minimum Value of the Array = %d\n",minimum);
	PRINTF("The maximum Value of the Array = %d\n",maximum);
	PRINTF("The mean Value of the Array = %d\n",mean);
	PRINTF("The median Value of the Array = %d\n",median);
}
#ifdef VERBOSE 
void print_array(unsigned char *data, unsigned char length)
{
	for(unsigned char i = 0 ; i < length ; i++)
	{
		PRINTF("data[%d] = %d\n",i,data[i]);
	}
}
#endif
unsigned char find_median(unsigned char *data, unsigned char length)
{
	unsigned char lengthhalf = length/2;
	if(length % 2 == 0)
	{
		return (((data[lengthhalf-1]+data[lengthhalf])/2)+0.5);
	}
	else
	{
		return data[lengthhalf-1];
	}
}
unsigned char find_mean(unsigned char *data, unsigned char length)
{
	unsigned long total = 0;
	for(unsigned char i = 0 ; i < length ; i++)
	{
		total+=data[i];
	}
	return ((total/length) + 0.5);
}
unsigned char find_minimum(unsigned char *data, unsigned char length)
{
	unsigned char min = data[0];
	for(unsigned char i = 1 ; i < length ; i++)
	{
		if(data[i] < min)
		{
			min = data[i];
		}
	}
	return min;
}
unsigned char find_maximum(unsigned char *data, unsigned char length)
{
	unsigned char max = data[0];
	for(unsigned char i = 1 ; i < length ; i++)
	{
		if(data[i] > max)
		{
			max = data[i];
		}
	}
	return max;
}
void sort_array(unsigned char *data, unsigned char length)
{
	unsigned char temp = 0;
	for(unsigned char i = 1 ; i < length ; i++)
	{
		for(unsigned char j = 1 ; j < length ; j++)
		{
			if(data[j] > data[j-1])
			{
				temp = data[j];
				data[j] = data[j-1];
				data[j-1] = temp;
			}
		}
	}
}
