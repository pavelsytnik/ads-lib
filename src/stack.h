#ifndef STACK_H
#define STACK_H

typedef struct stack stack;

void stack_create(stack** stck);
void stack_destroy(stack** stck);

int stack_reserved_space(stack* stck);
void stack_shrink(stack* stck);
int stack_size(stack* stck);

int stack_peek(stack* stck);
int stack_pop(stack* stck);
void stack_push(stack* stck, int value);

#endif
