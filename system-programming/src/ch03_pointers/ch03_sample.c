#include <stdlib.h>
#include <stdio.h>

#include "ch03_pointers/ch03_sample.h"

void demo_malloc(void) {
    int *p = malloc(sizeof(int));
    if (!p) {
        return;
    }

    *p = 42;
    printf("value = %d\n", *p);
    free(p);
}
