/*
 * MyIterator.h
 *
 *  Created on: 08-11-2013
 *      Author: mateusz
 */

#ifndef MYITERATOR_H_
#define MYITERATOR_H_

#include <iterator>

class MyIterator: public std::iterator<std::input_iterator_tag, int>
{
private:
	int* data;

public:
	MyIterator(int* x) : data(x) {}

	MyIterator(const MyIterator& mit) :	data(mit.data) {}

	MyIterator& operator++()
	{
		++data;
		return *this;
	}

	MyIterator operator++(int)
	{
		MyIterator tmp(*this);
		operator++();
		return tmp;
	}

	bool operator==(const MyIterator& rhs)
	{
		return data == rhs.data;
	}

	bool operator!=(const MyIterator& rhs)
	{
		return data != rhs.data;
	}

	int& operator*()
	{
		return *data;
	}
};

#endif /* MYITERATOR_H_ */
