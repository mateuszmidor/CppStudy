/*
 * VariadicSizeofExample.h
 *
 *  Created on: 14-01-2014
 *      Author: mateusz
 */

#ifndef VARIADICSIZEOFEXAMPLE_H_
#define VARIADICSIZEOFEXAMPLE_H_

#include <iostream>

namespace std
{

class VariadicSizeofExample
{
public:
	VariadicSizeofExample()
	{
		cout << R"(Variadic sizeof example. Will count params in size(12, false, "blank")  )" << endl;

		cout << "argument count is " <<  size(12, false, "blank");

		cout << endl << endl;
	}

	unsigned size()
	{
		return 0;
	}

	template<typename H, typename... T>
	unsigned size(H h, T... t)
	{
		return 1 + size(t...);
	}
};

} /* namespace std */

#endif /* VARIADICSIZEOFEXAMPLE_H_ */
