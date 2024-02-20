#include <iostream>

template <typename T>
struct base_parser
{
	template <typename U> void init()
	{
		std::cout << "init\n";
	}
};

template <typename T>
struct parser : base_parser<T>
{
	void parse()
	{
		//base_parser<T>::init<int>(); // [1] error
		base_parser<T>::template init<int>(); // [2] OK
		std::cout << "parse\n";
	}
};