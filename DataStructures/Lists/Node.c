//
//  Node.c
//  hdelibc
//
//  Created by Eric Meehan on 2/4/21.
//


#include "Node.h"

/* METHODS */

// The constructor is used to create new instances of nodes.
struct Node node_constructor(void *data, int data_type, int size)
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
    switch (data_type)
    {
        case Int:
        {
            // Allocate space - the size of the data type is multiplied by the size to accommodate arrays.
            node.data = malloc(sizeof(int) * size);
            // Insert each item from the specified array into the allocated space (a non-array can be considered an array with one element).
            for (int i = 0; i < size; i++)
            {
                ((int *)node.data)[i] = ((int *)data)[i];
            }
            break;
        }
        case Long:
        {
            node.data = malloc(sizeof(long) * size);
            for (int i = 0; i < size; i++)
            {
                ((long *)node.data)[i] = ((long *)data)[i];
            }
            break;
        }
        case Float:
        {
            node.data = malloc(sizeof(float) * size);
            for (int i = 0; i < size; i++)
            {
                ((float *)node.data)[i] = ((float *)data)[i];
            }
            break;
        }
        case Double:
        {
            node.data = malloc(sizeof(double) * size);
            for (int i = 0; i < size; i++)
            {
                ((double *)node.data)[i] = ((double *)data)[i];
            }
            break;
        }
        case Char:
        {
            // Character arrays must be null terminated - an additional space is added to accommodate this.
            node.data = malloc(sizeof(char) * size + 1);
            for (int i = 0; i < size; i++)
            {
                ((char *)node.data)[i] = ((char *)data)[i];
            }
            // Add the null character.
            ((char *)node.data)[size] = 0;
            break;
        }
        case Bool:
        {
            node.data = malloc(sizeof(bool) * size);
            for (int i = 0; i < size; i++)
            {
                ((bool *)node.data)[i] = ((bool *)data)[i];
            }
            break;
        }
        default:
        {
            node.data = data;
            break;
        }
    }
    // Initialize the data type and size.
    node.data_type = data_type;
    node.size = size;
    // Initialize the pointers.
    node.next = NULL;
    return node;
}

// The destructor removes a node by freeing the node's data and its node.
void node_destructor(struct Node *node)
{
    free(node->data);
    free(node);
}
