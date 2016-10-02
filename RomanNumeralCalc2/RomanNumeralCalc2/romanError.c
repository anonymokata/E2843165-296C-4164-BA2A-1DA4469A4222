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

void showCharMessage(char value)
{
	printf("Invalid Roman Numeral char '%c'.\n", value);
}

void showBadNumeralPair(char a, char b)
{
	printf("Invalid Roman numeral pair '%c%c'.\n", a, b);
}


