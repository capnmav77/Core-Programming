// Demonstrate a raw type.
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
		return ob;
	}
}

// Demonstrate raw type.
class RawDemo 
{
	public static void main(String args[]) 
	{
		// Create a Gen object for Integers.
		Gen<Integer> iOb = new Gen<Integer>(88);
		// Create a Gen object for Strings.
		Gen<String> strOb = new Gen<String>("Generics Test");
		// Create a raw-type Gen object and give it
		// a Double value.
		Gen raw = new Gen(new Double(98.6));
		// Cast here is necessary because type is unknown.
		double d = (Double) raw.getob();
		System.out.println("value: " + d);
		// The use of a raw type can lead to run-time
		// exceptions. Here are some examples.
		// The following cast causes a run-time error!
		// int i = (Integer) raw.getob(); // run-time error
		// This assignment overrides type safety.
		strOb = raw; // OK, but potentially wrong
		// String str = strOb.getob(); // run-time error
		// This assignment also overrides type safety.
		raw = iOb; // OK, but potentially wrong
		// d = (Double) raw.getob(); // run-time error
	}
}