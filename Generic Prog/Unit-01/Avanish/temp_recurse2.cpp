template <typename T>
struct wrapper {};
template <int N>
struct manyfold_wrapper
{
	using value_type =
	wrapper<
	typename manyfold_wrapper<N - 1>::value_type>;
};

template <>
struct manyfold_wrapper<0>
{
	using value_type = unsigned int;
};
int main()
{
	std::cout <<
	typeid(manyfold_wrapper<0>::value_type).name() << '\n';
	std::cout <<
	typeid(manyfold_wrapper<1>::value_type).name() << '\n';
	std::cout <<
	typeid(manyfold_wrapper<2>::value_type).name() << '\n';
	std::cout <<
	typeid(manyfold_wrapper<3>::value_type).name() << '\n';
}