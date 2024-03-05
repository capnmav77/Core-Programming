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

### Namespace ****
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





- ## Variadic templates
	- they are class or function templates that allow arbitrary number of arguments to be passed . they provide type safety and flexibility
	-  enable defining data structures with variable number of arguments . 
	- they are implemented recursively and it happens using parameter pack expansion
	- there is always a base case to be called because it cannot handle the base case 
	- As a result, min(1, 5, 3, -4, 9) expands to min(1, min(5, min(3, min(-4, 9)))).
	- but there is no function being called as it is subbed in inline . 
- ## Parameter packs
	- they accept zero , one or more parameters 
	- number of args can be retrieved using sizeof oper , which can be later on used similarly in the below case :
	- ![[Pasted image 20240228210316.png]]
	- the semantically equivalent program would be to keep a base case that overrides the one at the end in order to skip the usage of sizeof operator . 
	- ![[Pasted image 20240228210503.png]]
		- Notice 
			- sizeof...(args) -> the function parameter pack  == sizeof...(Args) -> the template parameter pack . 
		- the function that takes parameter pack as input can be specified to take sets of elements => <int , int, int , ...> 
		- ![[Pasted image 20240228211654.png]]
		- however when the types are different args1 will pack 1 ,2 and args2 will contain double .
		- however when asserting like -> same size etc. then things change 
		- ![[Pasted image 20240228212020.png]]
	- multiple parameter packs are not specific to variadic function templates . they can be used for variadic class templates
		- for passing functions as parameters we need
			- a type template parameter for the return type of the funciton 
			- a template parameter pack for the parameter types of the function 
			- ![[Pasted image 20240228220401.png]]
			- where typename R1 is used for specification of the return type of function 1 
			- the typename parameter pack is used to specify the parameter types for function 1
			- similar concepts apply for function 2 
			- in order to call these functions : 
				  func_pair<bool(int, int), bool(int, int)> myPair;
				  modify the template argument list in order to checkout multiple ways 

		- ## Template parameter pack 
			- a template param pack is template parameter that represents any number of template parameters . 
		- types of template parameter packs
			- type 
				- zero or more type template parameters 
				- ![[Pasted image 20240228222239.png]]
			- nontype
				- it represents the actual rvalues given to the functions 
				- ![[Pasted image 20240228222307.png]]
			- template template parameter packs
				- in cases where the template parameters types can deduced  -> function , class template etc. leave it 
				- template parameter pack should be the last template parameter that is supposed to be init 
				- ![[Pasted image 20240228222430.png]]
				- default args can't be used for template parameter packs . 
	- ## Function parameter pack 
		- the template argument list can be modified in order to pass the parameters as groups 
```
		- #include <cassert>

#include <iostream>

  
  

// an assertion is a statement used to state or assert that the expression

// must be true

template<class...A, class...B>

void func(A...arg1,int sz1, int sz2, B...arg2)  

{

   assert( sizeof...(arg1) == sz1);

   assert( sizeof...(arg2) == sz2);

}

  

int main(void)

{

   //A:(int, int, int), B:(int, int, int, int, int)

   func<int,int>(1,2,2,6,5,1,2,3,4,5); // here we are using the < > in order to specify the grouping of parameters

  

   //A: empty, B:(int, int, int, int, int)

   func(0,5,1,2,3,4,5);

   return 0;

}
```

- Default arguments can't be used for template parameter pack 
	- ![[Pasted image 20240228223413.png]]
- 
  
  ## Pack expansion contexts 
	- expression list expansion
		- the pack expansion args can be placed anywhere and the rest is computed 
```
		- #include <cstdio>

#include <cassert>

  

template<class...A> void func1(A...arg)

{

    assert(false);// assert is used to

}

  

void func1(int a1, int a2, int a3, int a4, int a5, int a6)

{

    printf("call with(%d,%d,%d,%d,%d,%d)\n",a1,a2,a3,a4,a5,a6);

}

  

template<class...A>

int func(A...args)

{

    int size = sizeof...(A);

    switch(size){

        case 0: func1(99,99,99,99,99,99);

        break;

        case 1: func1(99,99,args...,99,99,99);

        break;

        case 2: func1(99,99,args...,99,99);

        break;

        case 3: func1(args...,99,99,99);

        break;

        case 4: func1(99,args...,99);

        break;

        case 5: func1(99,args...);

        break;

        case 6: func1(args...);

        break;

        default:

        func1(0,0,0,0,0,0);

    }

    return size;

}

  

int main(void)

{

    func();

    func(1);

    func(1,2);

    func(1,2,3);

    func(1,2,3,4);

    func(1,2,3,4,5);

    func(1,2,3,4,5,6);

    func(1,2,3,4,5,6,7);

    return 0;

}
```


- Initializer List 
	- pack expansion args -> is in the initializer list 
```
	- #include <iostream>

using namespace std;

  

void printarray(int arg[], int length)

{

    for(int n=0; n<length; n++)

    {

        printf("%d ",arg[n]);

    }

    printf("\n");

}

  

template<class...A> void func(A...args)

{

    const int size = sizeof...(args) +5;

    printf("size %d\n", size);

    int res[sizeof...(args)+5]={99,98,args...,97,96,95};

    printarray(res,size);

}

  

int main(void)

{

    func();

    func(1);

    func(1,2);

    func(1,2,3);

    func(1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20);

    return 0;

}
```

the initalizer list is used to initialize a list /array and add the corresponding elements to it . 


