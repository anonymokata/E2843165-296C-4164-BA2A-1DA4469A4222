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
void showTermExceedsMaximumValueMessage(char* value);
void showTermNullMessage(char term);
void showNonValidSubtractionResult();
void showSumExceedsMaximumValueMessage();

#endif /* ROMANERROR_H_ */
