// typeFriendship.cpp

#include <iostream>
#include<typeinfo>
using namespace std;
template <typename T>
class Bank {
    std::string secret{"Secret from the bank."};
    friend T;

    template <typename U> 
    friend void print(Bank<U>);
};


template <typename T>
void print(Bank<T> bk)
{
    cout<<bk.secret<<" Here"<<endl;
}

class Account{
 public:
    Account() {
        Bank<Account> bank;
        std::cout << bank.secret << '\n';   // (1)
    }
};

int main(void)
{
    int const a = 2;
    cout<<typeid(a).name()<<'\n';

    // Account acc;
    // Bank<int>n;
    // print(n);
    // std::cout << '\n';
    return 0;

}