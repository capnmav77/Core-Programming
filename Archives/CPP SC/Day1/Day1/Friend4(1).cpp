#include<iostream>
using namespace std;
class space
{
    int x;
    int y;
    int z;
    public:
    void setdata (int a, int b, int c);
    void display(void);
     friend void operator- (space &s);
};
void space ::setdata (int a, int b, int c)
{
    x=a; y=b; z=c;
}
void space::display(void)
{
    cout<<x<<" "<<y<<" "<<z<<"\n";
}
void operator- (space &s)
{
    s.x =- s.x;
    s.y =- s.y;
    s.z =- s.z;
}
int main ()
{
    space s;
    s. setdata (5,2,9);
    cout<<"s:";
    s. display ();
    -s;
    cout<<"-s:";
    s. display ();
    return 0;
}