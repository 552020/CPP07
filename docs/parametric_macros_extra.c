#include <stdio.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main()
{
	int x = 5, y = 10;
	int result;

	// Normal use of MAX
	result = MAX(x, y);
	printf("The maximum of %d and %d is %d\n", x, y, result);

	// Reset x and y
	x = 5;
	y = 10;

	// Using MAX with side effects
	result = MAX(x++, y++);
	printf("After increment, x = %d, y = %d\n", x, y);
	printf("The maximum (with increments) is %d\n", result);
	printf("The maximum (with increments) is %d\n", result);

	return 0;
}
