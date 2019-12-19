#include <stdbool.h>

// The maximum allowable length for a name is 32 characters
#define MAX_NAME_LEN (25 + 7)

// A utility function for cheap polymorphism
#define return_allocated(TYPE, SRC) \
	TYPE *ret_alloc = (TYPE *) malloc(sizeof(TYPE)); \
	memcpy((void *) ret_alloc, (void *) &SRC, sizeof(TYPE)); \
	return ret_alloc;

// A name is allowed to be MAX_NAME_LEN number of characters
typedef char* name_t;

/* Test result structures */
// The three possible values of a test case 
typedef enum {
	PASSED,
	FAILED,
	INVALID
} test_result_t;

// A linked list of test results
typedef struct test_results_s {
	test_result_t result;
	struct test_results_s *next_result;
} test_results_t;


/* Test case structures */
// A test case is a test name and test function that returns a test_result_t
typedef struct {
	test_result_t (*test)(void);
	name_t name;
} test_case_t;

// A linked list of test cases
typedef struct test_cases_s {
	test_case_t* test;
	struct test_cases_s *next_test;  // this field must remain a pointer or else the C compiler will not accept this recursive structure
} test_cases_t;



/* Test suite structures */
// A suite is a name and a linked list of test cases
typedef struct {
	test_cases_t* test_cases;
	name_t name;
} suite_t;

// fxn protos
suite_t* make_suite(name_t);
test_case_t* make_test_case(name_t, test_result_t (*test)(void));
void add_test(suite_t*, test_case_t*);
test_results_t* run_test(test_cases_t*);
test_results_t* run_tests(suite_t*);
name_t make_name (name_t);
test_result_t monitor_assertions(test_result_t (*test)(void));
extern test_result_t assertion_state;
void assert(bool);
