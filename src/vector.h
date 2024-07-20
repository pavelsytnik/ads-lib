#ifndef VECTOR_H
#define VECTOR_H

void *vector_create();
void vector_destroy(void *vector);

int vector_is_empty(void *vector);
int vector_size(void *vector);
int vector_capacity(void *vector);
//void vector_reserve(struct vector *vec, int new_cap);
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
