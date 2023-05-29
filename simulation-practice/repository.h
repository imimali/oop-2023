//
// Created by Mali Imre Gergely on 22.05.2023.
//

#ifndef SIMULATION_PRACTICE_REPOSITORY_H
#define SIMULATION_PRACTICE_REPOSITORY_H
#include <vector>
#include <fstream>
#include <sstream>
#include "car.h"
class Repository{
    std::vector<Car> elements;
    std::string file_name;
public:
    Repository(std::string file_name){
        std::ifstream f(file_name);
        if (!f.is_open()){
            throw std::runtime_error("Could not open "+ file_name);
        }
        while (!f.eof()){
            std::string line;
            std::getline(f,line);
            std::stringstream ss(line);
            std::string nr,model,color,mileage_s;
            std::getline(ss,nr,';');
            std::getline(ss,model,';');
            std::getline(ss,color,';');
            std::getline(ss,mileage_s,';');
            this->elements.emplace_back(nr,model,color, atoi(mileage_s.c_str()));
        }
    }
    std::vector<Car> get_all(){
        return this->elements;
    }
};

#endif //SIMULATION_PRACTICE_REPOSITORY_H
