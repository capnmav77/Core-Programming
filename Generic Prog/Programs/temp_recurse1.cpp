template<>
struct factorial<4>
{
	inline static constexpr const unsigned int value =
		4U * factorial<3>::value;
};

template<>
struct factorial<3>
{
	inline static constexpr const unsigned int value =
		3U * factorial<2>::value;
};

template<>
struct factorial<2>
{
	inline static constexpr const unsigned int value =
		2U * factorial<1>::value;
};

template<>
struct factorial<1>
{
	inline static constexpr const unsigned int value =
		1U * factorial<0>::value;
};

template<>
struct factorial<0>
{
	inline static constexpr const unsigned int value = 1;
};