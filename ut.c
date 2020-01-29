#include <stdio.h>

#include "utf.h"
#include "ut.h"

test_result_t t1(void){
	printf("\trunning t1\n");
	return PASSED;
}

test_result_t t2(void){
	printf("\trunning t2\n");
	return FAILED;
}

test_result_t t3(void){
	printf("\trunning t3\n");
	return INVALID;
}
