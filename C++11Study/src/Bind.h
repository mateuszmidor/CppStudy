/*
 * Bind.h
 *
 *  Created on: 21-09-2014
 *      Author: mateusz
 */

#ifndef BIND_H_
#define BIND_H_

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using namespace placeholders;


void print(const char* s, const char separator)
{
	cout << s << separator;
}

class Bind
{
public:
	Bind()
	{
		cout << "bind example. Will bind separator '-' to binary printer function so it can run in for_each" << endl;

		const vector<const char*> elems = {"jeden", "dwa", "trzy"};
		for_each(elems.cbegin(), elems.cend(), bind(&print, _1, '-'));
		cout << endl << endl;
	}

};

#endif /* BIND_H_ */
