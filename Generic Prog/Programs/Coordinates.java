// Two-dimensional coordinates.
class TwoD 
{
	int x, y;
	TwoD(int a, int b) 
	{
		x = a;
		y = b;
	}
}
// Three-dimensional coordinates.
class ThreeD extends TwoD 
{
	int z;
	ThreeD(int a, int b, int c) 
	{
		super(a, b);
		z = c;
	}
}
// Four-dimensional coordinates.
class FourD extends ThreeD 
{
	int t;
	FourD(int a, int b, int c, int d) 
	{
		super(a, b, c);
		t = d;
	}
}