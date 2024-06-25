#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"
#include "stack.h"
#include "vector.h"

int main(void) {

    linked_list* list = NULL;
    linked_list_initialize(&list);
    linked_list_push_back(list, 9);
    linked_list_push_front(list, 0);
    linked_list_push_front(list, 1);
    linked_list_push_back(list, 5);
    linked_list_push_back(list, 7);
    linked_list_print(list);
    linked_list_remove_front(list);
    linked_list_remove_back(list);
    linked_list_insert(list, 2, 666);
    linked_list_insert(list, 4, 777);
    linked_list_delete(list, 1);
    linked_list_print(list);
    linked_list_set(list, 3, 1408);
    printf("Element: %d\n", linked_list_get(list, 3));
    printf("Size: %d\n", linked_list_size(list));
    linked_list_destroy(list);
    printf("Size: %d\n", linked_list_size(list));
    free(list);
    list = NULL;

    stack* stck = NULL;
    stack_create(&stck);
    stack_push(stck, 5);
    stack_push(stck, 7);
    stack_push(stck, 7);
    stack_push(stck, 7);
    stack_push(stck, 7);
    stack_push(stck, 7);
    stack_push(stck, 7);
    stack_push(stck, 7);
    stack_push(stck, 7);
    printf("\nStack size: %d\n", stack_size(stck));
    stack_shrink(stck);
    stack_push(stck, 15);
    stack_push(stck, 27);
    printf("Reserved size: %d\n", stack_reserved_space(stck));
    printf("Top element: %d\n", stack_peek(stck));
    stack_destroy(&stck);

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

    return 0;
}
