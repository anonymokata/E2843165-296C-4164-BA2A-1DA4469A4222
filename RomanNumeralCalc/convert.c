/*
 * convertNumeralToBaseTen.c
 *
 *  Created on: Sep 25, 2016
 *      Author: brad
 */
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

int singleNumeralValue(char numeral)
{
	switch (numeral)
	{
		case 'I' :
			return 1;
	}
}
