#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>
#include <string>

template <typename T>
void swap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

template <class T>
const T &min(const T &a, const T &b)
{
	return (a < b) ? a : b;
}

template <typename T>
T max(T a, T b)
{
	// a = 42;
	return (a > b) ? a : b;
}

// Version with const T passed by value
/*
template <typename T>
T max(const T a, const T b)
{
	// a = 42;
	return (a > b) ? a : b;
}
*/

// Version with const T passed by reference
/*
template <typename T>
T max(const T &a, const T &b)
{
	return (a > b) ? a : b;
}
*/

// Version with T (no const) passed by reference
/*
template <typename T>
T &max(T &a, T &b)
{
	return (a > b) ? a : b;
}
*/

#endif