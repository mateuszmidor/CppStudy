/*
 * ListExample.h
 *
 *  Created on: 22-11-2013
 *      Author: mateusz
 */

#ifndef LISTEXAMPLE_H_
#define LISTEXAMPLE_H_

#include <iostream>

#include <list>

using namespace std;

class ListExample
{
public:
	ListExample()
	{
		cout << "List example." << endl;

		list<char> lst;
		cout << "Filling up the list front and back..." << endl;
		for (char c = 'A'; c <= 'Z'; c++) {
			lst.push_back(c);
			lst.push_front(c+32);
		}

		cout << "Done. Printing list with iterator..." << endl;
		for (list<char>::const_iterator it = lst.begin(); it != lst.end(); it++)
			cout << *it << " ";

	cout << endl << endl;
	}

};

#endif /* LISTEXAMPLE_H_ */
