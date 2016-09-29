/*
 * convert.h
 *
 *  Created on: Sep 27, 2016
 *      Author: brad
 */

#ifndef CONVERT_H_
#define CONVERT_H_

int convertRomanNumeralStringToBaseTenInt(char* numeral);
int convertSingleCharacterToInt(char numeral);
int lookAhead(char first, char second, int *index);
char* convertIntToRomanNumeralString(int number);
char convertIntegerValueToNumeralChar(int* integer);

#endif /* CONVERT_H_ */
