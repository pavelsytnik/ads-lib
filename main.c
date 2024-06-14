#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int value;
    struct node* next;
} node_t;

void push_front(node_t** head_ref, int value) {
    node_t* node = malloc(sizeof(node_t));
    if (!node) {
        return;
    }
    node->value = value;
    node->next = *head_ref;
    *head_ref = node;
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
    push_front(&head, 0);
    push_front(&head, 1);
    print_list(head);
    return 0;
}
