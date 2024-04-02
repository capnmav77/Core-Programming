#include <iostream>
using namespace std;

class Box {
   double width; // private member

public:
   double length; // public member
   // Declaration of a friend function
   friend void printWidth(Box box);

   void setWidth(double wid) {
      width = wid;
   }
};

// Definition of the friend function
void printWidth(Box box) {
   // Because printWidth() is a friend of Box, it can directly access any member of this class
   cout << "Width of box : " << box.width << endl;
}

int main() {
   Box box;

   // Set box width without using a member function
   box.setWidth(10.0);

   // Use friend function to print the width
   printWidth(box);

   return 0;
}
