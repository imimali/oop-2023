//
// Created by Mali Imre Gergely on 20.03.2023.
//

#ifndef SEMINAR2_LIST_H
#define SEMINAR2_LIST_H
typedef void *TElem;

typedef void (*DestroyFn)(TElem);

typedef struct {
    int length;
    int capacity;
    TElem *elems;
    DestroyFn destroyFn;
} List;


List *create_list(DestroyFn destroyFn);

void destroy();

void add(TElem element);

void test_list();

#endif //SEMINAR2_LIST_H
