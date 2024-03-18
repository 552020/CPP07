#ifndef ARRAY_H
#define ARRAY_H

#include <stdexcept>

template <typename T>
class Array
{
  private:
	T *elements;
	unsigned int _size;

  public:
	Array() : elements(NULL), _size(0)
	{
	}

	explicit Array(unsigned int n) : _size(n)
	{
		// Here, new T[n]() dynamically allocates an array of n elements of type T, and importantly, it uses parentheses
		// (()) to ensure that each element is default-initialized. For primitive types like int, float, etc., this
		// means they are initialized to 0 or their equivalent zero-value. For class types, their default constructor is
		// called.
		// Alsternative:
		// elements = new T[n];
		elements = new T[n]();
	}

	Array(const Array &other) : _size(other._size), elements(new T[other._size])
	{
		for (unsigned int i = 0; i < _size; ++i)
		{
			elements[i] = other.elements[i]; // Direct copy of elements
		}
	}

	~Array()
	{
		delete[] elements;
	}

	Array &operator=(const Array &other)
	{
		if (this != &other)
		{
			delete[] elements;
			_size = other._size;
			elements = new T[_size]();
			for (unsigned int i = 0; i < _size; ++i)
			{
				elements[i] = other.elements[i];
			}
		}
		return *this;
	}
	// subscript operator [] is overloaded to provide access to the elements of the array
	T &operator[](unsigned int index)
	{
		if (index >= _size)
			// throw std::out_of_range("Index out of bounds");
			throw std::exception("Index out of bounds");
		return elements[index];
	}

	unsigned int size() const
	{
		return _size;
	}
};

#endif // ARRAY_H
