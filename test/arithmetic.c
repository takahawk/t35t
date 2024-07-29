#include "w/t35t/test.h"

TestResult
TestAddition(TestContext *tc) {
	int a = 10, b = 20;

	return a + b == 30
		? TEST_OK
		: TEST_FAILED;
}

int main() {
	TestContext tc = tTC_Alloc();
	
	tTC_AddTest(&tc, TestAddition);
	tTC_Engage(&tc);

	tTC_Free(&tc);
}
