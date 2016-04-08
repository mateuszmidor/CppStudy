/*
 * RawString.h
 *
 *  Created on: 14-11-2013
 *      Author: mateusz
 */

#ifndef RAWSTRING_H_
#define RAWSTRING_H_

#include <iostream>
#include <string>
using namespace std;
class RawString
{
public:
	RawString()
	{
		cout << "Zapis sciezki do katalogu raw string vs c string:" << endl;
		string raw_string = R"(D:\torrent\nightwish\)";
		string c_string =  R"(D:\\torrent\\nightwish\\)";
		cout << raw_string << endl;
		cout << c_string << endl;
		cout << endl;
	}
};

#endif /* RAWSTRING_H_ */
