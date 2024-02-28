#include<iostream>


template< typename T,typename... Ts>
struct tuple{
    tuple(T const &t, Ts const &...ts):value(t),rest(ts...)
    {}

    constexpr int size() const {return 1+rest.size();};
    T value;
    tuple<Ts...> rest;

};


template<typename T>
struct tuple<T>{
    tuple(const T&t):value(t)
    {}

    constexpr int size() const {return 1;}
    T value;
};

template<size_t N,typename T, typename...Ts>
struct nth_type : nth_type<N-1,Ts...>
{
    static_assert(N < sizeof...(Ts)+1,"Index out of bounds");

};

template<typename T, typename...Ts>
struct nth_type<0,T,Ts...>
{
    using value_type = T;
};



template<size_t N>
struct getter
{
    template <typename...Ts>
    static typename nth_type<N,Ts...>::value_type & get(tuple<Ts...>&t)
    {
        return getter<N-1>::get(t.rest);
    }
};


template<>
struct getter<0>
{
    template <typename T,typename...Ts>
    static T& get(tuple<T, Ts...>&t)
    {
        return t.value;
    }
};


template<size_t N, typename...Ts>
typename nth_type<N,Ts...>::value_type &get(tuple<Ts...>&t)
{
    return getter<N>::get(t);
};




int main()
{
    tuple<int,double,int,char,char,float> t(1,2.33,30,';','a',22.54);
    std::cout<<get<5>(t)<<std::endl;
}