#include <cassert>

// GoogleTest framework
#include "gtest/gtest.h"

void failAssertion()
{
	assert(1==0 && "assert fails");
}

// you can use regexp in ASSERT_DEATH
TEST(DeathTest, AssertDeath)
{
	ASSERT_DEATH(failAssertion(), "assert fails");
}


void exitProcess(int code)
{
	exit(code);
}

// no error message
TEST(DeathTest, AssertExit)
{
	ASSERT_EXIT(exitProcess(1), testing::ExitedWithCode(1), "");
}
