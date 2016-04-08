/*
 * LiteralOperatorExample.h
 *
 *  Created on: 28-12-2013
 *      Author: mateusz
 */

#ifndef LITERALOPERATOREXAMPLE_H
#define LITERALOPERATOREXAMPLE_H

#include <iostream>

using namespace std;

typedef unsigned kilos;
kilos operator "" _stone(unsigned long long value)
{
	return (value * 12.96);
}

kilos operator "" _pound(unsigned long long value)
{
	return (value * 0.45);
}

kilos operator "" _cetnar(unsigned long long value)
{
	return (value * 50.00);
}

class LiteralOperatorExample
{
public:
	LiteralOperatorExample()
	{
		cout << "LiteralOperatorExample" << endl;

		cout << "10 stones in kg: " << 10_stone << endl;
		cout << "10 pounds in kg: " << 10_pound << endl;
		cout << "10 cetnars in kg: " << 10_cetnar << endl;

		cout << endl;
	}
};

#endif /* LITERALOPERATOREXAMPLE_H */
