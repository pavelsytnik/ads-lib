#include <stdlib.h>
#include <stdio.h>

#include "ADS_LinkedList.h"

typedef struct ADS_Node ADS_Node;

struct ADS_Node {
    int value;
    ADS_Node *next;
};

struct ADS_LinkedList {
    ADS_Node *head;
    int size;
};

ADS_Node *ADS_Node_Create(ADS_Node *prev, int val, ADS_Node *next)
{
    ADS_Node *node = malloc(sizeof(ADS_Node));
    if (!node)
        return NULL;

    if (prev) prev->next = node;
    node->value = val;
    node->next = next;

    return node;
}

ADS_LinkedList *ADS_LinkedList_Create()
{
    ADS_LinkedList *list = malloc(sizeof(ADS_LinkedList));
    if (!list)
        return NULL;

    list->head = NULL;
    list->size = 0;

    return list;
}

void ADS_LinkedList_Destroy(ADS_LinkedList *list)
{
    ADS_LinkedList_Clear(list);
    free(list);
}

int ADS_LinkedList_IsEmpty(ADS_LinkedList *list)
{
    return list->size == 0;
}

int ADS_LinkedList_Size(ADS_LinkedList *list)
{
    return list->size;
}

void ADS_LinkedList_Clear(ADS_LinkedList *list)
{
    while (list->head) {
        ADS_Node *temp = list->head->next;
        free(list->head);
        list->head = temp;
    }

    list->size = 0;
}

void ADS_LinkedList_Erase(ADS_LinkedList *list, int pos)
{
    if (pos < 0 || pos >= list->size)
        return;

    if (pos == 0) {
        ADS_LinkedList_PopFront(list);
        return;
    }

    ADS_Node *node = list->head;
    for (int i = 1; i < pos; ++i)
        node = node->next;

    ADS_Node *temp = node->next->next;
    free(node->next);
    node->next = temp;

    list->size--;
}

void ADS_LinkedList_PopFront(ADS_LinkedList *list)
{
    if (!list->head)
        return;

    ADS_Node *new_head = list->head->next;
    free(list->head);
    list->head = new_head;

    list->size--;
}

void ADS_LinkedList_PopBack(ADS_LinkedList *list)
{
    ADS_LinkedList_Erase(list, list->size - 1);
}

void ADS_LinkedList_Insert(ADS_LinkedList *list, int pos, int val)
{
    if (pos < 0 || pos > list->size)
        return;

    if (pos == 0) {
        ADS_LinkedList_PushFront(list, val);
        return;
    }

    ADS_Node *node = list->head;
    for (int i = 1; i < pos; ++i)
        node = node->next;

    ADS_Node_Create(node, val, node->next);
    list->size++;
}

void ADS_LinkedList_PushFront(ADS_LinkedList *list, int val)
{
    list->head = ADS_Node_Create(NULL, val, list->head);
    list->size++;
}

void ADS_LinkedList_PushBack(ADS_LinkedList *list, int val)
{
    ADS_LinkedList_Insert(list, list->size, val);
}

int ADS_LinkedList_Get(ADS_LinkedList *list, int pos)
{
    if (pos < 0 || pos >= list->size)
        return;

    ADS_Node *node = list->head;
    for (int i = 0; i < pos; ++i)
        node = node->next;

    return node->value;
}

void ADS_LinkedList_Set(ADS_LinkedList *list, int pos, int val)
{
    if (pos < 0 || pos >= list->size)
        return;

    ADS_Node *node = list->head;
    for (int i = 0; i < pos; ++i)
        node = node->next;

    node->value = val;
}

int ADS_LinkedList_Front(ADS_LinkedList *list)
{
    return list->head->value;
}

int ADS_LinkedList_Back(ADS_LinkedList *list)
{
    return ADS_LinkedList_Get(list, list->size - 1);
}

void ADS_LinkedList_Reverse(ADS_LinkedList *list)
{
    if (list->size < 2)
        return;

    ADS_Node *prev = NULL;
    ADS_Node *curr = list->head;
    ADS_Node *next = NULL;

    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    list->head = prev;
}
