#include <stdlib.h>
#include <stddef.h>

#include "vector.h"

struct vector_header {
    int size;
    int capacity;
};

void *vector_create()
{
    struct vector_header *metadata = malloc(sizeof(struct vector_header));
    metadata->size = 0;
    metadata->capacity = 0;

    return ++metadata;
}

void vector_destroy(void *vector)
{
    free((size_t)vector - sizeof(struct vector_header));
}

int vector_is_empty(void *vector)
{
    return ((struct vector_header*)vector - 1)->size == 0;
}

int vector_size(void *vector)
{
    return ((struct vector_header*)vector - 1)->size;
}

int vector_capacity(void *vector)
{
    return ((struct vector_header*)vector - 1)->capacity;
}

//void vector_reserve(struct vector *vec, int new_cap)
//{
//    if (new_cap <= vec->capacity)
//        return;
//
//    int *new_array = realloc(vec->array, new_cap * sizeof(struct vector));
//    if (!new_array)
//        return;
//
//    vec->array = new_array;
//    vec->capacity = new_cap;
//}
//
//void vector_shrink(struct vector *vec)
//{
//    if (vec->size == vec->capacity)
//        return;
//
//    int *new_mem;
//
//    if (vec->size == 0) {
//        new_mem = NULL;
//        free(vec->array);
//
//    } else {
//        new_mem = realloc(vec->array, vec->size * sizeof(struct vector));
//        if (!new_mem)
//            return;
//    }
//
//    vec->array = new_mem;
//    vec->capacity = vec->size;
//}
//
//void vector_clear(struct vector *vec)
//{
//    vec->size = 0;
//}
//
//void vector_push_back(struct vector *vec, int val)
//{
//    if (vec->capacity == 0)
//        vector_reserve(vec, 8);
//    else if (vec->capacity == vec->size)
//        vector_reserve(vec, 2 * vec->capacity);
//
//    vec->array[vec->size] = val;
//    vec->size++;
//}
//
//void vector_pop_back(struct vector *vec)
//{
//    if (vec->size == 0)
//        return;
//
//    vec->size--;
//}
//
//void vector_set(struct vector *vec, int pos, int val)
//{
//    if (pos < 0 || pos >= vec->size)
//        return;
//
//    vec->array[pos] = val;
//}
//
//int vector_get(struct vector *vec, int pos)
//{
//    if (pos < 0 || pos >= vec->size)
//        return;
//
//    return vec->array[pos];
//}
