/*
 * ForThroughCollection.h
 *
 *  Created on: 07-11-2013
 *      Author: mateusz
 */

#ifndef FORTHROUGHCOLLECTION_H_
#define FORTHROUGHCOLLECTION_H_

#include <iostream>
#include <string>
#include <vector>


using namespace std;

class ForThroughCollection
{
public:
	ForThroughCollection() {
		// raw string: R"(tutaj string)"
		cout << R"(P�tla typu "for (string &s : strings) {...")" << endl;

		// fajna szybka inicjalizacja wektora poprzez liste inicjalizuj�c�
		vector<string> strings = { "ala", "ma", "kota" };

		// elegancka p�tla po wektorze
		for (string & s : strings)
		{
			cout << s << endl;
		}

		cout << endl;
	}
};

#endif /* FORTHROUGHCOLLECTION_H_ */
