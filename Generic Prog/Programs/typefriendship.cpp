// typeFriendship.cpp

#include <iostream>

template <typename T>
class Bank {
    std::string secret{"Secret from the bank."};
    friend T;
};

class Account{
 public:
    Account() {
        Bank<Account> bank;
        std::cout << bank.secret << '\n';   // (1)
    }
};

int main(void)
{

    std::cout << '\n';

    Account acc;

    std::cout << '\n';
    return 0;

}