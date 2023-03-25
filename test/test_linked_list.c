//
// test_linked_list.c
// hdelibc
//
// Created by Eric Meehan on 1/31/21.
//

#include "../libeom.h"

#include <stdio.h>
#include <stdlib.h>

int main()
{
    struct LinkedList list = linked_list_constructor();

    for (int i = 0; i < 10; i++)
    {
        int *x = (int *)malloc(sizeof(int));
        *x = i;
        list.insert(&list, i, x, sizeof(int));
    }

    list.remove(&list, 3);
    list.remove(&list, 7);

    for (int i = 0; i < 8; i++)
    {
        printf("%d\n", *(int *)list.retrieve(&list, i));
    }

    list.retrieve(&list, 100);

    linked_list_destructor(&list);
}
