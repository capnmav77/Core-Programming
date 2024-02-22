// Program to demonstrate the use of arrays in C++
#include <iostream>
#include <array>
#include <vector>
using namespace std;

void print_size_narray (int n [])
{
	cout << "Size of array is " << sizeof (n) << endl;
}

void print_size_vector (vector <int> &data)
{
	cout << "Size of vector is " << data.size() << endl;
}

void print_size_tarray (array<int, 5> data)
{
	cout << "Size of templatized array is " << data.size() << endl;
}

int main()
{
   	int ia[] = {0,1,2,3,4,5,6,7,8,9, 10, 11}; // ia is an array of ten ints
	int *beg = begin(ia); // pointer to the first element in ia
	vector <int> m_vector = {1, 2};
	array <int, 5> m_array = {1, 2, 3, 4, 5};
	int *last = end(ia); // pointer one past the last element in ia
	int length1 = sizeof (ia) / sizeof (int);
	int length2 = last - beg;
	
	cout << "Length of array is: " << length1 << " " << length2;
	
/*
	// Display the elements of the array
	while (beg != last)
        {
            cout << "Element is: " << *beg << endl;
            cout << "Pointer is: " << beg << endl;
            beg ++;
        }
*/

	print_size_narray (ia);	       // This is passed by reference
	print_size_vector (m_vector);  // This is passed by value
	print_size_tarray (m_array);   // Passed by value
}
