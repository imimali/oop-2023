# Seminar 3

## Warming up: the arrays  example revisited

So you'll probably encounter situations when you'll read a sequence of characters like this:

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    char characters[100];
    printf("Enter some characters: ");
    scanf("%s", characters);
    printf("You have read: %s", characters);
    return 0;
}
```

All good right now. Some of you, however might read it like:

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    char characters[100];
    printf("Enter some characters: ");
    scanf("%s", &characters);
    printf("You have read: %s", characters);
    return 0;
}
```

And get away with it. It works, all good, you can cash in the points for the first iteration.
But then the dreaded second iteration with the dynamic allocation comes, so you
change your implementation to this:

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    char *characters;
    characters = (char *) malloc(sizeof(char) * 100);
    printf("Enter some characters: ");
    scanf("%s", &characters);
    printf("You have read: %s", characters);
    return 0;
}
```

To your surprise, it crashed and burns. It's time to revisit the basics
of [addresses and pointers](https://github.com/imimali/oop-2023/tree/master/c-intro#further-on-pointers-to-static-and-dynamic-arrays).

## Dynamic allocation

Find some info about [malloc, calloc, realloc](https://man7.org/linux/man-pages/man3/malloc.3.html), etc.
[Everything you allocate you must also deallocate](https://youtu.be/guuYU74wU70?t=70).

A basic example:

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    char *characters;
    characters = (char *) malloc(sizeof(char) * 100);
    printf("Enter some characters: ");
    scanf("%s", characters);
    printf("You have read: %s", characters);
    free(characters);
    return 0;
}
```

Note however, that malloc by itself only allocates a number of bytes that can be
arbitrary, you could well do `malloc(1234)`. We just want that size
to be consistent with what we want to store in the allocated area, that's why we
multiply with the size of the desired type x how many of those we want to store at most.
It returns a `void*`, that's why we need the cast.

## A deeper dive
Let's say we have some `Element`s. Each element has a type, which is an array of characters, and a value, an int.
We want to have a matrix of such Elements, everything on the heap, nicely dinamically allocated.
The following code snippet achieves this:
```c
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
    // TODO deallocate
}
```

Question: how much memory did we actually allocate in bytes?


Deallocation:
```c
// deallocate bottom-up:
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            free(elements[i][j].name);
        }
        free(elements[i]);
    }
    free(elements);
```

The whole thing looks like this in memory:

![memory_scheme](/pics/memory_scheme.png)

## More on how memory is laid out
Say we have the following:
```c
typedef struct {
    char name[20];
    int a;
    float b;
} Element;

Element *elements = (Element *) malloc(sizeof(Element) * 3);
```
This would look something like this in memory
![memory_scheme](/pics/memory_scheme_2.png)

But then we could have something like:
```c
typedef struct {
    char* name;
    int a;
    float b;
} Element;

Element *elements = (Element *) malloc(sizeof(Element) * 3);
```
![memory_scheme](/pics/memory_scheme_3.png)

Note how only the area containing the address is in the contiguous part
of the memory zone of one `Element`. 

