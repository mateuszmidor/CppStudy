/*
 * any.h
 *
 *  Created on: Oct 19, 2015
 *      Author: user
 */

#ifndef SRC_ANY_H_
#define SRC_ANY_H_

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <functional>

using std::cout;
using std::endl;
using std::string;
using std::function;


// This is "delete" func template
template <typename T>
void delete_func(void * p) {
   delete static_cast<T*>(p);
}

// This is "clone" func template
template <typename T>
void* copy_func(void * p) {
	T* tp = static_cast<T*>(p);
    return new T(*tp);
}

// This type can represent any copyable type
class Any final
{
    void *payload = nullptr;
    function< void (void*) > deleter;
    function< void* (void*) > copier;

public:
    // No need default constructor/assignment operator. For simplicity
    Any() = delete;

    // Converting constructor
    template <typename T>
    Any(const T& what)
    {
        payload = new T(what);
        deleter = delete_func<T>;
        copier = copy_func<T>;
    }

    // Copy constructor
    Any(const Any& what)
    {
        payload = what.copier(what.payload);
        copier = what.copier;
        deleter = what.deleter;
    }

    // Make clean
    ~Any()
    {
        deleter(payload);
    }

    // Cast back to specific type
    template <typename T>
    friend T any_cast(const Any& a);
};

// Cast Any to precise type
template <typename T>
T any_cast(const Any& a)
{
    return *static_cast<T*>(a.payload);
}

void anytypeExample()
{
	cout << "[any]" << endl;

	// Heterogenic vector
    std::vector<Any> student_grade {string("Anna Tomasik"), 4.5,};

    cout << any_cast<string>(student_grade[0]) << endl;
    cout << any_cast<double>(student_grade[1]) << endl;

    cout << endl;
}


#endif /* SRC_ANY_H_ */
