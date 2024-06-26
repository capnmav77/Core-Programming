#include <iostream>
template <typename T>
struct base_parser
{
	void init()
	{
		std::cout << "init\n";
	}
};

template <typename T>
struct parser : base_parser<T>
{
	void parse()
	{
		this->init();
		std::cout << "parse\n";
	}
};

int main()
{
	parser<int> p;
	p.parse();
}