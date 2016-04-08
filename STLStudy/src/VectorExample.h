/*
 * VectorExample.h
 *
 *  Created on: 22-11-2013
 *      Author: mateusz
 */

#ifndef VECTOREXAMPLE_H_
#define VECTOREXAMPLE_H_

#include <iostream>
#include <vector>
using namespace std;

class VectorExample
{
public:
	VectorExample();

private:
	static const int NUM_ITEMS = 30;
};

VectorExample::VectorExample()
{
	cout << "Vector example" << endl;
	vector<int> vec;
	cout << "Filling up vector..." << endl;
	for (int i = 1; i <= NUM_ITEMS; i++)
	{
		vec.push_back(i);
	}

	cout << "Done." << endl << "Printing every third item..." << endl;
	for (int i = 0; i < NUM_ITEMS; i += 3)
	{
		cout << vec[i] << " ";
	}
	cout << endl << endl;
}

#endif /* VECTOREXAMPLE_H_ */
