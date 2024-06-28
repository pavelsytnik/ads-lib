#include <stdlib.h>
#include <stdio.h>

#include "linkedlist.h"

struct node {
    int value;
    struct node *next;
};

struct linked_list {
    struct node *head;
    int size;
};

static struct node *node_create(struct node *prev, int val, struct node *next)
{
    struct node *node = malloc(sizeof(struct node));
    if (!node)
        return NULL;

    if (prev) prev->next = node;
    node->value = val;
    node->next = next;

    return node;
}

struct linked_list *linked_list_create()
{
    struct linked_list *list = malloc(sizeof(struct linked_list));
    if (!list)
        return NULL;

    list->head = NULL;
    list->size = 0;

    return list;
}

void linked_list_destroy(struct linked_list *list)
{
    linked_list_clear(list);
    free(list);
}

int linked_list_is_empty(struct linked_list *list)
{
    return list->size == 0;
}

int linked_list_size(struct linked_list *list)
{
    return list->size;
}

void linked_list_clear(struct linked_list *list)
{
    while (list->head) {
        struct node *temp = list->head->next;
        free(list->head);
        list->head = temp;
    }

    list->size = 0;
}

void linked_list_erase(struct linked_list *list, int pos)
{
    if (pos < 0 || pos >= list->size)
        return;

    if (pos == 0) {
        linked_list_pop_front(list);
        return;
    }

    struct node *node = list->head;
    for (int i = 1; i < pos; ++i)
        node = node->next;

    struct node *temp = node->next->next;
    free(node->next);
    node->next = temp;

    list->size--;
}

void linked_list_pop_front(struct linked_list *list)
{
    if (!list->head)
        return;

    struct node *new_head = list->head->next;
    free(list->head);
    list->head = new_head;

    list->size--;
}

void linked_list_pop_back(struct linked_list *list)
{
    linked_list_erase(list, list->size - 1);
}

void linked_list_insert(struct linked_list *list, int pos, int val)
{
    if (pos < 0 || pos > list->size)
        return;

    if (pos == 0) {
        linked_list_push_front(list, val);
        return;
    }

    struct node *node = list->head;
    for (int i = 1; i < pos; ++i)
        node = node->next;

    node_create(node, val, node->next);
    list->size++;
}

void linked_list_push_front(struct linked_list *list, int val)
{
    list->head = node_create(NULL, val, list->head);
    list->size++;
}

void linked_list_push_back(struct linked_list *list, int val)
{
    linked_list_insert(list, list->size, val);
}

int linked_list_get(struct linked_list *list, int pos)
{
    if (pos < 0 || pos >= list->size)
        return;

    struct node *node = list->head;
    for (int i = 0; i < pos; ++i)
        node = node->next;

    return node->value;
}

void linked_list_set(struct linked_list *list, int pos, int val)
{
    if (pos < 0 || pos >= list->size)
        return;

    struct node *node = list->head;
    for (int i = 0; i < pos; ++i)
        node = node->next;

    node->value = val;
}

int linked_list_front(struct linked_list *list)
{
    return list->head->value;
}

int linked_list_back(struct linked_list *list)
{
    return linked_list_get(list, list->size - 1);
}

void linked_list_reverse(struct linked_list *list)
{
    if (list->size < 2)
        return;

    struct node *prev = NULL;
    struct node *curr = list->head;
    struct node *next = NULL;

    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    list->head = prev;
}
