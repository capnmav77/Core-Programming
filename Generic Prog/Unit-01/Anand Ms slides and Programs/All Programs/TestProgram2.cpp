#include<iostream>
#include<string>
using namespace std;
class Box
{
int capacity;
bool operator<(Box b)
{
return this->capacity < b.capacity ? true : false;
}
public:
Box(){}
Box(double capacity){
this->capacity = capacity;
}
};
int main(int argc, char const *argv[]) {
Box b1(10);
Box b2 = Box(14);
if(b1 < b2)
{
cout<<"Box 2 has large capacity.";
}
else
{
cout<<"Box 1 has large capacity.";
}
return 0;
}