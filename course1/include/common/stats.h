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
 * @brief function declaration file of stats.c file
 *
 *
 * @author Vimil Rathod
 * @date 12-11-2020
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */ 

/**
 * @brief Function: print_statistics
 * Description:
 *     This function prints the statistics of an array including minimum, maximum, mean, and median.
 * Parameters:
 *     int * ptr: Pointer to a data set
 *     int count: Number of items in data set
 * Return: 
 *     void
 */

void print_statistics(unsigned char test[], int S);

/**
 * @brief Function: print_array
 * Description:
 *     This function given an array of data and a length, prints the array to the screen
 * Parameters:
 *     int * ptr: Pointer to a data set
 *     int count: Number of items in data set
 * Return: 
 *     void
 */

void print_array(unsigned char test[], int S);

/**
 * @brief Function: find_median
 * Description:
 *     This function given an array of data and a length, returns the median value.
 * Parameters:
 *     int * ptr: Pointer to a data set
 *     int count: Number of items in data set
 * Return: 
 *     median of the numbers provided.
 */

int find_median(unsigned char test[], int S);

/**
 * @brief Function: find_mean
 * Description:
 *     This function given an array of data and a length, returns the mean.
 * Parameters:
 *     int * ptr: Pointer to a data set
 *     int count: Number of items in data set
 * Return: 
 *     mean of the numbers provided.
 */

int find_mean(unsigned char test[], int S);

/**
 * @brief Function: find_maximum
 * Description:
 *     This function given an array of data and a length, returns the maximum.
 * Parameters:
 *     int * ptr: Pointer to a data set
 *     int count: Number of items in data set
 * Return: 
 *     maximum of the numbers provided.
 */

int find_maximum(unsigned char test[], int S);

/**
 * @brief Function: find_minimum
 * Description:
 *     This function given an array of data and a length, returns the minimum.
 * Parameters:
 *     int * ptr: Pointer to a data set
 *     int count: Number of items in data set
 * Return: 
 *     minimum of the numbers provided.
 */

int find_minimum(unsigned char test[], int S);

/**
 * @brief Function: sort_array
 * Description:
 *     This function given an array of data and a length, sorts the array from largest to smallest. (The zeroth Element should be the largest value, and the last element (n-1) should be the smallest value. )
 * Parameters:
 *     int * ptr: Pointer to a data set
 *     int count: Number of items in data set
 * Return: 
 *     sorted array.
 */

unsigned char * sort_array(unsigned char test[], int S);

#endif /* __STATS_H__ */
