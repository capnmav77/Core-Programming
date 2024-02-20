### C++ Overview of datatypes and range of values :
- ![[Pasted image 20240220031021.png]]
### Operator types : 
- Arithmetic 
- assignment[=,+=,%=,/=]
- Relational operators [<,>,>=,== ,!=]
- Increment and decrement operators 
- Logical operators
- Bitwise operators [&,|,^,~,<<,>>]
- Decision making 
- Ternary operator[condition[x+y>7]?expr1:expr2;]
- Type conversion: Explicit - do it yourself , Implicit - automatic 
- Loops
- Arrays
- Pointers -> variables that store the address of another variable 
- the & operator - parameter passing by reference -> returns the memory address 
- Structure: user defined datatype
	- the structure members can be accessed through '.' operator
	- if we have a pointer to a structure -> operator is used
- Dynamic memory allocation: 
	- malloc (int size)
	- calloc (int nmembers, int size)
	- realloc (void * ptr , size t_size)
	- free(void * ptr)
- Linked List 
``` C++
	- An overview of C++ Generic Programming 01/02/2024 .Linked lists 
	- struct Node { int data; struct Node *next; }; 
	- struct Node { int data; struct Node *next; struct Node *prev; };
```
- BitFields
	- space optim of representation of data 
		- d-> 1,31 therefore unsigned int d:5;
- Union 
	- user def data structure like structure 
	- union is a user-defined data type that allows the storage of different data types in the same memory location
	- therefore only one member of union can be accessed at a given time and the size of a union is equal to it's largest member size . 
- Little Endian Big endian
	- Little and big endian are two ways of storing multibyte data-types ( int, float, etc). In little endian machines, last byte of binary representation of the multibyte data-type is stored first. On the other hand, in big endian machines, first byte of binary representation of the multibyte data-type is stored first.
	- ![[Pasted image 20240220035642.png]]
- Auto - default storage class 
- Extern - variable is defined elsewhere and not within the same code block 
- static - scope is local to the function to which they are defined
- register - class declares register vars that have the same functionality as that of auto . compiler tries to store these vars in the registers if they are available .
- Volatile - changing values of the variable .

### Environment variables 
- program [environ.c ]
	- extern char **environ

### Namespace 
- declarative region that provides a scope to the identifiers inside it.
- here ": :" is the scope resolution specifier that is used to access the members inside the namespace 
- check out namesp.cpp

### Class
- consists of :
	- access specifier 
	- data members 
	- member functions 
- #### Creating objects 
	- default constructor 
	- parameterized constructor 
	- parameterized constructor with single argument 
	
- #### Function Overloading 
	- Overloaded functions can have: 
		1. Different number of arguments 
		2. Different types of arguments 
		3. Different order of arguments
	- check out the scope resolution operator : scope resolution operator `::`
	- that just fucks you up if you don't understand it .
	
- #### Index Overloading 
	- we overload the '[]' operator in order to get the index we need .
	
- #### Inheritance 
	- check programs inheritance1 - inheritance4.cpp
	
- #### Lambda functions :
	- allows us to define anonymous function objects which can be used inline or passed as argument 
	- basic -> 
		- auto greet = []( )(the input variables ){
			  function body;
		  }
	- check lambda1 to lambda3 for overview 
	
- #### Inline functions:
	- avoid function call overhead by specifying the function as inline 
	- this makes the compiler substitute the content of inline function at the line of calling . 
	- checkout -> demoInline .
	
- #### Dynamic Memory Management 
- new - to allocate memory
	- it's adv over malloc is that it constructs object after allocating memory . 
- delete - to free memory 

- #### Constructors and Destructors :
	- check out prog-> showdestructor

- #### Initializer List
	- is used in initializing the datamembers of a class. 
	- the members to be initialized are seperated by comma and followed by a colon. The initialized class members are after the colon
	- initializer list is used when the member is a constant 
```cpp
class Test {
    const int t;
public:
    Test(int t):t(t) {} //Initializer list must be used
    int getT() { return t; }
};
```
```cpp
class Example {
private:
    int x;
    int y;
public:
    Example(int i, int j) : x(i), y(j) {
        // constructor body
    }
};
```
- #### Copy Constructor
	- 2 types 
	- deepcopy 
		- a deep copy creates a new object by copying data of another object along with the values of memory resources. In general, creating a copy of an object means creating an exact replica of the object having the same literal value, data type, and resources
	- shallowcopy
		- A shallow copy creates a new object by simply copying the data of all variables of the original object.
		- If some variables are dynamically allocated memory from the heap section, then the copied object variable will also reference the same memory location. This will create ambiguity and run-time errors, dangling pointer
	- check out the programs copyassignment and copyconstructor 1&2
- #### Inheritance types
	- ![[Pasted image 20240220055111.png]]
