/*
 * convert.c
 *
 *  Created on: Sep 27, 2016
 *      Author: brad rust
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "convert.h"
#include "romanError.h"

int occurrences[13];
int lastOccurrence, lastResult;

int convertRomanNumeralStringToBaseTenInt(char *numeralString)
{
	resetOccurrences();
	int total = 0;
	int i = 0;
	do
	{	int result = lookAhead(numeralString[i], numeralString[i+1], &i);
		total = checkValue(result, total, numeralString);
		i++;
	}while((i < strlen(numeralString)) && (total > 0));
	return total;
}

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
		{
			*index += 1;
			return second - first;
		}
	}
	return first;
}


int checkValue(int lookAheadResult, int currentTotal, char *numeralString)
{
	if (lookAheadResult  < 0)
	{
		showBadNumeralStringMessage(numeralString);
		return 0;
	}
	if (convertedValueExceedsMaximumFrequency(lookAheadResult, numeralString) > 0)
	{
		showViolatesModernConventionMessage(numeralString);
		return 0;
	}
	int newTotal = currentTotal + lookAheadResult;
	if (newTotal < 4000)
		return newTotal;
	showTermExceedsMaximumValueMessage(numeralString);
	return 0;
}

int convertedValueExceedsMaximumFrequency(int result, char *numeralString)
{	int conertedValues[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
	int maximumAllowableFrequency[13] = {3, 1, 1, 1, 3, 1, 1, 1, 3, 1, 1, 1, 3};
	for (int i = 0; i < 13; i++)
	{
		if (conertedValues[i] == result)
		{
			if (!numeralStringAdheresToModernConvention(result, lastResult, numeralString))
				return 1;
			lastResult = result;
			occurrences[i] += 1;
			return occurrences[i] > maximumAllowableFrequency[i] ? 1 : 0;
		}
	}
	return 0;
}

_Bool numeralStringAdheresToModernConvention(int convertedValue, int lastConvertedValue, char *numeralString)
{
	if (convertedValue > lastConvertedValue)
	{
		showViolatesModernConventionMessage(numeralString);
		return 0;
	}
	return 1;
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

char* convertIntToRomanNumeralString(int number)
{
	char *baseNumerals[14]={"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
	int value[13]={1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};//make me a global const when you refactor
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

void resetOccurrences()
{
	for (int i = 0; i < 13; i++)
		occurrences[i] = 0;
	lastOccurrence = 0;
	lastResult = 1000;
}
