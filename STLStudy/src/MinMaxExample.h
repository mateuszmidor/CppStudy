/*
 * FindMinMaxExample.h
 *
 *  Created on: 23-11-2013
 *      Author: mateusz
 */

#ifndef FINDMINMAXEXAMPLE_H_
#define FINDMINMAXEXAMPLE_H_

#include <algorithm>
#include <queue>
#include <list>

using namespace std;

// komparator jako funkcja
bool compareFunction(const int& a, const int& b) {
	return a < b;
}

// komparator jako obiekt
class Comparator
{
public:
	bool operator()(const int& a, const int& b) {
		return a < b;
	}
};
class MinMaxExample
{
public:
	MinMaxExample()
	{
		cout << "Min & max algorithm example." << endl;

		// adapter kolejki wykorzystuj¹cy liste jako kontener elmentów
		list<int> numbers;
		numbers.push_back(7);
		numbers.push_back(2);
		numbers.push_back(5);
		numbers.push_back(8);
		numbers.push_back(4);

		cout << "Numbers: " << endl;
		for (list<int>::const_iterator it = numbers.begin();
				it != numbers.end(); it++)
			cout << *it << " ";

		cout << endl;


		cout << "Min: " << endl;
		list<int>::const_iterator min = min_element(numbers.begin(), numbers.end(),
				compareFunction); // komparator jako funkcja
		cout << *min << endl;

		cout << "Max: " << endl;
		list<int>::const_iterator max = max_element(numbers.begin(), numbers.end(),
				Comparator()); // komparator jako obiekt
		cout << *max << endl;

		cout << endl;
	}
};

#endif /* FINDMINMAXEXAMPLE_H_ */
