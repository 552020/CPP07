#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

// Accepting a function taking a non-const reference to T
/*
template <typename T>
void iter(T *array, size_t length, void (*func)(T &))
{
	for (size_t i = 0; i < length; i++)
		func(array[i]);
}
*/

// Accepting a function taking a const reference to T
/*
template <typename T>
void iter(T *array, size_t length, void (*func)(const T &))
{
	for (size_t i = 0; i < length; i++)
		func(array[i]);
}
*/

template <typename T, typename Func>
void iter(T *array, size_t size, Func func)
{
	for (size_t i = 0; i < size; ++i)
		func(array[i]);
}

/* For testing  purpsoses */
template <typename T>
void printElement(const T &x)
{
	std::cout << x << std::endl;
}

#endif