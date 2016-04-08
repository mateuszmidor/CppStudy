/*
 * main.cpp
 *
 *  Created on: 07-01-2014
 *      Author: mateusz
 */

#include <iostream>

using namespace std;

template <typename ReturnType>
ReturnType bin2dec()
{
	return 0;
}

template <typename ReturnType, char head, char... tail>
ReturnType bin2dec()
{
	static_assert(head == '0' || head == '1', "binary literal must only contain 0 and 1 ");
	return (head == '0' ? 0 : 1ULL << sizeof...(tail)) + bin2dec<ReturnType, tail...>();
}

template <char... binary>
unsigned long long operator "" _b()
{
	return bin2dec<unsigned long long, binary...>();
}

int main()
{
	cout << 010_b << endl;
	cout << 100_b << endl;
	cout << 110_b << endl;
	return 0;
}

