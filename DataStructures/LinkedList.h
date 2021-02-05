//
//  LinkedList.h
//  hdelibc
//
//  Created by Eric Meehan on 1/31/21.
//

#ifndef LinkedList_h
#define LinkedList_h

#include <stdlib.h>
#include <stdio.h>
#include "Node.h"

struct LinkedList
{
    struct Node *head;
    int length;
    
    void (*insert)(struct LinkedList *linked_list, int index, void *data, int data_type, int size);
    void (*remove)(struct LinkedList *linked_list, int index);
    void * (*retrieve)(struct LinkedList *linked_list, int index);
};

struct LinkedList linked_list_constructor(void);
void linked_list_destructor(struct LinkedList *linked_list);

#endif /* LinkedList_h */
