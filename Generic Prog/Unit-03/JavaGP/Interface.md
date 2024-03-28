# Interface in Java
- Interface is a reference type in Java
- Interface is similar to a class
- Interface is a collection of abstract methods

## Declaration of an Interface
- Interface can be declared using the keyword `interface`
- Interface can have methods and variables
- Interface methods are by default abstract and public

## Example
```java
// Java Program to Illustrate Interface
// Interface
interface GFG{
    // Abstract method
    void display();
}

// Class
class Test implements GFG{
    // Implementing the abstract method
    public void display(){
        System.out.println("Hello World");
    }

    // Main driver method
    public static void main(String[] args){
        //calling the interface method
        GFG obj = new Test();
        obj.display();
        // Creating an object of the class
        Test obj = new Test();
        // Calling the method
        obj.display();
    }
}
```
