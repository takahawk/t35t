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
			printf(uIO_Green("OK\n"));
			okCount++;
		} else {
			printf(uIO_Red("Error\n"));
		}
	}
	
	if (okCount == tc->testCount) {
		printf(uIO_Green("Tests passed %d/%d (all passed)\n"), okCount, tc->testCount);
		return 0;
	} else {
		printf(uIO_Red("Tests passed %d/%d (there are errors)\n"), okCount, tc->testCount);
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
