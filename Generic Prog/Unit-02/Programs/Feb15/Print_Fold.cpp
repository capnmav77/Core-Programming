#include <iostream>
#include <string>

using namespace std;
 
template<typename ...Args>
void FoldPrint(Args&&... args) {
    (cout <<  ... <<  forward<Args>(args)) << '\n';
}

int main()
{
    FoldPrint("hello", ", ", 10, ", ", 90.0);
}