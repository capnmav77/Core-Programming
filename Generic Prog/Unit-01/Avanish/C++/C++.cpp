// #include <type_traits>
#include <iostream>

template <typename TFirst, typename TSecond>
auto Average(TFirst x, TSecond y)
{
	return (x + y) / 2;
}

int main(void)
{
	int ret = Average(12, "hello");
	return 0;
}
