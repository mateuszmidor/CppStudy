#include <type_traits>
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::enable_if;


/**
 * @section Tuple definition
 */

// Tuple class declaration
template <class... V>
struct Tuple;

// Specialization for zero-element tuple
template <>
struct Tuple<>  { };

// Specialization for 1+ element tuple
template <class H, class... T>
struct Tuple<H, T...> : Tuple<T...>
{
	// Default constructor
    constexpr Tuple() = default;

    // Recursive constructor
    constexpr Tuple(H h, T... t) : Tuple<T...>(t...), item(h) {}

    // this is the actual element holder
    H item;
};


/**
 * @section Tuple util functions - MakeTuple, getters, setters, printers
 */

// Element cast to type (convenience function)
template <class T, class V>
T As(const V & obj)
{
    return static_cast<const T &>(obj);
}

template <class T, class V>
T As(V & obj)
{
    return static_cast<T &>(obj);
}

// Print tuple
template <class H, class... T>
void print(const Tuple<H, T...> &t)
{
    cout << "  " << t.item  << endl;
	
	using TailType = Tuple<T...>;
     
    print(As<TailType>(t));
}

void print(const Tuple<> &t)
{
    cout <<  "<END>" <<endl;
}


// Assign tuple elements with values
template <class H, class... T>
void setup(Tuple<H, T...> &t, H item, T... tail)
{
    t.item = item;
    using TailType = Tuple<T...>;
    setup(As<TailType&>(t), tail...);
}

void setup(Tuple<> &t) {}


// Select the type of n-th element (type function)
template <int N, class... V>
struct Select;

template <int N, class H, class...T>
struct Select<N, H, T...> : Select<N-1, T...> {};

template <class H, class... T>
struct Select<0, H, T...>
{
    using type = H;
};


// Get the value of n-th element
template <class R, class H, class... T>
constexpr R GetNth(const Tuple<H, T...> &t, int N)
{
    return (N == 0) ? t.item : GetNth<R, T...>(t, N-1);
}

template <int N, class...V>
constexpr typename Select<N, V...>::type Get(const Tuple<V...> &t)
{
    using R = typename Select<N, V...>::type;
    return GetNth<R, V...>(t, N);
}

// Set n-th element value
template <int N, class V, class H, class ... T>
constexpr typename enable_if<N>::type
 Set(Tuple<H, T...> &t, V item)
{
    using TailType = Tuple<T...>;
    Set<N-1>(As<TailType&>(t), item);
}

template <int N, class V, class H, class ... T>
constexpr typename enable_if<!N>::type
 Set(Tuple<H, T...> &t, V item)
{
    t.item = item;
}

// make_tuple convenience function
template <class...V>
constexpr Tuple<V...> MakeTuple(V... values)
{
    return Tuple<V...>(values...);
}
