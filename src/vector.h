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

#define vector_shrink(vector) do {                                            \
                                                                              \
    struct vector_header *metadata = vector_metadata(vector);                 \
    int size = metadata->size;                                                \
                                                                              \
    if (size < metadata->capacity) {                                          \
                                                                              \
        void *new_memory = realloc(metadata, vector_size_for(*vector, size)); \
        if (!new_memory)                                                      \
            break;                                                            \
                                                                              \
        vector = vector_begin(new_memory);                                    \
        vector_metadata(vector)->capacity = size;                             \
    }                                                                         \
} while (0)

#define vector_clear(vector) \
    vector_metadata(vector)->size = 0

#define vector_push_back(vector, value)                              \
do {                                                          \
    struct vector_header *metadata = vector_metadata(vector); \
                                                              \
    if (metadata->capacity == 0)                              \
        vector_reserve(vec, 8);                               \
    else if (metadata->capacity == metadata->size)            \
        vector_reserve(vec, 2 * metadata->capacity);          \
                                                              \
    vector[metadata->size++] = value;                         \
} while (0)

#define vector_pop_back(vector)                               \
do {                                                          \
    struct vector_header *metadata = vector_metadata(vector); \
                                                              \
    if (metadata->size == 0)                                  \
        return;                                               \
                                                              \
    metadata->size--;                                         \
} while (0)

#endif
