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
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <Put a description of the supported targets here>
#
# Platform Overrides:
#      <Put a description of the supported Overrides here
#
#------------------------------------------------------------------------------
include sources.mk

# Override platform
PLATFORM = HOST

# Executable file name
TARGET = c1m2

# ARM linker file
LINKER_FILE = ../msp432p401r.lds

#C standard used
C_stand = c99

# ARM Architecture Specific Flags
CPU = cortex-m4
FPU = fpv4-sp-d16
ARCH = armv7e-m
SPECS = nosys.specs

# Host platform or MS432 platform
ifeq ($(PLATFORM),HOST)
	CC = gcc
	LD = ld
	CFLAGS = -Wall -Werror -MMD -g -std=$(C_stand) 
	LDFLAGS = -Wl,-O0
	size = size
	CPPFLAGs = $(HOSTINCLUDES)
	OBJS = $(HOSTSOURCES:.c=.o)
else
	CC = arm-none-eabi-gcc
	LD = arm-none-eabi-ld
	CFLAGS = -Wall -Werror -g -MMD -std=$(C_stand) -mcpu=$(CPU) -mthumb -march=$(ARCH) \
			 --specs=$(SPECS) -mfloat-abi=hard -mfpu=$(FPU)
	LDFLAGS = -Wl,-Map=$(TARGET).map -T $(LINKER_FILE) -O0 
	CPPFLAGs = $(TARGETINCLUDES)
	size = arm-none-eabi-size
	OBJS = $(TARGETSOURCES:.c=.o)
endif

%.o %.d : %.c
	$(CC) -c $< -D$(PLATFORM) $(CPPFLAGs) $(CFLAGS) -o $@
%.i : %.c
	$(CC) -E $< -D$(PLATFORM) $(CPPFLAGs) $(CFLAGS) -o $@
%.asm : %.c
	$(CC) -S $< -D$(PLATFORM) $(CPPFLAGs) $(CFLAGS) -o $@

.PHONY: compile-all
compile-all: $(TARGET).o
$(TARGET).o %.d: $(OBJS)
	$(CC) -c $(OBJS) -D$(PLATFORM) $(CPPFLAGs) $(CFLAGS) $(LDFLAGS) -o $@

.PHONY: build
build: $(TARGET).out
$(TARGET).out: $(OBJS)
	$(CC) $(OBJS) -D$(PLATFORM) $(CPPFLAGs) $(CFLAGS) $(LDFLAGS) -o $@
	$(size) $(TARGET).out
	
.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET).out $(TARGET).map $(TARGET).i $(TARGET).asm $(TARGET).d
