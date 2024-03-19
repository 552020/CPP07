#include "iter.hpp"

template <typename T>
void increment(T &value)
{
	++value;
}

void incrementInt(int &value)
{
	++value;
}

template <typename T>
void setTo42(T &value)
{
	value = static_cast<T>(42);
}

template <typename T>
void printArray(T *array, int length)
{
	for (int i = 0; i < length; ++i)
	{
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
}

void extra()
{

	int intArr[] = {1, 2, 3, 4, 5};
	int lengthIntArr = sizeof(intArr) / sizeof(intArr[0]);

	std::cout << "Original array: ";
	printArray(intArr, lengthIntArr);
	iter(intArr, lengthIntArr, increment<int>);
	std::cout << "Modified array: ";
	printArray(intArr, lengthIntArr);
	std::cout << std::endl;

	std::cout << "Original array: ";
	printArray(intArr, lengthIntArr);
	iter(intArr, lengthIntArr, incrementInt);
	std::cout << "Modified array: ";
	printArray(intArr, lengthIntArr);
	std::cout << std::endl;

	// Example with chars
	char CharArr[] = {'a', 'b', 'c', 'd', 'e'};
	int lengthC = sizeof(CharArr) / sizeof(CharArr[0]);

	std::cout << "Original char array: ";
	printArray(CharArr, lengthC);
	// iter(CharArr, lengthC, increment);
	std::cout << "Modified char array: ";
	printArray(CharArr, lengthC);
	std::cout << std::endl;

	std::cout << "Original array: ";
	printArray(intArr, lengthIntArr);
	// iter(intArr, lengthIntArr, setTo42);
	std::cout << "Modified array: ";
	printArray(intArr, lengthIntArr);
}

int main()
{
	int intArr[] = {1, 2, 3, 4, 5};
	int lengthIntArr = sizeof(intArr) / sizeof(intArr[0]);

	std::cout << "Original array: ";
	printArray(intArr, lengthIntArr);
	iter(intArr, lengthIntArr, increment<int>);
	std::cout << "Modified array: ";
	printArray(intArr, lengthIntArr);
	std::cout << std::endl;

	// Example with chars
	char CharArr[] = {'a', 'b', 'c', 'd', 'e'};
	int lengthC = sizeof(CharArr) / sizeof(CharArr[0]);

	std::cout << "Original char array: ";
	printArray(CharArr, lengthC);
	iter(CharArr, lengthC, increment<char>);
	std::cout << "Modified char array: ";
	printArray(CharArr, lengthC);
	std::cout << std::endl;

	std::cout << "Original array: ";
	printArray(intArr, lengthIntArr);
	iter(intArr, lengthIntArr, setTo42<int>);
	std::cout << "Modified array: ";
	printArray(intArr, lengthIntArr);

	return 0;
}
