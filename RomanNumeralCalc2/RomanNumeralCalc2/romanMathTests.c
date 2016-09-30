/*
 * DO NOT EDIT THIS FILE. Generated by checkmk.
 * Edit the original source file "romanMathTests.check" instead.
 */

#include <check.h>

#line 1 "romanMathTests.check"
#include "romanMath.h"

START_TEST(additionCheck)
{
#line 4
	ck_assert_msg(strcmp(add("V", "I"), "VI") == 0,"Failed to add V + I");
	ck_assert_msg(strcmp(add("XXXII", "LXIV"), "XCVI") == 0, "Failed to add XXXII + LXIV"); 
}
END_TEST

int main(void)
{
    Suite *s1 = suite_create("Core");
    TCase *tc1_1 = tcase_create("Core");
    SRunner *sr = srunner_create(s1);
    int nf;

    suite_add_tcase(s1, tc1_1);
    tcase_add_test(tc1_1, additionCheck);

    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}
