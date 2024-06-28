#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct linked_list;

struct linked_list *linked_list_create();
void linked_list_destroy(struct linked_list *list);

int linked_list_is_empty(struct linked_list *list);
int linked_list_size(struct linked_list *list);

void linked_list_clear(struct linked_list *list);
void linked_list_erase(struct linked_list *list, int pos);
void linked_list_pop_front(struct linked_list *list);
void linked_list_pop_back(struct linked_list *list);

void linked_list_insert(struct linked_list *list, int pos, int val);
void linked_list_push_front(struct linked_list *list, int val);
void linked_list_push_back(struct linked_list *list, int val);

int linked_list_get(struct linked_list *list, int pos);
void linked_list_set(struct linked_list *list, int pos, int val);
int linked_list_front(struct linked_list *list);
int linked_list_back(struct linked_list *list);

#endif
