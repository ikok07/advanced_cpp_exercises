//
// Created by kok on 12.08.24.
//

#include "I_Printable.hpp"

std::ostream& operator<<(std::ostream& os, const I_Printable& obj) {
    obj.print(os);
    return os;
}