//
// Created by Mali Imre Gergely on 20.03.2023.
//
#include <stdlib.h>
#include <string.h>
#include "country.h"

Country *create_country(char *name, char *capital, int population) {
    Country *country = (Country *) malloc(sizeof(Country));

    country->name = (char *) malloc(sizeof(char) * strlen(name) + 1);
    strcpy(country->name, name);

    country->capital = (char *) malloc(sizeof(char) * strlen(capital) + 1);
    strcpy(country->capital, capital);

    country->population = population;

    return country;

}

void destroy_country(Country *country) {
    free(country->name);
    free(country->capital);
    free(country);
}

Country *copy_country(Country *country) {

    Country *new_country = (Country *) malloc(sizeof(Country));

    new_country->name = (char *) malloc(sizeof(char) * strlen(country->name) + 1);
    strcpy(country->name, country->name);

    new_country->capital = (char *) malloc(sizeof(char) * strlen(country->capital) + 1);
    strcpy(country->capital, country->capital);

    new_country->population = country->population;

    return new_country;

}
