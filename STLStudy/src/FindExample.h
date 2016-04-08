/*
 * FindExample.h
 *
 *  Created on: 23-11-2013
 *      Author: mateusz
 */

#ifndef FINDEXAMPLE_H_
#define FINDEXAMPLE_H_

#include <algorithm>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class FindExample {
public:
	FindExample() {
		cout << "Find example." << endl;

		vector<string> colors;
		colors.push_back("zielony");
		colors.push_back("czerwony");
		colors.push_back("czarny");
		colors.push_back("bia造");
		colors.push_back("鄴速y");

		cout << "Colors on the list:" << endl;
		for (vector<string>::const_iterator it = colors.begin(); it != colors.end(); it++)
			cout << *it << " ";

		cout << endl;

		cout << "Kolor czerwony na pozycji: ";
		vector<string>::iterator red = find(colors.begin(), colors.end(), "czerwony");
		cout << distance(colors.begin(), red) << endl;

		cout << "Kolor 鄴速y na pozycji: ";
		vector<string>::iterator yellow = find(colors.begin(), colors.end(), "鄴速y");
		cout << distance(colors.begin(), yellow) << endl;

		cout << endl;
	}
};




#endif /* FINDEXAMPLE_H_ */
