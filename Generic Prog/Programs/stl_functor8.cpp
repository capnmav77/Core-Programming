#include <functional>
#include <iostream>
struct Money
{
    int Dollar;
    int Cent;
    bool operator ==(const Money& m)
    {
    if (Dollar==m.Dollar && Cent == m.Cent)
    return true;

    return false;
    }
};
int main(void)
{
    Money m1{ 5,40 };
    Money m2{ 5, 30 };
    std::equal_to<> e;
    //std::equal_to<void> e; //Same as above
    //std::equal_to<Money> e // Same as above
    if (e(m1,m2))
    {
        std::cout << m1.Dollar << " Dollar " << m1.Cent << " Cent is equal to "<< m2.Dollar << " Dollar " << m2.Cent << " Cent" << '\n'; 
    }
    else
    {
        std::cout << m1.Dollar << " Dollar " << m1.Cent << " Cent is not equal to " << m2.Dollar << " Dollar " << m2.Cent << " Cent" << '\n';
    }
    return 0;
    
}