/*
 * BackInserterExample.h
 *
 *  Created on: 10-01-2014
 *      Author: mateusz
 */

#ifndef BACKINSERTEREXAMPLE_H_
#define BACKINSERTEREXAMPLE_H_

#include <iostream>
#include <sstream>
#include <list>
#include <iterator>
#include <algorithm>

namespace std
{

class BackInserterExample
{
public:
	BackInserterExample()
	{
		cout << "back_inserter example." << endl;

		string s = "alfa beta gamma delta"; // input source
		stringstream input(s); // input stream

		istream_iterator<string> in(input); // input stream iterator
		istream_iterator<string> eos; // end of stream marker

		list<string> words; // container for words
		auto inserter = back_inserter(words); // inserter iterator will insert into words on copying to it
		copy(in, eos, inserter); // copy in -> inserter -> words

		ostream_iterator<string> out(cout, "; "); // output interator with ';' delimiter
		copy(words.begin(), words.end(), out); // copy words -> out -> cout

		cout << endl << endl;
	}
};

} /* namespace std */

#endif /* BACKINSERTEREXAMPLE_H_ */
