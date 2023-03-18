//
// Created by Mali Imre Gergely on 02.03.2023.
//
#include <stdio.h>
#include <stdlib.h>


int main() {
    int numbers[100];
    // a static array has the same value as its address
    printf("Address of numbers: %x and value of numbers: %x is the same\n", numbers, &numbers);

    int *numbers_on_heap = malloc(sizeof(int) * 100);
    // a dynamically allocated array has a different value from the variable's address
    printf("Address of numbers on heap: %x and value of numbers on heap: %x is not the same\n", numbers_on_heap,
           &numbers_on_heap);

    int *numbers_address = &numbers;
    // the variable `numbers_address` has a different address from the value it points to, which is `numbers`
    printf("Just like address of numbers_address: %x and value of numbers: %x are different\n", &numbers_address,
           numbers);
    return 0;
}
