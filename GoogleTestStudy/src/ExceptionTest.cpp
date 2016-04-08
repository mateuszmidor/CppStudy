// GoogleTest framework
#include "gtest/gtest.h"
#include <stdexcept>

using namespace std;


TEST(ExceptionTest, AssertThrow)
{
	ASSERT_THROW({ throw invalid_argument(""); }, invalid_argument);
}

TEST(ExceptionTest, AssertAnyThrow)
{
	ASSERT_ANY_THROW({ throw "some exception"; });
}

TEST(ExceptionTest, AssertNoThrow)
{
	ASSERT_NO_THROW({
		int a = 3;
		int b = 4;
		int c = a*a + b*b;
	});
}
