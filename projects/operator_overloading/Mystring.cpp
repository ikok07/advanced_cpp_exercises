#include <iostream>
#include <cstring>
#include "Mystring.h"

 // No-args constructor
Mystring::Mystring() 
    : str{nullptr} {
    str = new char[1];
    *str = '\0';
}

// Overloaded constructor
Mystring::Mystring(const char *s) 
    : str {nullptr} {
        if (s==nullptr) {
            str = new char[1];
            *str = '\0';
        } else {
            str = new char[strlen(s)+1];
            strcpy(str, s);
        }
}

// Copy constructor
Mystring::Mystring(const Mystring &source) 
    : str{nullptr} {
        str = new char[strlen(source.str)+ 1];
        strcpy(str, source.str);
 //       std::cout << "Copy constructor used" << std::endl;

}

// Move constructor
Mystring::Mystring( Mystring &&source) 
    :str(source.str) {
        source.str = nullptr;
//        std::cout << "Move constructor used" << std::endl;
}

 // Destructor
Mystring::~Mystring() {
    delete [] str;
}

 // Copy assignment
Mystring &Mystring::operator=(const Mystring &rhs) {
//    std::cout << "Using copy assignment" << std::endl;

    if (this == &rhs) 
        return *this;
    delete [] str;
    str = new char[strlen(rhs.str) + 1];
    strcpy(str, rhs.str);
    return *this;
}

// Move assignment
Mystring &Mystring::operator=( Mystring &&rhs) {
 //   std::cout << "Using move assignment" << std::endl;
    if (this == &rhs) 
        return *this;
    delete [] str;
    str = rhs.str;
    rhs.str = nullptr;
    return *this;
}

Mystring Mystring::operator-() const {
    char *buff = new char[strlen(this->str) + 1];
    strcpy(buff, this->str);
    for (int i = 0; i < strlen(this->str); i++) {
        buff[i] = tolower(buff[i]);
    }
    auto new_str = Mystring{buff};
    delete[] buff;
    return new_str;
}

Mystring Mystring::operator+() const {
    char *buff = new char[strlen(this->str) + 1];
    strcpy(buff, this->str);
    for (int i = 0; i < strlen(this->str); i++) {
        buff[i] = toupper(buff[i]);
    }
    auto new_str = Mystring{buff};
    delete[] buff;
    return new_str;
}

bool Mystring::operator==(const Mystring &rhs) const {
    return strcmp(this->str, rhs.str) == 0;
}

bool Mystring::operator!=(const Mystring &rhs) const {
    return !(*this == rhs);
}

bool Mystring::operator<(const Mystring &rhs) const {
    return strcmp(this->str, rhs.str) < 0;
}

bool Mystring::operator>(const Mystring &rhs) const {
    return !(*this < rhs);
}

Mystring Mystring::operator+(const Mystring &rhs) const {
    char *buff = new char[strlen(this->str) + strlen(rhs.str) + 1];
    strcpy(buff, this->str);
    strcat(buff, rhs.str);
    Mystring new_str{buff};
    delete[] buff;
    return new_str;
}

Mystring& Mystring::operator+=(const Mystring& rhs) {
    char *buff = new char[strlen(this->str) + strlen(rhs.str) + 1];
    strcpy(buff, this->str);
    strcat(buff, rhs.str);
    delete[] this->str;
    this->str = buff;
    return *this;
}

Mystring& Mystring::operator*(int multiplier) {
    char *buff = new char[strlen(this->str) * multiplier + 1];
    strcpy(buff, this->str);
    for (int i = 0; i < multiplier - 1; i++) {
        strcat(buff, this->str);
    }
    delete[] this->str;
    this->str = buff;
    return *this;
}

Mystring & Mystring::operator*=(int multiplier) {
    return *this * multiplier;
}

Mystring& Mystring::operator++() {
    *this = -*this;
    return *this;
}

Mystring Mystring::operator++(int) {
    Mystring str{*this};
    operator++();
    return str;
}

Mystring& Mystring::operator--() {
    *this = +*this;
    return *this;
}

Mystring Mystring::operator--(int) {
    Mystring str{*this};
    operator--();
    return str;
}


// Display method
void Mystring::display() const {
    std::cout << str << " : " << get_length() << std::endl;
}

 // getters
 int Mystring::get_length() const { return strlen(str); }
 const char *Mystring::get_str() const { return str; }

// overloaded insertion operator
std::ostream &operator<<(std::ostream &os, const Mystring &rhs) {
    os << rhs.str;
    return os;
}

// overloaded extraction operator
// std::istream &operator>>(std::istream &in, Mystring &rhs) {
//     char *buff = new char[1000];
//     in >> buff;
//     rhs = Mystring{buff};
//     delete [] buff;
//     return in;
// }

