//
// ==================================
// libeom
//
// an open source c library.
// ==================================
//
// Queue.h
//
// Eric Meehan
// 2/3/21
//
//

/*
 The Queue struct is a version of the LinkedList the enforces rules on how items are added and accessed.
 In short, items are always added to the end and removed from the front.
 Largely, the methods defined here simply utilize those from LinkedList in a predefined way.
 */



#ifndef Queue_h
#define Queue_h



#include "LinkedList.h"


// MARK: DATA TYPES

// Queues are used to access a linked list in a controlled manner.
struct Queue
{
    /* MEMBER VARIABLES */
    // A reference to the embedded LinkedList.
    struct LinkedList list;
    
    /* PUBLIC MEMBER METHODS */
    // The push function adds a node to the end of the chain.
    void (*push)(struct Queue *queue, void *data, unsigned long size);
    // The peek function retrieves the data from the front of the list.
    void * (*peek)(struct Queue *queue);
    // The pop function removes the first item in the list.
    void (*pop)(struct Queue *queue);
};



// MARK: CONSTRUCTORS

// The constructor should be used to create new Queue instances.
struct Queue queue_constructor(void);
// The destructor should be used to delete a Queue instance.
void queue_destructor(struct Queue *queue);

#endif /* Queue_h */
