#ifndef STACK_H
#define STACK_H

typedef struct stack* stack_t;

void create_stack(stack_t* stck);
void destroy_stack(stack_t* stck);

int stack_reserved_space(stack_t stck);
void shrink(stack_t stck);
int stack_size(stack_t stck);

int peek(stack_t stck);
int pop(stack_t stck);
void push(stack_t stck, int value);

#endif
