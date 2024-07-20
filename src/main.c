/* UNIVERSAL VECTOR TEST */

#include <stdio.h>
#include <stdlib.h>

#include "vector.h"

int main(void)
{
    short *vec = vector_create();

    printf("Is empty: %d\n", vector_is_empty(vec));
    printf("Size: %d\n", vector_size(vec));
    printf("Capacity: %d\n", vector_capacity(vec));

    vector_destroy(vec);
    vec = NULL;

    return 0;
}
