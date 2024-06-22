// Following code doesn't contain error detecting and error handling

#include "stack.h"

#include <stdlib.h>

typedef struct stack {
    int size;
    int reserved;
    int* arr;
} *stack_t;

void create_stack(stack_t* stck) {
    *stck = malloc(sizeof(struct stack));
    (*stck)->size = 0;
    (*stck)->reserved = 0;
    (*stck)->arr = NULL;
}

void destroy_stack(stack_t* stck) {
    free((*stck)->arr);
    free(*stck);
    *stck = NULL;
}

int stack_reserved_space(stack_t stck) {
    return stck->reserved;
}

int stack_size(stack_t stck) {
    return stck->size;
}

int peek(stack_t stck) {
    return stck->arr[stck->size - 1];
}

int pop(stack_t stck) {
    stck->size--;
    return stck->arr[stck->size];
}

void reserve(stack_t stck, int i) {
    if (stck->reserved == 0) {
        stck->arr = malloc(sizeof(int) * i);
    } else {
        stck->arr = realloc(stck->arr, sizeof(int) * i);
    }
    stck->reserved = i;
}

void push(stack_t stck, int value) {
    if (stck->reserved == 0) {
        reserve(stck, 8);
    } else if (stck->reserved == stck->size) {
        reserve(stck, stck->size * 2);
    }
    stck->arr[stck->size] = value;
    stck->size++;
}
