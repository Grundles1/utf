#include "utf.h"
#include "ut.h"

test_result_t t1_t(void){
	assert(1 == 1);
	return PASSED;
}
test_result_t t1_f(void){
	assert(1 == 0);
	return PASSED;
}

test_result_t t2_t(void){
	assert(1 == 1);
	return FAILED;
}
test_result_t t2_f(void){
	assert(1 == 0);
	return FAILED;
}

test_result_t t3_t(void){
	assert(1 == 1);
	return INVALID;
}
test_result_t t3_f(void){
	assert(1 == 0);
	return INVALID;
}

test_result_t t4_t(void){
	assert(1 == 1);
	return -1;
}
test_result_t t4_f(void){
	assert(1 == 0);
	return -1;
}