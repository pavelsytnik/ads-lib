#include "ADS_ForwardList.h"

#include <stdlib.h>
#include <stdio.h>

static ADS_Node *ADS_Node_Create(int val, const ADS_Node *next)
{
    ADS_Node *node = malloc(sizeof(ADS_Node));
    if (!node)
        return NULL;

    node->value = val;
    node->next = next;

    return node;
}

void ADS_ForwardList_Init(ADS_ForwardList *list)
{
    list->head = NULL;
}

void ADS_ForwardList_Free(ADS_ForwardList *list)
{
    ADS_ForwardList_Clear(list);
    list->head = NULL;
}

int ADS_ForwardList_IsEmpty(ADS_ForwardList *list)
{
    return !list->head;
}

void ADS_ForwardList_Clear(ADS_ForwardList *list)
{
    while (list->head) {
        ADS_Node *temp = list->head->next;
        free(list->head);
        list->head = temp;
    }
}

/* v    int pos ==> ADS_Node *pos    v */
void ADS_ForwardList_Erase(ADS_ForwardList *list, int pos)
{
    if (pos == 0) {
        ADS_ForwardList_PopFront(list);
        return;
    }

    ADS_Node *node = list->head;
    for (int i = 1; i < pos; ++i)
        node = node->next;

    ADS_Node *temp = node->next->next;
    free(node->next);
    node->next = temp;
}

void ADS_ForwardList_PopFront(ADS_ForwardList *list)
{
    ADS_Node *new_head = list->head->next;
    free(list->head);
    list->head = new_head;
}

/* v    int pos ==> ADS_Node *pos    v */
void ADS_ForwardList_Insert(ADS_ForwardList *list, int pos, int val)
{
    if (pos == 0) {
        ADS_ForwardList_PushFront(list, val);
        return;
    }

    ADS_Node *node = list->head;
    for (int i = 1; i < pos; ++i)
        node = node->next;

    node->next = ADS_Node_Create(val, node->next);
}

void ADS_ForwardList_PushFront(ADS_ForwardList *list, int val)
{
    list->head = ADS_Node_Create(val, list->head);
}

int ADS_ForwardList_Front(ADS_ForwardList *list)
{
    return list->head->value;
}

void ADS_ForwardList_Reverse(ADS_ForwardList *list)
{
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
