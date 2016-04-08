/*
 * DequeExample.h
 *
 *  Created on: 22-11-2013
 *      Author: mateusz
 */

#ifndef DEQUEEXAMPLE_H_
#define DEQUEEXAMPLE_H_

#include <deque>
#include <iostream>
#include <iomanip>
using namespace std;

class DequeExample
{
public:
	DequeExample()
	{
		cout << "Deque example." << endl;

		deque<double> deq;
		cout << "Filling up deque front and back..." << endl;
		for (int i = 1; i <= 10; i++) {
			deq.push_back((double)i);
			deq.push_front((double)1.0/i);
		}

		cout << "Done. Printing deque with iterator..." << endl;
		for (deque<double>::const_iterator it = deq.begin(); it != deq.end(); it++)
			cout << setprecision(2) << *it << " ";

		cout << endl << endl;
	}


};



#endif /* DEQUEEXAMPLE_H_ */
