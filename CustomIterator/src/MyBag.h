/*
 * MyBag.h
 *
 *  Created on: 08-11-2013
 *      Author: mateusz
 */

#ifndef MYBAG_H_
#define MYBAG_H_

#include "MyIterator.h"

class MyBag
{
private:
	int *data;
	int size;
public:

	MyBag(int *numbers, int len) :	data(numbers), size(len)
	{
	}

	const MyIterator begin()
	{
		return MyIterator(data);
	}

	const MyIterator end()
	{
		return MyIterator(data + size);
	}
};

#endif /* MYBAG_H_ */
