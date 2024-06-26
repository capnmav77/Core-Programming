// Generic classes

public class Pair 
{
	private Object first;
	private Object second;
	/**
	* Constructs a pair containing two given elements
	* @param firstElement the first element
	* @param secondElement the second element
	*/
	public Pair(Object firstElement, Object secondElement) 
	{
		first = firstElement;
		second = secondElement;
	}
	/**
	* Gets the first element of this pair
	* @return the first element
	*/
	public Object getFirst() 
	{
		return first;
	}
	/**
	* Gets the second element of this pair
	* @return the second element
	*/
	public Object getSecond() 
	{
		return second;
	}
	public String toString() 
	{
		return "(" + first + ", " + second + ")";
	}
}

public class Main 
{
	public static void main(String[] args) 
	{
		Pair p1 = new Pair("alpha", 1);
		// String & Integer (autoboxing) - Implicit upcasting to Object
		String name = (String) p1.getFirst();
		// esplicit downcasting from Object to String
		Integer value = (Integer) p1.getSecond();
		System.out.println("Name: "+name+" Value: "+value);
		Pair p2 = new Pair(3.2,5.5); // Double & Double (autoboxing)
		Double x = (Double) p2.getFirst();
		double y = (double) p2.getSecond(); // unboxing
		System.out.println("x: "+x+" y: "+y);
		x = (Double) p1.getFirst(); // run-time error
		// Exception in thread "main" java.lang.ClassCastException: java.lang.String
		// cannot be cast to java.lang.Double
	}
}


// Generic class

public class Pair<T, S> 
{
	private T first;
	private S second;
	/**
	* Constructs a pair containing two given elements.
	* @param firstElement the first element
	* @param secondElement the second element
	*/
	public Pair(T firstElement, S secondElement) 
	{
		first = firstElement;
		second = secondElement;
	}
	/**
	* Gets the first element of this pair.
	* @return the first element
	*/
	public T getFirst() 
	{
		return first;
	}
	/**
	* Gets the second element of this pair.
	* @return the second element
	*/
	public S getSecond() 
	{
		return second;
	}
	public String toString() 
	{
		return "(" + first + ", " + second + ")";
	}
}


// Upper bounded wildcards
import java.util.Arrays;
import java.util.List;
public class Main 
{
	public static double sumOfList(List<? extends Number> list) 
	{
		double s = 0.0;
		for (Number n : list)
			s += n.doubleValue();
		return s;
	}

	public static double productOfList(List<? extends Number> list) 
	{
		double p = 1.0;
		for (Number n : list)
			p *= n.doubleValue();
		return p;
	}
	public static void main(String[] args) 
	{
		List<Integer> li = Arrays.asList(1, 2, 3);
		System.out.println("sum = " + sumOfList(li)); // output sum = 6
		System.out.println("product = " + productOfList(li));
		List<String> sli =Arrays.asList("alpha","beta","charlie");
		System.out.println("sum = " + sumOfList(sli));
		// Compile time error: The method sumOfList(List<? extends Number>) in the type Main
		// is not applicable for the arguments (List<String>) …
		List gli = Arrays.asList("alpha","beta","charlie");;
		System.out.println("sum = " + sumOfList(gli));
		// Exception in thread "main" java.lang.ClassCastException:
		// java.lang.String cannot be cast to java.lang.Number
	}
}


