#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utf.h"

name_t make_name (name_t name){
	name_t name_alloc = (name_t) malloc(MAX_NAME_LEN);
	strncpy(name_alloc, name, MAX_NAME_LEN);
	return name_alloc;
}

suite_t* make_suite(name_t name){
	printf("\tMaking suite %s\n", name);
	suite_t ret = {
		.name = make_name(name),
		.test_cases = NULL
	};
	return_allocated(suite_t, ret);
}

test_case_t* make_test_case(name_t name, test_result_t (*test)(void)){
	printf("\tMaking test case %s\n", name);
	test_case_t ret = {
		.name = make_name(name),
		.test = test
	};
	return_allocated(test_case_t, ret);
}

void add_test(suite_t *suite, test_case_t *test_case){
	printf("\tAdding test case %s to suite %s\n", suite->name, test_case->name);
	test_cases_t updated_test_cases_list = {
		.test = test_case,
		.next_test = suite->test_cases
	};
	test_cases_t *updated_test_cases_list_alloc = (test_cases_t *) malloc(sizeof(test_cases_t));
	memcpy(updated_test_cases_list_alloc, &updated_test_cases_list, sizeof(test_cases_t));
	suite->test_cases = updated_test_cases_list_alloc;
}

test_results_t* run_test(test_cases_t *test_cases){
	test_results_t ret = {
		.result = INVALID,
		.next_result = NULL
	};
	test_result_t curr_result = INVALID;
	if (test_cases == NULL) {
		printf("\tReached the end of the test list\n");
		return_allocated(test_results_t, ret);
	}
	else if (test_cases->test->test == NULL) {
		printf("\tTest case not associated with a test function\n");
		ret.result = INVALID;
		ret.next_result = NULL;
	}
	test_results_t *next_res = run_test(test_cases->next_test);
	printf("Running test case %s\n", test_cases->test->name);
	curr_result = test_cases->test->test();
	if (curr_result == PASSED) {
		printf("\tTest passed\n");
		ret.result = PASSED;
		ret.next_result = next_res;
	}
	else if (curr_result == INVALID) {
		printf("\tTest invalid\n");
		ret.result = INVALID;
		ret.next_result = next_res;
	}
	else {
		printf("\tTest failed\n");
		ret.result = FAILED;
		ret.next_result = next_res;
	}

	return_allocated(test_results_t, ret);
}

test_results_t* run_tests(suite_t *suite){
	printf("Running test suite %s.\n", suite->name);
	return run_test(suite->test_cases);
}
