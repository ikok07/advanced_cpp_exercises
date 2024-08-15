//
// Created by kok on 10.08.24.
//

#ifndef TRUST_ACCOUNT_HPP
#define TRUST_ACCOUNT_HPP
#include "Account.h"
#include "Savings_Account.h"


class Trust_Account : public Savings_Account {
    static int withdrawals_count;
    void print(std::ostream &os) const override;
public:
    explicit Trust_Account(const std::string& name = "Unnamed Account", double balance = 0.0, double int_rate = 0.0) : Savings_Account(name, balance, int_rate) {}
    bool deposit(double amount) override;
    bool withdraw(double amount) override;
    ~Trust_Account() override = default;
};



#endif //TRUST_ACCOUNT_HPP
