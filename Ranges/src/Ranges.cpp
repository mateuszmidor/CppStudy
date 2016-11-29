//============================================================================
// Name        : Ranges.cpp
// Author      : Mateusz Midor
// Copyright   :
// Description : Ranges prototype based loosely on Java8 Streams
//============================================================================

#include <iostream>
#include <vector>
#include <initializer_list>
#include <algorithm>
#include <iterator>

using namespace std;


/**
 * Stream as a collection holder
 */
template <class T>
class BaseStream {
	vector<T> v;
public:
	BaseStream(const vector<T> &v) : v(v) {}
	vector<T>&& eval() {
		return move(v);
	}
};

// Helper function
template <class T>
BaseStream<T> Stream(const vector<T> &v) {
	return BaseStream<T>(v);
}

/**
 * Stream as a composition: internal stream + action to perform on that stream
 */
template <class Stream, class Action>
class CompoundStream {
	Stream s;
	Action a;
public:
	CompoundStream(const Stream &s, const Action &a) : s(s), a(a) {}
	auto eval() {
		return a.apply(s.eval());
	}
};

/**
 * Stream operation: Filter
 */
template <class Predicate>
class FilterStream {
	Predicate pred;
public:
	FilterStream(Predicate pred) :  pred(pred) {}

	template<class T>
	auto apply(const vector<T> &v) {
		vector<T>  output;
		copy_if(v.begin(), v.end(), back_inserter(output), pred);
		return output;
	}
};

// Helper function
template <class Predicate>
FilterStream<Predicate> Filter(Predicate p) {
	return FilterStream<Predicate>(p);
}

/**
 * Stream operation: Sort
 */
class Sort {
public:
	template<class T>
	auto apply(const vector<T> &v) {
		vector<T>  output(v);
		sort(output.begin(), output.end(), [](string s1, string s2) { return s1 > s2;});
		return output;
	}
};

/**
 * Stream operation: Limit
 */
class Limit {
	unsigned count;
public:
	Limit(unsigned count) : count(count) {}
	template<class T>
	auto apply(const vector<T> &v) {
		return vector<T>(v.begin(), v.begin() + count);
	}
};

/**
 * Stream operation: Map
 */
template <class Operation>
class MapStream {
	Operation op;
public:
	MapStream(Operation op) : op(op) {}

	template<class T, class ReturnType = result_of_t<Operation(T)>>
	auto apply(const vector<T> &v) {
		vector<ReturnType> output (v.size());
		transform(v.begin(), v.end(), output.begin(), op);
		return output;
	}
};

// Helper function
template <class Operation>
MapStream<Operation> Map(Operation op) {
	return MapStream<Operation>(op);

}

/**
 * Stream operation: ForEach
 */
template <class Operation>
class ForEachStream {
	Operation op;
public:
	ForEachStream(Operation op) : op(op) {}

	template<class T>
	auto apply(const vector<T> &v) {
		for_each(v.begin(), v.end(), op);
		return v;
	}
};

// Helper function
template <class Operation>
ForEachStream<Operation> ForEach(Operation o) {
	return ForEachStream<Operation>(o);
}

/**
 * Steam operations concatenation operation
 */
template <class Stream, class Action>
auto operator | (const Stream &s, const Action& a) {
	return CompoundStream<Stream, Action>(s, a);
}


/**
 * Application entry point
 */
int main() {
	// 1. work with integers
	vector<int> v { 1, 2, 3, 4, 5};
	auto istream =
		Stream(v)
		| Filter([](int i) { return i % 2 == 1; })
		| Map([](int i) { return to_string(i) + " is an odd number"; })
		| ForEach([](string s) { cout << s << endl;});

	// all the operations on stream are applied just here
	istream.eval();


	// 2. work with characters
	vector<char> c { 'a', 'b', 'c', 'd', 'e' };
	auto cstream=
		Stream(c)
		| Limit(3)
		| Map([](char c) { return toupper(c);})
		| ForEach([](char c) { cout << c << endl;});

	cstream.eval();


	// 3. work with strings
	vector<string> s { "lois", "bart", "sanders"};
	auto charToUpper = [](char c) { return toupper(c); };
	auto strToUpper = [charToUpper](string s) { transform(s.begin(), s.end(), s.begin(), charToUpper); return s;};
	auto sstream=
		Stream(s)
		| Map(strToUpper)
		| Sort()
		| ForEach([](string s) { cout << s << endl;});

	sstream.eval();


	return 0;
}
