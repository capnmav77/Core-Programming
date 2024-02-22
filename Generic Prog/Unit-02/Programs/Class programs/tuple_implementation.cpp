#include<iostream>
#include<bits/stdc++.h>
// using namespace std;


template< typename T, typename... Ts>
struct tuple{
    tuple(T const &t , Ts const &... ts):value(t),rest(ts...) //pack expansion
    {}
    constexpr int size() const {return 1 + rest.size();}
    T value;
    tuple<Ts...> rest;
};

// the partial specialization to end the recursion
template<typename T>
struct tuple<T>{
    tuple(T const &t):value(t)
    {}
    constexpr int size() const {return 1;}
    T value;
};

// for the nth_type -> we find the type of the nth element in the tuple
template <size_t N, typename T , typename... Ts> //pack expansion
struct nth_type : nth_type<N-1,Ts...> //recursive class template where the first parameter is decremented by 1
{
    static_assert(N < sizeof...(Ts)+1, "index out of range");
};

template <typename T, typename... Ts>
struct nth_type<0,T,Ts...>
{
    using value_type = T;
};


// for finding the value of the nth_type 
template <size_t N>
struct getter
{
    template<typename... Ts>
    static typename nth_type<N,Ts...>::value_type& get(tuple<Ts...>& t) //pack expansion.
    {
        return getter<N-1>::get(t.rest);
    }
};

template<>
struct getter<0> 
{
    template<typename T, typename... Ts> 
    static T& get(tuple<T, Ts...> &t)
    {
        return t.value;
    }
};


int main()
{
    tuple<int ,double , char> t(1,2.3,'a');
    std::cout<<getter<2>::get(t)<<std::endl;

    return 0;
}