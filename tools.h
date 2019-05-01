#pragma once
/////////////
//Tools.h
/////////////
#include <utility>

struct Arg1_t
{
}arg1;

// T < value
template <class T>
struct lessThan
{
	lessThan(T than) :than(than) {}
	
	template <class U>
	bool operator()(U &&other)
	{
		return (std::forward<U>(other) < than);
	}

	T than;
};

template<class T>
lessThan<T> operator<(const Arg1_t arg1, T&& other)
{
	return lessThan<T>(std::forward<T>(other));
}