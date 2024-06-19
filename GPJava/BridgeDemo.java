// A situation that creates a bridge method.
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
// A subclass of Gen.
class Gen2 extends Gen<String> 
{
	Gen2(String o) 
	{
		super(o);
	}
	// A String-specific override of getob().
	String getob() 
	{
		System.out.print("You called String getob(): ");
		return ob;
	}
}
// Demonstrate a situation that requires a bridge method.
class BridgeDemo 
{
	public static void main(String args[]) 
	{
		// Create a Gen2 object for Strings.
		Gen2 strOb2 = new Gen2("Generics Test");
		System.out.println(strOb2.getob());
	}
}