#include <iostream>
using namespace std;

template <typename NumberProvider>
int returnNumber()
{
    NumberProvider n;

    // here the duck typing takes place;
    // NumberProvider has no common interface
    // it only needs to provide "int getNumber()" method
    return n.getNumber();
}

struct Provider1
{
	// nonstatic
    int getNumber()
    {
        return 1;
    }
};

struct Provider100
{
	// static - makes no difference!
    static int getNumber()
    {
        return 100;
    }
};

int main()
{
   cout << "Duck typing study - dont care about common ancestor if the signatures in both objects match." << endl;

   // returnNumber called with non-related classes
   // you can call it with any class that provides "int getNumber()" method
   cout << returnNumber<Provider1>() << endl;
   cout << returnNumber<Provider100>() << endl;

   return 0;
}
