//
//  Queue.h
//  hdelibc
//
//  Created by Eric Meehan on 2/3/21.
//

#ifndef Queue_h
#define Queue_h

#include "LinkedList.h"

struct Queue
{
    struct LinkedList list;
    
    void (*push)(void *data, struct Queue *queue);
    void * (*pop)(struct Queue *queue);
};

struct Queue queue_constructor(void);
void queue_destructor(struct Queue *queue);

#endif /* Queue_h */
