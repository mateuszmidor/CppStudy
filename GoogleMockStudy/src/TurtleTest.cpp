#include "gmock/gmock.h"  // Brings in Google Mock.
#include "TurtleMock.h"

using namespace testing;

TEST(TurtleTest, CanGoAhead)
{
	TurtleMock turtle;

	// demand the actions to take place in a precise sequence
	InSequence seq;

	EXPECT_CALL(turtle, penDown()).Times(1);
	EXPECT_CALL(turtle, forward(50)).Times(1);
	EXPECT_CALL(turtle, penUp()).Times(1);

	turtle.penDown();
	turtle.forward(50);
	turtle.penUp();
}

TEST(TurtleTest, CanReturnPosition)
{
	TurtleMock turtle;

	EXPECT_CALL(turtle,
			getX()).WillOnce(Return(1)).WillOnce(Return(2)).WillOnce(Return(3));

	EXPECT_EQ(1, turtle.getX());
	EXPECT_EQ(2, turtle.getX());
	EXPECT_EQ(3, turtle.getX());
}


