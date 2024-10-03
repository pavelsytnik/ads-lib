#ifndef ADS_STACK_H
#define ADS_STACK_H

typedef struct ADS_Stack ADS_Stack;

ADS_Stack *ADS_Stack_Create();
void ADS_Stack_Destroy(ADS_Stack *stck);

int ADS_Stack_IsEmpty(ADS_Stack *stck);
int ADS_Stack_Size(ADS_Stack *stck);
int ADS_Stack_Capacity(ADS_Stack *stck);
void ADS_Stack_Reserve(ADS_Stack *stck, int new_cap);
void ADS_Stack_Shrink(ADS_Stack *stck);

void ADS_Stack_Clear(ADS_Stack *stck);
void ADS_Stack_Push(ADS_Stack *stck, int val);
int ADS_Stack_Pop(ADS_Stack *stck);
int ADS_Stack_Peek(ADS_Stack *stck);

#endif
