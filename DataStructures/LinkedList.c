//
//  LinkedList.c
//  hdelibc
//
//  Created by Eric Meehan on 1/31/21.
//

#include "LinkedList.h"

struct Node * create_node(void *data, int data_type, int size);
void destroy_node(struct Node *node_to_destroy);

struct Node * iterate(struct LinkedList *linked_list, int index);
void insert_node(struct LinkedList *linked_list, int index, void *data, int data_type, int size);
void remove_node(struct LinkedList *linked_list, int index);
void * retrieve_data(struct LinkedList *linked_list, int index);

struct LinkedList linked_list_constructor()
{
    struct LinkedList new_list;
    new_list.head = NULL;
    new_list.length = 0;
    
    new_list.insert = insert_node;
    new_list.remove = remove_node;
    new_list.retrieve = retrieve_data;
    
    return new_list;
}

void linked_list_destructor(struct LinkedList *linked_list)
{
    for (int i = 0; i < linked_list->length; i++)
    {
        linked_list->remove(linked_list, 0);
    }
}

struct Node * create_node(void *data, int data_type, int size)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    *new_node = node_constructor(data, data_type, size);
    return new_node;
}

void destroy_node(struct Node *node_to_destroy)
{
    node_destructor(node_to_destroy);
}

struct Node * iterate(struct LinkedList *linked_list, int index)
{
    if (index < 0 || index >= linked_list->length)
    {
        printf("Index out of bound..");
        exit(9);
    }
    struct Node *cursor = linked_list->head;
    for (int i = 0; i < index; i++)
    {
        cursor = cursor->next;
    }
    return cursor;
}

void insert_node(struct LinkedList *linked_list, int index, void *data, int data_type, int size)
{
    struct Node *node_to_insert = create_node(data, data_type, size);
    
    if (index == 0)
    {
        node_to_insert->next = linked_list->head;
        linked_list->head = node_to_insert;
    }
    else
    {
        struct Node *cursor = iterate(linked_list, index - 1);
        node_to_insert->next = cursor->next;
        cursor->next = node_to_insert;
        
    }
    linked_list->length += 1;
}

void remove_node(struct LinkedList *linked_list, int index)
{
    if (index == 0)
    {
        struct Node *node_to_remove = linked_list->head;
        linked_list->head = node_to_remove->next;
        destroy_node(node_to_remove);
    }
    else
    {
        struct Node *cursor = iterate(linked_list, index - 1);
        struct Node *node_to_remove = cursor->next;
        cursor->next = node_to_remove->next;
        destroy_node(node_to_remove);
    }
    linked_list->length -= 1;
}

void * retrieve_data(struct LinkedList *linked_list, int index)
{
    struct Node *cursor = iterate(linked_list, index);
    return cursor->data;
}
