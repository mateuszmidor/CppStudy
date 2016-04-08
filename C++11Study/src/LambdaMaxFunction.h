/*
 * LambdaMaxFunction.h
 *
 *  Created on: 07-11-2013
 *      Author: mateusz
 */

#ifndef LAMBDAMAXFUNCTION_H_
#define LAMBDAMAXFUNCTION_H_

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class LambdaMaxFunction
{
public:
LambdaMaxFunction()
{
	cout << "Proste lambda expression typu bool biggerThan(a, b)" << endl;
	cout << "Przydatne np. do funkcji std::sort(...)" << endl;
	cout << "Sortujemy nazwy wd³. d³ugosci:" << endl;

	vector<string> islands =
		{"Nowa Zelandia", "Kuba", "Gran Canaria", "Islandia", "Malta"};

	// nasz lambda porównuj¹ce d³ugosci stringów
	auto isLongerThan =
			[](string a, string b)->bool{ return a.length() > b.length(); };



	sort(islands.begin(), islands.end(), isLongerThan);

	for (string &s : islands)
		cout << s << endl;


	cout << endl;
}
};

#endif /* LAMBDAMAXFUNCTION_H_ */
