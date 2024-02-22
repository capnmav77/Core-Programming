// C++ Program to implement using
#include <bits/stdc++.h>
	
using namespace std;
	
int main()
{
	// Now we can make more vectors by using vInt
	using vInt = std::vector<int>;
	
	// vec1 is a vector of type int
	vInt v;
	
	v.push_back(190);
	v.push_back(180);
	v.push_back(10);
	v.push_back(10);
	v.push_back(27);
	
	for (auto X : v) {
		cout << X << " ";
	}
	
	return 0;
}
