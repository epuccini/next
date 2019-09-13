UNAME := $(shell uname)

ifeq ($(UNAME),Windows_NT)
	ASM_FLAGS	= -f win64
	ASM_LDFLAGS = -lSystem
endif
ifeq ($(UNAME),CYGWIN_NT-10.0)
	ASM_FLAGS	= -f coff
	ASM_LDFLAGS = 
endif
ifeq ($(UNAME),Linux)
	ASM_FLAGS	= -f elf64
	ASM_LDFLAGS = -lSystem
endif
ifeq ($(UNAME),MacOSX)
	ASM_FLAGS	= -f macho64
	ASM_LDFLAGS = -macosx_version_min 10.14 -lSystem
endif

APPLICATION = output
ASM_LIBRARY	= 64
VERSION 	= 4.7.0
CC      	= /usr/bin/gcc
ASM         = /usr/bin/nasm
CFLAGS  	= -Wall -g -c -D_REENTRANT -DVERSION=\"$(VERSION)\" -Wsizeof-array-argument 
LDFLAGS 	= -pthread -lm 
SRCDIR 		= /Users/edward/Documents/Code/common-lisp/projects/next/output 

OBJ		= runtime.o output.o
ASM_OBJ	= 64.o

$(APPLICATION): $(OBJ)
	$(CC) -o $(APPLICATION) $(OBJ) $(LDFLAGS)

$(ASM_LIBRARY): $(ASM_OBJ)
	nasm -o $(ASM_OBJ) $(ASM_LIBRARY).asm $(ASM_FLAGS)
	ld $(ASM_LDFLAGS) -o $(ASM_LIBRARY) $(ASM_OBJ) 

clean:
	rm -f $(APPLICATION)
	rm -f *.o

%.o: %.asm
	$(ASM) $(ASM_FLAGS) $<

%.o: %.c
	$(CC) $(CFLAGS) -c $<

