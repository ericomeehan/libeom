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

    for (int index = 0; index < 10; index++)
    {
        int *data = (int *)malloc(sizeof(int));
        *data = index;
        list.insert(&list, index, data, sizeof(int));
    }

    list.remove(&list, 3);
    list.remove(&list, 7);

    for (int index = 0; index < list.length; index++)
    {
        void *value = list.retrieve(&list, index);
        if (value) // NULL denotes no node exists
        {
            printf("%d\n", *(int *)list.retrieve(&list, index));
        }
    }

    // Should return NULL
    list.retrieve(&list, 100);

    linked_list_destructor(&list);
}
