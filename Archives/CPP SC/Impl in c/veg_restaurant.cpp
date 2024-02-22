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

class restaurant{
    private:
        string name;
        vector<string> menu;
    public:
        string address;
        void add_menu(int n);
        void restaurant_name(string restname){
            name = restname;
        }
        void getter(){
            address = random_string(20);
        }

        void display(){
            cout << name << "\t" << menu[0] << "\t"<< address << "\n";
        }
};

void restaurant::add_menu(int n){
    for(int i=0;i<n;i++){
        string menuitem = random_string(10);
        menu.push_back(menuitem);
    }
    
}

class rating : public restaurant{
    private:
        int Ratin;
    public: 
        //constructor of the child class
        rating(int stars) {Ratin = stars; }
};


int main()
{
    vector<restaurant> Rest;
    restaurant r1;
    for(int i= 0;i<10;i++){
        r1 name = 
    }
    return 0;
}