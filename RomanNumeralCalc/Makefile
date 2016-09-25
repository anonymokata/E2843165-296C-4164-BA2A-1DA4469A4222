## makefile for Roman Numeral Calculator Kata
## Brad Rust
## 9/24/2016

#create our compiler and flags variables
CC=gcc
CFLAGS=-g -std=c99 -Wall -Werror
#supposedly lcheck is enough, but I needed the other three to squelch the litanny of errors for timers and the like
LIBS=-lcheck -pthread -lm -lrt
checkSyntaxObj=checkSyntax.o checkSyntaxTests.o
convertObjects=convert.o convertTests.o

all: compileSyntaxTests.c compileConvertTests.c compSyntax compConvert runTests

%.o : %.c
	$(CC) $(CFLAGS) -c $< 
#******************************************************************
#might as well put this in the make file. we will be changing the tests a lot
#this needs to be done first since it will change the test objects
compileSyntaxTests.c: checkSyntaxTests.check
	checkmk  checkSyntaxTests.check >checkSyntaxTests.c

compileConvertTests.c: convertTests.check
	checkmk  convertTests.check >convertTests.c

#*******************************************************************
#create syntaxTests executable by linking the checkSyntax object
#with the checkSyntaxTests object that we made, above
compSyntax: $(checkSyntaxObj)
	$(CC) $(CLFAGS) $(checkSyntaxObj) -o syntaxTests $(LIBS)

#create the convertTests exe by doing the same thing as above
compConvert: $(convertObjects)
	$(CC) $(CFLAGS) $(convertObjects) -o convertTests $(LIBS)
#******************************************************************

#compile checkSyntax c, make checkSyntax object
checkSyntax.o: checkSyntax.c checkSyntax.h
	$(CC) $(CLFAGS) -c checkSyntax.c

#create the object for the checkSyntax tests
checkSyntaxTests.o: checkSyntaxTests.c checkSyntax.h 
	$(CC) $(CLFAGS) -c checkSyntaxTests.c
	
convert.o: convert.c convert.h
	$(CC) $(CLFAGS) -std=c99 -c convert.c

convertTests.o: convertTests.c convert.h
	 $(CC) $(CLFAGS) -c convertTests.c
#******************************************************************

#go ahead and run the tests while we are at it
runTests: runSyntaxTests runConvertTests

runConvertTests: convertTests
	./convertTests
	
runSyntaxTests: syntaxTests
	./syntaxTests

#******************************************************************
clean:
	-rm -f *.o runSyntaxTests