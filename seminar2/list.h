//
// Created by Mali Imre Gergely on 20.03.2023.
//

#ifndef SEMINAR2_LIST_H
#define SEMINAR2_LIST_H
typedef void *TElem;

typedef struct {
    int length;
    int capacity;
    TElem *elems;
} List;

typedef void (*DestroyFn)(TElem);

List *create(DestroyFn destroyFn);

void destroy();


void test_list();

#endif //SEMINAR2_LIST_H
