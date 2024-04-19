#include <functional>
#include <iostream>
struct Money
{
    int Dollar;
    int Cent;
    bool operator >(const Money& m)
    {
        if (Dollar > m.Dollar)
            return true;
        if (Dollar==m.Dollar)
            if (Cent > m.Cent)
                return true;
        return false;
    }
};
int main(void)
{
    Money m1{ 5,40 };
    Money m2{ 4, 50 };
    std::greater<> g;
    //std::greater<void> g; //Same as above
    //std::greater<Money> g // Same as above
    if (g(m1,m2))
    {
        std::cout << m1.Dollar << " Dollar " << m1.Cent << " Cent is greater than "<< m2.Dollar << " Dollar " << m2.Cent << " Cent" << '\n'; 
    }
    else
    {
        std::cout << m1.Dollar << " Dollar " << m1.Cent << " Cent is not greater than " << m2.Dollar << " Dollar " << m2.Cent << " Cent" << '\n';
    }
    return 0;
    
}