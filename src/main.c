#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"
#include "stack.h"
#include "vector.h"

int main(void) {

    struct linked_list *list = linked_list_create();
    linked_list_push_back(list, 9);
    linked_list_push_front(list, 0);
    linked_list_push_front(list, 1);
    linked_list_push_back(list, 5);
    linked_list_push_back(list, 7);
    linked_list_pop_front(list);
    linked_list_pop_back(list);
    linked_list_insert(list, 2, 666);
    linked_list_insert(list, 4, 777);
    linked_list_erase(list, 1);
    linked_list_set(list, 3, 1408);
    printf("Element: %d\n", linked_list_get(list, 3));
    printf("Size: %d\n", linked_list_size(list));
    linked_list_destroy(list);
    list = NULL;

    struct stack *stck = stack_create();
    stack_push(stck, 5);
    stack_push(stck, 7);
    stack_push(stck, 8);
    stack_push(stck, 9);
    stack_push(stck, 10);
    stack_push(stck, 12);
    stack_push(stck, 85);
    stack_push(stck, 77);
    stack_push(stck, 896);
    printf("\nStack size: %d\n", stack_size(stck));
    stack_shrink(stck);
    stack_push(stck, 15);
    stack_push(stck, 27);
    printf("Reserved size: %d\n", stack_capacity(stck));
    printf("Top element: %d\n", stack_pop(stck));
    printf("Top element: %d\n", stack_pop(stck));
    stack_destroy(stck);
    stck = NULL;

    struct vector *v = vector_create();
    vector_push_back(v, 1);
    vector_push_back(v, 3);
    vector_push_back(v, 5);
    printf("\nVector size: %d\n", vector_size(v));
    vector_clear(v);
    vector_shrink(v);
    vector_reserve(v, 1);
    vector_push_back(v, 666);
    printf("Vector capacity: %d\n", vector_capacity(v));
    printf("%d\n", vector_get(v, 0));

    return 0;
}
