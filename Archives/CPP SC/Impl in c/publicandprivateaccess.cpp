#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<math.h>
using namespace std;

string random_string(int len){
    string str;
    for(int i=0;i<len;i++){
        char ch = 'A'+ rand() %26;
        str.push_back(ch); 
    }
    return str; 
}

int random_number(int start, int range){
    return (start+ rand()%range);
}

class salary{
    private:
        string name;
        int salary;
    public:
        void setsalary(){
            salary = random_number(10000,100000);
        }
        void set_name(){
            name = random_string(10);
        }
        void display(){
            cout<<name<<"\t"<<salary<<endl;
        }
};

int main()
{
    salary s1;
    s1.set_name();
    s1.setsalary();
    s1.display();
    return 0;
}
