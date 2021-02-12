//
//  Queue.c
//  hdelibc
//
//  Created by Eric Meehan on 2/3/21.
//

#include "Queue.h"


/* PUBLIC METHODS */
void push(struct Queue *queue, void *data, int size);
void * peek(struct Queue *queue);
void pop (struct Queue *queue);



/* CONSTRUCTORS */

struct Queue queue_constructor()
{
    // Create a Queue instance.
    struct Queue queue;
    // Instantiate the queue's LinkedList via the constructor.
    queue.list = linked_list_constructor();
    
    // Define the member functions.
    queue.push = push;
    queue.peek = peek;
    queue.pop = pop;
    
    return queue;
}

void queue_destructor(struct Queue *queue)
{
    linked_list_destructor(&queue->list);
}



/* PUBLIC METHODS */

// The push method adds an item to the end of the list.
void push(struct Queue *queue, void *data, int size)
{
    // Utilize insert from LinkedList with enforced parameters.
    queue->list.insert(&queue->list, queue->list.length, data, size);
}

// The peek function returns the data from the first item in the chain.
void * peek(struct Queue *queue)
{
    // Utilize the retrieve function from LinkedList with enforced parameters.
    void *data = queue->list.retrieve(&queue->list, 0);
    return data;
}

// The pop function removes the first item in the chain.
void pop(struct Queue *queue)
{
    // Utilize the remove function from LinkedList with enforced parameters.
    queue->list.remove(&queue->list, 0);
}
