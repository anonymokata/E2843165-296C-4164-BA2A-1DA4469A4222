/*
 * romanError.c
 *
 *  Created on: Oct 1, 2016
 *      Author: brad
 */
#include <stdio.h>
#include "romanError.h"

char *showMessage(int messageType, char *value)
{
	char *messages[1];
	messages[0] = "Character not recognized ";
	printf("%s%s\n", messages[messageType], value);
	return NULL;
}

