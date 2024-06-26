template <typename T> 
struct foo 
{
	protected: 
		using value_type = T; 
}; 
template <typename T, typename U = typename T::value_type> 
struct bar 
{ 
	using value_type = U; 
}; 
bar<foo<int>> x;
