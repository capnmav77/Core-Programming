#include <iostream>
#include <string>
#include <vector>

using namespace std;
 
template<typename T, typename... Args>
void FoldPushBack(vector<T>& v, Args&&... args)
{
    (v.push_back(args), ...);
}

int main()
{
    vector<int> v;
	FoldPushBack(v, 1, 2, 3, 4);
	
	for (auto &i : v)
		cout << i << "\n";
}