#include<bits/stdc++.h>

using namespace std;

template <typename T>
constexpr T NewLine = T('\n');

//this template can be used for any type of data

int main()
{
    std::wstring test = L"Hello World"; // L is used to denote wide character
    cout<< "size_is:" << sizeof(U'\n') << endl; // U is used to denote unicode character
    cout<< "size_is:" << sizeof(NewLine<wchar_t>) << endl;
    test += NewLine<wchar_t>; //wide character is similar to character type , except that wide char takes up twice the space of a char
    std::wcout << test;
    return 0;
}

// the above program does :
// 1. defines a template variable NewLine
// 2. assigns a value to it
// 3. uses it in a string
// 4. prints the string
// 5. returns 0