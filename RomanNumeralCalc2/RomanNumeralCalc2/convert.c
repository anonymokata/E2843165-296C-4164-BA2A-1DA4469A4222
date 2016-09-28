/*
 * convert.c
 *
 *  Created on: Sep 27, 2016
 *      Author: brad
 */
#include "stdio.h"
#include "convert.h"
#include "string.h"

int convertRomanNumeralStringToBaseTenInt(char* numeral)
{
	int total = 0;
	for (int i = 0; i < strlen(numeral); i++)
		total += convertSingleCharacterToInt(numeral[i]);
	return total;
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
