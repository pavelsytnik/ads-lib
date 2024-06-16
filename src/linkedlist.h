#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct linkedlist linkedlist_t;

void initialize_list(linkedlist_t** list_ptr);
void destroy_list(linkedlist_t* list);

int list_size(linkedlist_t* list);
void print_list(linkedlist_t* list);

void push_front(linkedlist_t* list, int value);
void push_back(linkedlist_t* list, int value);
void insert(linkedlist_t* list, int pos, int value);

void remove_front(linkedlist_t* list);
void remove_back(linkedlist_t* list);
void delete(linkedlist_t* list, int pos);

int get(linkedlist_t* list, int pos);
void set(linkedlist_t* list, int pos, int value);

#endif
