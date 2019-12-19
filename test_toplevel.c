#include <stdio.h>
#include "utf.h"

#include "ut.h"

int main(void)
{
	printf("Making test suite\n");
	suite_t *suite = make_suite("suite_1");
	test_case_t *test_case1_t = make_test_case("test_case_1_t", t1_t);
	test_case_t *test_case2_t = make_test_case("test_case_2_t", t2_t);
	test_case_t *test_case3_t = make_test_case("test_case_3_t", t3_t);
	test_case_t *test_case4_t = make_test_case("test_case_4_t", t4_t);
	test_case_t *test_case1_f = make_test_case("test_case_1_f", t1_f);
	test_case_t *test_case2_f = make_test_case("test_case_2_f", t2_f);
	test_case_t *test_case3_f = make_test_case("test_case_3_f", t3_f);
	test_case_t *test_case4_f = make_test_case("test_case_4_f", t4_f);
	add_test(suite, test_case1_t);
	add_test(suite, test_case2_t);
	add_test(suite, test_case3_t);
	add_test(suite, test_case4_t);
	add_test(suite, test_case1_f);
	add_test(suite, test_case2_f);
	add_test(suite, test_case3_f);
	add_test(suite, test_case4_f);
	run_tests(suite);
	printf("Made suite.\n");
	return 0;
}
