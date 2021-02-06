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
        char x = 'i';
        list.push(&list, &x, Char, 1);
    }
        
    for (int i = 0; i < 10; i++)
    {
        printf("%c\n", *(char *)list.peek(&list));
        list.pop(&list);
    }
    
            
    queue_destructor(&list);
}
