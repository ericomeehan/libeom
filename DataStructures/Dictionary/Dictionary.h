//
//  Dictionary.h
//  hdelibc
//
//  Created by Eric Meehan on 2/12/21.
//

#ifndef Dictionary_h
#define Dictionary_h

#include "../Trees/BinarySearchTree.h"
#include "Entry.h"

// MARK: DATA TYPES
// The dictionary is a collection of entries stored in a BinarySearchTree.
struct Dictionary
{
    /* MEMBER VARIABLES */
    // Inheriting the BinarySearchTree object.
    struct BinarySearchTree binary_search_tree;
    /* PUBLIC MEMBER METHODS */
    // Insert adds new items to the dictionary - the user need only specify the key, value, and their respective sizes.
    void (*insert)(struct Dictionary *dictionary, void *key, int key_size, void *value, int value_size);
    // Search looks for a given key in the dictionary and returns its value if found or NULL if not.
    void * (*search)(struct Dictionary *dictionary, void *key);
};

// MARK: CONSTRUCTORS
// The constructor for a dictionary requires a compare function.  This will be passed on to the BinarySearchTree.
struct Dictionary dictionary_constructor(int (*compare)(void *key_one, void *key_two));
// The destructor will need to free every node in the tree.
struct Dictionary dictionary_destructor(struct Dictionary *dictionary);

#endif /* Dictionary_h */
