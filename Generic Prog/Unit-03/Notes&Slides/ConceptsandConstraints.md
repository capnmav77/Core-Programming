## Constraints and concepts 
- there is syntactic support for concepts and synstactic support for 

## Concepts
- Concepts are a how we specify requirements on template arguments.

## Constraints
- Constraints are what we specify requirements on template arguments.



### 3. Abbreviated function templates 
- Abbreviated function templates are a way to write function templates without having to specify the template arguments.
eg: auto Average(auto a, auto b) { return (a + b) / 2; }

    similarly for writing concepts here we insert the concept before the auto type.

    auto Average(std:: integral auto x, std:: integral auto y ){ return (x + y) / 2; }  // this is a concept 


### WRITING OUR OWN CONCEPTS : 
- we have to follow the following steps :
    1. A template parameter list ( this cnnnot reference other concepts )
    2. the concepts keyword 
    3. the name of the concept
    4. the requires keyword 

    eg:
    template <typename T>
    concept Integral = std::is_integral<T>::value; // this is a concept


an example of my concept : 
template<typename T>
concept myconcept = requires (T a, T b){ return a + b;};

from the above we can derive that 
- both the values of a and b should be able to be added together 
- the type of a and b should be the same 