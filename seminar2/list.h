//
// Created by Mali Imre Gergely on 20.03.2023.
//

#ifndef SEMINAR2_LIST_H
#define SEMINAR2_LIST_H
typedef void *TElem;

typedef void (*DestroyFn)(TElem);

typedef TElem (*CopyFn)(TElem);

typedef struct {
    int length;
    int capacity;
    TElem *elems;
    DestroyFn destroyFn;
    CopyFn copyFn;
} List;


List *create_list(DestroyFn destroyFn, CopyFn copyFn);

void destroy_list(List *l);

List *copy_list(List *l);

void add(List *l, TElem element);

void test_list();

#endif //SEMINAR2_LIST_H