- BASE SPECIFIER LIST 
	- the pack expansion is used to expand other possible structures in order to use them in the correspondingparameter packing 
```
	- #include <iostream>

using namespace std;

  

struct a1{};

struct a2{};

struct a3{};

struct a4{};

  

template<class X> struct baseC{

    baseC() {printf("baseC primary ctor\n");}

};

template<> struct baseC<a1>{

    baseC() {printf("baseC a1 ctor\n");}

};

template<> struct baseC<a2>{

    baseC() {printf("baseC a2 ctor\n");}

};

template<> struct baseC<a3>{

    baseC() {printf("baseC a3 ctor\n");}

};

template<> struct baseC<a4>{

    baseC() {printf("baseC a4 ctor\n");}

};

  

template<class...A>

struct container : public baseC<A>...{

    container(){

        printf("container ctor\n");

    }

};

  

int main(void){

    container<a1,a2,a3,a4> test;

    return 0;

}
```
- Member initializer list 
	- the constructor init is expanded to include the call for each base class 
```
	- #include <iostream>

using namespace std;

  

void printarray(int arg[], int length)

{

    for(int n=0; n<length; n++)

    {

        printf("%d ",arg[n]);

    }

    printf("\n");

}

  

template<class...A> void func(A...args)

{

    const int size = sizeof...(args) +5;

    printf("size %d\n", size);

    int res[sizeof...(args)+5]={99,98,args...,97,96,95};

    printarray(res,size);

}

  

int main(void)

{

    func();

    func(1);

    func(1,2);

    func(1,2,3);

    func(1,2,3,4,5,6,7,8,9,(int)10.00,11,12,13,14,15,16,17,18,19,20);

    return 0;

}
```

## Partial specialization 
- ![[Pasted image 20240228231906.png]]
	- when the class template is instantiated with list of args. the partial specialization is matched in all cases where there are 1 or more elems. in that case template parameter B holds the first parameter and pack exp C contains the rest of the argument . 
- Parameter expansion 
	- is the process of expansion of the variadic templates by calling it recursively in order to process one argument at a time 
- Partial specialization 
	- it is used to access a specific part of a variadic templates 
		- ![[Pasted image 20240229010829.png]]
		- accessing the elements using .rest.value is cumbersome 
	- We use fold operation
		- IT'S A WAY OF REDUCING THE OPERATIONS OVER A BINARY PACK 
		- provide a easy way to apply a binary operator to a pack . instead of doing a recursive call . 
		- - **Syntax**: The syntax for a fold expression is `(pack op ...)` or `(init op ... op pack)` where `op` is a binary operator and `pack` is the parameter pack being expanded.
		- **Types of Folds**:
		    
		    - **Left Fold (`(pack op ...)`)**: The binary operator is applied between the elements in the parameter pack from left to right.
		    - **Right Fold (`(... op pack)`)**: The binary operator is applied from right to left.
		    
		- **Example**:
		    
		    - In your code, `return (a + ... + args);` represents a left fold where the `+` operator is applied between `a` and each element in `args` from left to right.
		    - This expression effectively sums up all the arguments passed to the function `foo`.
		- eg: 
			- EARLIER 
			- ![[Pasted image 20240229013728.png]]
			- NOW : 
```
	TEMPLATE<typename T> 
	int sum(T... args){
		return (... + args); lfold
	}
```


- ## Name binding 
	- The term name binding refers to the process of finding the declaration of each name that is used within a template. There are two kinds of names used within a template: dependent names and non-dependent names
	- Dependent Names:
		Dependent names are bound at the point of template instantiation, not at the point of template definition.
		They depend on template parameters, so their meaning can change depending on the template arguments.
		Examples of dependent names include function calls with a dependent function name, and names from scopes that are visible inside the template's definition.
	- Non-Dependent Names:
		Non-dependent names are bound at the point of template definition and stay bound in every instantiation of that template.
		They do not depend on template parameters, so their meaning does not change with template arguments.
		Examples of non-dependent names include the name of the template and names declared in the template
	- name lookup is performed differently 
		- for dependent - point of template instantiation 
		- for non-dependent - point of template defn
	- 
	  
	  
	  
	  - DECLTYPE 
		  - ![[Pasted image 20240229030454.png]]
		  - .In summary, decltype is a type specifier used to deduce the type of an expression. It can be used in different contexts, but its purpose is for templates to determine the return type of a function and to ensure the perfect forwarding of it.
	- Declval type operator
		- it add's a rvalue reference to type template argument . 
		- ![[Pasted image 20240229030733.png]]
```
#include <utility> // std::declval
#include <iostream> // std::cout

struct A {
 virtual int value() = 0;
};

class B : public A {
 int val_;
public:
 B(int i, int j) : val_(i * j) {}
 int value() { return val_; }
};

int main() {
 decltype(std::declval<A>().value()) a; // int a
 decltype(std::declval<B>().value()) b; // int b
 decltype(B(0, 0).value()) c; // same as above (known constructor)

 a = b = B(10, 2).value();
 std::cout << a << '\n';

 return 0;
}

```

### Friendfunction
-  A friend function in C++ is a special type of function that has the ability to access private and protected members of a class, even though it is not a member of that class itself. This is achieved by declaring the function as a friend within the class definition. Friend functions are useful in scenarios where you need to perform operations on a class's private or protected members without making those members public or by creating a member function.

### Declaration and Use
```
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

```

despite not being the member of the box class , the friend function can access the private vars of the box  -> width 

```
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

```

