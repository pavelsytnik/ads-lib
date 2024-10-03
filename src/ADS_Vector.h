#ifndef ADS_VECTOR_H
#define ADS_VECTOR_H

typedef struct ADS_Vector ADS_Vector;

ADS_Vector *ADS_Vector_Create();
void ADS_Vector_Destroy(ADS_Vector *vec);

int ADS_Vector_IsEmpty(ADS_Vector *vec);
int ADS_Vector_Size(ADS_Vector *vec);
int ADS_Vector_Capacity(ADS_Vector *vec);
void ADS_Vector_Reserve(ADS_Vector *vec, int new_cap);
void ADS_Vector_Shrink(ADS_Vector *vec);

void ADS_Vector_Clear(ADS_Vector *vec);
void ADS_Vector_Insert(ADS_Vector *vec, int pos, int val);
void ADS_Vector_PushBack(ADS_Vector *vec, int val);
void ADS_Vector_PopBack(ADS_Vector *vec);

void ADS_Vector_Set(ADS_Vector *vec, int pos, int val);
int ADS_Vector_Get(ADS_Vector *vec, int pos);

#endif
