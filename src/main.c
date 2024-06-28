#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"
#include "stack.h"
#include "vector.h"

int main(void)
{
    struct linked_list *list = linked_list_create();

    linked_list_push_back(list, 0);
    linked_list_push_back(list, 1);
    linked_list_push_back(list, 2);
    linked_list_push_back(list, 3);
    linked_list_push_back(list, 4);

    for (int i = 0; i < linked_list_size(list); i++) {
        printf("%d ", linked_list_get(list, i));
    }
    printf("\n");

    linked_list_reverse(list);

    for (int i = 0; i < linked_list_size(list); i++) {
        printf("%d ", linked_list_get(list, i));
    }

    linked_list_destroy(list);
    list = NULL;

    return 0;
}
