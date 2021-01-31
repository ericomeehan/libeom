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

struct LinkedList_int
{
    struct Node_int *head;
    int length;
    
    void (*insert)(int index, int data, struct LinkedList_int *linked_list);
    void (*remove)(int index, struct LinkedList_int *linked_list);
    int (*retrieve)(int index, struct LinkedList_int *linked_list);
};

struct LinkedList_int linked_list_int_constructor();

#endif /* LinkedList_h */