- #### Function overriding 
	- redefinition of a base class function with it's derived class with same signature . 
	- Runtime polymorphism 
	- ### Virtual Functions 
		- is a member function of a base class that we expect to override or redefine in our derived classs. 
		- in C++ what calling a virtual functions means is that; if we call a member function then it could cause a different function to be executed instead depending on what type of object invoked it. Because overriding from derived classes hasn’t happened yet, the virtual call mechanism is disallowed in constructors.
		- Usecase : 
			- Virtual functions allow us to create a list of base class pointers and call methods of any of the derived classes without even knowing the kind of derived class object. 
			- Runtime polymorphism is achieved only through a pointer (or reference) of the base class type. Also, a base class pointer can point to the objects of the base class as well as to the objects of the derived class. 
			- Late binding (Runtime) is done in accordance with the content of the pointer (i.e. location pointed to by pointer) and Early binding (Compile-time) is done according to the type of pointer
		- Rules for Virtual functions :
			1. Virtual functions cannot be static. 
			2. A virtual function can be a friend function of another class. 
			3. Virtual functions should be accessed using a pointer or reference of base class type to achieve runtime polymorphism.
			4. The prototype of virtual functions should be the same in the base as well as the derived class. 
			5. They are always defined in the base class and overridden in a derived class. It is not mandatory for the derived class to override (or re-define the virtual function), in that case, the base class version of the function is used. 
			6. A class may have a virtual destructor but it cannot have a virtual constructor.


	- #### move oper and Copy oper
		- deep copies -> costly 
		- move semantics -> take resources from one and pass it onto the object being moved .
		- Move semantics points the other object to the already existing object in the memory. It avoids the instantiation of unnecessary temporary copies of the objects by giving the resources of the already existing object to the new one and safely taking from the existing one. Taking resources from the old existing object is necessary to prevent more than one object from having the same resources.
		- r-value references and l-value references 
			- an l-value refers to a memory location that identifies an object, while an r-value refers to the data value that is stored at some address in memory. An l-value represents an object that occupies some identifiable location in memory, such as a variable. On the other hand, an r-value is a temporary or short-lived value that does not necessarily have a memory location.
			- For example, in the expression `int x = 10;`, `x` is an l-value because it represents a memory location, while `10` is an r-value because it is a temporary value without a specific memory location.
			- R-value references are denoted by `&&` and are used to extend the lifespan of temporary objects, allowing them to be bound to references and used beyond their initial scope. They are commonly used in move semantics and perfect forwarding.
			- A declaration of an rvalue reference looks like this: 
			- std::string&& rrstr; //C++11 rvalue reference variable 
			- The traditional reference variables of C++ e.g., std::string& ref; are now called lvalue references

## Need for templates : 
- Try generalizing quicksort ?
	- man it's flipping hard 
	- the most we could come up with was void pointers 
	- check quicksort with void pointers 
	- the main problem faced was using swap operation and comparision operation
	- we use void( * )(void * *, int const i , int const j); -> for swap 
	- we use bool(* )(void*,int const i , int const j  ) -> for compare func 
	- check quicksort prog for depth . 
- #### Advantages 
	- Templates help us avoid writing repetitive code. 
	- Templates foster the creation of generic libraries providing algorithms and types, such as the standard C++ library (sometimes incorrectly referred to as the STL), which can be used in many applications, regardless of their type. 
	- The use of templates can result in less and better code. For instance, using algorithms from the standard library can help write less code that is likely easier to understand and maintain and also probably more robust because of the effort put into the development and testing of these algorithms.

### Template Specialization
- it's a method to override a template defn in order to handle multiple input params
- The idea of template specialization is to override the default template implementation to handle a particular type in a different way.
- #### TYPES: 
	- Explicit specialization - when the template arguments are all manually provided by the user
	- Implicit specialization- when the template arguments are instantiated by the compiler 
	- Partial Specialization - only some template parameters are implemented.
- Template Instantion -> this happens by sub-ing the template arguments for template parameters 
	- Types : 
	  - implicit instantiation - compiler generates defn based on the use of templates and when no explicit instantiation is present 
	  - example :
``` cpp
		template<typename T> 
		struct foo
		{
			void f() {};
		};
		int main(){
			foo<int> x;
		}
		// here since the compiler encounters foo<int> x but do not use any of it's functions the compiler implicitly defines a specialization of foo for the int type 
		// therefore the above code is converted to : 
		template<> 
		struct foo<int>
		{
			Inline void f();
		};
```

#### NOTE: 
However, if we add one more function, g, with the following implementation that contains an error, we will get different behaviors with different compilers: 
```
template <typename T> 
struct foo { 
	void f() {} 
	void g() {int a = "42";}  // hehh string ? 
}; 
int main() { 
	foo<int> x; 
	x.f(); 
}
```
this body of g contains an error . this code compiles because some compilers ignore the part of the template that are not used , provided the code is syntactically correct but semantically wrong . 

