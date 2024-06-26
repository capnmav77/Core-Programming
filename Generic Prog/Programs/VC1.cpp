template <size_t N> 
struct getter 
{ 
	template <typename... Ts> 
	static typename nth_type<N, Ts...>::value_type& 
	get(tuple<Ts...>& t) 
	{ 
		return getter<N - 1>::get(t.rest);
	} 
}; 
template <> 
struct getter<0> 
{ 
	template <typename T, typename... Ts> 
	static T& get(tuple<T, Ts...>& t) 
	{ 
		return t.value; 
	} 
}; 
