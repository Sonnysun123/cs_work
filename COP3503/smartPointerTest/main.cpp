#include <type_traits>
#include <iostream>

int main() {
    bool result = std::is_same<int, int>::value; // true
    bool result2 = std::is_same<int, double>::value; // false

    std::cout << "int and int are the same: " << result << std::endl; // Output: true
    std::cout << "int and double are the same: " << result2 << std::endl; // Output: false

    return 0;
}