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

//***************************************************************************************
int termOccurrences[13];
int lastTermConversion;
const int convertedTermValues[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
const int maximumAllowableTermFrequency[13] = {3, 1, 1, 1, 3, 1, 1, 1, 3, 1, 1, 1, 3};
const char *terms[14]={"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
//***************************************************************************************

int convertRomanNumeralStringToBaseTenInt(char *numeralString)
{
	resetTermOccurrences();
	int total = 0;
	int i = 0;
	do
	{	int conversionResultOfSingleTerm = getNextConvertableValue(numeralString[i], numeralString[i+1], &i);
		total = checkConvertedTermValue(conversionResultOfSingleTerm, total, numeralString);
		i++;
	}while((i < strlen(numeralString)) && (total > 0));
	return total;
}

int getNextConvertableValue(char currentChar, char nextChar, int *index)
{
	int firstConvertedTerm = convertSingleCharacterToInt(currentChar);
	if (nextChar != '\0')
	{
		int secondConvertedTerm = convertSingleCharacterToInt(nextChar);
		if (firstConvertedTerm == -1 || secondConvertedTerm == -1)
			return -1;
		if ((secondConvertedTerm / firstConvertedTerm >= 50) || ((firstConvertedTerm == 5 || firstConvertedTerm == 50 || firstConvertedTerm == 500) && (secondConvertedTerm >= firstConvertedTerm)))
			{
				showBadNumeralPairMessage(currentChar, nextChar);
				return -2;
			}
		if (((5 * firstConvertedTerm) == secondConvertedTerm) || ((10 * firstConvertedTerm) == secondConvertedTerm))
		{
			*index += 1;
			return secondConvertedTerm - firstConvertedTerm;
		}
	}
	return firstConvertedTerm;
}

int checkConvertedTermValue(int convertedTermValue, int currentTotal, char *numeralString)
{
	if (convertedTermValue  < 0)
	{
		showBadNumeralStringMessage(numeralString);
		return 0;
	}
	if (convertedTermValueExceedsMaximumFrequency(convertedTermValue, numeralString) > 0)
	{
		showViolatesModernConventionMessage(numeralString);
		return 0;
	}
	int newTotal = currentTotal + convertedTermValue;
	if (newTotal < 4000)
		return newTotal;
	showTermExceedsMaximumValueMessage(numeralString);
	return 0;
}

int convertedTermValueExceedsMaximumFrequency(int result, char *numeralString)
{
	for (int i = 0; i < 13; i++)
	{
		if (convertedTermValues[i] == result)
		{
			if (!numeralStringAdheresToModernConvention(result, lastTermConversion, numeralString))
				return 1;
			lastTermConversion = result;
			termOccurrences[i] += 1;
			return termOccurrences[i] > maximumAllowableTermFrequency[i] ? 1 : 0;
		}
	}
	return 0;
}

_Bool numeralStringAdheresToModernConvention(int convertedTermValue, int lastConvertedTermValue, char *numeralString)
{
	if (convertedTermValue > lastConvertedTermValue)
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

char* convertIntToRomanNumeralString(int intToConvert)
{
	char *convertedString = malloc (sizeof(char) * 16);
	convertedString[0] = 0;
	int i = 0;
	while(intToConvert > 0)
	{
		while(intToConvert > convertedTermValues[i])//global const convertedTermValues = [1000, 900, 500...
			{
				strcat(convertedString, terms[i]);
				intToConvert -= convertedTermValues[i];
			}
		if (intToConvert == convertedTermValues[i])
			return strcat(convertedString, terms[i]);
		i++;
	}
	return convertedString;
}

void resetTermOccurrences()
{
	for (int i = 0; i < 13; i++)
		termOccurrences[i] = 0;
	lastTermConversion = 1000;
}
