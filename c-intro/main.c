//
// Created by Mali Imre Gergely on 02.03.2023.
//
#include <stdio.h>

typedef struct {
    int age;
    char name[20];
} Person;

int main() {
    Person p;
    Person people[100];
    printf("One p takes: %lu bytes\n", sizeof p);
    printf("%lu ps take: %lu bytes\n", sizeof people / sizeof p, sizeof people);
    printf("One address takes: sizeof &p = %lu, sizeof &people=%lu. No matter the type, an address is an address\n",
           sizeof &p, sizeof &people); // although clang tidy will complain

    int i;
    char c;
    long l;
    float f;
    double d;
    printf("These all take: int %lu, char %lu, long %lu, float %lu, double %lu\n", sizeof i, sizeof c, sizeof l,
           sizeof f, sizeof d);
    return 0;
}
