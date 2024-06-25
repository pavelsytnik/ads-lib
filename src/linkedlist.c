#include <stdlib.h>
#include <stdio.h>

#include "linkedlist.h"

typedef struct node {
    int value;
    struct node* next;
} node;

typedef struct linked_list {
    struct node* head;
    int size;
} linked_list;

void linked_list_initialize(linked_list** list_ptr) {
    *list_ptr = malloc(sizeof(linked_list));
    (*list_ptr)->head = NULL;
    (*list_ptr)->size = 0;
}

int linked_list_size(linked_list* list) {
    return list->size;
}

static node* node_create(int value) {
    node* node = malloc(sizeof(struct node));
    if (!node) {
        return NULL;
    }
    node->value = value;
    node->next = NULL;
    return node;
}

void linked_list_push_front(linked_list* list, int value) {
    node* node = node_create(value);
    if (!node) {
        return;
    }
    node->next = list->head;
    list->head = node;
    list->size++;
}

void linked_list_push_back(linked_list* list, int value) {
    node* new_node = node_create(value);
    if (!new_node) {
        return;
    }
    if (!list->head) {
        list->head = new_node;
        list->size++;
        return;
    }
    node* node = list->head;
    while (node->next) {
        node = node->next;
    }
    node->next = new_node;
    list->size++;
}

void linked_list_insert(linked_list* list, int pos, int value) {
    if (pos < 0) {
        return;
    }
    if (pos == 0) {
        linked_list_push_front(list, value);
        return;
    }
    node* node = list->head;
    for (int i = 1; i < pos; ++i) {
        if (!node) {
            return;
        }
        node = node->next;
    }
    struct node* new_node = node_create(value);
    new_node->next = node->next;
    node->next = new_node;
    list->size++;
}

void linked_list_remove_front(linked_list* list) {
    if (!list->head) {
        return;
    }
    struct node* new_head = list->head->next;
    free(list->head);
    list->head = new_head;
    list->size--;
}

void linked_list_remove_back(linked_list* list) {
    if (!list->head) {
        return;
    }
    if (!list->head->next) {
        free(list->head);
        list->head = NULL;
        list->size--;
        return;
    }
    node* node = list->head;
    while (node->next->next) {
        node = node->next;
    }
    free(node->next);
    node->next = NULL;
    list->size--;
}

void linked_list_delete(linked_list* list, int pos) {
    if (pos < 0) {
        return;
    }
    if (pos == 0) {
        linked_list_remove_front(list);
        return;
    }
    node* node = list->head;
    for (int i = 1; i < pos; ++i) {
        if (!node) {
            return;
        }
        node = node->next;
    }
    if (!node->next) {
        return;
    }
    struct node* temp = node->next->next;
    free(node->next);
    node->next = temp;
    list->size--;
}

// The following code has undefined behavior if the position is out of the bounds
int linked_list_get(linked_list* list, int pos) {
    if (pos < 0) {
        return;
    }
    node* node = list->head;
    for (int i = 0; i < pos; ++i) {
        node = node->next;
    }
    return node->value;
}

void linked_list_set(linked_list* list, int pos, int value) {
    if (pos < 0) {
        return;
    }
    node* node = list->head;
    for (int i = 0; i < pos; ++i) {
        if (!node) {
            return;
        }
        node = node->next;
    }
    if (!node) {
        return;
    }
    node->value = value;
}

void linked_list_destroy(linked_list* list) {
    while (list->head) {
        node* temp = list->head->next;
        free(list->head);
        printf("-\n");
        list->head = temp;
    }
    list->head = NULL;
    list->size = 0;
}

void linked_list_print(linked_list* list) {
    printf("</\n");
    node* node = list->head;
    while (node) {
        printf("  %d\n", node->value);
        node = node->next;
    }
    printf("/>\n");
}
