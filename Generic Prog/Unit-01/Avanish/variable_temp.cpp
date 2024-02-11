#include<iostream>


using namespace std;



// template<class T>
// constexpr T PI =T(3.14159265L);


struct math_constant{
    template<class T>
    static constexpr T PI = T(3.14159L);
};


template <typename T>
T sphere_volume(T const r)
{
    return 4 * math_constant::PI<T> * r *r *r /3; 
}


class tess{
    public:
        int a;
    tess(int k)
    {
        a=k;
    }
};


int main()
{
   
    //normal lambda
    const auto lambda =[](string x)
    {
        cout<<x<<endl;
    };

    //generic lambda 
    const auto geSolver =[](auto c)
    {
        cout<<c<<endl;
    };

   //template lambda only works for c++20
    const auto solver =[]<typename T>(T c){
        cout<<c<<endl;
    };

    solver("Hello");
}