#### Explicit instantiation - compiler generates defn based on the use of manual help provided 
![[Pasted image 20240220173335.png]]
![[Pasted image 20240220173629.png]]

##### One more example : 
![[Pasted image 20240220173718.png]]




- #### Static cast: 
	- is a compile time cast . implicit conversions between types (int - float , pointer - void* etc.)
	- can also call explicit conversion function.

- #### Types of templates:
	- **Type template parameters**, such as in template```<typename T>```where the parameter represents a type specified when the template is used. 
	- **Non-type template parameters**, such as in template```<size_t N>```or template```<auto n>```, where each parameter must have a structural type, which includes integral types, floating-point types (as for C++20), pointer types, enumeration types, lvalue reference types, and others (i.e., basic or derived data types) .
	- **Template template parameters**, such as in template
		- ```<typename K, typename V, template<typename> typename C >``` where the type of a parameter is another template. 

example :
``` cpp
#include <iostream>
using namespace std;
// Class template
template <typename T>

class Number {
   private:
    // Variable of type T
    T num;
   public:
    Number(T n) : num(n) {}   // constructor
    //why dont' we manually define the constructor?
    //because we are using a template class, so we don't know the type of the variable
    //so we can't define the constructor manually
    // what about num = n;?
    // num(n) is the same as num = n;
    T getNum() {
        return num;
    }
};
int main() {
    // create object with int type
    Number<int> numberInt(7);
    // create object with double type
    Number<double> numberDouble(7.7);
    cout << "int Number = " << numberInt.getNum() << endl;
    cout << "double Number = " << numberDouble.getNum() << endl;
    return 0;
}
```

- Basic Instinct: 
	- T-> class identifier that is used to define the type of value passed into the function . 
#### Function templates
	- 1. Generic Function:
```cpp
template<typename T>
T max(T a, T b) {
    return a > b ? a : b;
}

int main() {
    int x = 5, y = 10;
    double a = 3.14, b = 2.71;
    std::cout << max(x, y) << std::endl; // Output: 10
    std::cout << max(a, b) << std::endl; // Output: 3.14
    return 0;
}
```
- the above template is used to generically make the comparasions based on different types of data provided to it. 

#### Class Templates
- 2. Generic Classes : 
```cpp
template<typename T>
class Stack {
private:
    T* data;
    int size;
public:
    Stack(int size) {
        this->size = size;
        data = new T[size];
    }
    ~Stack() {
        delete[] data;
    }
    void push(T value) {
        data[size++] = value;
    }
    T pop() {
        return data[--size];
    }
};

int main() {
    Stack<int> intStack(10);
    intStack.push(5);
    intStack.push(10);
    std::cout << intStack.pop() << std::endl; // Output: 10

    Stack<double> doubleStack(10);
    doubleStack.push(3.14);
    doubleStack.push(2.71);
    std::cout << doubleStack.pop() << std::endl; // Output: 2.71
    return 0;
}

```
- In this example, the `Stack` class is a generic class that can work with different types of data. The `typename` keyword is used to specify that `T` is a type parameter. When the class is instantiated, the type of `T` is specified in angle brackets (`<>`).
#### Template specialization
- 3.Template Specialization: 
```cpp
template<typename T>
void print(T value) {
    std::cout << value << std::endl;
}

template<>
void print<std::string>(std::string value) {
    std::cout << "String: " << value << std::endl;
}

int main() {
    print(5); // Output: 5
    print("Hello"); // Output: String: Hello
    return 0;
}

```
- In this example, the `print` function is a generic function that can work with different types of data. However, the function is specialized for `std::string`, which means that a different implementation is used for `std::string` than for other types.

- 4. Template Metaprogramming 
``` cpp
template<int N>
struct Factorial {
    static const int value = N * Factorial<N - 1>::value;
};

template<>
struct Factorial<0> {
    static const int value = 1;
};

int main() {
    std::cout << Factorial<5>::value << std::endl; // Output: 120
    return 0;
}
```
- In this example, the `Factorial` struct is a template struct that calculates the factorial of a number at compile time. The `value` member is a static constant that is calculated recursively using template specialization.



### Function Templates 
```cpp
template <typename Input, typename Predicate> 
int count_if(Input start, Input end, Predicate p) { 
	int total = 0; 
	for (Input i = start; i != end; i++) {
		if (p(*i)) total++;
	} 
	return total; 
}
```
- Classes - default access specifier is private 
- Structure - default access specifier is public 

- #### Template class, Template functions 
	- eg : check slides 109 
	- when class is templatized : ```c.add<int>(41,42);```gives an error
	- when function is templatized but not the class  : ```c.add<int>(41,42);``` does not give an error

#### Template Parameter pack -> variadic template 
- discussed in unit - 2

