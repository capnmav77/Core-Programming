#include<iostream>
#include<bits/stdc++.h>


using namespace std;

// Constructor as private when it used
class Employee{
    int salary;

    public:
        int getSalary()
        {
            return salary;
        }

        void setSalary(int salary)
        {
            this->salary =  salary;
        }

        //default
        Employee()
        {
            salary  = 100;
        }

        //parameterised
        Employee(int salary)
        {
            this->salary  = salary ;
        }

        //Copy constructor
        Employee(const Employee& obj)
        {
            salary = obj.salary;
            cout<<"Here"<<endl;
        }

        ~Employee()
        {
            cout<<"Salary : "<<salary<<endl;
        }

};





// int  main(int argc, char **argv)
// {
//     // int a;
//     // string val = cin>>a;
//     // cout<<val<<endl;

//     Employee obj = Employee();
//     Employee obj1 = Employee(obj);
//     obj.setSalary(200);
// }   


class Example{
    public:
    int a;
    int *ptr;
    int b;
    Example(int x)
    {
       a=x;
    }
    // Example(Example &ob)
    // {
    //     cout<< "Copy Constructor"<<endl;
    //     a = ob.a;
    // }
    //Dynamic Constructpr
    Example (int n)
    {
        this->ptr = new int[n];
    }



    //Delegation Constructor (default constructor first)
    Example(int _b):Example()
    {
        b = _b;
    }

};
int main()
{
    Example e1(36);
    Example e2(e1); // deep copy
    Example e3(12);
    e3 = e2; //shallow copy
    cout<<e3.a<<endl;
    return 0;
}