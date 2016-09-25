/*
 * convertNumeralToBaseTen.c
 *
 *  Created on: Sep 25, 2016
 *      Author: brad
 */
#include "stdlib.h"
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
