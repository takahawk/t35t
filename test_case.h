#ifndef TEST_CASE_H_
#define TEST_CASE_H_

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

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
tTC_AllocTestContext() {
	TestContext tc;
	tc.testCount = 0;
	tc.tests = malloc(100 * sizeof(TestCase));
	return tc;
}

static inline void
tTC_AddTest(TestContext *tc, TestCase tcase) {
	tc->tests[tc->testCount++] = tcase;
}

static inline void
tTC_Engage(TestContext *tc) {
	// TODO: colorful printing 
	size_t okCount = 0;
	for (size_t i = 0; i < tc->testCount; i++) {
		if (tc->tests[i](tc) == TEST_OK) {
			printf("Test %d: OK\n");
			okCount++;
		} else {
			printf("Test %d: Error\n");
		}
	}
	
	if (okCount == tc->testCount) {
		printf("Tests passed %d/%d (all passed)\n");
	} else {
		printf("Tests passed %d/%d (errors)\n");
	}
}

static inline void
tTC_FreeTestContext(TestContext *tc) {
	free(tc->tests);
	tc->tests = NULL;
	tc->testCount = 0;
}
#endif
