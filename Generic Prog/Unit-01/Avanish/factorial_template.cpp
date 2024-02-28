#include <iostream>

template <unsigned int N>
struct factorial
{
	static constexpr unsigned int value =
	N * factorial<N - 1>::value;
};
template <>
struct factorial<0>
{
	static constexpr unsigned int value = 1;
};

int main()
{
	std::cout << factorial<4>::value << '\n';
}