#include <iostream>
struct dictionary_traits
{
	using key_type = int;
	using map_type = std::map<key_type, std::string>;
	static constexpr int identity = 1;
};
template <typename T>
struct dictionary : T::map_type // [1]
{
	int start_key { T::identity }; // [2]
	typename T::key_type next_key; // [3]
};
int main(void)
{
	dictionary<dictionary_traits> d;
	return 0;
}