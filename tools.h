#pragma once
/////////////
//Tools.h
/////////////
#include <utility>

struct Arg1_t
{
}arg1;

#define	MAKE_BINARY_OPERATOR(name, op)									\
template <class T>														\
struct name																\
{																		\
	explicit name(T than) :than(than) {}								\
	template <class U>													\
	bool operator()(U &&other){return (std::forward<U>(other) op than);}\
	T than;																\
};																		\
template<class T>														\
name<T> operator op (const Arg1_t arg1, T&& other)						\
{return name<T>(std::forward<T>(other));}

#define MAKE_OPOSING_BINARY_OPERATORS_ONE_WAY(name1, name2)	\
template<class T>											\
name1<T> operator!(const name2<T> &other)					\
{return name1<T>(other.than);}								\

#define MAKE_OPORING_BINARY_OPERATORS(name1, name2)	\
MAKE_OPOSING_BINARY_OPERATORS_ONE_WAY(name1, name2)	\
MAKE_OPOSING_BINARY_OPERATORS_ONE_WAY(name2, name1)	\

#define MAKE_BINARY_OPERATORS_SET(name1, op1, name2, op2)\
MAKE_BINARY_OPERATOR(name1, op1)						\
MAKE_BINARY_OPERATOR(name2, op2)						\
MAKE_OPORING_BINARY_OPERATORS(name1, name2);			\

MAKE_BINARY_OPERATORS_SET(LessThan, <, BiggerEqualThan, >=);
MAKE_BINARY_OPERATORS_SET(LessEqualThan, <= , BiggerThan, > );
MAKE_BINARY_OPERATORS_SET(Equals, == , NotEquals, != );
MAKE_BINARY_OPERATORS_SET(BinaryAnd, &, BinaryOr, |);

