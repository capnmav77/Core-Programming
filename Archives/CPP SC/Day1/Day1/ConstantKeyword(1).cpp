#include <iostream>
using namespace std;
//global constant definition
const int PI=3.14;

//function to calculate area of circle
float circle(float radius)
{
    return PI*radius*radius;
}

//function to calculate area of cylinder
float cylinder(float radius,float height)
{
    return (2*PI*radius*height)+(2*PI*radius*radius);
}

//function to calculate area of cone
float cone(float radius)
{
    //local constant definition
    const int height=6;
    return PI*radius*(radius+(height*height)+(radius*radius));
}

//driver code
int main()
{
    float radius=4,height=5;
    cout<<"Area of circle: "<<circle(radius)<<"\n";
    cout<<"Area of cylinder: "<<cylinder(radius,height)<<"\n";
    cout<<"Area of cone: "<<cone(radius)<<"\n";
}
