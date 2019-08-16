APPLICATION 	= output
VERSION 	= 4.7.0
CC      	= /usr/bin/gcc
CFLAGS  	= -Wall -g -c -D_REENTRANT -DVERSION=\"$(VERSION)\"
LDFLAGS 	= -pthread -lm
SRCDIR 		= /usr/local/src/async

OBJ		= output.o

$(APPLICATION): $(OBJ)
	$(CC) -o $(APPLICATION) $(OBJ) $(LDFLAGS)

clean:
	rm -f $(APPLICATION)
	rm -f *.o

%.o: %.c
	$(CC) $(CFLAGS) -c $<
