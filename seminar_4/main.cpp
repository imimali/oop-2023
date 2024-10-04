#include <iostream>
#include <string>
#include "beverage.h"
#include "coffee.h"
#include "beverage_with_milk.h"
;


int main() {
    Beverage *b=new Coffee();
//    b->print();
//    delete b;

    Beverage *b1 = new BeverageWithMilk(*b);
    b1->print();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
