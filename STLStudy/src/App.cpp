//============================================================================
// Name        : STLStudy.cpp
// Author      : Mateusz
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#include "ListExample.h"
#include "VectorExample.h"
#include "DequeExample.h"

#include "SetExample.h"
#include "MultisetExample.h"
#include "MapExample.h"
#include "MinMaxExample.h"
#include "FindExample.h"
#include "SortReverseForEachExample.h"
#include "TransformExample.h"
#include "OstreamIteratorExample.h"
#include "PartitionExample.h"
#include "BackInserterExample.h"
using namespace std;

int main() {
	// podstawowe kontenery
	VectorExample vectorExample; // vector
	ListExample listExample; // list
	DequeExample dequeExample; // deque

	// kontenery asocjacyjne
	SetExample setExample; // set
	MultisetExample multisetExample; // multiset
	MapExample mapExample; // map

	// adaptery kontenerów- wykorzystuj¹ kontenery podstawowe
	// ale dostarczaj¹ inny interfejs, np brak begin() i end()
	// queue
	// stack
	// prirityqueue

	MinMaxExample mMinMaxExample; // funkcja min_element i max_element
	FindExample findExample; // funkcja find
	SortReverseForEachExample sortReverseExample; // funkcja sort i reverse
	TransformExample transformExample; // funkcja transform dla obliczenia dotProduct

	OstreamIteratorExample ostreamIteratorExample; // ostream_iterator
	PartitionExample partionExample; // partition()
	BackInserterExample backInserterExample; // back_inserter

	return 0;
}
