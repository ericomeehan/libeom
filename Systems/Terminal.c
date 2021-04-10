//
// ==================================
// libeom
//
// an open source c library.
// ==================================
//
// Terminal.c
//
// Eric Meehan
// 4/10/21
//
//

#include "Terminal.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void interactive_terminal(void (*interpreter)(const char *arg));

void terminal(int argc, const char *argv[], void (*interpreter)(const char *arg))
{
    switch (argc)
    {
        case 1:
            interactive_terminal(interpreter);
            break;
        default:
        {
            for (int i = 1; i < argc; i++)
            {
                interpreter(argv[i]);
            }
        }
    }
}

void interactive_terminal(void (*interpreter)(const char *arg))
{
    char input[256];
    memset(input, 0, 256);
    while (strcmp(input, "quit\n") != 0)
    {
        if(strlen(input) > 0)
        {
            interpreter(input);
        }
        printf(">>> ");
        memset(input, 0, 256);
        fgets(input, 256, stdin);
    }
}
