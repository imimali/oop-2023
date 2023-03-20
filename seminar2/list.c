//
// Created by Mali Imre Gergely on 20.03.2023.
//
#include <stdlib.h>
#include <assert.h>

#include "list.h"
#include "country.h"

#define INIT_CAPACITY 10

List *create_list(DestroyFn destroyFn, CopyFn copyFn) {
    List *list = (List *) malloc(sizeof(List));
    if (list == NULL) {
        return NULL;
    }
    list->length = 0;
    list->capacity = INIT_CAPACITY;
    list->elems = (TElem *) malloc(INIT_CAPACITY * sizeof(TElem));
    list->destroyFn = destroyFn;
    list->copyFn = copyFn;
    return list;
}

void destroy_list(List *l) {
    for (int i = 0; i < l->length; i++) {
        l->destroyFn(l->elems[i]);
    }
    free(l->elems);
    free(l);
}

void add(List *l, TElem element) {
    //TODO resize
    l->elems[l->length++] = element;

}

List *copy_list(List *l) {
    List *new_l = create_list(l->destroyFn, l->copyFn);
    for (int i = 0; i < l->length; i++) {
        new_l->elems[i] = l->copyFn(l->elems[i]);
    }
    new_l->length = l->length;
    new_l->capacity = l->capacity;
    return new_l;
}

int length(List *l) {
    return l->length;
}

TElem pop(List *l) {

    TElem elem = l->elems[l->length - 1];
    l->length -= 1;
    return elem;
}

void test_list() {
    List *l = create_list((DestroyFn) destroy_country, (CopyFn) copy_country);
    assert(l->capacity == INIT_CAPACITY);
    assert(l->length == 0);
    add(l, create_country("Spain", "Madrid", 123));
    List *other = copy_list(l);
    assert(l->length == 1);
    destroy_list(l);
    destroy_list(other);
    //TODO test more, when resize is implemented, etc.
}