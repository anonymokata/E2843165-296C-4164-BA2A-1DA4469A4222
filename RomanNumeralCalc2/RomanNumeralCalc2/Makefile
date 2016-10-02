## makefile for Roman Numeral Calculator Kata
## Brad Rust
## 9/27/2016

#create our compiler and flags variables
CC=gcc
CFLAGS=-g -std=c99 -Wall -Werror -D_GNU_SOURCE
#    link check and include the math? and timer? libs that are throwing errors
LIBS=-lcheck -pthread -lm -lrt

SOURCES = convert.c romanMath.c romanError.c tests.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=tests

all: makeTests.c $(SOURCES) $(EXECUTABLE) runTests

%.o : %.c
	$(CC) $(CFLAGS) -c $<
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@ $(LIBS)
	
.c.o:
	$(CC) $(CFLAGS) $< -o $@

makeTests.c: tests.check
	checkmk tests.check >tests.c

runTests: tests
	./tests
	
#******************************************************************
clean:
	-rm -f *.o runSyntaxTests