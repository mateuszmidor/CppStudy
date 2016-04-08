/*
 * vector.h
 *
 *  Created on: Oct 16, 2015
 *      Author: user
 */

#ifndef SRC_MYVECTOR_H_
#define SRC_MYVECTOR_H_

#include <iostream>
#include <memory>

using std::cout;
using std::endl;

template <typename T>
class myvector
{
private:
	T *buff;
	unsigned elementCount;
	unsigned capacity;

	void doubleTheCapacity()
	{
		unsigned newCapacity = capacity * 2;
		T *newBuff = new T[newCapacity];
		memcpy(newBuff, buff, elementCount * sizeof(T));
		delete[] buff;
		buff = newBuff;
		capacity = newCapacity;
	}

public:
	myvector(unsigned size) : elementCount(0), capacity(size)
	{
		buff = new T[capacity];
	}

	virtual ~myvector()
	{
		delete[] buff;
	}

	unsigned len() const
	{
		return elementCount;
	}

	void pushBack(const T& element)
	{
		if (elementCount == capacity)
			doubleTheCapacity();

		buff[elementCount++] = element;
	}

	T operator[] (unsigned index) const
	{
		return buff[index];
	}

	T& operator[] (unsigned index)
	{
		return buff[index];
	}
};

void myvectorExample()
{
	cout << "[vector]" << endl;

	myvector<int> v(2);
	v.pushBack(-3);
	v.pushBack(0);
	v.pushBack(2);
	v[2] = 3;

	for (unsigned i = 0; i < v.len(); i++)
		cout << v[i] << " ";

	cout << endl << endl;
}

#endif /* SRC_MYVECTOR_H_ */
