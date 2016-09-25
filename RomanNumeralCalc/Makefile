## makefile for Roman Numeral Calculator Kata
## Brad Rust
## 9/24/2016

#create our compiler and flags variables
CC=gcc
CFLAGS= -g -std=c99 -Wall -Werror
#supposedly lcheck is enough, but I needed the other three to squelch the litanny of errors regarding timers and the like
LIBS=-lcheck -pthread -lm -lrt

all: compileTests.c testSyntax runTests

%.o : %.c
	$(CC) $(CFLAGS) $<

#might as well put this in the make file. we will be changing the tests a lot
#this needs to be done first since it will change checkSyntaxTests.o
compileTests.c: checkSyntaxTests.check
	checkmk  checkSyntaxTests.check >checkSyntaxTests.c

#create runSyntaxTests executable by linking the checkSyntax object
#with the checkSyntaxTests object that we made, above
testSyntax: checkSyntax.o checkSyntaxTests.o
	$(CC) checkSyntax.o checkSyntaxTests.o -o runSyntaxTests $(LIBS)

#compile checkSyntax c, make object
checkSyntax.o: checkSyntax.c checkSyntax.h
	$(CC) -c checkSyntax.c

#create the object for the 'IsTheCharacter_an_I_X_or_C' test
checkSyntaxTests.o: checkSyntaxTests.c checkSyntax.h 
	$(CC) -c checkSyntaxTests.c

#go ahead and run the test while we are at it	
runTests: runSyntaxTests
	./runSyntaxTests
	
clean:
	-rm -f *.o runSyntaxTests