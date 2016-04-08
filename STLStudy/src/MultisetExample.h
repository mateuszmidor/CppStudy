/*
 * MultisetExample.h
 *
 *  Created on: 22-11-2013
 *      Author: mateusz
 */

#ifndef MULTISETEXAMPLE_H_
#define MULTISETEXAMPLE_H_

#include <set>
#include <string>
#include <iostream>

using namespace std;

class MultisetExample {
public:
	MultisetExample() {
		cout << "Multiset example. Will count duplicated names." << endl;
		multiset<string> m;
		m.insert("Andrzej");
		m.insert("Andrzej");
		m.insert("Monika");
		m.insert("Krysia");
		m.insert("Damian");
		m.insert("Cypa");
		m.insert("Damian");
		m.insert("Damian");
		m.insert("Cypa");

		while (m.size() > 0) {
			string curr = *m.begin();
			cout << curr << " - " << m.count(curr) << "x" << endl;
			m.erase(curr);
		}

		cout << endl;
	}
};


#endif /* MULTISETEXAMPLE_H_ */
