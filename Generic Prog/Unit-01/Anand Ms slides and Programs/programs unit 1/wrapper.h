// wrapper.h
template <typename T>
struct wrapper
{
	T data;
};
extern template struct wrapper <int>; // [1] 
