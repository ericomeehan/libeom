//
//  BinarySearchTree.c
//  hdelibc
//
//  Created by Eric Meehan on 2/11/21.
//

#include "BinarySearchTree.h"

#include <stdlib.h>

// MARK: PROTOTYPES

// MARK: Private Member Methods

struct Node * create_node(void *data, int size);
void destroy_node(struct Node *node_to_destroy);


// MARK: Public Member Methods

void * search(struct BinarySearchTree *tree, void *data);
void insert(struct BinarySearchTree *tree, void *data, int size);


// MARK: DEFINITIONS

// MARK: Constructors

// The constructor takes a compare function pointer as its only argument and returns a defined BinarySearchTree struct.
struct BinarySearchTree binary_search_tree_constructor(int (*compare)(void *data_one, void *data_two))
{
    struct BinarySearchTree tree;
    tree.compare = compare;
    tree.search = search;
    tree.insert = insert;
    return tree;
}


// MARK: Private Member Methods

// The create_node allocates space on the heap for a node and uses the Node constructor to instantiate it.
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

// The iterate function is a recursive algorithm that traverses the branches of a tree.
// It utilizes the compare function to determine if it should move left or right, and returns the cursor once there is nowhere left for the iterator to move.
// The user must take care to insrue this function returns the node they are actually looking for.
// The function takes a reference to the BinarySearchTree, the current position, desired data, and an int pointer as arguments.
// The int pointer becomes 1 if the desired data is greater than the returned node, -1 if it is less than, and 0 if they are equal.
struct Node * iterate(struct BinarySearchTree *tree, struct Node *cursor, void *data, int *direction)
{
    // Compare the cursor's data to the desired data.
    if (tree->compare(cursor->data, data) == 1)
    {
        // Check if there is another node in the chain to be tested.
        if (cursor->next)
        {
            // Recursively test the next (right) node.
            return iterate(tree, cursor->next, data, direction);
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
            return iterate(tree, cursor->previous, data, direction);
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
        direction = 0;
        // Return the node.
        return cursor;
    }
}


// MARK: Public Member Methods

// The search function utilizes the iterate function to test if a given node exists in the tree.
// If the node is found, its data is returned.  Otherwise, NULL is returned.
void * search(struct BinarySearchTree *tree, void *data)
{
    // Set the direction int pointer.
    int *direction = NULL;
    // Utilize iterate to find the desired position.
    struct Node *cursor = iterate(tree, tree->head, data, direction);
    // Test if the found node is the desired node, or an adjacent one.
    if (*direction == 0)
    {
        return cursor->data;
    }
    else
    {
        return NULL;
    }
}

// The insert function adds new nodes to the tree by finding their proper position.
void insert(struct BinarySearchTree *tree, void *data, int size)
{
    // Set the direction int pointer.
    int *direction = NULL;
    // Find the desired position.
    struct Node *cursor = iterate(tree, tree->head, data, direction);
    // Check if the new node should be inserted to the left or right.
    if (*direction == 1)
    {
        cursor->next = create_node(data, size);
    }
    else if (*direction == -1)
    {
        cursor->previous = create_node(data, size);
    }
    // Duplicate nodes will not be added.
}
