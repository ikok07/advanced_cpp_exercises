//
// Created by kok on 14.08.24.
//

#ifndef INSUFFICENTFUNDSEXCEPTION_HPP
#define INSUFFICENTFUNDSEXCEPTION_HPP
#include <exception>
#include <string>

class InsufficentFundsException : public std::exception {
public:
    explicit InsufficentFundsException(const char *text) : msg{text} {}
    const char *what() const noexcept override {return msg;}
private:
    const char *msg;
};

#endif //INSUFFICENTFUNDSEXCEPTION_HPP
