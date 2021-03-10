//
// ==================================
// libeom
//
// an open source c library.
// ==================================
//
// Node.c
//
// Eric Meehan
// 2/4/21
//
//


#include "Node.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// MARK: CONSTRUCTORS

// The constructor is used to create new instances of nodes.
struct Node node_constructor(void *data, unsigned long size)
{
    if (size < 1)
    {
        // Confirm the size of the data is at least one, otherwise exit with an error message.
        printf("Invalid data size for node...\n");
        exit(1);
    }
    // Create a Node instance to be returned
    struct Node node;
    // Allocate space for the data if it is of a supported type
    node.data = malloc(size);
    memcpy(node.data, data, size);
    // Initialize the pointers.
    node.next = NULL;
    node.previous = NULL;
    return node;
}

// The destructor removes a node by freeing the node's data and its node.
void node_destructor(struct Node *node)
{
    free(node->data);
    free(node);
}
