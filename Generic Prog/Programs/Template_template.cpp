/*
The simple_wrapper class is a very simple class template that holds a value of the type template parameter T. On the other hand, fancy_wrapper is a more complex wrapper implementation that hides the wrapped value and exposes member functions for data access. Next, we implement a class template called wrapping_pair that contains two values of a wrapping type. This can be either simpler_wrapper, fancy_wrapper, or anything else that is similar:
*/


template <typename T>
class simple_wrapper
{
	public:
		T value;
};

template <typename T>
class fancy_wrapper
{
	public:
	fancy_wrapper(T const v) :value(v)
	{
	}
	T const& get() const { return value; }
	template <typename U>
	U as() const
	{
		return static_cast<U>(value);
	}
	private:
		T value;
};

/*
The wrapping_pair class template has three parameters. The first two are type template parameters, named T and U. The third parameter is a template template parameter, called W, that has a default value, which is the fancy_wrapper type. We can use this class template as shown in the following snippet:
*/


template <typename T, typename U,
template<typename> typename W = fancy_wrapper>
class wrapping_pair
{
	public:
		wrapping_pair(T const a, U const b) :
	item1(a), item2(b)
	{
	}
	W<T> item1;
	W<U> item2;
};


wrapping_pair<int, double> p1(42, 42.0);
std::cout << p1.item1.get() << ' '
<< p1.item2.get() << '\n';
wrapping_pair<int, double, simple_wrapper> p2(42, 42.0);
std::cout << p2.item1.value << ' '
<< p2.item2.value << '\n';

/*
In this example, p1 is a wrapping_pair object that contains two values, an int and a double, each wrapped in a fancy_wrapper object. This is not explicitly specified but is the default value of the template template parameter. On the other hand, p2 is also a wrapping_pair object, also containing an int and a double, but these are wrapped by a simple_wrapper object, which is now specified explicitly in the template instantiation.
*/