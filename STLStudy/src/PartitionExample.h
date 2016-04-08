/*
 * PartitionExample.h
 *
 *  Created on: 10-01-2014
 *      Author: mateusz
 */

#ifndef PARTITIONEXAMPLE_H_
#define PARTITIONEXAMPLE_H_

#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

namespace std
{

class PartitionExample
{
public:
	PartitionExample()
	{
		cout << "partition example. Will divide elements into 2 sequences based on (x<10) predicate" << endl;
		list<int> numbers { 1, 12, 7, 15, 17, 3, 5, 18 };

		ostream_iterator<int> out(cout, " ");
		cout << "numbers:" << endl;
		copy(numbers.begin(), numbers.end(), out);
		cout << endl;

		partition(numbers.begin(), numbers.end(), [](int x)	{ return (x < 10); });

		cout << "partitioned numbers:" << endl;
		copy(numbers.begin(), numbers.end(), out);

		cout << endl << endl;
	}
};

} /* namespace std */

#endif /* PARTITIONEXAMPLE_H_ */
