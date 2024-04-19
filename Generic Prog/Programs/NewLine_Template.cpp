#include <iostream>
using namespace std;

template<typename T>
constexpr T NewLine = T('\n');

// This template can be used as follows:
int main()
{
	std::wstring test = L"demo";
	cout << "size is: " << sizeof (U'\n') << "\n";
	cout << "size is: " << sizeof (NewLine<wchar_t>) << "\n";
	test += NewLine<wchar_t>; // Wide char is similar to char data type, 
				  // except that wide char takes up twice the space
	std::wcout << test;
}