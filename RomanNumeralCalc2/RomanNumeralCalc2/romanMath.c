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

//add first checks if inputs are good (non-null, non-zero)
//if so, find the sum. if the sum is less than 4000, convert it
//back to Roman numerals. if the value is too large to convert,
//show an error message.
char *add(char *a, char *b)
{
	int termA, termB;
	if (goodInput(a, b, &termA, &termB))
	{
		int sum = termA + termB;
		if (sum < 4000)
			return convertIntToRomanNumeralString(sum);
	}
	showSumExceedsMaximumValueMessage();
	return NULL;
}

//follows same pattern as add
char *sub(char *a, char *b)
{
	int termA, termB;
	if (goodInput(a, b, &termA, &termB))
	{
		int diff = termA - termB;
		if (diff > 0)
			return convertIntToRomanNumeralString(diff);
	}
	showNonValidSubtractionResultMessage();
	return NULL;
}

//ensures both inputs are valid. If either is null, has a single character,
//or a combination of characters that is invalid, the function returns 0
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
		return 0;//wait to report the output so that we can identify the offending string for the user
	return 1;
}
