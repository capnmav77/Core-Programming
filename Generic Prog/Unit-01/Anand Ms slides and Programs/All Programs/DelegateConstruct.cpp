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
        TestClass(): TestClass{5} {}
 
        /*This construtor will be indirectly called by the non-
        parametrized constructor or direclty when the argument-
        is specified at object creation.*/
        TestClass(int val) : myVariable{val} {}
 
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