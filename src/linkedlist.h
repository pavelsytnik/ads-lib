#ifndef LINKED_LIST_H
#define LINKED_LIST_H

///////////////////////////////////////////////////
//typedef struct linkedlist linkedlist_t;

//void initialize_list(linkedlist_t* list);
//void clear_list(linkedlist_t* list);

//int list_size(linkedlist_t* list);
///////////////////////////////////////////////////

typedef struct node node_t;

node_t* create_node(int value);
void push_front(node_t** head_ref, int value);
void push_back(node_t** head_ref, int value);
void insert(node_t** head_ref, int pos, int value);
void remove_front(node_t** head_ref);
void remove_back(node_t** head_ref);
void delete(node_t** head_ref, int pos);
int get(node_t* head, int pos);
void set(node_t* head, int pos, int value);
void destroy_list(node_t* head);
void print_list(node_t* head);

#endif
