/*
 * splitstring.h
 *
 *  Created on: Oct 17, 2015
 *      Author: user
 */

#ifndef SRC_SPLITSTRING_H_
#define SRC_SPLITSTRING_H_

#include <iostream>
#include <string>
#include <list>

using std::cout;
using std::endl;
using std::string;
using std::list;

// Split string based on delimiter.
// C is container type for resulting string list
template <typename C>
C splitString(const string &s, char delimiter)
{
	// define result holder
	C result;

	// segment begin, segment end
	string::const_iterator sBegin = s.begin();
	string::const_iterator sEnd = s.begin();

	// scan the string till the end
	while (sEnd != s.end())
	{
		// if delimiter found
		if (*sEnd == delimiter)
		{
			// add the string segment to results
			result.push_back(string(sBegin, sEnd));

			// move the begin past the delimiter
			sBegin = sEnd + 1;
		}
		++sEnd;
	}

	// add remaining string segment and return
	result.push_back(string(sBegin, sEnd));
	return result;
}

void splitStringExample()
{
	cout << "[splitstring]" << endl;

	typedef list<string> StringList;

	StringList strings = splitString<StringList>("jeden:dwa:trzy", ':');
	for (StringList::const_iterator s = strings.begin(); s != strings.end(); ++s)
		cout << *s << " ";

	cout << endl << endl;
}

#endif /* SRC_SPLITSTRING_H_ */
