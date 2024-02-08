#include <stdio.h>

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




int main (int argc, char **argv)
{
    printf ("Size of struct abc1 is %d\n", sizeof (struct abc1));
    printf ("Size of struct abc2 is %d\n", sizeof (struct abc2));
    printf ("Size of struct abc3 is %d\n", sizeof (struct abc3));
    printf ("Size of struct abc4 is %d\n", sizeof (struct abc4));
    printf ("Size of struct abc5 is %d\n", sizeof (struct abc5));
    printf ("Size of struct abc6 is %d\n", sizeof (struct abc6));

}
