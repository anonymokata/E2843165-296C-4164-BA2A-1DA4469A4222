/*
 * romanError.c
 *
 *  Created on: Oct 1, 2016
 *      Author: brad
 */
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include "romanError.h"

void showBadCharMessage(char value)
{
	printf("Invalid Roman Numeral char '%c' ", value);
	fflush(stdout);
}

void showBadNumeralPairMessage(char a, char b)
{
	printf("Invalid Roman numeral pair '%c%c' ", a, b);
	fflush(stdout);
}

void showBadNumeralStringMessage(char* value)
{
	printf("in the string '%s'.\n", value);
}

