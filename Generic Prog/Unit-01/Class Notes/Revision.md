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
- 