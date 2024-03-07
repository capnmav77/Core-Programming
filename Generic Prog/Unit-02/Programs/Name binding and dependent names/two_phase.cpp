#include <iostream>

template <typename T>
struct base_parser
{
	void init() //non dependent name
	{
		std::cout << "init\n";
	}
};

template <typename T>
struct parser : base_parser<T>
{
	void parse()
	{
		base_parser<T>::init(); // error: identifier not found
		std::cout << "parse\n";
	}
};

int main()
{
	parser<int> p;
	p.parse();
}