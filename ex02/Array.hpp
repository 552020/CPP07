#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <stdexcept>
#include <string>

template <typename T>
class Array
{
  private:
	T *_array;
	unsigned int _size;

  public:
	Array();
	// alternative: explicit Array(unsinged int)
	Array(unsigned int n);
	Array(const Array &other);
	Array &operator=(const Array &other);
	~Array();
	// subscript operator
	const T &operator[](unsigned int index) const;
	T &operator[](unsigned int index);

	unsigned int size() const;
};

#include "Array.tpp"

#endif

// Note 1: Paremeterized constructor: elements = new T[n]();
/*
Here, new T[n]() dynamically allocates an array of n elements of type T, and importantly, it uses parentheses(()) to
ensure that each element is default-initialized. For primitive types like int, float, etc., this means they are
initialized to 0 or their equivalent zero-value. For class types, their default constructor is called.

Alsternative:
elements = new T[n];
*/
