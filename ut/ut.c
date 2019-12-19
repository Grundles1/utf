#include "utf.h"
#include "ut.h"

test_result_t t1(void){
	return PASSED;
}

test_result_t t2(void){
	return FAILED;
}

test_result_t t3(void){
	return INVALID;
}

test_result_t t4(void){
	return -1;
}