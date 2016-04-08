// GoogleTest framework
#include "gtest/gtest.h"

bool isEven(int a)
{
	return (a % 2) == 0;
}

bool isSumEven(int a, int b)
{
	return isEven(a + b);
}

TEST(PredicateTest, PredArity1)
{
	ASSERT_PRED1(isEven, 2);
}

TEST(PredicateTest, PredArity2)
{
	ASSERT_PRED2(isSumEven, 1, 3);
}
