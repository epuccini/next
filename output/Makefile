APPLICATION 	= output
VERSION 	= 4.7.0
CC      	= /usr/bin/gcc
ASM         = /usr/bin/nasm
ASM_FLAGS_OSX	= -f macho64
ASM_FLAGS_LINUX	= -f elf64
ASM_FLAGS_WIN	= -f win64	
ASM_LDFLAGS_OSX = -macosx_version_min 10.14 -lSystem
ASM_LDFLAGS_LINUX = -lSystem
ASM_LDFLAGS_WIN   = -lSystem	
CFLAGS  	= -Wall -g -c -D_REENTRANT -DVERSION=\"$(VERSION)\" -Wsizeof-array-argument 
LDFLAGS 	= -pthread -lm 
SRCDIR 		= /Users/edward/Documents/Code/common-lisp/projects/next/output 

OBJ		= library.o output.o

$(APPLICATION): $(OBJ)
	$(CC) -o $(APPLICATION) $(OBJ) $(LDFLAGS)

clean:
	rm -f $(APPLICATION)
	rm -f *.o

%.o: %.s
	$(ASM) $(ASMFLAGS) $<

%.o: %.c
	$(CC) $(CFLAGS) -c $<

