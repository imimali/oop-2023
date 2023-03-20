//
// Created by Mali Imre Gergely on 20.03.2023.
//
#include <stdlib.h>
#include <assert.h>

#include "list.h"

#define INIT_CAPACITY 10

List *create() {
    List *list = (List *) malloc(sizeof(List));
    if (list == NULL) {
        return NULL;
    }
    list->length = 0;
    list->capacity = INIT_CAPACITY;
    list->elems = (TElem *) malloc(INIT_CAPACITY * sizeof(TElem));
    return list;
}

void destroy(List *l) {
    //TODO deallocate the rest
    free(l);
}

void test_list() {
    List *l = create((DestroyFn) destroy);
    assert(l->capacity == INIT_CAPACITY);
    assert(l->length == 0);

}