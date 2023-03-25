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
        int *x = (int *)malloc(sizeof(int));
        *x = i;
        printf("> i=%d, x=%p, *x=%d\n", i, x, *x);
        queue.push(&queue, x, sizeof(x));
    }

    queue.pop(&queue);
    queue.pop(&queue);

    for (int i = 0; i < 8; i++)
    {
        printf("%d\n", *(int *)queue.peek(&queue));
        queue.pop(&queue);
    }

    queue_destructor(&queue);
}
