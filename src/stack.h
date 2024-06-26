#ifndef STACK_H
#define STACK_H

struct stack;

struct stack *stack_create();
void stack_destroy(struct stack *stck);

int stack_is_empty(struct stack *stck);
int stack_size(struct stack *stck);
int stack_capacity(struct stack *stck);
void stack_reserve(struct stack *stck, int new_cap);
void stack_shrink(struct stack *stck);

void stack_clear(struct stack *stck);
void stack_push(struct stack *stck, int val);
int stack_pop(struct stack *stck);
int stack_peek(struct stack *stck);

#endif
