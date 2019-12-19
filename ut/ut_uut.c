#include "utf.h"
#include "uut.h"

test_result_t t1_2_even_t(void){
	assert(even(2));
	return PASSED;
}

test_result_t t2_2_even_f(void){
	assert(even(2));
	return FAILED;
}

test_result_t t3_2_not_even_t(void){
	assert(!even(2));
	return PASSED;
}

test_result_t t4_2_not_even_f(void){
	assert(!even(2));
	return FAILED;
}