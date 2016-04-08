// GoogleTest framework
#include "gtest/gtest.h"

TEST(FloatingPointMathTest, FloatsAlmosEqual)
{
	float a = 0.3;
	float b = 0.3;
	ASSERT_FLOAT_EQ(a, b);
}

TEST(FloatingPointMathTest, DoublesAlmosEqual)
{
	double a = 0.3;
	double b = 0.3;
	ASSERT_DOUBLE_EQ(a, b);
}

TEST(FloatingPointMathTest, ValuesNear)
{
	double a = 0.5;
	double b = 0.4999;
	double DELTA = 0.0001;
	ASSERT_NEAR(a, b, DELTA);
}

