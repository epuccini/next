UNAME := $(shell uname)

APPLICATION 	= output
PIDIGITS		= output
NEXT      		= ../bin/next
SRCDIR 			= /Users/edward/Documents/Code/common-lisp/projects/next/src 
SRC_EXAMPLE		= ../src/example.next
SRC_PIDIGITS	= ../src/pidigits.next

$(APPLICATION): $(OBJ)
	$(NEXT) -c $(SRC_EXAMPLE) -o ../output/$(APPLICATION)
pi:
	$(NEXT) -c $(SRC_PIDIGITS) -o ../output/$(APPLICATION)


clean:
	rm -f ../output/$(APPLICATION)
	rm -f ../output/$(PIDIGITS)
