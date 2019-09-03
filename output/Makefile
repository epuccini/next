APPLICATION 	= output
VERSION 	= 4.7.0
CC      	= /usr/bin/gcc
ASM             = /usr/bin/nasm
ASMFLAGS	= -f elf64
CFLAGS  	= -Wall -g -c -D_REENTRANT -DVERSION=\"$(VERSION)\" 
LDFLAGS 	= -pthread -lm
SRCDIR 		= /Users/edward/Documents/Code/common-lisp/projects/next/output 

OBJ		= output.o

$(APPLICATION): $(OBJ)
	$(CC) -o $(APPLICATION) $(OBJ) $(LDFLAGS)

clean:
	rm -f $(APPLICATION)
	rm -f *.o

%.o: %.s
	$(ASM) $(ASMFLAGS) $<

%.o: %.c
	$(CC) $(CFLAGS) -c $<

