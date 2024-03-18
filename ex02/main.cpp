#include "Array.hpp"
#include <iostream>

#define SIZE 10

struct ComplexType
{
	std::string text;
	int number;

	ComplexType(std::string t = "42", int n = 42) : text(t), number(n)
	{
	}
};

void printComplexType(const ComplexType &ct)
{
	std::cout << "{" << ct.text << ", " << ct.number << "}";
}

// Output operator for ComplexType
std::ostream &operator<<(std::ostream &os, const ComplexType &ct)
{
	return os << "{" << ct.text << ", " << ct.number << "}";
}

template <typename T>
void printArray(const Array<T> &array)
{
	for (unsigned int i = 0; i < array.size(); ++i)
	{
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
	if (array.size() == 0)
	{
		std::cout << "Empty array" << std::endl;
	}
}

void printArray(const Array<ComplexType> &array)
{
	for (unsigned int i = 0; i < array.size(); ++i)
	{
		printComplexType(array[i]);
		std::cout << " ";
	}
	std::cout << std::endl;
	if (array.size() == 0)
		std::cout << "Empty array" << std::endl;
}

void testComplexType()
{

	std::cout << "***Test ComplexType***\n" << std::endl;
	// Test default constructor
	std::cout << "***Test default constructor***\n" << std::endl;
	Array<ComplexType> complexArray;
	std::cout << "complexArray size: " << complexArray.size() << std::endl;
	std::cout << "complexArray elements: ";
	printArray(complexArray);
	// Test sized constructor
	std::cout << "***Test sized constructor***\n" << std::endl;
	Array<ComplexType> complexArraySized(SIZE);
	std::cout << "complexArraySized size: " << complexArraySized.size() << std::endl;
	std::cout << "complexArraySized elements: ";
	printArray(complexArraySized);
	// Test copy construction
	Array<ComplexType> complexArrayCopy = complexArraySized;
	std::cout << "complexArrayCopy just after copy construction: ";
	printArray(complexArrayCopy);
	for (unsigned int i = 0; i < complexArrayCopy.size(); ++i)
	{
		std::string text = "new_" + std::to_string(i);
		complexArrayCopy[i] = ComplexType(text, i);
	}
	std::cout << "complexArrayCopy after modification: ";
	printArray(complexArrayCopy);
	std::cout << "complexArraySized after modification of complexArrayCopy: ";
	printArray(complexArraySized);

	// Test assignment operator
	std::cout << "***Test assignment operator***\n" << std::endl;
	Array<ComplexType> anotherComplexArray(SIZE);
	std::cout << "anotherComplexArray size: " << anotherComplexArray.size() << std::endl;
	for (unsigned int i = 0; i < anotherComplexArray.size(); ++i)
	{
		std::string text = "another_" + std::to_string(i);
		anotherComplexArray[i] = ComplexType(text, i);
	}
	std::cout << "anotherComplexArray elements: ";
	printArray(anotherComplexArray);
	complexArrayCopy = anotherComplexArray;
	std::cout << "complexArrayCopy after assignment: ";
	printArray(complexArrayCopy);
	for (unsigned int i = 0; i < complexArrayCopy.size(); ++i)
	{
		std::string text = "new_" + std::to_string(i);
		complexArrayCopy[i] = ComplexType(text, i);
	}
	std::cout << "complexArrayCopy after modification: ";
	printArray(complexArrayCopy);
	std::cout << "anotherComplexArray after modification of complexArrayCopy: ";
	printArray(anotherComplexArray);

	// Test out of bounds access
	std::cout << "***Test out of bounds access***\n" << std::endl;
	try
	{
		std::cout << complexArrayCopy[complexArrayCopy.size()] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
	catch (std::out_of_range &e)
	{
		std::cout << "Caught out_of_range exception: " << e.what() << std::endl;
	}
}

void testSimpleTypes()
{
	std::cout << "***Test simple types***\n" << std::endl;
	// Test default constructor
	std::cout << "***Test default constructor***\n" << std::endl;
	Array<int> intArray;
	std::cout << "intArray size: " << intArray.size() << std::endl;
	std::cout << "intArray elements: ";
	printArray(intArray);
	std::cout << std::endl;

	// Test sized constructor
	std::cout << "***Test sized constructor***\n" << std::endl;
	Array<float> floatArray(SIZE);
	std::cout << "floatArray size: " << floatArray.size() << std::endl;
	std::cout << "floatArray elements: ";
	printArray<float>(floatArray);
	std::cout << std::endl;

	// Test copy construction
	Array<float> floatArrayCopy = floatArray;
	std::cout << "floatArrayCopy just after copy construction: ";
	printArray<float>(floatArrayCopy);
	for (unsigned int i = 0; i < floatArray.size(); ++i)
		floatArray[i] = i * 1.1;
	std::cout << "floatArray after modification: ";
	printArray<float>(floatArray);
	std::cout << "floatArrayCopy after modification of original: ";
	printArray<float>(floatArrayCopy);
	std::cout << std::endl;

	// Test assignment operator
	std::cout << "***Test assignment operator***\n" << std::endl;
	Array<double> doubleArray(SIZE);
	Array<double> anotherDoubleArray(SIZE);
	std::cout << "doubleArray size: " << doubleArray.size() << std::endl;
	for (unsigned int i = 0; i < doubleArray.size(); ++i)
		doubleArray[i] = i * 1.5;
	std::cout << "doubleArray elements: ";
	printArray<double>(doubleArray);
	anotherDoubleArray = doubleArray;
	std::cout << "anotherDoubleArray after assignment: ";
	printArray<double>(anotherDoubleArray);
	for (unsigned int i = 0; i < anotherDoubleArray.size(); ++i)
		anotherDoubleArray[i] = i * 2.5;
	std::cout << "anotherDoubleArray after modification: ";
	printArray<double>(anotherDoubleArray);
	std::cout << "doubleArray after modification of anotherDoubleArray: ";
	printArray<double>(doubleArray);

	// Test out of bounds access
	std::cout << "***Test out of bounds access***\n" << std::endl;
	try
	{
		std::cout << floatArrayCopy[floatArrayCopy.size()] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
	catch (std::out_of_range &e)
	{
		std::cout << "Caught out_of_range exception: " << e.what() << std::endl;
	}
	// Test wrong type copy construction
	std::cout << "***Test wrong type copy construction***\n" << std::endl;
	std::cout << "Array<int> floatArrayCopy = intArray;" << std::endl;
	std::cout << "error: redefinition of 'floatArrayCopy' with a different type: 'Array<int>' vs 'Array<double>'"
			  << std::endl;
	// Array<int> floatArrayCopy = intArray;
	std::cout << std::endl;

	std::cout << "*** Test access out of bounds ***" << std::endl;
	std::cout << "Copied array size: " << floatArrayCopy.size() << std::endl;
	try
	{
		std::cout << "floatArrayCopy[floatArrayCopy.size() - 1]: " << floatArrayCopy[floatArrayCopy.size() - 1]
				  << std::endl;
		std::cout << "floatArrayCopy[floatArrayCopy.size()]: " << floatArrayCopy[floatArrayCopy.size()] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "\nCaught exception: " << e.what() << std::endl;
	}
	catch (std::out_of_range &e)
	{
		std::cout << "\nCaught out_of_range exception: " << e.what() << std::endl;
	}
}

void testConstArray()
{
	Array<int> mutableArray(SIZE);
	for (unsigned int i = 0; i < mutableArray.size(); ++i)
		mutableArray[i] = i;
	const Array<int> constArray = mutableArray;

	std::cout << "***Test const Array***\n" << std::endl;
	std::cout << "mutableArray size: " << mutableArray.size() << std::endl;
	std::cout << "constArray size: " << constArray.size() << std::endl;
	std::cout << "mutableArray elements: ";
	printArray(mutableArray);
	std::cout << "constArray elements: ";
	printArray(constArray);

	for (unsigned int i = 0; i < mutableArray.size(); ++i)
		mutableArray[i] = i * 2;
	std::cout << "mutableArray after modification: ";
	printArray(mutableArray);
	std::cout << "constArray after modification of mutableArray: ";
	printArray(constArray);

	for (unsigned int i = 0; i < constArray.size(); ++i)
	{
		// rror: cannot assign to return value because function 'operator[]' returns a const value
		// constArray[i] = i * 3;
		std::cout << constArray[i] << " ";
	}
	Array<const int> constIntArray(SIZE);
	std::cout << "constIntArray size: " << constIntArray.size() << std::endl;
	std::cout << "constIntArray elements: ";
	printArray(constIntArray);
	for (unsigned int i = 0; i < constIntArray.size(); ++i)
	{
		// error: cannot assign to return value because function 'operator[]' returns a const value
		// constIntArray[i] = i * 4;
		std::cout << constIntArray[i] << " ";
	}
}

int main()
{
	// testSimpleTypes();
	// testComplexType();
	testConstArray();
	return 0;
}