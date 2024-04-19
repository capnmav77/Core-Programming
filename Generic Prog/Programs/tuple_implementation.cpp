template <typename T, typename... Ts>
// This is the primary template
struct tuple
{
	tuple(T const& t, Ts const &... ts)
		: value(t), rest(ts...)
	{
	}
	constexpr int size() const { return 1 + rest.size(); }
	T value;
	tuple<Ts...> rest;
};

// The partial specialization
template <typename T>
struct tuple<T>
{
	tuple(const T& t) : value(t)
	{
	}
	constexpr int size() const { return 1; }
		T value;
};