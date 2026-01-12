#include <iostream>

template <typename T> auto printTypeInfo(const T &t) {
    if constexpr (std::is_integral<T>::value) {
        return t + 1;
    } else {
        return t + 0.001;
    }
}

int main() {
    std::cout << "Type info: " << printTypeInfo(42) << std::endl;
    std::cout << "Type info: " << printTypeInfo(3.14) << std::endl;

    return 0;
}