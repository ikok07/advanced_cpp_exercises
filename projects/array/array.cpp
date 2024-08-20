//
// Created by kok on 20.08.24.
//

#include <iostream>

using namespace std;

template<typename T, int N>
class Array {
public:
    Array() = default;
    explicit Array(const int init_val) {
        for (auto& item: values)
            item = init_val;
    }
    void fill(T val) {
        for (auto& item: values)
            item = val;
    }

    int get_size() const {return this->size;}

    T &operator[](int index) {
        return values[index];
    }
private:
    int size{N};
    T values[N];

    friend ostream& operator<<(ostream& os, const Array<T, N>& arr) {
        os << "[ ";
        for (const auto& val: arr.values)
            os << val << " ";
        os << " ]" << endl;
        return os;
    }
};
