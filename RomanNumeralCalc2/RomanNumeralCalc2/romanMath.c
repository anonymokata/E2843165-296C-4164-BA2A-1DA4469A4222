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
	int termA = convertRomanNumeralStringToBaseTenInt(a);
	int termB = convertRomanNumeralStringToBaseTenInt(b);
	int sum = termA + termB;
	if (sum < 4000)
		return convertIntToRomanNumeralString(sum);
	return NULL;
}

char *sub(char *a, char *b)
{
	int termA = convertRomanNumeralStringToBaseTenInt(a);
	int termB = convertRomanNumeralStringToBaseTenInt(b);
	int diff = termA - termB;
	if (diff > 0)
		return convertIntToRomanNumeralString(termA - termB);
	return NULL;
}
