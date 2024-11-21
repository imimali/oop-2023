//
// Created by Mali Imre Gergely on 24.04.2023.
//

#ifndef SEMINAR_4_BEVERAGE_WITH_MILK_H
#define SEMINAR_4_BEVERAGE_WITH_MILK_H

#include "beverage.h"

class BeverageWithMilk : public Beverage {
    int milkCount;
    Beverage& beverage;
public:
    BeverageWithMilk( Beverage &b)
    : Beverage("with milk"),beverage(b){
    }

    double price(){
        return this->beverage.price()+100;
    }

    void print(){
        this->beverage.print();
        std::cout<<"+ milk\n";
    }
};


#endif //SEMINAR_4_BEVERAGE_WITH_MILK_H
