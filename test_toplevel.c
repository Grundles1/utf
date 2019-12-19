#include <stdio.h>
#include "utf.h"

#include "ut.h"
#include "ut_uut.h"

int main(void)
{
	printf("Making test suite\n");
	suite_t *suite = make_suite("suite_1");
	printf("Making test cases\n");
	test_case_t *test_case1_t = make_test_case("test_case_1_t", t1_t);
	test_case_t *test_case2_t = make_test_case("test_case_2_t", t2_t);
	test_case_t *test_case3_t = make_test_case("test_case_3_t", t3_t);
	test_case_t *test_case4_t = make_test_case("test_case_4_t", t4_t);
	test_case_t *test_case1_f = make_test_case("test_case_1_f", t1_f);
	test_case_t *test_case2_f = make_test_case("test_case_2_f", t2_f);
	test_case_t *test_case3_f = make_test_case("test_case_3_f", t3_f);
	test_case_t *test_case4_f = make_test_case("test_case_4_f", t4_f);
	test_case_t *test_case1_2_even_t = make_test_case("test_case_uut 2 even true", t1_2_even_t);
	test_case_t *test_case2_2_even_f = make_test_case("test_case_uut 2 even false", t2_2_even_f);
	test_case_t *test_case3_2_not_even_t = make_test_case("test_case_uut 2 not even true", t3_2_not_even_t);
	test_case_t *test_case4_2_not_even_f = make_test_case("test_case_uut 2 not even false", t4_2_not_even_f);
	printf("Adding test cases to suites\n");
	add_test(suite, test_case1_t);
	add_test(suite, test_case2_t);
	add_test(suite, test_case3_t);
	add_test(suite, test_case4_t);
	add_test(suite, test_case1_f);
	add_test(suite, test_case2_f);
	add_test(suite, test_case3_f);
	add_test(suite, test_case4_f);
	add_test(suite, test_case1_2_even_t);
	add_test(suite, test_case2_2_even_f);
	add_test(suite, test_case3_2_not_even_t);
	add_test(suite, test_case4_2_not_even_f);
	printf("Running the tests\n");
	test_results_t *results = run_tests(suite);
	printf("Printing the results\n");
	print_results(results);
	printf("Made suite.\n");
	return 0;
}
