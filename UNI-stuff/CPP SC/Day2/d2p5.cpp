/*Performance: Initialization lists are more efficient than initialization in the constructor body. This is because members are initialized directly using the list, while in the constructor body, they would be default-initialized first, then reassigned.

Initializes const members: const data members 
and references must be initialized using an initialization list. They can't be initialized inside the body of the constructor because they are const and thus can't be changed after default initialization.

Initializes member objects that don't have a default constructor: If your class has a member object that doesn't have a default constructor (a constructor with no parameters), you must initialize that object in the initialization list.

Initializes base class constructor: If you're deriving from a base class and the base class has a constructor that takes parameters, you must call that constructor in the initialization list. */

#include <string>

class ExampleBase {
public:
    ExampleBase(int x) : x_(x) {}
private:
    int x_;
};

class ExampleDerived : public ExampleBase {
public:
    ExampleDerived(int x, double y, const std::string& name)
        : ExampleBase(x), // Base class constructor
          y_(y),          // Member without default constructor
          name_(name) {}  // const member
private:
    double y_;
    const std::string name_;
};
