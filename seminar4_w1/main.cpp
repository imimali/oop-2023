#include <iostream>
#include "tlist.h"

int main() {
    d_vector<int> v;
    d_vector<int> v1;
    v.add(1);
    v.add(2);
    auto p=std::make_unique<d_vector<int>>(v);
    auto p1=std::move(p);

    auto p3 = std::make_shared<d_vector<int>>(v1);

    auto p4 = p3;
    std::cout << v[1] << std::endl;
    std::cout << *v << std::endl;
    v();


//    std::cout << v.to_string() << std::endl;
//    std::cout << v2.to_string() << std::endl;
    std::cout << "Hello, World!" << std::endl;
//    std::getchar();
//    std::getchar();
    return 0;
}
