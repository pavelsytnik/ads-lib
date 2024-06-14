#include <stdlib.h>
#include <stdio.h>

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

int main(void) {
    node_t* head = NULL;
    push_back(&head, 9);
    push_front(&head, 0);
    push_front(&head, 1);
    push_back(&head, 5);
    push_back(&head, 7);
    print_list(head);
    destroy_list(head);
    head = NULL;
    return 0;
}
