// prog to define a namespace 

#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>

using namespace std;


namespace outer_ns
{
    //define the functions here 
    int arr[] = {12,2,34,4};
    int len =4;

    namespace inner_ns{
        //create a function here as well 
        void printer(int arr[] , int len){
            cout<<"inside the inner namespace";
            for(int i=0 ; i<len ; i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
    }

    void print_ints(){
        cout<<"inside the outer namespace";
        inner_ns::printer(arr,len);
    }

}


int main()
{
    //define the functions here 
    outer_ns::inner_ns::printer(outer_ns::arr,outer_ns::len); // the :: is the scope resolution operator which is used to access the members of a namespace
    //outer_ns::print_ints();
    return 0;
}