#include<iostream>
using namespace std;

template <typename T>

constexpr T NewLine = T('\n');

int main()
{
    wstring test = L"demo";

    cout<<"Size is "<<sizeof(U'\n')<<"\n";
    cout<<"Size is "<<sizeof(NewLine<wchar_t>)<<"\n";
    test+= NewLine<wchar_t>;
    wcout<<test;

}