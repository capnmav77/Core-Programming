#include <iostream>

template <typename T>
struct base_parser
{
	using value_type = T;
};

template <typename T>
struct parser : base_parser<T>
{
	void parse()
	{
		typename base_parser<T>::value_type v{}; // 			[3] OK bbecause we have used typename before the dependent name base_parser<T>::value_type
		// what is value_type here?
		// value_type v{}; // 			[1] error because value_type is a dependent name and it's not clear that it is a type or a value therefore we use typename before it
		// therefore we use typename before it 
		// or
		// base_parser<T>::value_type v{}; // 			[2] error because base_parser<T> is a dependent name and it's not clear that it is a type or a value therefore we use typename before it
		std::cout << "parse\n";
	}
};


/*
template <typename T>
struct parser : base_parser<T>
{
	void parse()
	{
		value_type v{}; // [1] error
		// or
		base_parser<T>::value_type v{}; // [2] error
		value_type v{}; // [3] OK
		std::cout << "parse\n";
	}
};
*/