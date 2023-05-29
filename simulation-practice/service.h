//
// Created by Mali Imre Gergely on 22.05.2023.
//

#ifndef SIMULATION_PRACTICE_SERVICE_H
#define SIMULATION_PRACTICE_SERVICE_H
#include <algorithm>
#include "repository.h"

class Service {
    Repository &repo;
public:

    Service(Repository &repo) : repo(repo) {}

    std::vector<Car> get_all() {
        return this->repo.get_all();
    }

    std::vector<Car> get_sorted_by_model(){
        std::vector<Car> result{repo.get_all()};
        std::sort(result.begin(),result.end(),[](const Car& c1,const Car&c2){

            return c1.get_model()<c2.get_model();

        });
        return result;
    }

    std::vector<Car> get_sorted_by_registration_nr(){
        std::vector<Car> result{repo.get_all()};
        std::sort(result.begin(),result.end(),[](const Car& c1,const Car&c2){

            return c1.get_registration_nr()<c2.get_registration_nr();

        });
        return result;
    }
};

#endif //SIMULATION_PRACTICE_SERVICE_H
