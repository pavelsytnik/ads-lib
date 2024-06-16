#include <stdlib.h>
#include <stdio.h>

#include "linkedlist.h"

typedef struct node {
    int value;
    struct node* next;
} node_t;

struct linkedlist {
    node_t* head;
    int size;
};

void initialize_list(linkedlist_t** list_ptr) {
    *list_ptr = malloc(sizeof(linkedlist_t));
    (*list_ptr)->head = NULL;
    (*list_ptr)->size = 0;
}

int list_size(linkedlist_t* list) {
    return list->size;
}

node_t* create_node(int value) {
    node_t* node = malloc(sizeof(node_t));
    if (!node) {
        return NULL;
    }
    node->value = value;
    node->next = NULL;
    return node;
}

void push_front(linkedlist_t* list, int value) {
    node_t* node = create_node(value);
    if (!node) {
        return;
    }
    node->next = list->head;
    list->head = node;
    list->size++;
}

void push_back(linkedlist_t* list, int value) {
    node_t* new_node = create_node(value);
    if (!new_node) {
        return;
    }
    if (!list->head) {
        list->head = new_node;
        list->size++;
        return;
    }
    node_t* node = list->head;
    while (node->next) {
        node = node->next;
    }
    node->next = new_node;
    list->size++;
}

void insert(linkedlist_t* list, int pos, int value) {
    if (pos < 0) {
        return;
    }
    if (pos == 0) {
        push_front(list, value);
        return;
    }
    node_t* node = list->head;
    for (int i = 1; i < pos; ++i) {
        if (!node) {
            return;
        }
        node = node->next;
    }
    node_t* new_node = create_node(value);
    new_node->next = node->next;
    node->next = new_node;
    list->size++;
}

void remove_front(linkedlist_t* list) {
    if (!list->head) {
        return;
    }
    node_t* new_head = list->head->next;
    free(list->head);
    list->head = new_head;
    list->size--;
}

void remove_back(linkedlist_t* list) {
    if (!list->head) {
        return;
    }
    if (!list->head->next) {
        free(list->head);
        list->head = NULL;
        list->size--;
        return;
    }
    node_t* node = list->head;
    while (node->next->next) {
        node = node->next;
    }
    free(node->next);
    node->next = NULL;
    list->size--;
}

void delete(linkedlist_t* list, int pos) {
    if (pos < 0) {
        return;
    }
    if (pos == 0) {
        remove_front(list);
        return;
    }
    node_t* node = list->head;
    for (int i = 1; i < pos; ++i) {
        if (!node) {
            return;
        }
        node = node->next;
    }
    if (!node->next) {
        return;
    }
    node_t* temp = node->next->next;
    free(node->next);
    node->next = temp;
    list->size--;
}

// The following code has undefined behavior if the position is out of the bounds
int get(linkedlist_t* list, int pos) {
    if (pos < 0) {
        return;
    }
    node_t* node = list->head;
    for (int i = 0; i < pos; ++i) {
        node = node->next;
    }
    return node->value;
}

void set(linkedlist_t* list, int pos, int value) {
    if (pos < 0) {
        return;
    }
    node_t* node = list->head;
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

void destroy_list(linkedlist_t* list) {
    while (list->head) {
        node_t* temp = list->head->next;
        free(list->head);
        printf("-\n");
        list->head = temp;
    }
    list->head = NULL;
    list->size = 0;
}

void print_list(linkedlist_t* list) {
    printf("</\n");
    node_t* node = list->head;
    while (node) {
        printf("  %d\n", node->value);
        node = node->next;
    }
    printf("/>\n");
}
