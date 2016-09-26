/*
 * convertNumeralToBaseTen.h
 *
 *  Created on: Sep 25, 2016
 *      Author: brad
 */

#ifndef CONVERT_H_
#define CONVERT_H_

int convertFromRomanNumeralToBaseTen(char* numeralString);
int singleNumeralValue(char numeral);
int pairValue(char firstNumeral, char secondNumeral);
_Bool legalPair(char first, char second);
int lookAhead(int *indexer, char* numeralString);

#endif /* CONVERT_H_ */
