//============================================================================
// Name        : C++11Study.cpp
// Author      : Mateusz
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//#include <iostream>
//#include <string>
//#include <vector>

#include <iostream>

#include "RawString.h"
#include "ForThroughCollection.h"
#include "InitializerList.h"
#include "LambdaMaxFunction.h"
#include "TemplateFactorial.h"
#include "LiteralOperatorExample.h"
#include "TupleExample.h"
#include "VariadicVarargsExample.h"
#include "VariadicSizeofExample.h"
#include "Bind.h"
#include "Regex.h"
#include "TagDispatcher.h"
using namespace std;

int main()
{
	RawString rawString;
	ForThroughCollection forThrough;
	LambdaMaxFunction lambdaMax;
	Basket basket = {"jab³ko", "sliwka", "pomarañcza"};
	basket.addItems({"banan", "marchew"});
	cout << "Silnia z 10 to: " << TemplateFactorial<1, 10>::value << endl << endl;
	LiteralOperatorExample apostropheOperator;
	TupleExample tupleExample;
	VariadicSizeofExample variadicSizeofExample;
	VariadicVarargsExample varargsExample;
	Bind bind;
	//Regex regex;
    TagDispatcher dispatcher;

	return 0;
}
