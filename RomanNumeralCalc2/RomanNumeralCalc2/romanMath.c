/*
 * romanMath.c
 *
 *  Created on: Sep 29, 2016
 *      Author: brad
 */
#include <stdio.h>
#include "convert.h"
#include "romanMath.h"

char *add(char *a, char *b)
{
	int sum = convertRomanNumeralStringToBaseTenInt(a) + convertRomanNumeralStringToBaseTenInt(b);
	if (sum < 4000)
		return convertIntToRomanNumeralString(sum);
	return NULL;
}

char *sub(char *a, char *b)
{
	int diff = convertRomanNumeralStringToBaseTenInt(a) - convertRomanNumeralStringToBaseTenInt(b);
	if (diff > 0)
		return convertIntToRomanNumeralString(diff);
	return NULL;
}
