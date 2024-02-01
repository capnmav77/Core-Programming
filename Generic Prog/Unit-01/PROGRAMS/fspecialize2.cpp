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

	const T& operator[](int index) const { return m_array[index]; }
	T& operator[](int index) { cout<<"nonconst"<<endl; return m_array[index]; }
};

template <typename T, int size>
void print(const StaticArray<T, size>& array)
{
	for (int count{ 0 }; count < size; ++count)
		std::cout << array[count] << ' ';
}

// Override print() for fully specialized StaticArray<char, 14>
template <>
void print(const StaticArray<char, 10>& array)
{
	for (int count{ 0 }; count < 10; ++count)
		std::cout << array[count];
}

int main()
{
    // Declare a char array
    StaticArray<char, 10> char12{}; // fully specialization of StaticArray<char, 12>

    // Copy some data into it
    constexpr std::string_view hello{ "Hello, mom!" };
    std::copy_n(hello.begin(), hello.size(), char12.getArray());

    // Print the array
    print(char12);

	char12[0];

	char12[0]='a';
    return 0;
}