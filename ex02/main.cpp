#include "Array.hpp"
#include <iostream>

int main()
{
	// Test default constructor
	Array<int> intArray;
	std::cout << "Empty int array size: " << intArray.size() << std::endl;

	// Test sized constructor and element access
	Array<double> doubleArray(5);
	std::cout << "Double array size: " << doubleArray.size() << std::endl;
	for (unsigned int i = 0; i < doubleArray.size(); ++i)
	{
		std::cout << doubleArray[i] << " ";
	}
	std::cout << std::endl;

	// Test copy construction
	Array<double> copiedArray = doubleArray;
	// Modify the original array
	for (unsigned int i = 0; i < doubleArray.size(); ++i)
	{
		doubleArray[i] = i * 1.1;
	}

	// Checking copied array remains unchanged
	std::cout << "Copied array after modifying the original: ";
	for (unsigned int i = 0; i < copiedArray.size(); ++i)
	{
		std::cout << copiedArray[i] << " ";
	}
	std::cout << std::endl;

	// Test out of bounds access
	try
	{
		std::cout << copiedArray[copiedArray.size()] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}

	Array<std::string> stringArray(3);
	stringArray[0] = "Hello";
	stringArray[1] = "World";
	stringArray[2] = "!";
	std::cout << "String array contents: ";
	for (unsigned int i = 0; i < stringArray.size(); ++i)
	{
		std::cout << stringArray[i] << " ";
	}
	std::cout << std::endl;

	Array<int> copiedArray = intArray;
	std::cout << "Copied array size: " << copiedArray.size() << std::endl;
	for (unsigned int i = 0; i < copiedArray.size(); ++i)
	{
		std::cout << "copiedArray[" << i << "] = " << copiedArray[i] << std::endl;
	}

	// Modify original array to prove deep copy
	intArray[0] = 42;
	std::cout << "After modification, intArray[0] = " << intArray[0] << ", copiedArray[0] = " << copiedArray[0]
			  << std::endl;

	// Test out-of-bounds access
	try
	{
		std::cout << "Attempting out-of-bounds access: ";
		std::cout << intArray[intArray.size()] << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}
