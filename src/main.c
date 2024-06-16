#include <stdio.h>

#include "linkedlist.h"

int main(void) {
    node_t* head = NULL;
    push_back(&head, 9);
    push_front(&head, 0);
    push_front(&head, 1);
    push_back(&head, 5);
    push_back(&head, 7);
    print_list(head);
    remove_front(&head);
    remove_back(&head);
    insert(&head, 2, 666);
    insert(&head, 4, 777);
    delete(&head, 1);
    print_list(head);
    set(head, 3, 1408);
    printf("Element: %d\n", get(head, 3));
    destroy_list(head);
    head = NULL;
    return 0;
}
