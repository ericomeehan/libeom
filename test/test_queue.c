//
// test_queue.c
// hdelibc
//
// Created by Eric Meehan on 2/1/21.
//

#include "../libeom.h"

#include <stdio.h>
#include <stdlib.h>

int main()
{
    struct Queue queue = queue_constructor();

    for (int i = 0; i < 10; i++)
    {
        int *data = (int *)malloc(sizeof(int));
        *data = i;
        queue.push(&queue, data, sizeof(data));
    }

    queue.pop(&queue);
    queue.pop(&queue);

    while (queue.list.length)
    {
        printf("%d\n", *(int *)queue.peek(&queue));
        queue.pop(&queue);
    }

    queue_destructor(&queue);
}
