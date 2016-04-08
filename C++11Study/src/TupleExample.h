/*
 * TupleExample.h
 *
 *  Created on: 14-01-2014
 *      Author: mateusz
 */

#ifndef TUPLEEXAMPLE_H_
#define TUPLEEXAMPLE_H_

#include <iostream>
#include <tuple>

namespace std
{

class TupleExample
{
public:

	TupleExample()
	{
		cout << "Tuple example. Will return quotient and remainder from a divmod(a, b) function" << endl;

		int div, mod;
		tie(div, mod) = divmod(5, 2);
		cout << "divmod(5, 2) = " << div << ", remainder " << mod << endl;

		cout << endl;
	}

	tuple<int, int> divmod(int a, int b)
	{
		return make_tuple(a / b, a % b);
	}
};

} /* namespace std */

#endif /* TUPLEEXAMPLE_H_ */
