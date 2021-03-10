//
// ==================================
// libeom
//
// an open source c library.
// ==================================
//
// Entry.c
//
// Eric Meehan
// 2/12/21
//
//

#include "Entry.h"

#include <stdlib.h>
#include <string.h>

// MARK: CONSTRUCTORS

// The constructor creates, initializes, and returns a new dictionary entry.
struct Entry entry_constructor(void *key, unsigned long key_size, void *value, unsigned long value_size)
{
    // Create the entry instance.
    struct Entry entry;
    // Allocate space on the heap for the key and value.
    entry.key = malloc(key_size);
    entry.value = malloc(value_size);
    // Copy the data parameters into the new object.
    memcpy(entry.key, key, key_size);
    memcpy(entry.value, value, value_size);
    return entry;
}

// The destructor must free the key and value of a given entry.
void entry_destructor(struct Entry *entry)
{
    free(entry->key);
    free(entry->value);
    free(entry);
}

