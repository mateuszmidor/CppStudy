/*
 * Turtle.h
 *
 *  Created on: 06-02-2014
 *      Author: mateusz
 */

#ifndef TURTLE_H_
#define TURTLE_H_

class Turtle
{
public:
	virtual void penDown() = 0;
	virtual void penUp() = 0;
	virtual void forward(int distance) = 0;
	virtual int getX() const = 0;
	virtual int getY() const { return 1; }
	virtual ~Turtle() { }
};

#endif /* TURTLE_H_ */
