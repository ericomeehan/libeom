//
//  BinarySearchTree.c
//  hdelibc
//
//  Created by Eric Meehan on 2/11/21.
//

#include "BinarySearchTree.h"

struct Node * create_node(void *data, int size);
void destroy_node(struct Node *node_to_destroy);

void * search(struct BinarySearchTree *tree, void *data);
void insert(struct BinarySearchTree *tree, void *data, int size);

struct BinarySearchTree binary_search_tree_constructor(int (*compare)(void *data_one, void *data_two))
{
    struct BinarySearchTree tree;
    tree.compare = compare;
    tree.search = search;
    tree.insert = insert;
    return tree;
}

struct Node * create_node(void *data, int size)
{
    // Allocate space.
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    // Call the constructor.
    *new_node = node_constructor(data, size);
    return new_node;
}

// The destroy_node function removes a node by deallocating it's memory address.  This simply renames the node destructor function.
void destroy_node(struct Node *node_to_destroy)
{
    node_destructor(node_to_destroy);
}

struct Node * iterate(struct BinarySearchTree *tree, struct Node *cursor, void *data, int *direction)
{
    if (tree->compare(cursor->data, data) == 1)
    {
        if (cursor->next)
        {
            return iterate(tree, cursor->next, data, direction);
        }
        else
        {
            *direction = 1;
            return cursor;
        }
    }
    else if (tree->compare(cursor->data, data) == -1)
    {
        if (cursor->previous)
        {
            return iterate(tree, cursor->previous, data, direction);
        }
        else
        {
            *direction = -1;
            return cursor;
        }
    }
    else
    {
        direction = 0;
        return cursor;
    }
}

void * search(struct BinarySearchTree *tree, void *data)
{
    int *direction = NULL;
    struct Node *cursor = iterate(tree, tree->head, data, direction);
    if (*direction == 0)
    {
        return cursor->data;
    }
    else
    {
        return NULL;
    }
}

void insert(struct BinarySearchTree *tree, void *data, int size)
{
    int *direction = NULL;
    struct Node *cursor = iterate(tree, tree->head, data, direction);
    if (*direction == 1)
    {
        cursor->next = create_node(data, size);
    }
    else if (*direction == -1)
    {
        cursor->previous = create_node(data, size);
    }
}
