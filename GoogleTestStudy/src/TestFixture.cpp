/*
 * TestFixture.cpp
 *
 *  Created on: 26-01-2014
 *      Author: mateusz
 */

#include <iostream>

// GoogleTest framework
#include "gtest/gtest.h"

class TestFixture: public testing::Test
{
public:
	// data to be used in tests
	char* string1;
	char* string2;

	// per test function
	virtual void SetUp()
	{
		string1 = "waterpipe";
		string2 = "Waterpipe";
	}

	virtual void TearDown()
	{
		string1 = NULL;
		string2 = NULL;
	}

	// per whole suite
	static void SetUpTestCase()
	{
		std::cout << "setup test case" << std::endl;
	}

	static void TearDownTestCase()
	{
		std::cout << "tear test case" << std::endl;
	}
};

TEST_F(TestFixture, StringsCaseSensitiveNonEqual)
{
	ASSERT_STRNE(string1, string2);
}

TEST_F(TestFixture, StringsCaseInsensitiveEqual)
{
	ASSERT_STRCASEEQ(string1, string2);
}
