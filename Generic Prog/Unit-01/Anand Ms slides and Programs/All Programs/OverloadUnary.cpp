#include<iostream>
using namespace std;

class UnaryOverload
{
        int hr, min;
     public:
        void in()
        {
                cout<<"\n Enter the time: \n";
                cin>>hr;
                cout<<endl;
                cin>>min;
        }
        void operator++(int) //Overload Unary Increment
        {
                hr++;
                min++;
        }
        void operator--(int) //Overload Unary Decrement
        {
                hr--;
                min--;
        }
        
        void out()
        {
                cout<<"\nTime is "<<hr<<"hr "<<min<<"min";
               
        }
};
int main()
{
        UnaryOverload ob;
        ob.in();
        ob++;
        cout<<"\n\n After Incrementing : ";
        ob.out();
        ob--;
        ob--;
        cout<<"\n\n After Decrementing : ";
        ob.out();
        return 0;
}