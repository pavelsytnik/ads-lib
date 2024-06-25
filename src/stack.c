// Following code doesn't contain error detecting and error handling

#include "stack.h"

#include <stdlib.h>

typedef struct stack {
    int size;
    int reserved;
    int* arr;
} stack;

void stack_create(stack** stck) {
    *stck = malloc(sizeof(struct stack));
    (*stck)->size = 0;
    (*stck)->reserved = 0;
    (*stck)->arr = NULL;
}

void stack_destroy(stack** stck) {
    free((*stck)->arr);
    free(*stck);
    *stck = NULL;
}

int stack_reserved_space(stack* stck) {
    return stck->reserved;
}

int stack_size(stack* stck) {
    return stck->size;
}

void stack_shrink(stack* stck) {
    stck->arr = realloc(stck->arr, sizeof(int) * stck->size);
    stck->reserved = stck->size;
}

int stack_peek(stack* stck) {
    return stck->arr[stck->size - 1];
}

int stack_pop(stack* stck) {
    stck->size--;
    return stck->arr[stck->size];
}

void reserve(stack* stck, int i) {
    if (stck->reserved == 0) {
        stck->arr = malloc(sizeof(int) * i);
    } else {
        stck->arr = realloc(stck->arr, sizeof(int) * i);
    }
    stck->reserved = i;
}

void stack_push(stack* stck, int value) {
    if (stck->reserved == 0) {
        reserve(stck, 8);
    } else if (stck->reserved == stck->size) {
        reserve(stck, stck->size * 2);
    }
    stck->arr[stck->size] = value;
    stck->size++;
}
