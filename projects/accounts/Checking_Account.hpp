//
// Created by kok on 10.08.24.
//

#ifndef CHECKING_ACCOUNT_HPP
#define CHECKING_ACCOUNT_HPP

#include "Account.h"

class Checking_Account : public Account {
    void print(std::ostream &os) const override;
public:
    explicit Checking_Account(const std::string& name = "Unnamed Account", double balance = 0.0): Account(name, balance) {}
    bool deposit(double amount) override;
    bool withdraw(double amount) override;
    ~Checking_Account() override = default;
};


#endif //CHECKING_ACCOUNT_HPP
