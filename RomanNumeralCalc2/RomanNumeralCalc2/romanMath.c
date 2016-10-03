/*
 * romanMath.c
 *
 *  Created on: Sep 29, 2016
 *      Author: Brad Rust
 */
#include <stdio.h>
#include "convert.h"
#include "romanMath.h"
#include "romanError.h"

char *add(char *a, char *b)
{
	int termA, termB;
	if (goodInput(a, b, &termA, &termB) == 0)
		{
			return NULL;
		}
	int sum = termA + termB;
	if (sum < 4000)
		return convertIntToRomanNumeralString(sum);
	return NULL;
}

char *sub(char *a, char *b)
{
	int termA, termB;
	if (!goodInput(a, b, &termA, &termB))
		return NULL;
	int diff = termA - termB;
	if (diff > 0)
		return convertIntToRomanNumeralString(diff);
	return NULL;
}

int goodInput(char *numeralStringA, char *numeralStringB, int *termA, int *termB)
{
	if (numeralStringA == NULL)
	{
		showTermNullMessage('A');
		return 0;
	}
	if (numeralStringB == NULL)
	{
		showTermNullMessage('B');
		return 0;
	}
	*termA = convertRomanNumeralStringToBaseTenInt(numeralStringA);
	*termB = convertRomanNumeralStringToBaseTenInt(numeralStringB);
	if (*termA == 0 || *termB == 0)
		return 0;
	return 1;
}
