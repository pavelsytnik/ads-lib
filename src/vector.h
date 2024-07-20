#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>

struct vector_header {
    int size;
    int capacity;
};

#define vector_create(vector) do {                                         \
                                                                           \
    struct vector_header *metadata = malloc(sizeof(struct vector_header)); \
    if (!metadata)                                                         \
        break;                                                             \
                                                                           \
    metadata->size = 0;                                                    \
    metadata->capacity = 0;                                                \
                                                                           \
    vector = ++metadata;                                                   \
} while (0)

#define vector_reserve(vector, new_capacity) do {                         \
                                                                          \
    struct vector_header *metadata = (struct vector_header*)vector - 1;   \
                                                                          \
    if (new_capacity <= metadata->capacity)                               \
        break;                                                            \
                                                                          \
    void *new_memory = realloc(metadata, new_capacity * sizeof(*vector)); \
    if (!new_memory)                                                      \
        break;                                                            \
                                                                          \
    vector = (size_t)new_memory + sizeof(struct vector_header);           \
    ((struct vector_header*)vector - 1)->capacity = new_capacity;         \
} while (0)

#define vector_destroy(vector) do {                      \
    free((size_t)vector - sizeof(struct vector_header)); \
    vector = NULL;                                       \
} while (0)

#define vector_is_empty(vector) \
    (((struct vector_header*)vector - 1)->size == 0)

#define vector_size(vector) \
    (((struct vector_header*)vector - 1)->size)

#define vector_capacity(vector) \
    (((struct vector_header*)vector - 1)->capacity)

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
