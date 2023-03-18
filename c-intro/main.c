//
// Created by Mali Imre Gergely on 02.03.2023.
//
#include <stdio.h>

int f(int a) {
    // a different address from the original argument's address, the same value
    printf("Address of a: %x, value of a: %d\n", &a, a);
    a += 1;//no effect on original
    return a;
}

void f_that_can_modify(int *a) {
    // all arguments are passed by value, we can mutate values from outside the original scope of the function
    // by passing an address - still by value.
    printf("Address of a: %x, value of a: %x\n", &a, a);
    *a += 1; // dereference
}


int main() {
    int k = 9;
    printf("Address of k: %x, value of k: %d\n", &k, k);
    int from_f = f(k);
    // yet another address, same value
    printf("Address of from_f: %x, value of from_f: %d\n", &from_f, from_f);
    printf("Address of k after calling f: %x, value of k: %d\n", &k, k);

    f_that_can_modify(&k);
    printf("Address of k after calling f that can modify: %x, value of k: %d\n", &k, k);
    return 0;
}
