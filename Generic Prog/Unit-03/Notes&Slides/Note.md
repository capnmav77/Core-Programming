## Generic progamming Unit - 03

- ### concepts and constraints
    - concepts are way to specify constraints on template parameters 
    - constraints are conditions or requirements that need to be satisfied by template arguments .
    - Types of constaints : 
        - Conjunctions - '&&'
        - Disjunctions - '||'
        - Atomic constraints 

    - advantages : 
        - enforcing the constaints on type params 
        - make it more readable 
        - better documentation 
        - preventing unintended template instantiations 

    - syntax :
        - they are available from the <concepts> header 
        - eg: 
            ```cpp
            template <typename T>
            requires std::integral<T>::value;

            // or 
            template <std::integral<T>>
            void fund(T x);
            ```

    - ### 4 main ways to use concepts withing our code : 
        - 1. Constrained Template parameters 
            - the language has built-in syntactic support . we can constrain the template parameters directly in the template declaration
            - eg: 
                ```cpp
                template <std::integral T>
                void func(T x);
                ```

        - 2. The requires Keyword : 
            - it has access to the types we are using and returns a boolean depending on the match 
            - eg: 
                ```cpp
                template <typename T>
                requires std::floating_point<T>
                T Average(T x, T y) 
                ```
            - we can also use is_base_of type traits to check instead of concepts 
            - eg: 
                ```cpp
                template <typename T>
                requires std::is_base_of<Shape, T>::value
                void Draw(T shape);
                ```
            
        - 3. Trailing requires clause : 
            - we can also use the trailing requires clause to specify the constraints
            - eg: 
                ```cpp
                template <typename T>
                void func(T x) requires std::integral<T>;
                ```
        
        - 4. ABBREVIATED NESTED FUNCTIONS : 
            - within abbreviated function we can set one or more function parameters to be be auto.
            - eg: 
                ```cpp
                void func(auto x, auto y) ;
                ```
            - we can also use the concepts to set constraints
            - eg: 
                ```cpp
                void func(std::integral auto x, std::integral auto y);
                ```

    - ### Writing our own concepts : 
        - we can also write our own concepts 
        - eg: 
            ```cpp
            template <typename T>
            concept Integer = std::integral<T>;
            ```
        - the breakdown : 
            - 1. template parameter list 
            - 2. concept keyword
            - 3. the name of the concept
            - 4. the constraint expression

        - we can also use the concept in the function
        - eg: 
            ```cpp
            template <Integer T>
            void func(T x);
            ```
        - we can add more complex requirements to the concepts with a function like body : 
        - eg ```
            template <typename T>
            concept Integer = requires(T x) {
                {x + x} -> std::same_as<T>;
                {x * x} -> std::same_as<T>;
            };
            ```
        - in doing so we are actually specifying the requirements for the concept 
            - Firstly we look for a type that is capable of adding and multiplying
            - Secondly we are specifying that the result of the addition and multiplication should be of the same type as the input type [optional]

        

