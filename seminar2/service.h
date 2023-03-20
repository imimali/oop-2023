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

/// Create new service
/// \return
Service *createService();

/// Destroy service
/// \param s
void destroy_service(Service *s);

/// Add a country
/// \param s  service to add country to
/// \param country
void add_country(Service *s, Country *country);

/// Undo last operation
/// \return
int undo();

void test_service();

#endif //SEMINAR2_SERVICE_H
