#ifndef ADS_FORWARD_LIST_H
#define ADS_FORWARD_LIST_H

#include <stdlib.h>

#define ADS_TYPEDEF_STRUCT(name) \
    typedef struct name name;

#define ADS_FORWARD_LIST_DEFINE(type, prefix)       \
                                                    \
    ADS_TYPEDEF_STRUCT(ADS_ForwardList(prefix))     \
    ADS_TYPEDEF_STRUCT(ADS_ForwardListNode(prefix)) \
    ADS_TYPEDEF_STRUCT(ADS_ForwardListHead(prefix)) \
                                                    \
    struct ADS_ForwardListHead(prefix) {            \
        ADS_ForwardListNode(prefix) *next;          \
    };                                              \
                                                    \
    struct ADS_ForwardList(prefix) {                \
        ADS_ForwardListHead(prefix) head;           \
    };                                              \
                                                    \
    struct ADS_ForwardListNode(prefix) {            \
        type value;                                 \
        ADS_ForwardListNode(prefix) *next;          \
    };

#define ADS_ForwardList(prefix)     ADS_##prefix##_ForwardList
#define ADS_ForwardListNode(prefix) ADS_##prefix##_ForwardListNode
#define ADS_ForwardListHead(prefix) ADS_##prefix##_ForwardListHead

#define ADS_ForwardList_Create() \
    { { NULL } }

#define ADS_ForwardList_IsEmpty(list) \
    (!(list)->head.next)

#define ADS_ForwardList_Front(list) \
    (*(list)->head.next)

#define ADS_ForwardList_BeforeBegin(list) \
    (&(list)->head)

#define ADS_ForwardList_Begin(list) \
    ((list)->head.next)

#define ADS_ForwardList_End() \
    NULL

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

#define ADS_ForwardList_PopFront(list) do                 \
{                                                         \
    void *new_head = ADS_ForwardList_Begin((list))->next; \
    free(ADS_ForwardList_Begin((list)));                  \
    ADS_ForwardList_Begin((list)) = new_head;             \
}                                                         \
while (0)

#define ADS_ForwardList_Clear(list) do                    \
{                                                         \
    while (!ADS_ForwardList_IsEmpty((list))) {            \
        void *next = ADS_ForwardList_Begin((list))->next; \
        free(ADS_ForwardList_Begin((list)));              \
        ADS_ForwardList_Begin((list)) = next;             \
    }                                                     \
}                                                         \
while (0)

#define ADS_ForwardList_Reverse(list) do            \
{                                                   \
    void *prev = NULL;                              \
    void *next = NULL;                              \
                                         \
    while (ADS_ForwardList_Begin((list))) {         \
        next = ADS_ForwardList_Begin((list))->next; \
        ADS_ForwardList_Begin((list))->next = prev; \
        prev = ADS_ForwardList_Begin((list));       \
        ADS_ForwardList_Begin((list)) = next;       \
    }                                               \
                                         \
    ADS_ForwardList_Begin((list)) = prev;           \
}                                                   \
while (0)

/* Temporarily deleted */
//void ADS_ForwardList_Erase(ADS_ForwardList *list, int pos);
//void ADS_ForwardList_Insert(ADS_ForwardList *list, int pos, int val);

#endif
