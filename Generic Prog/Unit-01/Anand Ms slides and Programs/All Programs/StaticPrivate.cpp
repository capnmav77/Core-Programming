#include <iostream>
using namespace std;
class MyClass{
   private:
      static int st_var;
   public:
      MyClass(){
         st_var++; //increase the value of st_var when new object is created
      }
      static int getStaticVar() {
         return st_var;
      }
};
int MyClass::st_var = 0; //initializing the static int
main() {
   MyClass ob1, ob2, ob3; //three objects are created
   cout << "Number of objects: " << MyClass::getStaticVar();
}