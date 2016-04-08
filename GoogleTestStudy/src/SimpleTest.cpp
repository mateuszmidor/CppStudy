/*
 * SimpleTest.cpp
 *
 *  Created on: 26-01-2014
 *      Author: mateusz
 *
 */

// GoogleTest framework
#include "gtest/gtest.h"

TEST(SimpleTest, IsTrue)
{
	EXPECT_TRUE(true);
}

TEST(SimpleTest, IsFalse)
{
	EXPECT_FALSE(false);
}

TEST(SimpleTest, IsEqual)
{
	EXPECT_EQ(0, 0);
}

TEST(SimpleTest, IsGreater)
{
	EXPECT_GT(1, 0);
}

TEST(SimpleTest, IsLess)
{
	EXPECT_LT(0, 1);
}

TEST(SimpleTest, StringsEqual)
{
	const char S1[] = "some string";
	const char S2[] = "some string";
	EXPECT_STREQ(S1, S2);
}

TEST(SimpleTest, StringsIgnoreCaseEqual)
{
	const char S1[] = "some string";
	const char S2[] = "Some String";
	EXPECT_STRCASEEQ(S1, S2);
}

TEST(SimpleTest, SucceedFailureFail)
{
	switch(0)
	{
	case 0:
		SUCCEED() << "everything's fine";
		break;
	case 1:
		ADD_FAILURE() << "error";
		break;
	default:
		FAIL() << "we should not get here";
	}
}



