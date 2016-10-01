/*
 * DO NOT EDIT THIS FILE. Generated by checkmk.
 * Edit the original source file "convertTests.check" instead.
 */

#include <check.h>

#line 1 "convertTests.check"
#include "convert.h"

START_TEST(convertFromRomanNumeralToBaseTenTest)
{
#line 4
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
#line 32
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
#line 46
	fail_unless(convertRomanNumeralStringToBaseTenInt("MMMCMXCIXI") == 0,"Failed to rejct number larger than 3999");
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

    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}
