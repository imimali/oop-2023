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

/// Create a new country
/// \param name
/// \param capital
/// \param population
/// \return
Country *create_country(char *name, char *capital, int population);

///Destroy country
void destroy_country();


///Copy country
Country *copy_country(Country *country);

#endif //SEMINAR2_COUNTRY_H
