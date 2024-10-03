#ifndef ADS_LINKED_LIST_H
#define ADS_LINKED_LIST_H

typedef struct ADS_LinkedList ADS_LinkedList;

ADS_LinkedList *ADS_LinkedList_Create();
void ADS_LinkedList_Destroy(ADS_LinkedList *list);

int ADS_LinkedList_IsEmpty(ADS_LinkedList *list);
int ADS_LinkedList_Size(ADS_LinkedList *list);

void ADS_LinkedList_Clear(ADS_LinkedList *list);
void ADS_LinkedList_Erase(ADS_LinkedList *list, int pos);
void ADS_LinkedList_PopFront(ADS_LinkedList *list);
void ADS_LinkedList_PopBack(ADS_LinkedList *list);

void ADS_LinkedList_Insert(ADS_LinkedList *list, int pos, int val);
void ADS_LinkedList_PushFront(ADS_LinkedList *list, int val);
void ADS_LinkedList_PushBack(ADS_LinkedList *list, int val);

int ADS_LinkedList_Get(ADS_LinkedList *list, int pos);
void ADS_LinkedList_Set(ADS_LinkedList *list, int pos, int val);
int ADS_LinkedList_Front(ADS_LinkedList *list);
int ADS_LinkedList_Back(ADS_LinkedList *list);

void ADS_LinkedList_Reverse(ADS_LinkedList *list);

#endif