- ## STL standard template library 
    - ### Introduction 
        - The Standard Template Library (STL) is a set of C++ template classes to provide common programming data structures and functions such as lists, stacks, arrays, etc. It is a library of container classes, algorithms, and iterators. It is a generalized library and so, its components are parameterized. A working knowledge of template classes is a prerequisite for working with STL.
        - The STL has four components:
            - Algorithms
            - Containers
            - Functions
            - Iterators

    - ### Containers
        - it's a holder object that stores a collection of other objects .
        - they are implemented as class templates allowing flexibility 
        - they manage 
            - storage space 
            - provide member functions to access the stored elements
            - provide iterators to iterate through the elements
            - replicate most commonly used data structures like q , stk , vector , ll , heap , pq etc 

        - Types of containers :
            - Sequence containers : 
                - implement data structures which can be accessed in a sequential manner 
                    - eg: vector , list , deque , arrays
                - Array 
                    - it's a static array
                    - ```array<object_type,size> array_name;```
                - Vector 
                    - it's a dynamic array 
                    - ```vector<object_type> vector_name;```
                - Deque 
                    - it's a double-ended queue
                    - ```deque<object_type> deque_name;```
                - List
                    - it's a doubly linked list allowing non-contiguous memory allocation
                    - ```list<object_type> list_name;```
                - Forward List
                    - it's a singly linked list
                    - ```forward_list<object_type> forward_list_name;```
                

            - Associative containers : 
                - implement sorted data structures that can be quickly searched , they are initially implemented as binary tree structures . results are in O(log n)
                    - eg: set , multiset , map , multimap
                - Set 
                    - it's a set of unique keys that are sorted using Red-Black Tree
                    - ```set<object_type> set_name;```
                - Map
                    - it's a set of key-value pairs that are sorted by keys with underlying data structure as Red-Black Tree
                    - ```map<key_type,value_type> map_name;```
                - Multiset 
                    - it's like a set but allows duplicate keys
                    - ```multiset<object_type> multiset_name;```
                - Multimap
                    - it's like a map but allows duplicate keys
                    - ```multimap<key,value> mmap;```


            - Unordered associative containers :
                - implement unsorted data structures that are hashed for quick retrieval
                    - eg: unordered_set , unordered_multiset , unordered_map , unordered_multimap
                - Unordered Set
                    - it's a set of unique keys that are hashed 
                    - eg: ```unordered_set<object_type> uset_name;```
                - Unordered Map
                    - it's a set of key-value pairs that are hashed by keys
                    - eg: ```unordered_map<key_type,value_type> umap_name;```
                - Unordered Multiset
                    - it's like a set but allows duplicate keys
                    - eg: ```unordered_multiset<object_type> umset_name;```
                - Unordered Multimap
                    - it's like a map but allows duplicate keys
                    - eg: ```unordered_multimap<key,value> ummap;```
                

            - Container adaptors : 
                - provide a different interface for sequential containers 
                - eg: stack , queue , priority_queue
                - Stack
                    - it's a LIFO data structure , implemented on top of deque
                    - eg: ```stack<object_type> stk_name;```
                - Queue
                    - it's a FIFO data structure , implemented on top of deque 
                    - eg: ```queue<object_type> q_name;```
                - Priority Queue
                    - it's a data structure that manages a collection of prioritized elements, similar to max heap 
                    - eg: ```priority_queue<object_type> pq_name;```
                - Note : 
                    - stack and queue are implemented on top of deque 
                    - priority queue is implemented on top of vector


    - ### Iterators
        - it's an object that allows a programmer to traverse through all the elements of a container
        - it's a generalization of pointers
        - it's a class that is used to iterate over any container
        - it's a pointer-like object that can be incremented with ++ and dereferenced with *
        - dereferencing means accessing the value of the element pointed to by the iterator -> eg : *it where it is the iterator that points to the address of the element and *it will give the value of the element
        - common syntax : 
            - ```cpp
                container_type::iterator it;
                for(it = container_name.begin(); it != container_name.end(); it++) {
                    cout << *it << endl;
                }
            ```

        - Types of iterators in increasing order of functionality: 
            - Input iterators
                - read only access to the container elements
                - can be used to read the elements of the container sequentially
                - can be incremented using ++ and dereferenced using *
            - Output iterators
                - write only access to the container elements
                - can be used to write the elements of the container sequentially
                - can be incremented using ++ and dereferenced using *
            - Forward iterators
                - read and write access to the container elements
                - can be used to read and write the elements of the container sequentially
                - can be incremented using ++ and dereferenced using *
            - Bidirectional iterators
                - read and write access to the container elements
                - can be used to read and write the elements of the container sequentially
                - can be incremented and decremented using ++ and -- and dereferenced using *
            - Random access iterators
                - read and write access to the container elements
                - can be used to read and write the elements of the container randomly
                - can be incremented and decremented using ++ and -- and dereferenced using *
                - can be used to access any element of the container in constant time
                - can be used to calculate the distance between two iterators in constant time
                - can be used to compare two iterators using relational operators


    - ### Algorithms 
        - they define a collection of functions specially to be used on sequence of objects
        - these are standalone template funtions that can be used with different containers

        - categories of algorithims into 5 types : 
            - Non-manipulative 
                - non modifying 
                - neither change the container nor the elements
                - eg : std::find , std::count , std::all_of , std::none_of , std::any_of
            - Manipulative
                - modifying 
                - change the container or the elements
                - eg : std::sort , std::reverse , std::rotate , std::copy , std::remove
            - Sorting
                - sort the elements of the container
                - eg : std::sort , std::stable_sort , std::partial_sort , std::nth_element
            - Set Algorithms 
                - perform set operations on the elements of the container
                - eg : std::set_union , std::set_intersection , std::set_difference , std::set_symmetric_difference
            

    - ### Functors 
        - it's a shorthand for function object
        - it's an object that can be called as if it were a function , it can be achieved by overloading the function call operator() 
        - Need 
            - seperation of logic 
            - parameterization 
            - Statefullness 
            - Performance 

        - eg: 
            ```cpp
            struct add_x {
                int x;
                add_x(int x) : x(x) {}
                int operator()(int y) { return x + y; }
            };
            ```
        
        - types : 
            - Generator Functors - can be called without arguments 
            - Unary Functors - can be called with one argument
            - Binary Functors - can be called with two arguments
            
        - How to create a Functor :
            - 1. Create a class with overloaded operator()
            - 2. Create an object of the class
            - 3. Call the object as if it were a function
        
- marks the end of unit - 03