//
// Homo Deus
// 2/12/21
//
// Homo Deus C Library
// Entry.h
//
// Eric Meehan
//

#ifndef Entry_h
#define Entry_h

// MARK: DATA TYPES

// Entries are the fundamental unit of a dictionary, containing a value to be stored and a key to identify it.
struct Entry
{
    void *key;
    void *value;
};

// MARK: CONSTRUCTORS
// The constructor for an entry requires the key, value, and sizes of each, allowing any data type to be stored.
struct Entry entry_constructor(void *key, int key_size, void *value, int value_size);
void entry_destructor(struct Entry *entry);
#endif /* Entry_h */
