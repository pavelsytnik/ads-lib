#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>

struct vector_header {
    int size;
    int capacity;
};

#define vector_metadata(vector) \
    ((struct vector_header*)vector - 1)

#define vector_begin(metadata) \
    ((struct vector_header*)metadata + 1)

#define vector_size_for(type, capacity) \
    (sizeof(struct vector_header) + capacity * sizeof(type))

#define vector_create(vector) do {                                         \
                                                                           \
    struct vector_header *metadata = malloc(sizeof(struct vector_header)); \
    if (!metadata)                                                         \
        break;                                                             \
                                                                           \
    metadata->size = 0;                                                    \
    metadata->capacity = 0;                                                \
                                                                           \
    vector = vector_begin(metadata);                                       \
} while (0)

#define vector_reserve(vector, new_capacity) do {                                 \
                                                                                  \
    struct vector_header *metadata = vector_metadata(vector);                     \
                                                                                  \
    if (new_capacity <= metadata->capacity)                                       \
        break;                                                                    \
                                                                                  \
    void *new_memory = realloc(metadata, vector_size_for(*vector, new_capacity)); \
    if (!new_memory)                                                              \
        break;                                                                    \
                                                                                  \
    vector = vector_begin(new_memory);                                            \
    vector_metadata(vector)->capacity = new_capacity;                             \
} while (0)

#define vector_destroy(vector) do { \
    free(vector_metadata(vector));  \
    vector = NULL;                  \
} while (0)

#define vector_is_empty(vector) \
    (vector_metadata(vector)->size == 0)

#define vector_size(vector) \
    (vector_metadata(vector)->size)

#define vector_capacity(vector) \
    (vector_metadata(vector)->capacity)

//void vector_shrink(struct vector *vec);
//
//void vector_clear(struct vector *vec);
//void vector_insert(struct vector *vec, int pos, int val);
//void vector_push_back(struct vector *vec, int val);
//void vector_pop_back(struct vector *vec);
//
//void vector_set(struct vector *vec, int pos, int val);
//int vector_get(struct vector *vec, int pos);

#endif
