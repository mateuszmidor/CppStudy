/**
 * @file CustomTuple.cpp
 * @author Mateusz Midor
 * @date 18.04.2016
 * @brief Example of custom-made tuple with util functions
 */


#include "tuple.h"

using namespace std;

int main() {
    cout << boolalpha;

    // create tuple with constructor; cumbersome
    constexpr Tuple<int, bool> t1(7, true);
    	print(t1);

    // create tuple with convenience tuple-maker
    auto t2 = MakeTuple(false, 0, 5.05);
        print(t2);

    // setup tuple values
    setup(t2, true, 5, 11.1);
        print(t2);

	// set just a single value in tuple
    Set<1>(t2, 500);
        print(t2);

	// get a single value from tuple
    cout << Get<2>  (t2) << endl;
}
