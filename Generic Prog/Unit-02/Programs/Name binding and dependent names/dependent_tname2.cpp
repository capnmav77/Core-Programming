#include <iostream>

template <typename T>
struct base_parser
{
	template <typename U>
	struct token {};
};

template <typename T>
struct parser : base_parser<T>
{
	void parse()
	{
		using token_type =
		typename base_parser<T>::template token<int>; // [1] // adding the typename to this line makes the compiler understand that token is a type and not a value
		token_type t1{};
		typename base_parser<T>::template token<int> t2{}; 
		// base_parser<T>::template token<int> t3{}; // [2]  this is an error because the compiler does not know that token is a type and not a value
		// here template is used to tell the compiler that token is a type and not a value ? 
		// explain why template is used here = to tell the compiler that token is a type and not a value
		// 
// [2]
		std::cout << "parse\n";
	}
};