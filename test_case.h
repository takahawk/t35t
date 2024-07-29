#ifndef TEST_CASE_H_
#define TEST_CASE_H_

#include <stddef.h>
#include <stdlib.h>

typedef enum {
	TEST_FAILED,
	TEST_OK
} TestResult;

struct TestContext;

typedef TestResult(*TestCase) (struct TestContext) ;

typedef struct TestContext {
	// TODO: init?
	// TODO: arraylist?
	// TODO: test descriptions
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
tTC_FreeTestContext(TestContext *tc) {
	free(tc->tests);
	tc->tests = NULL;
	tc->testCount = 0;
}
#endif
