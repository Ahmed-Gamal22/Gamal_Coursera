/**
 * @file memory.h
 * @brief Abstraction of integer and ascii data manipulation
 *
 * @author Ahmed Gamal
 * @date June 8 2020
 *
 */

#ifndef _DATA_H_
#define _DATA_H_

#include <stdint.h>

/**
 * @brief Integer-to-ASCII Conversion 
 *
 * Integer-to-ASCII needs to convert data from 
 * a standard integer type into an ASCII string.
 *
 * @param integer data to be converted
 * @param pointer to the converted character string 
 * @param integer value of the converted base (2 -> 16)
 *
 * @return the length of the converted data
 */
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);

/**
 * @brief ASCII-to-Integer Conversion 
 *
 * ASCII-to-Integer needs to convert data back from
 * an ASCII represented string into an integer type.
 * 
 * @param pointer to the character string to convert 
 * @param number of digits in character set
 * @param integer value of the base (2 -> 16)
 *
 * @return the converted integer data
 */
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);

#endif