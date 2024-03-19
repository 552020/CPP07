#include <iostream>

const int increment(int value)
{
	return value + 1;
}

int const &incrementConstRef(int &value)
{
	return value + 1;
}

/*
eturning_const.cpp:10:9: warning: returning reference to local temporary object [-Wreturn-stack-address]
		return value + 1;
			   ^~~~~~~~~
returning_const.cpp:15:9: error: non-const lvalue reference to type 'int' cannot bind to a temporary of type 'int'
		return value + 1;
			   ^~~~~~~~~
1 warning and 1 error generated.

int &incrementConstRef(int const &value)
{
	return value + 1;
}
*/

int &incrementRef(int &value)
{
	value += 1;
	return value;
}

int &returnInt(int &value)
{
	return value;
}

int main()
{

	int a = 42;
	int &aRef = a;
	// Increment `a` to 43
	a = increment(a); // `a` is now 43

	// Try to reassign `a` to 45
	a = 45; // This is perfectly valid.

	// Try to increment `a` using the function and directly modify it afterwards
	// This would not be valid: increment(a) = 50; // Error: left operand must be l-value
	increment(a); // `a` is now 46 in the function scope but not in the main scope
	// increment(a) = 50; // Error: left operand must be l-value // This would not work even if the function wourld
	// return a non const value

	std::cout << "a: " << a << std::endl; // Prints "a: 45"
}
