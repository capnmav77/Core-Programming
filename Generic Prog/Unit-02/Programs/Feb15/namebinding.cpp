#include<iostream>

template <typename T>
struct parser; // [1] template declaration
void handle(double value) // [2] handle(double) definition //non dependent name 
{
	std::cout << "processing a double: " << value << '\n';
}
template <typename T>
struct parser // [3] template definition //dependent name therefore 
{
	void parse()
	{
		handle(42); // [4] non-dependent name
	}
};
void handle(int value) // [5] handle(int) definition //non dependent name 
{
	std::cout << "processing an int: " << value << '\n';
}

int main()
{
	parser<int> p; // [6] template instantiation
	p.parse();
}