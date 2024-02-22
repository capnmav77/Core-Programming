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
		value_type v{}; // [1] error
		// or
		base_parser<T>::value_type v{}; // [2] error
		std::cout << "parse\n";
	}
};