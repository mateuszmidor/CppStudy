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
		cout << R"(Pêtla typu "for (string &s : strings) {...")" << endl;

		// fajna szybka inicjalizacja wektora poprzez liste inicjalizuj¹c¹
		vector<string> strings = { "ala", "ma", "kota" };

		// elegancka pêtla po wektorze
		for (string & s : strings)
		{
			cout << s << endl;
		}

		cout << endl;
	}
};

#endif /* FORTHROUGHCOLLECTION_H_ */
