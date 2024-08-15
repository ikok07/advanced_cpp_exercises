//
// Created by kok on 10.08.24.
//

#include "Checking_Account.hpp"

bool Checking_Account::deposit(double amount) {
    return Account::deposit(amount);
}

bool Checking_Account::withdraw(double amount) {
    amount += 1.5;
    return Account::withdraw(amount);
}

void Checking_Account::print(std::ostream &os) const {
    os << "[Checking_Account: " << this->name << ": " << this->balance << ']' << std::endl;
}
