#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct Element {
    char *name;
    int value;
} Element;

int main() {
    int rows = 2, columns = 3;

    char *names[2][3] = {{"Simon Petrikov", "Finn", "Jake"},
                         {"A",              "B",    "C"}};

    // allocate the structure containing pointers to Elements. `elements` is a pointer to a pointer of Elements,
    // because it will contain(point to) rows of the matrix, which are actually pointers to Elements.
    Element **elements = (Element **) malloc(sizeof(Element *) * rows);
    for (int i = 0; i < rows; i++) {
        // each row will contain Elements, we need a pointer to that area
        elements[i] = (Element *) malloc(sizeof(Element) * columns);

        for (int j = 0; j < columns; j++) {
            // each name will be dynamically allocated.
            elements[i][j].name = (char *) malloc(sizeof(char) * strlen(names[i][j]));
            elements[i][j].value = i + j;
            strcpy(elements[i][j].name, names[i][j]);
        }
    }
    // deallocate bottom-up:
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            free(elements[i][j].name);
        }
        free(elements[i]);
    }
    free(elements);
}