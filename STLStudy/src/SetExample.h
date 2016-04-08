/*
 * SetExample.h
 *
 *  Created on: 22-11-2013
 *      Author: mateusz
 */

#ifndef SETEXAMPLE_H_
#define SETEXAMPLE_H_

#include <set>
#include <string>
#include <iostream>

using namespace std;

// porownywacz stringow po dlugosci
class LengthComparator {
public:
	bool operator ()(const string& a, const string& b) {
		return a.length() < b.length();
	}
};
class SetExample {
public:
	SetExample() {
		cout << "Set example - week days." << endl;
		cout <<  "Ordered by length, no duplicates allowed. " << endl;

		set<string, LengthComparator> s;
		s.insert("Poniedzialek");
		s.insert("Wtorek");
		s.insert("Wtorek");
		s.insert("Sroda");
		s.insert("Czwartek");
		s.insert("Piatek");
		s.insert("Piatek");

		for (set<string>::const_iterator it = s.begin(); it != s.end(); it++)
			cout << *it << " ";

		cout << endl << endl;
	}
};



#endif /* SETEXAMPLE_H_ */
