#include<iostream>
#include<typeinfo>
using namespace std;

namespace outer_ns{
    int arr[] ={1,2,3,4,5};

    int len=5;

    namespace inner_ns{
            void printer(int arr[],int len)
            {
                for(int i= 0; i<len;i++)
                {
                    cout<<arr[i]<<" ";
                }
                cout<<endl;
            }
    }

    void print_arr()
    {
        inner_ns::printer(arr,len);
    }
}

int function1()
{
    return 2;
}


int main()
{
    int num[] = {10,20,30};
    outer_ns::inner_ns::printer(num,3);
    outer_ns::print_arr();


    auto greet = [](){
        //body
    };

    auto a =20;
    auto b=120.0;

    cout<<"A = "<<typeid(greet).name()<<endl;
    cout<<"B = "<<typeid(num).name()<<endl;

    decltype(function1()) x;

}