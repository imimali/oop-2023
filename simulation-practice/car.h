//
// Created by Mali Imre Gergely on 22.05.2023.
//

#ifndef SIMULATION_PRACTICE_CAR_H
#define SIMULATION_PRACTICE_CAR_H

#include <string>

class Car {
    std::string registration_nr;
    std::string model;
    std::string color;
    int mileage;
public:
    Car(std::string registration_nr, std::string model, std::string color, int mileage) : registration_nr(
            std::move(registration_nr)),
                                                                                          model(std::move(model)),
                                                                                          color(std::move(color)),
                                                                                          mileage(mileage) {}

    std::string get_registration_nr() const { return this->registration_nr; };

    std::string get_model() const { return this->model; };

    std::string get_color() const { return this->color; };

    int get_mileage() const{ return this->mileage; }

};

#endif //SIMULATION_PRACTICE_CAR_H
