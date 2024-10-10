#include "ADS_Vector.h"

#define ADS_SizeOfVector(elem_sz, cap) \
    (sizeof(ADS_VectorHeader) + (cap) * (elem_sz))

ADS_Vector(void) ADS_Vector_Init(void)
{
    ADS_VectorHeader *head = malloc(sizeof(ADS_VectorHeader));
    head->size = 0;
    head->capacity = 0;
    return ADS_HeaderToVector(head);
}

void ADS_Vector_Free(ADS_Vector(void) *vec)
{
    free(ADS_VectorToHeader(vec));
    *vec = NULL;
}

void ADS_Vector_Clear(ADS_Vector(void) *vec)
{
    ADS_VectorToHeader(vec)->size = 0;
}

void ADS_Vector_Resize_Impl(ADS_Vector(void) *vec, size_t elem_sz, size_t cap)
{
    ADS_VectorHeader *head;
    ADS_VectorHeader *new_mem;

    if (cap == ADS_Vector_Capacity(vec))
        return;

    head = ADS_VectorToHeader(vec);
    new_mem = realloc(head, ADS_SizeOfVector(elem_sz, cap));

    *vec = ADS_HeaderToVector(new_mem);
    ADS_Vector_Capacity(vec) = cap; /* `head` is invalidated here */
}

void ADS_Vector_PopBack(ADS_Vector(void) *vec)
{
    ADS_Vector_Size(vec)--;
}
