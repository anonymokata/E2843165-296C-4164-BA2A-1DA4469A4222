/*
 * DO NOT EDIT THIS FILE. Generated by checkmk.
 * Edit the original source file "tests.check" instead.
 */

#include <check.h>

#line 1 "tests.check"
#include "convert.h"
#include "romanMath.h"
#include "romanError.h"
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>

//*************************************************************************************
//these functions assist in the romanError tests by redirecting the console output to a text file
//and then checking the desired result against the text file

void writeToConsoleTextFile()
{
	int consoleTextDescr = open("consoleText.txt", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
	dup2(consoleTextDescr, 2);
	close(consoleTextDescr);	
}
char *getStdoutTextWrittenToFile()
{
	int consoleTextDescr = open("consoleText.txt", O_RDONLY);
	char *text = malloc (sizeof(char) * 255);
	read(consoleTextDescr, text, 255);
	return text;
}

//*************************************************************************************************************

START_TEST(convertFromRomanNumeralToBaseTenTest)
{
#line 32
	fail_unless(convertRomanNumeralStringToBaseTenInt("I") == 1,"Failed to convert I to 1");
	fail_unless(convertRomanNumeralStringToBaseTenInt("V") == 5,"Failed to convert V to 5");
	fail_unless(convertRomanNumeralStringToBaseTenInt("X") == 10,"Failed to convert X to 10");
	fail_unless(convertRomanNumeralStringToBaseTenInt("L") == 50,"Failed to convert L to 50");
	fail_unless(convertRomanNumeralStringToBaseTenInt("C") == 100,"Failed to convert C to 100");
	fail_unless(convertRomanNumeralStringToBaseTenInt("D") == 500,"Failed to convert D to 500");
	fail_unless(convertRomanNumeralStringToBaseTenInt("M") == 1000,"Failed to convert M to 1000");
	
	
	fail_unless(convertRomanNumeralStringToBaseTenInt("VI") == 6,"Failed to convert VI to 6");
	fail_unless(convertRomanNumeralStringToBaseTenInt("CIII") == 103,"Failed to convert CIII to 103");
	fail_unless(convertRomanNumeralStringToBaseTenInt("MMCCXXVI") == 2226,"Failed to convert MMCCXXVI to 2226");
	
	fail_unless(convertRomanNumeralStringToBaseTenInt("IV") == 4,"Failed to convert IV to 4");
	fail_unless(convertRomanNumeralStringToBaseTenInt("IX") == 9,"Failed to convert IX to 9");
	fail_unless(convertRomanNumeralStringToBaseTenInt("XL") == 40,"Failed to convert XL to 40");
	fail_unless(convertRomanNumeralStringToBaseTenInt("XC") == 90,"Failed to convert XC to  90");
	fail_unless(convertRomanNumeralStringToBaseTenInt("CD") == 400,"Failed to convert CD to 400");
	fail_unless(convertRomanNumeralStringToBaseTenInt("CM") == 900,"Failed to convert CM to  900");
	
	fail_unless(convertRomanNumeralStringToBaseTenInt("MCMXXVII") == 1927,"Failed to convert MCMXXVII to 1927");
	
	fail_unless(convertRomanNumeralStringToBaseTenInt("VV") == 0,"Failed to recognize bad input, VV");
	fail_unless(convertRomanNumeralStringToBaseTenInt("LL") == 0,"Failed to recognize bad input, LL");
	fail_unless(convertRomanNumeralStringToBaseTenInt("ID") == 0,"Failed to recognize bad input, ID");
	fail_unless(convertRomanNumeralStringToBaseTenInt("XD") == 0,"Failed to recognize bad input, XD");
	
}
END_TEST

START_TEST(convertIntToRomanNumeralTest)
{
#line 60
	ck_assert_msg(strcmp(convertIntToRomanNumeralString(1),  "I") == 0,"Failed to convert 1 to I");
	ck_assert_msg(strcmp(convertIntToRomanNumeralString(1000),  "M") == 0,"Failed to convert 1000 to M");
	ck_assert_msg(strcmp(convertIntToRomanNumeralString(1500),  "MD") == 0,"Failed to convert 1500 to MD");
	ck_assert_msg(strcmp(convertIntToRomanNumeralString(3200),  "MMMCC") == 0,"Failed to convert 3200 to MMMCC");
	ck_assert_msg(strcmp(convertIntToRomanNumeralString(65),  "LXV") == 0,"Failed to convert 65 to LXV");
	ck_assert_msg(strcmp(convertIntToRomanNumeralString(4),  "IV") == 0,"Failed to convert 4 to IV");
	ck_assert_msg(strcmp(convertIntToRomanNumeralString(9),  "IX") == 0,"Failed to convert 9 to IX");
	ck_assert_msg(strcmp(convertIntToRomanNumeralString(40),  "XL") == 0,"Failed to convert 44 to XL");
	ck_assert_msg(strcmp(convertIntToRomanNumeralString(90),  "XC") == 0,"Failed to convert 90 to XC");
	ck_assert_msg(strcmp(convertIntToRomanNumeralString(400),  "CD") == 0,"Failed to convert 400 to CD");
	ck_assert_msg(strcmp(convertIntToRomanNumeralString(900),  "CM") == 0,"Failed to convert 900 to CM");
	ck_assert_msg(strcmp(convertIntToRomanNumeralString(3999),  "MMMCMXCIX") == 0,"Failed to convert 3999 to MMMCMXCIX");

}
END_TEST

START_TEST(exceedsMaximum)
{
#line 74
	fail_unless(convertRomanNumeralStringToBaseTenInt("MMMCMXCIXI") == 0,"Failed to rejct number larger than 3999");
	
//******************************************************************************************************************************

}
END_TEST

START_TEST(additionCheck)
{
#line 79
	ck_assert_msg(strcmp(add("V", "I"), "VI") == 0,"Failed to add V + I");
	fail_unless(add("MXIVV", "I") == NULL,"Failed to recognize bad input");
	ck_assert_msg(strcmp(add("XXXII", "LXIV"), "XCVI") == 0, "Failed to add XXXII + LXIV"); 
	ck_assert_msg(strcmp(add("IV", "V"), "IX") == 0, "Failed to add IV + V");
	ck_assert_msg(strcmp(add("MMMCMXCVIII", "I"), "MMMCMXCIX") == 0, "Failed to add MMMCMXCVIII + I");
	ck_assert_msg(strcmp(add("MMMDCCCLXXXVIII", "II"), "MMMDCCCXC") == 0, "Failed to add MMMDCCCLXXXVIII + II");
	fail_unless(add("MMM", "M") == NULL,"Add func failed to recognize sum larger than allowable maximum");
	fail_unless(add("X", NULL) == NULL,"Add func failed to recognize NULL value");
	fail_unless(add("XIXX", "I") == NULL, "Failed to recognize improper input.");
}
END_TEST

START_TEST(subtractionCheck)
{
#line 89
	ck_assert_msg(strcmp(sub("V", "I"), "IV") == 0,"Failed to subtract V - I");
	ck_assert_msg(strcmp(sub("DCLIX", "XCIX"), "DLX") == 0,"Failed to subtract DCLIX - XCIX");
	fail_unless(sub("C", "MM") == NULL,"Sub func failed to recognize negative value");
	fail_unless(sub(NULL, "MM") == NULL,"Sub func failed to recognize NULL value");
	fail_unless(sub("CCC", "CCC") == NULL,"Sub func failed to recognize zero");

}
END_TEST

START_TEST(addAndSubReturnNullForBadSingleTerm)
{
#line 96
	fail_unless(sub("*", "I") == NULL,"Failed to recognize bad A term");
	fail_unless(add("I", "VD") == NULL,"Failed to recognize bad B term");

}
END_TEST

START_TEST(repeatingTermsTest)
{
#line 100
	fail_unless(add("MXIVIV", "I") == NULL,"Failed to recognize bad input");

}
END_TEST

START_TEST(convertedValuesOutOfOrder)
{
#line 103
	fail_unless(add("DCIVX", "XVI") == NULL, "Failed to recognize bad input");
	
//******************************************************************************************************************************
//Input Errors & Messages

}
END_TEST

START_TEST(characterExceedsMaximumFrequency)
{
#line 109
 	fail_unless(convertRomanNumeralStringToBaseTenInt("CCCCC") == 0, "Failed to detect maximum character frequency in numeral string");

}
END_TEST

START_TEST(badRomanNumeralCharacter)
{
#line 112
	writeToConsoleTextFile();
	ck_assert_int_eq(convertSingleCharacterToInt('J'), -1);
	char *message = "Invalid Roman Numeral char 'J'";
	ck_assert_msg(strncmp(getStdoutTextWrittenToFile(), message, strlen(message)) == 0,"Failed to show bad character message");
	
}
END_TEST

START_TEST(badlookAheadPairs)
{
#line 118
	writeToConsoleTextFile();
	fail_unless(lookAhead('I', 'C', 0) == -2, "Conversion of non Roman Numeral to int test failed (lookAhead)");
	char *message1 = "Invalid Roman numeral pair 'IC'";
	ck_assert_msg(strncmp(getStdoutTextWrittenToFile(), message1, strlen(message1)) == 0,"Failed to show bad pair message");
	
}
END_TEST

START_TEST(badConversionToBaseTen)
{
#line 124
	writeToConsoleTextFile();
	ck_assert_msg(convertRomanNumeralStringToBaseTenInt("MIM") == 0, "convertRomanNumeralStringToBaseTen fails to catch bad input MC%");
	char *message2 = "Invalid Roman numeral pair 'IM' in the string 'MIM'.";
	ck_assert_msg(strncmp(getStdoutTextWrittenToFile(), message2, strlen(message2)) == 0,"Failed to show bad conversion messages");
	
}
END_TEST

START_TEST(termExceeds3999MessageTest)
{
#line 130
	writeToConsoleTextFile();
	convertRomanNumeralStringToBaseTenInt("MMMCMXCIXI");
	char *message3 = "Numeral string 'MMMCMXCIXI' exceeds maximum allowable value of 3999.";
	ck_assert_msg(strncmp(getStdoutTextWrittenToFile(), message3, strlen(message3)) == 0,"Failed to show exceeeds 3999 message");

}
END_TEST

START_TEST(nullStringPassedAsArgSub)
{
#line 136
	writeToConsoleTextFile();
	sub(NULL, "MM");
	char *message4 = "Error. Term A null.";
	ck_assert_msg(strncmp(getStdoutTextWrittenToFile(), message4, strlen(message4)) == 0,"Sub func failed to show null arg message");
	
}
END_TEST

START_TEST(nullStringPassedAsArgAdd)
{
#line 142
	writeToConsoleTextFile();
	add("CC", NULL);
	char *message5 = "Error. Term B null.";
	ck_assert_msg(strncmp(getStdoutTextWrittenToFile(), message5, strlen(message5)) == 0,"Add func failed to show null arg message");

}
END_TEST

START_TEST(subtractionYieldsNonValidRomanNumeral)
{
#line 148
	writeToConsoleTextFile();
	sub("CC", "MD");
	char *message6 = "Error. Subtraction results are not a valid Roman numeral (negative or zero).";
	ck_assert_msg(strncmp(getStdoutTextWrittenToFile(), message6, strlen(message6)) == 0,"Sub func failed to show invalid result message");

}
END_TEST

START_TEST(sumExceedsMaximumValueErrorMessageTest)
{
#line 154
	writeToConsoleTextFile();
	add("MMM", "M");
	char *message7 = "Error. Addition results in sum that exceeds maximum allowable value of 3999.";
	ck_assert_msg(strncmp(getStdoutTextWrittenToFile(), message7, strlen(message7)) == 0,"Add func failed to show sum exceeds maximum allowable value message");
 
	
}
END_TEST

int main(void)
{
    Suite *s1 = suite_create("Core");
    TCase *tc1_1 = tcase_create("Core");
    SRunner *sr = srunner_create(s1);
    int nf;

    suite_add_tcase(s1, tc1_1);
    tcase_add_test(tc1_1, convertFromRomanNumeralToBaseTenTest);
    tcase_add_test(tc1_1, convertIntToRomanNumeralTest);
    tcase_add_test(tc1_1, exceedsMaximum);
    tcase_add_test(tc1_1, additionCheck);
    tcase_add_test(tc1_1, subtractionCheck);
    tcase_add_test(tc1_1, addAndSubReturnNullForBadSingleTerm);
    tcase_add_test(tc1_1, repeatingTermsTest);
    tcase_add_test(tc1_1, convertedValuesOutOfOrder);
    tcase_add_test(tc1_1, characterExceedsMaximumFrequency);
    tcase_add_test(tc1_1, badRomanNumeralCharacter);
    tcase_add_test(tc1_1, badlookAheadPairs);
    tcase_add_test(tc1_1, badConversionToBaseTen);
    tcase_add_test(tc1_1, termExceeds3999MessageTest);
    tcase_add_test(tc1_1, nullStringPassedAsArgSub);
    tcase_add_test(tc1_1, nullStringPassedAsArgAdd);
    tcase_add_test(tc1_1, subtractionYieldsNonValidRomanNumeral);
    tcase_add_test(tc1_1, sumExceedsMaximumValueErrorMessageTest);

    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}
