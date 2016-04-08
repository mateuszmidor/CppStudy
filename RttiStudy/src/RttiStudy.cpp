#include <iostream>
#include <typeinfo.h>

class Base
{
public:
	virtual void vvfunc()
	{
	}
	virtual ~Base()
	{
	}
};

class Derived: public Base
{
};

using namespace std;
int main()
{
	Derived* pd = new Derived;
	Base* pb = pd;

	cout << typeid( pb ).name() << endl;   //prints Base
	cout << typeid( *pb ).name() << endl;   //prints Derived
	cout << typeid( pd ).name() << endl;   //prints Derived*
	cout << typeid( *pd ).name() << endl;   //prints Derived

	delete pd;
}
