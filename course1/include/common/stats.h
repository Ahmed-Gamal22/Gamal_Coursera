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
 * @file stats.h 
 * @brief header file of stats module 
 *		  Reponsible for statsical analysis on an Array input.
 * @author Ahmed Gamal
 * @date 28-05-2020
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

#include "platform.h"

/* Add Your Declarations and Function Comments here */ 

/**
 * @brief print statistical elements on console
 *
 *	This function take four inputs and print theri values
 *	on the console application.
 *
 * @param unsigned integer 8 bit minimum
 * @param unsigned integer 8 bit maximum
 * @param unsigned integer 8 bit mean
 * @param unsigned integer 8 bit median
 *
 * @return void
 */
void print_statistics(unsigned char minimum, unsigned char maximum, unsigned char mean, unsigned char median);

/**
 * @brief print array elements on console
 *
 *	Given an array of data and a length, prints the array to the console screen.
 *
 * @param pointer to unsigned integer 8 bit value(first element of array)
 * @param unsigned integer 8 bit length of array
 *
 * @return void
 */
#ifdef VERBOSE 
void print_array(unsigned char *data, unsigned char length);
#endif
/**
 * @brief calculate array median value
 *
 *	Given an array of data and a length, calculate array median value and return it back.
 *
 * @param pointer to unsigned integer 8 bit value(first element of array)
 * @param unsigned integer 8 bit length of array
 *
 * @return unsigned integer 8 bit median value of array
 */
unsigned char find_median(unsigned char *data, unsigned char length);

/**
 * @brief calculate array mean value
 *
 *	Given an array of data and a length, calculate array mean value and return it back.
 *
 * @param pointer to unsigned integer 8 bit value(first element of array)
 * @param unsigned integer 8 bit length of array
 *
 * @return unsigned integer 8 bit mean value of array
 */
unsigned char find_mean(unsigned char *data, unsigned char length);

/**
 * @brief calculate array max value
 *
 *	Given an array of data and a length, calculate array max value and return it back.
 *
 * @param pointer to unsigned integer 8 bit value(first element of array)
 * @param unsigned integer 8 bit length of array
 *
 * @return unsigned integer 8 bit max value of array
 */ 
unsigned char find_maximum(unsigned char *data, unsigned char length); 

/**
 * @brief calculate array min value
 *
 *	Given an array of data and a length, calculate array min value and return it back.
 *
 * @param pointer to unsigned integer 8 bit value(first element of array)
 * @param unsigned integer 8 bit length of array
 *
 * @return unsigned integer 8 bit min value of array
 */
unsigned char find_minimum(unsigned char *data, unsigned char length);

/**
 * @brief sort array in Descending order
 *
 *	Given an array of data and a length,sorts the array from largest to smallest. 
 *	The zeroth Element should be the largest value, and 
 *	the last element (n-1) should be the smallest value.
 *
 * @param pointer to unsigned integer 8 bit value(first element of array)
 * @param unsigned integer 8 bit length of array
 *
 * @return void
 */
void sort_array(unsigned char *data, unsigned char length);

#endif /* __STATS_H__ */
