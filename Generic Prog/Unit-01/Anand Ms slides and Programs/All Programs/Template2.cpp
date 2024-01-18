// C++ Program to implement
// Bubble sort
// using template function
#include <iostream>
using namespace std;

// A template function to implement bubble sort.
// We can use this for any data type that supports
// comparison operator < and swap works for it.
template <class T> void bubbleSort(T a[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = n - 1; i < j; j--)
			if (a[j] < a[j - 1])
				swap(a[j], a[j - 1]);
}

// Driver Code
int main()
{
	int a[5] = { 10, 50, 30, 40, 20 };
	char c[5] = {'m', 'a', 'b', 'n', 'c'};
	float fl[8] = {1.23, 1.25, 2.54, 3.33, 2.78, 1.11, 0.45, 1.08};
	int n = sizeof(a) / sizeof(a[0]);

	// calls template function
	bubbleSort<int>(a, n);

	cout << " Sorted array : ";
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;

	n = sizeof(c) / sizeof(c[0]);

	bubbleSort<char>(c, n);

	cout << " Sorted array : ";
	for (int i = 0; i < n; i++)
		cout << c[i] << " ";
	cout << endl;

	n = sizeof(fl) / sizeof(fl[0]);

	bubbleSort<float>(fl, n);

	cout << " Sorted array : ";
	for (int i = 0; i < n; i++)
		cout << fl[i] << " ";
	cout << endl;

	return 0;
}
