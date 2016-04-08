/*
 * atoi.h
 *
 *  Created on: 16 paü 2015
 *      Author: m.midor
 */

#ifndef SRC_ATOI_H_
#define SRC_ATOI_H_

#include <iostream>
#include <cstring>

using std::cout;
using std::endl;

int atoi(const char a[])
{
    int len = strlen(a);
    int multiplier = 1;
    int result = 0;

    for (int i = len-1; i > 0; i--)
    {
        result += (a[i] - '0') * multiplier;
        multiplier *= 10;
    }

    if (a[0] == '-')
        result = -result;
    else
        result += (a[0] - '0') * multiplier;

    return result;

}

void atoiExample()
{
    cout << "[atoi]" << endl;

    cout << atoi("127") << endl;
    cout << atoi("0") << endl;
    cout << atoi("-255") << endl;

    cout << endl;
}


#endif /* SRC_ATOI_H_ */
