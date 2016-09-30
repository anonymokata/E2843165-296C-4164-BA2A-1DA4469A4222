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

//lookAhead

//    (1st 3 rows)       OR  ((any V, L, or D) when the first letter (is equal to or larger))
//(second / first >= 50) || ((first == 5 ||first == 50 || first == 500) && (second >= first))

//if it isn't evident, I glommed onto Maurice Karnaugh's mapping idea
//and used a positive, graphical solution. This is the "product of sums" of
//bad numeral pairs.
//IE, if you put the first numeral in rows and the second numeral in columns, then
//map what doesn't work, you get patterns that are easy to spot. Instead of making
//char comparisons I elected to just use their integer conversions.
//this might be refactor-able still but I was pleased enough with a one line statement
//of logical comparisons

int lookAhead(char currentChar, char nextChar, int *index)
{
	int first = convertSingleCharacterToInt(currentChar);
	if (nextChar != '\0')
	{
		int second = convertSingleCharacterToInt(nextChar);
		if ((second / first >= 50) || ((first == 5 ||first == 50 || first == 500) && (second >= first)))
			return 0;
		if (((5 * first) == second) || ((10 * first) == second))//same thing for subtraction.
		{								//this only works because I have the rejection statement first.
			*index += 1;
			return (second - first);
		}
	}
	return first;//you could get "more efficient" and write an addition statement for all known addition pairs,
	             //but everything I wrote was still three bracketed comparisons and these strings are short,
				 //so I left it like this rather than refactor again.
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
	char *numeralString = malloc (sizeof(char) * 16);
	int index = 0;
	while (number > 0)
	{
		numeralString[index] = convertIntegerValueToNumeralChar(&number);
		index++;
	}
	return numeralString;
}

char convertIntegerValueToNumeralChar(int* number)
{
	//I'm not as happy about this solution. It just doens't feel as tidy.
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
	return '%';//this will never be reached (because we are guaranteed good input if we ever get to this function)
			   //but it removes the warning that eclipse was giving.
}

