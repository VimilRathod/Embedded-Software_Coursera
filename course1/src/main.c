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
 
#include "course1.h"
#include "platform.h"
#include "memory.h"


#define MAX_LENGTH (10)
char buffer[MAX_LENGTH];

/* A pretty boring main file */

int main(void) {
  #if defined (COURSE1)
  course1();
  #endif
}


