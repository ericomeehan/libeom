//
//  LinkedList.c
//  hdelibc
//
//  Created by Eric Meehan on 1/31/21.
//

#include "LinkedList.h"

struct Node_int * create_node_int(int data);
void destroy_node_int(struct Node_int *node_to_destroy);

struct Node_int * iterate_int(int index, struct LinkedList_int *linked_list);
void insert_node_int(int index, int data, struct LinkedList_int *linked_list);
void remove_node_int(int index, struct LinkedList_int *linked_list);
int retrieve_data_int(int index, struct LinkedList_int *linked_list);

struct LinkedList_int linked_list_int_constructor()
{
    struct LinkedList_int new_list;
    new_list.head = NULL;
    new_list.length = 0;
    
    new_list.insert = insert_node_int;
    new_list.remove = remove_node_int;
    new_list.retrieve = retrieve_data_int;
    
    return new_list;
}

struct Node_int * create_node_int(int data)
{
    struct Node_int *new_node_address = (struct Node_int *)malloc(sizeof(struct Node_int));
    struct Node_int new_node_instance;
    new_node_instance.data = data;
    new_node_instance.next = NULL;
    *new_node_address = new_node_instance;
    return new_node_address;
}

void destroy_node_int(struct Node_int *node_to_destroy)
{
    free(node_to_destroy);
}

struct Node_int * iterate_int(int index, struct LinkedList_int *linked_list)
{
    if (index < 0 || index >= linked_list->length)
    {
        printf("Index out of bound..");
        exit(9);
    }
    struct Node_int *cursor = linked_list->head;
    for (int i = 0; i < index; i++)
    {
        cursor = cursor->next;
    }
    return cursor;
}

void insert_node_int(int index, int data, struct LinkedList_int *linked_list)
{
    struct Node_int *node_to_insert = create_node_int(data);
    
    if (index == 0)
    {
        node_to_insert->next = linked_list->head;
        linked_list->head = node_to_insert;
    }
    else
    {
        struct Node_int *cursor = iterate_int(index - 1, linked_list);
        node_to_insert->next = cursor->next;
        cursor->next = node_to_insert;
        
    }
    linked_list->length += 1;
}

void remove_node_int(int index, struct LinkedList_int *linked_list)
{
    if (index == 0)
    {
        struct Node_int *node_to_remove = linked_list->head;
        linked_list->head = node_to_remove->next;
        destroy_node_int(node_to_remove);
    }
    else
    {
        struct Node_int *cursor = iterate_int(index - 1, linked_list);
        struct Node_int *node_to_remove = cursor->next;
        cursor->next = node_to_remove->next;
        destroy_node_int(node_to_remove);
    }
    linked_list->length -= 1;
}

int retrieve_data_int(int index, struct LinkedList_int *linked_list)
{
    struct Node_int *cursor = iterate_int(index, linked_list);
    return cursor->data;
}
