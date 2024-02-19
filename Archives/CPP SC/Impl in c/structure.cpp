#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
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

bool random_bool(){
    if(rand()%2==0){
        return 0;
    }
    else{
        return 1;
    }
}


class Student{
    public:
        string name;
        int age;
        int gender;
        void getter(){
            name = random_string(10);
            age = random_number(10,25);
            gender = random_bool();
        }

        void display(){
            cout << name << "\t" << age << "\t"<< gender << "\n";
        }
    private:
        float cgpa;
        int semester;
};


int main(){
    vector<Student> Class;
    Student s1;

    for(int i =0;i<10;i++){
        s1.getter();
        Class.push_back(s1);
    }

    for(int i=0;i<10;i++){
        Class[i].display();
    }
    return 0;
}