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
	printf("%s\n", convertIntToRomanNumeralString(termA + termB));
	return convertIntToRomanNumeralString(termA + termB);
}

