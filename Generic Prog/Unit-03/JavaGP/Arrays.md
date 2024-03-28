# Arrays in Java
- arrays in java can store similar type of data in a contiguous container 
- arrays are reference data types
- arrays are objects in java

## Declaration of arrays
- arrays can be declared in two ways:
    - int[] arr; // preferred way
    - int arr[]; // not preferred way

## Initialization of arrays
- arrays can be initialized in two ways:
    - int[] arr = new int[5]; // preferred way
    - int arr[] = new int[5]; // not preferred way

## Accessing elements of an array
- elements of an array can be accessed using the index of the element
- index of the first element is 0
- index of the last element is n-1 where n is the size of the array

## Example
```java
// Java Program to Illustrate Arrays
// Class
Class Test{
    public static void main(String[] args){
        // Declaring an array
        int[] arr;
        // Initializing an array
        arr = new int[5];
        // Assigning values to the array
        arr[0] = 1;
        arr[1] = 2;
        arr[2] = 3;
        arr[3] = 4;
        arr[4] = 5;
        // Printing the array
        for(int i=0; i<5; i++){
            System.out.println(arr[i]);
        }
    }
}
```

## Output
```
1
2
3
4
5
```

## Array of objects
- arrays can also store objects
- objects can be of any class
- objects can be of the same class or different classes

## Example
```java
// Java Program to Illustrate Arrays of Objects
Class Test{
    public static void main(String[] args){
        // Declaring an array of objects
        String[] arr;
        // Initializing an array of objects
        arr = new String[5];
        // Assigning values to the array
        arr[0] = "Hello";
        arr[1] = "World";
        arr[2] = "Java";
        arr[3] = "Programming";
        arr[4] = "Language";
        // Printing the array
        for(int i=0; i<5; i++){
            System.out.println(arr[i]);
        }

        //declaring an array of class objects
        Test[] obj;
        obj = new Test[5];
        for(int i=0; i<5; i++){
            obj[i] = new Test();
        }
    }
}
```
