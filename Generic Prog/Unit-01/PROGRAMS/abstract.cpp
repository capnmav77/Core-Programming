#include<bits/stdc++.h>

using namespace std;


class base{
    public:
        base(){
            cout<<"constructor base"<<endl;
        }
        // ~base(){
        //     cout<<"destructor base"<<endl;
        // }
        virtual ~base(){
            cout<<"destructor base"<<endl;
        }
};

class derived: public base{
    public:
        derived(){
            cout<<"constructor derived"<<endl;
        }
        ~derived(){
            cout<<"destructor derived"<<endl;
        }
};


int main()
{
    derived *d = new derived();
    base *b = d;
    delete b;
    getchar();
    return 0;
    //virtual function, binded at runtime
    return 0;
}