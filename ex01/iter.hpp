#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T, typename Func>
void iter(T *array, size_t size, Func func)
{
	for (size_t i = 0; i < size; ++i)
		func(array[i]);
}

/* Alternative solution
// Accepting a function taking a non-const reference to T
template <typename T>
void iter(T *array, size_t length, void (*func)(T &))
{
	for (size_t i = 0; i < length; i++)
		func(array[i]);
}

// Accepting a function taking a const reference to T
template <typename T>
void iter(T *array, size_t length, void (*func)(const T &))
{
	for (size_t i = 0; i < length; i++)
		func(array[i]);
}
*/

#endif