#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
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
	printf("\tAdding test case %s to suite %s\n", test_case->name, suite->name);
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
		.next_result = NULL,
		.name = NULL
	};
	if (test_cases == NULL) {
		printf("Test cases loaded, starting test execution.\n");
		// return_allocated(test_results_t, ret);
		return NULL;
	}
	ret.name = test_cases->test->name;
	if (test_cases->test->test == NULL) {
		printf("\tTest case not associated with a test function\n");
		ret.result = INVALID;
		ret.next_result = NULL;
	}
	test_results_t *next_res = run_test(test_cases->next_test);
	printf("\tRunning test case %s\n", test_cases->test->name);
	switch (monitor_assertions(test_cases->test->test)){
		case PASSED:
			printf("\t\tTest passed\n");
			ret.result = PASSED;
			ret.next_result = next_res;
			break;
		case INVALID:
			printf("\t\tTest invalid\n");
			ret.result = INVALID;
			ret.next_result = next_res;
			break;
		case FAILED:
			printf("\t\tTest failed\n");
			ret.result = FAILED;
			ret.next_result = next_res;
			break;
	}
	return_allocated(test_results_t, ret);
}

test_results_t* run_tests(suite_t *suite){
	printf("Running test suite %s.\n", suite->name);
	return run_test(suite->test_cases);
}

test_result_t assertion_state = INVALID;
test_result_t monitor_assertions(test_result_t (*test)(void)){
	assertion_state = INVALID;
	if (test()==assertion_state){
		return assertion_state;
	}
	else {
		printf("\t\tWarning: Test result does not agree with assertion status\n");
		return INVALID;
	}
}

void assert(bool assertion){
	if (assertion && assertion_state != FAILED){
			assertion_state = PASSED;
	}
	else {
		assertion_state = FAILED;
	}
}

void print_result(test_result_t result){
	switch (result){
		case PASSED:
			printf(" PASSED\n");
			break;
		case FAILED:
			printf(" FAILED\n");
			break;
		case INVALID:
			printf(" INVALID\n");
			break;
	}
}

void print_results(test_results_t *results){
	if (results != NULL){
		if (results->next_result != NULL)
			print_results(results->next_result);
		printf("%s:", results->name);
		print_result(results->result);
	}
}

void print_totals(test_results_t *results, int passed, int failed, int invalid){
	if (results == NULL){
		printf("Totals:\n\n");
		printf("INVALID:\t%d\n", invalid);
		printf("PASSED:\t\t%d\n", passed);
		printf("FAILED:\t\t%d\n", failed);
		return;
	}
	switch(results->result){
		case PASSED:
			print_totals(results->next_result, passed+1, failed, invalid);
			break;
		case FAILED:
			print_totals(results->next_result, passed, failed+1, invalid);
			break;
		case INVALID:
			print_totals(results->next_result, passed, failed, invalid+1);
			break;
	}
}
