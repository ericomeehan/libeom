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
    
    void (*insert)(int index, void *data, struct LinkedList *linked_list);
    void (*remove)(int index, struct LinkedList *linked_list);
    void * (*retrieve)(int index, struct LinkedList *linked_list);
};

struct LinkedList linked_list_constructor(void);
void linked_list_destructor(struct LinkedList *linked_list);

#endif /* LinkedList_h */
