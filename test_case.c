#ifndef TEST_CASE_H_
#define TEST_CASE_H_

#include <stddef.h>

typedef TestCase (*TestFunc) (TestContext);

typedef struct {
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
tTC_AddTest(TestCase tc) {
	tc->tests[testCount++] = tc;
}

static inline void
tTC_FreeTestContext(TestContext *tc) {
	free(tc->tests);
	tc->tests = NULL;
	tc->testCount = 0;
}
#endif
