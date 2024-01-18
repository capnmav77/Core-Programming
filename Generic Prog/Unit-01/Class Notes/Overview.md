Structure in CPP 
    can have member functions 
    all strucutre members are public 
    no access specifiers 

Classes in CPP 
    access members through public get and set methods 

Constructors and Destructors 
    Constructors - are used to create and prepare an object for use , it can init a object using parameters passed to it . 
    - types of constructors 
        - parameterized 
        - default 
        - copy - takes a refrence from the same constructor 

INitializers - if we have multiple variables we need to initialize , but we need to initialize certain vars only , then we use Initializer List 

Operator Overloading - changing the meaning of a operator using compile time polymorphism in order to make it do our specific requirements 

Type Converter - converts a primitive datatype to another primitive datatype 
    - typecasting 
        - int - float 

Virtual Function -  are functions that are expected to be overridden 
    allow to create a list of base class pointers and call methods without even knowing the return type of the functions 

Abstract Class 
    are functions meant to be overridden 
    they have atleast one pure virtual function 

Multiple Inheritance 
    a feature in cpp where a class can inherit features or functions from more than one parent classes.
    for example in problem MI3.cpp -> forms a diamond problem where the class d derives functions from class a , from both class b and c , causing multiple copies of a . 

    in order to solve that problem we use virtual function -> i.e a's function is made virtual -> therefore d get's a single copy of a 

Exception Handling : 
    smart pointer 
    it consists of a constructor , destructor and a overloaded operators such that when the pointers go out of scope the memory is deallocated . 
    
copyassignment.cpp
    -> declare first and then copy - shallow copy 
    -> constructor is called - deep copy

Types of Constructor 
    -copy 
    -dynamic 
    -move constructor