/*
 * VariadicVarargsExample.h
 *
 *  Created on: 14-01-2014
 *      Author: mateusz
 */

#ifndef VARIADICVARARGSEXAMPLE_H_
#define VARIADICVARARGSEXAMPLE_H_

#include <iostream>

namespace std
{

class VariadicVarargsExample
{
public:
	VariadicVarargsExample()
	{
		cout << R"(Variadic varargs example. Will execute print(123, "some string", 'f', true);)" << endl;

		cout << boolalpha;
		print(123, "some string", 'f', true);

		cout << endl << endl;
	}

	void print()
	{
	}

	template<typename T, typename ... Ts>
	void print(T head, Ts ... tail)
	{
		cout << head << "; ";
		print(tail...);
	}
};

} /* namespace std */

#endif /* VARIADICVARARGSEXAMPLE_H_ */
