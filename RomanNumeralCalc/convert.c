/*
 * convertNumeralToBaseTen.c
 *
 *  Created on: Sep 25, 2016
 *      Author: brad
 */
#include "stdlib.h"
#include "string.h"
#include "checkSyntax.h"
#include "convert.h"

int convertFromRomanNumeralToBaseTen(char* numeralString)
{
	int total = 0;
	for (int i = 0; i < strlen(numeralString); i++)
	{
		total += singleNumeralValue(numeralString[i]);
	}
	return total;
}

int lookAhead(int *indexer, char* numeralString)
{
	if (strlen(numeralString) ==(*indexer + 1))//is this the last character?
		return singleNumeralValue(numeralString[*indexer]);
	int value = pairValue(numeralString[*indexer], numeralString[*indexer + 1]);
	return value;
}

int pairValue(char firstNumeral, char secondNumeral)
{
	//if (!legalPair())
		return 4;

}

_Bool legalPair(char first, char second)
{
	if (first == 'I')
		if ((second == 'V') || (second == 'X'))
			return 1;
	if (first == 'X')
		if ((second == 'L') || (second == 'C'))
			return 1;
	if (first == 'C')
			if ((second == 'D') || (second == 'M'))
				return 1;
		return 0;
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
