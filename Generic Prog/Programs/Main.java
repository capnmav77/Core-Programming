package Practice;

import java.util.Arrays;

import javax.sound.midi.SysexMessage;

public class Main {
    public static void main(String[] args) {

        // Java Arrays
        // int[] arr = {1, 2, 3, 4, 5};
        // for (int i = 0; i < arr.length; i++) {
        //     System.out.println(arr[i]);
        // }
        
        // //declare a array to use arrays.sort and arrays.fill method
        // int[] arr2 = new int[5];
        // Arrays.fill(arr2, 10);
        // Arrays.sort(arr2);
        // for (int i = 0; i < arr2.length; i++) {
        //     System.out.println(arr2[i]);
        // }

        // //declare a 2D array
        // int[][] arr3 = new int[2][3];
        // for (int i = 0; i < arr3.length; i++) {
        //     for (int j = 0; j < arr3[i].length; j++) {
        //         arr3[i][j] = i + j;
        //     }
        // }
        // System.out.println("Before sorting");
        // for (int i = 0; i < arr3.length; i++) {
        //     for (int j = 0; j < arr3[i].length; j++) {
        //         System.out.println(arr3[i][j]);
        //     }
        // }
        // System.out.println("After sorting");
        // Arrays.sort(arr3[0]);
        // for (int i = 0; i < arr3.length; i++) {
        //     for (int j = 0; j < arr3[i].length; j++) {
        //         System.out.println(arr3[i][j]);
        //     }
        // }


        // //Java Strings 
        // String myString = new String("Hello World");
        // String myString2 = "Hello World";
        // System.out.println(myString==myString2);
        // MyStringEx myobj = new MyStringEx();
        // System.out.println(myobj.getTypeOfDayWithSwitchStatement("Thursday"));


        //Java Nested Classes
        // Main.NestedClass obj = new Main.NestedClass();
        // obj.myMethod();

        //Java Lambda expressions
        //MyInterface myobj = () -> System.out.println("This is a lambda expression");
        // MyInterface Myob2 = (int a , int b ) -> {
        //     System.out.println("i have nothing to say mate !");
        //     System.out.println("nah i'd rather have a coffee");
        //     System.out.println(a+b);
        // };
        // Myob2.myMethod(2,3);


        //Generics in Java - assigning raw type to a generic type lol //unchecked warn
        // Boxy integerBox = new Boxy();
        // Boxy<Integer> rawBoxy = integerBox;
        // rawBoxy.set(8);
        // System.out.println(rawBoxy.get());

        // Pair <Integer , String> P1 = new Pair<>(1, "apple");
        // Pair <Integer , String> P2 = new Pair<>(2, "orange");

        // boolean areEqual = Util.compare(P1, P2);
        // System.out.println("yes or no:\n"+areEqual);


        //wildcard demo
        // Integer inums[] = { 1, 2, 3, 4, 5 };
        // Stats<Integer> iob = new Stats<Integer>(inums);
        // double v = iob.average();
        // System.out.println("iob average is " + v);
        // Double dnums[] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
        // Stats<Double> dob = new Stats<Double>(dnums);
        // double w = dob.average();
        // System.out.println("dob average is " + w);
        
        // Stats<Float> fob = new Stats<Float>(new Float[] {1.0f,2.0f,3.0F,4.0F,5.0F});
        // double avg = fob.average();
        // System.out.println("fob average is " + avg);
            
        // System.out.println(iob.sameAvg(fob));

        // String str[] = { "One", "Two", "Three", "Four", "Five" };
        // // System.out.println(iob.sameAvg(str));

        // Gen<Integer> iOb = new Gen<Integer>(88);

        // Gen2<Integer> iob = new Gen2<>(88);
        // System.out.println(iob.getob());
        // Gen<Integer> iob2 = new Gen<>(99);
        // System.out.println(iob2.getob());

        // System.out.println(iob instanceof Gen2<?>);
        // System.out.println(iob instanceof Gen<?>);
        // System.out.println(iob2 instanceof Gen2<?>);
        // System.out.println(iob2 instanceof Gen<?>);

        // (Gen<Integer) iob;
        // this is not possible as generic type info does not exist at runtime
        
        // Create a Gen object for Integers.
		Gen<Integer> iOb = new Gen<Integer>(88);
		// Create a Gen2 object for Integers.
		Gen2<Integer> iOb2 = new Gen2<Integer>(99);
		// Create a Gen2 object for Strings.
		Gen2<String> strOb2 = new Gen2<String> ("Generics Test");
		System.out.println(iOb.getob());
		System.out.println(iOb2.getob());
		System.out.println(strOb2.getob());

    }

    //nested classes in java
    static class NestedClass {
        public void myMethod() {
            System.out.println("This is a nested class");
        }
    }
}

// Overriding a generic method in a generic class.
class Gen<T> 
{
	T ob; // declare an object of type T
	// Pass the constructor a reference to an object of type T.
	Gen(T o) 
	{
		ob = o;
	}
	// Return ob.
	T getob() 
	{
		System.out.print("Gen's getob(): " );
		return ob;
	}
}
// A subclass of Gen that overrides getob().
class Gen2<T> extends Gen<T> 
{
	Gen2(T o) 
	{
		super(o);
	}
	// Override getob().
	T getob() 
	{
		System.out.print("Gen2's getob(): ");
		return ob;
	}
}


class Pair<K, V> {
    private K key;
    private V value;
    public Pair(K key, V value) {
    this.key = key;
    this.value = value;
    }
    public void setKey(K key) { this.key = key; }
    public void setValue(V value) { this.value = value; }
    public K getKey() { return key; }
    public V getValue() { return value; }
}

class Util {
    //example of type inference where the compiler decides the tyep of K and V based on the parameters passed
    public static <K, V> boolean compare(Pair<K, V> p1, Pair<K, V> p2) {
    return p1.getKey().equals(p2.getKey()) &&
    p1.getValue().equals(p2.getValue());
    }
}

class Boxy<T>
{
    private T t;
    public void set(T t) { this.t = t; }
    public T get() { return t; }
}

interface MyInterface {
    void myMethod(int a , int b);
}

class MyStringEx {
    public String getTypeOfDayWithSwitchStatement(String dayOfWeekArg) {
        String typeOfDay;
        switch (dayOfWeekArg) {
        case "Monday":
        typeOfDay = "Start of work week";
        break;
        case "Tuesday":
        case "Wednesday":
        case "Thursday":
        typeOfDay = "Midweek";
        break;
        case "Friday":
        typeOfDay = "End of work week";
        break;
        case "Saturday":
        case "Sunday":
        typeOfDay = "Weekend";
        break;
        default:
        throw new IllegalArgumentException("Invalid day of the week: " + dayOfWeekArg);
        }
        return typeOfDay;
    }
}

class Stats<T extends Number> 
{
	T[] nums; // array of Number or subclass
	// Pass the constructor a reference to
	// an array of type Number or subclass.
	Stats(T[] o) 
	{
		nums = o;
	}
	// Return type double in all cases.
	public double average() 
	{
		double sum = 0.0;
		for(int i=0; i < nums.length; i++)
			sum += nums[i].doubleValue();
		return sum / nums.length;
	}
	// Determine if two averages are the same.
	// Notice the use of the wildcard.
	boolean sameAvg(Stats<?> ob) // wildcard that matches Stats of any type
	{
		if(average() == ob.average())
			return true;
		return false;
	}
}
