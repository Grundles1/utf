#include <stdio.h>
#include "utf.h"

#include "ut.h"

int main(void)
{
	printf("Making test suite\n");
	suite_t *suite = make_suite("suite_1");
	suite_t *suite2 = make_suite("suite_2");
	test_case_t *test_case1 = make_test_case("test_case_1", t1);
	test_case_t *test_case2 = make_test_case("test_case_2", t2);
	test_case_t *test_case3 = make_test_case("test_case_3", t3);
	add_test(suite, test_case1);
	add_test(suite, test_case2);
	add_test(suite, test_case3);
	add_test(suite2, test_case1);
	add_test(suite2, test_case2);
	add_test(suite2, test_case3);
	run_tests(suite);
	run_tests(suite2);
	printf("Made suite.\n");
	return 0;
}
