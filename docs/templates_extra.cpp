#include <iostream>
#include <string>

// Function template to find the maximum of two values
template <typename T> T myMax(T x, T y)
{
	return (x > y) ? x : y;
}

// Class template for a Box that can hold any type of item
template <typename T> class Box
{
  private:
	T content;

  public:
	void setContent(T newContent)
	{
		content = newContent;
	}
	T getContent()
	{
		return content;
	}
};

int main()
{
	// Using the max function template
	int intMax = myMax(10, 5);												 // with int
	std::string strMax = myMax(std::string("apple"), std::string("orange")); // with string

	std::cout << "The max of 10 and 5 is " << intMax << std::endl;
	std::cout << "The max of 'apple' and 'orange' is " << strMax << std::endl;

	// Using the Box class template
	Box<int> intBox;
	intBox.setContent(123);

	Box<std::string> stringBox;
	stringBox.setContent("Hello, Templates!");

	std::cout << "The content of intBox is " << intBox.getContent() << std::endl;
	std::cout << "The content of stringBox is " << stringBox.getContent() << std::endl;

	return 0;
}
