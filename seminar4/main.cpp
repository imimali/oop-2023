#include <iostream>


template<int N>
int f() {
    return N + 10;
}
int main() {
    f<100>();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
