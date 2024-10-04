//
// Created by Mali Imre Gergely on 22.05.2023.
//

#ifndef SIMULATION_EXAMPLE_REPOSITORY_H
#define SIMULATION_EXAMPLE_REPOSITORY_H

#include <vector>
#include <fstream>
#include <sstream>
#include "car.h"

class RepoException : public std::runtime_error {
public:
    RepoException(const std::string &message) : std::runtime_error(message) {}
};

class Repository {
    std::vector<Car> elements;
public:
    Repository(std::string file_name) {
        std::ifstream stream(file_name);
        if (!stream.is_open()) {
            throw RepoException("Could not open file");
        }
        while (!stream.eof()) {
            std::string line;
            std::getline(stream, line);
            std::string registration, model, color, mileage_str;
            std::stringstream ss(line);
            std::getline(ss, registration, ';');
            std::getline(ss, model, ';');
            std::getline(ss, color, ';');
            std::getline(ss, mileage_str, ';');
            this->elements.emplace_back(registration, model, color, std::stoi(mileage_str));
        }
    }

    std::vector<Car> get_all() { return this->elements; }
};

#endif //SIMULATION_EXAMPLE_REPOSITORY_H
