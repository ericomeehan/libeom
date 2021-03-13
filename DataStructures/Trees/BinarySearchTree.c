//
// Homo Deus
// 2/11/21
//
// Homo Deus C Library
// BinarySearchTree.c
//
// Eric Meehan
//

//
// ==================================
// libeom
//
// an open source c library.
// ==================================
//
// BinarySearchTree.c
//
// Eric Meehan
// 2/11/21
//
//

#include "BinarySearchTree.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// MARK: PROTOTYPES

// MARK: Private Member Methods

struct Node * create_node_bst(void *data, unsigned long size);
void destroy_node_bst(struct Node *node_to_destroy);
struct Node * iterate_bst(struct BinarySearchTree *tree, struct Node *cursor, void *data, int *direction);
void recursive_tree_destruction(struct Node *node);


// MARK: Public Member Methods

void * search_bst(struct BinarySearchTree *tree, void *data);
void insert_bst(struct BinarySearchTree *tree, void *data, unsigned long size);


// MARK: DEFINITIONS

// MARK: Constructors

// The constructor takes a compare function pointer as its only argument and returns a defined BinarySearchTree struct.
struct BinarySearchTree binary_search_tree_constructor(int (*compare)(void *data_one, void *data_two))
{
    struct BinarySearchTree tree;
    tree.head = NULL;
    tree.compare = compare;
    tree.search = search_bst;
    tree.insert = insert_bst;
    return tree;
}

void binary_search_tree_destructor(struct BinarySearchTree tree)
{
    recursive_tree_destruction(tree.head);
}


// MARK: Private Member Methods

// The create_node allocates space on the heap for a node and uses the Node constructor to instantiate it.
struct Node * create_node_bst(void *data, unsigned long size)
{
    // Allocate space.
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    // Call the constructor.
    *new_node = node_constructor(data, size);
    return new_node;
}

// The destroy_node function removes a node by deallocating it's memory address.  This simply renames the node destructor function.
void destroy_node_bst(struct Node *node_to_destroy)
{
    node_destructor(node_to_destroy);
}

// The iterate function is a recursive algorithm that traverses the branches of a tree.
// It utilizes the compare function to determine if it should move left or right, and returns the cursor once there is nowhere left for the iterator to move.
// The user must take care to insrue this function returns the node they are actually looking for.
// The function takes a reference to the BinarySearchTree, the current position, desired data, and an int pointer as arguments.
// The int pointer becomes 1 if the desired data is greater than the returned node, -1 if it is less than, and 0 if they are equal.
struct Node * iterate_bst(struct BinarySearchTree *tree, struct Node *cursor, void *data, int *direction)
{
    // Compare the cursor's data to the desired data.
    if (tree->compare(cursor->data, data) == 1)
    {
        // Check if there is another node in the chain to be tested.
        if (cursor->next)
        {
            // Recursively test the next (right) node.
            return iterate_bst(tree, cursor->next, data, direction);
        }
        else
        {
            // Set the direction pointer to reflect the next position is desired (moving right).
            *direction = 1;
            // Return the cursor.
            return cursor;
        }
    }
    // Alternative outcome of the compare.
    else if (tree->compare(cursor->data, data) == -1)
    {
        // Check if there is another node in the chain to be tested.
        if (cursor->previous)
        {
            // Recursively test the previous (left) node.
            return iterate_bst(tree, cursor->previous, data, direction);
        }
        else
        {
            // Set the direction pointer to reflect the previous position is desired (moving left).
            *direction = -1;
            return cursor;
        }
    }
    // The two data values are equal.
    else
    {
        // Set direction.
        *direction = 0;
        // Return the node.
        return cursor;
    }
}

void recursive_tree_destruction(struct Node *node)
{
    if (node->previous)
    {
        recursive_tree_destruction(node->previous);
    }
    if (node->next)
    {
        recursive_tree_destruction(node->next);
    }
    destroy_node_bst(node);
}


// MARK: Public Member Methods

// The search function utilizes the iterate function to test if a given node exists in the tree.
// If the node is found, its data is returned.  Otherwise, NULL is returned.
void * search_bst(struct BinarySearchTree *tree, void *data)
{
    // Set the direction int pointer.
    int direction = 0;
    // Utilize iterate to find the desired position.
    struct Node *cursor = iterate_bst(tree, tree->head, data, &direction);
    // Test if the found node is the desired node, or an adjacent one.
    if (direction == 0)
    {
        return cursor->data;
    }
    else
    {
        return NULL;
    }
}

// The insert function adds new nodes to the tree by finding their proper position.
void insert_bst(struct BinarySearchTree *tree, void *data, unsigned long size)
{
    // Check if this is the first node in the tree.
    if (!tree->head)
    {
        tree->head = create_node_bst(data, size);
    }
    else
    {
        // Set the direction int pointer.
        int direction = 0;
        // Find the desired position.
        struct Node *cursor = iterate_bst(tree, tree->head, data, &direction);
        // Check if the new node should be inserted to the left or right.
        if (direction == 1)
        {
            cursor->next = create_node_bst(data, size);
        }
        else if (direction == -1)
        {
            cursor->previous = create_node_bst(data, size);
        }
        // Duplicate nodes will not be added.
    }
}


int binary_search_tree_str_compare(void *data_one, void *data_two)
{
    int comparison = strcmp(data_one, data_two);
    
    if (comparison > 0)
    {
        return 1;
    }
    else if (comparison < 0)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}
