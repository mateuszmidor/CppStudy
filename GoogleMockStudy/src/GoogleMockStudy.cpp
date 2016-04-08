// this should be compiled as a seperate project to a static library
// and linked to the executable,
// but to keep whole study within one project it is just included here :)
#include "src/gtest-all.cc"
#include "src/gmock-all.cc"


using namespace std;

int main(int argc, char* argv[])
{
	::testing::InitGoogleMock(&argc, argv);
	return RUN_ALL_TESTS();
}
