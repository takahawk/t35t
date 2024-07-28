#ifndef TEST_CASE_H_
#define TEST_CASE_H_
typedef struct {
} TestContext;

typedef TestCase (*TestFunc) (TestContext);
#endif
