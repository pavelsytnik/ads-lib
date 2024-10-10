#ifndef ADS_VECTOR_H
#define ADS_VECTOR_H

#include <stdlib.h>

#define ADS_Vector(type) type *

typedef struct ADS_VectorHeader {
    size_t size;
    size_t capacity;
} ADS_VectorHeader;

#define ADS_VectorToHeader(vec) \
    ((ADS_VectorHeader *)*(vec) - 1)

#define ADS_HeaderToVector(head) \
    ((ADS_Vector(void))((ADS_VectorHeader *)(head) + 1))

#define ADS_Vector_Size(vec) \
    (ADS_VectorToHeader((vec))->size)

#define ADS_Vector_Capacity(vec) \
    (ADS_VectorToHeader((vec))->capacity)

#define ADS_Vector_IsEmpty(vec) \
    (ADS_Vector_Size((vec)) == 0)

#define ADS_Vector_Resize(vec, cap) \
    ADS_Vector_Resize_Impl((vec), sizeof(**(vec)), (cap))

#define ADS_Vector_Shrink(vec) \
    ADS_Vector_Resize((vec), ADS_Vector_Size((vec)))

ADS_Vector(void) ADS_Vector_Init(void);
void ADS_Vector_Free(ADS_Vector(void) *vec);
void ADS_Vector_Clear(ADS_Vector(void) *vec);
void ADS_Vector_Resize_Impl(ADS_Vector(void) *vec, size_t elem_sz, size_t cap);
void ADS_Vector_PopBack(ADS_Vector(void) *vec);

#define ADS_Vector_PushBack(vec, val) do                 \
{                                                        \
    ADS_VectorHeader *head = ADS_VectorToHeader((vec)); \
                                                         \
    if (head->capacity == 0)                             \
        ADS_Vector_Resize((vec), 8);                     \
    else if (head->capacity == head->size)               \
        ADS_Vector_Resize((vec), 2 * head->capacity);    \
                                                         \
    /* `head` is invalidated here */                     \
    (*(vec))[ADS_Vector_Size((vec))++] = (val);          \
}                                                        \
while (0)

#endif
