//
// ==================================
// libeom
//
// an open source c library.
// ==================================
//
// Dictionary.c
//
// Eric Meehan
// 2/12/21
//
//

#include "Dictionary.h"

#include <stdlib.h>
#include <string.h>

// MARK: PRIVATE MEMBER FUNCTIONS
// Recursive algorithm to destroy the nodes in a dictionary - overrides the destructor of a BinarySearchTree
void recursive_dictionary_destroy(struct Node *cursor);

// MARK: PUBLIC MEMBER FUNCTIONS
// Insert adds items to the dictionary - the user does not need to implement Elements themselves.
void insert_dict(struct Dictionary *dictionary, void *key, unsigned long key_size, void *value, unsigned long value_size);
// Search finds the value for a given key in the Dictionary.
void * search_dict(struct Dictionary *dictionary, void *key, unsigned long key_size);

// MARK: CONSTRUCTORS
struct Dictionary dictionary_constructor(int (*compare)(void *key_one, void *key_two))
{
    struct Dictionary dictionary;
    dictionary.binary_search_tree = binary_search_tree_constructor(compare);
    dictionary.keys = linked_list_constructor();
    dictionary.insert = insert_dict;
    dictionary.search = search_dict;
    return dictionary;
}

void dictionary_destructor(struct Dictionary *dictionary)
{
    linked_list_destructor(&dictionary->keys);
    recursive_dictionary_destroy(dictionary->binary_search_tree.head);
}

// MARK: PRIVATE MEMBER FUNCTIONS
void recursive_dictionary_destroy(struct Node *cursor)
{
    if (cursor->previous)
    {
        recursive_dictionary_destroy(cursor->previous);
    }
    if (cursor->next)
    {
        recursive_dictionary_destroy(cursor->next);
    }
    entry_destructor((struct Entry *)cursor->data);
    free(cursor->data);
    free(cursor);
}

// MARK: PUBLIC MEMBER FUNCTIONS

void * search_dict(struct Dictionary *dictionary, void *key, unsigned long key_size)
{
    int dummy_value = 0;
    struct Entry searchable = entry_constructor(key, key_size, &dummy_value, sizeof(dummy_value));
    // Use the iterate function of the BinarySearchTree to find the desired element.
    void * result = dictionary->binary_search_tree.search(&dictionary->binary_search_tree, &searchable);
    // Return either the value for that key or NULL if not found.
    if (result)
    {
        return ((struct Entry *)result)->value;
    }
    else
    {
        return NULL;
    }
}

void insert_dict(struct Dictionary *dictionary, void *key, unsigned long key_size, void *value, unsigned long value_size)
{
    // Create a new Entry.
    struct Entry entry = entry_constructor(key, key_size, value, value_size);
    // Insert that entry into the tree.
    dictionary->binary_search_tree.insert(&dictionary->binary_search_tree, &entry, sizeof(entry));
    dictionary->keys.insert(&dictionary->keys, dictionary->keys.length, key, key_size);
}

#include <stdio.h>

// MARK: PUBLIC HELPER FUNCTIONS
int compare_string_keys(void *entry_one, void *entry_two)
{
    if (strcmp((char *)(((struct Entry *)entry_one)->key), (char *)(((struct Entry *)entry_two)->key)) > 0)
    {
        return 1;
    }
    else if (strcmp((char *)(((struct Entry *)entry_one)->key), (char *)(((struct Entry *)entry_two)->key)) < 0)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}
