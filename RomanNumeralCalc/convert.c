/*
 * convertNumeralToBaseTen.c
 *
 *  Created on: Sep 25, 2016
 *      Author: brad
 */
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "checkSyntax.h"
#include "convert.h"

_Bool badInput = 0;

int convertFromRomanNumeralToBaseTen(char* numeralString)
{
	//TODO : write a way to check for maximum numeral occurrence
	int total = 0, bound = strlen(numeralString), tempVal;
	for (int i = 0; i < bound; i++)
	{
		tempVal = lookAhead(&i, numeralString);
		total += tempVal;
	}
	return total;
}

//lookAhead - looks at current character and the next value
//uses pairValue to to get their additive or subtractive qualities
//pairValue uses legalPair to determine if the character set is valid
//know that I have to implement the max character checking, but couldn't
//think of a way to drive that with TDD right away.
int lookAhead(int *indexer, char* numeralString)
{
	if (!(numeralString[*indexer + 1]))//is this the last character?
		return singleNumeralValue(numeralString[*indexer]);
	int value = pairValue(numeralString[*indexer], numeralString[*indexer + 1]);
	*indexer = *indexer + 1;
	return value;
}

//if the pair is legal, get its value
int pairValue(char firstNumeral, char secondNumeral)
{
	if (!legalPair(firstNumeral, secondNumeral))
		return -1;
	int firstNumeralValue = singleNumeralValue(firstNumeral);
	int secondNumeralValue = singleNumeralValue(secondNumeral);
	return firstNumeralValue < secondNumeralValue ? (secondNumeralValue - firstNumeralValue) : (firstNumeralValue + secondNumeralValue);
}

//checks for a pair of legal numerals
_Bool legalPair(char first, char second)
{
	switch (first)
	{
		case 'I' :
			if ((second == 'V') || (second == 'X') || (second == 'I'))
				return 1;
		case 'V' :
			if (second == 'I')
				return 1;
		case 'X' :
			if (second == 'D' || second == 'M')
				return 0;
			return 1;
		case 'L' :
			if (second == 'I' || second == 'V' || second == 'X')
				return 1;
		case 'C' :
			return 1;
		case 'D' :
			if (second == 'D' || second == 'M')
				return 0;
			return 1;
		case 'M' :
			return 1;
		default :
			return 0;
	}
}

int singleNumeralValue(char numeral)
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
}
