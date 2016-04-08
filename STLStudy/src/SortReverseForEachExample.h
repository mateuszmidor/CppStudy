/*
 * SortReverseExample.h
 *
 *  Created on: 23-11-2013
 *      Author: mateusz
 */

#ifndef SORTREVERSEEXAMPLE_H_
#define SORTREVERSEEXAMPLE_H_

#include <string>
#include <deque>
#include <algorithm>
#include <iostream>

using namespace std;


class LenghtComparator {
public:
	bool operator()(const string& a, const string& b) {
		return a.length() < b.length();
	}
};

class Printer {
public:
	void operator()(const string& s) {
		cout << s << " ";
	}
};

class SortReverseForEachExample {
public:
	SortReverseForEachExample() {
		cout << "Sort and reverse example." << endl;

		deque<string> genres;
		genres.push_back("R&B");
		genres.push_back("Instrumental");
		genres.push_back("Folk");
		genres.push_back("Rock&Roll");
		genres.push_back("Pop");

		cout << "Music genres unsorted:" << endl;
		for_each(genres.begin(), genres.end(), Printer());
		cout << endl;

		sort(genres.begin(), genres.end(), LenghtComparator());
		cout << "Sorted by lenght: " << endl;
		for_each(genres.begin(), genres.end(), Printer());
		cout << endl;

		reverse(genres.begin(), genres.end());
		cout << "Reverse order: " << endl;
		for_each(genres.begin(), genres.end(), Printer());
		cout << endl;

		cout << endl;
	}
};




#endif /* SORTREVERSEEXAMPLE_H_ */
