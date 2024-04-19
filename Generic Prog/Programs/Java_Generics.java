// Methods and generic programming

/**
* Generic method - Overloading
*/
public class ArrayUtil 
{
	/**
	Get the central element of array
	@param a String array
	@return central element
	*/
	public static String getCentral(String[] a) 
	{
		if (a == null || a.length == 0)
			return null;
		return (a[a.length/2]);
	}
	public static Character getCentral(Character[] a) 
	{
		if (a == null || a.length == 0)
			return null;
		return (a[a.length/2]);
	}
	public static Integer getCentral(Integer[] a) 
	{
		if (a == null || a.length == 0)
			return null;
		return (a[a.length/2]);
	}
}

public class Main 
{
	public static void main(String[] args) 
	{
		String[] s = {"alpha","beta","charlie"};
		Character[] c = {'h', 'a', 'l'}; // autoboxing
		Integer[] i = {4 , 8 , 15 , 16 , 23 , 42};
		String sc = ArrayUtil.getCentral(s);
		assert sc.equals("beta");
		Character cc = ArrayUtil.getCentral(c);
		assert cc == 'a';
		int ic = ArrayUtil.getCentral(i); // unboxing
		assert ic == 16;
		Double[] d = {1.1, 2.3, 5.8, 13.21};
		Double dc = ArrayUtil.getCentral(d); // compile time error:
		// no suitable method found for getCentral(Double[])
		assert dc == 5.8;
	}
}

// Generic method - Inheritance and polymorphism


/*
a method that takes a base class (or interface) as an argument,
and then use that method with any class derived from that base class.
This method is more general and can be used in more places.
*/

/**
* Generic method - Inheritance
*/
public class ArrayUtil 
{
	/**
	Get the central element of the array
	@param a Object array
	@return central element
	*/
	public static Object getCentral(Object[] a)
	{
		if (a == null || a.length == 0)
			return null;
		return (a[a.length/2]);
	}
}

public class Main 
{
	public static void main(String[] args) 
	{
		String[] s = {"alpha","beta","charlie"};
		Character[] c = {'h', 'a', 'l'};
		Integer[] i = {4 , 8 , 15 , 16 , 23 , 42};
		String sc = (String) ArrayUtil.getCentral(s); 
		//downcast from Objet to String
		assert sc.equals("beta");
		Character cc = (Character) ArrayUtil.getCentral(c);
		assert cc == 'a';
		int ic = (int) ArrayUtil.getCentral(i); //downcast & unboxing
		assert ic == 16;
		Double[] d = {1.1, 2.3, 5.8, 13.21};
		Double dc = (Double) ArrayUtil.getCentral(d);
		assert dc == 5.8;
		Integer iVar = (Integer) ArrayUtil.getCentral(c); 
		// no compile-time error ->
		// run-time exception
		// Exception in thread ... java.lang.ClassCastException: java.lang.Character
		//cannot be cast to java.lang.Integer ...
	}
}
/*
Downcasting from base class can generate no type-safe code
Run-time exception occurs in wrong cast operations
*/

// Java generics
public class ArrayUtil 
{
	public static <T> T getCentral( T[] a)
	{
		if (a == null || a.length == 0)
			return null;
		return (a[a.length/2]);
	}
}

public class Main 
{
	public static void main(String[] args) 
	{
		String[] s = { "alpha", "beta", "charlie" };
		Character[] c = { 'h', 'a', 'l' };
		Integer[] i = { 4, 8, 15, 16, 23, 42 };
		Double[] d = { 1.1, 2.3, 5.8, 13.21 };
		String sc = ArrayUtil.getCentral(s); // implicit type (String) parameter
		assert sc.equals("beta");
		Character cc = ArrayUtil.<Character> getCentral(c); // esplicit type (Character) parameter
		assert cc == 'a';
		int ic = ArrayUtil.getCentral(i); // implicit type parameter & unboxing
		assert ic == 16;
		Double dc = (Double) ArrayUtil.getCentral(d);
		assert dc == 5.8;
		// Integer iVar = ArrayUtil.getCentral(c); // compile-time error: incompatible types
	}
}
