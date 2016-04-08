/*
 * TagDispatcher.h
 *
 *  Created on: 12-01-2015
 *      Author: mateusz
 */

#ifndef TAGDISPATCHER_H_
#define TAGDISPATCHER_H_

#include <iostream>
using namespace std;

// define tags for concepts
struct SingleValue_tag {};
struct RangeValue_tag {};

// define type that implements SingleValue concept
class SingleValue
{
public:
	using value_tag = SingleValue_tag;
};

// define type that implements RangeValue concept
class RangeValue
{
public:
	using value_tag = RangeValue_tag;
};


class TagDispatcher
{
public:
	// overload specialized for printing SingleValue types
	template <typename T>
	void print(T value, SingleValue_tag)
	{
		cout << "Printing value that implements SingleValue_tag concept" << endl;
	}

	// overload specialized for printing RangeValue types
	template <typename T>
	void print(T value, RangeValue_tag)
	{
		cout << "Printing value that implements RangeValue_tag concept" << endl;
	}

	template <typename T>
    void print (T& value)
	{
		using tag = typename T::value_tag;
		print(value, tag{});
	}

	TagDispatcher()
	{
		cout << "Tag dispatching example.\n" \
				"This is more general than overloading based only on types.\n" \
				"Multiple types can be given the same tag thus handled by same function: "<< endl;

		SingleValue sv{};
		print(sv);

		RangeValue rv{};
		print(rv);

		cout << endl;
	}
};



#endif /* TAGDISPATCHER_H_ */
