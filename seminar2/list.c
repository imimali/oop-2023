//
// Created by Mali Imre Gergely on 20.03.2023.
//
#include <stdlib.h>
#include <assert.h>

#include "list.h"

#define INIT_CAPACITY 10

List *create_list(DestroyFn destroyFn) {
    List *list = (List *) malloc(sizeof(List));
    if (list == NULL) {
        return NULL;
    }
    list->length = 0;
    list->capacity = INIT_CAPACITY;
    list->elems = (TElem *) malloc(INIT_CAPACITY * sizeof(TElem));
    list->destroyFn = destroyFn;
    return list;
}

void destroy_list(List *l) {
    for (int i = 0; i < l->length; i++) {
        l->destroyFn(l->elems[i]);
    }
    free(l->elems);
    free(l);
}

void add(TElem element) {

}

void test_list() {
    List *l = create_list((DestroyFn) destroy_list);
    assert(l->capacity == INIT_CAPACITY);
    assert(l->length == 0);
    destroy_list(l);
}