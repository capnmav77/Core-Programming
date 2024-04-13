# Bounded type parameters

- Checkout Stats.java , it throws an error because the type parameter T is not bounded. therefore when we try to compare the objects of type T , it throws an error. 
- To fix this we can bound the type parameter T to implement the Comparable interface.
- we can fix this by mentioning <T extends superclass> 
- therefore checkout Bounds.java for the fixed code.

- #### Bounded by an interface
```java
class Gen<T extends MyClass & MyInterface>
```
- Therefore T should be a subclass of MyClass and should implement MyInterface.
- Note : in bounded Type the class should appear first and then the interface appears. 


- ### Using Wildcard Arguments 
    - using of auto to compare the objects of type T and U is possible in cpp but not here
    - example: wildcard.java
    - Wildcards are used to represent an unknown type.
    - they are used in the place of type arguments.

- #### Bounded Wildcard Arguments
    - the problem with wildcard arguments is that they can take in all types of file 
    - therefore we can bound the wildcard arguments to take in only the objects of type T or its subclasses.
    - checkout Bounded Wildcard .java for the implementation 


- ### Multiple bounds 
    - if we have multiple classes that act as the bound , if any of them act as interface then it should be mentioned first.
    - example : MultipleBounds.java
    - T should be a subclass of MyClass and should implement MyInterface and Comparable interface.

- #### Generic Methods within a Non -Generic Class
    - we can have generic methods within a non-generic class.
    - checkout GenericMethodDemo.java 


- ### Generic Constructor for Non-Generic Class
    - we can have a generic constructor for a non-generic class.
    - checkout GenericConstructor.java


- ### Generic Interface 
    - we can have a generic interface.
    - checkout GenIFDemo.java