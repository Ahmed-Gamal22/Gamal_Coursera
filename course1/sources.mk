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

# Add your Source files to this variable
TARGETSOURCES = ../course1\src\course1.c \
				../course1\src\data.c \
				../course1\src\interrupts_msp432p401r_gcc.c \
				../course1\src\memory.c \
				../course1\src\startup_msp432p401r_gcc.c \
				../course1\src\stats.c \
				../course1\src\system_msp432p401r.c \
				../course1\src\main.c 
# Add your include paths to this variable
TARGETINCLUDES = -I../include\common \
				 -I../include\msp432 \
				 -I../include\CMSIS
# Add your Source files to this variable
HOSTSOURCES = ../course1\src\course1.c \
				../course1\src\data.c \
				../course1\src\memory.c \
				../course1\src\stats.c \
				../course1\src\main.c 
# Add your include paths to this variable
HOSTINCLUDES = -I../include\common 
