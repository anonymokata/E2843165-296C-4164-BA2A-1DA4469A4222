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
		if (total == 0)
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

char* convertIntToRomanNumeral(int number)
{
	char * numeralString = malloc (sizeof(char) * 25);
	numeralString[0] = 'I';
	printf("%s\n", numeralString);
	return numeralString;
}


/*int* temp;
*temp = number;
printf("initial val = %d\n", *temp);
char numeralString[25];
	for (int i = 0; i < 25; i++)
		{
			numeralString[i] = convertIntegerValueToNumeral(temp);
			printf("value = %s\n", numeralString);
			if (temp == 0)
				break;
		}
	return numeralString;
	*/
char convertIntegerValueToNumeral(int* integer)
{
	if ((*integer / 1000) >= 0)
	{
		*integer -= 1000;
		return 'M';
	}
	if ((*integer / 500) >= 0)
	{
		*integer -= 500;
		return 'D';
	}
	if ((*integer / 100) >= 0)
	{
		*integer -= 100;
		return 'C';
	}
	if ((*integer / 50) >= 0)
	{
		*integer -= 50;
		return 'L';
	}
	if ((*integer / 10) >= 0)
	{
		*integer -= 10;
		return 'X';
	}
	if ((*integer / 5) >= 0)
	{
		*integer -= 5;
		return 'V';
	}
	if ((*integer / 1) >= 0)
	{
		*integer -= 1;
		return 'I';
	}

}

