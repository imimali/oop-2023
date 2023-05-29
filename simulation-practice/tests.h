//
// Created by Mali Imre Gergely on 22.05.2023.
//

#ifndef SIMULATION_PRACTICE_TESTS_H
#define SIMULATION_PRACTICE_TESTS_H

#include <cassert>
#include "car.h"
#include "repository.h"
#include "service.h"

void test_car() {
    Car c("a", "B", "c", 10);
    assert(c.get_color() == "c");
    assert(c.get_model() == "B");
    assert(c.get_registration_nr() == "a");
    assert(c.get_mileage() == 10);
}

void test_repo() {
    Repository r("/Users/maliimregergely/mig/oop-2023/simulation-practice/test_cars.txt");
    assert(r.get_all().size() == 3);
    assert(r.get_all()[0].get_registration_nr()=="Mazda");
}

void test_service(){
    Repository r("/Users/maliimregergely/mig/oop-2023/simulation-practice/test_cars.txt");
    Service s{r};
    assert(s.get_all().size()==3);
    assert(s.get_all()[0].get_registration_nr()=="Mazda");
}

void test_service_sort(){
    Repository r("/Users/maliimregergely/mig/oop-2023/simulation-practice/test_cars.txt");
    Service s{r};
    assert(s.get_sorted_by_model().at(0).get_model() == "qw1");
    assert(s.get_sorted_by_registration_nr().at(0).get_model() == "qw3");
}

void test_all() {
    test_car();
    test_repo();
    test_service();
    test_service_sort();
}

#endif //SIMULATION_PRACTICE_TESTS_H
