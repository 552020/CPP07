#include <iostream>

const int &getNumber()
{
	int localNumber = 42; // Local variable
	std::cout << "localNumber: " << localNumber << std::endl;
	return localNumber; // WARNING: Returning reference to local variable!
}

int main()
{
	const int &myNumber = getNumber();
	std::cout << "myNumber: " << myNumber << std::endl;
	// `myNumber` now refers to a destroyed object!
	// Using `myNumber` here is undefined behavior.
}
