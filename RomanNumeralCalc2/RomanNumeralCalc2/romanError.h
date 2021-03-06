/*
 * romanError.h
 *
 *  Created on: Oct 1, 2016
 *      Author: brad
 */

#ifndef ROMANERROR_H_
#define ROMANERROR_H_

void showBadCharMessage(char value);
void showBadNumeralPairMessage(char a, char b);
void showBadNumeralStringMessage(char* value);
void showTermExceedsMaximumValueMessage(char* value);//single term
void showTermNullMessage(char term);
void showNonValidSubtractionResultMessage();
void showSumExceedsMaximumValueMessage();//total of both terms
void showViolatesModernConventionMessage(char *value);
void showLastConvertedValueLessThanCurrentValue();

#endif /* ROMANERROR_H_ */
