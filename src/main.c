/* UNIVERSAL VECTOR TEST */

#include <stdio.h>
#include <stdlib.h>

#include "vector.h"

int main(void)
{
    short *vec = NULL;
    vector_create(vec);

    printf("Is empty: %d\n", vector_is_empty(vec));
    printf("Size: %d\n", vector_size(vec));
    printf("Capacity: %d\n", vector_capacity(vec));

    vector_reserve(vec, 58);
    printf("Capacity: %d\n", vector_capacity(vec));

    /* NOT SUPPOSED TO BE DONE LIKE THAT BECAUSE THE SIZE IS STILL ZERO */
    vec[5] = 1785;
    printf("vec[5]: %d\n", vec[5]);

    vector_destroy(vec);

    return 0;
}
