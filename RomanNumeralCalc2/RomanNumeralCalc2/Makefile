## makefile for Roman Numeral Calculator Kata
## Brad Rust
## 9/27/2016

#create our compiler and flags variables
CC=gcc
CFLAGS=-g -std=c99 -Wall -Werror
#    link check and include the math? and timer? libs that are throwing errors
LIBS=-lcheck -pthread -lm -lrt

convertObjects=convert.o convertTests.o
mathObjects = romanMath.o romanMathTests.o

all: makeConvertTests.c makeMathTests.c compConvert compMath runTests

%.o : %.c
	$(CC) $(CFLAGS) -c $< 
#******************************************************************
#might as well put this in the make file. we will be changing the tests a lot
#this needs to be done first since it will change the test .c files
#which get converted to objects. 
makeConvertTests.c: convertTests.check
	checkmk convertTests.check >convertTests.c

makeMathTests.c: romanMathTests.check
	checkmk romanMathTests.check >romanMathTests.c
#******************************************************************

#create convertTests executable by linking the convert objects
#with the convertTests.c file that we made, above
#we need all of the libraries for things required in the check frameowork, like floor and timer
#hence, LIBS
compConvert: $(convertObjects)
	$(CC) $(CFLAGS) $(convertObjects) -o convertTests $(LIBS)
	
compMath: $(mathObjects)
	$(CC) $(CFLAGS) $(mathObjects) -o romanMathTests $(LIBS)
#******************************************************************

#compile convert.c, make convert object
convert.o: convert.c convert.h
	$(CC) $(CLFAGS) -std=c99 -c convert.c

#create the object for the convert tests
convertTests.o: convertTests.c convert.h
	 $(CC) $(CLFAGS) -c convertTests.c
	 
romanMath.o: romanMath.c romanMath.h
	$(CC) $(CFLAGS) -std=c99 -c romanMath.c

romanMathTests.o: romanMathTests.c romanMath.h
	$(CC) $(CFLAGS) -std=c99 -c romanMathTests.c
#******************************************************************

#go ahead and run the tests while we are at it
runTests: convert math

convert: convertTests
	./convertTests
	
math: romanMathTests
	./romanMathTests
	
#******************************************************************
clean:
	-rm -f *.o runSyntaxTests