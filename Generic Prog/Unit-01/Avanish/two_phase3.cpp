#include <iostream>
template <typename T>
struct base_parser
{
	void init()
	{
		std::cout << "init\n";
	}
};

template <>
struct base_parser<int>
{
	void init()
	{
		std::cout << "specialized init\n";
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



int main(void)
{
	parser<int> p1;
	p1.parse();
	// parser<double> p2;
	// p2.parse();
	return 0;
}
