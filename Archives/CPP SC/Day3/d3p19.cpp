#include <iostream>
#include <cstdlib>
using namespace std;

class Foo {
  int x;
public:
  Foo(int x) : x(x) {} // constructor
  void display() { // display the value of x
    cout << "x = " << x << endl;
  }
  static void* operator new(size_t size) { // overload new operator
    cout << "Overloading new operator with size: " << size << endl;
    void* ptr = malloc(size); // allocate memory using malloc
    if (!ptr) { // check if allocation succeeded
      bad_alloc ba; // create a bad_alloc object
      throw ba; // throw it as exception
    }
    return ptr; // return the pointer
  }
  static void operator delete(void* ptr) { // overload delete operator
    cout << "Overloading delete operator" << endl;
    free(ptr); // deallocate memory using free
  }
};

int main() {
  Foo* f = new Foo(5); // create a Foo object using new
  f->display(); // display its value
  delete f; // delete it using delete
}
