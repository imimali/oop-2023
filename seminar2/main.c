#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    char *name;
    char *capital;
    int population;
} Country;

void f() {

    int n = 2, m = 3;
    char *names[2][3] = {{"Romania", "Bulgaria", "Croatia"},
                         {"Russia",  "China",    "Indonesia"}};

    char *capitals[2][3] = {{"Bucharest", "Sofia",   "Zagreb"},
                            {"Moscow",    "Beijing", "Djakarta"}};
    Country **countries = (Country **) malloc(n * sizeof(Country *));
    for (int i = 0; i < n; i++) {
        countries[i] = (Country *) malloc(m * sizeof(Country));
        for (int j = 0; j < m; j++) {
            countries[i][j].name = (char *) malloc(sizeof(char) * strlen(names[i][j]) + 1);
            strcpy(countries[i][j].name, names[i][j]);

            countries[i][j].capital = (char *) malloc(sizeof(char) * strlen(capitals[i][j]) + 1);
            strcpy(countries[i][j].capital, capitals[i][j]);

            countries[i][j].population = i + j;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            free(countries[i][j].name);
            free(countries[i][j].capital);
        }
        free(countries[i]);
    }
    free(countries);
}

int main() {

    f();
    getchar();
    getchar();
    return 0;

}