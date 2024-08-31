#include <iostream>
#include <cstdint>

class Account {
public:
    Account() = default;

    Account( std::int32_t balance ) { this->balance = balance; }

    Account( const Account& other ) {
        this->balance = other.balance;
    }

    void displayBalance() const {
        std::cout << this->balance << '\n';
    }

    void deductBalance( std::int32_t deduction ) {
        if ( deduction <= balance )
            this->balance -= deduction;
    }

private:
    std::int32_t balance {0}; // assuming balance won't exceed 2,147,483,647
};

int main() {
    Account defaultAccount;
    Account parametrizedAccount(1000);
    Account copiedAccount(parametrizedAccount);
    copiedAccount.deductBalance(200);

    defaultAccount.displayBalance();
    parametrizedAccount.displayBalance();
    copiedAccount.displayBalance();
    parametrizedAccount.displayBalance();
}