// C++ program to demonstrate the working of friend class

#include <iostream>
using namespace std;

// forward declaration
class ClassB;

class ClassA 
{
    private:
        int numA;

        // friend class declaration
        friend class ClassB;

    public:
        // constructor to initialize numA to 12
        ClassA() : numA(12) {}
};

class ClassB 
{
    private:
        int numB;

    public:
        // constructor to initialize numB to 1
        ClassB() : numB(1) {}
    
    // member function to add numA from ClassA and numB from ClassB
    int add() {
        ClassA objectA;
        return objectA.numA + numB;
    }
};

int main() 
{
    ClassB objectB;
    int *ptr;
    char *ptr_1;

    int arr[]={1,2,3,4,5,6,7,8,9,10,11,12};

    long long *ptr_2;

    cout<<sizeof(ptr)<< " "<<sizeof(ptr_1)<<" "<<sizeof(arr)<<endl;
    
    cout << "Sum: " << objectB.add();
    return 0;
}