//
// Created by Mali Imre Gergely on 20.03.2023.
//

#ifndef SEMINAR2_SERVICE_H
#define SEMINAR2_SERVICE_H

#include "list.h"
#include "country.h"

typedef struct {
    List *elements;
    List *undoList;

} Service;

Service *createService();


void destroy_service(Service *s);

void add_country(Service *s, Country *country);

void test_service();

#endif //SEMINAR2_SERVICE_H
