#include <iostream>

template <typename T>
class List
{

  public:
	List<T>(T const &content)
	{
		// etc...
	}

	List<T>(List<T> const &list)
	{
		// etc...
	}

	~List<T>(void)
	{
		// etc...
	}

	// etc...

  private:
	T *_content; // it works the same without *
	List<T> *_next;
};

/*******************************************************/

int main(void)
{
	List<int> a(42);
	List<float> b(3.14f);
	List<List<int>> c(a); // A list of list of integers

	// etc...

	return 0;
}