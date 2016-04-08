//============================================================================
// Name        : CustomIterator.cpp
// Author      : Mateusz
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>     // std::cout
#include "MyBag.h"

using namespace std;

int main()
{
	int numbers[] = { 10, 20, 30, 40, 50 };
	MyBag bag(numbers, 5);

	for (auto n : bag)
		cout << n << ' ';

	cout << endl;

	return 0;
}
