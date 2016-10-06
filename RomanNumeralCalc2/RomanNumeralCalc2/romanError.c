/*
 *  romanError.c
 *  Created on: Oct 1, 2016
 *  Author: Brad Rust
 */
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "romanError.h"

void showBadCharMessage(char value)
{
	fprintf(stderr, "Invalid Roman Numeral char '%c' ", value);
	fflush(stdout);
}

void showBadNumeralPairMessage(char a, char b)
{
	fprintf(stderr, "Error. Invalid Roman numeral pair '%c%c' ", a, b);
	fflush(stdout);
}

void showBadNumeralStringMessage(char* value)
{
	fprintf(stderr, "in the string '%s'.\n", value);
}

void showTermExceedsMaximumValueMessage(char *value)
{
	fprintf(stderr, "Numeral string '%s' exceeds maximum allowable value of 3999.\n", value);
}

void showSumExceedsMaximumValueMessage()
{
	fprintf(stderr, "Error. Addition results in sum that exceeds maximum allowable value of 3999.\n");
}

void showTermNullMessage(char term)
{
	fprintf(stderr, "Error. Term %c null.\n", term);
}

void showNonValidSubtractionResultMessage()
{
	fprintf(stderr, "Error. Subtraction results are not a valid Roman numeral (negative or zero).\n");
}

void showViolatesModernConventionMessage(char *value)
{
	fprintf(stderr, "Error. Numeral string '%s' violates modern convention.\n", value);
}
