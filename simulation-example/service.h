//
// Created by Mali Imre Gergely on 22.05.2023.
//

#ifndef SIMULATION_EXAMPLE_SERVICE_H
#define SIMULATION_EXAMPLE_SERVICE_H
#include "repository.h"
#include <algorithm>

class Service{
private:
    Repository& repo;
public:
    explicit Service(Repository &repo) : repo(repo) {}

    auto get_all(){return this->repo.get_all();}

    std::vector<Car> get_sorted_by_model(){
        auto all = this->get_all();
        std::sort(all.begin(),
                  all.end(),
                  [](const Car&c1,const Car&c2){
                      return c1.get_model()<c2.get_model();
        });
        return all;
    }

    std::vector<Car> get_sorted_by_registration_nr(){
        auto all = this->get_all();
        std::sort(all.begin(),
                  all.end(),
                  [](const Car&c1,const Car&c2){
                      return c1.get_registration_nr()<c2.get_registration_nr();
                  });
        return all;
    }

    std::vector<Car> get_filtered_by_mileage(int mileage){
        std::vector<Car> result;
        auto all = this->get_all();
        std::copy_if(all.begin(),
                     all.end(),
                     std::back_inserter(result),
                     [mileage](const Car& c){
                         return c.get_mileage()<mileage;
        });
        return result;
    }



};

#endif //SIMULATION_EXAMPLE_SERVICE_H
