// C++ Program to implement typedef
#include <bits/stdc++.h>
	
using namespace std;
	
int main()
{
	// Now we can make more vectors by using vInt
	typedef std::vector<int> vInt;
	
	// vec1 is a vectorof type int
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
