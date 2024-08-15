//
// Created by kok on 10.08.24.
//

#include "Trust_Account.hpp"

#include "Account.h"

int Trust_Account::withdrawals_count = 0;

bool Trust_Account::deposit(double amount) {
    if (!Account::deposit(amount)) return false;
    if (amount >= 5000) this->balance += 50;
    return true;
}

bool Trust_Account::withdraw(double amount) {
    double percentage = amount / balance;
    if (withdrawals_count < 4 && percentage < 0.2) {
        if (!Savings_Account::withdraw(amount)) return false;
        withdrawals_count++;
        return true;
    }
    return false;
}

void Trust_Account::print(std::ostream &os) const {
    os << "[Trust_Account: " << this->name << ": " << this->balance << ", " << this->int_rate << "%]" << std::endl;
}
