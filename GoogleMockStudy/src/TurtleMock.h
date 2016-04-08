/*
 * Turtlemock.h
 *
 *  Created on: 06-02-2014
 *      Author: mateusz
 */

#ifndef TURTLEMOCK_H_
#define TURTLEMOCK_H_

#include "Turtle.h"
#include "gmock/gmock.h"  // Brings in Google Mock.

class TurtleMock: public Turtle
{
public:
	MOCK_METHOD0(penDown, void());
	MOCK_METHOD0(penUp, void());
	MOCK_METHOD1(forward, void(int distance));
	MOCK_CONST_METHOD0(getX, int());
	MOCK_CONST_METHOD0(getY, int());
};

#endif /* TURTLEMOCK_H_ */
