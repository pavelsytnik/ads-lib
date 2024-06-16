#include <stdlib.h>
#include <stdio.h>

#include "linkedlist.h"

typedef struct node {
    int value;
    struct node* next;
} node_t;

node_t* create_node(int value) {
    node_t* node = malloc(sizeof(node_t));
    if (!node) {
        return NULL;
    }
    node->value = value;
    node->next = NULL;
    return node;
}

void push_front(node_t** head_ref, int value) {
    node_t* node = create_node(value);
    if (!node) {
        return;
    }
    node->next = *head_ref;
    *head_ref = node;
}

void push_back(node_t** head_ref, int value) {
    node_t* new_node = create_node(value);
    if (!new_node) {
        return;
    }
    if (!*head_ref) {
        *head_ref = new_node;
        return;
    }
    node_t* node = *head_ref;
    while (node->next) {
        node = node->next;
    }
    node->next = new_node;
}

void insert(node_t** head_ref, int pos, int value) {
    if (pos < 0) {
        return;
    }
    node_t* node = *head_ref;
    if (pos == 0) {
        push_front(&node, value);
        return;
    }
    for (int i = 1; i < pos; ++i) {
        if (!node) {
            return;
        }
        node = node->next;
    }
    node_t* new_node = create_node(value);
    new_node->next = node->next;
    node->next = new_node;
}

void remove_front(node_t** head_ref) {
    if (!*head_ref) {
        return;
    }
    node_t* new_head = (*head_ref)->next;
    free(*head_ref);
    *head_ref = new_head;
}

void remove_back(node_t** head_ref) {
    if (!*head_ref) {
        return;
    }
    if (!(*head_ref)->next) {
        free(*head_ref);
        *head_ref = NULL;
        return;
    }
    node_t* node = *head_ref;
    while (node->next->next) {
        node = node->next;
    }
    free(node->next);
    node->next = NULL;
}

void delete(node_t** head_ref, int pos) {
    if (pos < 0) {
        return;
    }
    if (pos == 0) {
        remove_front(head_ref);
        return;
    }
    node_t* node = *head_ref;
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
}

// The following code has undefined behavior if the position is out of the bounds
int get(node_t* head, int pos) {
    if (pos < 0) {
        return;
    }
    node_t* node = head;
    for (int i = 0; i < pos; ++i) {
        node = node->next;
    }
    return node->value;
}

void set(node_t* head, int pos, int value) {
    if (pos < 0) {
        return;
    }
    node_t* node = head;
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

void destroy_list(node_t* head) {
    while (head) {
        node_t* temp = head->next;
        free(head);
        printf("-\n");
        head = temp;
    }
}

void print_list(node_t* head) {
    printf("</\n");
    node_t* node = head;
    while (node) {
        printf("  %d\n", node->value);
        node = node->next;
    }
    printf("/>\n");
}
