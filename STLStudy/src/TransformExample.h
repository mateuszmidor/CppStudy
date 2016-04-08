/*
 * TransformExample.h
 *
 *  Created on: 25-11-2013
 *      Author: mateusz
 */

#ifndef TRANSFORMEXAMPLE_H_
#define TRANSFORMEXAMPLE_H_

#include <algorithm>
#include <numeric>
#include <iostream>
#include <vector>
using namespace std;

class TransformExample
{
private:
	void printVec(const vector<double> &v)
	{
		for (vector<double>::const_iterator it = v.begin(); it != v.end(); it++)
			cout << setprecision(2) << *it << " ";
		cout << endl;
	}

public:
	TransformExample()
	{
		cout << "Transform&accumulate example. Will calculate dot product" << endl;
		double x_array[] =	{ 1.0, 0.0, 1.0 };
		double y_array[] =	{ 0.0, 1.0, 0.0 };

		vector<double> x_vec(x_array, x_array + 3);
		vector<double> y_vec(y_array, y_array + 3);
		vector<double> x_mul_y(3, 0.0);

		transform(x_vec.begin(), x_vec.end(), y_vec.begin(), x_mul_y.begin(),
				multiplies<double>());

		double result = accumulate(x_mul_y.begin(), x_mul_y.end(), 0.0);

		cout << "The dotProduct of:" << endl;
		printVec(x_vec);
		printVec(y_vec);
		cout << "is: " << endl;
		cout << result;

		cout << endl << endl;
	}
};

#endif /* TRANSFORMEXAMPLE_H_ */
