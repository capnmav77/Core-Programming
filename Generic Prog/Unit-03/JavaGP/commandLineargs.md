# Command line arguments in Java
- Command line arguments are the arguments that are passed to the program when it is invoked.
- these arguments are passed to the main method of the program. 
eg: 
```java 
// Java Program to Illustrate First Argument

// Class
class GFG {

	// Main driver method
	public static void main(String[] args)
	{
		// Printing the first argument
		System.out.println(args[0]);
	}
}
```
- In the above code, the first argument is printed.
- The arguments are passed as strings.
- The arguments are passed after the name of the program.
- to compile the above program we use the following command:
```bash
javac GFG.java
```

- to run the above program we use the following command:
```bash
java GFG "Hello World"
```



