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
 * @brief Performs statistical data analysis on given dataset like finding:
 * Median
 * Mean
 * Maximum
 * Minimum
 * Sort in descending order
 * @author Vimil Rathod
 * @date 12-11-2020
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE 40

int i;

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  int S;
  S = SIZE;
  /* Statistics and Printing Functions Go Here */
  print_array(test, S);
  printf("Analytical Statistics:\n");
  print_statistics(test, S);
  find_median(test, S);
  find_mean(test, S);
  find_maximum(test, S);
  find_minimum(test, S);
  sort_array(test, S);
  printf("Given Dataset in Descending order:\n");
  for (i=0;i<S;i++){
  printf("%d\n",test[i]);
}
}

/* Add other Implementation File Code Here */

void print_statistics(unsigned char test[], int S){
int med, mn, max, min;
med = find_median(test, S);
mn = find_mean(test, S);
max = find_maximum(test, S);
min = find_minimum(test, S);
printf("Median of the dataset = %d\n",med);
printf("Mean of the dataset = %d\n",mn);
printf("Maximum of the dataset = %d\n",max);
printf("Minimum of the dataset = %d\n",min);

}

void print_array(unsigned char test[], int S){
printf("Given Dataset:\n");
for (i=0;i<S;i++){
printf("%d\n",test[i]);
}
}

int find_median(unsigned char test[], int S){
int m;
//Sorting the array in ascending order before calculating the median
int i, j, temp;
for (i=0;i<S;i++){
for (j=i+1;j<S;j++){
if (test[i]>test[j]){
temp = test[i];
test[i] = test[j];
test[j] = temp;
}
}
}

if (S%2 != 0){
m = test[(S+1)/2];
}
else{
m = test[(((S/2)+((S+2)/2))/2)-1];
}
return m;
}

int find_mean(unsigned char test[], int S){
int avg=0;
for (i=0;i<S;i++){
avg = avg + test[i];
}
avg = avg/S;
return avg;
}

int find_maximum(unsigned char test[], int S){
for (i=0;i<S;i++){
if (test[0]<test[i]){
test[0] = test[i];
}
}
return test[0];
}

int find_minimum(unsigned char test[], int S){
for (i=0;i<S;i++){
if (test[0]>test[i]){
test[0] = test[i];
}
}
return test[0];
}

unsigned char * sort_array(unsigned char test[], int S){
int i, j, temp;
for (i=0;i<S;i++){
for (j=i+1;j<S;j++){
if (test[i]<test[j]){
temp = test[i];
test[i] = test[j];
test[j] = temp;
}
}
}
return test;
}

