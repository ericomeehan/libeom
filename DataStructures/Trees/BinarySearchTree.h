//
//  BinarySearchTree.h
//  hdelibc
//
//  Created by Eric Meehan on 2/11/21.
//

#ifndef BinarySearchTree_h
#define BinarySearchTree_h

#include "../Common/Node.h"

struct BinarySearchTree
{
    struct Node *head;
    
    int (*compare)(void *data_one, void *data_two);
    void * (*search)(struct BinarySearchTree *tree, void *data);
    void (*insert)(struct BinarySearchTree *tree, void *data, int size);
};

struct BinarySearchTree binary_search_tree_constructor(int (*compare)(void *data_one, void *data_two));

#endif /* BinarySearchTree_h */
