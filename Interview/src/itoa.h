/*
 * itoa.h
 *
 *  Created on: 16 paü 2015
 *      Author: m.midor
 */

#ifndef SRC_ITOA_H_
#define SRC_ITOA_H_

#include <iostream>
#include <cstring>

using std::cout;
using std::endl;

void reverse(char *a, char *b)
{
    while (a < b)
    {
        char tmp = *a;
        *a = *b;
        *b = tmp;
        a++;
        b--;
    }
}

void itoa(int i, char out_buff[])
{
    bool isNegative = i < 0;
    if (isNegative) i = -i;
    int index = 0;
    do
    {
        unsigned rem = i % 10;
        i /= 10;
        out_buff[index++] = '0' + rem;
    } while (i);

    if (isNegative) out_buff[index++] = '-';
    out_buff[index] = '\0';
    reverse(out_buff, out_buff + index - 1);
}

void itoaExample()
{
    cout << "[itoa]" << endl;

    char buff[20] = {'\0'};

    itoa(127, buff);
    cout << buff << endl;

    itoa(0, buff);
    cout << buff << endl;

    itoa(-255, buff);
    cout << buff << endl;

    cout << endl;
}



#endif /* SRC_ITOA_H_ */
