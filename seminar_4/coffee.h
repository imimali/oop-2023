//
// Created by Mali Imre Gergely on 24.04.2023.
//

#ifndef SEMINAR_4_COFFEE_H
#define SEMINAR_4_COFFEE_H
#include "beverage.h"

class Coffee: public Beverage{
public:
    Coffee(): Beverage("coffee"){
    }
    double price()override{
        return 50;
    }

};


#endif //SEMINAR_4_COFFEE_H
