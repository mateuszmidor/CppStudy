/*
 * MapExample.h
 *
 *  Created on: 22-11-2013
 *      Author: mateusz
 */

#ifndef MAPEXAMPLE_H_
#define MAPEXAMPLE_H_

#include <map>
#include <string>
#include <iostream>

using namespace std;

class MapExample
{
public:
	MapExample()
	{
		cout << "Map example." << endl;

		map<string, string> city_capital;

		// wstawiamy dane do mapy
		city_capital["USA"] = "Waszyngton";
		city_capital["Kanada"] = "Ottawa";

		// wstawiamy mniej wygodnym sposobem
		city_capital.insert(make_pair("Meksyk", "Meksyko City"));

		// szukamy w mapie
		cout << "Canada capital is: " << city_capital["Kanada"] << endl;

		cout << "All known countries:" << endl;

		// printujemy zawartosc mapy
		for (map<string, string>::const_iterator it = city_capital.begin();
				it != city_capital.end(); it++)
			cout << it->first << " - " << it->second << endl;

		cout << endl;
	}
};

#endif /* MAPEXAMPLE_H_ */
