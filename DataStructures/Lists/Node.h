//
//  Node.h
//  hdelibc
//
//  Created by Eric Meehan on 1/31/21.
//

/*
 The Node struct is the foundation for list objects, functioning like a single cell in the list.
 Nodes utilize void pointers to store data, and as such are capable of storing any data type.
 
 Typically, nodes should not be manually instantiated.
 Usage is typically handled by the various list objects.
 
 In order to work, this requires the data to be allocated on the heap prior to being inserted into a node object.
 Typically, this is handled automatically when the node constructor is used;
 however, custom data types (those not included in the enumeration) need to be allocated manually and the data type Special should be used.
 
 In order to destroy a node, the node destructor is recommended as it will free both the stored data and the node itself automatically.
 */

#ifndef Node_h
#define Node_h

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>



/* DATA TYPES */

// The DataTypes enumeration stores names for each of the data types that supports automatic allocation.
enum DataTypes
{
    // Special is used when data will be allocated manually.
    Special,
    // This list will likely grow over time.
    Int,
    Long,
    Float,
    Double,
    Char,
    Bool
};

// Nodes are used to store data of any type in a list.  
struct Node
{
    /* PUBLIC MEMBER VARIABLES */
    // The data is stored as a void pointer - casting is required for proper access.
    void *data;
    // The type of data stored as defined in the DataTypes enumeration.
    int data_type;
    // The number of items in this node - this is used to accommodate arrays (size one for single items).
    int size;
    // A pointer to the next node in the chain.
    struct Node *next;
};


/* METHODS */

// The constructor should be used to create nodes.
struct Node node_constructor(void *data, int data_type, int size);
// The destructor should be used to destroy nodes.
void node_destructor(struct Node *node);

#endif /* Node_h */
