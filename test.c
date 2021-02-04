//
//  test.c
//  hdelibc
//
//  Created by Eric Meehan on 2/1/21.
//

#include <stdio.h>
#include "DataStructures/Queue.h"

#include <time.h>

int main()
{
    struct Queue list = queue_constructor();
        
    clock_t begin = clock();
    for (int i = 0; i < 100; i++)
    {
        int *x = (int *)malloc(sizeof(int));
        *x = i;
        list.push(x, &list);
    }
    clock_t end = clock();
    
    for (int i = 0; i < 100; i++)
    {
        printf("%d\n", *(int *)list.pop(&list));
    }
    
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    
    printf("%f\n", time_spent);
    
    queue_destructor(&list);
}
