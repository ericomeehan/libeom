//
// ==================================
// libeom
//
// an open source c library.
// ==================================
//
// LinkedList.h
//
// Eric Meehan
// 1/31/21
//
//

/*
 The LinkedList struct is a collection of Nodes, each pointing to the next one in the chain.
 This is a dynamic implementation of a linked list - it does not enforce ubiquitous data types and can be resized at any point.
 
 The object handles the creation and destruction of nodes automatically, allowing the user to simply insert the desired data.
 In order to provide this functionality, node data takes the form of void pointers, so it must be casted appropriately upon access.
 
 The constructor and destructor should be used to create and destroy instances of the LinkedList struct.
 
 Note that a reference to the LinkedList instance must be passed to the member functions.
 This is similar to passing "self" to class member functions in Python.
 */



#ifndef LinkedList_h
#define LinkedList_h

#include "../Common/Node.h"

// MARK: DATA TYPES

// LinkedLists are used to move between and manipulate related nodes in an organized fashion.
struct LinkedList
{
    /* PUBLIC MEMBER VARIABLES */
    // Head points to the first node in the chain.
    struct Node *head;
    // Length refers to the number of nodes in the chain.
    int length;
    
    /* PUBLIC MEMBER METHODS */
    // Insert adds new items to the chain at a specified location - this function creates the new nodes.
    void (*insert)(struct LinkedList *linked_list, int index, void *data, unsigned long size);
    // Remove deletes an item from the chain and handles the deallocation of memory.
    void (*remove)(struct LinkedList *linked_list, int index);
    // Retrieve allows data in the chain to be accessed
    void * (*retrieve)(struct LinkedList *linked_list, int index);
    // Sorting and searching the list (bubble sort).
    void (*sort)(struct LinkedList *linked_list, int (*compare)(void *a, void *b));
    // Binary search (requires the list be sorted).
    short (*search)(struct LinkedList *linked_list, void *query, int (*compare)(void *a, void *b));
};



// MARK: CONSTRUCTORS 
struct LinkedList linked_list_constructor(void);
void linked_list_destructor(struct LinkedList *linked_list);

#endif /* LinkedList_h */
