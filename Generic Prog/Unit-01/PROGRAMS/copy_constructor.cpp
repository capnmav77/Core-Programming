#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<algorithm>
#include<cmath>
#include<cstdio>

using namespace std;

class Employee{

    private: 
        string name;
        int age;
        
        void display(){
            cout<<"Name of the current object: "<<name<<endl;
            cout<<"Age of the current object: "<<age<<endl;
            cout<<endl;
        }
    
    public:
        Employee(string name, int age){
            this->name = name;
            this->age = age;
        }
        //void display();
};


int main()
{
    Employee e1("Rahul", 20);
    e1.display();
    Employee e2 = e1;
    e2.display();
    return 0;
}