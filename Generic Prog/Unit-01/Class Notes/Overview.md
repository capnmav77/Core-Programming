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

## Templates: 
    need for templates:
        the need for using the same source code while using different byte sized inputs : english vs other languages
        therefore characters of different widths can be accomodated in one templatized variable .

## partial Specialization . 
    we can overload the templates , for every variable types of template call , we can call different functions

## Template Instantiation?
    template -- blueprint 
    only when instantiated -- code is generated and put into the program code .
    ### implicit Instantiation :  
        - done by the compiler to call the template 
    ### explicit instantiation: 
        - it's a way to explicitly tell the compiler what instantiations of template to create even if they are not explicitly used in code .

## Formal defn of Generic programming:
    we take out the abstraction , concrete , efficient algo , to obtain generic algorithims that can be combined with different data rep. to produce wide variety of software.
    C++ 98 was when the first concept of templates are used.

    - Advantages 
        - avoid repetation 
        - compact code 
        - more compatable
    - disadvantages
        - cumbersome and hard to write 
        - cryptic error messages
        increase the compilation time . as they are in header files , and whenever the body of the template changes the all translation units in that header files are recompiled.

## Class templates 
    can be declared without being defined and used in contexts where incomplete types are allowed , such as the declaration of a function , as shown : 

    template<typename T>
    class wrapper;
    void use foo()

    template<typename T>
    class wrapper
    {
        //template defn 
    };
    void use_wrapper(wrapper<int> *ptr)
    {
        std::cout<<ptr->get <<'\n';
    }


## Member Function Templates:
    it is possible to define member function templates , both in templates classes and class templates .
    eg: 
        template<typename T>
        class wrapper // a class template
        {
            public:
                
                T foo(U u); // not a template function.
        };
        throws error when we call : 
        wrapper<int> w;
        w.foo<int>(10); // error - because it's not a template function.

    eg: 
        template<typename T>
        class wrapper // a class template
        {
            public:
                template<typename U>
                T foo(U u); // a template function.
        };
        does not throw error when we call :
        wrapper<int> w;
        w.foo<int>(10); // no error -  because it is a template function 

# Note: the function template parameter should be different from the class template parameter.

## we can templatize the class or the function or both . 


## declare a member function within a templatized class and declaration outside the class . 
    template<typename T>
    class wrapper
    {
        public:
            T foo(T t);
    };
    template<typename T>
    T wrapper<T>::foo(T t)
    {
        return t;
    }


## Non Tpye template Parameters
    we pass a non type parameter to a template , it can be a value or a pointer or a reference , but not a type .
    eg: template<typename T , int size > // here we need to declare the size of the array at compile time . 

    the possible forms are : 
        template <int V>

        template <int *V>

        template <int &V>

        template <int V[10]>

## CLass templates with multiple parameters 

## Template Template Parameters
    each parameter of a template template parameter must itself be a template parameter .
    i.e when we instantiante a class template , we can pass a class template as a parameter to the class template .
    eg: template_template.cpp

## Default Template Arguments
    we can provide default arguments to the template parameters , so that we can instantiate the template without providing the template arguments .
    eg: 
        template<typename T = int>
        class wrapper
        {
            //class defn
        };
        wrapper<> w; // here we are not providing the template argument , but the compiler will take the default argument as int .