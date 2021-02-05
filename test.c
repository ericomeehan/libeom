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
        
    for (int i = 0; i < 10; i++)
    {
        char x[3] = "xyz";
        list.push(&list, &x, Char, 3);
    }
    
    for (int i = 0; i < 10; i++)
    {
        printf("%c\n", ((char *)list.peek(&list))[2]);
        list.pop(&list);
    }
            
    queue_destructor(&list);
}
