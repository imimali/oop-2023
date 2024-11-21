//
// Created by Mali Imre Gergely on 24.04.2023.
//

#ifndef SEMINAR_4_BEVERAGE_H
#define SEMINAR_4_BEVERAGE_H
#include <string>
#include <iostream>

class Beverage {
    std::string description;
public:
    Beverage(const std::string&desc):description(desc){
    }
    virtual double price()=0;

    virtual void print(){
        std::cout<<description<<" for $"<<this->price()<<std::endl;
    }
};


#endif //SEMINAR_4_BEVERAGE_H
