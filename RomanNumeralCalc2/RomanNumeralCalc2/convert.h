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
int getNextConvertableValue(char first, char second, int *index);
char* convertIntToRomanNumeralString(int number);
char* throwError(int _err);
int checkConvertedTermValue(int lookAheadResult, int currentTotal, char *numeralString);
int detectFourSequentialCharactersOfSameType(char *numeralString);
int convertedTermValueExceedsMaximumFrequency(int result, char *numeralString);
void resetTermOccurrences();
_Bool numeralStringAdheresToModernConvention(int convertedValue, int lastConvertedValue, char *numeralString);

#endif /* CONVERT_H_ */
