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
	printf("Invalid Roman Numeral char '%c'.\n", value);
}



