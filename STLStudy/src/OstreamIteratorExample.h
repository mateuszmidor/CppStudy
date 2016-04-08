/*
 * OstreamIteratorExample.h
 *
 *  Created on: 10-01-2014
 *      Author: mateusz
 */

#ifndef OSTREAMITERATOREXAMPLE_H_
#define OSTREAMITERATOREXAMPLE_H_

#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

namespace std
{

class OstreamIteratorExample
{
public:
	OstreamIteratorExample()
	{
		cout << "ostream_iterator example. Will print out list by copying it into ostream_iterator" << endl;
		list<int> numbers = { 8, 6, 4, 2, 0, 11, 13, 15 };

		ostream_iterator<int> out(cout, "; ");
		// li -> ostream_iterator -> cout
		copy(numbers.begin(), numbers.end(), out);

		cout << endl << endl;
	}
};

} /* namespace std */

#endif /* OSTREAMITERATOREXAMPLE_H_ */
