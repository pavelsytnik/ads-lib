#include <stdlib.h>

#include "ADS_Stack.h"

struct ADS_Stack {
    int *array;
    int size;
    int capacity;
};

ADS_Stack *ADS_Stack_Create()
{
    ADS_Stack *stck = malloc(sizeof(ADS_Stack));
    if (!stck)
        return NULL;

    stck->array = NULL;
    stck->size = 0;
    stck->capacity = 0;

    return stck;
}

void ADS_Stack_Destroy(ADS_Stack *stck)
{
    free(stck->array);
    free(stck);
}

int ADS_Stack_IsEmpty(ADS_Stack *stck)
{
    return stck->size == 0;
}

int ADS_Stack_Size(ADS_Stack *stck)
{
    return stck->size;
}

int ADS_Stack_Capacity(ADS_Stack *stck)
{
    return stck->capacity;
}

void ADS_Stack_Reserve(ADS_Stack *stck, int new_cap)
{
    if (new_cap <= stck->capacity)
        return;

    int *new_array = realloc(stck->array, new_cap * sizeof(ADS_Stack));
    if (!new_array)
        return;

    stck->array = new_array;
    stck->capacity = new_cap;
}

void ADS_Stack_Shrink(ADS_Stack *stck)
{
    if (stck->size == stck->capacity)
        return;

    int *new_mem;

    if (stck->size == 0) {
        new_mem = NULL;
        free(stck->array);

    } else {
        new_mem = realloc(stck->array, stck->size * sizeof(ADS_Stack));
        if (!new_mem)
            return;
    }

    stck->array = new_mem;
    stck->capacity = stck->size;
}

void ADS_Stack_Clear(ADS_Stack *stck)
{
    stck->size == 0;
}

void ADS_Stack_Push(ADS_Stack *stck, int val)
{
    if (stck->capacity == 0)
        ADS_Stack_Reserve(stck, 8);
    else if (stck->capacity == stck->size)
        ADS_Stack_Reserve(stck, 2 * stck->capacity);

    stck->array[stck->size] = val;
    stck->size++;
}

int ADS_Stack_Pop(ADS_Stack *stck)
{
    if (stck->size == 0)
        return;

    return stck->array[stck->size-- - 1];
}

int ADS_Stack_Peek(ADS_Stack *stck)
{
    return stck->array[stck->size - 1];
}
