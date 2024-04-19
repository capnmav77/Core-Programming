#include<stdarg.h>
#include <iostream>

int min(int count, ...)
{
	va_list args;
	va_start(args, count);
	int val = va_arg(args, int);
	std::cout << "\ncount is " << count << '\n';
	for (int i = 1; i < count; i++)
	{
		int n = va_arg(args, int);
		if (n < val)
			val = n;
	}
	va_end(args);
	return val;
}

int main()
{
	std::cout << "min(42, 7)=" << min(2, 42, 7) << '\n';
	std::cout << "min(1,5,3,-4,9)=" <<
	min(5, 1, 5, 3, -4, 9) << '\n';
}