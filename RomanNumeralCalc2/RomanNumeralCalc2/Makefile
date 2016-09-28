## makefile for Roman Numeral Calculator Kata
## Brad Rust
## 9/27/2016

#create our compiler and flags variables
CC=gcc
CFLAGS=-g -std=c99 -Wall -Werror
#    link check and include the math? and timer? libs that are throwing errors
LIBS=-lcheck -pthread -lm -lrt

convertObjects=convert.o convertTests.o

all: compileConvertTests.c compConvert runTests

%.o : %.c
	$(CC) $(CFLAGS) -c $< 
#******************************************************************
#might as well put this in the make file. we will be changing the tests a lot
#this needs to be done first since it will change the test objects
compileConvertTests.c: convertTests.check
	checkmk convertTests.check >convertTests.c

#create convertTests executable by linking the convert object
#with the convertTests object that we made, above
#we need all of the libraries for things required in the check frameowork, like floor and timer
compConvert: $(convertObjects)
	$(CC) $(CFLAGS) $(convertObjects) -o convertTests $(LIBS)
#******************************************************************

#compile convert c, make convert object
convert.o: convert.c convert.h
	$(CC) $(CLFAGS) -std=c99 -c convert.c

#create the object for the convert tests
convertTests.o: convertTests.c convert.h
	 $(CC) $(CLFAGS) -c convertTests.c
#******************************************************************

#go ahead and run the tests while we are at it
runTests: runConvertTests

runConverTests: convertTests
	./convertTests
	
#******************************************************************
clean:
	-rm -f *.o runSyntaxTests