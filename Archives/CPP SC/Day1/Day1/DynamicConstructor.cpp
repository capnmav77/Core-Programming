#include <iostream>
using namespace std;
class ABC
{
    int *value;
public:
    ABC()//Default constructor
    {
        value = new int; //Memory allocation at run time
        *value = 1729;
    }
    ABC(int p_value) //Parameterised constructor
    {
        value = new int; //Memory allocation at run time
        *value= p_value+1;
    }
    void display()
    {
        cout<< *value <<endl;
    }
    ~ABC()
    {
        delete value ;
    }
};

int main()
{
    ABC obj1, obj2(7225);
    cout<<"The value of object obj1 is: ";
    obj1.display();// Calling default constructor
    cout<<"\nThe value of object 0bj2 is: ";
    obj2.display();// calling parameterised constructor
    return 0;
}
