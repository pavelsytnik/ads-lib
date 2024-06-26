#include <stdlib.h>

#include "stack.h"

struct stack {
    int *array;
    int size;
    int capacity;
};

struct stack *stack_create()
{
    struct stack *stck = malloc(sizeof(struct stack));
    if (!stck)
        return NULL;

    stck->array = NULL;
    stck->size = 0;
    stck->capacity = 0;

    return stck;
}

void stack_destroy(struct stack *stck)
{
    free(stck->array);
    free(stck);
}

int stack_is_empty(struct stack *stck)
{
    return stck->size == 0;
}

int stack_size(struct stack *stck)
{
    return stck->size;
}

int stack_capacity(struct stack *stck)
{
    return stck->capacity;
}

void stack_reserve(struct stack *stck, int new_cap)
{
    if (new_cap <= stck->capacity)
        return;

    int *new_array = realloc(stck->array, new_cap * sizeof(struct stack));
    if (!new_array)
        return;

    stck->array = new_array;
    stck->capacity = new_cap;
}

void stack_shrink(struct stack *stck)
{
    if (stck->size == stck->capacity)
        return;

    int *new_mem;

    if (stck->size == 0) {
        new_mem = NULL;
        free(stck->array);

    } else {
        new_mem = realloc(stck->array, stck->size * sizeof(struct stack));
        if (!new_mem)
            return;
    }

    stck->array = new_mem;
    stck->capacity = stck->size;
}

void stack_clear(struct stack *stck)
{
    stck->size == 0;
}

void stack_push(struct stack *stck, int val)
{
    if (stck->capacity == 0)
        stack_reserve(stck, 8);
    else if (stck->capacity == stck->size)
        stack_reserve(stck, 2 * stck->capacity);

    stck->array[stck->size] = val;
    stck->size++;
}

int stack_pop(struct stack *stck)
{
    if (stck->size == 0)
        return;

    return stck->array[stck->size-- - 1];
}

int stack_peek(struct stack *stck)
{
    return stck->array[stck->size - 1];
}
