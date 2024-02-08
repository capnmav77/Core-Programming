#include <iostream>

using namespace std;

struct abc1
{
    char c1;
    char c2;
    int i1;
};


struct abc2
{
    char c1;
    int i1;
    char c2;
};

struct abc3
{
    int i1;
    char c1;
    char c2;
};

struct abc4
{

    short s1;
    int i1;
};

struct abc5
{

    short s1;
    long l1;
};

struct abc6
{
    char c1;
    char c2;
    short i1;
};




int main ()
{
    cout << "Size of struct abc1 is " << sizeof (struct abc1) << endl;
    cout << "Size of struct abc2 is " << sizeof (struct abc2) << endl;
    cout << "Size of struct abc3 is " << sizeof (struct abc3) << endl;
    cout << "Size of struct abc4 is " << sizeof (struct abc4) << endl;
    cout << "Size of struct abc5 is " << sizeof (struct abc5) << endl;
    cout << "Size of struct abc6 is " << sizeof (struct abc6) << endl;
    return 0;

}
