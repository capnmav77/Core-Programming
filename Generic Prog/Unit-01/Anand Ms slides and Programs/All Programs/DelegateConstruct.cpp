#include <iostream>
using namespace std;
 
class TestClass {
    private:
        const int myVariable;
 
    public:
        /*This constructor will be called when no argument-
        is passed during the object creation. This constructor-
        to initialize 'myVariable' with default value is calling-
        the parameterized constructor in the initialization list.*/
        TestClass(): TestClass{5}{} // Delegate constructor call to the parameterized constructor where {} is the initialization list to initialize myVariable with 5
 
        /*This construtor will be indirectly called by the non-
        parametrized constructor or direclty when the argument-
        is specified at object creation.*/
        TestClass(int val) : myVariable(val){} // Parameterized constructor to initialize 'myVariable' with the value passed , {} is the initialization list
 
        void display() {
            cout << "Value of myVariable is: " << myVariable << endl;
        }
};
 
int main() {
    TestClass object1;
    object1.display();
    
    TestClass object2(12);
    object2.display();
    return 0;
}