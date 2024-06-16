#include <stdio.h>

#include "linkedlist.h"

int main(void) {
    linkedlist_t* list = NULL;
    initialize_list(&list);
    push_back(list, 9);
    push_front(list, 0);
    push_front(list, 1);
    push_back(list, 5);
    push_back(list, 7);
    print_list(list);
    remove_front(list);
    remove_back(list);
    insert(list, 2, 666);
    insert(list, 4, 777);
    delete(list, 1);
    print_list(list);
    set(list, 3, 1408);
    printf("Element: %d\n", get(list, 3));
    printf("Size: %d\n", list_size(list));
    destroy_list(list);
    printf("Size: %d\n", list_size(list));
    free(list);
    list = NULL;
    return 0;
}
