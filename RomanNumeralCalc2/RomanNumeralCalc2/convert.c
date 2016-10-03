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

int convertRomanNumeralStringToBaseTenInt(char* numeralString)
{
	int total = 0;
	int check = 0;
	for (int i = 0; i < strlen(numeralString); i++)
	{
		check = lookAhead(numeralString[i], numeralString[i+1], &i);
		total += check;
		if (total > 3999 || check < 0)
		{
			showBadNumeralStringMessage(numeralString);
			return 0;
		}
	}
	return total;
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
	char *numeralString = malloc (sizeof(char) * 16);
	numeralString[0] = 0;
	while (number >= 1000)
	{
		number -= 1000;
		strcat(numeralString, "M");
	}
	if(number >= 900)
	{
		number -= 900;
		strcat(numeralString, "CM");
	}
	if (number >= 500)
	{
		number -= 500;
		strcat(numeralString, "D");
	}
	if (number >= 400)
	{
		number -= 400;
		strcat(numeralString, "CD");
	}
	while (number >= 100)
	{
		number -= 100;
		strcat(numeralString, "C");
	}
	if (number >= 90)
	{
		number -= 90;
		strcat(numeralString, "XC");
	}
	if (number >= 50)
	{
		number -= 50;
		strcat(numeralString, "L");
	}
	if (number >= 40)
	{
		number -= 40;
		strcat(numeralString, "XL");
	}
	while (number >= 10)
	{
		number -= 10;
		strcat(numeralString, "X");
	}
	if (number == 9)
		return strcat(numeralString, "IX");
	else if (number >= 5)
		{
			number -= 5;
			strcat(numeralString, "V");
		}
	else if (number == 4)
		return strcat(numeralString, "IV");
	while(number >= 1)
	{
		number -= 1;
		strcat(numeralString, "I");
	}
	return numeralString;
}

