class BankAccount {
private: // encapsulated data
    int balance;

public: // methods
    BankAccount(): balance(0) {} // Constructor

    void deposit(int amount) {
        if (amount > 0) { 
            balance += amount;
        } else {
            std::cout << "Amount should be positive." << std::endl;
        }
    }

    void withdraw(int amount) {
        if (amount > balance) {
            std::cout << "Insufficient balance." << std::endl;
        } else {
            balance -= amount;
        }
    }

    int getBalance() {
        return balance;
    }
};

int main() {
    BankAccount account;

    account.deposit(100);
    account.withdraw(50);

    std::cout << "Balance: " << account.getBalance() << std::endl; // Prints: Balance: 50

    return 0;
}
