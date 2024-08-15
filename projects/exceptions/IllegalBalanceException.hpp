//
// Created by kok on 14.08.24.
//

#ifndef ILLEGALBALANCEEXCEPTION_HPP
#define ILLEGALBALANCEEXCEPTION_HPP
#include <exception>
#include <string>

class IllegalBalanceException : public std::exception {
public:
    explicit IllegalBalanceException(const char *text) : msg{text} {}
    const char *what() const noexcept override {return msg;}
private:
    const char *msg;
};

#endif //ILLEGALBALANCEEXCEPTION_HPP
