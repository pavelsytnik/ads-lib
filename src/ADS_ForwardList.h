#ifndef ADS_FORWARD_LIST_H
#define ADS_FORWARD_LIST_H

#include <stdlib.h>

#define ADS_TYPEDEF_STRUCT(name) \
    typedef struct name name;

#define ADS_FORWARD_LIST_DEFINE(type, prefix)       \
                                                    \
    ADS_TYPEDEF_STRUCT(ADS_ForwardList(prefix))     \
    ADS_TYPEDEF_STRUCT(ADS_ForwardListNode(prefix)) \
                                                    \
    struct ADS_ForwardList(prefix) {                \
        ADS_ForwardListNode(prefix) *head;          \
    };                                              \
                                                    \
    struct ADS_ForwardListNode(prefix) {            \
        type value;                                 \
        ADS_ForwardListNode(prefix) *next;          \
    };

#define ADS_ForwardList(prefix)     ADS_##prefix##ForwardList
#define ADS_ForwardListNode(prefix) ADS_##prefix##ForwardListNode

#define ADS_ForwardList_Create() { NULL }

#define ADS_ForwardList_IsEmpty(list) \
    (!(list)->head)

#define ADS_ForwardList_Front(list) \
    ((list)->head)

#define ADS_ForwardListNode_New(val, node) do \
{                                             \
    void *next = (node);                      \
    (node) = malloc(sizeof(*(node)));         \
    (node)->value = (val);                    \
    (node)->next = next;                      \
}                                             \
while (0)

#define ADS_ForwardList_PushFront(list, val) do   \
{                                                 \
    ADS_ForwardListNode_New((val), (list)->head); \
}                                                 \
while (0)

#define ADS_ForwardList_PopFront(list) do \
{                                         \
    void *new_head = (list)->head->next;  \
    free((list)->head);                   \
    (list)->head = new_head;              \
}                                         \
while (0)

#define ADS_ForwardList_Clear(list) do   \
{                                        \
    while ((list)->head) {               \
        void *next = (list)->head->next; \
        free((list)->head);              \
        (list)->head = next;             \
    }                                    \
}                                        \
while (0)

#define ADS_ForwardList_Reverse(list) do \
{                                        \
    void *prev = NULL;                   \
    void *next = NULL;                   \
                                         \
    while ((list)->head) {               \
        next = (list)->head->next;       \
        (list)->head->next = prev;       \
        prev = (list)->head;             \
        (list)->head = next;             \
    }                                    \
                                         \
    (list)->head = prev;                 \
}                                        \
while (0)

/* Temporarily deleted */
//void ADS_ForwardList_Erase(ADS_ForwardList *list, int pos);
//void ADS_ForwardList_Insert(ADS_ForwardList *list, int pos, int val);

#endif
