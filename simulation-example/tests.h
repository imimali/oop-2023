//
// Created by Mali Imre Gergely on 22.05.2023.
//

#ifndef SIMULATION_EXAMPLE_TESTS_H
#define SIMULATION_EXAMPLE_TESTS_H

#include "assert.h"
#include "car.h"
#include "repository.h"
#include "service.h"

void test_car() {
    Car c{"cj-123", "mazda", "black", 100};
    assert(c.get_registration_nr() == "cj-123");
    assert(c.get_color() == "black");
    assert(c.get_model() == "mazda");
    assert(c.get_mileage() == 100);
}

void test_repo_get_all() {
    Repository r{"/Users/maliimregergely/mig/oop-2023/simulation-example/test_cars.txt"};
    auto all = r.get_all();
    assert(all.at(0).get_registration_nr() == "cj-123");
    assert(all.at(1).get_registration_nr() == "bh-456");
    assert(all.at(2).get_registration_nr() == "gh-356");
    assert(all.at(3).get_registration_nr() == "cj-111");
}

void test_service_get_all() {
    Repository r{"/Users/maliimregergely/mig/oop-2023/simulation-example/test_cars.txt"};
    Service s{r};
    auto all = s.get_all();
    assert(all.at(0).get_registration_nr() == "cj-123");
    assert(all.at(1).get_registration_nr() == "bh-456");
    assert(all.at(2).get_registration_nr() == "gh-356");
    assert(all.at(3).get_registration_nr() == "cj-111");
}

void test_service_get_sorted_by_model() {
    Repository r{"/Users/maliimregergely/mig/oop-2023/simulation-example/test_cars.txt"};
    Service s{r};
    auto all = s.get_sorted_by_model();
    assert(all.at(0).get_model() == "bmw");
    assert(all.at(1).get_model() == "ford");
    assert(all.at(2).get_model() == "mazda");
    assert(all.at(3).get_model() == "ww");
}

void test_service_get_sorted_by_registration_nr() {
    Repository r{"/Users/maliimregergely/mig/oop-2023/simulation-example/test_cars.txt"};
    Service s{r};
    auto all = s.get_sorted_by_registration_nr();
    assert(all.at(0).get_registration_nr() == "bh-456");
    assert(all.at(1).get_registration_nr() == "cj-111");
    assert(all.at(2).get_registration_nr() == "cj-123");
    assert(all.at(3).get_registration_nr() == "gh-356");
}

void test_service_get_filtered_by_mileage() {
    Repository r{"/Users/maliimregergely/mig/oop-2023/simulation-example/test_cars.txt"};
    Service s{r};
    auto all = s.get_filtered_by_mileage(500);
    assert(all.at(0).get_registration_nr() == "cj-123");
    assert(all.at(1).get_registration_nr() == "gh-356");
}

void test_all() {
    test_car();
    test_repo_get_all();
    test_service_get_all();
    test_service_get_sorted_by_model();
    test_service_get_sorted_by_registration_nr();
    test_service_get_filtered_by_mileage();
}

#endif //SIMULATION_EXAMPLE_TESTS_H
