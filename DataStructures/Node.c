//
//  Node.c
//  hdelibc
//
//  Created by Eric Meehan on 2/4/21.
//


#include "Node.h"


struct Node node_constructor(void *data, int data_type, int size)
{
    if (size < 1)
    {
        printf("Invalid data size for node...\n");
        exit(1);
    }
    struct Node node;
    switch (data_type) {
        case Int:
        {
            node.data = malloc(sizeof(int) * size);
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
            node.data = malloc(sizeof(char) * size + 1);
            for (int i = 0; i < size; i++)
            {
                ((char *)node.data)[i] = ((char *)data)[i];
            }
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
    node.data_type = data_type;
    node.size = size;
    node.next = NULL;
    return node;
}


void node_destructor(struct Node *node)
{
    free(node->data);
    free(node);
}
