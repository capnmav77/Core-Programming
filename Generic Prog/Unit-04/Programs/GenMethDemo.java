// Demonstrate a simple generic method.
class GenMethDemo 
{
	// Determine if an object is in an array.
	static <T extends Comparable<T>, V extends T> boolean isIn(T x, V[] y) // T is a type parameter that must be a Comparable type, and V is a type parameter that must be the same as or a subclass of T where comparabel is a generic interface
	{
		for(int i=0; i < y.length; i++)
			if(x.equals(y[i])) 
				return true;
		return false;
	}

	public static void main(String args[]) 
	{
		// Use isIn() on Integers.
		Integer nums[] = { 1, 2, 3, 4, 5 };
		if(isIn(2, nums))
			System.out.println("2 is in nums");
		if(!isIn(7, nums))
			System.out.println("7 is not in nums");
		System.out.println();
		// Use isIn() on Strings.
		String strs[] = { "one", "two", "three", "four", "five" };
		if(isIn("two", strs))
			System.out.println("two is in strs");
		if(!isIn("seven", strs))
			System.out.println("seven is not in strs");
		// Oops! Won't compile! Types must be compatible.
		// if(isIn("two", nums))
		// System.out.println("two is in strs");
	}
}