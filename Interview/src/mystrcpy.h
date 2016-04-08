/*
 * mystrcpy.h
 *
 *  Created on: Oct 20, 2015
 *      Author: user
 */

#ifndef SRC_MYSTRCPY_H_
#define SRC_MYSTRCPY_H_


#include <iostream>
#include <cstring>

using std::cout;
using std::endl;

void mystrcpy(char *dst, const char *src)
{
	while (*(dst++) = *(src++));
}

void mystrcpyExample()
{
    cout << "[mystrcpy]" << endl;

    const char *SOURCE = "Panie Droza, Smiechu Warte, idz Pan ... z takim zartem!";
    char dst[100];

    mystrcpy(dst, SOURCE);
    cout << dst << endl;

    cout << endl;
}



#endif /* SRC_MYSTRCPY_H_ */
