#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>

struct vector_header {
    size_t size;
    size_t capacity;
};

#define vector_metadata(vector) \
    ((struct vector_header *) (vector) - 1)

#define vector_from_metadata(metadata) \
    ((struct vector_header *) (metadata) + 1)

#define vector_begin(vector) \
    (vector)

#define vector_end(vector) \
    (&(vector)[vector_size(vector)])

#define vector_size_for(type, capacity) \
    (sizeof(struct vector_header) + (capacity) * sizeof(type))

#define vector_create(vector)                                              \
do {                                                                       \
    struct vector_header *metadata = malloc(sizeof(struct vector_header)); \
    if (!metadata)                                                         \
        break;                                                             \
                                                                           \
    metadata->size = 0;                                                    \
    metadata->capacity = 0;                                                \
                                                                           \
    vector = vector_from_metadata(metadata);                               \
} while (0)

#define vector_reserve(vector, new_capacity)                                      \
do {                                                                              \
    struct vector_header *metadata = vector_metadata(vector);                     \
                                                                                  \
    if (new_capacity <= metadata->capacity)                                       \
        break;                                                                    \
                                                                                  \
    void *new_memory = realloc(metadata, vector_size_for(*vector, new_capacity)); \
    if (!new_memory)                                                              \
        break;                                                                    \
                                                                                  \
    vector = vector_from_metadata(new_memory);                                    \
    vector_metadata(vector)->capacity = new_capacity;                             \
} while (0)

#define vector_destroy(vector)      \
do {                                \
    free(vector_metadata(vector));  \
    vector = NULL;                  \
} while (0)

#define vector_is_empty(vector) \
    (vector_metadata(vector)->size == 0)

#define vector_size(vector) \
    (vector_metadata(vector)->size)

#define vector_capacity(vector) \
    (vector_metadata(vector)->capacity)

#define vector_shrink(vector)                                                 \
do {                                                                          \
    struct vector_header *metadata = vector_metadata(vector);                 \
    int size = metadata->size;                                                \
                                                                              \
    if (size < metadata->capacity) {                                          \
                                                                              \
        void *new_memory = realloc(metadata, vector_size_for(*vector, size)); \
        if (!new_memory)                                                      \
            break;                                                            \
                                                                              \
        vector = vector_from_metadata(new_memory);                            \
        vector_metadata(vector)->capacity = size;                             \
    }                                                                         \
} while (0)

#define vector_clear(vector) \
    vector_metadata(vector)->size = 0

#define vector_push_back(vector, value)                       \
do {                                                          \
    struct vector_header *metadata = vector_metadata(vector); \
                                                              \
    if (metadata->capacity == 0)                              \
        vector_reserve(vec, 8);                               \
    else if (metadata->capacity == metadata->size)            \
        vector_reserve(vec, 2 * metadata->capacity);          \
                                                              \
    vector[vector_size(vector)++] = value;                    \
} while (0)

#define vector_pop_back(vector)                               \
do {                                                          \
    struct vector_header *metadata = vector_metadata(vector); \
                                                              \
    if (metadata->size == 0)                                  \
        break;                                                \
                                                              \
    metadata->size--;                                         \
} while (0)

#define vector_insert(vector, index, value)                   \
do {                                                          \
    struct vector_header *metadata = vector_metadata(vector); \
                                                              \
    if (index < 0 || index > metadata->size)                  \
        break;                                                \
                                                              \
    if (metadata->capacity == 0)                              \
        vector_reserve(vec, 8);                               \
    else if (metadata->capacity == metadata->size)            \
        vector_reserve(vec, 2 * metadata->capacity);          \
                                                              \
    metadata = vector_metadata(vector);                       \
                                                              \
    for (int i = metadata->size; i != index; --i)             \
        vector[i] = vector[i - 1];                            \
                                                              \
    metadata->size++;                                         \
    vector[index] = value;                                    \
} while (0)

#endif
