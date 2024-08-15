//
// Created by kok on 12.08.24.
//

#ifndef I_PRINTABLE_HPP
#define I_PRINTABLE_HPP

#include <sstream>

class I_Printable {
    friend std::ostream& operator<<(std::ostream& os, const I_Printable& obj);
public:
    virtual void print(std::ostream& os) const = 0;
    virtual ~I_Printable() = default;
};


#endif //I_PRINTABLE_HPP
