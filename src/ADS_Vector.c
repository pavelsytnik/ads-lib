#include <stdlib.h>

#include "ADS_Vector.h"

struct ADS_Vector {
    int *array;
    int size;
    int capacity;
};

ADS_Vector *ADS_Vector_Create()
{
    ADS_Vector *vec = malloc(sizeof(ADS_Vector));
    vec->array = NULL;
    vec->size = 0;
    vec->capacity = 0;

    return vec;
}

void ADS_Vector_Destroy(ADS_Vector *vec)
{
    free(vec->array);
    free(vec);
}

int ADS_Vector_IsEmpty(ADS_Vector *vec)
{
    return vec->size == 0;
}

int ADS_Vector_Size(ADS_Vector *vec)
{
    return vec->size;
}

int ADS_Vector_Capacity(ADS_Vector *vec)
{
    return vec->capacity;
}

void ADS_Vector_Reserve(ADS_Vector *vec, int new_cap)
{
    if (new_cap <= vec->capacity)
        return;

    int *new_array = realloc(vec->array, new_cap * sizeof(ADS_Vector));
    if (!new_array)
        return;

    vec->array = new_array;
    vec->capacity = new_cap;
}

void ADS_Vector_Shrink(ADS_Vector *vec)
{
    if (vec->size == vec->capacity)
        return;

    int *new_mem;

    if (vec->size == 0) {
        new_mem = NULL;
        free(vec->array);

    } else {
        new_mem = realloc(vec->array, vec->size * sizeof(ADS_Vector));
        if (!new_mem)
            return;
    }

    vec->array = new_mem;
    vec->capacity = vec->size;
}

void ADS_Vector_Clear(ADS_Vector *vec)
{
    vec->size = 0;
}

void ADS_Vector_PushBack(ADS_Vector *vec, int val)
{
    if (vec->capacity == 0)
        ADS_Vector_Reserve(vec, 8);
    else if (vec->capacity == vec->size)
        ADS_Vector_Reserve(vec, 2 * vec->capacity);

    vec->array[vec->size] = val;
    vec->size++;
}

void ADS_Vector_PopBack(ADS_Vector *vec)
{
    if (vec->size == 0)
        return;

    vec->size--;
}

void ADS_Vector_Set(ADS_Vector *vec, int pos, int val)
{
    if (pos < 0 || pos >= vec->size)
        return;

    vec->array[pos] = val;
}

int ADS_Vector_Get(ADS_Vector *vec, int pos)
{
    if (pos < 0 || pos >= vec->size)
        return;

    return vec->array[pos];
}
