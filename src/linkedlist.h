#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct linked_list linked_list;

void linked_list_initialize(linked_list** list_ptr);
void linked_list_destroy(linked_list* list);

int linked_list_size(linked_list* list);
void linked_list_print(linked_list* list);

void linked_list_push_front(linked_list* list, int value);
void linked_list_push_back(linked_list* list, int value);
void linked_list_insert(linked_list* list, int pos, int value);

void linked_list_remove_front(linked_list* list);
void linked_list_remove_back(linked_list* list);
void linked_list_delete(linked_list* list, int pos);

int linked_list_get(linked_list* list, int pos);
void linked_list_set(linked_list* list, int pos, int value);

#endif
