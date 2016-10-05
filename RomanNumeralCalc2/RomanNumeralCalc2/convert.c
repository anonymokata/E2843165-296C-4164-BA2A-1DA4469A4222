/*
 * convert.c
 *
 *  Created on: Sep 27, 2016
 *      Author: brad rust
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "convert.h"
#include "romanError.h"

_Bool occurrences[6] = {0, 0, 0, 0, 0, 0};
//this function reports directly to romanMath, and acts as an
//access layer of sorts since all conversion and error reporting functions
//speak to it.
//it takes in a string and outputs an integer. Along the way,
//it and the functions that are called by it do the error checking
//for invalid characters, character pairs, maximum sequential characters
//and single terms that exceed 3999. Each check calls romanError
//directly so that error messages don't have to be routed back to
//this function. Thus, it only reports one general failure mode
int convertRomanNumeralStringToBaseTenInt(char *numeralString)
{
	if (detectFourSequentialCharactersOfSameType(numeralString))
		return 0;
	resetOccurrences();
	int total = 0;
	int i = 0;
	do
	{
		total = checkValue(lookAhead(numeralString[i], numeralString[i+1], &i), total, numeralString);
		i++;
	}while((i < strlen(numeralString)) && (total > 0));
	return total;
}

//this function only detects strings that have more than 3 sequential characters of any type
//VV, LL, DD are caught by the lookAhead function
int detectFourSequentialCharactersOfSameType(char *numeralString)
{

	char currentChar = numeralString[0];
	int charCount = 1;
	for (int i = 1; i < strlen(numeralString); i++)
	{
		if (currentChar == numeralString[i])
		{	charCount++;
			if ((charCount == 2) && (currentChar == 'V' || currentChar == 'L' || currentChar == 'D'))
				return 1;
			if (charCount == 4)
			{
				showExceedsMaximumAllowableFrequencyMessage(numeralString);
				return 1;
			}
		}
		else
			charCount = 1;
		currentChar = numeralString[i];
	}
	return 0;
}
//direct result of refactoring convertRomanNumeralStringToBaseTenInt
//to deal exclusively in good totals/conversions
int checkValue(int lookAheadResult, int currentTotal, char *numeralString)
{
	if (recurs(lookAheadResult))
	{
		showNonValidNumeralStringMessage(numeralString);
		return 0;
	}
	if (lookAheadResult  < 0)
	{
		showBadNumeralStringMessage(numeralString);
		return 0;
	}
	int newTotal = currentTotal + lookAheadResult;
	if (newTotal < 4000)
		return newTotal;
	showTermExceedsMaximumValueMessage(numeralString);
	return 0;
}

//keeps track of how many times the same value was returned
//we should never see these values twice. All other repeats
// (VV, MMMM, LL, DD) are caught elsewhere
int recurs(int result)
{	int terms[6] = {900, 400, 90, 40, 9, 4};
	for (int i = 0; i < 6; i++)
	{
		if (terms[i] == result)//if our result is a value in terms
		{
			occurrences[i] = occurrences[i] == 0 ? 1 : 0;//if not found before, assign 1. else, assign 0
			return !occurrences[i];//return the opposite of the assignment. If it's a 1 now, it hasn't happened before
		}
	}
	return 0;//not one of the terms
}

void resetOccurrences()
{
	for (int i = 0; i < 6; i++)
		occurrences[i] = 0;
}

/*
lookAhead refactor -

    ( I & X  )         OR  ((any V, L, or D) when the second value (is equal to or larger))
(second / first >= 50) || ((first == 5 ||first == 50 || first == 500) && (second >= first))

if it isn't evident, I glommed onto Maurice Karnaugh's mapping idea
and used a positive, graphical solution. This is the "sum of products" of
bad numeral pairs.
IE, if you put the first numeral in rows and the second numeral in columns, then
map what doesn't work, you get patterns that are easy to spot. Instead of making
char comparisons I elected to use their integer conversions.
this might be refactor-able still but I was pleased enough with a one line statement
of logical comparisons

     |I|V|X|L|C|D|M   2nd
1st I| | | |*|*|*|*
    V| |*|*|*|*|*|*
    X| | | | | |*|*
    L| | | |*|*|*|*
    C| | | | | | |
    D| | | | | |*|*
    M| | | | | | |
*/

int lookAhead(char currentChar, char nextChar, int *index)
{
	int first = convertSingleCharacterToInt(currentChar);
	if (nextChar != '\0')
	{
		int second = convertSingleCharacterToInt(nextChar);
		if (first == -1 || second == -1)
			return -1;
		if ((second / first >= 50) || ((first == 5 || first == 50 || first == 500) && (second >= first)))//outright rejections
			{
				showBadNumeralPairMessage(currentChar, nextChar);
				return -2;
			}
		if (((5 * first) == second) || ((10 * first) == second))//subtraction.
		{								//this only works because I have the rejection statement first.
			*index += 1;
			return second - first;
		}
	}
	return first;//gotta wait. only return a single value since we don't have enough information.
}



int convertSingleCharacterToInt(char numeral)
{
	switch (numeral)
	{
		case 'I' :
			return 1;
		case 'V' :
			return 5;
		case 'X' :
			return 10;
		case 'L' :
			return 50;
		case 'C' :
			return 100;
		case 'D' :
			return 500;
		case 'M' :
			return 1000;
	}
	showBadCharMessage(numeral);
	return -1;
}

//A less "visual" approach seemed appropriate here. Use a pseudo lookup table instead
//baseNumerals[] and value[] arrays are the same size and serve as a 1D lookup table
char* convertIntToRomanNumeralString(int number)
{
	char *baseNumerals[14]={"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
	int value[13]={1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
	char *convertedString = malloc (sizeof(char) * 16);
	convertedString[0] = 0;
	int i = 0;
	while(number > 0)
	{
		while(number > value[i])//if the number being converted is larger than the current value in the array
			{					//add the corresponding string of current value to our conversion string
				strcat(convertedString, baseNumerals[i]);
				number -= value[i];
			}
		if (number == value[i])
					return strcat(convertedString, baseNumerals[i]);
		i++;
	}
	return convertedString;
}

