#ifndef ASSERT_H_
#define ASSERT_H_

#include <stdbool.h>
#include <stdio.h>


#define _PrintEquals(X, expected) _Generic(X, \
	String: fprintf(stderr, "%s equals %s\n", X.str, expected.str) \
	)
#define _PrintNotEquals(X, expected) _Generic(X, \
	String: fprintf(stderr, "%s not equals %s\n", X.str, expected.str) \
	)
#define _Equals(X, expected) _Generic(X, \
		String: S_Equals(X, expected))

#define AssertEquals(X, expected) if (! _Equals(X, expected)) {\
		_PrintNotEquals(X, expected); \
		return TEST_FAILED;\
	}
#define AssertNotEquals(X, expected) if (_Equals(X, expected)) {\
		_PrintEquals(X, expected); \
		return TEST_FAILED;\
	}

#endif
