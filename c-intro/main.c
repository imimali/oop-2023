//
// Created by Mali Imre Gergely on 02.03.2023.
//
#include <stdio.h>

struct Person {
    int age;
    char name[20];
};

// typedef <existing type> <alias> where now existing type is `struct Person` and alias is `Person1`;
typedef struct Person Person1;

// analogously

typedef struct {
    int age;
    char name[20];
} Person2;

// where existing type now is struct { ... } and alias is Person2


int main() {
    struct Person p;
    Person1 p1; // but no Person p;
    printf("Hello world!\n");
    return 0;
}
