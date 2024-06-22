// Following code doesn't contain error detecting and error handling

#include "stack.h"

#include <stdlib.h>

typedef struct stack {
    int size;
    int data[MAX_STACK_SIZE];
} *stack_t;

void create_stack(stack_t* stck) {
    *stck = malloc(sizeof(struct stack));
    (*stck)->size = 0;
}

void destroy_stack(stack_t* stck) {
    free(*stck);
    *stck = NULL;
}

int stack_size(stack_t stck) {
    return stck->size;
}

int peek(stack_t stck) {
    return stck->data[stck->size - 1];
}

int pop(stack_t stck) {
    stck->size--;
    return stck->data[stck->size];
}

void push(stack_t stck, int value) {
    stck->data[stck->size] = value;
    stck->size++;
}
