/*
 * InitializerList.h
 *
 *  Created on: 08-11-2013
 *      Author: mateusz
 */

#ifndef INITIALIZERLIST_H_
#define INITIALIZERLIST_H_




#include <initializer_list>
#include <string>
#include <vector>
#include <iostream>

using namespace std;



class Basket
{
private:
	vector<string> items;

public:
	Basket(const initializer_list<string>& li) : items(li)
	{
		cout << "Stworzono koszyk z towarami przy u¿yciu listy inicjalizatora: " << endl;
		printItems();
	}

	void addItems(const initializer_list<string>& li)
	{
		items.insert(items.end(), li.begin(), li.end());
		cout << "Do koszyka dodano nowe towary. Teraz mamy: " << endl;


		printItems();
	}

	void printItems()
	{
		for (string s : items)
			cout << s << endl;
		cout << endl;
	}
};

#endif /* INITIALIZERLIST_H_ */
