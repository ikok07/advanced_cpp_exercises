#include "Account.h"

#include "../exceptions/IllegalBalanceException.hpp"
#include "../exceptions/InsufficentFundsException.hpp"

Account::Account(std::string name, double balance) 
    : name{name}, balance{balance} {
    if (balance < 0) throw IllegalBalanceException("Account's amount must be greater than 0!");
}

bool Account::deposit(double amount) {
    if (amount < 0) return false;
    balance += amount;
    return true;
}

bool Account::withdraw(double amount) {
    if (balance-amount >=0) {
        balance-=amount;
        return true;
    }
    throw InsufficentFundsException("Account has insufficient funds!");
}

// double Account::get_balance() const {
//     return balance;
// }
