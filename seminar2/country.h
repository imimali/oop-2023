//
// Created by Mali Imre Gergely on 20.03.2023.
//

#ifndef SEMINAR2_COUNTRY_H
#define SEMINAR2_COUNTRY_H

typedef struct {
    char *name;
    char *capital;
    int population;
} Country;

Country *create_country(char* name, char* capital, int population);

void destroyCountry();

Country *copy_country(Country *country);

#endif //SEMINAR2_COUNTRY_H
