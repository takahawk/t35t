#ifndef TEST_CASE_H_
#define TEST_CASE_H_

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "w/ut1l5/io.h"

typedef enum {
	TEST_FAILED,
	TEST_OK
} TestResult;

struct TestContext;

// TODO: test descriptions
typedef TestResult(*TestCase) (struct TestContext*) ;

typedef struct TestContext {
	// TODO: init?
	// TODO: arraylist?
	size_t testCount;
	TestCase *tests;

} TestContext;

static inline TestContext
tTC_Alloc() {
	TestContext tc;
	tc.testCount = 0;
	tc.tests = malloc(100 * sizeof(TestCase));
	return tc;
}

static inline void
tTC_AddTest(TestContext *tc, TestCase tcase) {
	tc->tests[tc->testCount++] = tcase;
}

static inline int 
tTC_Engage(TestContext *tc) {
	size_t okCount = 0;
	for (size_t i = 0; i < tc->testCount; i++) {
		printf("Running test %d... ", i + 1);
		if (tc->tests[i](tc) == TEST_OK) {
			printf(CLI_COLOR_GREEN "OK\n" CLI_COLOR_RESET);
			okCount++;
		} else {
			printf(CLI_COLOR_RED "Error\n" CLI_COLOR_RESET);
		}
	}
	
	if (okCount == tc->testCount) {
		printf(CLI_COLOR_GREEN "Tests passed %d/%d (all passed)\n" CLI_COLOR_RESET, okCount, tc->testCount);
		return 0;
	} else {
		printf(CLI_COLOR_RED "Tests passed %d/%d (there are errors)\n" CLI_COLOR_RESET, okCount, tc->testCount);
		return -1;
	}
}

static inline void
tTC_Free(TestContext *tc) {
	free(tc->tests);
	tc->tests = NULL;
	tc->testCount = 0;
}
#endif
