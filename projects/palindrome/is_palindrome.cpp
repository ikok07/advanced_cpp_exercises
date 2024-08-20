//
// Created by kok on 20.08.24.
//

#include <iostream>
#include <cmath>
#include <deque>

using namespace std;

bool is_palindrome(const string& s) {
    string formatted_str = s;
    formatted_str.erase(remove_if(formatted_str.begin(), formatted_str.end(), [](const char c) {
        return !isalpha(c);
    }), formatted_str.end());
    transform(formatted_str.begin(), formatted_str.end(), formatted_str.begin(), ::toupper);

    deque<char> palindrome;
    auto forward_it = formatted_str.begin() + formatted_str.length() / 2;
    auto reverse_it = formatted_str.rbegin() + formatted_str.length() / 2 - 1;

    for (int i = 0; i < ceil(formatted_str.length() / 2.0); i++) {
        if (forward_it != formatted_str.end()) palindrome.push_front(*forward_it--);
        if (*reverse_it) palindrome.push_back(*reverse_it--);
    }

    auto deque_fwd = palindrome.begin();
    auto deque_rvs = palindrome.rbegin();

    for (int i = 0; i < formatted_str.length() / 2; i++) {
        if (*deque_fwd++ != *deque_rvs++) return false;
    }

    return true;
}