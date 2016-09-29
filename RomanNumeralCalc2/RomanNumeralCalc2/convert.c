/*
 * convert.c
 *
 *  Created on: Sep 27, 2016
 *      Author: brad
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "convert.h"

int convertRomanNumeralStringToBaseTenInt(char* numeralString)
{
	int total = 0;
	for (int i = 0; i < strlen(numeralString); i++)
	{
		total += lookAhead(numeralString[i], numeralString[i+1], &i);
		if (total == 0 || total > 3999)
			return 0;
	}
	return total;
}

int lookAhead(char currentChar, char nextChar, int *index)
{
	int first = convertSingleCharacterToInt(currentChar);
	if (nextChar == '\0')
		return first;
	int second = convertSingleCharacterToInt(nextChar);
	if ((second / first >= 50) || ((first == 5 ||first == 50 || first == 500) && (second >= first)))
		return 0;
	if (((5 * first) == second) || ((10 * first) == second))
		{
			*index += 1;
			return (second - first);
		}
	return first;
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
	return 0;
}

char* convertIntToRomanNumeralString(int number)
{
	char *numeralString = malloc (sizeof(char) * 25);
	int index = 0;
	do
	{
		numeralString[index] = convertIntegerValueToNumeralChar(&number);
		index++;
	}
	while (number > 0);
	return numeralString;
}

char convertIntegerValueToNumeralChar(int* number)
{
	if (*number >= 1000)
	{
		*number -= 1000;
		return 'M';
	}
	if (*number >= 900)
	{
		*number += 100;
		return 'C';
	}
	if (*number >= 500)
	{
		*number -= 500;
		return 'D';
	}
	if (*number >= 400)
	{
		*number += 100;
		return 'C';
	}
	if (*number >= 100)
	{
		*number -= 100;
		return 'C';
	}
	if (*number >= 90)
	{
		*number += 10;
		return 'X';
	}
	if (*number >= 50)
	{
		*number -= 50;
		return 'L';
	}
	if (*number >= 40)
	{
		*number += 10;
		return 'X';
	}
	if (*number >= 10)
	{
		*number -= 10;
		return 'X';
	}
	if (*number >= 9)
	{
		*number += 1;
		return 'I';
	}
	if (*number >= 5)
	{
		*number -= 5;
		return 'V';
	}
	if (*number >= 4)
	{
		*number += 1;
		return 'I';
	}
	if (*number >= 1)
	{
		*number -= 1;
		return 'I';
	}
}

