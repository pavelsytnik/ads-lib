#ifndef ADS_FORWARD_LIST_H
#define ADS_FORWARD_LIST_H

typedef struct ADS_ForwardList ADS_ForwardList;
typedef struct ADS_Node ADS_Node;

struct ADS_ForwardList {
    ADS_Node *head;
};

struct ADS_Node {
    int value;
    ADS_Node *next;
};

void ADS_ForwardList_Init(ADS_ForwardList *list);
void ADS_ForwardList_Free(ADS_ForwardList *list);

int ADS_ForwardList_IsEmpty(ADS_ForwardList *list);

void ADS_ForwardList_Clear(ADS_ForwardList *list);

/* v    int pos ==> ADS_Node *pos    v */
void ADS_ForwardList_Erase(ADS_ForwardList *list, int pos);
void ADS_ForwardList_PopFront(ADS_ForwardList *list);

/* v    int pos ==> ADS_Node *pos    v */
void ADS_ForwardList_Insert(ADS_ForwardList *list, int pos, int val);
void ADS_ForwardList_PushFront(ADS_ForwardList *list, int val);

int ADS_ForwardList_Front(ADS_ForwardList *list);

void ADS_ForwardList_Reverse(ADS_ForwardList *list);

#endif
