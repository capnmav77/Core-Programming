# Introduction to GP in JAVA

- (Oracle-Link)[https://docs.oracle.com/javase/tutorial/java/generics/rawTypes.html]

- Elimination of casts 
- Enabling Programmers to typecast
- A generic type is a generic class or interface that is parameterized over types. The following Box class will be modified to demonstrate the concept:


### Generic Types

Generic types are parameterized types that allow you to specify the type of objects a class or method can operate on. This is done by using type parameters, which are placeholders for the actual types that will be used when an instance of the generic class or method is created. For example, a generic Box class might be defined as follows:

public class Box<T> {
    public void set(T t) { /* ... */ }
    // ...
}
- Here T is a placeholder for the type that will be specified when a Box instance is created. This type parameter can be used to declare the type of instance variables, return types, and parameters for methods, as shown in the set method.



### Raw Types 

- Raw types, on the other hand, are the unparameterized versions of generic types. They are used when the type parameters of a generic class or method are not specified. For example, if you create an instance of Box without specifying a type argument, like :
```java
    Box rawBox = new Box();
```
- you are using a raw type. 
- Raw types essentially revert to the pre-generics behavior, where the Box would give you Objects, and you would need to cast the objects to the expected type manually when you retrieve them.
- are types of generic classes or interfaces without any arguments . 
- Raw types show up in legacy code because of lot's of api classes were not generic , threfore when using raw types , you essentially get pre-generics behaviour
- example of a raw type : Box rawBox = stringBox; where stringBox is a generic type and rawBox is a raw type
- Therefore when we assign a raw type with a object the compiler infers the type of the object and assigns it to the raw type


- ### Unchecked Error Message
    - Raw types show up in legacy code because of lot's of api classes were not generic , threfore when using raw types , you essentially get pre-generics behaviour 
    - Box rawBox = stringBox;

    - we do something called - compile type typechecking in normal code 
    - Over here the compiler does not have enough information in order to do the above typechecking during compile time therefore we get a error message -> Unchecked Error Message

- What happens when we assign a Generic type to a Raw type ?
    - The compiler will give a warning message
    - ex: Box rawBox = stringBox; // warning message , what type of object is being stored in the rawBox
    - There is a tool called Type eraser that removes the type parameters and replaces it with the raw type
    - ex: 
    ```java
        Box<String> stringBox = new Box<>(); // generic type where the type is specified as String and the new Box is created with the type String
        Box rawBox = stringBox; // raw type
        rawBox.set(8); // warning message
    ```


### Bounded Type Parameters
    - equivalent to the type traits in C++
    - i.e we can restrict the types that can be used as type parameters in a generic class or method
    - How do we use Type Traits in C++?
        -Type traits are used to associate properties of types with the types themselves.
        - template <typename T>
        - void print(T t)
        - {
        -     cout << t << endl;
        - }
    
    - How do we use Bounded Type Parameters in JAVA?
    ``` 
        public class Box<T extends Integer>
        {
            public void set(T t)
            {
                // ...
            }
        }
    ```
    - In the above example we are restricting the type parameter to be of type Integer and the derived classes of Integer i.e Integer, Long, Short, Byte etc.
    
    
