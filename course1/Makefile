#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# Makefile for Build system for assisgnment 2
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <FILE>.o - Builds <FILE>.o object file
#      build - Builds and links all source files
#      all - Same as build
#      clean - removes all generated filests here>
#
# Platform Overrides:
#      CPU - ARM Cortex Architecture (cortex-m0plus, cortex-m4)
#      ARCH - ARM Architecture (arm, thumb)
#      SPECS - Specs file to give the linker (nosys.specs, nano.specs)
#
#------------------------------------------------------------------------------

include sources.mk


# Platform Overrides
ifeq ($(PLATFORM),MSP432)

        # Architectures Specific Flags
        CPU = cortex-m4
        ARCH = thumb
        SPECS = nosys.specs
        LINKER_FILE = ../msp432p401r.lds

        # Compiler Flags and Defines
        CC = arm-none-eabi-gcc
        LD = arm-none-eabi-ld
        CFLAGS = -mcpu=$(CPU) -m$(ARCH) --specs=$(SPECS) -Wall -DMSP432
	CFLAGS += $(INCLUDES)
        CPPFLAGS = -MMD -MP
        LDFLAGS = -Wl,-Map=$(TARGET).map -T $(LINKER_FILE)
	OBJDUMP = arm-none-eabi-objdump

	#Size Utility
        SIZE = arm-none-eabi-size


else ifeq ($(PLATFORM),HOST)

        # Compiler Flags and Defines
        CC = gcc
	LD = ld
        CFLAGS = -std=c99 -Wall -DHOST
        CFLAGS += $(INCLUDES)
        CPPFLAGS = -MMD -MP
	#Size Utility
        SIZE = size
        LDFLAGS = -Wl,-Map=$(TARGET).map
        OBJDUMP = objdump
endif

TARGET = c1m2

OBJS = $(SOURCES:.c=.o)

PREPRO = $(SOURCES:.c=.i)

ASMS = $(SOURCES:.c=.asm)

DEPS = $(SOURCES:.c=.d)

FILES = *.asm *.i *.o *.d *.out *.map

%.o : %.c
	$(CC) $(INCLUDES) -c $< $(CFLAGS) -o $@

%.i : %.c
	$(CC) $(INCLUDES) $(CPPFLAGS) $< $(CFLAGS) -o $@

%.asm : %.c
	$(CC) $(INCLUDES) -S $< $(CFLAGS) -o $@

$(TARGET).asm : $(TARGET).out
	$(OBJDUMP) -d $(TARGET).out >> $@

%.d : %.c
	$(CC) $(INCLUDES) -M $< $(CFLAGS) -o $@


.PHONY: build
build: all

.PHONY: all
all: $(TARGET).out $(TARGET).asm

$(TARGET).out: $(OBJS) $(DEPS)
	$(CC) $(CFLAGS) $(INCLUDES) $(CPPFLAGS) $(LDFLAGS) -o $(TARGET).out $(OBJS)
	$(SIZE) -Atd $(TARGET).out
	$(SIZE) $(TARGET).out


.PHONY: clean
clean:
	rm -f $(FILES)

