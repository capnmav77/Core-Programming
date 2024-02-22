#include <algorithm>
#include <iostream>
#include <string_view>
using namespace std;

template <typename T, int size> // size is the expression parameter
class StaticArray
{
private:
	// The expression parameter controls the size of the array
	T m_array[size]{};

public:
	T* getArray() { return m_array; }

	const T& operator[](int index) const { 
        cout<<"const operator"<<endl;
        return m_array[index]; 
    }
	T& operator[](int index) { 
        cout<<"not const operator"<<endl;
        return m_array[index]; 
    }
};

template <typename T, int size>
void print( StaticArray<T, size>& array)
{
	for (int count{ 0 }; count < size; ++count)
		std::cout << array[count] << ' ';
}

// Override print() for fully specialized StaticArray<char, 14>
template <>
void print( StaticArray<char, 14>& array)
{
	for (int count{ 0 }; count < 14; ++count)
		std::cout << array[count];
}

int main()
{
    // Declare a char array
    StaticArray<char, 15> char14{};

    // Copy some data into it
    std::string_view hello{ "Hello, world!" };
    /* std::string_view() provides the view of pre-defined char str[] without creating 
       a new object to the memory.
    */
    std::copy_n(hello.begin(), hello.size(), char14.getArray());
    /* The copy_n() function in C++ is used to copy the first n values starting 
       from an index to a result vector. This function is available in the 
       <algorithm.h> header file.
    */

    // Print the array
    print(char14);

    return 0;
}