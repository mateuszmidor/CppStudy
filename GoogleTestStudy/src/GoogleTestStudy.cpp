/**
 * Google Test Study.
 * Needs gtest-1.7.0 and gtest-1.7.0/include to be on Include path
 */

#include <iostream>


// this should be compiled as a seperate project to a static library
// and linked to the executable,
// but to keep whole study within one project it is just included here :)
#include "src/gtest-all.cc"

using namespace std;




int main(int argc, char* argv[])
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}



