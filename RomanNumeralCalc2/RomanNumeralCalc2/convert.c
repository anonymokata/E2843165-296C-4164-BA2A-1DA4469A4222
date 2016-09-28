/*
 * convert.c
 *
 *  Created on: Sep 27, 2016
 *      Author: brad
 */
#include "stdio.h"
#include "convert.h"
#include "string.h"

int convertRomanNumeralStringToBaseTenInt(char* numeralString)
{
	int total = 0;
	for (int i = 0; i < strlen(numeralString); i++)
		total += lookAhead(numeralString[i], numeralString[i+1], &i);
	return total;
}

int lookAhead(char currentChar, char nextChar, int *index)
{
	int first = convertSingleCharacterToInt(currentChar);
	if (nextChar == '\0')
		return first;
	int second = convertSingleCharacterToInt(nextChar);
	switch (currentChar)
	{
		case 'I' :
			if (nextChar == 'V' || nextChar == 'X')
			{
				*index = *index + 1;
				return (second - first);
			}
		default :
			return first;
	}
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

}
