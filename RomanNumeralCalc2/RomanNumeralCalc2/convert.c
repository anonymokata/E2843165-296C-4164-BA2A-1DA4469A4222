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
#include "romanError.h"

char* globalNumeralString = NULL;

int convertRomanNumeralStringToBaseTenInt(char* _numeralString)
{
	globalNumeralString = _numeralString;
	int total = 0;
	int i = 0;
	do
	{
		total = checkValue(lookAhead(globalNumeralString[i], globalNumeralString[i+1], &i), total);
		i++;
	}while((i < strlen(globalNumeralString)) && (total > 0));
	return total;
}

int checkValue(int lookAheadResult, int currentTotal)
{
	if (lookAheadResult  < 0)
	{
		showBadNumeralStringMessage(globalNumeralString);
		return 0;
	}
	int newTotal = currentTotal + lookAheadResult;
	if (newTotal < 4000)
		return newTotal;
	showTermExceedsMaximumValueMessage(globalNumeralString);
	return 0;
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
		if ((second / first >= 50) || ((first == 5 || first == 50 || first == 500) && (second >= first)))
			{
				showBadNumeralPairMessage(currentChar, nextChar);
				return -2;
			}
		if (((5 * first) == second) || ((10 * first) == second))//same thing for subtraction.
		{								//this only works because I have the rejection statement first.
			*index += 1;				//if the string was larger and I expected more good input than bad
			return (second - first);   //I would probably do the opposite and put this first, then alter the
		}                              //bad input filter to not overlap rejection
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
	showBadCharMessage(numeral);
	return -1;
}

char* convertIntToRomanNumeralString(int number)
{
	_Bool show = 0;
	if (number == 1)
		show = 1;
	char *baseNumerals[14]={"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
	int value[13]={1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
	char *numeralString = malloc (sizeof(char) * 16);
	numeralString[0] = 0;
	int i = 0;
	while(number > 0)
	{
		while(number > value[i])
			{
				strcat(numeralString, baseNumerals[i]);
				if(show)
					printf("i = %d and val = %d. meanwhile, string is %s\n", i, number, numeralString);
				number -= value[i];
			}
		if (number == value[i])//save iterations
			return strcat(numeralString, baseNumerals[i]);
		i++;
	}
	return numeralString;
}

