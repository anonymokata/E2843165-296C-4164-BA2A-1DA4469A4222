/*
 * main.c
 *
 *  Created on: Sep 28, 2016
 *      Author: brad
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "convert.h"

int main(int argc, char *argv)
{
	char *c = convertIntToRomanNumeral(1);
	printf("we get %s\n", c);
	return 0;
}

