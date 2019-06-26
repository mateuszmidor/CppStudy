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
		return (output);
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
 * Stream operation: Map, to be used with functors and standalone functions
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
 * Stream operation: Map; to be used with class member functions like Map(Person::getName)
 */
template <class FPTR>
class MemberMapStream {
	FPTR fptr;
public:
	MemberMapStream(FPTR fptr) : fptr(fptr) {}

	template<class T, class ReturnType = std::result_of_t<decltype(fptr)(T)>>
	auto apply(const vector<T> &v) {
		vector<ReturnType> output;
		output.reserve(v.size());
		for (const auto &item : v)
			output.push_back((item.*fptr)());

		return output;
	}
};

// Helper function
template <class FuncRet, class Obj, class FPTR = FuncRet (Obj::*)() const>
MemberMapStream<FPTR> Map(FuncRet (Obj::*fptr)() const) {
	return MemberMapStream<FPTR>(fptr);
}

//template <class FuncRet, class... FuncArgs, class Obj>
//auto run_this_guy(FuncRet (Obj::*fptr)(FuncArgs...), Obj& obj) {
//   return [&obj, fptr](FuncArgs...args) { return (obj.*fptr)(args...); };
//}

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
 * Stream operation: Exec
 */
class Exec {

};
template <class Stream>
void operator| ( Stream &&s, Exec&& ) {
	s.eval();
}

/**
 * Application entry point
 */
int main() {
	vector<string> cchannels { "POP", "ROCK", "BLUES" };
	vector<string> nchannels { "POP", "BLUES", "CHRISTIAN" };

	// 1. remove channels
	auto is_channel_to_be_removed = [&] (const auto& s) { return find(nchannels.begin(), nchannels.end(), s) == nchannels.end();};
	auto channel_to_iterator = [&](const auto& s) { return find(cchannels.begin(), cchannels.end(), s); };
	auto remove_channel = [&](const auto& i) { cchannels.erase(i); };

	Stream(cchannels)
	| Filter ( is_channel_to_be_removed )
	| Map    ( channel_to_iterator )
	| ForEach( remove_channel )
	| Exec();

	// 2. add new channels
	auto should_add_channel = [&] (const string& s) { return find(cchannels.begin(), cchannels.end(), s) == cchannels.end();};
	auto add_channel = [&](const string& s) { cchannels.push_back(s); };
	Stream(nchannels)
	| Filter( should_add_channel )
	| ForEach( add_channel )
	| Exec();

	// 3. printout channels
	auto print = [] (const auto& s) { cout << s << " " << endl; };
	Stream(cchannels)
	| Sort()
	| ForEach( print )
	| Exec();




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


	// 4. work with structures
	struct Person {
		string name;
		int age;

		string get_name() const { return name; }
		int get_age() const { return age; }

		static auto younger_than(int age) { return [age](const Person& p) { return p.get_age() < age; }; }
		static auto older_than(int age) { return [age](const Person& p) { return p.get_age() > age; }; }
	};
	
	vector<Person> people { {"Iza", 19}, {"Ela", 44},  {"Werka", 24} };
	Stream(people)
	| Filter(Person::younger_than(35))
	| Filter(Person::older_than(21))
	| Map(Person::get_name)
	| ForEach(print)
	| Exec();

	return 0;
}
