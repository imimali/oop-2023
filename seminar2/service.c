//
// Created by Mali Imre Gergely on 20.03.2023.
//
#include <stdlib.h>
#include "service.h"
#include "country.h"
#include "list.h"

Service *createService() {
    Service *s = (Service *) malloc(sizeof(Service));
    s->elements = create_list(destroy_country, (CopyFn) copy_country);
    s->undoList = create_list((DestroyFn) destroy_list, (CopyFn) copy_list);
    return s;
}

void destroy_service(Service *s) {
    destroy_list(s->elements);
    destroy_list(s->undoList);
    free(s);
}

void add_country(Service *s, Country *country) {
    List *copy = copy_list(s->elements);
    add(s->undoList, copy);

    add(s->elements, country);
}

int undo(Service *service) {
    if (length(service->undoList) == 0) {
        return 1;
    }
    List *l = pop(service->undoList);
    destroy_list(service->elements);
    service->elements = l;
    return 0;
}

void test_service() {
    Service *s = createService();
    add_country(s, create_country("Portugal", "Lisbon", 34));

    undo(s);
    //TODO test more: test if deallocation is successful with a non-empty undo-stack, etc.
    destroy_service(s);
}
